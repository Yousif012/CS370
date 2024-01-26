# CS370 Lab 2.1
# January 26, 2024
# Yosif Yosif
# makefile for Lab 2.1. We have one file, "lab21.l", that is needed in our makefile

all:	lab21

lab21:	lab21.l
		lex lab21.l
		gcc -o lab21 lex.yy.c

clean:
		rm -f lab21
		rm -f lex.yy.c