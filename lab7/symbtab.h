/*
 
CS370 Lab 4
February 16, 2024
Yosif Yosif

Description:
We modify this file by adding a new prototype for function FetchAddress that takes a symbol string and returns an address
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
int FetchAddress(char *s); // takes symbol and returns related address

struct SymbTab
{
    char *symbol;
    int addr;
    struct SymbTab *next;
};

#endif
