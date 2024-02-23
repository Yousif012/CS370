%{


/* begin specs */
#include <stdio.h>
#include <ctype.h>

int yylex();

extern int mydebug;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}

%start Program

%union {
      int value;
      char * string;
}

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
		 | T_ID '[' T_NUM ']'
		 | T_ID ',' Var_List
		 | T_ID '[' T_NUM ']' ',' Var_List
		 ;

Fun_Declaration : Type_Specifier T_ID '(' Params ')' Compound_Stmt
				;

Params : T_VOID | Params_List
	   ;

Params_List : Param
			| Param ',' Params_List
			;
Param : Type_Specifier T_ID
	  | Type_Specifier T_ID '[' ']'
	  ;

Compound_Stmt : '{' Local_Declarations Statement_List '}'
			  ;

Local_Declarations : /* Empty */
				   | Var_Declaration
				   ;

Statement_List : /* Empty */
			   | Statement
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

Iteration_Stmt : "while" '(' Expression ')' Statement
			   ;

Return_Stmt : T_RETURN ';'
			| T_RETURN Expression ';'
			;

Read_Stmt : "read" Var ';'
		  ;

/* need to do write string */
Write_Stmt : "write" Expression ';'
		   ;

Assignment_Stmt : Var '=' Simple_Expression ';'
				;

Var : T_ID 
	| T_ID '[' Expression ']'
	;

Expression : Simple_Expression
		   ;

Simple_Expression : Additive_Expression
				  | Additive_Expression relop Additive_Expression

relop : T_LET | T_LT | T_BT | T_BET | T_EE | T_NE ;
	

Additive_Expression : ;


%%	/* end of rules, start of program */

int main()
{ yyparse();
}
