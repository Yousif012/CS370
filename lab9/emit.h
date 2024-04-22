#ifndef EMIT_H
#define EMIT_H
#include "ast.h"
#include <string.h>

#define W_SIZE 4
#define LOG_W_SIZE 2

void EMIT(ASTnode * p, FILE * fp);
void EMIT_GLOBALS(ASTnode * p, FILE * fp);
void EMIT_STRINGS(ASTnode * p, FILE * fp);
char * CreateLabel();


#endif // of EMIT_H