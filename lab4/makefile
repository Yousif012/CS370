# CS370 Lab 2.2
# January 26, 2024
# Yosif Yosif
# makefile for Lab 2.2. We have two files, "lab22.l" and "lab22.y", that is needed in our makefile

all:    lab4

lab4:  lab4.l lab4.y symbtab.h symtable.c
		lex lab4.l
		yacc -d	lab4.y
		gcc symtable.c symbtab.h lex.yy.c y.tab.c -o lab4

clean: 
	rm -f lab4
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h