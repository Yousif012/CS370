/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015 Free Software Foundation, Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <http://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

#ifndef YY_YY_Y_TAB_H_INCLUDED
# define YY_YY_Y_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    T_NUM = 258,
    T_ID = 259,
    T_STRING = 260,
    T_INT = 261,
    T_VOID = 262,
    T_LET = 263,
    T_LT = 264,
    T_BT = 265,
    T_BET = 266,
    T_EE = 267,
    T_NE = 268,
    T_IF = 269,
    T_ELSE = 270,
    T_WHILE = 271,
    T_RETURN = 272,
    T_WRITE = 273,
    T_READ = 274,
    T_ADD = 275,
    T_SUB = 276,
    T_STAR = 277,
    T_SLASH = 278
  };
#endif
/* Tokens.  */
#define T_NUM 258
#define T_ID 259
#define T_STRING 260
#define T_INT 261
#define T_VOID 262
#define T_LET 263
#define T_LT 264
#define T_BT 265
#define T_BET 266
#define T_EE 267
#define T_NE 268
#define T_IF 269
#define T_ELSE 270
#define T_WHILE 271
#define T_RETURN 272
#define T_WRITE 273
#define T_READ 274
#define T_ADD 275
#define T_SUB 276
#define T_STAR 277
#define T_SLASH 278

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 40 "lab7.y" /* yacc.c:1909  */

      int value;
      char * string;
	  ASTnode * node;
	  enum AST_MY_DATA_TYPE d_type;
	  enum AST_OPERATORS operator;

#line 108 "y.tab.h" /* yacc.c:1909  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */
