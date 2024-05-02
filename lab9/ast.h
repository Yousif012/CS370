/*

    Yosif Yosif
    Lab 9
    May 1, 2024
    Description:
      In this file, we define the types and function headers for the AST tree

*/

#include<stdio.h>
//#include<malloc.h>
#include <stdlib.h>
#include "symtable.h"

#ifndef AST_H
#define AST_H
int mydebug;

/* define the enumerated types for the AST.  THis is used to tell us what 
sort of production rule we came across */

enum ASTtype {
   A_FUNCTIONDEC,
   A_VARDEC,
   A_COMPOUND,
   A_WRITE,
   A_NUM,
   A_EXPR,
   A_PARAM,
   A_IF,
   A_IFBODY,
   A_VAR,
   A_WHILE,
   A_ASSIGN,
   A_RETURN,
   A_READ,
   A_CALL,
   A_ARG,
   A_EXPR_STMT
};

// Math Operators

enum AST_OPERATORS {
   A_PLUS,
   A_MINUS,
   A_TIMES,
   A_LET,
   A_LT,
   A_BT,
   A_BET,
   A_EE,
   A_NE,
   A_MULT,
   A_DIV,
   A_UMINUS,
};

enum AST_MY_DATA_TYPE {
   A_INTTYPE,
   A_VOIDTYPE
};

/* define a type AST node which will hold pointers to AST structs that will
   allow us to represent the parsed code 
*/

typedef struct ASTnodetype
{
     enum ASTtype type;
     enum AST_OPERATORS operator;
     char * name;
     int value;
     enum AST_MY_DATA_TYPE my_data_type;
     ///.. missing
     struct SymbTab *symbol;
     struct ASTnodetype *s1,*s2, *next ; /* used for holding IF and WHILE components -- not very descriptive */
     char * label;
} ASTnode;


/* uses malloc to create an ASTnode and passes back the heap address of the newley created node */
ASTnode *ASTCreateNode(enum ASTtype mytype);

void PT(int howmany);


/*  Print out the abstract syntax tree */
void ASTprint(int level,ASTnode *p);

// parameter checking
int check_params(ASTnode *actuals, ASTnode *formals);

#endif // of AST_H
