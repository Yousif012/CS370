/*
    Yosif Yosif
    Lab 9
    May 1, 2024
    Description:
      In this file, we define the sematic actions for every rule and we create an AST tree
	  and use it in our call to the EMIT function which prints out MIPS code to a specified file
*/

%{


/* begin specs */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ast.h" 
#include "symtable.h"
#include "emit.h"


int yylex();

extern int mydebug;
extern int linecount;

int LEVEL = 0; // global variable to know how far deep we are
int OFFSET = 0; // global variable for size of program
int GOFFSET = 0; // global variable for global variable offset
int maxOffset = 0; // largest offset needed for function

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
%type <node> Write_Stmt Expression Simple_Expression Additive_Expression Term Args Args_List
%type <node> Factor Var Call Param Params_List Selection_Stmt Expression_Stmt Iteration_Stmt Assignment_Stmt Return_Stmt Read_Stmt
%type <operator> Addop relop Multop 

%type <d_type> Type_Specifier


%%	/* end specs, begin rules */

Program : Declaration_List { PROGRAM = $1; }
  	

Declaration_List : Declaration { $$ = $1; }
				 | Declaration Declaration_List
				 {
					$$ = $1;
					if($1 != NULL) $$->next = $2;
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

					// check if variable already defined at current level
					if(Search(p->name, LEVEL, 0) != NULL){
						// if symbol found, BARF
						yyerror(p->name);
						yyerror("Symbol already defined");
						exit(1);
					}

					// variable not in symbol table
					// variable is scalar
					if(p->value == 0){
						p->symbol = Insert(p->name, p->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
						OFFSET += 1;
					}

					// variable is array
					else{
						p->symbol = Insert(p->name, p->my_data_type, SYM_ARRAY, LEVEL, p->value, OFFSET);
						OFFSET += p->value;
					}

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
		     $$->value = $3;
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
			 $$->value = $3;
			 $$->s1 = $6;
		   }
		 ;

Fun_Declaration : Type_Specifier T_ID 
				{
					// check if function has been defined
					if(Search($2, LEVEL, 0) != NULL){
						// T_ID has already been used, BARF
						yyerror($2);
						yyerror("function name already in use");
						exit(1);
					}
					// not in symbol table, insert it
					Insert($2, $1, SYM_FUNCTION, LEVEL, 0, 0);

					GOFFSET = OFFSET;
					OFFSET = 2;
					maxOffset = OFFSET;
				}
				'(' Params ')'
				{ 
				  // add ASTnode to the symbol structure
				  Search($2, LEVEL, 0)->fparms = $5;
				}
				Compound_Stmt 
				{ 
					$$ = ASTCreateNode(A_FUNCTIONDEC);
				    $$->name = $2;
				    $$->my_data_type = $1;
				    $$->s1 = $5;
					$$->s2 = $8; 

					// change offset in symbol struct
					struct SymbTab *p;
					p = Search($2, LEVEL, 0);
					p->offset = maxOffset;
					$$->symbol = p;
					
					OFFSET = GOFFSET;
				}
				;

Params : T_VOID { $$ = NULL; }
	   | Params_List { $$ = $1; }
	   ;

Params_List : Param { $$ = $1; }
			| Param ',' Params_List
			{ $$ = $1; 
			  $$->next = $3; }
			;
Param : Type_Specifier T_ID
		{ 
		  // check if parameter already defined
		  if(Search($2, LEVEL+1, 0) != NULL){
			yyerror($2);
			yyerror("Parameter already used");
			exit(1);
		  }
		  $$ = ASTCreateNode(A_PARAM);
		  $$->name = $2;
		  $$->my_data_type = $1;
		  $$->symbol = Insert($$->name, $$->my_data_type, SYM_SCALAR, LEVEL+1, 1, OFFSET);
		  OFFSET++;
		}
	  | Type_Specifier T_ID '[' ']'
	  	{ 
		  // check if parameter already defined
		  if(Search($2, LEVEL+1, 0) != NULL){
			yyerror($2);
			yyerror("Parameter already used");
			exit(1);
		  }
		  $$ = ASTCreateNode(A_PARAM);
		  $$->name = $2;
		  $$->my_data_type = $1;
		  $$->symbol = Insert($$->name, $$->my_data_type, SYM_ARRAY, LEVEL+1, 1, OFFSET);
		  OFFSET++;
		}
	  ;

Compound_Stmt : '{' 
			  { 
				LEVEL ++; 
			  } 
			  	Local_Declarations Statement_List '}'
			  {
				$$ = ASTCreateNode(A_COMPOUND);
				$$->s1 = $3;
				$$->s2 = $4;

				if(mydebug) Display();
				// adjust offset and level when exiting compound statement
				if(OFFSET > maxOffset) maxOffset = OFFSET;
				OFFSET -= Delete(LEVEL);
				LEVEL --;
			  }
			  ;

Local_Declarations : /* Empty */ { $$ = NULL; }
				   | Var_Declaration Local_Declarations
				   { 
					 $$ = $1;
				     if($1 != NULL) $$->next = $2;
				   }
				   ;

Statement_List : /* Empty */ { $$ = NULL; }
			   | Statement Statement_List
			   {
				$$ = $1;
				$$->next = $2;
			   }
			   ;

Statement : Expression_Stmt { $$ = $1; }
		  | Compound_Stmt { $$ = $1; }
		  | Selection_Stmt { $$ = $1; }
		  | Iteration_Stmt { $$ = $1; }
		  | Assignment_Stmt { $$ = $1; }
		  | Return_Stmt { $$ = $1; }
		  | Read_Stmt { $$ = $1; }
		  | Write_Stmt { $$ = $1; }
		  ;

Expression_Stmt : Expression ';' 
				{ 
					$$ = ASTCreateNode(A_EXPR_STMT);
					$$->s1 = $1;
				}
				| ';' { $$ = ASTCreateNode(A_EXPR_STMT); }
				;

Selection_Stmt : T_IF '(' Expression ')' Statement
				{
				 $$ = ASTCreateNode(A_IF);
				 $$->s1 = $3;
				 $$->s2 = ASTCreateNode(A_IFBODY);
				 $$->s2->s1 = $5;
				}
			   | T_IF '(' Expression ')' Statement T_ELSE Statement
				{
				 $$ = ASTCreateNode(A_IF);
				 $$->s1 = $3;
				 $$->s2 = ASTCreateNode(A_IFBODY);
				 $$->s2->s1 = $5;
				 $$->s2->s2 = $7;
				}
			   ;

Iteration_Stmt : T_WHILE '(' Expression ')' Statement
			   {
				$$ = ASTCreateNode(A_WHILE);
				$$->s1 = $3;
				$$->s2 = $5;
			   }
			   ;

Return_Stmt : T_RETURN ';'
			{ $$ = ASTCreateNode(A_RETURN); }
			| T_RETURN Expression ';'
			{ 
				$$ = ASTCreateNode(A_RETURN); 
				$$->s1 = $2;
			}

			;

Read_Stmt : T_READ Var ';'
		  {
			$$ = ASTCreateNode(A_READ);
			$$->s1 = $2;
		  }
		  ;

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
				{
					if($1->my_data_type != $3->my_data_type){
						yyerror("Type Mismatch");
						exit(1);
					 }
					$$ = ASTCreateNode(A_ASSIGN);
					$$->s1 = $1;
					$$->s2 = $3;
					$$->name = CreateTemp();
					$$->symbol = Insert($$->name, $1->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
					OFFSET++;
				}
				;

Var : T_ID 
	{ 
		struct SymbTab *p;
		p = Search($1, LEVEL, 1);

		// check if variable defined
		if(p == NULL){
			// variable not defined within scope
			yyerror($1);
			yyerror("symbol used but not defined");
			exit(1);
		}

		// verify if variable is scalar
		if (p->SubType != SYM_SCALAR){
			// variable is used as scalar but not scalar
			yyerror($1);
			yyerror("symbol must be scalar");
			exit(1);
		}

		$$ = ASTCreateNode(A_VAR);
	   	$$->name = $1;
		$$->symbol = p;
		$$->my_data_type = p->Declared_Type;
	}
	| T_ID '[' Expression ']'
	{ 
		struct SymbTab *p;
		p = Search($1, LEVEL, 1);

		// check if variable defined
		if(p == NULL){
			// variable not defined within scope
			yyerror($1);
			yyerror("symbol used but not defined");
			exit(1);
		}

		// verify if variable is array
		if (p->SubType != SYM_ARRAY){
			// variable is used as array but not array
			yyerror($1);
			yyerror("symbol must be array");
			exit(1);
		}

		$$ = ASTCreateNode(A_VAR);
	   	$$->name = $1;
		$$->s1 = $3;
		$$->symbol = p;
		$$->my_data_type = p->Declared_Type;
	}
	;

Expression : Simple_Expression { $$ = $1; }
		   ;

Simple_Expression : Additive_Expression { $$ = $1; }
				  | Additive_Expression relop Additive_Expression 
					{

					// check if variables are same type
					if($1->my_data_type != $3->my_data_type){
						yyerror("Type Mismatch");
						exit(1);
					 }

					 $$ = ASTCreateNode(A_EXPR); 
					 $$->s1 = $1;
					 $$->s2 = $3;
					 $$->operator = $2;
					 $$->name = CreateTemp();
					 $$->symbol = Insert($$->name, $1->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
					 $$->my_data_type = $1->my_data_type;
					 OFFSET++;
					}

relop : T_LET { $$ = A_LET; } 
      | T_LT  { $$ = A_LT; }
	  | T_BT  { $$ = A_BT; }
	  | T_BET { $$ = A_BET; }
	  | T_EE  { $$ = A_EE; }
	  | T_NE  { $$ = A_NE; }
	  ;
	

Additive_Expression : Term { $$ = $1; }
				    | Term Addop Additive_Expression 
					{

					 // check if variables are same type
					 if($1->my_data_type != $3->my_data_type){
						yyerror("Type Mismatch");
						exit(1);
					 }

					 $$ = ASTCreateNode(A_EXPR);
					 $$->s1 = $1;
					 $$->s2 = $3;
					 $$->operator = $2;
					 $$->my_data_type = $1->my_data_type;
					 $$->name = CreateTemp();
					 $$->symbol = Insert($$->name, $1->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
					 OFFSET++;
					}
					; 

Addop : T_ADD { $$ = A_PLUS; }
	  | T_SUB { $$ = A_MINUS; };

Term : Factor { $$ = $1; }
	 | Factor Multop Term 
	 { 

		// check if variables are same type
		if($1->my_data_type != $3->my_data_type){
			yyerror("Type Mismatch");
			exit(1);
		}
		
		$$ = ASTCreateNode(A_EXPR);
		$$->s1 = $1;
		$$->s2 = $3;
		$$->operator = $2;
		$$->my_data_type = $1->my_data_type;
		$$->name = CreateTemp();
		$$->symbol = Insert($$->name, $1->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
		OFFSET++;
	 } 
	 ;

Multop : T_STAR { $$ = A_MULT; } | T_SLASH { $$ = A_DIV; } ;

Factor : '(' Expression ')' { $$ = $2; }
	   | T_NUM 
	   { 
		 $$ = ASTCreateNode(A_NUM);
	   	 $$->value = $1; 
		 $$->my_data_type = A_INTTYPE;
	   }
	   | Var { $$ = $1; }
	   | Call { $$ = $1; }
	   | T_SUB Factor 
	   { 
		$$ = ASTCreateNode(A_EXPR);
		$$->operator = A_UMINUS;
		$$->s1 = $2; 
		$$->my_data_type = $$->s1->my_data_type;
	   }
	   ;

Call : T_ID '(' Args ')'  
	 { 
		struct SymbTab *p;
		p = Search($1, 0, 0);
		if(p == NULL){
			// function not defined
			yyerror($1);
			yyerror("function not defined");
			exit(1);
		}

		// name is there but is it a function?
		if(p->SubType != SYM_FUNCTION){
			// function name is not related to a function declaration but to a variable
			yyerror($1);
			yyerror("not defined as function");
			exit(1);
		}

		// check if parameters length and type are correct
		if(check_params($3, p->fparms) == 0){
			yyerror($1);
			yyerror("Actual and Formals do not match");
			exit(1);
		}
		
	   $$ = ASTCreateNode(A_CALL);
	   $$->name = $1;
	   $$->s1 = $3;
	   $$->symbol = p;
	   $$->my_data_type = p->Declared_Type;
	 }
	 ;

Args : Args_List { $$ = $1; } |  { $$ = NULL; } ;

Args_List : Expression
		  { 
			$$ = ASTCreateNode(A_ARG);
			$$->s1 = $1;
			$$->my_data_type = $1->my_data_type;

			$$->name = CreateTemp();
			$$->symbol = Insert($$->name, $1->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
			OFFSET++;
		  }
		  | Expression ',' Args_List
		  { 
			$$ = ASTCreateNode(A_ARG);
			$$->s1 = $1;
			$$->next = $3;
			$$->my_data_type = $1->my_data_type;

			$$->name = CreateTemp();
			$$->symbol = Insert($$->name, $1->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
			OFFSET++;
		  }


%%	/* end of rules, start of program */

int main(int argc, char *argv[])
{ 
  FILE *fp;

  int i;
  char s[100];
  for(i = 0; i<argc; i++){
	if(strcmp(argv[i], "-d") == 0) mydebug = 1;
	if(strcmp(argv[i], "-o") == 0){
		strcpy(s, argv[i+1]);
		strcat(s, ".asm");
	} 
  }
  
  fp = fopen(s, "w");
  if(fp == NULL){
	printf("cannot open file %s\n", s);
	exit(1);
  }

  yyparse();

  if(mydebug){
  	printf("Finished parsing\n");
	Display(); // shows our global variables
	printf("\n\n\nAST PRINT \n\n\n");
	ASTprint(0, PROGRAM);
  }

  EMIT(PROGRAM, fp);
  
}
