/*
 
CS370 Lab 3
February 3, 2024
Yosif Yosif

Description:

*/


#include <stdio.h>
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#ifndef SYMBTAB_H
#define SYMBTAB_H

struct SymbTab *Insert(char *symbol, int address);
void Display();
void Delete(char *symbol);
struct SymbTab *Search(char *symbol);

struct SymbTab
{
    char *symbol;
    int addr;
    struct SymbTab *next;
};

#endif
