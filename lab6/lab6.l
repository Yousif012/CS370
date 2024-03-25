/*
    Yosif Yosif
    Lab 6
    March 26, 2024
    Description:
      We don't change anything here from lab 5.

*/


%{

int mydebug=0;
int linecount=1;
#include "ast.h" 
#include "y.tab.h"

%}


%%

\/\/.* { /* handle single line comments */ }

int   {return (T_INT);}
void {return (T_VOID);}

"if" {return (T_IF);}

"else" {return (T_ELSE);}
"return" {return (T_RETURN);}
"while" {return (T_WHILE);}
"read" {return (T_READ);}
"write" {return (T_WRITE);} 

"<=" {return (T_LET);}
"<" {return (T_LT);}
">" {return (T_BT);}
">=" {return (T_BET);}
"==" {return (T_EE);}
"!=" {return (T_NE);}
"+" {return (T_ADD);}
"-" {return (T_SUB);}
"*" {return (T_STAR);}
"/" {return (T_SLASH);}




\".*\"            { yylval.string = strdup(yytext);
                    return (T_STRING);}
[a-zA-Z][a-zA-Z0-9_]*	{
                        yylval.string=strdup(yytext); 
                        return(T_ID);
                        }

[0-9][0-9]*	      {           
                  yylval.value=atoi((const char *)yytext); 
                  return(T_NUM);
                  }

[ \t]		{/* whitespace, do nothing */}


[;=\-+*/%&|()\[\],{}] 	{ return (*yytext);}
                       
\n 		{ linecount++; }

%%

int yywrap(void)
{ return 1;}