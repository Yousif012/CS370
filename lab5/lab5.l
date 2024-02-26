
%{

int mydebug=0;
#include "y.tab.h"
%}


%%

int   {return (T_INT);}
void {return (T_VOID);}

"if" {if (mydebug) fprintf(stderr,"if found\n");
    return (T_IF);}

"else" {if (mydebug) fprintf(stderr,"else found\n");
      return (T_ELSE);}
"return" {if (mydebug) fprintf(stderr,"return found\n");
      return (T_RETURN);}
"while" {if (mydebug) fprintf(stderr,"while found\n");
      return (T_WHILE);}
"read" {if (mydebug) fprintf(stderr,"read found\n");
            return (T_READ);}
"write" {if (mydebug) fprintf(stderr,"write found\n");
      return (T_WRITE);} 

"<=" {if (mydebug) fprintf(stderr,"less than or equal found\n");
      return (T_LET);}
"<" {if (mydebug) fprintf(stderr,"less than found\n");
      return (T_LT);}
">" {if (mydebug) fprintf(stderr,"bigger than found\n");
      return (T_BT);}
">=" {if (mydebug) fprintf(stderr,"bigger than or equal found\n");
      return (T_BET);}
"==" {if (mydebug) fprintf(stderr,"equal equal found\n");
      return (T_EE);}
"!=" {if (mydebug) fprintf(stderr,"not equal found\n");
      return (T_NE);}
"+" {if (mydebug) fprintf(stderr,"add found\n");
      return (T_ADD);}
"-" {if (mydebug) fprintf(stderr,"subtract found\n");
      return (T_SUB);}
"*" {if (mydebug) fprintf(stderr,"star found\n");
      return (T_STAR);}
"/" {if (mydebug) fprintf(stderr,"forward slash found\n");
      return (T_SLASH);}



\".*\"            {if (mydebug) fprintf(stderr,"string found\n");
                  return (T_STRING);}
[a-zA-Z][a-zA-Z_]*		{if (mydebug) fprintf(stderr,"ID found\n"); 
                        
                        yylval.string=strdup(yytext); 
                        return(T_ID);}

[0-9][0-9]*	{if (mydebug) fprintf(stderr,"Digit found\n"); 
                       
            yylval.value=atoi((const char *)yytext); 
            return(T_NUM);}

[ \t]		{if (mydebug) fprintf(stderr,"Whitespace found\n");}

[;=\-+*/%&|()\[\],{}] 	{ if (mydebug) fprintf(stderr,"return a token %c\n",*yytext); 
                       return (*yytext);}
                       
\n 		{ if (mydebug) fprintf(stderr,"cariage return %c\n",*yytext); }

%%

int yywrap(void)
{ return 1;}