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
#include "ast.h" 


int yylex();

extern int mydebug;
extern int linecount;

ASTnode * PROGRAM;

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
	  ASTnode * node;
	  enum AST_MY_DATA_TYPE d_type;
	  enum AST_OPERATORS operator;
}

/* Define tokens */

%token <value> T_NUM
%token  <string> T_ID T_STRING
%token T_INT
%token T_VOID
%token T_LET T_LT T_BT T_BET T_EE T_NE
%token T_IF T_ELSE T_WHILE T_RETURN T_WRITE T_READ
%token T_ADD T_SUB T_STAR T_SLASH

%type <node> Declaration_List Declaration Var_Declaration Var_List
%type <node> Fun_Declaration Params Compound_Stmt Local_Declarations Statement_List Statement
%type <node> Write_Stmt Expression Simple_Expression Additive_Expression Term
%type <node> Factor Var Call
%type <operator> Addop

%type <d_type> Type_Specifier


%%	/* end specs, begin rules */

Program : Declaration_List { PROGRAM = $1; }
  	

Declaration_List : Declaration { $$ = $1; }
				 | Declaration Declaration_List
				 {
					$$ = $1;
					$$->next = $2;
				 }
				 ;

Declaration : Var_Declaration { $$ = $1; }
			| Fun_Declaration { $$ = $1; }
			;

Var_Declaration : Type_Specifier Var_List ';'
				{ 
				  // populate the s1 connected list with the
				  // defined type via $1
				  ASTnode *p = $2;
				  while ( p != NULL ){
					p->my_data_type = $1;
					p = p->s1;
				  }
				  $$ = $2; 
				}
				;

Type_Specifier : T_INT { $$ = A_INTTYPE; }
			   | T_VOID { $$ = A_VOIDTYPE; }
			   ;

Var_List : T_ID 
		   { $$ = ASTCreateNode(A_VARDEC); 
			 $$->name = $1; 
		   }
		 | T_ID '[' T_NUM ']' 
		   { $$ = ASTCreateNode(A_VARDEC); 
		     $$->name = $1; 
		   }
		 | T_ID ',' Var_List 
		   { $$ = ASTCreateNode(A_VARDEC); 
			 $$->name = $1; 
			 $$->s1 = $3;
		   }
		 | T_ID '[' T_NUM ']' ',' Var_List
		   { $$ = ASTCreateNode(A_VARDEC); 
			 $$->name = $1; 
			 $$->s1 = $6;
		   }
		 ;

Fun_Declaration : Type_Specifier T_ID '(' Params ')' Compound_Stmt
				{ 
				  $$ = ASTCreateNode(A_FUNCTIONDEC);
				  $$->name = $2;
				  $$->my_data_type = $1;
				  $$->s1 = $4;
				  $$->s2 = $6;
				}
				;

Params : T_VOID { $$ = NULL; }
	   | Params_List { $$ = NULL; }
	   ;

Params_List : Param
			| Param ',' Params_List
			;
Param : Type_Specifier T_ID
	  | Type_Specifier T_ID '[' ']'
	  ;

Compound_Stmt : '{' Local_Declarations Statement_List '}'
			  {
				$$ = ASTCreateNode(A_COMPOUND);
				$$->s1 = $2;
				$$->s2 = $3;
			  }
			  ;

Local_Declarations : /* Empty */ { $$ = NULL; }
				   | Var_Declaration Local_Declarations
				   { 
					 $$ = $1;
				     $$->next = $2;
				   }
				   ;

Statement_List : /* Empty */ { $$ = NULL; }
			   | Statement Statement_List
			   {
				$$ = $1;
				$$->next = $2;
			   }
			   ;

Statement : Expression_Stmt { $$ = NULL; }
		  | Compound_Stmt { $$ = $1; }
		  | Selection_Stmt { $$ = NULL; }
		  | Iteration_Stmt { $$ = NULL; }
		  | Assignment_Stmt { $$ = NULL; }
		  | Return_Stmt { $$ = NULL; }
		  | Read_Stmt { $$ = NULL; }
		  | Write_Stmt { $$ = $1; }
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
Write_Stmt : T_WRITE T_STRING ';' 
		   { 
			 $$ = ASTCreateNode(A_WRITE);
			 $$->name = $2;
		   }
		   | T_WRITE Expression ';' 
		   {
			 $$ = ASTCreateNode(A_WRITE);
			 $$->s1 = $2;
		   }

		   ;

Assignment_Stmt : Var '=' Simple_Expression ';'
				;

Var : T_ID { $$ = NULL; }
	| T_ID '[' Expression ']' { $$ = NULL; }
	;

Expression : Simple_Expression { $$ = $1; }
		   ;

Simple_Expression : Additive_Expression { $$ = $1; }
				  | Additive_Expression relop Additive_Expression 
				  { 
					$$ = NULL;
				  }

relop : T_LET | T_LT | T_BT | T_BET | T_EE | T_NE ;
	

Additive_Expression : Term { $$ = $1; }
				    | Term Addop Additive_Expression 
					{
					 $$ = ASTCreateNode(A_EXPR); 
					 $$->s1 = $1;
					 $$->s2 = $3;
					 $$->operator = $2;
					}
					; 

Addop : T_ADD { $$ = A_PLUS; }
	  | T_SUB { $$ = A_MINUS; };

Term : Factor { $$ = $1; }
	 | Factor Multop Term { $$ = NULL; } ;

Multop : T_STAR | T_SLASH ;

Factor : '(' Expression ')' { $$ = $2; }
	   | T_NUM 
	   { 
		 $$ = ASTCreateNode(A_NUM);
	   	 $$->value = $1; 
	   }
	   | Var { $$ = NULL; }
	   | Call { $$ = NULL; }
	   | '-' Factor { $$ = NULL; }
	   ;

Call : T_ID '(' Args ')'  { $$ = NULL; }
	 ;

Args : Args_List | ;

Args_List : Expression | Expression ',' Args_List


%%	/* end of rules, start of program */

int main()
{ yyparse();
  printf("Finished parsing\n");
  ASTprint(0, PROGRAM);
}