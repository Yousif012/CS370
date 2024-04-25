/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

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

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
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




/* Copy the first part of user declarations.  */
#line 11 "lab7.y"



/* begin specs */
#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "ast.h" 
#include "symtable.h"
#include "emit.h"


int yylex();

extern int mydebug;
extern int linecount;

int LEVEL = 0; // global variable to know how far deep we are
int OFFSET = 0; // global variable for size of program
int GOFFSET = 0; // global variable for global variable offset
int maxOffset = 0; // largest offset needed for function

ASTnode * PROGRAM;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s at line number %d\n", s, linecount);
}




/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 46 "lab7.y"
{
      int value;
      char * string;
	  ASTnode * node;
	  enum AST_MY_DATA_TYPE d_type;
	  enum AST_OPERATORS operator;
}
/* Line 193 of yacc.c.  */
#line 183 "y.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 196 "y.tab.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   117

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  37
/* YYNRULES -- Number of rules.  */
#define YYNRULES  76
/* YYNRULES -- Number of states.  */
#define YYNSTATES  126

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      28,    29,     2,     2,    27,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    24,
       2,    32,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,    25,     2,    26,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    30,     2,    31,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    12,    14,    18,    20,
      22,    24,    29,    33,    40,    41,    42,    51,    53,    55,
      57,    61,    64,    69,    70,    76,    77,    80,    81,    84,
      86,    88,    90,    92,    94,    96,    98,   100,   103,   105,
     111,   119,   125,   128,   132,   136,   140,   144,   149,   151,
     156,   158,   160,   164,   166,   168,   170,   172,   174,   176,
     178,   182,   184,   186,   188,   192,   194,   196,   200,   202,
     204,   206,   209,   214,   216,   217,   219
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      34,     0,    -1,    35,    -1,    36,    -1,    36,    35,    -1,
      37,    -1,    40,    -1,    38,    39,    24,    -1,     6,    -1,
       7,    -1,     4,    -1,     4,    25,     3,    26,    -1,     4,
      27,    39,    -1,     4,    25,     3,    26,    27,    39,    -1,
      -1,    -1,    38,     4,    41,    28,    43,    29,    42,    46,
      -1,     7,    -1,    44,    -1,    45,    -1,    45,    27,    44,
      -1,    38,     4,    -1,    38,     4,    25,    26,    -1,    -1,
      30,    47,    48,    49,    31,    -1,    -1,    37,    48,    -1,
      -1,    50,    49,    -1,    51,    -1,    46,    -1,    52,    -1,
      53,    -1,    57,    -1,    54,    -1,    55,    -1,    56,    -1,
      59,    24,    -1,    24,    -1,    14,    28,    59,    29,    50,
      -1,    14,    28,    59,    29,    50,    15,    50,    -1,    16,
      28,    59,    29,    50,    -1,    17,    24,    -1,    17,    59,
      24,    -1,    19,    58,    24,    -1,    18,     5,    24,    -1,
      18,    59,    24,    -1,    58,    32,    60,    24,    -1,     4,
      -1,     4,    25,    59,    26,    -1,    60,    -1,    62,    -1,
      62,    61,    62,    -1,     8,    -1,     9,    -1,    10,    -1,
      11,    -1,    12,    -1,    13,    -1,    64,    -1,    64,    63,
      62,    -1,    20,    -1,    21,    -1,    66,    -1,    66,    65,
      64,    -1,    22,    -1,    23,    -1,    28,    59,    29,    -1,
       3,    -1,    58,    -1,    67,    -1,    21,    66,    -1,     4,
      28,    68,    29,    -1,    69,    -1,    -1,    59,    -1,    59,
      27,    69,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    75,    75,    78,    79,    86,    87,    90,   127,   128,
     131,   135,   140,   145,   154,   170,   153,   192,   193,   196,
     197,   201,   215,   232,   231,   249,   250,   257,   258,   265,
     266,   267,   268,   269,   270,   271,   272,   275,   280,   284,
     291,   301,   309,   311,   319,   326,   331,   339,   354,   380,
     409,   412,   413,   432,   433,   434,   435,   436,   437,   441,
     442,   462,   463,   465,   466,   486,   486,   488,   489,   495,
     496,   497,   506,   540,   540,   542,   552
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NUM", "T_ID", "T_STRING", "T_INT",
  "T_VOID", "T_LET", "T_LT", "T_BT", "T_BET", "T_EE", "T_NE", "T_IF",
  "T_ELSE", "T_WHILE", "T_RETURN", "T_WRITE", "T_READ", "T_ADD", "T_SUB",
  "T_STAR", "T_SLASH", "';'", "'['", "']'", "','", "'('", "')'", "'{'",
  "'}'", "'='", "$accept", "Program", "Declaration_List", "Declaration",
  "Var_Declaration", "Type_Specifier", "Var_List", "Fun_Declaration", "@1",
  "@2", "Params", "Params_List", "Param", "Compound_Stmt", "@3",
  "Local_Declarations", "Statement_List", "Statement", "Expression_Stmt",
  "Selection_Stmt", "Iteration_Stmt", "Return_Stmt", "Read_Stmt",
  "Write_Stmt", "Assignment_Stmt", "Var", "Expression",
  "Simple_Expression", "relop", "Additive_Expression", "Addop", "Term",
  "Multop", "Factor", "Call", "Args", "Args_List", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    59,    91,    93,    44,    40,    41,
     123,   125,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    38,    38,
      39,    39,    39,    39,    41,    42,    40,    43,    43,    44,
      44,    45,    45,    47,    46,    48,    48,    49,    49,    50,
      50,    50,    50,    50,    50,    50,    50,    51,    51,    52,
      52,    53,    54,    54,    55,    56,    56,    57,    58,    58,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    62,
      62,    63,    63,    64,    64,    65,    65,    66,    66,    66,
      66,    66,    67,    68,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     1,
       1,     4,     3,     6,     0,     0,     8,     1,     1,     1,
       3,     2,     4,     0,     5,     0,     2,     0,     2,     1,
       1,     1,     1,     1,     1,     1,     1,     2,     1,     5,
       7,     5,     2,     3,     3,     3,     3,     4,     1,     4,
       1,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     1,     1,     3,     1,     1,     3,     1,     1,
       1,     2,     4,     1,     0,     1,     3
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     9,     0,     2,     3,     5,     0,     6,     1,
       4,    10,     0,     0,     0,     0,     7,     0,    10,    12,
       0,    11,     9,     0,     0,    18,    19,     0,    21,    15,
       0,    13,     0,     0,    20,    22,    23,    16,    25,    25,
       0,    27,    26,    68,    48,     0,     0,     0,     0,     0,
       0,    38,     0,    30,     0,    27,    29,    31,    32,    34,
      35,    36,    33,    69,     0,    50,    51,    59,    63,    70,
       0,    74,     0,     0,    42,    69,     0,     0,     0,    48,
       0,    71,     0,    24,    28,     0,    37,    53,    54,    55,
      56,    57,    58,     0,    61,    62,     0,    65,    66,     0,
       0,    75,     0,    73,     0,     0,    43,    45,    46,    44,
      67,     0,    52,    60,    64,    49,     0,    72,     0,     0,
      47,    76,    39,    41,     0,    40
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    12,     8,    15,    33,
      24,    25,    26,    53,    38,    41,    54,    55,    56,    57,
      58,    59,    60,    61,    62,    75,    64,    65,    93,    66,
      96,    67,    99,    68,    69,   102,   103
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -115
static const yytype_int8 yypact[] =
{
      13,  -115,  -115,    15,  -115,    13,  -115,    17,  -115,  -115,
    -115,    36,    26,    55,    35,    41,  -115,    48,   -18,  -115,
      39,    52,    51,    77,    53,  -115,    57,    35,    60,  -115,
      13,  -115,    61,    56,  -115,  -115,  -115,  -115,    13,    13,
      35,    14,  -115,  -115,     9,    62,    63,    19,     8,    84,
      45,  -115,    45,  -115,    58,    14,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,    64,    68,  -115,    44,    47,    49,  -115,
      45,    45,    45,    45,  -115,  -115,    69,    70,    71,    72,
      74,  -115,    73,  -115,  -115,    45,  -115,  -115,  -115,  -115,
    -115,  -115,  -115,    45,  -115,  -115,    45,  -115,  -115,    45,
      75,    76,    78,  -115,    79,    80,  -115,  -115,  -115,  -115,
    -115,    81,  -115,  -115,  -115,  -115,    45,  -115,    14,    14,
    -115,  -115,    85,  -115,    14,  -115
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -115,  -115,    94,  -115,    37,    21,   -11,  -115,  -115,  -115,
    -115,    82,  -115,    83,  -115,    65,    59,  -114,  -115,  -115,
    -115,  -115,  -115,  -115,  -115,   -41,   -46,    25,  -115,   -31,
    -115,     7,  -115,    67,  -115,  -115,    -5
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -18
static const yytype_int8 yytable[] =
{
      63,    76,    78,    19,   122,   123,    82,    13,    80,    14,
     125,    43,    44,    77,    63,     9,    31,    43,    44,     1,
       2,    11,    43,    44,   100,   101,   104,   105,    45,    50,
      46,    47,    48,    49,    70,    50,    52,    71,    51,    18,
      50,    23,    52,    74,    36,     1,    22,    52,    43,    44,
      16,    23,    87,    88,    89,    90,    91,    92,    17,    40,
      40,    13,   112,    14,   -14,   113,    50,    94,    95,    20,
     101,    97,    98,    52,    21,    39,    39,    63,    63,    27,
     -17,    28,    29,    63,    30,    32,    36,    35,    79,    83,
      72,    73,    86,   106,   107,   108,    85,    70,   109,    10,
     124,   115,   110,   116,    42,   120,   114,   117,   118,   119,
     111,   121,    34,     0,    84,     0,    37,    81
};

static const yytype_int8 yycheck[] =
{
      41,    47,    48,    14,   118,   119,    52,    25,    49,    27,
     124,     3,     4,     5,    55,     0,    27,     3,     4,     6,
       7,     4,     3,     4,    70,    71,    72,    73,    14,    21,
      16,    17,    18,    19,    25,    21,    28,    28,    24,     4,
      21,    20,    28,    24,    30,     6,     7,    28,     3,     4,
      24,    30,     8,     9,    10,    11,    12,    13,     3,    38,
      39,    25,    93,    27,    28,    96,    21,    20,    21,    28,
     116,    22,    23,    28,    26,    38,    39,   118,   119,    27,
      29,     4,    29,   124,    27,    25,    30,    26,     4,    31,
      28,    28,    24,    24,    24,    24,    32,    25,    24,     5,
      15,    26,    29,    27,    39,    24,    99,    29,    29,    29,
      85,   116,    30,    -1,    55,    -1,    33,    50
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    34,    35,    36,    37,    38,    40,     0,
      35,     4,    39,    25,    27,    41,    24,     3,     4,    39,
      28,    26,     7,    38,    43,    44,    45,    27,     4,    29,
      27,    39,    25,    42,    44,    26,    30,    46,    47,    37,
      38,    48,    48,     3,     4,    14,    16,    17,    18,    19,
      21,    24,    28,    46,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    62,    64,    66,    67,
      25,    28,    28,    28,    24,    58,    59,     5,    59,     4,
      58,    66,    59,    31,    49,    32,    24,     8,     9,    10,
      11,    12,    13,    61,    20,    21,    63,    22,    23,    65,
      59,    59,    68,    69,    59,    59,    24,    24,    24,    24,
      29,    60,    62,    62,    64,    26,    27,    29,    29,    29,
      24,    69,    50,    50,    15,    50
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (YYLEX_PARAM)
#else
# define YYLEX yylex ()
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule)
#else
static void
yy_reduce_print (yyvsp, yyrule)
    YYSTYPE *yyvsp;
    int yyrule;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
int yydebug;
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
#else
static void
yydestruct (yymsg, yytype, yyvaluep)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
#endif
{
  YYUSE (yyvaluep);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (void);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */



/* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void)
#else
int
yyparse ()

#endif
#endif
{
  
  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 75 "lab7.y"
    { PROGRAM = (yyvsp[(1) - (1)].node); }
    break;

  case 3:
#line 78 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 4:
#line 80 "lab7.y"
    {
					(yyval.node) = (yyvsp[(1) - (2)].node);
					if((yyvsp[(1) - (2)].node) != NULL) (yyval.node)->next = (yyvsp[(2) - (2)].node);
				 }
    break;

  case 5:
#line 86 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 6:
#line 87 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 7:
#line 91 "lab7.y"
    { 
				  // populate the s1 connected list with the
				  // defined type via $1

				  ASTnode *p = (yyvsp[(2) - (3)].node);
				  while ( p != NULL ){
					p->my_data_type = (yyvsp[(1) - (3)].d_type);

					// check if variable already defined at current level
					if(Search(p->name, LEVEL, 0) != NULL){
						// if symbol found, BARF
						yyerror(p->name);
						yyerror("Symbol already defined");
						exit(1);
					}

					// variable not in symbol table
					// variable is scalar
					if(p->value == 0){
						p->symbol = Insert(p->name, p->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
						OFFSET += 1;
					}

					// variable is array
					else{
						p->symbol = Insert(p->name, p->my_data_type, SYM_ARRAY, LEVEL, p->value, OFFSET);
						OFFSET += p->value;
					}

					p = p->s1;

				  }
				  (yyval.node) = (yyvsp[(2) - (3)].node); 
				}
    break;

  case 8:
#line 127 "lab7.y"
    { (yyval.d_type) = A_INTTYPE; }
    break;

  case 9:
#line 128 "lab7.y"
    { (yyval.d_type) = A_VOIDTYPE; }
    break;

  case 10:
#line 132 "lab7.y"
    { (yyval.node) = ASTCreateNode(A_VARDEC); 
			 (yyval.node)->name = (yyvsp[(1) - (1)].string); 
		   }
    break;

  case 11:
#line 136 "lab7.y"
    { (yyval.node) = ASTCreateNode(A_VARDEC); 
		     (yyval.node)->value = (yyvsp[(3) - (4)].value);
		     (yyval.node)->name = (yyvsp[(1) - (4)].string); 
		   }
    break;

  case 12:
#line 141 "lab7.y"
    { (yyval.node) = ASTCreateNode(A_VARDEC); 
			 (yyval.node)->name = (yyvsp[(1) - (3)].string); 
			 (yyval.node)->s1 = (yyvsp[(3) - (3)].node);
		   }
    break;

  case 13:
#line 146 "lab7.y"
    { (yyval.node) = ASTCreateNode(A_VARDEC); 
			 (yyval.node)->name = (yyvsp[(1) - (6)].string); 
			 (yyval.node)->value = (yyvsp[(3) - (6)].value);
			 (yyval.node)->s1 = (yyvsp[(6) - (6)].node);
		   }
    break;

  case 14:
#line 154 "lab7.y"
    {
					// check if function has been defined
					if(Search((yyvsp[(2) - (2)].string), LEVEL, 0) != NULL){
						// T_ID has already been used, BARF
						yyerror((yyvsp[(2) - (2)].string));
						yyerror("function name already in use");
						exit(1);
					}
					// not in symbol table, insert it
					Insert((yyvsp[(2) - (2)].string), (yyvsp[(1) - (2)].d_type), SYM_FUNCTION, LEVEL, 0, 0);

					GOFFSET = OFFSET;
					OFFSET = 2;
					maxOffset = OFFSET;
				}
    break;

  case 15:
#line 170 "lab7.y"
    { 
				  // add ASTnode to the symbol structure
				  Search((yyvsp[(2) - (6)].string), LEVEL, 0)->fparms = (yyvsp[(5) - (6)].node);
				}
    break;

  case 16:
#line 175 "lab7.y"
    { 
					(yyval.node) = ASTCreateNode(A_FUNCTIONDEC);
				    (yyval.node)->name = (yyvsp[(2) - (8)].string);
				    (yyval.node)->my_data_type = (yyvsp[(1) - (8)].d_type);
				    (yyval.node)->s1 = (yyvsp[(5) - (8)].node);
					(yyval.node)->s2 = (yyvsp[(8) - (8)].node); 

					// change offset in symbol struct
					struct SymbTab *p;
					p = Search((yyvsp[(2) - (8)].string), LEVEL, 0);
					p->offset = maxOffset;
					(yyval.node)->symbol = p;
					
					OFFSET = GOFFSET;
				}
    break;

  case 17:
#line 192 "lab7.y"
    { (yyval.node) = NULL; }
    break;

  case 18:
#line 193 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 19:
#line 196 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 20:
#line 198 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (3)].node); 
			  (yyval.node)->next = (yyvsp[(3) - (3)].node); }
    break;

  case 21:
#line 202 "lab7.y"
    { 
		  // check if parameter already defined
		  if(Search((yyvsp[(2) - (2)].string), LEVEL+1, 0) != NULL){
			yyerror((yyvsp[(2) - (2)].string));
			yyerror("Parameter already used");
			exit(1);
		  }
		  (yyval.node) = ASTCreateNode(A_PARAM);
		  (yyval.node)->name = (yyvsp[(2) - (2)].string);
		  (yyval.node)->my_data_type = (yyvsp[(1) - (2)].d_type);
		  (yyval.node)->symbol = Insert((yyval.node)->name, (yyval.node)->my_data_type, SYM_SCALAR, LEVEL+1, 1, OFFSET);
		  OFFSET++;
		}
    break;

  case 22:
#line 216 "lab7.y"
    { 
		  // check if parameter already defined
		  if(Search((yyvsp[(2) - (4)].string), LEVEL+1, 0) != NULL){
			yyerror((yyvsp[(2) - (4)].string));
			yyerror("Parameter already used");
			exit(1);
		  }
		  (yyval.node) = ASTCreateNode(A_PARAM);
		  (yyval.node)->name = (yyvsp[(2) - (4)].string);
		  (yyval.node)->my_data_type = (yyvsp[(1) - (4)].d_type);
		  (yyval.node)->symbol = Insert((yyval.node)->name, (yyval.node)->my_data_type, SYM_ARRAY, LEVEL+1, 1, OFFSET);
		  OFFSET++;
		}
    break;

  case 23:
#line 232 "lab7.y"
    { 
				LEVEL ++; 
			  }
    break;

  case 24:
#line 236 "lab7.y"
    {
				(yyval.node) = ASTCreateNode(A_COMPOUND);
				(yyval.node)->s1 = (yyvsp[(3) - (5)].node);
				(yyval.node)->s2 = (yyvsp[(4) - (5)].node);

				if(mydebug) Display();
				// adjust offset and level when exiting compound statement
				if(OFFSET > maxOffset) maxOffset = OFFSET;
				OFFSET -= Delete(LEVEL);
				LEVEL --;
			  }
    break;

  case 25:
#line 249 "lab7.y"
    { (yyval.node) = NULL; }
    break;

  case 26:
#line 251 "lab7.y"
    { 
					 (yyval.node) = (yyvsp[(1) - (2)].node);
				     if((yyvsp[(1) - (2)].node) != NULL) (yyval.node)->next = (yyvsp[(2) - (2)].node);
				   }
    break;

  case 27:
#line 257 "lab7.y"
    { (yyval.node) = NULL; }
    break;

  case 28:
#line 259 "lab7.y"
    {
				(yyval.node) = (yyvsp[(1) - (2)].node);
				(yyval.node)->next = (yyvsp[(2) - (2)].node);
			   }
    break;

  case 29:
#line 265 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 30:
#line 266 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 31:
#line 267 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 32:
#line 268 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 33:
#line 269 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 34:
#line 270 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 35:
#line 271 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 36:
#line 272 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 37:
#line 276 "lab7.y"
    { 
					(yyval.node) = ASTCreateNode(A_EXPR_STMT);
					(yyval.node)->s1 = (yyvsp[(1) - (2)].node);
				}
    break;

  case 38:
#line 280 "lab7.y"
    { (yyval.node) = ASTCreateNode(A_EXPR_STMT); }
    break;

  case 39:
#line 285 "lab7.y"
    {
				 (yyval.node) = ASTCreateNode(A_IF);
				 (yyval.node)->s1 = (yyvsp[(3) - (5)].node);
				 (yyval.node)->s2 = ASTCreateNode(A_IFBODY);
				 (yyval.node)->s2->s1 = (yyvsp[(5) - (5)].node);
				}
    break;

  case 40:
#line 292 "lab7.y"
    {
				 (yyval.node) = ASTCreateNode(A_IF);
				 (yyval.node)->s1 = (yyvsp[(3) - (7)].node);
				 (yyval.node)->s2 = ASTCreateNode(A_IFBODY);
				 (yyval.node)->s2->s1 = (yyvsp[(5) - (7)].node);
				 (yyval.node)->s2->s2 = (yyvsp[(7) - (7)].node);
				}
    break;

  case 41:
#line 302 "lab7.y"
    {
				(yyval.node) = ASTCreateNode(A_WHILE);
				(yyval.node)->s1 = (yyvsp[(3) - (5)].node);
				(yyval.node)->s2 = (yyvsp[(5) - (5)].node);
			   }
    break;

  case 42:
#line 310 "lab7.y"
    { (yyval.node) = ASTCreateNode(A_RETURN); }
    break;

  case 43:
#line 312 "lab7.y"
    { 
				(yyval.node) = ASTCreateNode(A_RETURN); 
				(yyval.node)->s1 = (yyvsp[(2) - (3)].node);
			}
    break;

  case 44:
#line 320 "lab7.y"
    {
			(yyval.node) = ASTCreateNode(A_READ);
			(yyval.node)->s1 = (yyvsp[(2) - (3)].node);
		  }
    break;

  case 45:
#line 327 "lab7.y"
    { 
			 (yyval.node) = ASTCreateNode(A_WRITE);
			 (yyval.node)->name = (yyvsp[(2) - (3)].string);
		   }
    break;

  case 46:
#line 332 "lab7.y"
    {
			 (yyval.node) = ASTCreateNode(A_WRITE);
			 (yyval.node)->s1 = (yyvsp[(2) - (3)].node);
		   }
    break;

  case 47:
#line 340 "lab7.y"
    {
					if((yyvsp[(1) - (4)].node)->my_data_type != (yyvsp[(3) - (4)].node)->my_data_type){
						yyerror("Type Mismatch");
						exit(1);
					 }
					(yyval.node) = ASTCreateNode(A_ASSIGN);
					(yyval.node)->s1 = (yyvsp[(1) - (4)].node);
					(yyval.node)->s2 = (yyvsp[(3) - (4)].node);
					(yyval.node)->name = CreateTemp();
					(yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[(1) - (4)].node)->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
					OFFSET++;
				}
    break;

  case 48:
#line 355 "lab7.y"
    { 
		struct SymbTab *p;
		p = Search((yyvsp[(1) - (1)].string), LEVEL, 1);

		// check if variable defined
		if(p == NULL){
			// variable not defined within scope
			yyerror((yyvsp[(1) - (1)].string));
			yyerror("symbol used but not defined");
			exit(1);
		}

		// verify if variable is scalar
		if (p->SubType != SYM_SCALAR){
			// variable is used as scalar but not scalar
			yyerror((yyvsp[(1) - (1)].string));
			yyerror("symbol must be scalar");
			exit(1);
		}

		(yyval.node) = ASTCreateNode(A_VAR);
	   	(yyval.node)->name = (yyvsp[(1) - (1)].string);
		(yyval.node)->symbol = p;
		(yyval.node)->my_data_type = p->Declared_Type;
	}
    break;

  case 49:
#line 381 "lab7.y"
    { 
		struct SymbTab *p;
		p = Search((yyvsp[(1) - (4)].string), LEVEL, 1);

		// check if variable defined
		if(p == NULL){
			// variable not defined within scope
			yyerror((yyvsp[(1) - (4)].string));
			yyerror("symbol used but not defined");
			exit(1);
		}

		// verify if variable is array
		if (p->SubType != SYM_ARRAY){
			// variable is used as array but not array
			yyerror((yyvsp[(1) - (4)].string));
			yyerror("symbol must be array");
			exit(1);
		}

		(yyval.node) = ASTCreateNode(A_VAR);
	   	(yyval.node)->name = (yyvsp[(1) - (4)].string);
		(yyval.node)->s1 = (yyvsp[(3) - (4)].node);
		(yyval.node)->symbol = p;
		(yyval.node)->my_data_type = p->Declared_Type;
	}
    break;

  case 50:
#line 409 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 51:
#line 412 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 52:
#line 414 "lab7.y"
    {

					// check if variables are same type
					if((yyvsp[(1) - (3)].node)->my_data_type != (yyvsp[(3) - (3)].node)->my_data_type){
						yyerror("Type Mismatch");
						exit(1);
					 }

					 (yyval.node) = ASTCreateNode(A_EXPR); 
					 (yyval.node)->s1 = (yyvsp[(1) - (3)].node);
					 (yyval.node)->s2 = (yyvsp[(3) - (3)].node);
					 (yyval.node)->operator = (yyvsp[(2) - (3)].operator);
					 (yyval.node)->name = CreateTemp();
					 (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[(1) - (3)].node)->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
					 (yyval.node)->my_data_type = (yyvsp[(1) - (3)].node)->my_data_type;
					 OFFSET++;
					}
    break;

  case 53:
#line 432 "lab7.y"
    { (yyval.operator) = A_LET; }
    break;

  case 54:
#line 433 "lab7.y"
    { (yyval.operator) = A_LT; }
    break;

  case 55:
#line 434 "lab7.y"
    { (yyval.operator) = A_BT; }
    break;

  case 56:
#line 435 "lab7.y"
    { (yyval.operator) = A_BET; }
    break;

  case 57:
#line 436 "lab7.y"
    { (yyval.operator) = A_EE; }
    break;

  case 58:
#line 437 "lab7.y"
    { (yyval.operator) = A_NE; }
    break;

  case 59:
#line 441 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 60:
#line 443 "lab7.y"
    {

					 // check if variables are same type
					 if((yyvsp[(1) - (3)].node)->my_data_type != (yyvsp[(3) - (3)].node)->my_data_type){
						yyerror("Type Mismatch");
						exit(1);
					 }

					 (yyval.node) = ASTCreateNode(A_EXPR);
					 (yyval.node)->s1 = (yyvsp[(1) - (3)].node);
					 (yyval.node)->s2 = (yyvsp[(3) - (3)].node);
					 (yyval.node)->operator = (yyvsp[(2) - (3)].operator);
					 (yyval.node)->my_data_type = (yyvsp[(1) - (3)].node)->my_data_type;
					 (yyval.node)->name = CreateTemp();
					 (yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[(1) - (3)].node)->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
					 OFFSET++;
					}
    break;

  case 61:
#line 462 "lab7.y"
    { (yyval.operator) = A_PLUS; }
    break;

  case 62:
#line 463 "lab7.y"
    { (yyval.operator) = A_MINUS; }
    break;

  case 63:
#line 465 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 64:
#line 467 "lab7.y"
    { 

		// check if variables are same type
		if((yyvsp[(1) - (3)].node)->my_data_type != (yyvsp[(3) - (3)].node)->my_data_type){
			yyerror("Type Mismatch");
			exit(1);
		}
		
		(yyval.node) = ASTCreateNode(A_EXPR);
		(yyval.node)->s1 = (yyvsp[(1) - (3)].node);
		(yyval.node)->s2 = (yyvsp[(3) - (3)].node);
		(yyval.node)->operator = (yyvsp[(2) - (3)].operator);
		(yyval.node)->my_data_type = (yyvsp[(1) - (3)].node)->my_data_type;
		(yyval.node)->name = CreateTemp();
		(yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[(1) - (3)].node)->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
		OFFSET++;
	 }
    break;

  case 65:
#line 486 "lab7.y"
    { (yyval.operator) = A_MULT; }
    break;

  case 66:
#line 486 "lab7.y"
    { (yyval.operator) = A_DIV; }
    break;

  case 67:
#line 488 "lab7.y"
    { (yyval.node) = (yyvsp[(2) - (3)].node); }
    break;

  case 68:
#line 490 "lab7.y"
    { 
		 (yyval.node) = ASTCreateNode(A_NUM);
	   	 (yyval.node)->value = (yyvsp[(1) - (1)].value); 
		 (yyval.node)->my_data_type = A_INTTYPE;
	   }
    break;

  case 69:
#line 495 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 70:
#line 496 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 71:
#line 498 "lab7.y"
    { 
		(yyval.node) = ASTCreateNode(A_EXPR);
		(yyval.node)->operator = A_UMINUS;
		(yyval.node)->s1 = (yyvsp[(2) - (2)].node); 
		(yyval.node)->my_data_type = (yyval.node)->s1->my_data_type;
	   }
    break;

  case 72:
#line 507 "lab7.y"
    { 
		struct SymbTab *p;
		p = Search((yyvsp[(1) - (4)].string), 0, 0);
		if(p == NULL){
			// function not defined
			yyerror((yyvsp[(1) - (4)].string));
			yyerror("function not defined");
			exit(1);
		}

		// name is there but is it a function?
		if(p->SubType != SYM_FUNCTION){
			// function name is not related to a function declaration but to a variable
			yyerror((yyvsp[(1) - (4)].string));
			yyerror("not defined as function");
			exit(1);
		}

		// check if parameters length and type are correct
		if(check_params((yyvsp[(3) - (4)].node), p->fparms) == 0){
			yyerror((yyvsp[(1) - (4)].string));
			yyerror("Actual and Formals do not match");
			exit(1);
		}
		
	   (yyval.node) = ASTCreateNode(A_CALL);
	   (yyval.node)->name = (yyvsp[(1) - (4)].string);
	   (yyval.node)->s1 = (yyvsp[(3) - (4)].node);
	   (yyval.node)->symbol = p;
	   (yyval.node)->my_data_type = p->Declared_Type;
	 }
    break;

  case 73:
#line 540 "lab7.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); }
    break;

  case 74:
#line 540 "lab7.y"
    { (yyval.node) = NULL; }
    break;

  case 75:
#line 543 "lab7.y"
    { 
			(yyval.node) = ASTCreateNode(A_ARG);
			(yyval.node)->s1 = (yyvsp[(1) - (1)].node);
			(yyval.node)->my_data_type = (yyvsp[(1) - (1)].node)->my_data_type;

			(yyval.node)->name = CreateTemp();
			(yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[(1) - (1)].node)->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
			OFFSET++;
		  }
    break;

  case 76:
#line 553 "lab7.y"
    { 
			(yyval.node) = ASTCreateNode(A_ARG);
			(yyval.node)->s1 = (yyvsp[(1) - (3)].node);
			(yyval.node)->next = (yyvsp[(3) - (3)].node);
			(yyval.node)->my_data_type = (yyvsp[(1) - (3)].node)->my_data_type;

			(yyval.node)->name = CreateTemp();
			(yyval.node)->symbol = Insert((yyval.node)->name, (yyvsp[(1) - (3)].node)->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
			OFFSET++;
		  }
    break;


/* Line 1267 of yacc.c.  */
#line 2195 "y.tab.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    yyerror (yymsg);
	  }
	else
	  {
	    yyerror (YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 565 "lab7.y"
	/* end of rules, start of program */

int main(int argc, char *argv[])
{ 
  FILE *fp;

  int i;
  char s[100];
  for(i = 0; i<argc; i++){
	if(strcmp(argv[i], "-d") == 0) mydebug = 1;
	if(strcmp(argv[i], "-o") == 0){
		strcpy(s, argv[i+1]);
		strcat(s, ".asm");
		printf("File name is %s \n", s);
	} 
	printf("%s\n", argv[i]);
  }
  
  fp = fopen(s, "w");
  if(fp == NULL){
	printf("cannot open file %s\n", s);
	exit(1);
  }

  yyparse();

  if(mydebug){
  	printf("Finished parsing\n");
	Display(); // shows our global variables
	printf("\n\n\nAST PRINT \n\n\n");
	ASTprint(0, PROGRAM);
  }

  EMIT(PROGRAM, fp);
  
}

