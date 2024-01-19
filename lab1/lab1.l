     /*  This lex routine uses a counting array to match alphabeticstrings 
         and make a frequency count.
  
         The real item to notice is that yywrap() is called at EOF and then is run
         to do what we need to do.   yywrap() returns true when we have a successful 
         end to the program.  We may want to return false (0) if we want to lexing process 
         to fail 

        Shaun Cooper
        January 2015
   */
   /*
     Yosif Yosif
     Lab 1
     January 19, 2024
     Description:
          Made changes so that we count the number of numbers in a given file and print it out   
   */
	int lgths[100];
     int countOfNums = 0;
%%
[a-zA-Z]+	 {lgths[yyleng]++;}
[0-9]+     {countOfNums++; /* increments variable everytime we find a sequence of numbers */}
.	|
\n	;
%%

// Input: Nothing
// Output: Prints the the number of words for each length and also print the number of numbers
int yywrap()
{
	int i;
	printf("Length  No. words\n");

     // print the number of words for each length
	for (i=1; i<100; i++) {
		if (lgths[i] > 0) {
			printf("%5d%10d\n",i,lgths[i]);
		}
	}

     // Change: print the number of numbers with two printf statements
     printf("Total count of numbers\n");
     printf("%d\n", countOfNums);

	return(1);
}

// Input: Nothing
// Output: Runs yylex()
void main()
{  yylex();

}
