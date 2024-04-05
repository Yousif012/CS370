# CS370 Lab 6
# March 25, 2024
# Yosif Yosif
# Makefile for Lab 7. It uses lex, yacc, and gcc to compile the program

all: lab7

lab7: lab7.l lab7.y ast.h ast.c
	lex lab7.l
	yacc -d lab7.y
	gcc -o lab7 ast.c lex.yy.c y.tab.c

clean:
	rm -f lab7 lex.yy.c y.tab.c y.tab.h

