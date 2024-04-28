#include "emit.h"
#include "ast.h"
#include <stdlib.h>

int STRING_COUNT = 0; // global variable for count of strings

void EMIT(ASTnode * p, FILE * fp){

    if(p == NULL) return;
    if(fp == NULL) return;
    
    fprintf(fp, "# MIPS code generated by Compilers class\n\n");
    fprintf(fp, ".data\n\n");
    EMIT_STRINGS(p, fp);
    fprintf(fp, ".align 2\n");
    EMIT_GLOBALS(p, fp);
    fprintf(fp, ".text\n\n\n");
    EMIT_AST(p, fp);

}


void EMIT_GLOBALS(ASTnode * p, FILE * fp){
    while (p){
        if (p->type == A_VARDEC && p->symbol->level == 0){
            fprintf(fp, "%s: .space %d\n", p->name, p->symbol->mysize*W_SIZE);
			ASTnode * varList = p->s1;
            while(varList){
                fprintf(fp, "%s: .space %d\n", varList->name, varList->symbol->mysize*W_SIZE);
                varList = varList->s1;
            }

        }
        p = p->next;
    }
}

void EMIT_STRINGS(ASTnode * p, FILE * fp){
    if(p == NULL) return;

    if (p->type == A_WRITE && p->name != NULL){
        p->label = CreateLabel();
        fprintf(fp, "%s: .asciiz %s\n", p->label, p->name);
    }

    EMIT_STRINGS(p->next, fp);
    EMIT_STRINGS(p->s1, fp);
    EMIT_STRINGS(p->s2, fp);
}

void EMIT_AST(ASTnode * p, FILE * fp){
    if(p == NULL)
        return;
    
    switch (p->type){

        case A_VARDEC:
            EMIT_AST(p->next, fp);
            break;
        
        case A_FUNCTIONDEC:
            emit_function(p, fp);
            EMIT_AST(p->next, fp);
            break;
        case A_COMPOUND:
            EMIT_AST(p->s2, fp);
            EMIT_AST(p->next, fp);
            break;
        case A_WRITE:
            emit_write(p, fp);
            EMIT_AST(p->next, fp);
            break;
        case A_READ:
            emit_read(p, fp);
            EMIT_AST(p->next, fp);
            break;
        case A_ASSIGN:
            emit_assign(p, fp);
            EMIT_AST(p->next, fp);
            break;



        default:
            printf("EMIT_AST case %d not implemented\n", p->type);
            printf("WE SHOULD NEVER BE HERE\n");
            exit(1);
    }
}


char * CreateLabel()
{
    char hold[100];
    char *s;
    sprintf(hold,"_L%d",STRING_COUNT);
    s=strdup(hold);
    STRING_COUNT++;
    return (s);
}

void emit_function(ASTnode * p, FILE * fp){

    char s[100];

    emit(fp, p->name, "", "function definition");

    // Carve out the Stack for activation record
    emit(fp, "", "move $a1, $sp", "Activation Record carve out copy SP");
    sprintf(s,"subi $a1, $a1, %d",p->symbol->offset*W_SIZE); 
    emit(fp, "", s,"Activation Record carve out copy size of function"); 
    emit(fp, "", "sw $ra, ($a1)","Store Return address ");
    sprintf(s, "sw $sp %d($a1)",W_SIZE);
    emit(fp, "", s, "Store the old Stack pointer");
    emit(fp, "", "move $sp, $a1","Make SP the current activation record");
    fprintf(fp, "\n\n");

    // copy the parameters to the formal from registers $t0 et

    // generate compound statement
    EMIT_AST(p->s2, fp);

    // restore RA and SP before we return
    emit(fp, "", "lw $ra ($sp)", "restore old environment RA");
    sprintf(s, "lw $sp %d($sp)", W_SIZE);
    emit(fp, "", s, "Return from function store SP");
    fprintf(fp, "\n");


    // create an implicit return depending on if we are main or not
    if(strcmp(p->name, "main") == 0){
        // exit the system
        emit(fp, "", "li $v0, 10", "Exit from Main");
        emit(fp, "", "syscall", "EXIT everything");
    }
    else{
        // jump back to the caller
    }
}

void emit_write(ASTnode * p, FILE * fp){
    char s[100];
    if(p->name != NULL){
        // need to load the address of label into $a0
        // and call print string
        sprintf(s, "la $a0, %s", p->label);
        emit(fp, "", s, "The string address");
        emit(fp, "", "li $v0, 4", "About to print a string");
        emit(fp, "", "syscall", "call write string");
        fprintf(fp, "\n\n");
    }
    else{
        emit_expr(p->s1, fp);
        emit(fp, "", "li $v0, 1", "About to print a number");
        emit(fp, "", "syscall", "call write number");
        fprintf(fp, "\n\n");
    }
} // emit_write

void emit_read(ASTnode * p, FILE * fp){

    emit_var(p->s1, fp); // $a0 will be the location of the variable
    emit(fp, "", "li $v0, 5", "About to read a value");
    emit(fp, "", "syscall", "read in value $v0 now has the read value");
    emit(fp, "", "sw $v0 ($a0)", "store read in value to memory");
    fprintf(fp, "\n\n");

}

void emit_var(ASTnode * p, FILE * fp){
    char s[100];
    // handle internal offset if array

    if(p->symbol->level == 0) // global variable
    {
        // get the direct address of global var
        sprintf(s, "la $a0, %s", p->name);
        emit(fp, "", s, "EMIT Var global variable");
    }
    else{
        // local variable, Stack pointer plus offset
    }

    // add on array index if needed
}


void emit_expr(ASTnode * p, FILE * fp){
    char s[100];

    // base cases
    switch(p->type){
        case A_NUM:
            sprintf(s, "li $a0, %d", p->value);
            emit(fp, "", s, "expression is a constant");
            return;
            break;
        case A_VAR:
            emit_var(p, fp); // $a0 is the memory location
            emit(fp, "", "lw $a0, ($a0)", "Expression is a VAR");
            return;
            break;
        case A_EXPR: break; // handled after switch

        default: printf("emit_expr switch NEVER SHOULD BE HERE\n");
                 printf("FIX FIX FIX\n");
                 exit(1);
    }
}

void emit_assign(ASTnode * p, FILE * fp){
    emit_var(p->s1, fp); // $a0 will be the location of the variable
    emit(fp, "", "addi $a1, $a0, 0", "Load location of variable into $a1");
    emit_expr(p->s2, fp);
    emit(fp, "", "sw $a0 ($a1)", "Assign new value to variable");
}



void emit(FILE *fp, char * label, char * command, char * comment)
{
    if (strcmp("", comment) == 0 ) 
        if (strcmp("",label) == 0)
            fprintf (fp,"\t%s\t\t\n", command );
        else
            fprintf(fp,"%s:\t%s\t\t\n",label, command);
    else
        if (strcmp("",label) == 0)
            fprintf(fp,"\t%s\t\t# %s\n", command, comment);
        else
            fprintf(fp,"%s:\t%s\t\t# %s\n",label, command, comment);
}