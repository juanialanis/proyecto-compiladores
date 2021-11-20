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
     INT = 258,
     ID = 259,
     BTRUE = 260,
     BFALSE = 261,
     EQUAL = 262,
     LOWER = 263,
     HIGHER = 264,
     TMINUS = 265,
     TNOT = 266,
     TPLUS = 267,
     TMOD = 268,
     TDIV = 269,
     TMULT = 270,
     TOR = 271,
     TAND = 272,
     PROGRAM = 273,
     EXTERN = 274,
     WHILE = 275,
     BOOL = 276,
     INTEGER = 277,
     IF = 278,
     ELSE = 279,
     THEN = 280,
     VOID = 281,
     RETURN = 282,
     UNARY = 283
   };
#endif
/* Tokens.  */
#define INT 258
#define ID 259
#define BTRUE 260
#define BFALSE 261
#define EQUAL 262
#define LOWER 263
#define HIGHER 264
#define TMINUS 265
#define TNOT 266
#define TPLUS 267
#define TMOD 268
#define TDIV 269
#define TMULT 270
#define TOR 271
#define TAND 272
#define PROGRAM 273
#define EXTERN 274
#define WHILE 275
#define BOOL 276
#define INTEGER 277
#define IF 278
#define ELSE 279
#define THEN 280
#define VOID 281
#define RETURN 282
#define UNARY 283




/* Copy the first part of user declarations.  */
#line 1 "calc-sintaxis.y"


#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "treeManagement.h"

extern int yylineno;

//table of symbols
stStack* stackOfLevels = NULL;
listThreeDir* threeDirList = NULL;
int label_num = 1;

int yylex();
int yyerror(char *);



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
#line 20 "calc-sintaxis.y"
{ int i; char *s; struct treeN *tn; struct idList* idL;}
/* Line 193 of yacc.c.  */
#line 173 "calc-sintaxis.tab.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 186 "calc-sintaxis.tab.c"

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
#define YYFINAL  4
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   245

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  36
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  21
/* YYNRULES -- Number of rules.  */
#define YYNRULES  63
/* YYNRULES -- Number of states.  */
#define YYNSTATES  120

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   283

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
      33,    34,     2,     2,    32,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,    31,
       2,    35,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,    29,     2,    30,     2,     2,     2,     2,
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
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint8 yyprhs[] =
{
       0,     0,     3,     9,    14,    19,    23,    26,    28,    32,
      36,    38,    41,    43,    49,    54,    57,    60,    62,    65,
      70,    73,    78,    82,    86,    89,    92,    94,    96,    98,
     103,   106,   108,   112,   114,   116,   118,   122,   125,   132,
     141,   146,   150,   154,   156,   158,   160,   162,   164,   167,
     170,   174,   178,   182,   186,   190,   194,   198,   202,   206,
     210,   214,   216,   218
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      37,     0,    -1,    18,    29,    38,    41,    30,    -1,    18,
      29,    41,    30,    -1,    18,    29,    38,    30,    -1,    18,
      29,    30,    -1,    38,    39,    -1,    39,    -1,    48,    40,
      31,    -1,     4,    32,    40,    -1,     4,    -1,    41,    42,
      -1,    42,    -1,    43,    33,    45,    34,    44,    -1,    43,
      33,    34,    44,    -1,    48,     4,    -1,    26,     4,    -1,
      46,    -1,    19,    31,    -1,    48,     4,    32,    45,    -1,
      48,     4,    -1,    29,    38,    47,    30,    -1,    29,    47,
      30,    -1,    29,    38,    30,    -1,    29,    30,    -1,    49,
      47,    -1,    49,    -1,    22,    -1,    21,    -1,     4,    35,
      54,    31,    -1,    52,    31,    -1,    51,    -1,    20,    54,
      46,    -1,    50,    -1,    46,    -1,    31,    -1,    27,    54,
      31,    -1,    27,    31,    -1,    23,    33,    54,    34,    25,
      46,    -1,    23,    33,    54,    34,    25,    46,    24,    46,
      -1,     4,    33,    53,    34,    -1,     4,    33,    34,    -1,
      53,    32,    54,    -1,    54,    -1,     4,    -1,    52,    -1,
      56,    -1,    55,    -1,    10,    54,    -1,    11,    54,    -1,
      33,    54,    34,    -1,    54,    12,    54,    -1,    54,    10,
      54,    -1,    54,    15,    54,    -1,    54,    14,    54,    -1,
      54,    13,    54,    -1,    54,     8,    54,    -1,    54,     9,
      54,    -1,    54,     7,    54,    -1,    54,    17,    54,    -1,
      54,    16,    54,    -1,     3,    -1,     5,    -1,     6,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    38,    38,    47,    59,    69,    80,    84,    89,    97,
     100,   105,   109,   114,   120,   128,   132,   138,   141,   147,
     153,   159,   163,   167,   171,   177,   181,   186,   189,   194,
     200,   203,   206,   210,   213,   216,   222,   226,   232,   236,
     244,   250,   258,   262,   267,   271,   274,   277,   280,   284,
     288,   293,   297,   301,   305,   309,   313,   317,   321,   325,
     329,   335,   339,   343
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "ID", "BTRUE", "BFALSE", "EQUAL",
  "LOWER", "HIGHER", "TMINUS", "TNOT", "TPLUS", "TMOD", "TDIV", "TMULT",
  "TOR", "TAND", "PROGRAM", "EXTERN", "WHILE", "BOOL", "INTEGER", "IF",
  "ELSE", "THEN", "VOID", "RETURN", "UNARY", "'{'", "'}'", "';'", "','",
  "'('", "')'", "'='", "$accept", "prog", "variables", "v_declaration",
  "ides", "methods", "m_declaration", "method_type", "m_declaration_final",
  "typeides", "block", "statements", "type", "statement", "return_stmt",
  "if_stmt", "method_call", "expressions", "expression", "expr_bin",
  "literal", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   123,
     125,    59,    44,    40,    41,    61
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    36,    37,    37,    37,    37,    38,    38,    39,    40,
      40,    41,    41,    42,    42,    43,    43,    44,    44,    45,
      45,    46,    46,    46,    46,    47,    47,    48,    48,    49,
      49,    49,    49,    49,    49,    49,    50,    50,    51,    51,
      52,    52,    53,    53,    54,    54,    54,    54,    54,    54,
      54,    55,    55,    55,    55,    55,    55,    55,    55,    55,
      55,    56,    56,    56
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     5,     4,     4,     3,     2,     1,     3,     3,
       1,     2,     1,     5,     4,     2,     2,     1,     2,     4,
       2,     4,     3,     3,     2,     2,     1,     1,     1,     4,
       2,     1,     3,     1,     1,     1,     3,     2,     6,     8,
       4,     3,     3,     1,     1,     1,     1,     1,     2,     2,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     1,     1,     1
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,     0,     0,     0,     1,    28,    27,     0,     5,     0,
       7,     0,    12,     0,     0,    16,     4,     6,     0,     3,
      11,     0,     0,    10,     0,     2,    15,     0,     0,     0,
       0,     8,     0,     0,    14,    17,     0,    20,    10,     9,
      18,     0,     0,     0,     0,    24,    35,     0,    34,     0,
       0,    26,    33,    31,     0,    13,     0,     0,     0,    61,
      44,    62,    63,     0,     0,     0,    45,     0,    47,    46,
       0,    37,     0,    23,     0,    22,    25,    30,    19,    41,
       0,    43,     0,    48,    49,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,    32,     0,    36,    21,
       0,    40,    29,    50,    58,    56,    57,    52,    51,    55,
      54,    53,    60,    59,     0,    42,     0,    38,     0,    39
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     2,     9,    10,    24,    11,    12,    13,    34,    28,
      48,    49,    14,    51,    52,    53,    66,    80,    67,    68,
      69
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -44
static const yytype_int16 yypact[] =
{
     -16,   -19,    13,   184,   -44,   -44,   -44,    15,   -44,   187,
     -44,   190,   -44,    -7,    32,   -44,   -44,   -44,   197,   -44,
     -44,    38,    33,    87,    25,   -44,   -44,   -11,    34,    72,
      84,   -44,    61,    86,   -44,   -44,   -11,    62,    79,   -44,
     -44,    26,    60,    85,    27,   -44,   -44,   106,   -44,    91,
      84,   119,   -44,   -44,    99,   -44,   103,     1,    60,   -44,
      98,   -44,   -44,    60,    60,    60,   -44,   175,   -44,   -44,
      60,   -44,   144,   -44,   102,   -44,   -44,   -44,   -44,   -44,
      80,   186,   155,   -44,   -44,    65,    60,    60,    60,    60,
      60,    60,    60,    60,    60,    60,   -44,    88,   -44,   -44,
      60,   -44,   -44,   -44,   221,   221,   221,    71,    71,   -44,
     -44,   -44,   230,   230,   109,   186,   111,   114,   111,   -44
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -44,   -44,   108,    -6,   113,   135,     5,   -44,   130,    89,
     -27,   -22,     6,   -44,   -44,   -44,    36,   -44,   -43,   -44,
     -44
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -16
static const yytype_int8 yytable[] =
{
      35,    72,     1,    17,    59,    60,    61,    62,    32,    35,
       3,    63,    64,     4,    81,    82,    20,    21,    33,    15,
      83,    84,    85,    20,    21,    74,    22,    97,    29,    76,
      59,    60,    61,    62,    65,    79,    23,    63,    64,    50,
      96,    17,    26,   104,   105,   106,   107,   108,   109,   110,
     111,   112,   113,    50,     5,     6,    31,   115,    71,    57,
      65,    58,    29,    59,    60,    61,    62,    27,    36,    54,
      63,    64,    86,    87,    88,    89,    37,    90,    91,    92,
      93,    94,    95,    54,    91,    92,    93,    54,    38,   117,
      41,   119,    40,    65,    56,    86,    87,    88,    89,   103,
      90,    91,    92,    93,    94,    95,    42,     5,     6,    43,
      41,    30,   100,    44,   101,    33,    45,    46,    70,    30,
     -15,    75,   114,    41,     5,     6,    42,     5,     6,    43,
      77,    57,    99,    44,   116,    33,    73,    46,   118,    42,
      33,    47,    43,    39,    18,    78,    44,     0,    33,     0,
      46,    86,    87,    88,    89,     0,    90,    91,    92,    93,
      94,    95,    86,    87,    88,    89,    55,    90,    91,    92,
      93,    94,    95,     0,     0,    98,     0,     0,     0,     0,
       0,     0,    86,    87,    88,    89,   102,    90,    91,    92,
      93,    94,    95,    86,    87,    88,    89,     0,    90,    91,
      92,    93,    94,    95,    33,     5,     6,     0,     5,     6,
       7,     5,     6,     7,     8,     0,     7,    16,     5,     6,
      19,     0,     0,     7,     0,     0,     0,    25,   -16,   -16,
     -16,    89,     0,    90,    91,    92,    93,    86,    87,    88,
      89,     0,    90,    91,    92,    93
};

static const yytype_int8 yycheck[] =
{
      27,    44,    18,     9,     3,     4,     5,     6,    19,    36,
      29,    10,    11,     0,    57,    58,    11,    11,    29,     4,
      63,    64,    65,    18,    18,    47,    33,    70,    22,    51,
       3,     4,     5,     6,    33,    34,     4,    10,    11,    33,
      67,    47,     4,    86,    87,    88,    89,    90,    91,    92,
      93,    94,    95,    47,    21,    22,    31,   100,    31,    33,
      33,    35,    56,     3,     4,     5,     6,    34,    34,    33,
      10,    11,     7,     8,     9,    10,     4,    12,    13,    14,
      15,    16,    17,    47,    13,    14,    15,    51,     4,   116,
       4,   118,    31,    33,    32,     7,     8,     9,    10,    34,
      12,    13,    14,    15,    16,    17,    20,    21,    22,    23,
       4,    32,    32,    27,    34,    29,    30,    31,    33,    32,
      33,    30,    34,     4,    21,    22,    20,    21,    22,    23,
      31,    33,    30,    27,    25,    29,    30,    31,    24,    20,
      29,    33,    23,    30,     9,    56,    27,    -1,    29,    -1,
      31,     7,     8,     9,    10,    -1,    12,    13,    14,    15,
      16,    17,     7,     8,     9,    10,    36,    12,    13,    14,
      15,    16,    17,    -1,    -1,    31,    -1,    -1,    -1,    -1,
      -1,    -1,     7,     8,     9,    10,    31,    12,    13,    14,
      15,    16,    17,     7,     8,     9,    10,    -1,    12,    13,
      14,    15,    16,    17,    29,    21,    22,    -1,    21,    22,
      26,    21,    22,    26,    30,    -1,    26,    30,    21,    22,
      30,    -1,    -1,    26,    -1,    -1,    -1,    30,     7,     8,
       9,    10,    -1,    12,    13,    14,    15,     7,     8,     9,
      10,    -1,    12,    13,    14,    15
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,    18,    37,    29,     0,    21,    22,    26,    30,    38,
      39,    41,    42,    43,    48,     4,    30,    39,    41,    30,
      42,    48,    33,     4,    40,    30,     4,    34,    45,    48,
      32,    31,    19,    29,    44,    46,    34,     4,     4,    40,
      31,     4,    20,    23,    27,    30,    31,    38,    46,    47,
      48,    49,    50,    51,    52,    44,    32,    33,    35,     3,
       4,     5,     6,    10,    11,    33,    52,    54,    55,    56,
      33,    31,    54,    30,    47,    30,    47,    31,    45,    34,
      53,    54,    54,    54,    54,    54,     7,     8,     9,    10,
      12,    13,    14,    15,    16,    17,    46,    54,    31,    30,
      32,    34,    31,    34,    54,    54,    54,    54,    54,    54,
      54,    54,    54,    54,    34,    54,    25,    46,    24,    46
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
#line 38 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, PROG, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root, (yyvsp[(3) - (5)].tn), (yyvsp[(4) - (5)].tn)); 
                                                printTree((yyval.tn),0);
                                                createLevelOfSymbolTable((yyval.tn));
                                                checkValidation((yyval.tn));
                                                createInstructions((yyval.tn));
                                                printInstructions();
                                        ;}
    break;

  case 3:
#line 47 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, PROG, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root, NULL, (yyvsp[(3) - (4)].tn)); 
                                                printTree((yyval.tn),0);
                                                createLevelOfSymbolTable((yyval.tn));
                                                createInstructions((yyval.tn));
                                                checkValidation((yyval.tn));
                                                printf("\n");
                                                printInstructions();
                                                

                                        ;}
    break;

  case 4:
#line 59 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, PROG, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root, (yyvsp[(3) - (4)].tn), NULL); 
                                                //printTree($$,0);
                                                createLevelOfSymbolTable((yyval.tn));
                                                checkValidation((yyval.tn));
                                                printf("voy a crear");
                                                createInstructions((yyval.tn));

                                        ;}
    break;

  case 5:
#line 69 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, PROG, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root, NULL, NULL); 
                                                //printTree($$,0);
                                                createLevelOfSymbolTable((yyval.tn));
                                                checkValidation((yyval.tn));
                                                createInstructions((yyval.tn));

                                        ;}
    break;

  case 6:
#line 80 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, SEMICOLON, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root, (yyvsp[(1) - (2)].tn), (yyvsp[(2) - (2)].tn)); 
                                        ;}
    break;

  case 7:
#line 84 "calc-sintaxis.y"
    {
                                                (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                        ;}
    break;

  case 8:
#line 89 "calc-sintaxis.y"
    {
                                        node* root = newNode(0, yylineno, None, VDECL, NULL, NULL, NULL, 0);
                                        node* sonL = newNode(0, yylineno, (yyvsp[(1) - (3)].i), NONE, NULL, (yyvsp[(2) - (3)].idL),NULL, 0);
                                        tree* newTL = newTree(sonL, NULL, NULL);
                                        (yyval.tn) = newTree(root, newTL, NULL);
                                ;}
    break;

  case 9:
#line 97 "calc-sintaxis.y"
    {
                        (yyval.idL) = newIdList((yyvsp[(1) - (3)].s),(yyvsp[(3) - (3)].idL));
                    ;}
    break;

  case 10:
#line 100 "calc-sintaxis.y"
    {
                        (yyval.idL) = newIdList((yyvsp[(1) - (1)].s),NULL);
                    ;}
    break;

  case 11:
#line 105 "calc-sintaxis.y"
    {
                                        node* root = newNode(0, yylineno, None, SEMICOLON, NULL, NULL, NULL, 0);
                                        (yyval.tn) = newTree(root, (yyvsp[(1) - (2)].tn), (yyvsp[(2) - (2)].tn)); 
                                ;}
    break;

  case 12:
#line 109 "calc-sintaxis.y"
    {
                                        (yyval.tn) = (yyvsp[(1) - (1)].tn);  
                                ;}
    break;

  case 13:
#line 114 "calc-sintaxis.y"
    {
                                                                        node* root = newNode(0, yylineno, None, MDECL, NULL, NULL, NULL, 0);
                                                                        node* left = newNode(0, yylineno, None, MDECLTYPE, NULL, NULL, NULL, 0);
                                                                        tree* leftTree = newTree(left, (yyvsp[(1) - (5)].tn), (yyvsp[(3) - (5)].tn));
                                                                        (yyval.tn) = newTree(root, leftTree, (yyvsp[(5) - (5)].tn));
                                                                ;}
    break;

  case 14:
#line 120 "calc-sintaxis.y"
    {
                                                                        node* root = newNode(0, yylineno, None, MDECL, NULL, NULL, NULL, 0);
                                                                        node* left = newNode(0, yylineno, None, MDECLTYPE, NULL, NULL, NULL, 0);
                                                                        tree* leftTree = newTree(left, (yyvsp[(1) - (4)].tn), NULL);
                                                                        (yyval.tn) = newTree(root, leftTree, (yyvsp[(4) - (4)].tn));
                                                                ;}
    break;

  case 15:
#line 128 "calc-sintaxis.y"
    {
                                node* root = newNode(0, yylineno, (yyvsp[(1) - (2)].i), NONE, (yyvsp[(2) - (2)].s),NULL,NULL, 0);
                                (yyval.tn) = newTree(root, NULL, NULL);
                        ;}
    break;

  case 16:
#line 132 "calc-sintaxis.y"
    {
                                node* root = newNode(0, yylineno, Void, NONE, (yyvsp[(2) - (2)].s),NULL,NULL, 0);
                                (yyval.tn) = newTree(root, NULL, NULL);
                        ;}
    break;

  case 17:
#line 138 "calc-sintaxis.y"
    { 
                                        (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                ;}
    break;

  case 18:
#line 141 "calc-sintaxis.y"
    {
                                        node* root = newNode(0, yylineno, None, EXT, NULL, NULL, NULL, 0);
                                        (yyval.tn) = newTree(root,NULL,NULL);
                                ;}
    break;

  case 19:
#line 147 "calc-sintaxis.y"
    {    
                                    node* left = newNode(0, yylineno, (yyvsp[(1) - (4)].i), PARAM, (yyvsp[(2) - (4)].s), NULL,NULL, 0);
                                    tree* leftTree = newTree(left, NULL, NULL);
                                    node* root = newNode(0, yylineno, None, COMMA, NULL, NULL, NULL, 0);
                                    (yyval.tn) = newTree(root, leftTree, (yyvsp[(4) - (4)].tn));  
                               ;}
    break;

  case 20:
#line 153 "calc-sintaxis.y"
    {
                                node* root = newNode(0, yylineno, (yyvsp[(1) - (2)].i), PARAM, (yyvsp[(2) - (2)].s), NULL,NULL, 0);
                                (yyval.tn) = newTree(root,NULL,NULL);
                       ;}
    break;

  case 21:
#line 159 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, BLOCKDECL, NULL, NULL, NULL, 0);
                                                (yyval.tn)= newTree(root,(yyvsp[(2) - (4)].tn),(yyvsp[(3) - (4)].tn));
                                        ;}
    break;

  case 22:
#line 163 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, BLOCKDECL, NULL, NULL, NULL, 0);
                                                (yyval.tn)= newTree(root,NULL,(yyvsp[(2) - (3)].tn));
                                        ;}
    break;

  case 23:
#line 167 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, BLOCKDECL, NULL, NULL, NULL, 0);
                                                (yyval.tn)= newTree(root,(yyvsp[(2) - (3)].tn),NULL);
                                        ;}
    break;

  case 24:
#line 171 "calc-sintaxis.y"
    {
                                node* root = newNode(0, yylineno, None, NONEBLOCK, NULL, NULL, NULL, 0);
                                (yyval.tn) = newTree(root,NULL,NULL);   
                        ;}
    break;

  case 25:
#line 177 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, STMT, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root, (yyvsp[(1) - (2)].tn), (yyvsp[(2) - (2)].tn));
                                        ;}
    break;

  case 26:
#line 181 "calc-sintaxis.y"
    { 
                                (yyval.tn) = (yyvsp[(1) - (1)].tn);
                        ;}
    break;

  case 27:
#line 186 "calc-sintaxis.y"
    {
                        (yyval.i) = Int;
                ;}
    break;

  case 28:
#line 189 "calc-sintaxis.y"
    {
                        (yyval.i) = Bool;
                ;}
    break;

  case 29:
#line 194 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, STMTASSIGN, NULL, NULL, NULL, 0);
                                                node* leftRoot = newNode(0, yylineno, None, VAR, (yyvsp[(1) - (4)].s), NULL, NULL, 0);
                                                tree* leftTree = newTree(leftRoot, NULL, NULL);
                                                (yyval.tn) = newTree(root, leftTree, (yyvsp[(3) - (4)].tn));   
                                        ;}
    break;

  case 30:
#line 200 "calc-sintaxis.y"
    {
                                                (yyval.tn) = (yyvsp[(1) - (2)].tn);
                                        ;}
    break;

  case 31:
#line 203 "calc-sintaxis.y"
    {   
                                                (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                        ;}
    break;

  case 32:
#line 206 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, STMTWHILE, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(2) - (3)].tn), (yyvsp[(3) - (3)].tn)); 
                                        ;}
    break;

  case 33:
#line 210 "calc-sintaxis.y"
    {
                                                (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                        ;}
    break;

  case 34:
#line 213 "calc-sintaxis.y"
    {
                                                (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                        ;}
    break;

  case 35:
#line 216 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, SEMICOLON, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root, NULL, NULL); 
                                        ;}
    break;

  case 36:
#line 222 "calc-sintaxis.y"
    {
                                        node* root = newNode(0, yylineno, None, RET, NULL, NULL, NULL, 0);
                                        (yyval.tn) = newTree(root, NULL, (yyvsp[(2) - (3)].tn));    
                                ;}
    break;

  case 37:
#line 226 "calc-sintaxis.y"
    {
                                        node* root = newNode(0, yylineno, None, RET, NULL, NULL, NULL, 0);
                                        (yyval.tn) = newTree(root, NULL, NULL);    
                                ;}
    break;

  case 38:
#line 232 "calc-sintaxis.y"
    {
                                                                node* root = newNode(0, yylineno, None, IFTHEN, NULL, NULL, NULL, 0);
                                                                (yyval.tn) = newTree(root,(yyvsp[(3) - (6)].tn),(yyvsp[(6) - (6)].tn));
                                                        ;}
    break;

  case 39:
#line 236 "calc-sintaxis.y"
    {
                                                                node* root = newNode(0, yylineno, None, IFTELSE, NULL, NULL, NULL, 0);
                                                                node* leftRoot = newNode(0, yylineno, None, IFTHEN, NULL, NULL, NULL, 0);
                                                                tree* leftTree = newTree(leftRoot, (yyvsp[(3) - (8)].tn), (yyvsp[(6) - (8)].tn));
                                                                (yyval.tn) = newTree(root,leftTree,(yyvsp[(8) - (8)].tn));
                                                        ;}
    break;

  case 40:
#line 244 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, MCALL, NULL, NULL, NULL, 0);
                                                node* leftRoot = newNode(0, yylineno, None, NONE, (yyvsp[(1) - (4)].s), NULL, NULL, 0);
                                                tree* leftTree = newTree(leftRoot, NULL, NULL);
                                                (yyval.tn) = newTree(root,leftTree,(yyvsp[(3) - (4)].tn));
                                        ;}
    break;

  case 41:
#line 250 "calc-sintaxis.y"
    {
                                                node* root = newNode(0, yylineno, None, MCALL, NULL, NULL, NULL, 0);
                                                node* leftRoot = newNode(0, yylineno, None, NONE, (yyvsp[(1) - (3)].s), NULL,NULL, 0);
                                                tree* leftTree = newTree(leftRoot,NULL, NULL);
                                                (yyval.tn) = newTree(root,leftTree, NULL);
                                        ;}
    break;

  case 42:
#line 258 "calc-sintaxis.y"
    {
                                                        node* root = newNode(0, yylineno, None, COMMA, NULL, NULL, NULL, 0);
                                                        (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));
                                                ;}
    break;

  case 43:
#line 262 "calc-sintaxis.y"
    {
                                                        (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                                ;}
    break;

  case 44:
#line 267 "calc-sintaxis.y"
    { 
                                                        node* root = newNode(0, yylineno, None, VAR, (yyvsp[(1) - (1)].s), NULL, NULL, 0);
                                                        (yyval.tn) = newTree(root,NULL,NULL);      
                                                ;}
    break;

  case 45:
#line 271 "calc-sintaxis.y"
    {
                                                        (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                                ;}
    break;

  case 46:
#line 274 "calc-sintaxis.y"
    {   
                                                        (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                                ;}
    break;

  case 47:
#line 277 "calc-sintaxis.y"
    {
                                                        (yyval.tn) = (yyvsp[(1) - (1)].tn);
                                                ;}
    break;

  case 48:
#line 280 "calc-sintaxis.y"
    {
                                                        node* root = newNode(0, yylineno, None, NEGATIVEEXP, NULL,NULL,NULL, 0);
                                                        (yyval.tn) = newTree(root, NULL, (yyvsp[(2) - (2)].tn));
                                                ;}
    break;

  case 49:
#line 284 "calc-sintaxis.y"
    {
                                                        node* root = newNode(0, yylineno, None, NOTEXP, NULL,NULL,NULL, 0);
                                                        (yyval.tn) = newTree(root, NULL, (yyvsp[(2) - (2)].tn));
                                                ;}
    break;

  case 50:
#line 288 "calc-sintaxis.y"
    { 
                                                        (yyval.tn) = (yyvsp[(2) - (3)].tn);
                                                ;}
    break;

  case 51:
#line 293 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, SUMA, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 52:
#line 297 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, RESTA, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 53:
#line 301 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, MULTIPLICACION, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 54:
#line 305 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, DIVISION, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 55:
#line 309 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, LMOD, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 56:
#line 313 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, MENOR, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 57:
#line 317 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, MAYOR, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 58:
#line 321 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, LEQUAL, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 59:
#line 325 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, LAND, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 60:
#line 329 "calc-sintaxis.y"
    { 
                                                node* root = newNode(0, yylineno, None, LOR, NULL, NULL, NULL, 0);
                                                (yyval.tn) = newTree(root,(yyvsp[(1) - (3)].tn),(yyvsp[(3) - (3)].tn));      
                                        ;}
    break;

  case 61:
#line 335 "calc-sintaxis.y"
    {
                        node* root = newNode((yyvsp[(1) - (1)].i), 0, Int, CONST, NULL, NULL, NULL, 0); 
                        (yyval.tn) = newTree(root,NULL, NULL);
                ;}
    break;

  case 62:
#line 339 "calc-sintaxis.y"
    {
                        node* root = newNode(1, 0, Bool, CONST, NULL, NULL, NULL, 0); 
                        (yyval.tn) = newTree(root, NULL, NULL);
                ;}
    break;

  case 63:
#line 343 "calc-sintaxis.y"
    {
                        node* root = newNode(0, 0, Bool, CONST, NULL, NULL, NULL, 0); 
                        (yyval.tn) = newTree(root, NULL, NULL);
                ;}
    break;


/* Line 1267 of yacc.c.  */
#line 2027 "calc-sintaxis.tab.c"
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


#line 348 "calc-sintaxis.y"


