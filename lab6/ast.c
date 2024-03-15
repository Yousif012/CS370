/*   Abstract syntax tree code

     This code is used to define an AST node,
    routine for printing out the AST
    defining an enumerated type so we can figure out what we need to
    do with this.  The ENUM is basically going to be every non-terminal
    and terminal in our language.

    Shaun Cooper Spring 2023

*/

#include <stdio.h>
// #include<malloc.h>
#include <stdlib.h>
#include "ast.h"

/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
//  PRE:  Ast Node Type
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
  p->value = 0;
  return (p);
}

/*  Helper function to print tabbing */
// PRE:  Number of spaces desired
// POST:  Number of spaces printed on standard output

void PT(int howmany)
{
  // MISSING
  for (int i=0; i<howmany; i++){
    printf("   ");
  }
}

//  PRE:  A declaration type
//  POST:  A character string that is the name of the type
//          Typically used in formatted printing
char *ASTtypeToString(enum AST_MY_DATA_TYPE mytype)
{
  // Missing
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
  case A_VARDEC:
    PT(level);
    printf("Variable %s %s ", ASTtypeToString(p->my_data_type), p->name);
    printf("\n");
    ASTprint(level, p->s1);
    ASTprint(level, p->next);
    break;
  case A_FUNCTIONDEC:
    PT(level);
    printf("Function %s %s ", ASTtypeToString(p->my_data_type), p->name);
    printf("\n");
    ASTprint(level + 1, p->s1); // parameters
    ASTprint(level + 1, p->s2); // compound
    ASTprint(level, p->next);
    break;
  case A_COMPOUND:
    PT(level);
    printf("Compound Statement ");
    printf("\n");
    ASTprint(level + 1, p->s1); // local decs
    ASTprint(level + 1, p->s2); // statement list
    ASTprint(level, p->next);
    break;
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
  case A_NUM:
    PT(level);
    printf("NUMBER value %d", p->value);
    printf("\n");
    break;
  case A_EXPR:
    PT(level);
    printf("EXPRESSION Operator ");
    switch(p->operator){
      case A_PLUS:
        printf("PLUS"); break;
      case A_MINUS:
        printf("MINUS");
      default:
        printf("unknown operator in A_EXPR in ASTprint");

    }
    printf("\n");
    ASTprint(level+1, p->s1);
    ASTprint(level+1, p->s2);
  
    break; 
  default:
    printf("unknown AST Node type %d in ASTprint\n", p->type);
  }
}

/* dummy main program so I can compile for syntax error independently
main()
{
}
*/
