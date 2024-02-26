/*
    Yosif Yosif
    Lab 5
    February 26, 2024
    Description:
      In this file, we will introduce every rule according to the given document
	  that has a set of rules for the C-minus language syntax. We will also print out
	  debug statements for each time we find a Var, Var_List, Fun_Declaration, Param, and CALL.

*/

%{


/* begin specs */
#include <stdio.h>
#include <ctype.h>

int yylex();

extern int mydebug;
extern int linecount;


void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s at line number %d\n", s, linecount);
}


%}

%start Program

%union {
      int value;
      char * string;
}

/* Define tokens */

%token <value> T_NUM
%token  <string> T_ID
%token T_INT
%token T_VOID
%token T_LET 
%token T_LT 
%token T_BT
%token T_BET
%token T_EE
%token T_NE
%token T_IF
%token T_ELSE
%token T_WHILE
%token T_RETURN
%token T_WRITE
%token T_READ
%token T_ADD
%token T_SUB
%token T_STRING
%token T_STAR
%token T_SLASH



%%	/* end specs, begin rules */

Program : Declaration_List
  		;

Declaration_List : Declaration
				 | Declaration Declaration_List
				 ;

Declaration : Var_Declaration
			| Fun_Declaration
			;

Var_Declaration : Type_Specifier Var_List ';'
				;

Type_Specifier : T_INT | T_VOID
			   ;

Var_List : T_ID
		 { if(mydebug == 1){printf("Var_LIST with value %s on line %d\n", $1, linecount);}}
		 | T_ID '[' T_NUM ']'
		 { if(mydebug == 1){printf("Var_LIST with value %s on line %d\n", $1, linecount);}}
		 | T_ID ',' Var_List
		 { if(mydebug == 1){printf("Var_LIST with value %s on line %d\n", $1, linecount);}}
		 | T_ID '[' T_NUM ']' ',' Var_List
		 { if(mydebug == 1){printf("Var_LIST with value %s on line %d\n", $1, linecount);}}
		 ;

Fun_Declaration : Type_Specifier T_ID '(' Params ')' Compound_Stmt
	 			{ if(mydebug == 1){printf("FunDec with value %s on line %d\n", $2, linecount);}}
				;

Params : T_VOID | Params_List
	   ;

Params_List : Param
			| Param ',' Params_List
			;
Param : Type_Specifier T_ID
	  { if(mydebug == 1){printf("PARAM with value %s on line %d\n", $2, linecount);}}
	  | Type_Specifier T_ID '[' ']'
	  { if(mydebug == 1){printf("PARAM with value %s on line %d\n", $2, linecount);}}
	  ;

Compound_Stmt : '{' Local_Declarations Statement_List '}'
			  ;

Local_Declarations : /* Empty */
				   | Var_Declaration Local_Declarations
				   ;

Statement_List : /* Empty */
			   | Statement Statement_List
			   ;

Statement : Expression_Stmt
		  | Compound_Stmt
		  | Selection_Stmt
		  | Iteration_Stmt
		  | Assignment_Stmt
		  | Return_Stmt
		  | Read_Stmt
		  | Write_Stmt
		  ;

Expression_Stmt : Expression ';'
				| ';'
				;

Selection_Stmt : T_IF '(' Expression ')' Statement
			   | T_IF '(' Expression ')' Statement T_ELSE Statement
			   ;

Iteration_Stmt : T_WHILE '(' Expression ')' Statement
			   ;

Return_Stmt : T_RETURN ';'
			| T_RETURN Expression ';'
			;

Read_Stmt : T_READ Var ';'
		  ;

/* need to do write string */
Write_Stmt : T_WRITE Expression ';'
		   | T_WRITE T_STRING ';'
		   ;

Assignment_Stmt : Var '=' Simple_Expression ';'
				;

Var : T_ID 
	{ if(mydebug == 1){printf("Var with value %s on lineno %d\n", $1, linecount);}}
	| T_ID '[' Expression ']'
	{ if(mydebug == 1){printf("Var with value %s on lineno %d\n", $1, linecount);}}
	;

Expression : Simple_Expression
		   ;

Simple_Expression : Additive_Expression
				  | Additive_Expression relop Additive_Expression

relop : T_LET | T_LT | T_BT | T_BET | T_EE | T_NE ;
	

Additive_Expression : Term | Term Addop Additive_Expression ; 

Addop : T_ADD | T_SUB ;

Term : Factor | Factor Multop Term ;

Multop : T_STAR | T_SLASH ;

Factor : '(' Expression ')'
	   | T_NUM
	   | Var
	   | Call
	   | '-' Factor
	   ;

Call : T_ID '(' Args ')' 
	 { if(mydebug == 1){printf("CALL with value %s on lineno %d\n", $1, linecount);}}
	 ;

Args : Args_List | ;

Args_List : Expression | Expression ',' Args_List


%%	/* end of rules, start of program */

int main()
{ yyparse();
}
