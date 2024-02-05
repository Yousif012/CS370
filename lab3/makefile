# CS370 Lab 3
# February 5, 2024
# Yosif Yosif
# makefile for Lab 3

all: symtable

symtable: symtable.o
	gcc symtable.o -o symtable

symtable.o: symtable.c symbtab.h
	gcc -c symtable.c

clean:
	rm -f symtable
	rm -f symtable.o