# CS370 Lab 1
# January 19, 2024
# Yosif Yosif
# makefile for Lab 1

all:	lab1

lab1:	lab1.l
		lex lab1.l
		gcc -o lab1 lex.yy.c

clean:
		rm -f lab1