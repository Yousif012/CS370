# CS370 Lab 9
# May 1, 2024
# Yosif Yosif
# Makefile for Lab 9. It uses lex, yacc, and gcc to compile the program

all: lab9

lab9: lab9.l lab9.y ast.h ast.c emit.h emit.c
	lex lab9.l
	yacc -d lab9.y
	gcc -o lab9 ast.c emit.c lex.yy.c y.tab.c symtable.c

clean:
	rm -f lab9 lex.yy.c y.tab.c y.tab.h

