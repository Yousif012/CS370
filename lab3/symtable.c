/*
 
CS370 Lab 3
February 5, 2024
Yosif Yosif

Description:
In this lab, we modify this file in the following ways:

- indent and comment the code
- remove all instances of "label"
- change the symbol variable to be a pointer instead of an array
- move the function prototypes to the symbtab.h file
- modify the functions so that they don't take user inputs and
  the user input gets taken in the main function only.
- remove "Modify()" function

In this code, we use a "Linked List" data structure to represent the symbol table.
This linked list is called SymbTab and it contains a value, and address, and pointer
to the next structure (just like in a linked list). The address is the address where
the value is stored.

We are using malloc in this code. Malloc is a dynamic memory method that allows us
to give variables a dynamic size. We need malloc in this case as we don't know how
big the structure SymbTab could be. This is due to one of its components, symbol, which
is a pointer to an array that could take up to 10 characters.

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
void main()
{
    int op, addr;
    struct SymbTab * y;
    char sym[10];
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

} /* and of main */

// PRE CONDITION: PTR to character string
// POST CONDITION: PTR to structure new symbol
// Assumptions: assumes that the pointer points to a character array
struct SymbTab *Insert(char *sym, int address)
{
    struct SymbTab *n = Search(sym);
    if (n != NULL)
    {
        printf("\n\tThe symbol exists already in the symbol table\n\tDuplicate can.t be inserted");
        return NULL;
    }
    else
    {
        struct SymbTab *p;
        p = malloc(sizeof(struct SymbTab));
        p->symbol = strdup(sym);
        strcpy(p->symbol, sym);
        p->addr = address;
        p->next = NULL;
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
    for (i = 0; i < size; i++)
    {
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
    if (a == NULL)
        printf("\n\tSymbol not found\n");
    else
    {
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
