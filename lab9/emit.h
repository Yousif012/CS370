/*
    Yosif Yosif
    Lab 9
    May 1, 2024
    Description:
        In this file we define the function headers for emit.c
*/

#ifndef EMIT_H
#define EMIT_H
#include "ast.h"
#include <string.h>

#define W_SIZE 4
#define LOG_W_SIZE 2

void EMIT(ASTnode * p, FILE * fp);
void EMIT_GLOBALS(ASTnode * p, FILE * fp);
void EMIT_STRINGS(ASTnode * p, FILE * fp);
void EMIT_AST(ASTnode * p, FILE * fp);
char * CreateLabel();
void emit(FILE *fp, char * label, char * command, char * comment);
void emit_function(ASTnode * p, FILE * fp);
void emit_write(ASTnode * p, FILE * fp);
void emit_expr(ASTnode * p, FILE * fp);
void emit_read(ASTnode * p, FILE * fp);
void emit_var(ASTnode * p, FILE * fp);
void emit_assign(ASTnode * p, FILE * fp);
void emit_if(ASTnode * p, FILE * fp);
void emit_ifBody(ASTnode * p, FILE * fp);
void emit_while(ASTnode * p, FILE * fp);
void emit_param(ASTnode * p, FILE * fp);
void emit_call(ASTnode * p, FILE * fp);



#endif // of EMIT_H