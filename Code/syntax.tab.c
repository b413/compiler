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
#line 1 "./syntax.y" /* yacc.c:339  */

    #include<stdio.h>
    #include<malloc.h>
    #include<string.h>
    #include"lex.yy.c"
    #include"Tree.h"
	#include"Kits.h"

#line 75 "./syntax.tab.c" /* yacc.c:339  */

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
   by #include "syntax.tab.h".  */
#ifndef YY_YY_SYNTAX_TAB_H_INCLUDED
# define YY_YY_SYNTAX_TAB_H_INCLUDED
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
    INT = 258,
    FLOAT = 259,
    ID = 260,
    TYPE = 261,
    SEMI = 262,
    COMMA = 263,
    ASSIGNOP = 264,
    RELOP = 265,
    PLUS = 266,
    MINUS = 267,
    STAR = 268,
    DIV = 269,
    AND = 270,
    OR = 271,
    DOT = 272,
    NOT = 273,
    LP = 274,
    RP = 275,
    LB = 276,
    RB = 277,
    LC = 278,
    RC = 279,
    STRUCT = 280,
    RETURN = 281,
    IF = 282,
    ELSE = 283,
    WHILE = 284,
    TAKENEGATIVE = 285,
    LOWER_THAN_ELSE = 286
  };
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED

union YYSTYPE
{
#line 9 "./syntax.y" /* yacc.c:355  */

    int type_int;
    float type_float;
    struct Tnode* type_Node_pointer;
    char* type_char_pointer;

#line 154 "./syntax.tab.c" /* yacc.c:355  */
};

typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif

/* Location type.  */
#if ! defined YYLTYPE && ! defined YYLTYPE_IS_DECLARED
typedef struct YYLTYPE YYLTYPE;
struct YYLTYPE
{
  int first_line;
  int first_column;
  int last_line;
  int last_column;
};
# define YYLTYPE_IS_DECLARED 1
# define YYLTYPE_IS_TRIVIAL 1
#endif


extern YYSTYPE yylval;
extern YYLTYPE yylloc;
int yyparse (void);

#endif /* !YY_YY_SYNTAX_TAB_H_INCLUDED  */

/* Copy the second part of user declarations.  */

#line 185 "./syntax.tab.c" /* yacc.c:358  */

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
         || (defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL \
             && defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss_alloc;
  YYSTYPE yyvs_alloc;
  YYLTYPE yyls_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE) + sizeof (YYLTYPE)) \
      + 2 * YYSTACK_GAP_MAXIMUM)

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
#define YYFINAL  11
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   287

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  32
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  22
/* YYNRULES -- Number of rules.  */
#define YYNRULES  70
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  134

/* YYTRANSLATE[YYX] -- Symbol number corresponding to YYX as returned
   by yylex, with out-of-bounds checking.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   286

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
      25,    26,    27,    28,    29,    30,    31
};

#if YYDEBUG
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_uint8 yyrline[] =
{
       0,    45,    45,    48,    49,    54,    56,    58,    60,    61,
      65,    66,    70,    72,    75,    80,    85,    88,    90,    93,
      96,    99,   106,   109,   114,   124,   126,   129,   132,   138,
     139,   142,   145,   147,   148,   151,   155,   160,   167,   168,
     169,   170,   172,   173,   176,   183,   184,   189,   190,   194,
     196,   198,   200,   202,   204,   206,   208,   210,   213,   214,
     215,   219,   223,   226,   229,   231,   233,   238,   239,   241,
     243
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "INT", "FLOAT", "ID", "TYPE", "SEMI",
  "COMMA", "ASSIGNOP", "RELOP", "PLUS", "MINUS", "STAR", "DIV", "AND",
  "OR", "DOT", "NOT", "LP", "RP", "LB", "RB", "LC", "RC", "STRUCT",
  "RETURN", "IF", "ELSE", "WHILE", "TAKENEGATIVE", "LOWER_THAN_ELSE",
  "$accept", "Program", "ExtDefList", "ExtDef", "ExtDecList", "Specifier",
  "StructSpecifier", "OptTag", "Tag", "VarDec", "FunDec", "VarList",
  "ParamDec", "CompSt", "StmtList", "Stmt", "DefList", "Def", "DecList",
  "Dec", "Exp", "Args", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286
};
# endif

#define YYPACT_NINF -57

#define yypact_value_is_default(Yystate) \
  (!!((Yystate) == (-57)))

#define YYTABLE_NINF -44

#define yytable_value_is_error(Yytable_value) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
static const yytype_int16 yypact[] =
{
       0,   -57,     3,    17,   -57,     0,    40,   -57,    -9,    23,
     -57,   -57,   -57,    36,   -57,    49,    28,    27,    14,    -1,
      12,    68,    71,   -57,     0,   -57,    51,    68,    52,     0,
     -57,    68,    57,    75,    81,   -57,   -57,    65,    83,    39,
     -57,    32,    99,   105,   -57,   -57,   101,   -57,     0,   120,
     -57,   -57,   124,   -57,   -57,   113,   138,   138,   138,   138,
     114,   118,   -57,   122,    39,   151,   138,   -57,    68,   -57,
     -57,   -57,   106,    43,    43,   192,    87,   111,   116,   -57,
     -57,   -57,   138,   138,   138,   138,   138,   138,   138,   138,
     144,   135,   231,   -57,   139,   -57,   165,   149,   -57,   -57,
     -57,   150,   205,   163,   218,   231,   266,   131,   131,    43,
      43,   255,   243,   -57,   129,   178,   -57,   138,   -57,    66,
      66,    66,    66,   -57,   -57,   -57,   127,   143,   -57,   -57,
      66,    66,   -57,   -57
};

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       4,    12,    18,     0,     2,     4,     0,    13,    19,     0,
      15,     1,     3,    20,     7,     0,    10,     0,     0,     0,
       0,     0,     0,     9,    43,     8,     0,     0,     0,    43,
      24,     0,     0,    26,     0,    20,    11,     0,     0,     0,
      16,    47,     0,    45,    14,    42,    27,    23,     0,     0,
      22,    21,     0,    65,    66,    64,     0,     0,     0,     0,
       0,     0,    33,     0,     0,     0,     0,    44,     0,    25,
       5,    31,     0,    58,    59,     0,     0,     0,     0,    28,
      29,    32,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,    46,     0,    61,    70,     0,    57,    38,
      34,     0,     0,     0,     0,    49,    52,    53,    54,    55,
      56,    50,    51,    63,     0,     0,    67,     0,    60,     0,
       0,     0,     0,    68,    62,    69,    39,    35,    41,    37,
       0,     0,    40,    36
};

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -57,   -57,   179,   -57,   164,     4,   -57,   -57,   -57,   -20,
     -57,   148,   -57,   180,   134,   -40,    30,   -57,   142,   -57,
     -56,    94
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int8 yydefgoto[] =
{
      -1,     3,     4,     5,    15,    27,     7,     9,    10,    16,
      17,    32,    33,    62,    63,    64,    28,    29,    42,    43,
      65,    97
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
      73,    74,    75,    76,     6,     1,     1,    41,     8,     6,
      92,    46,    -6,    34,   -17,    26,    96,    11,    -6,    30,
       1,   102,   104,    31,     2,     2,   105,   106,   107,   108,
     109,   110,   111,   112,    23,   115,    21,    -6,   -43,     2,
      52,    66,    53,    54,    55,    13,    18,    14,    41,    22,
      24,    56,    31,    22,    39,    19,    20,    57,    58,    45,
      90,    96,    24,   -30,    91,    59,    60,    52,    61,    53,
      54,    55,    37,    35,    38,    40,    44,    47,    56,   126,
     127,   128,   129,    48,    57,    58,    49,    50,    99,    24,
     132,   133,    59,    60,   100,    61,    82,    83,    84,    85,
      86,    87,    88,    89,    90,    51,    67,    94,    91,    53,
      54,    55,   101,    68,    53,    54,    55,   103,    56,    53,
      54,    55,    22,    56,    57,    58,    95,    70,    56,    57,
      58,    71,    72,    77,    57,    58,   114,    78,    53,    54,
      55,    53,    54,    55,    86,    87,    79,    56,    90,   113,
      56,   123,    91,    57,    58,   130,    57,    58,    81,   116,
      82,    83,    84,    85,    86,    87,    88,    89,    90,   118,
     119,   131,    91,   117,    82,    83,    84,    85,    86,    87,
      88,    89,    90,   121,    12,    36,    91,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    69,    25,    80,    91,
     124,    82,    83,    84,    85,    86,    87,    88,    89,    90,
      93,   125,    98,    91,    82,    83,    84,    85,    86,    87,
      88,    89,    90,     0,     0,   120,    91,    82,    83,    84,
      85,    86,    87,    88,    89,    90,     0,     0,   122,    91,
      82,    83,    84,    85,    86,    87,    88,    89,    90,     0,
       0,     0,    91,    83,    84,    85,    86,    87,    88,     0,
      90,     0,     0,     0,    91,    83,    84,    85,    86,    87,
       0,     0,    90,     0,     0,     0,    91,    84,    85,    86,
      87,     0,     0,    90,     0,     0,     0,    91
};

static const yytype_int16 yycheck[] =
{
      56,    57,    58,    59,     0,     6,     6,    27,     5,     5,
      66,    31,     0,     1,    23,     1,    72,     0,     6,    20,
       6,    77,    78,    19,    25,    25,    82,    83,    84,    85,
      86,    87,    88,    89,     7,    91,     8,    25,    24,    25,
       1,     9,     3,     4,     5,     5,    23,     7,    68,    21,
      23,    12,    48,    21,    24,    19,     7,    18,    19,    29,
      17,   117,    23,    24,    21,    26,    27,     1,    29,     3,
       4,     5,     1,     5,     3,    24,    24,    20,    12,   119,
     120,   121,   122,     8,    18,    19,     5,    22,     1,    23,
     130,   131,    26,    27,     7,    29,     9,    10,    11,    12,
      13,    14,    15,    16,    17,    22,     7,     1,    21,     3,
       4,     5,     1,     8,     3,     4,     5,     1,    12,     3,
       4,     5,    21,    12,    18,    19,    20,     7,    12,    18,
      19,     7,    19,    19,    18,    19,     1,    19,     3,     4,
       5,     3,     4,     5,    13,    14,    24,    12,    17,     5,
      12,    22,    21,    18,    19,    28,    18,    19,     7,    20,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    20,
      20,    28,    21,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    20,     5,    21,    21,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    48,    17,    64,    21,
      22,     9,    10,    11,    12,    13,    14,    15,    16,    17,
      68,   117,    20,    21,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    -1,    -1,    20,    21,     9,    10,    11,
      12,    13,    14,    15,    16,    17,    -1,    -1,    20,    21,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    -1,
      -1,    -1,    21,    10,    11,    12,    13,    14,    15,    -1,
      17,    -1,    -1,    -1,    21,    10,    11,    12,    13,    14,
      -1,    -1,    17,    -1,    -1,    -1,    21,    11,    12,    13,
      14,    -1,    -1,    17,    -1,    -1,    -1,    21
};

  /* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
     symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     6,    25,    33,    34,    35,    37,    38,     5,    39,
      40,     0,    34,     5,     7,    36,    41,    42,    23,    19,
       7,     8,    21,     7,    23,    45,     1,    37,    48,    49,
      20,    37,    43,    44,     1,     5,    36,     1,     3,    48,
      24,    41,    50,    51,    24,    48,    41,    20,     8,     5,
      22,    22,     1,     3,     4,     5,    12,    18,    19,    26,
      27,    29,    45,    46,    47,    52,     9,     7,     8,    43,
       7,     7,    19,    52,    52,    52,    52,    19,    19,    24,
      46,     7,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    21,    52,    50,     1,    20,    52,    53,    20,     1,
       7,     1,    52,     1,    52,    52,    52,    52,    52,    52,
      52,    52,    52,     5,     1,    52,    20,     8,    20,    20,
      20,    20,    20,    22,    22,    53,    47,    47,    47,    47,
      28,    28,    47,    47
};

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    32,    33,    34,    34,    35,    35,    35,    35,    35,
      36,    36,    37,    37,    38,    38,    38,    39,    39,    40,
      41,    41,    41,    42,    42,    43,    43,    44,    45,    46,
      46,    47,    47,    47,    47,    47,    47,    47,    47,    47,
      47,    47,    48,    48,    49,    50,    50,    51,    51,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    52,
      52,    52,    52,    52,    52,    52,    52,    52,    52,    53,
      53
};

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     2,     0,     6,     3,     2,     3,     3,
       1,     3,     1,     1,     5,     2,     5,     1,     0,     1,
       1,     4,     4,     4,     3,     3,     1,     2,     4,     2,
       0,     2,     2,     1,     3,     5,     7,     5,     3,     5,
       7,     5,     2,     0,     3,     1,     3,     1,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     2,     2,
       4,     3,     4,     3,     1,     1,     1,     4,     4,     3,
       1
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


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)                                \
    do                                                                  \
      if (N)                                                            \
        {                                                               \
          (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;        \
          (Current).first_column = YYRHSLOC (Rhs, 1).first_column;      \
          (Current).last_line    = YYRHSLOC (Rhs, N).last_line;         \
          (Current).last_column  = YYRHSLOC (Rhs, N).last_column;       \
        }                                                               \
      else                                                              \
        {                                                               \
          (Current).first_line   = (Current).last_line   =              \
            YYRHSLOC (Rhs, 0).last_line;                                \
          (Current).first_column = (Current).last_column =              \
            YYRHSLOC (Rhs, 0).last_column;                              \
        }                                                               \
    while (0)
#endif

#define YYRHSLOC(Rhs, K) ((Rhs)[K])


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


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL

/* Print *YYLOCP on YYO.  Private, do not rely on its existence. */

YY_ATTRIBUTE_UNUSED
static unsigned
yy_location_print_ (FILE *yyo, YYLTYPE const * const yylocp)
{
  unsigned res = 0;
  int end_col = 0 != yylocp->last_column ? yylocp->last_column - 1 : 0;
  if (0 <= yylocp->first_line)
    {
      res += YYFPRINTF (yyo, "%d", yylocp->first_line);
      if (0 <= yylocp->first_column)
        res += YYFPRINTF (yyo, ".%d", yylocp->first_column);
    }
  if (0 <= yylocp->last_line)
    {
      if (yylocp->first_line < yylocp->last_line)
        {
          res += YYFPRINTF (yyo, "-%d", yylocp->last_line);
          if (0 <= end_col)
            res += YYFPRINTF (yyo, ".%d", end_col);
        }
      else if (0 <= end_col && yylocp->first_column < end_col)
        res += YYFPRINTF (yyo, "-%d", end_col);
    }
  return res;
 }

#  define YY_LOCATION_PRINT(File, Loc)          \
  yy_location_print_ (File, &(Loc))

# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


# define YY_SYMBOL_PRINT(Title, Type, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Type, Value, Location); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*----------------------------------------.
| Print this symbol's value on YYOUTPUT.  |
`----------------------------------------*/

static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  FILE *yyo = yyoutput;
  YYUSE (yyo);
  YYUSE (yylocationp);
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
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, YYLTYPE const * const yylocationp)
{
  YYFPRINTF (yyoutput, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  YY_LOCATION_PRINT (yyoutput, *yylocationp);
  YYFPRINTF (yyoutput, ": ");
  yy_symbol_value_print (yyoutput, yytype, yyvaluep, yylocationp);
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
yy_reduce_print (yytype_int16 *yyssp, YYSTYPE *yyvsp, YYLTYPE *yylsp, int yyrule)
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
                       , &(yylsp[(yyi + 1) - (yynrhs)])                       );
      YYFPRINTF (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)          \
do {                                    \
  if (yydebug)                          \
    yy_reduce_print (yyssp, yyvsp, yylsp, Rule); \
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
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, YYLTYPE *yylocationp)
{
  YYUSE (yyvaluep);
  YYUSE (yylocationp);
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
/* Location data for the lookahead symbol.  */
YYLTYPE yylloc
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
  = { 1, 1, 1, 1 }
# endif
;
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
       'yyls': related to locations.

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

    /* The location stack.  */
    YYLTYPE yylsa[YYINITDEPTH];
    YYLTYPE *yyls;
    YYLTYPE *yylsp;

    /* The locations where the error started and ended.  */
    YYLTYPE yyerror_range[3];

    YYSIZE_T yystacksize;

  int yyn;
  int yyresult;
  /* Lookahead token as an internal (translated) token number.  */
  int yytoken = 0;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;
  YYLTYPE yyloc;

#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N), yylsp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  yyssp = yyss = yyssa;
  yyvsp = yyvs = yyvsa;
  yylsp = yyls = yylsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */
  yylsp[0] = yylloc;
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
        YYLTYPE *yyls1 = yyls;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * sizeof (*yyssp),
                    &yyvs1, yysize * sizeof (*yyvsp),
                    &yyls1, yysize * sizeof (*yylsp),
                    &yystacksize);

        yyls = yyls1;
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
        YYSTACK_RELOCATE (yyls_alloc, yyls);
#  undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;
      yylsp = yyls + yysize - 1;

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
  *++yylsp = yylloc;
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

  /* Default location.  */
  YYLLOC_DEFAULT (yyloc, (yylsp - yylen), yylen);
  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 45 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_Program, NULL, (yyloc).first_line, 1, (yyvsp[0].type_Node_pointer)); /*if(ISOK==true && ROOT!=NULL) Traverse(ROOT,0);*/ }
#line 1477 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 3:
#line 48 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_ExtDefList, NULL, (yyloc).first_line, 2, (yyvsp[-1].type_Node_pointer), (yyvsp[0].type_Node_pointer));}
#line 1483 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 4:
#line 49 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_ExtDefList, NULL, (yyloc).first_line, 0);}
#line 1489 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 5:
#line 54 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1495 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 6:
#line 56 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[0].type_Node_pointer)=Reduction(T_SEMI, NULL, (yyloc).first_line, 0);
									(yyval.type_Node_pointer)=Reduction(T_ExtDef, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1502 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 7:
#line 58 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[0].type_Node_pointer)=Reduction(T_SEMI, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_ExtDef, NULL, (yyloc).first_line, 2,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1509 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 8:
#line 60 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_ExtDef, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1515 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 9:
#line 61 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[0].type_Node_pointer)=Reduction(T_SEMI, NULL, (yyloc).first_line, 0);
									(yyval.type_Node_pointer)=Reduction(T_ExtDef, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1522 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 10:
#line 65 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_ExtDecList, NULL, (yyloc).first_line, 1,(yyvsp[0].type_Node_pointer));}
#line 1528 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 11:
#line 66 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_COMMA, NULL, (yyloc).first_line, 0);
										(yyval.type_Node_pointer)=Reduction(T_ExtDecList, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1535 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 12:
#line 70 "./syntax.y" /* yacc.c:1646  */
    { struct Tnode* n=Reduction(T_TYPE, (yyvsp[0].type_char_pointer), (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Specifier, NULL, (yyloc).first_line, 1,n);}
#line 1542 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 13:
#line 72 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_Specifier, NULL, (yyloc).first_line, 1,(yyvsp[0].type_Node_pointer)); }
#line 1548 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 14:
#line 75 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-4].type_Node_pointer)=Reduction(T_STRUCT, NULL, (yyloc).first_line, 0);
												(yyvsp[-2].type_Node_pointer)=Reduction(T_LC, NULL, (yyloc).first_line, 0);
												(yyvsp[0].type_Node_pointer)=Reduction(T_RC, NULL, (yyloc).first_line, 0);
												(yyval.type_Node_pointer)=Reduction(T_StructSpecifier, NULL, (yyloc).first_line, 5,(yyvsp[-4].type_Node_pointer),(yyvsp[-3].type_Node_pointer),(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer)); }
#line 1557 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 15:
#line 80 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_STRUCT, NULL, (yyloc).first_line, 0); 
								(yyval.type_Node_pointer)=Reduction(T_StructSpecifier, NULL, (yyloc).first_line, 2,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1564 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 16:
#line 85 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1570 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 17:
#line 88 "./syntax.y" /* yacc.c:1646  */
    { struct Tnode* n=Reduction(T_ID, (yyvsp[0].type_char_pointer), (yyloc).first_line, 0);(yyval.type_Node_pointer)=Reduction(T_OptTag, NULL, (yyloc).first_line, 1,n); 
	   		SymTableSize++; }
#line 1577 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 18:
#line 90 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_OptTag, NULL, (yyloc).first_line, 0);SymTableSize++; }
#line 1583 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 19:
#line 93 "./syntax.y" /* yacc.c:1646  */
    {struct Tnode* n=Reduction(T_ID, (yyvsp[0].type_char_pointer), (yyloc).first_line, 0);(yyval.type_Node_pointer)=Reduction(T_Tag, NULL, (yyloc).first_line, 1,n); }
#line 1589 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 20:
#line 96 "./syntax.y" /* yacc.c:1646  */
    {   struct Tnode* n=Reduction(T_ID, (yyvsp[0].type_char_pointer), (yyloc).first_line, 0);
				(yyval.type_Node_pointer)=Reduction(T_VarDec, NULL, (yyloc).first_line, 1,n);
				SymTableSize++;	}
#line 1597 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 21:
#line 99 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-2].type_Node_pointer)=Reduction(T_LB, NULL, (yyloc).first_line, 0);
							struct Tnode* n=Reduction(T_INT,(yyvsp[-1].type_char_pointer),(yyloc).first_line,0);
							(yyvsp[0].type_Node_pointer)=Reduction(T_RB, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_VarDec, NULL, (yyloc).first_line, 4,(yyvsp[-3].type_Node_pointer),(yyvsp[-2].type_Node_pointer),n,(yyvsp[0].type_Node_pointer));}
#line 1606 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 22:
#line 106 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1612 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 23:
#line 109 "./syntax.y" /* yacc.c:1646  */
    { struct Tnode* n=Reduction(T_ID, (yyvsp[-3].type_char_pointer), (yyloc).first_line, 0);
							(yyvsp[-2].type_Node_pointer)=Reduction(T_LP, NULL, (yyloc).first_line, 0);
							(yyvsp[0].type_Node_pointer)=Reduction(T_RP, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_FunDec, NULL, (yyloc).first_line, 4,n,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));
							SymTableSize++; }
#line 1622 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 24:
#line 114 "./syntax.y" /* yacc.c:1646  */
    {struct Tnode* n=Reduction(T_ID, (yyvsp[-2].type_char_pointer), (yyloc).first_line, 0);
							(yyvsp[-1].type_Node_pointer)=Reduction(T_LP, NULL, (yyloc).first_line, 0);
							(yyvsp[0].type_Node_pointer)=Reduction(T_RP, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_FunDec, NULL, (yyloc).first_line, 3,n,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));
							SymTableSize++; }
#line 1632 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 25:
#line 124 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_COMMA, NULL, (yyloc).first_line, 0);
									(yyval.type_Node_pointer)=Reduction(T_VarList, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1639 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 26:
#line 126 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_VarList, NULL, (yyloc).first_line, 1,(yyvsp[0].type_Node_pointer));}
#line 1645 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 27:
#line 129 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_ParamDec, NULL, (yyloc).first_line, 2,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1651 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 28:
#line 132 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-3].type_Node_pointer)=Reduction(T_LC, NULL, (yyloc).first_line, 0);
									(yyvsp[0].type_Node_pointer)=Reduction(T_RC, NULL, (yyloc).first_line, 0);
									(yyval.type_Node_pointer)=Reduction(T_CompSt, NULL, (yyloc).first_line, 4,(yyvsp[-3].type_Node_pointer),(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1659 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 29:
#line 138 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_StmtList, NULL, (yyloc).first_line, 2,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1665 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 30:
#line 139 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_StmtList, NULL, (yyloc).first_line, 0);}
#line 1671 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 31:
#line 142 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1677 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 32:
#line 145 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[0].type_Node_pointer)=Reduction(T_SEMI, NULL, (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Stmt, NULL, (yyloc).first_line, 2,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1684 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 33:
#line 147 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_Stmt, NULL, (yyloc).first_line, 1,(yyvsp[0].type_Node_pointer));}
#line 1690 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 34:
#line 148 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-2].type_Node_pointer)=Reduction(T_RETURN, NULL, (yyloc).first_line, 0);
						(yyvsp[0].type_Node_pointer)=Reduction(T_SEMI, NULL, (yyloc).first_line, 0);
						(yyval.type_Node_pointer)=Reduction(T_Stmt, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1698 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 35:
#line 151 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-4].type_Node_pointer)=Reduction(T_IF, NULL, (yyloc).first_line, 0);
												(yyvsp[-3].type_Node_pointer)=Reduction(T_LP, NULL, (yyloc).first_line, 0);
												(yyvsp[-1].type_Node_pointer)=Reduction(T_RP, NULL, (yyloc).first_line, 0);
												(yyval.type_Node_pointer)=Reduction(T_Stmt, NULL, (yyloc).first_line, 5,(yyvsp[-4].type_Node_pointer),(yyvsp[-3].type_Node_pointer),(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1707 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 36:
#line 155 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-6].type_Node_pointer)=Reduction(T_IF, NULL, (yyloc).first_line, 0);
									(yyvsp[-5].type_Node_pointer)=Reduction(T_LP, NULL, (yyloc).first_line, 0);
									(yyvsp[-3].type_Node_pointer)=Reduction(T_RP, NULL, (yyloc).first_line, 0);
									(yyvsp[-1].type_Node_pointer)=Reduction(T_ELSE, NULL, (yyloc).first_line, 0);
									(yyval.type_Node_pointer)=Reduction(T_Stmt, NULL, (yyloc).first_line, 7,(yyvsp[-6].type_Node_pointer),(yyvsp[-5].type_Node_pointer),(yyvsp[-4].type_Node_pointer),(yyvsp[-3].type_Node_pointer),(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1717 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 37:
#line 160 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-4].type_Node_pointer)=Reduction(T_WHILE, NULL, (yyloc).first_line, 0);
							(yyvsp[-3].type_Node_pointer)=Reduction(T_LP, NULL, (yyloc).first_line, 0);
							(yyvsp[-1].type_Node_pointer)=Reduction(T_RP, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_Stmt, NULL, (yyloc).first_line, 5,(yyvsp[-4].type_Node_pointer),(yyvsp[-3].type_Node_pointer),(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1726 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 38:
#line 167 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1732 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 39:
#line 168 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1738 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 40:
#line 169 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1744 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 41:
#line 170 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1750 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 42:
#line 172 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_DefList, NULL, (yyloc).first_line, 2,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1756 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 43:
#line 173 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_DefList, NULL, (yyloc).first_line, 0);}
#line 1762 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 44:
#line 176 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[0].type_Node_pointer)=Reduction(T_SEMI, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_Def, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1769 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 45:
#line 183 "./syntax.y" /* yacc.c:1646  */
    {(yyval.type_Node_pointer)=Reduction(T_DecList, NULL, (yyloc).first_line, 1,(yyvsp[0].type_Node_pointer)); }
#line 1775 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 46:
#line 184 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_COMMA, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_DecList, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1782 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 47:
#line 189 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_Dec, NULL, (yyloc).first_line, 1,(yyvsp[0].type_Node_pointer)); }
#line 1788 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 48:
#line 190 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_ASSIGNOP, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_Dec, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer)); }
#line 1795 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 49:
#line 194 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_ASSIGNOP, NULL, (yyloc).first_line, 0);
							(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1802 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 50:
#line 196 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_AND, NULL, (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1809 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 51:
#line 198 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_OR, NULL, (yyloc).first_line, 0);
				   (yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1816 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 52:
#line 200 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_RELOP, NULL, (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1823 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 53:
#line 202 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_PLUS, NULL, (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1830 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 54:
#line 204 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_MINUS, NULL, (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1837 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 55:
#line 206 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_STAR, NULL, (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1844 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 56:
#line 208 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_DIV, NULL, (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1851 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 57:
#line 210 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-2].type_Node_pointer)=Reduction(T_LP, NULL, (yyloc).first_line, 0);
				  (yyvsp[0].type_Node_pointer)=Reduction(T_RP, NULL, (yyloc).first_line, 0);
				  (yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1859 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 58:
#line 213 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_MINUS, NULL, (yyloc).first_line, 0);(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 2,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1865 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 59:
#line 214 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_NOT, NULL, (yyloc).first_line, 0);(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 2,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1871 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 60:
#line 215 "./syntax.y" /* yacc.c:1646  */
    { struct Tnode* n=Reduction(T_ID, (yyvsp[-3].type_char_pointer), (yyloc).first_line, 0); 
						(yyvsp[-2].type_Node_pointer)=Reduction(T_LP, NULL, (yyloc).first_line, 0);
						(yyvsp[0].type_Node_pointer)=Reduction(T_RP, NULL, (yyloc).first_line, 0);
						(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 4,n,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1880 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 61:
#line 219 "./syntax.y" /* yacc.c:1646  */
    { struct Tnode* n=Reduction(T_ID, (yyvsp[-2].type_char_pointer), (yyloc).first_line, 0); 
				(yyvsp[-1].type_Node_pointer)=Reduction(T_LP, NULL, (yyloc).first_line, 0);
				(yyvsp[0].type_Node_pointer)=Reduction(T_RP, NULL, (yyloc).first_line, 0);
				(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,n,(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1889 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 62:
#line 223 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-2].type_Node_pointer)=Reduction(T_LB,NULL,(yyloc).first_line,0);
                        (yyvsp[0].type_Node_pointer)=Reduction(T_RB,NULL,(yyloc).first_line,0);
                        (yyval.type_Node_pointer)=Reduction(T_Exp,NULL,(yyloc).first_line,4,(yyvsp[-3].type_Node_pointer),(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1897 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 63:
#line 226 "./syntax.y" /* yacc.c:1646  */
    {struct Tnode* n=Reduction(T_ID, (yyvsp[0].type_char_pointer), (yyloc).first_line, 0); 
					(yyvsp[-1].type_Node_pointer)=Reduction(T_DOT, NULL, (yyloc).first_line, 0);
					(yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),n); }
#line 1905 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 64:
#line 229 "./syntax.y" /* yacc.c:1646  */
    {struct Tnode* n=Reduction(T_ID, (yyvsp[0].type_char_pointer), (yyloc).first_line, 0); 
		 (yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 1,n); }
#line 1912 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 65:
#line 231 "./syntax.y" /* yacc.c:1646  */
    { struct Tnode* n=Reduction(T_INT, (yyvsp[0].type_char_pointer), (yyloc).first_line, 0); 
		 (yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 1,n);}
#line 1919 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 66:
#line 233 "./syntax.y" /* yacc.c:1646  */
    { struct Tnode* n=Reduction(T_FLOAT, (yyvsp[0].type_char_pointer), (yyloc).first_line, 0); 
		 (yyval.type_Node_pointer)=Reduction(T_Exp, NULL, (yyloc).first_line, 1,n);}
#line 1926 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 67:
#line 238 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1932 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 68:
#line 239 "./syntax.y" /* yacc.c:1646  */
    {}
#line 1938 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 69:
#line 241 "./syntax.y" /* yacc.c:1646  */
    { (yyvsp[-1].type_Node_pointer)=Reduction(T_COMMA, NULL, (yyloc).first_line, 0); 
						(yyval.type_Node_pointer)=Reduction(T_Args, NULL, (yyloc).first_line, 3,(yyvsp[-2].type_Node_pointer),(yyvsp[-1].type_Node_pointer),(yyvsp[0].type_Node_pointer));}
#line 1945 "./syntax.tab.c" /* yacc.c:1646  */
    break;

  case 70:
#line 243 "./syntax.y" /* yacc.c:1646  */
    { (yyval.type_Node_pointer)=Reduction(T_Args, NULL, (yyloc).first_line, 1,(yyvsp[0].type_Node_pointer));}
#line 1951 "./syntax.tab.c" /* yacc.c:1646  */
    break;


#line 1955 "./syntax.tab.c" /* yacc.c:1646  */
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
  *++yylsp = yyloc;

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

  yyerror_range[1] = yylloc;

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
                      yytoken, &yylval, &yylloc);
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

  yyerror_range[1] = yylsp[1-yylen];
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

      yyerror_range[1] = *yylsp;
      yydestruct ("Error: popping",
                  yystos[yystate], yyvsp, yylsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  yyerror_range[2] = yylloc;
  /* Using YYLLOC is tempting, but would change the location of
     the lookahead.  YYLOC is available though.  */
  YYLLOC_DEFAULT (yyloc, yyerror_range, 2);
  *++yylsp = yyloc;

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
                  yytoken, &yylval, &yylloc);
    }
  /* Do not reclaim the symbols of the rule whose action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
                  yystos[*yyssp], yyvsp, yylsp);
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
#line 245 "./syntax.y" /* yacc.c:1906  */

yyerror(char* msg){
    ISOK=false;
	//LJY_0322
    char a[200];
    if(yytext!=NULL && yytext[0]!='\0')
        sprintf(a,"something wrong near \'%s\'",yytext);
    else
        sprintf(a,"something wrong");
	ShowError(T_ERROR_B,yylineno);
	printf("%s\n",a);
}




