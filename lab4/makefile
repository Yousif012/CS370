# CS370 Lab 4
# February 16, 2024
# Yosif Yosif
# makefile for Lab 4. We have 4 files, "symbtab.h", "symtable.c", "lab4.l" and "lab4.y", that is needed in our makefile

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