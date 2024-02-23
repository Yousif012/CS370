# CS370 Lab 5
# February 16, 2024
# Yosif Yosif
# makefile for Lab 4. We have 4 files, "symbtab.h", "symtable.c", "lab5.l" and "lab5.y", that is needed in our makefile

all:    lab5

lab5:  lab5.l lab5.y
		lex lab5.l
		yacc -d	lab5.y
		gcc lex.yy.c y.tab.c -o lab5

clean: 
	rm -f lab5
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h