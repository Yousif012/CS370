/* A Bison parser, made by GNU Bison 3.0.4.  */

/* Bison implementation for Yacc-like parsers in C

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
#define YYBISON_VERSION "3.0.4"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* Copy the first part of user declarations.  */
#line 11 "lab7.y" /* yacc.c:339  */



/* begin specs */
#include <stdio.h>
#include <ctype.h>
#include "ast.h" 
#include "symtable.h"


int yylex();

extern int mydebug;
extern int linecount;

int LEVEL = 0; // global variable to know how far deep we are
int OFFSET = 0; // global variable for size of program

ASTnode * PROGRAM;

void yyerror (s)  /* Called by yyparse on error */
     char *s;
{
  printf ("%s at line number %d\n", s, linecount);
}



#line 95 "y.tab.c" /* yacc.c:339  */

# ifndef YY_NULLPTR
#  if defined __cplusplus && 201103L <= __cplusplus
#   define YY_NULLPTR nullptr
#  else
#   define YY_NULLPTR 0
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* In a future release of Bison, this section will be replaced
   by #include "y.tab.h".  */
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
#line 42 "lab7.y" /* yacc.c:355  */

      int value;
      char * string;
	  ASTnode * node;
	  enum AST_MY_DATA_TYPE d_type;
	  enum AST_OPERATORS operator;

#line 189 "y.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_Y_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 206 "y.tab.c" /* yacc.c:358  */

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
#else
typedef signed char yytype_int8;
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
# elif ! defined YYSIZE_T
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
#   define YY_(Msgid) dgettext ("bison-runtime", Msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(Msgid) Msgid
# endif
#endif

#ifndef YY_ATTRIBUTE
# if (defined __GNUC__                                               \
      && (2 < __GNUC__ || (__GNUC__ == 2 && 96 <= __GNUC_MINOR__)))  \
     || defined __SUNPRO_C && 0x5110 <= __SUNPRO_C
#  define YY_ATTRIBUTE(Spec) __attribute__(Spec)
# else
#  define YY_ATTRIBUTE(Spec) /* empty */
# endif
#endif

#ifndef YY_ATTRIBUTE_PURE
# define YY_ATTRIBUTE_PURE   YY_ATTRIBUTE ((__pure__))
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# define YY_ATTRIBUTE_UNUSED YY_ATTRIBUTE ((__unused__))
#endif

#if !defined _Noreturn \
     && (!defined __STDC_VERSION__ || __STDC_VERSION__ < 201112)
# if defined _MSC_VER && 1200 <= _MSC_VER
#  define _Noreturn __declspec (noreturn)
# else
#  define _Noreturn YY_ATTRIBUTE ((__noreturn__))
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN \
    _Pragma ("GCC diagnostic push") \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")\
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END \
    _Pragma ("GCC diagnostic pop")
#else
# define YY_INITIAL_VALUE(Value) Value
#endif
#ifndef YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
# define YY_IGNORE_MAYBE_UNINITIALIZED_END
#endif
#ifndef YY_INITIAL_VALUE
# define YY_INITIAL_VALUE(Value) /* Nothing. */
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
#    if ! defined _ALLOCA_H && ! defined EXIT_SUCCESS
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
      /* Use EXIT_SUCCESS as a witness for stdlib.h.  */
#     ifndef EXIT_SUCCESS
#      define EXIT_SUCCESS 0
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's 'empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (0)
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
#  if (defined __cplusplus && ! defined EXIT_SUCCESS \
       && ! ((defined YYMALLOC || defined malloc) \
             && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef EXIT_SUCCESS
#    define EXIT_SUCCESS 0
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined EXIT_SUCCESS
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined EXIT_SUCCESS
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
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

# define YYCOPY_NEEDED 1

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack_alloc, Stack)                           \
    do                                                                  \
      {                                                                 \
        YYSIZE_T yynewbytes;                                            \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / sizeof (*yyptr);                          \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, (Count) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYSIZE_T yyi;                         \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  9
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   119

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  33
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  36
/* YYNRULES -- Number of rules.  */
#define YYNRULES  75
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  125

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   278

#define YYTRANSLATE(YYX)                                                \
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, without out-of-bounds checking.  */
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    71,    71,    74,    75,    82,    83,    86,   122,   123,
     126,   130,   135,   140,   149,   148,   175,   176,   179,   180,
     184,   190,   199,   198,   214,   215,   222,   223,   230,   231,
     232,   233,   234,   235,   236,   237,   240,   245,   249,   256,
     266,   274,   276,   284,   291,   296,   304,   312,   333,   357,
     360,   361,   369,   370,   371,   372,   373,   374,   378,   379,
     388,   389,   391,   392,   401,   401,   403,   404,   409,   410,
     411,   419,   451,   451,   453,   458
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "T_NUM", "T_ID", "T_STRING", "T_INT",
  "T_VOID", "T_LET", "T_LT", "T_BT", "T_BET", "T_EE", "T_NE", "T_IF",
  "T_ELSE", "T_WHILE", "T_RETURN", "T_WRITE", "T_READ", "T_ADD", "T_SUB",
  "T_STAR", "T_SLASH", "';'", "'['", "']'", "','", "'('", "')'", "'{'",
  "'}'", "'='", "$accept", "Program", "Declaration_List", "Declaration",
  "Var_Declaration", "Type_Specifier", "Var_List", "Fun_Declaration",
  "$@1", "Params", "Params_List", "Param", "Compound_Stmt", "$@2",
  "Local_Declarations", "Statement_List", "Statement", "Expression_Stmt",
  "Selection_Stmt", "Iteration_Stmt", "Return_Stmt", "Read_Stmt",
  "Write_Stmt", "Assignment_Stmt", "Var", "Expression",
  "Simple_Expression", "relop", "Additive_Expression", "Addop", "Term",
  "Multop", "Factor", "Call", "Args", "Args_List", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,    59,    91,    93,    44,    40,    41,
     123,   125,    61
};
# endif

#define YYPACT_NINF -114

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-114)))

#define YYTABLE_NINF -17

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int8 yypact[] =
{
      13,  -114,  -114,    15,  -114,    13,  -114,    17,  -114,  -114,
    -114,    35,    26,    36,    61,    41,  -114,    50,   -18,  -114,
      39,    52,    51,    77,    53,  -114,    57,    61,    60,    56,
      13,  -114,    62,  -114,  -114,  -114,  -114,    13,    13,    61,
      14,  -114,  -114,     9,    59,    63,    19,     8,    85,    45,
    -114,    45,  -114,    64,    14,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,    58,    68,  -114,    44,    47,    49,  -114,    45,
      45,    45,    45,  -114,  -114,    69,    70,    72,    73,    75,
    -114,    71,  -114,  -114,    45,  -114,  -114,  -114,  -114,  -114,
    -114,  -114,    45,  -114,  -114,    45,  -114,  -114,    45,    76,
      74,    78,  -114,    79,    80,  -114,  -114,  -114,  -114,  -114,
      81,  -114,  -114,  -114,  -114,    45,  -114,    14,    14,  -114,
    -114,    82,  -114,    14,  -114
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     8,     9,     0,     2,     3,     5,     0,     6,     1,
       4,    10,     0,     0,     0,     0,     7,     0,    10,    12,
       0,    11,     9,     0,     0,    17,    18,     0,    20,     0,
       0,    13,     0,    22,    15,    19,    21,    24,    24,     0,
      26,    25,    67,    47,     0,     0,     0,     0,     0,     0,
      37,     0,    29,     0,    26,    28,    30,    31,    33,    34,
      35,    32,    68,     0,    49,    50,    58,    62,    69,     0,
      73,     0,     0,    41,    68,     0,     0,     0,    47,     0,
      70,     0,    23,    27,     0,    36,    52,    53,    54,    55,
      56,    57,     0,    60,    61,     0,    64,    65,     0,     0,
      74,     0,    72,     0,     0,    42,    44,    45,    43,    66,
       0,    51,    59,    63,    48,     0,    71,     0,     0,    46,
      75,    38,    40,     0,    39
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int8 yypgoto[] =
{
    -114,  -114,    98,  -114,    37,    21,   -11,  -114,  -114,  -114,
      83,  -114,    86,  -114,    66,    65,  -113,  -114,  -114,  -114,
    -114,  -114,  -114,  -114,   -40,   -45,    22,  -114,   -31,  -114,
      12,  -114,    67,  -114,  -114,    -4
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,     6,     7,    12,     8,    15,    24,
      25,    26,    52,    37,    40,    53,    54,    55,    56,    57,
      58,    59,    60,    61,    74,    63,    64,    92,    65,    95,
      66,    98,    67,    68,   101,   102
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int8 yytable[] =
{
      62,    75,    77,    19,   121,   122,    81,    13,    79,    14,
     124,    42,    43,    76,    62,     9,    31,    42,    43,     1,
       2,    11,    42,    43,    99,   100,   103,   104,    44,    49,
      45,    46,    47,    48,    69,    49,    51,    70,    50,    17,
      49,    23,    51,    73,    33,     1,    22,    51,    42,    43,
      16,    23,    86,    87,    88,    89,    90,    91,    39,    39,
      13,   111,    14,   -14,   112,    18,    49,    93,    94,    20,
     100,    96,    97,    51,    38,    38,    21,    62,    62,    27,
     -16,    28,    29,    62,    30,    32,    33,    71,    36,    78,
      84,    72,    85,   105,   106,    82,   107,   123,    69,   108,
     109,   115,   114,    10,    41,   119,   110,   116,   117,   118,
     113,   120,     0,    35,     0,    34,    80,     0,     0,    83
};

static const yytype_int8 yycheck[] =
{
      40,    46,    47,    14,   117,   118,    51,    25,    48,    27,
     123,     3,     4,     5,    54,     0,    27,     3,     4,     6,
       7,     4,     3,     4,    69,    70,    71,    72,    14,    21,
      16,    17,    18,    19,    25,    21,    28,    28,    24,     3,
      21,    20,    28,    24,    30,     6,     7,    28,     3,     4,
      24,    30,     8,     9,    10,    11,    12,    13,    37,    38,
      25,    92,    27,    28,    95,     4,    21,    20,    21,    28,
     115,    22,    23,    28,    37,    38,    26,   117,   118,    27,
      29,     4,    29,   123,    27,    25,    30,    28,    26,     4,
      32,    28,    24,    24,    24,    31,    24,    15,    25,    24,
      29,    27,    26,     5,    38,    24,    84,    29,    29,    29,
      98,   115,    -1,    30,    -1,    29,    49,    -1,    -1,    54
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,     7,    34,    35,    36,    37,    38,    40,     0,
      35,     4,    39,    25,    27,    41,    24,     3,     4,    39,
      28,    26,     7,    38,    42,    43,    44,    27,     4,    29,
      27,    39,    25,    30,    45,    43,    26,    46,    37,    38,
      47,    47,     3,     4,    14,    16,    17,    18,    19,    21,
      24,    28,    45,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    61,    63,    65,    66,    25,
      28,    28,    28,    24,    57,    58,     5,    58,     4,    57,
      65,    58,    31,    48,    32,    24,     8,     9,    10,    11,
      12,    13,    60,    20,    21,    62,    22,    23,    64,    58,
      58,    67,    68,    58,    58,    24,    24,    24,    24,    29,
      59,    61,    61,    63,    26,    27,    29,    29,    29,    24,
      68,    49,    49,    15,    49
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    33,    34,    35,    35,    36,    36,    37,    38,    38,
      39,    39,    39,    39,    41,    40,    42,    42,    43,    43,
      44,    44,    46,    45,    47,    47,    48,    48,    49,    49,
      49,    49,    49,    49,    49,    49,    50,    50,    51,    51,
      52,    53,    53,    54,    55,    55,    56,    57,    57,    58,
      59,    59,    60,    60,    60,    60,    60,    60,    61,    61,
      62,    62,    63,    63,    64,    64,    65,    65,    65,    65,
      65,    66,    67,    67,    68,    68
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     1,     1,     3,     1,     1,
       1,     4,     3,     6,     0,     7,     1,     1,     1,     3,
       2,     4,     0,     5,     0,     2,     0,     2,     1,     1,
       1,     1,     1,     1,     1,     1,     2,     1,     5,     7,
       5,     2,     3,     3,     3,     3,     4,     1,     4,     1,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     3,
       1,     1,     1,     3,     1,     1,     3,     1,     1,     1,
       2,     4,     1,     0,     1,     3
};


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                  \
do                                                              \
  if (yychar == YYEMPTY)                                        \
    {                                                           \
      yychar = (Token);                                         \
      yylval = (Value);                                         \
      YYPOPSTACK (yylen);                                       \
      yystate = *yyssp;                                         \
      goto yybackup;                                            \
    }                                                           \
  else                                                          \
    {                                                           \
      yyerror (YY_("syntax error: cannot back up")); \
      YYERROR;                                                  \
    }                                                           \
while (0)

/* Error token number */
#define YYTERROR        1
#define YYERRCODE       256



/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)                        \
do {                                            \
  if (yydebug)                                  \
    YYFPRINTF Args;                             \
} while (0)

/* This macro is provided for backward compatibility. */
#ifndef YY_LOCATION_PRINT
# define YY_LOCATION_PRINT(File, Loc) ((void) 0)
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# endif
  YYUSE (yytype);
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)                            \
do {                                                            \
  if (yydebug)                                                  \
    yy_stack_print ((Bottom), (Top));                           \
} while (0)


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

static void
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  unsigned long int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[yyssp[yyi + 1 - yynrhs]],
                       &(yyvsp[(yyi + 1) - (yynrhs)])
                                              );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, Rule); \
} while (0)

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
#ifndef YYINITDEPTH
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
static YYSIZE_T
yystrlen (const char *yystr)
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
static char *
yystpcpy (char *yydest, const char *yysrc)
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

/* Copy into *YYMSG, which is of size *YYMSG_ALLOC, an error message
   about the unexpected token YYTOKEN for the state stack whose top is
   YYSSP.

   Return 0 if *YYMSG was successfully written.  Return 1 if *YYMSG is
   not large enough to hold the message.  In that case, also set
   *YYMSG_ALLOC to the required number of bytes.  Return 2 if the
   required number of bytes is too large to store.  */
static int
yysyntax_error (YYSIZE_T *yymsg_alloc, char **yymsg,
                yytype_int16 *yyssp, int yytoken)
{
  YYSIZE_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
  YYSIZE_T yysize = yysize0;
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat. */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Number of reported tokens (one for the "unexpected", one per
     "expected"). */
  int yycount = 0;

  /* There are many possibilities here to consider:
     - If this state is a consistent state with a default action, then
       the only way this function was invoked is if the default action
       is an error action.  In that case, don't check for expected
       tokens because there are none.
     - The only way there can be no lookahead present (in yychar) is if
       this state is a consistent state with a default action.  Thus,
       detecting the absence of a lookahead is sufficient to determine
       that there is no unexpected or expected token to report.  In that
       case, just report a simple "syntax error".
     - Don't assume there isn't a lookahead just because this state is a
       consistent state with a default action.  There might have been a
       previous inconsistent state, consistent state with a non-default
       action, or user semantic action that manipulated yychar.
     - Of course, the expected token list depends on states to have
       correct lookahead information, and it depends on the parser not
       to perform extra reductions after fetching a lookahead from the
       scanner and before detecting a syntax error.  Thus, state merging
       (from LALR or IELR) and default reductions corrupt the expected
       token list.  However, the list is correct for canonical LR with
       one exception: it will still contain any token that will not be
       accepted due to an error action in a later state.
  */
  if (yytoken != YYEMPTY)
    {
      int yyn = yypact[*yyssp];
      yyarg[yycount++] = yytname[yytoken];
      if (!yypact_value_is_default (yyn))
        {
          /* Start YYX at -YYN if negative to avoid negative indexes in
             YYCHECK.  In other words, skip the first -YYN actions for
             this state because they are default actions.  */
          int yyxbegin = yyn < 0 ? -yyn : 0;
          /* Stay within bounds of both yycheck and yytname.  */
          int yychecklim = YYLAST - yyn + 1;
          int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
          int yyx;

          for (yyx = yyxbegin; yyx < yyxend; ++yyx)
            if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR
                && !yytable_value_is_error (yytable[yyx + yyn]))
              {
                if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
                  {
                    yycount = 1;
                    yysize = yysize0;
                    break;
                  }
                yyarg[yycount++] = yytname[yyx];
                {
                  YYSIZE_T yysize1 = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (! (yysize <= yysize1
                         && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
                    return 2;
                  yysize = yysize1;
                }
              }
        }
    }

  switch (yycount)
    {
# define YYCASE_(N, S)                      \
      case N:                               \
        yyformat = S;                       \
      break
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    YYSIZE_T yysize1 = yysize + yystrlen (yyformat);
    if (! (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM))
      return 2;
    yysize = yysize1;
  }

  if (*yymsg_alloc < yysize)
    {
      *yymsg_alloc = 2 * yysize;
      if (! (yysize <= *yymsg_alloc
             && *yymsg_alloc <= YYSTACK_ALLOC_MAXIMUM))
        *yymsg_alloc = YYSTACK_ALLOC_MAXIMUM;
      return 1;
    }

  /* Avoid sprintf, as that infringes on the user's name space.
     Don't have undefined behavior even if the translation
     produced a string with the wrong number of "%s"s.  */
  {
    char *yyp = *yymsg;
    int yyi = 0;
    while ((*yyp = *yyformat) != '\0')
      if (*yyp == '%' && yyformat[1] == 's' && yyi < yycount)
        {
          yyp += yytnamerr (yyp, yyarg[yyi++]);
          yyformat += 2;
        }
      else
        {
          yyp++;
          yyformat++;
        }
  }
  return 0;
}
#endif /* YYERROR_VERBOSE */

/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep)
{
  YYUSE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}




/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;
/* Number of syntax errors so far.  */
int yynerrs;


/*----------.
| yyparse.  |
`----------*/

int
yyparse (void)
{
    int yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yytype_int16 yyssa[YYINITDEPTH];
    yytype_int16 *yyss;
    yytype_int16 *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
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
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
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

  if (yystate == YYFINAL)
    YYACCEPT;

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     lookahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to lookahead token.  */
  yyn = yypact[yystate];
  if (yypact_value_is_default (yyn))
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = yylex ();
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
      if (yytable_value_is_error (yyn))
        goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
  yychar = YYEMPTY;

  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

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
     '$$ = $1'.

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
#line 71 "lab7.y" /* yacc.c:1646  */
    { PROGRAM = (yyvsp[0].node); }
#line 1371 "y.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 74 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1377 "y.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 76 "lab7.y" /* yacc.c:1646  */
    {
					(yyval.node) = (yyvsp[-1].node);
					if((yyvsp[-1].node) != NULL) (yyval.node)->next = (yyvsp[0].node);
				 }
#line 1386 "y.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 82 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1392 "y.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 83 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1398 "y.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 87 "lab7.y" /* yacc.c:1646  */
    { 
				  // populate the s1 connected list with the
				  // defined type via $1
				  ASTnode *p = (yyvsp[-1].node);
				  while ( p != NULL ){
					p->my_data_type = (yyvsp[-2].d_type);

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
						Insert(p->name, p->my_data_type, SYM_SCALAR, LEVEL, 1, OFFSET);
						OFFSET += 1;
					}

					// variable is array
					else{
						Insert(p->name, p->my_data_type, SYM_ARRAY, LEVEL, p->value, OFFSET);
						OFFSET += p->value;
					}

					p = p->s1;

				  }
				  (yyval.node) = (yyvsp[-1].node); 
				}
#line 1436 "y.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 122 "lab7.y" /* yacc.c:1646  */
    { (yyval.d_type) = A_INTTYPE; }
#line 1442 "y.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 123 "lab7.y" /* yacc.c:1646  */
    { (yyval.d_type) = A_VOIDTYPE; }
#line 1448 "y.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 127 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(A_VARDEC); 
			 (yyval.node)->name = (yyvsp[0].string); 
		   }
#line 1456 "y.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 131 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(A_VARDEC); 
		     (yyval.node)->value = (yyvsp[-1].value);
		     (yyval.node)->name = (yyvsp[-3].string); 
		   }
#line 1465 "y.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 136 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(A_VARDEC); 
			 (yyval.node)->name = (yyvsp[-2].string); 
			 (yyval.node)->s1 = (yyvsp[0].node);
		   }
#line 1474 "y.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 141 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(A_VARDEC); 
			 (yyval.node)->name = (yyvsp[-5].string); 
			 (yyval.node)->value = (yyvsp[-3].value);
			 (yyval.node)->s1 = (yyvsp[0].node);
		   }
#line 1484 "y.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 149 "lab7.y" /* yacc.c:1646  */
    {
					// check if function has been defined
					if(Search((yyvsp[0].string), LEVEL, 0) != NULL){
						// T_ID has already been used, BARF
						yyerror((yyvsp[0].string));
						yyerror("function name already in use");
						exit(1);
					}
					// not in symbol table, insert it
					Insert((yyvsp[0].string), (yyvsp[-1].d_type), SYM_FUNCTION, LEVEL, 0, 0);

				}
#line 1501 "y.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 163 "lab7.y" /* yacc.c:1646  */
    { 
				  struct SymbTab *p;
				  p = Search((yyvsp[-5].string), LEVEL, 0);
				  p->fparms = (yyvsp[-2].node); 
				  (yyval.node) = ASTCreateNode(A_FUNCTIONDEC);
				  (yyval.node)->name = (yyvsp[-5].string);
				  (yyval.node)->my_data_type = (yyvsp[-6].d_type);
				  (yyval.node)->s1 = (yyvsp[-2].node);
				  (yyval.node)->s2 = (yyvsp[0].node);
				}
#line 1516 "y.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 175 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1522 "y.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 176 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1528 "y.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 179 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1534 "y.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 181 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-2].node); 
			  if((yyvsp[-2].node) != NULL) (yyval.node)->next = (yyvsp[0].node); }
#line 1541 "y.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 185 "lab7.y" /* yacc.c:1646  */
    { 
		  (yyval.node) = ASTCreateNode(A_PARAM);
		  (yyval.node)->name = (yyvsp[0].string);
		  (yyval.node)->my_data_type = (yyvsp[-1].d_type);
		}
#line 1551 "y.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 191 "lab7.y" /* yacc.c:1646  */
    { 
		  (yyval.node) = ASTCreateNode(A_PARAM);
		  (yyval.node)->name = (yyvsp[-2].string);
		  (yyval.node)->my_data_type = (yyvsp[-3].d_type);
		}
#line 1561 "y.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 199 "lab7.y" /* yacc.c:1646  */
    { 
				LEVEL ++; 
			  }
#line 1569 "y.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 203 "lab7.y" /* yacc.c:1646  */
    {
				(yyval.node) = ASTCreateNode(A_COMPOUND);
				(yyval.node)->s1 = (yyvsp[-2].node);
				(yyval.node)->s2 = (yyvsp[-1].node);

				Display();
				Delete(LEVEL);
				LEVEL --;
			  }
#line 1583 "y.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 214 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1589 "y.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 216 "lab7.y" /* yacc.c:1646  */
    { 
					 (yyval.node) = (yyvsp[-1].node);
				     if((yyvsp[-1].node) != NULL) (yyval.node)->next = (yyvsp[0].node);
				   }
#line 1598 "y.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 222 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 1604 "y.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 224 "lab7.y" /* yacc.c:1646  */
    {
				(yyval.node) = (yyvsp[-1].node);
				(yyval.node)->next = (yyvsp[0].node);
			   }
#line 1613 "y.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 230 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1619 "y.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 231 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1625 "y.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 232 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1631 "y.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 233 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1637 "y.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 234 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1643 "y.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 235 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1649 "y.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 236 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1655 "y.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 237 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1661 "y.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 241 "lab7.y" /* yacc.c:1646  */
    { 
					(yyval.node) = ASTCreateNode(A_EXPR_STMT);
					(yyval.node)->s1 = (yyvsp[-1].node);
				}
#line 1670 "y.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 245 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(A_EXPR_STMT); }
#line 1676 "y.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 250 "lab7.y" /* yacc.c:1646  */
    {
				 (yyval.node) = ASTCreateNode(A_IF);
				 (yyval.node)->s1 = (yyvsp[-2].node);
				 (yyval.node)->s2 = ASTCreateNode(A_IFBODY);
				 (yyval.node)->s2->s1 = (yyvsp[0].node);
				}
#line 1687 "y.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 257 "lab7.y" /* yacc.c:1646  */
    {
				 (yyval.node) = ASTCreateNode(A_IF);
				 (yyval.node)->s1 = (yyvsp[-4].node);
				 (yyval.node)->s2 = ASTCreateNode(A_IFBODY);
				 (yyval.node)->s2->s1 = (yyvsp[-2].node);
				 (yyval.node)->s2->s2 = (yyvsp[0].node);
				}
#line 1699 "y.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 267 "lab7.y" /* yacc.c:1646  */
    {
				(yyval.node) = ASTCreateNode(A_WHILE);
				(yyval.node)->s1 = (yyvsp[-2].node);
				(yyval.node)->s2 = (yyvsp[0].node);
			   }
#line 1709 "y.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 275 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = ASTCreateNode(A_RETURN); }
#line 1715 "y.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 277 "lab7.y" /* yacc.c:1646  */
    { 
				(yyval.node) = ASTCreateNode(A_RETURN); 
				(yyval.node)->s1 = (yyvsp[-1].node);
			}
#line 1724 "y.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 285 "lab7.y" /* yacc.c:1646  */
    {
			(yyval.node) = ASTCreateNode(A_READ);
			(yyval.node)->s1 = (yyvsp[-1].node);
		  }
#line 1733 "y.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 292 "lab7.y" /* yacc.c:1646  */
    { 
			 (yyval.node) = ASTCreateNode(A_WRITE);
			 (yyval.node)->name = (yyvsp[-1].string);
		   }
#line 1742 "y.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 297 "lab7.y" /* yacc.c:1646  */
    {
			 (yyval.node) = ASTCreateNode(A_WRITE);
			 (yyval.node)->s1 = (yyvsp[-1].node);
		   }
#line 1751 "y.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 305 "lab7.y" /* yacc.c:1646  */
    {
					(yyval.node) = ASTCreateNode(A_ASSIGN);
					(yyval.node)->s1 = (yyvsp[-3].node);
					(yyval.node)->s2 = (yyvsp[-1].node);
				}
#line 1761 "y.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 313 "lab7.y" /* yacc.c:1646  */
    { 
		struct SymbTab *p;
		p = Search((yyvsp[0].string), LEVEL, 1);
		if(p == NULL){
			// variable not defined within scope
			yyerror((yyvsp[0].string));
			yyerror("symbol used but not defined");
			exit(1);
		}

		if (p->SubType != SYM_SCALAR){
			// variable is used as scalar but not scalar
			yyerror((yyvsp[0].string));
			yyerror("symbol must be scalar");
			exit(1);
		}

		(yyval.node) = ASTCreateNode(A_VAR);
	   	(yyval.node)->name = (yyvsp[0].string);
	}
#line 1786 "y.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 334 "lab7.y" /* yacc.c:1646  */
    { 
		struct SymbTab *p;
		p = Search((yyvsp[-3].string), LEVEL, 1);
		if(p == NULL){
			// variable not defined within scope
			yyerror((yyvsp[-3].string));
			yyerror("symbol used but not defined");
			exit(1);
		}

		if (p->SubType != SYM_ARRAY){
			// variable is used as array but not array
			yyerror((yyvsp[-3].string));
			yyerror("symbol must be array");
			exit(1);
		}

		(yyval.node) = ASTCreateNode(A_VAR);
	   	(yyval.node)->name = (yyvsp[-3].string);
		(yyval.node)->s1 = (yyvsp[-1].node);
	}
#line 1812 "y.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 357 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1818 "y.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 360 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1824 "y.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 362 "lab7.y" /* yacc.c:1646  */
    {
					 (yyval.node) = ASTCreateNode(A_EXPR); 
					 (yyval.node)->s1 = (yyvsp[-2].node);
					 (yyval.node)->s2 = (yyvsp[0].node);
					 (yyval.node)->operator = (yyvsp[-1].operator);
					}
#line 1835 "y.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 369 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LET; }
#line 1841 "y.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 370 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_LT; }
#line 1847 "y.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 371 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_BT; }
#line 1853 "y.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 372 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_BET; }
#line 1859 "y.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 373 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_EE; }
#line 1865 "y.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 374 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_NE; }
#line 1871 "y.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 378 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1877 "y.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 380 "lab7.y" /* yacc.c:1646  */
    {
					 (yyval.node) = ASTCreateNode(A_EXPR);
					 (yyval.node)->s1 = (yyvsp[-2].node);
					 (yyval.node)->s2 = (yyvsp[0].node);
					 (yyval.node)->operator = (yyvsp[-1].operator);
					}
#line 1888 "y.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 388 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_PLUS; }
#line 1894 "y.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 389 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_MINUS; }
#line 1900 "y.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 391 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1906 "y.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 393 "lab7.y" /* yacc.c:1646  */
    { 
		(yyval.node) = ASTCreateNode(A_EXPR);
		(yyval.node)->s1 = (yyvsp[-2].node);
		(yyval.node)->s2 = (yyvsp[0].node);
		(yyval.node)->operator = (yyvsp[-1].operator);
	 }
#line 1917 "y.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 401 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_MULT; }
#line 1923 "y.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 401 "lab7.y" /* yacc.c:1646  */
    { (yyval.operator) = A_DIV; }
#line 1929 "y.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 403 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[-1].node); }
#line 1935 "y.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 405 "lab7.y" /* yacc.c:1646  */
    { 
		 (yyval.node) = ASTCreateNode(A_NUM);
	   	 (yyval.node)->value = (yyvsp[0].value); 
	   }
#line 1944 "y.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 409 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1950 "y.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 410 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 1956 "y.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 412 "lab7.y" /* yacc.c:1646  */
    { 
		(yyval.node) = ASTCreateNode(A_EXPR);
		(yyval.node)->operator = A_UMINUS;
		(yyval.node)->s1 = (yyvsp[0].node); 
	   }
#line 1966 "y.tab.c" /* yacc.c:1646  */
    break;

  case 71:
#line 420 "lab7.y" /* yacc.c:1646  */
    { 
		struct SymbTab *p;
		p = Search((yyvsp[-3].string), 0, 0);
		if(p == NULL){
			// function not defined
			yyerror((yyvsp[-3].string));
			yyerror("function not defined");
			exit(1);
		}

		// name is there but is it a function?
		if(p->SubType != SYM_FUNCTION){
			// function name is not related to a function declaration but to a variable
			yyerror((yyvsp[-3].string));
			yyerror("not defined as function");
			exit(1);
		}

		// check if parameters length and type are correct
		if(check_params((yyvsp[-1].node), p->fparms) == 0){
			yyerror((yyvsp[-3].string));
			yyerror("Actual and Formals do not match");
			exit(1);
		}
		
	   (yyval.node) = ASTCreateNode(A_CALL);
	   (yyval.node)->name = (yyvsp[-3].string);
	   (yyval.node)->s1 = (yyvsp[-1].node);
	 }
#line 2000 "y.tab.c" /* yacc.c:1646  */
    break;

  case 72:
#line 451 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = (yyvsp[0].node); }
#line 2006 "y.tab.c" /* yacc.c:1646  */
    break;

  case 73:
#line 451 "lab7.y" /* yacc.c:1646  */
    { (yyval.node) = NULL; }
#line 2012 "y.tab.c" /* yacc.c:1646  */
    break;

  case 74:
#line 454 "lab7.y" /* yacc.c:1646  */
    { 
			(yyval.node) = ASTCreateNode(A_ARG);
			(yyval.node)->s1 = (yyvsp[0].node);
		  }
#line 2021 "y.tab.c" /* yacc.c:1646  */
    break;

  case 75:
#line 459 "lab7.y" /* yacc.c:1646  */
    { 
			(yyval.node) = ASTCreateNode(A_ARG);
			(yyval.node)->s1 = (yyvsp[-2].node);
			if((yyvsp[-2].node) != NULL) (yyval.node)->next = (yyvsp[0].node);
		  }
#line 2031 "y.tab.c" /* yacc.c:1646  */
    break;


#line 2035 "y.tab.c" /* yacc.c:1646  */
      default: break;
    }
  /* User semantic actions sometimes alter yychar, and that requires
     that yytoken be updated with the new translation.  We take the
     approach of translating immediately before every use of yytoken.
     One alternative is translating here after every semantic action,
     but that translation would be missed if the semantic action invokes
     YYABORT, YYACCEPT, or YYERROR immediately after altering yychar or
     if it invokes YYBACKUP.  In the case of YYABORT or YYACCEPT, an
     incorrect destructor might then be invoked immediately.  In the
     case of YYERROR or YYBACKUP, subsequent parser actions might lead
     to an incorrect destructor call or verbose syntax error message
     before the lookahead is translated.  */
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;

  /* Now 'shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*--------------------------------------.
| yyerrlab -- here on detecting error.  |
`--------------------------------------*/
yyerrlab:
  /* Make sure we have latest lookahead translation.  See comments at
     user semantic actions for why this is necessary.  */
  yytoken = yychar == YYEMPTY ? YYEMPTY : YYTRANSLATE (yychar);

  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      yyerror (YY_("syntax error"));
#else
# define YYSYNTAX_ERROR yysyntax_error (&yymsg_alloc, &yymsg, \
                                        yyssp, yytoken)
      {
        char const *yymsgp = YY_("syntax error");
        int yysyntax_error_status;
        yysyntax_error_status = YYSYNTAX_ERROR;
        if (yysyntax_error_status == 0)
          yymsgp = yymsg;
        else if (yysyntax_error_status == 1)
          {
            if (yymsg != yymsgbuf)
              YYSTACK_FREE (yymsg);
            yymsg = (char *) YYSTACK_ALLOC (yymsg_alloc);
            if (!yymsg)
              {
                yymsg = yymsgbuf;
                yymsg_alloc = sizeof yymsgbuf;
                yysyntax_error_status = 2;
              }
            else
              {
                yysyntax_error_status = YYSYNTAX_ERROR;
                yymsgp = yymsg;
              }
          }
        yyerror (yymsgp);
        if (yysyntax_error_status == 2)
          goto yyexhaustedlab;
      }
# undef YYSYNTAX_ERROR
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse lookahead token after an
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

  /* Else will try to reuse lookahead token after shifting the error
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

  /* Do not reclaim the symbols of the rule whose action triggered
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
  yyerrstatus = 3;      /* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
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

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


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

#if !defined yyoverflow || YYERROR_VERBOSE
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEMPTY)
    {
      /* Make sure we have latest lookahead translation.  See comments at
         user semantic actions for why this is necessary.  */
      yytoken = YYTRANSLATE (yychar);
      yydestruct ("Cleanup: discarding lookahead",
                  yytoken, &yylval);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
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
  return yyresult;
}
#line 466 "lab7.y" /* yacc.c:1906  */
	/* end of rules, start of program */

int main()
{ yyparse();
  printf("Finished parsing\n");
  
  Display(); // shows our global variables

  printf("\n\n\nAST PRINT \n\n\n");
  ASTprint(0, PROGRAM);
}