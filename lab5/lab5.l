
%{

int mydebug=1;
#include "y.tab.h"
%}


%%

int   {return (T_INT);}
void {return (T_VOID);}

if {if (mydebug) fprintf(stderr,"if found\n");
    return (T_IF);}

else {if (mydebug) fprintf(stderr,"else found\n");
      return (T_ELSE);}
return {return (T_RETURN);}
while {return (T_WHILE);}
read {return (T_READ);}
write {return (T_WRITE);} 

"<=" {if (mydebug) fprintf(stderr,"less than or equal found\n");
      return (T_LET);}
"<" {return (T_LT);}
">" {return (T_BT);}
">=" {return (T_BET);}
"==" {return (T_EE);}
"!=" {return (T_NE);}


[a-zA-Z][a-zA-Z0-9_]*		{if (mydebug) fprintf(stderr,"ID found\n"); 
                        
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