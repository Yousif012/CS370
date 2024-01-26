         /* simple lex program which removes comments from a source program
            The main key is that a variable "comment" is set when the start of a comment
            is seen and then unset when the ending set is seen.  It is possible to have
            two starts closed by on end.

            Shaun Cooper
            January 2015
 
         */
/*
	Yosif Yosif
    Lab 2.2
    January 26, 2024
    Description:
		  In this lab, we will be adjusting the error messages by adding the line number that the error messages occur at.
*/
        int comment = 0;
        int debug=1;  /* prints out debug statements if desired */
        int ln = 1;
%%
"/*"	{
	if (comment && debug) fprintf(stderr,
		" >>>>>>>> line %d: Possible Nested comment <<<<<<<<<<\n", ln);
	comment = 1;
	}

"*/"	{
          if (!comment) printf("%s\n",yytext); /*print out if it is not in a comment */
  	  comment = 0;
	}

"\n" { ln++; }

.       { if (!comment) printf("%s\n",yytext);}



%%

int yywrap(void)
{ return 1;
}

void main()
{
  yylex();
   
}

