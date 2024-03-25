# CS370 Lab 6
# March 25, 2024
# Yosif Yosif
# Makefile for Lab 6. It uses lex, yacc, and gcc to compile the program

all: lab6

lab6: lab6.l lab6.y ast.h ast.c
	lex lab6.l
	yacc -d lab6.y
	gcc -o lab6 ast.c lex.yy.c y.tab.c

clean:
	rm -f lab6 lex.yy.c y.tab.c y.tab.h

