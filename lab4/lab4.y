%{

/*
 *			**** CALC ****
 *
 * This routine will function like a desk calculator
 * There are 26 integer registers, named 'a' thru 'z'
 *
 */

/* This calculator depends on a LEX description which outputs either VARIABLE or INTEGER.
   The return type via yylval is integer 

   When we need to make yylval more complicated, we need to define a pointer type for yylval 
   and to instruct YACC to use a new type so that we can pass back better values
 
   The registers are based on 0, so we substract 'a' from each single letter we get.

   based on context, we have YACC do the correct memmory look up or the storage depending
   on position

   Shaun Cooper
    January 2015

   problems  fix unary minus, fix parenthesis, add multiplication
   problems  make it so that verbose is on and off with an input argument instead of compiled in
*/

/*
	Yosif Yosif
    Lab 2.2
    January 26, 2024
    Description:
		In this lab, we will be fixing three problems with this file:  
			- fix unary minus
			- fix parenthesis
			- add multiplication

		To fix unary minus, there was an issue with the expression on line 106. It was
		defined as "expr '-' expr". We do not expect an "expr" in front of the minus
		sign in a unary minus operation. So, we just remove it to fix the issue.

		To fix the parenthesis, we go to the lab22.l file and add "()" to the line where
		we identify the operators.

		To add multiplication, we add a rule if that we find '*" surrounded between two expressions,
		then we multiply the expressions together.
*/


	/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "symbtab.h"

#define LIMIT 10

int yylex();
extern int mydebug;

int regs[LIMIT];
int base, debugsw;
int ONEUP = 0;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s\n", s);
}


%}
/*  defines the start symbol, what values come back from LEX and how the operators are associated  */

%start P

%union {
      int value;
      char * string;
}

%token <value> INTEGER
%token  <string> VARIABLE
%token T_INT

%type<value> expr 

%left '|'
%left '&'
%left '+' '-'
%left '*' '/' '%'
%left UMINUS


%%	/* end specs, begin rules */

P : DECLS list
  ;

DECLS : DECLS DECL
	  |
	  ;

DECL : T_INT VARIABLE ';' '\n'
	 { // search symtable if there then BARF
	   // check to see if there is room in m REGS array vs LIMIT
	   // else Insert($2, ONEUP); ONEUP ++;
	   
	    if (Search($2) != NULL)
			printf("can't declare existing variable again\n");
	    else if (ONEUP >= LIMIT)
	   	 	printf("memory limit exceeded\n");
		else{
			Insert($2, ONEUP);
			ONEUP ++;
		}
	} 

list	:	/* empty */
	|	list stat '\n'
	|	list error '\n'
			{ yyerrok; }
	;

stat	:	expr
			{ fprintf(stderr,"the answer is %d\n", $1); }
	|	VARIABLE '=' expr
			{ // if $1 is not in symtable then BARF
			  // else
			  if (Search($1) == NULL)
				printf("variable not found\n");
			  else
				regs[FetchAddress($1)] = $3; }
	;

expr	:	'(' expr ')'
			{ $$ = $2; }
	|	expr '-' expr
			{ $$ = $1 - $3; }
	|	expr '+' expr
			{ $$ = $1 + $3; }
	/* here I added a rule for the multiplication when we find an '*' between two expressions, we multiply */
	|	expr '*' expr
			{ $$ = $1 * $3; }
	|	expr '/' expr
			{ $$ = $1 / $3; }
	|	expr '%' expr
			{ $$ = $1 % $3; }
	|	expr '&' expr
			{ $$ = $1 & $3; }
	|	expr '|' expr
			{ $$ = $1 | $3; }
	/* here for the uniary minus, I removed "expr" from the beginning */
	|	'-' expr	%prec UMINUS
			{ $$ = -$2; }
	|	VARIABLE
			{ 	
				if (Search($1) == NULL){
					printf("variable not found\n");
					exit(1);
				}

				else
					$$ = regs[FetchAddress($1)]; 
				if(mydebug) 
					fprintf(stderr,"found a variable value =%d\n",$1); 
			}
	|	INTEGER {$$=$1; if(mydebug) fprintf(stderr,"found an integer\n");}
	;



%%	/* end of rules, start of program */

int main()
{ yyparse();
}
