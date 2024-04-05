/*
 
CS370 Lab 4
February 5, 2024
Yosif Yosif

Description:
In this lab, we modify this file by adding a new function

This new function is called FetchAddress. It takes a string that resembles a symbol
and then returns the address of this symbol if found in the symbol table. If not found,
the program will exit.

We find the symbol and return its address by iterating over the linked list and comparing
the value of each node with the wanted value. if found, we return the address.

*/




#include <stdio.h>
/* #include<conio.h> */
#include <malloc.h>
#include <string.h>
#include <stdlib.h>

#include "symbtab.h"

int size = 0;
struct SymbTab *first, *last;

// PRE CONDITION: No precondition
// POST CONDITION: prompts the user for input and gives corresponding output
// Assumptions: assumes user input is valid

/*
void main()
{
    int op, addr;
    struct SymbTab * y;
    char sym[100];
    do
    {
        printf("\n\tSYMBOL TABLE IMPLEMENTATION\n");
        printf("\n\t1.INSERT\n\t2.DISPLAY\n\t3.DELETE\n\t4.SEARCH\n\t5.MODIFY\n\t6.END\n");
        printf("\n\tEnter your option : ");
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            printf("\n\tEnter the symbol : ");
            scanf("%s", sym);
            printf("\n\tEnter the address: ");
            scanf("%d", &addr);
            Insert(sym, addr);
            break;
        case 2:
            Display();
            break;
        case 3:
            printf("\n\tEnter the symbol to be deleted : ");
            scanf("%s", sym);
            Delete(sym);
            break;
        case 4:
            printf("\n\tEnter the symbol to be searched : ");
            scanf("%s", sym);
            y = Search(sym);
            printf("\n\tSearch Result:");
            if (y != NULL)
                printf("\n\tThe symbol is present in the symbol table\n");
            else
                printf("\n\tThe symbol is not present in the symbol table\n");
            break;
        case 5:
            exit(0);
        }
    } while (op < 6);

}*/ /* and of main */

// PRE CONDITION: PTR to character string
// POST CONDITION: PTR to structure new symbol
// Assumptions: assumes that the pointer points to a character array
struct SymbTab *Insert(char *sym, int address)
{
    struct SymbTab *n = Search(sym);

    // if symbol already in symbol table, error out
    // else, add symbol
    if (n != NULL)
    {
        printf("\n\tThe symbol exists already in the symbol table\n\tDuplicate can.t be inserted");
        return NULL;
    }
    else
    {
        // copy the given symbol and address into a SymbTab structure
        struct SymbTab *p;
        p = malloc(sizeof(struct SymbTab));
        p->symbol = strdup(sym);
        strcpy(p->symbol, sym);
        p->addr = address;
        p->next = NULL;

        // handle if the symbol was the first to be inserted
        // otherwise, just attach to the end of the linked list
        if (size == 0)
        {
            first = p;
            last = p;
        }
        else
        {
            last->next = p;
            last = p;
        }
        size++;
        printf("\n\tSymbol inserted\n");
        return p;
    }
}

// PRE CONDITION: no precondition 
// POST CONDITION: displays all symbols within the symbol table
// Assumptions: No assumptions are made
void Display()
{
    int i;
    struct SymbTab *p;
    p = first;
    printf("\n\tSYMBOL\t\tADDRESS\n");
    // go through the linked list and print its contents
    for (i = 0; i < size; i++)
    {
        printf("\t%s\t\t%d\n", p->symbol, p->addr);
        p = p->next;
    }
}

// PRE CONDITION: PTR to character string
// POST CONDITION: PTR to matching structure or NULL
// Assumptions: assumes that the pointer points to a character array
struct SymbTab *Search(char *sym)
{
    int i, flag = 0;
    struct SymbTab *p;
    p = first;

    // go through the linked list and check and match contents with the given symbol
    for (i = 0; i < size; i++)
    {
        // check if symbol matches
        if (strcmp(p->symbol, sym) == 0){
            flag = 1;
            return p;
        }
        p = p->next;
    }
    return NULL;
}

// PRE CONDITION: PTR to character string
// POST CONDITION: no post condition, either deletes the symbol or not
// Assumptions: assumes that the pointer points to a character array
void Delete(char *sym)
{
    struct SymbTab *a;
    struct SymbTab *p, *q;
    p = first;

    a = Search(sym);
    // if symbol not in symbol table, no need to delete
    // else, find and delete symbol
    if (a == NULL)
        printf("\n\tSymbol not found\n");

    // change pointers in the linked list when a node is removed
    else
    {
        // check if symbol is first in the list
        // if not, check if it is last
        // else, go over the list and check every item
        if (strcmp(first->symbol, sym) == 0)
            first = first->next;
        else if (strcmp(last->symbol, sym) == 0)
        {
            q = p->next;
            while (strcmp(q->symbol, sym) != 0)
            {
                p = p->next;
                q = q->next;
            }
            p->next = NULL;
            last = p;
        }
        else
        {
                q = p->next;
                // slow and fast pointers to the list, so when we find the right node
                // we can easily remove the node and change pointers
                while (strcmp(q->symbol, sym) != 0){
                    p=p->next;
                    q = q->next;
                    }
            p->next = q->next;
        }
        size--;
        printf("\n\tAfter Deletion:\n");
        Display();
    }
}


// PRE CONDITION: PTR to character string
// POST CONDITION: address of symbol if found, otherwise BARF
// Assumptions: no assumptions
int FetchAddress(char *s){
    struct SymbTab *p;
    p = first;

    while (p != NULL){
        if(strcmp(p->symbol, s) == 0) return p->addr;
        p = p->next;
    }
    printf("variable doesn't exist");
    exit(1);
    return -1;
}