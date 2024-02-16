/*                 Small LEX routine which returns two formal tokens (INTEGER and VARIABLE)
                   along with single string elements like '+'.
 
                    This LEX definition is the companion to the docalc.y YACC routine which
                   is a simple calculator

                    Shaun Cooper
                    January 2015
*/

/*
	Yosif Yosif
    Lab 4
    February 16, 2024
    Description:
      In this file, we modify the lab 2.2 to do the following:
        - modify the program to match variable names instead of just single lower case characters
          - we do that by modifying the regular expression
        - add a new rule for INTEGER where we assign yylval.value to the answer.
          - this relates to the UNION type we created in the YACC file
        - add a new rule for VARIABLE where we copy the variable name string using strdup
          - this relates to the UNION type we created in the YACC file
        

*/


%{

int mydebug=0;
#include "y.tab.h"
%}


%%

"int"   {return (T_INT);}
[a-zA-Z][a-zA-Z0-9_]*		{if (mydebug) fprintf(stderr,"VARIABLE found\n"); 
                        
                        yylval.string=strdup(yytext); 
                        return(VARIABLE);}

[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                       
            yylval.value=atoi((const char *)yytext); 
            return(INTEGER);}

[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}

[;=\-+*/%&|()] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                       return (*yytext);}
                       
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); 
                       return (*yytext);}

%%

int yywrap(void)
{ return 1;}