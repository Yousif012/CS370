/*   Abstract syntax tree code

     This code is used to define an AST node,
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.

    Shaun Cooper Spring 2023

*/

/*

    Yosif Yosif
    Lab 6
    March 25, 2024
    Description:
      In this file, we define the functions responsible for the Abstract Syntax Tree. We create functions for
      creating nodes, printing indentation, converting types to strings, and printing the tree.

*/

#include <stdio.h>
// #include<malloc.h>
#include <stdlib.h>
#include "ast.h"

/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
//  PRE:    Ast Node Type
//  POST:   PTR To heap memory and ASTnode set and all other pointers set to NULL
ASTnode *ASTCreateNode(enum ASTtype mytype)

{
  ASTnode *p;
  if (mydebug)
    fprintf(stderr, "Creating AST Node \n");
  p = (ASTnode *)malloc(sizeof(ASTnode));
  p->type = mytype;
  p->s1 = NULL;
  p->s2 = NULL;
  p->next = NULL;
  p->symbol = NULL;
  p->value = 0;
  return (p);
}

/*  Helper function to print tabbing */
// PRE:   Number of spaces desired
// POST:  Number of spaces printed on standard output. This will print 3 spaces for each "howmany"
void PT(int howmany)
{
  for (int i=0; i<howmany; i++){
    printf("   ");
  }
}

//  PRE:   A declaration type
//  POST:  A character string that is the name of the type. We have two options here, either INT or VOID.
//  if my mytype is any other value than A_INTTYPE or A_VOIDTYPE then it will return VOID
char *ASTtypeToString(enum AST_MY_DATA_TYPE mytype)
{
  if (mytype == A_INTTYPE)
  {
    return "INT";
  }
  else
  {
    return "VOID";
  }
}

/*  Print out the abstract syntax tree */
// PRE:   PRT to an ASTtree
// POST:  indented output using AST order printing with indentation
void ASTprint(int level, ASTnode *p)
{
  int i;
  if (p == NULL)
    return;
  switch (p->type)
  {

  // handles variable declaratio, e.g. (int x;), (int x[100];), (int x, x[200];)
  case A_VARDEC:
    PT(level);
    printf("Variable %s %s", 
    ASTtypeToString(p->my_data_type), 
                    p->name);
    // if variable is an array, print its size along with square brackets
    if(p->value != 0) printf("[%d]", p->value);
    printf(" level %d offset %d", p->symbol->level, p->symbol->offset);
    printf("\n");
    ASTprint(level, p->s1);
    ASTprint(level, p->next);
    break;

  // handles function declarations, e.g. (int func(int a, int b, int c){ ... })
  case A_FUNCTIONDEC:
    PT(level);
    printf("Function %s %s ", ASTtypeToString(p->my_data_type), p->name);
    printf("\n");
    ASTprint(level + 1, p->s1); // parameters
    ASTprint(level + 1, p->s2); // compound
    ASTprint(level, p->next);
    break;

  // handles the compound statement of a function declaration
  case A_COMPOUND:
    PT(level);
    printf("Compound Statement ");
    printf("\n");
    ASTprint(level + 1, p->s1); // local decs
    ASTprint(level + 1, p->s2); // statement list
    ASTprint(level, p->next);
    break;

  // handles the write expression, e.g. (write "hello";)
  case A_WRITE:
    PT(level);
    if (p->name != NULL)
    {
      printf("Write String %s ", p->name);
    }
    else
    { // expression
      printf("Write Expression\n");
      ASTprint(level+1, p->s1);
    }
    printf("\n");
    ASTprint(level, p->next);
    break;

  // handles standalone numbers
  case A_NUM:
    PT(level);
    printf("NUMBER value %d", p->value);
    printf("\n");
    break;

  // handles expressions that involve using operators, e.g. (a+b), (a==5)
  case A_EXPR:
    PT(level);
    printf("EXPRESSION Operator ");
    switch(p->operator){
      case A_PLUS:
        printf("PLUS"); break;
      case A_MINUS:
        printf("MINUS"); break;
      case A_LET:
        printf("<="); break;
      case A_LT:
        printf("<"); break;
      case A_BET:
        printf(">="); break;
      case A_BT:
        printf(">"); break;
      case A_EE:
        printf("=="); break;
      case A_NE:
        printf("!="); break;
      case A_DIV:
        printf("/"); break;
      case A_MULT:
        printf("TIMES"); break;
      case A_UMINUS:
        printf("Unary-minus"); break;
      default:
        printf("unknown operator in A_EXPR in ASTprint");
    }
    printf("\n");
    ASTprint(level+1, p->s1);
    ASTprint(level+1, p->s2);
    break;

  // handles the parameter of a function declaration
  case A_PARAM:
    PT(level);
    printf("Parameter %s %s ", ASTtypeToString(p->my_data_type), p->name);
    printf("\n");
    ASTprint(level, p->next);
    break; 

  // handles if statements
  case A_IF:
    PT(level);
    printf("IF STATEMENT\n");
    PT(level+1);
    printf("IF expression\n");
    ASTprint(level+2, p->s1);
    PT(level+1);
    printf("IF body\n");
    ASTprint(level+2, p->s2->s1);
    if(p->s2->s2 != NULL){
      PT(level+1);
      printf("ELSE body\n");
      ASTprint(level+2, p->s2->s2);
    }
    ASTprint(level, p->next);
    break;
  
  // handles variables that appear in expressions
  case A_VAR:
    PT(level);
    printf("VARIABLE %s level %d offset %d", p->name, p->symbol->level, p->symbol->offset);
    printf("\n");

    if(p->s1 != NULL){
      PT(level);
      printf("[\n");
      ASTprint(level+1, p->s1);
      PT(level);
      printf("]\n");
    }
    break;

  // handles while loops
  case A_WHILE:
    PT(level);
    printf("WHILE expression\n");
    ASTprint(level+1, p->s1);
    PT(level);
    printf("WHILE body\n");
    ASTprint(level+1, p->s2);

    ASTprint(level, p->next);
    break;

  // handles variable assignments, e.g. (a = 5;)
  case A_ASSIGN:
    PT(level);
    printf("ASSIGMENT STATEMENT\n");
    ASTprint(level+1, p->s1);
    PT(level);
    printf("is assigned\n");
    ASTprint(level+1, p->s2);

    ASTprint(level, p->next);

    break;

  // handles return statements (usually found in function compound statements)
  case A_RETURN:
    PT(level);
    printf("RETURN STATEMENT\n");
    if(p->s1 != NULL){
      ASTprint(level+1, p->s1);
    }

    ASTprint(level, p->next);

    break;

  // handles read statements, e.g. (read a;)
  case A_READ:
    PT(level);
    printf("READ Expression\n");
    ASTprint(level+1, p->s1);

    ASTprint(level, p->next);
    break;

  // handles functions calls, e.g. (a = func(1, 2);)
  case A_CALL:
    PT(level);
    printf("CALL STATEMENT function %s\n", p->name);

    ASTprint(level+1, p->s1);

    ASTprint(level, p->next);
    break;
  
  // handles the arguments inside a function call
  case A_ARG:
    PT(level);
    printf("CALL argument\n");

    ASTprint(level+1, p->s1);

    ASTprint(level, p->next);

    break;

  case A_EXPR_STMT:

    PT(level);
    
    printf("Expression STATEMENT\n"); 

    ASTprint(level+1, p->s1);
    
    ASTprint(level, p->next);

    break;

  default:
    printf("unknown AST Node type %d in ASTprint\n", p->type);
  }
}

// PRE : PTRS to actual and formals
// POST: 0 if they are not same type or length
//       1 if they are same type and length
int check_params(ASTnode *actuals, ASTnode *formals){
  ASTnode *temp1, *temp2;
  temp1 = actuals;
  temp2 = formals;


  if(actuals == NULL && formals == NULL) return 1;
  if(actuals == NULL || formals == NULL) return 0;

  printf("check params %d %d\n", actuals->my_data_type, formals->my_data_type);

  if(actuals->my_data_type != formals->my_data_type) return 0;

  return check_params(actuals->next, formals->next);
}