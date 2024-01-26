# CS370 Lab 2.2
# January 26, 2024
# Yosif Yosif
# makefile for Lab 2.2. We have two files, "lab22.l" and "lab22.y", that is needed in our makefile

all:    lab22

lab22:  lab22.l lab22.y
		lex lab22.l
		yacc -d	lab22.y
		gcc lex.yy.c y.tab.c -o lab22

clean: 
	rm -f lab22
	rm -f lex.yy.c
	rm -f y.tab.c
	rm -f y.tab.h