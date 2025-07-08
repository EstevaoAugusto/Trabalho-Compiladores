
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C
   
      Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.
   
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
#define YYBISON_VERSION "2.4.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Copy the first part of user declarations.  */

/* Line 189 of yacc.c  */
#line 5 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tabelaSimbolos.h"

    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();

    extern int line_number;
    extern int column_number;

    extern int lexical_errors;
    int syntax_errors = 0;
    int semantic_errors = 0;


    void yyerror(const char *s);
    void erro_sintatico_previsto(const char *msg);
    DataType last_type_declared = TYPE_INVALID;  



/* Line 189 of yacc.c  */
#line 98 "parser.tab.c"

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

/* "%code requires" blocks.  */

/* Line 209 of yacc.c  */
#line 1 "parser.y"

    #include "tabelaSimbolos.h"



/* Line 209 of yacc.c  */
#line 128 "parser.tab.c"

/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     IF = 258,
     ELSE = 259,
     WHILE = 260,
     RETURN = 261,
     INT = 262,
     FLOAT = 263,
     CHAR = 264,
     VOID = 265,
     STRUCT = 266,
     PLUS = 267,
     MINUS = 268,
     DIVISION = 269,
     MULTIPLY = 270,
     EQUAL_OP = 271,
     NOT_EQUAL_OP = 272,
     LESS_EQUAL_OP = 273,
     RIGHT_EQUAL_OP = 274,
     LEFT_OP = 275,
     RIGHT_OP = 276,
     ASSIGN_OP = 277,
     LEFT_BRACE = 278,
     RIGHT_BRACE = 279,
     LEFT_BRACKET = 280,
     RIGHT_BRACKET = 281,
     LEFT_PAREN = 282,
     RIGHT_PAREN = 283,
     SEMICOLON = 284,
     COMMA = 285,
     CONSTINT = 286,
     CONSTFLOAT = 287,
     CONSTCHAR = 288,
     CONSTSTRING = 289,
     IDENTIFIER = 290,
     LOWER_THAN_ELSE = 291
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
{

/* Line 214 of yacc.c  */
#line 30 "parser.y"

    int intval;
    float floatval;
    char charval;
    char* id;
    char* sval;
    DataType type;
    Symbol* symbol;
    Dimension* dim;
    Param* param;
    HashTable* members;
    Node* node;



/* Line 214 of yacc.c  */
#line 197 "parser.tab.c"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif


/* Copy the second part of user declarations.  */


/* Line 264 of yacc.c  */
#line 209 "parser.tab.c"

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
# if YYENABLE_NLS
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
YYID (int yyi)
#else
static int
YYID (yyi)
    int yyi;
#endif
{
  return yyi;
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
# define YYSTACK_RELOCATE(Stack_alloc, Stack)				\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack_alloc, Stack, yysize);			\
	Stack = &yyptr->Stack_alloc;					\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  14
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   258

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  37
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  33
/* YYNRULES -- Number of rules.  */
#define YYNRULES  96
/* YYNRULES -- Number of states.  */
#define YYNSTATES  168

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   291

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
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
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     5,     7,    10,    14,    16,    18,    22,
      27,    33,    38,    42,    47,    51,    55,    60,    62,    64,
      66,    68,    74,    80,    82,    85,    92,    99,   106,   107,
     108,   110,   112,   114,   118,   121,   126,   131,   138,   141,
     142,   145,   146,   148,   150,   152,   154,   156,   159,   162,
     164,   170,   178,   184,   190,   196,   199,   203,   207,   211,
     215,   217,   221,   223,   225,   227,   229,   231,   233,   235,
     237,   241,   245,   247,   251,   255,   260,   265,   269,   271,
     273,   275,   277,   279,   281,   285,   290,   295,   297,   298,
     300,   304,   309,   313,   315,   321,   326
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int8 yyrhs[] =
{
      38,     0,    -1,    39,    -1,    40,    -1,    39,    40,    -1,
      39,     1,    29,    -1,    45,    -1,    41,    -1,    43,    35,
      29,    -1,    43,    35,    42,    29,    -1,    43,    35,    22,
       1,    29,    -1,    43,    35,     1,    29,    -1,    43,     1,
      29,    -1,    25,    31,    26,    42,    -1,    25,    31,    26,
      -1,    25,     1,    26,    -1,    25,     1,    26,    42,    -1,
       7,    -1,     8,    -1,     9,    -1,    10,    -1,    11,    35,
      23,    44,    24,    -1,    11,     1,    23,    44,    24,    -1,
      41,    -1,    41,    44,    -1,    43,    35,    27,    48,    28,
      51,    -1,    43,     1,    27,    48,    28,    51,    -1,    43,
      35,    27,     1,    28,    51,    -1,    -1,    -1,    49,    -1,
      10,    -1,    50,    -1,    50,    30,    49,    -1,    43,    35,
      -1,    43,    35,    25,    26,    -1,    43,    35,     1,    26,
      -1,    23,    46,    52,    53,    24,    47,    -1,    52,    41,
      -1,    -1,    53,    54,    -1,    -1,    55,    -1,    51,    -1,
      56,    -1,    57,    -1,    58,    -1,     1,    29,    -1,    59,
      29,    -1,    29,    -1,     3,    27,    59,    28,    54,    -1,
       3,    27,    59,    28,    54,     4,    54,    -1,     3,    27,
       1,    28,    54,    -1,     5,    27,    59,    28,    54,    -1,
       5,    27,     1,    28,    54,    -1,     6,    29,    -1,     6,
      59,    29,    -1,     6,     1,    29,    -1,    68,    22,    59,
      -1,    68,    22,     1,    -1,    60,    -1,    62,    61,    62,
      -1,    62,    -1,    20,    -1,    21,    -1,    18,    -1,    19,
      -1,    16,    -1,    17,    -1,    63,    -1,    62,    12,    63,
      -1,    62,    13,    63,    -1,    64,    -1,    63,    15,    64,
      -1,    63,    14,    64,    -1,    63,    15,    64,     1,    -1,
      63,    14,    64,     1,    -1,    27,    59,    28,    -1,    68,
      -1,    65,    -1,    32,    -1,    31,    -1,    33,    -1,    34,
      -1,    27,     1,    28,    -1,    35,    27,    66,    28,    -1,
      35,    27,     1,    28,    -1,    67,    -1,    -1,    59,    -1,
      67,    30,    59,    -1,    67,    30,    30,     1,    -1,    67,
      30,     1,    -1,    35,    -1,    35,    25,    59,    26,    69,
      -1,    69,    25,    59,    26,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,    85,    85,    90,    91,    92,    98,    99,   104,   134,
     160,   162,   164,   169,   179,   189,   191,   197,   202,   207,
     212,   217,   223,   229,   241,   257,   270,   277,   287,   291,
     296,   298,   304,   306,   312,   323,   334,   340,   345,   346,
     351,   352,   357,   358,   359,   360,   361,   362,   368,   374,
     378,   394,   414,   420,   439,   445,   452,   462,   468,   509,
     518,   523,   546,   551,   552,   553,   554,   555,   556,   561,
     562,   579,   599,   600,   617,   633,   638,   647,   651,   656,
     661,   669,   677,   685,   693,   703,   731,   737,   740,   745,
     753,   761,   763,   769,   791,   892,   912
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "IF", "ELSE", "WHILE", "RETURN", "INT",
  "FLOAT", "CHAR", "VOID", "STRUCT", "PLUS", "MINUS", "DIVISION",
  "MULTIPLY", "EQUAL_OP", "NOT_EQUAL_OP", "LESS_EQUAL_OP",
  "RIGHT_EQUAL_OP", "LEFT_OP", "RIGHT_OP", "ASSIGN_OP", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PAREN",
  "RIGHT_PAREN", "SEMICOLON", "COMMA", "CONSTINT", "CONSTFLOAT",
  "CONSTCHAR", "CONSTSTRING", "IDENTIFIER", "LOWER_THAN_ELSE", "$accept",
  "programa", "declaracao_lista", "declaracao", "var_declaracao",
  "arrayDimensao", "tipo_especificador", "varDeclList", "func_declaracao",
  "abre_escopo_funcao", "fecha_escopo_funcao", "params", "params_lista",
  "param", "composto_decl", "local_declaracoes", "comando_lista",
  "comando", "expressao_decl", "selecao_decl", "iteracao_decl",
  "retorno_decl", "expressao", "expressao_simples", "relacional",
  "exp_soma", "termo", "fator", "ativacao", "args", "arg_lista", "var",
  "var_auxiliar", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    40,    40,    41,    41,
      41,    41,    41,    42,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    44,    44,    45,    45,    45,    46,    47,
      48,    48,    49,    49,    50,    50,    50,    51,    52,    52,
      53,    53,    54,    54,    54,    54,    54,    54,    55,    55,
      56,    56,    56,    57,    57,    58,    58,    58,    59,    59,
      59,    60,    60,    61,    61,    61,    61,    61,    61,    62,
      62,    62,    63,    63,    63,    63,    63,    64,    64,    64,
      64,    64,    64,    64,    64,    65,    65,    66,    66,    67,
      67,    67,    67,    68,    68,    69,    69
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     1,     1,     3,     4,
       5,     4,     3,     4,     3,     3,     4,     1,     1,     1,
       1,     5,     5,     1,     2,     6,     6,     6,     0,     0,
       1,     1,     1,     3,     2,     4,     4,     6,     2,     0,
       2,     0,     1,     1,     1,     1,     1,     2,     2,     1,
       5,     7,     5,     5,     5,     2,     3,     3,     3,     3,
       1,     3,     1,     1,     1,     1,     1,     1,     1,     1,
       3,     3,     1,     3,     3,     4,     4,     3,     1,     1,
       1,     1,     1,     1,     3,     4,     4,     1,     0,     1,
       3,     4,     3,     1,     5,     4,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint8 yydefact[] =
{
       0,    17,    18,    19,    20,     0,     0,     0,     3,     7,
       0,     6,     0,     0,     1,     0,     4,     0,     0,     0,
       0,     5,     0,    12,     0,     0,     0,     0,     8,     0,
      23,     0,     0,     0,    20,     0,     0,    30,    32,    11,
       0,     0,     0,     0,     0,     9,    24,     0,     0,    22,
      21,     0,     0,     0,    10,    15,    14,     0,     0,     0,
       0,    28,    26,    33,    16,    13,    27,    25,    36,    35,
      39,    41,    38,     0,     0,     0,     0,     0,    29,     0,
      49,    81,    80,    82,    83,    93,    43,    40,    42,    44,
      45,    46,     0,    60,    62,    69,    72,    79,    78,    47,
       0,     0,     0,    55,     0,    37,     0,     0,     0,     0,
      48,     0,     0,    67,    68,    65,    66,    63,    64,     0,
       0,     0,     0,     0,     0,     0,     0,    57,    56,    84,
      77,     0,     0,    89,     0,    87,    70,    78,    71,    61,
       0,     0,    59,    58,     0,     0,     0,     0,    96,    86,
      85,     0,    76,    75,    52,    50,    54,    53,    94,    92,
       0,    90,     0,     0,    91,    51,     0,    95
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    30,    29,    31,    32,    11,    70,
     105,    36,    37,    38,    86,    71,    73,    87,    88,    89,
      90,    91,    92,    93,   119,    94,    95,    96,    97,   134,
     135,    98,   158
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -134
static const yytype_int16 yypact[] =
{
     229,  -134,  -134,  -134,  -134,     5,    19,   199,  -134,  -134,
       6,  -134,   -19,    -8,  -134,    -7,  -134,    25,   168,   229,
     229,  -134,   234,  -134,     7,    50,     4,   204,  -134,    26,
     229,     8,     2,    40,    45,    41,    53,  -134,    48,  -134,
      66,    76,    85,    91,   121,  -134,  -134,    84,   169,  -134,
    -134,    52,    98,   229,  -134,   140,   140,    98,    98,   137,
     160,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,  -134,
    -134,   229,  -134,    15,   163,   174,   175,    36,  -134,    83,
    -134,  -134,  -134,  -134,  -134,    33,  -134,  -134,  -134,  -134,
    -134,  -134,   167,  -134,   205,   126,  -134,  -134,   181,  -134,
      93,   102,   187,  -134,   190,  -134,   176,   192,   200,    65,
    -134,   200,   200,  -134,  -134,  -134,  -134,  -134,  -134,   200,
     200,   200,   111,   201,   202,   218,   219,  -134,  -134,  -134,
    -134,   222,   221,  -134,   223,   198,   126,  -134,   126,   135,
     138,   159,  -134,  -134,    56,    56,    56,    56,  -134,  -134,
    -134,    74,  -134,  -134,  -134,   246,  -134,  -134,   227,  -134,
     252,  -134,    56,   200,  -134,  -134,   228,  -134
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,   248,     1,   106,     3,    -3,  -134,  -134,
    -134,   230,   203,  -134,   -24,  -134,  -134,  -133,  -134,  -134,
    -134,  -134,   -77,  -134,  -134,   139,    70,    63,  -134,  -134,
    -134,    11,  -134
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -89
static const yytype_int16 yytable[] =
{
     104,     9,   107,    10,    19,    41,    12,    17,     9,    47,
      10,   154,   155,   156,   157,    20,    74,    33,    75,    14,
      76,    77,    21,   124,   126,    35,    49,    46,    62,   165,
      35,   131,   133,    66,    67,    42,    39,   102,    61,    78,
      13,    18,    79,    48,    80,   143,    81,    82,    83,    84,
      85,    40,    22,    59,    23,    45,    35,    74,   108,    75,
     109,    76,    77,    79,    50,   103,   132,    81,    82,    83,
      84,    85,    72,   -31,   161,   159,    51,    60,    53,    61,
     -34,    52,   -34,    79,   106,    80,   166,    81,    82,    83,
      84,    85,    79,   -88,   123,    54,    81,    82,    83,    84,
      85,    79,    55,   125,   160,    81,    82,    83,    84,    85,
      79,    56,   142,    23,    81,    82,    83,    84,    85,    57,
      79,    61,   137,   137,    81,    82,    83,    84,    85,    79,
     137,   137,   137,    81,    82,    83,    84,    85,    79,   152,
     120,   121,    81,    82,    83,    84,    85,   111,   112,    58,
     -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,   -74,
     153,    64,    65,    68,   -74,    26,   -74,   -74,   -74,    24,
      24,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,   -73,
     -73,   136,   138,   140,   141,   -73,    69,   -73,   -73,   -73,
      25,    25,    99,    26,    26,    27,   110,    28,    28,    -2,
      15,   100,   101,   122,   129,    43,     1,     2,     3,     4,
       5,     1,     2,     3,    34,     5,   127,   111,   112,   128,
     130,   113,   114,   115,   116,   117,   118,    79,   151,   144,
     145,    81,    82,    83,    84,    85,     1,     2,     3,     4,
       5,     1,     2,     3,    34,     5,   146,   147,   148,   149,
     162,   150,   163,   164,   167,    16,    63,    44,   139
};

static const yytype_uint8 yycheck[] =
{
      77,     0,    79,     0,    23,     1,     1,     1,     7,     1,
       7,   144,   145,   146,   147,    23,     1,    20,     3,     0,
       5,     6,    29,   100,   101,    22,    24,    30,    52,   162,
      27,   108,   109,    57,    58,    31,    29,     1,    23,    24,
      35,    35,    27,    35,    29,   122,    31,    32,    33,    34,
      35,     1,    27,     1,    29,    29,    53,     1,    25,     3,
      27,     5,     6,    27,    24,    29,     1,    31,    32,    33,
      34,    35,    71,    28,   151,     1,    35,    25,    30,    23,
      28,    28,    30,    27,     1,    29,   163,    31,    32,    33,
      34,    35,    27,    28,     1,    29,    31,    32,    33,    34,
      35,    27,    26,     1,    30,    31,    32,    33,    34,    35,
      27,    26,     1,    29,    31,    32,    33,    34,    35,    28,
      27,    23,   111,   112,    31,    32,    33,    34,    35,    27,
     119,   120,   121,    31,    32,    33,    34,    35,    27,     1,
      14,    15,    31,    32,    33,    34,    35,    12,    13,    28,
      12,    13,    14,    15,    16,    17,    18,    19,    20,    21,
       1,    55,    56,    26,    26,    25,    28,    29,    30,     1,
       1,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,   111,   112,   120,   121,    26,    26,    28,    29,    30,
      22,    22,    29,    25,    25,    27,    29,    29,    29,     0,
       1,    27,    27,    22,    28,     1,     7,     8,     9,    10,
      11,     7,     8,     9,    10,    11,    29,    12,    13,    29,
      28,    16,    17,    18,    19,    20,    21,    27,    30,    28,
      28,    31,    32,    33,    34,    35,     7,     8,     9,    10,
      11,     7,     8,     9,    10,    11,    28,    28,    26,    28,
       4,    28,    25,     1,    26,     7,    53,    27,   119
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    38,    39,    40,    41,
      43,    45,     1,    35,     0,     1,    40,     1,    35,    23,
      23,    29,    27,    29,     1,    22,    25,    27,    29,    42,
      41,    43,    44,    44,    10,    43,    48,    49,    50,    29,
       1,     1,    31,     1,    48,    29,    44,     1,    35,    24,
      24,    35,    28,    30,    29,    26,    26,    28,    28,     1,
      25,    23,    51,    49,    42,    42,    51,    51,    26,    26,
      46,    52,    41,    53,     1,     3,     5,     6,    24,    27,
      29,    31,    32,    33,    34,    35,    51,    54,    55,    56,
      57,    58,    59,    60,    62,    63,    64,    65,    68,    29,
      27,    27,     1,    29,    59,    47,     1,    59,    25,    27,
      29,    12,    13,    16,    17,    18,    19,    20,    21,    61,
      14,    15,    22,     1,    59,     1,    59,    29,    29,    28,
      28,    59,     1,    59,    66,    67,    63,    68,    63,    62,
      64,    64,     1,    59,    28,    28,    28,    28,    26,    28,
      28,    30,     1,     1,    54,    54,    54,    54,    69,     1,
      30,    59,     4,    25,     1,    54,    59,    26
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
# if YYLTYPE_IS_TRIVIAL
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
yy_stack_print (yytype_int16 *yybottom, yytype_int16 *yytop)
#else
static void
yy_stack_print (yybottom, yytop)
    yytype_int16 *yybottom;
    yytype_int16 *yytop;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; yybottom <= yytop; yybottom++)
    {
      int yybot = *yybottom;
      YYFPRINTF (stderr, " %d", yybot);
    }
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
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       );
      YYFPRINTF (stderr, "\n");
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


/* The lookahead symbol.  */
int yychar;

/* The semantic value of the lookahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;



/*-------------------------.
| yyparse or yypush_parse.  |
`-------------------------*/

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
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       `yyss': related to states.
       `yyvs': related to semantic values.

       Refer to the stacks thru separate pointers, to allow yyoverflow
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
  int yytoken;
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

  yytoken = 0;
  yyss = yyssa;
  yyvs = yyvsa;
  yystacksize = YYINITDEPTH;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY; /* Cause a token to be read.  */

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
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a lookahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid lookahead symbol.  */
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

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the lookahead token.  */
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token.  */
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
        case 5:

/* Line 1455 of yacc.c  */
#line 93 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaracao mal formada e não reconhecida"); yyerrok; ;}
    break;

  case 8:

/* Line 1455 of yacc.c  */
#line 105 "parser.y"
    {
        if((yyvsp[(1) - (3)].symbol) == NULL){
            printf("\nErro Sintático: Declaração de struct possui erro sintático (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if((yyvsp[(1) - (3)].symbol)->type == TYPE_VOID){
            printf("\nErro Semântico: Variavel não pode ser declarada com tipo VOID (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.symbol) = NULL;
        } else if((yyvsp[(1) - (3)].symbol)->kind == KIND_STRUCT_DEF){
            if(!insert_struct_def((yyvsp[(1) - (3)].symbol)->name, (yyvsp[(1) - (3)].symbol)->data.struct_info.members)){
                printf("\nErro Semântico: Struct '%s' já foi declarada (linha %d, coluna %d).\n", (yyvsp[(1) - (3)].symbol)->name, line_number, column_number);
                semantic_errors++;
                (yyval.symbol) = NULL;
            } else if(strcmp((yyvsp[(1) - (3)].symbol)->name, (yyvsp[(2) - (3)].id))  == 0){
                printf("\nErro Semântico: O identificador '%s' é o mesmo da struct declarada (linha %d, coluna %d).\n", (yyvsp[(2) - (3)].id), line_number, column_number);
                semantic_errors++;
                (yyval.symbol) = NULL;
            } else {
                insert_variable((yyvsp[(2) - (3)].id), (yyvsp[(1) - (3)].symbol)->type, (yyvsp[(1) - (3)].symbol)->name);
                (yyval.symbol) = lookup_symbol((yyvsp[(2) - (3)].id));
            }
        } else if (!insert_variable((yyvsp[(2) - (3)].id), (yyvsp[(1) - (3)].symbol)->type, NULL)) {
            printf("\nErro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", (yyvsp[(2) - (3)].id), line_number, column_number);
            semantic_errors++;
            (yyval.symbol) = NULL;
        } else {
            (yyval.symbol) = lookup_symbol((yyvsp[(2) - (3)].id));
        }
    ;}
    break;

  case 9:

/* Line 1455 of yacc.c  */
#line 135 "parser.y"
    {
        if((yyvsp[(1) - (4)].symbol) == NULL){
            printf("\nErro Semântico: Declaração de struct possui erro sintático (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if((yyvsp[(1) - (4)].symbol)->type == TYPE_VOID) {
            printf("\nErro Semântico: Variavel não pode ser declarada com tipo VOID (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.symbol) = NULL;
        } else if((yyvsp[(1) - (4)].symbol)->kind == KIND_STRUCT_DEF){
            if(!insert_struct_def((yyvsp[(1) - (4)].symbol)->name, (yyvsp[(1) - (4)].symbol)->data.struct_info.members)){
                printf("\nErro Semântico: Struct '%s' já foi declarada (linha %d, coluna %d).\n", (yyvsp[(1) - (4)].symbol)->name, line_number, column_number);
                semantic_errors++;
                (yyval.symbol) = NULL;
            } else if(strcmp((yyvsp[(1) - (4)].symbol)->name, (yyvsp[(2) - (4)].id)) == 0){
                printf("\nErro Semântico: O identificador '%s' é o mesmo da struct declarada (linha %d, coluna %d).\n", (yyvsp[(2) - (4)].id), line_number, column_number);
                semantic_errors++;
                (yyval.symbol) = NULL;
            } else {
                insert_array((yyvsp[(2) - (4)].id), (yyvsp[(1) - (4)].symbol)->type, (yyvsp[(1) - (4)].symbol)->name, (yyvsp[(3) - (4)].dim));
            }
        } else if (!insert_array((yyvsp[(2) - (4)].id), (yyvsp[(1) - (4)].symbol)->type, NULL, (yyvsp[(3) - (4)].dim))) {
            printf("\nErro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", (yyvsp[(2) - (4)].id), line_number, column_number);
            semantic_errors++;
        }
    ;}
    break;

  case 10:

/* Line 1455 of yacc.c  */
#line 161 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Inicialização de variável não suportada nesta linguagem"); (yyval.symbol) = NULL; yyerrok; ;}
    break;

  case 11:

/* Line 1455 of yacc.c  */
#line 163 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); (yyval.symbol) = NULL; yyerrok; ;}
    break;

  case 12:

/* Line 1455 of yacc.c  */
#line 165 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); (yyval.symbol) = NULL; yyerrok;  ;}
    break;

  case 13:

/* Line 1455 of yacc.c  */
#line 170 "parser.y"
    {
        if((yyvsp[(2) - (4)].intval) > 0){
            (yyval.dim) = new_dimension((yyvsp[(2) - (4)].intval), (yyvsp[(4) - (4)].dim));
        } else {
            printf("\nErro Semântico: Vetor com tamanho 0 é invalido (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.dim) = NULL;
        }
    ;}
    break;

  case 14:

/* Line 1455 of yacc.c  */
#line 180 "parser.y"
    {
        if((yyvsp[(2) - (3)].intval) > 0){
            (yyval.dim) = new_dimension((yyvsp[(2) - (3)].intval), NULL);
        } else {
            printf("\nErro Semântico: Vetor com tamanho 0 é invalido (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.dim) = NULL;
        }
    ;}
    break;

  case 15:

/* Line 1455 of yacc.c  */
#line 190 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); (yyval.dim) = NULL; yyerrok; ;}
    break;

  case 16:

/* Line 1455 of yacc.c  */
#line 192 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); (yyval.dim) = NULL; yyerrok; ;}
    break;

  case 17:

/* Line 1455 of yacc.c  */
#line 198 "parser.y"
    {   
        last_type_declared = TYPE_INT;
        (yyval.symbol) = cria_symbol_temporario(TYPE_INT, KIND_VARIABLE);
    ;}
    break;

  case 18:

/* Line 1455 of yacc.c  */
#line 203 "parser.y"
    {   
        last_type_declared = TYPE_FLOAT;
        (yyval.symbol) = cria_symbol_temporario(TYPE_FLOAT, KIND_VARIABLE);
    ;}
    break;

  case 19:

/* Line 1455 of yacc.c  */
#line 208 "parser.y"
    {   
        last_type_declared = TYPE_CHAR;
        (yyval.symbol) = cria_symbol_temporario(TYPE_CHAR, KIND_VARIABLE);
    ;}
    break;

  case 20:

/* Line 1455 of yacc.c  */
#line 213 "parser.y"
    {   
        last_type_declared = TYPE_VOID;
        (yyval.symbol) = cria_symbol_temporario(TYPE_VOID, KIND_VARIABLE);
    ;}
    break;

  case 21:

/* Line 1455 of yacc.c  */
#line 218 "parser.y"
    {   
        (yyval.symbol) = cria_symbol_temporario(TYPE_STRUCT, KIND_STRUCT_DEF);
        (yyval.symbol)->name = strdup((yyvsp[(2) - (5)].id));
        (yyval.symbol)->data.struct_info.members = (yyvsp[(4) - (5)].members);
    ;}
    break;

  case 22:

/* Line 1455 of yacc.c  */
#line 224 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Nome de struct ausente"); (yyval.symbol) = NULL;  yyerrok; ;}
    break;

  case 23:

/* Line 1455 of yacc.c  */
#line 230 "parser.y"
    {
        HashTable* members = create_hash_table();
        if(((yyvsp[(1) - (1)].symbol) != NULL) && !insert_struct_members((yyvsp[(1) - (1)].symbol), members)){
            printf("\nErro Semântico: O identificador '%s' já existe dentro da struct (linha %d, coluna %d).\n", (yyvsp[(1) - (1)].symbol)->name, line_number, column_number);
            semantic_errors++;
            free(members);
            (yyval.members) = NULL;
        } else {
            (yyval.members) = members;
        }
    ;}
    break;

  case 24:

/* Line 1455 of yacc.c  */
#line 242 "parser.y"
    {
        HashTable* members = (yyvsp[(2) - (2)].members);
        if(((yyvsp[(1) - (2)].symbol) != NULL) && !insert_struct_members((yyvsp[(1) - (2)].symbol), members)){
            printf("\nErro Semântico: O identificador '%s' já existe dentro da struct (linha %d, coluna %d).\n", (yyvsp[(1) - (2)].symbol)->name, line_number, column_number);
            semantic_errors++;
            free(members);
            (yyval.members) = NULL;
        } else {
            (yyval.members) = members;
        }
    ;}
    break;

  case 25:

/* Line 1455 of yacc.c  */
#line 258 "parser.y"
    {
        if((yyvsp[(1) - (6)].symbol) == NULL || (yyvsp[(1) - (6)].symbol)->kind == KIND_STRUCT_DEF){
            printf("\nErro Semântico: Struct nao é aceito como tipo de retorno (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else {
            if(!insert_function((yyvsp[(2) - (6)].id), (yyvsp[(1) - (6)].symbol)->type, NULL, (yyvsp[(4) - (6)].param))){
                printf("\nErro Semântico: Função '%s' já declarada (linha %d, coluna %d).\n", (yyvsp[(2) - (6)].id), line_number, column_number);
                semantic_errors++;
                last_type_declared = TYPE_INVALID;
            }
        } 
    ;}
    break;

  case 26:

/* Line 1455 of yacc.c  */
#line 271 "parser.y"
    { 
        erro_sintatico_previsto("Erro Sintático: Função inexistente ou invalida apos o tipo de retorno"); 
        last_type_declared = TYPE_INVALID; 
        (yyval.symbol) = NULL; 
        yyerrok; 
    ;}
    break;

  case 27:

/* Line 1455 of yacc.c  */
#line 278 "parser.y"
    { 
        erro_sintatico_previsto("Erro Sintático: Lista de parâmetros malformada na declaração de função"); 
        last_type_declared = TYPE_INVALID;
        (yyval.symbol) = NULL; 
        yyerrok; 
    ;}
    break;

  case 28:

/* Line 1455 of yacc.c  */
#line 287 "parser.y"
    { open_scope(last_type_declared); ;}
    break;

  case 29:

/* Line 1455 of yacc.c  */
#line 291 "parser.y"
    { close_scope(); last_type_declared = TYPE_INVALID; ;}
    break;

  case 30:

/* Line 1455 of yacc.c  */
#line 297 "parser.y"
    { (yyval.param) = (yyvsp[(1) - (1)].param); ;}
    break;

  case 31:

/* Line 1455 of yacc.c  */
#line 299 "parser.y"
    { (yyval.param) = NULL; ;}
    break;

  case 32:

/* Line 1455 of yacc.c  */
#line 305 "parser.y"
    { (yyval.param) = (yyvsp[(1) - (1)].param); ;}
    break;

  case 33:

/* Line 1455 of yacc.c  */
#line 307 "parser.y"
    { (yyvsp[(1) - (3)].param)->next = (yyvsp[(3) - (3)].param); (yyval.param) = (yyvsp[(1) - (3)].param); ;}
    break;

  case 34:

/* Line 1455 of yacc.c  */
#line 313 "parser.y"
    {
        if((yyvsp[(1) - (2)].symbol) == NULL || (yyvsp[(1) - (2)].symbol)->kind == KIND_STRUCT_DEF){
            printf("\nErro Semântico: Struct não pode ser utilizado como parametro (linha %d, coluna %d).", line_number, column_number);
            semantic_errors++;
            (yyval.param) = NULL;
        } else {
            (yyval.param) = create_param((yyvsp[(2) - (2)].id), (yyvsp[(1) - (2)].symbol)->type, (yyvsp[(1) - (2)].symbol)->data.var_info.is_array);
            insert_variable((yyvsp[(2) - (2)].id), (yyvsp[(1) - (2)].symbol)->type, NULL);
        }
    ;}
    break;

  case 35:

/* Line 1455 of yacc.c  */
#line 324 "parser.y"
    {
        if((yyvsp[(1) - (4)].symbol) == NULL || (yyvsp[(1) - (4)].symbol)->kind == KIND_STRUCT_DEF){
            printf("\nErro Semântico: Struct não pode ser utilizado como parametro (linha %d, coluna %d).", line_number, column_number);
            semantic_errors++;
            (yyval.param) = NULL;
        } else {
            (yyval.param) = create_param((yyvsp[(2) - (4)].id), (yyvsp[(1) - (4)].symbol)->type, (yyvsp[(1) - (4)].symbol)->data.var_info.is_array);
            insert_array((yyvsp[(2) - (4)].id), (yyvsp[(1) - (4)].symbol)->type, NULL, NULL);
        }
    ;}
    break;

  case 36:

/* Line 1455 of yacc.c  */
#line 335 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Falta de abrir colchetes"); (yyval.param) = NULL; yyerrok; ;}
    break;

  case 47:

/* Line 1455 of yacc.c  */
#line 363 "parser.y"
    { erro_sintatico_previsto("\nErro Sintático: Comando invalido sintaticamente ou incompleto"); yyerrok; ;}
    break;

  case 48:

/* Line 1455 of yacc.c  */
#line 369 "parser.y"
    {
        if ((yyvsp[(1) - (2)].node)) {
            generate_code((yyvsp[(1) - (2)].node));
        }
    ;}
    break;

  case 50:

/* Line 1455 of yacc.c  */
#line 379 "parser.y"
    {
        if ((yyvsp[(3) - (5)].node) && (yyvsp[(3) - (5)].node)->type != TYPE_INT) {
            printf("\nErro Semântico: Expressão condicional do 'if' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
        char* Ltrue = new_label();
        char* Lend = new_label();
        char* cond = generate_code((yyvsp[(3) - (5)].node));

        fprintf(code_output, "if %s goto %s\n", cond, Ltrue);
        fprintf(code_output, "goto %s\n", Lend);
        fprintf(code_output, "%s:\n", Ltrue);
        // código do comando ($5) será gerado automaticamente
        fprintf(code_output, "%s:\n", Lend);
    ;}
    break;

  case 51:

/* Line 1455 of yacc.c  */
#line 395 "parser.y"
    {
        if ((yyvsp[(3) - (7)].node) && (yyvsp[(3) - (7)].node)->type != TYPE_INT) {
            printf("\nErro Semântico: Expressão condicional do 'if' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
        char* Ltrue = new_label();
        char* Lfalse = new_label();
        char* Lend = new_label();
        char* cond = generate_code((yyvsp[(3) - (7)].node));

        fprintf(code_output, "if %s goto %s\n", cond, Ltrue);
        fprintf(code_output, "goto %s\n", Lfalse);
        fprintf(code_output, "%s:\n", Ltrue);
        // código do comando $5
        fprintf(code_output, "goto %s\n", Lend);
        fprintf(code_output, "%s:\n", Lfalse);
        // código do comando $7
        fprintf(code_output, "%s:\n", Lend);
    ;}
    break;

  case 52:

/* Line 1455 of yacc.c  */
#line 415 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Condição errada no comando IF"); yyerrok;;}
    break;

  case 53:

/* Line 1455 of yacc.c  */
#line 421 "parser.y"
    {
        if ((yyvsp[(3) - (5)].node) && (yyvsp[(3) - (5)].node)->type != TYPE_INT) {
            printf("\nErro Semântico: Expressão condicional do 'while' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
        char* Lstart = new_label();
        char* Lcond = new_label();
        char* Lend = new_label();

        fprintf(code_output, "%s:\n", Lcond);
        char* cond = generate_code((yyvsp[(3) - (5)].node));
        fprintf(code_output, "if %s goto %s\n", cond, Lstart);
        fprintf(code_output, "goto %s\n", Lend);
        fprintf(code_output, "%s:\n", Lstart);
        // código do comando $5
        fprintf(code_output, "goto %s\n", Lcond);
        fprintf(code_output, "%s:\n", Lend);
    ;}
    break;

  case 54:

/* Line 1455 of yacc.c  */
#line 440 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Comando WHILE invalido"); yyerrok; ;}
    break;

  case 55:

/* Line 1455 of yacc.c  */
#line 445 "parser.y"
    {
        DataType type = find_current_function_type();
        if (type != TYPE_VOID) {
            printf("\nErro Semântico: Retorno sem valor em função que exige retorno (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
    ;}
    break;

  case 56:

/* Line 1455 of yacc.c  */
#line 452 "parser.y"
    {
        DataType type = find_current_function_type();
        if ((yyvsp[(2) - (3)].node) && (yyvsp[(2) - (3)].node)->type != type) {
            printf("\nErro Semântico: Tipo do valor de retorno incompatível com a função (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if ((yyvsp[(2) - (3)].node)) {
        char* temp = generate_code((yyvsp[(2) - (3)].node));
        fprintf(code_output, "return %s\n", temp);
        }
    ;}
    break;

  case 57:

/* Line 1455 of yacc.c  */
#line 463 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Retorno invalido"); yyerrok;;}
    break;

  case 58:

/* Line 1455 of yacc.c  */
#line 469 "parser.y"
    {
        if ((yyvsp[(1) - (3)].node) && (yyvsp[(3) - (3)].node)) {
            Node* node = create_node();
            node->op = OP_ASSIGN;
            node->type = (yyvsp[(1) - (3)].node)->type;
            node->left = (yyvsp[(1) - (3)].node);
            node->right = (yyvsp[(3) - (3)].node);
            node->place = generate_code(node);
            (yyval.node) = node;

            if((yyvsp[(1) - (3)].node)->symbol->data.var_info.is_from_struct){
                printf("\nErro Semântico: Acesso a membros de struct não suportado pela gramática (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                DataType tipo_var = (yyvsp[(1) - (3)].node)->type;
                DataType tipo_expr = (yyvsp[(3) - (3)].node)->type;

                bool tipos_compativeis = false;

                if (tipo_var == tipo_expr) {
                    tipos_compativeis = true;
                } else if ((tipo_var == TYPE_FLOAT && tipo_expr == TYPE_INT) ||  (tipo_var == TYPE_INT && tipo_expr == TYPE_FLOAT)) {
                    tipos_compativeis = true;
                } else {
                    tipos_compativeis = false;
                }

                if (!tipos_compativeis) {
                    printf("\nErro Semântico: Tipos incompatíveis na atribuição (linha %d, coluna %d).\n", line_number, column_number);
                    semantic_errors++;
                    (yyval.node) = NULL;
                } else {
                    (yyval.node) = (yyvsp[(1) - (3)].node);
                }
            }
        } else {
            (yyval.node) = NULL;
        }
    ;}
    break;

  case 59:

/* Line 1455 of yacc.c  */
#line 510 "parser.y"
    { 
        erro_sintatico_previsto("Erro Sintático: Atribuição sem expressão à direita"); 
        if((yyvsp[(1) - (3)].node) && (yyvsp[(1) - (3)].node)->symbol->data.var_info.is_from_struct){
            printf("\nErro Semântico: Acesso a membros de struct não suportado pela gramática (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
        (yyval.node) = NULL; 
        yyerrok; ;}
    break;

  case 60:

/* Line 1455 of yacc.c  */
#line 518 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 61:

/* Line 1455 of yacc.c  */
#line 523 "parser.y"
    {
        if ((yyvsp[(1) - (3)].node) && (yyvsp[(3) - (3)].node)) {
            if ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type) {
                printf("\nErro Semântico: Tipos incompatíveis na comparação (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                // Cria um novo node para a comparação
                Node* node = create_node();

                node->op = operador_para_enum((yyvsp[(2) - (3)].sval)); // Você precisa implementar essa função

                // O tipo do resultado de comparação normalmente é int ou bool (aqui, por simplicidade, int)
                node->type = TYPE_INT;

                node->left = (yyvsp[(1) - (3)].node);
                node->right = (yyvsp[(3) - (3)].node);

                (yyval.node) = node;
                node->place = generate_code(node);
            }
        } else { (yyval.node) = NULL; }
    ;}
    break;

  case 62:

/* Line 1455 of yacc.c  */
#line 546 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 63:

/* Line 1455 of yacc.c  */
#line 551 "parser.y"
    {   (yyval.sval) = (yyvsp[(1) - (1)].sval);    ;}
    break;

  case 64:

/* Line 1455 of yacc.c  */
#line 552 "parser.y"
    {   (yyval.sval) = (yyvsp[(1) - (1)].sval);    ;}
    break;

  case 65:

/* Line 1455 of yacc.c  */
#line 553 "parser.y"
    {   (yyval.sval) = (yyvsp[(1) - (1)].sval);    ;}
    break;

  case 66:

/* Line 1455 of yacc.c  */
#line 554 "parser.y"
    {   (yyval.sval) = (yyvsp[(1) - (1)].sval);    ;}
    break;

  case 67:

/* Line 1455 of yacc.c  */
#line 555 "parser.y"
    {   (yyval.sval) = (yyvsp[(1) - (1)].sval);    ;}
    break;

  case 68:

/* Line 1455 of yacc.c  */
#line 556 "parser.y"
    {   (yyval.sval) = (yyvsp[(1) - (1)].sval);    ;}
    break;

  case 69:

/* Line 1455 of yacc.c  */
#line 561 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 70:

/* Line 1455 of yacc.c  */
#line 562 "parser.y"
    {
        if ((yyvsp[(1) - (3)].node) && (yyvsp[(3) - (3)].node)) {
            if ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type) {
                printf("\nErro Semântico: tipos incompatíveis na soma (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_PLUS;
                node->type = (yyvsp[(1) - (3)].node)->type;   // ou aplicar promoção de tipo, se quiser
                node->left = (yyvsp[(1) - (3)].node);
                node->right = (yyvsp[(3) - (3)].node);
                node->place = generate_code(node);
                (yyval.node) = node;
            }
        } else { (yyval.node) = NULL; }
    ;}
    break;

  case 71:

/* Line 1455 of yacc.c  */
#line 579 "parser.y"
    {
        if ((yyvsp[(1) - (3)].node) && (yyvsp[(3) - (3)].node)) {
            if ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type) {
                printf("\nErro Semântico: tipos incompatíveis na subtração (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_MINUS;
                node->type = (yyvsp[(1) - (3)].node)->type;
                node->left = (yyvsp[(1) - (3)].node);
                node->right = (yyvsp[(3) - (3)].node);
                (yyval.node) = node;
                node->place = generate_code(node);
            }
        } else { (yyval.node) = NULL; }
    ;}
    break;

  case 72:

/* Line 1455 of yacc.c  */
#line 599 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 73:

/* Line 1455 of yacc.c  */
#line 600 "parser.y"
    {
        if ((yyvsp[(1) - (3)].node) && (yyvsp[(3) - (3)].node)) {
            if ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type) {
                printf("\nErro Semântico: tipos incompatíveis na multiplicação (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_MULTIPLY;
                node->type = (yyvsp[(1) - (3)].node)->type; // ou fazer promoção de tipo se desejar
                node->left = (yyvsp[(1) - (3)].node);
                node->right = (yyvsp[(3) - (3)].node);
                (yyval.node) = node;
                node->place = generate_code(node);
            }
        } else { (yyval.node) = NULL; }
    ;}
    break;

  case 74:

/* Line 1455 of yacc.c  */
#line 617 "parser.y"
    {
        if ((yyvsp[(1) - (3)].node) && (yyvsp[(3) - (3)].node)) {
            if ((yyvsp[(1) - (3)].node)->type != (yyvsp[(3) - (3)].node)->type) {
                printf("\nErro Semântico: tipos incompatíveis na divisão (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_DIVIDE;
                node->type = (yyvsp[(1) - (3)].node)->type;
                node->left = (yyvsp[(1) - (3)].node);
                node->right = (yyvsp[(3) - (3)].node);
                (yyval.node) = node;
            }
        } else { (yyval.node) = NULL; }
    ;}
    break;

  case 75:

/* Line 1455 of yacc.c  */
#line 633 "parser.y"
    {
        erro_sintatico_previsto("Erro Sintático: Operação de '*' sem o fator");
        yyerrok;
        (yyval.node) = NULL;
    ;}
    break;

  case 76:

/* Line 1455 of yacc.c  */
#line 638 "parser.y"
    {
        erro_sintatico_previsto("Erro Sintático: Operação de '/' sem o fator");
        yyerrok;
        (yyval.node) = NULL;
    ;}
    break;

  case 77:

/* Line 1455 of yacc.c  */
#line 648 "parser.y"
    {
        (yyval.node) = (yyvsp[(2) - (3)].node);  // Apenas propaga o Node da expressão
    ;}
    break;

  case 78:

/* Line 1455 of yacc.c  */
#line 652 "parser.y"
    {
        // var retorna Node*, já preenchido com o símbolo e tipo
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 79:

/* Line 1455 of yacc.c  */
#line 657 "parser.y"
    {
        // ativacao retorna Node* com símbolo da função e tipo de retorno
        (yyval.node) = (yyvsp[(1) - (1)].node);
    ;}
    break;

  case 80:

/* Line 1455 of yacc.c  */
#line 662 "parser.y"
    {
        Node *n = create_node();
        n->type = TYPE_FLOAT;
        n->op = OP_NONE;
        n->value.float_val = (yyvsp[(1) - (1)].floatval);
        (yyval.node) = n;
    ;}
    break;

  case 81:

/* Line 1455 of yacc.c  */
#line 670 "parser.y"
    {
        Node *n = create_node();
        n->type = TYPE_INT;
        n->op = OP_NONE;
        n->value.int_val = (yyvsp[(1) - (1)].intval); // ou $1
        (yyval.node) = n;
    ;}
    break;

  case 82:

/* Line 1455 of yacc.c  */
#line 678 "parser.y"
    {
        Node *n = create_node();
        n->type = TYPE_CHAR;
        n->op = OP_NONE;
        n->value.char_val = (yyvsp[(1) - (1)].charval); // ignora aspas simples
        (yyval.node) = n;
    ;}
    break;

  case 83:

/* Line 1455 of yacc.c  */
#line 686 "parser.y"
    {
        Node *n = create_node();
        n->type = TYPE_STRING; // defina esse tipo se ainda não existir
        n->op = OP_NONE;
        n->value.string_val = strdup((yyvsp[(1) - (1)].sval)); // copia a string
        (yyval.node) = n;
    ;}
    break;

  case 84:

/* Line 1455 of yacc.c  */
#line 694 "parser.y"
    {
        erro_sintatico_previsto("Erro Sintático: Expressão vazia entre parênteses");
        yyerrok;
        (yyval.node) = NULL;
    ;}
    break;

  case 85:

/* Line 1455 of yacc.c  */
#line 704 "parser.y"
    {
        Symbol *sym = lookup_symbol((yyvsp[(1) - (4)].id));
        if (!sym) {
            printf("\nErro Semântico: Função '%s' não declarada (linha %d, coluna %d).\n", (yyvsp[(1) - (4)].id), line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if (sym->kind != KIND_FUNCTION) {
            printf("\nErro Semântico: '%s' não é uma função (linha %d, coluna %d).\n", (yyvsp[(1) - (4)].id), line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if (!verifica_argumentos(sym, (yyvsp[(3) - (4)].node))) {
            printf("(linha %d, coluna %d)\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else {
            (yyval.node) = create_node();
            (yyval.node)->type = sym->type;
            (yyval.node)->op = OP_CALL;
            (yyval.node)->left = NULL;
            (yyval.node)->right = (yyvsp[(3) - (4)].node); // lista de argumentos
            (yyval.node)->symbol = sym;

            if (sym->type == TYPE_STRUCT && sym->data.func_info.struct_name) {
                (yyval.node)->struct_name = strdup(sym->data.func_info.struct_name);
            }
        }
    ;}
    break;

  case 86:

/* Line 1455 of yacc.c  */
#line 732 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Argumentos invalidos no retorno da funcao"); (yyval.node) = NULL; yyerrok; ;}
    break;

  case 87:

/* Line 1455 of yacc.c  */
#line 738 "parser.y"
    { (yyval.node) = (yyvsp[(1) - (1)].node); ;}
    break;

  case 88:

/* Line 1455 of yacc.c  */
#line 740 "parser.y"
    { (yyval.node) = NULL; ;}
    break;

  case 89:

/* Line 1455 of yacc.c  */
#line 746 "parser.y"
    {
        if((yyvsp[(1) - (1)].node)->kind == KIND_VARIABLE){
            insert_variable((yyvsp[(1) - (1)].node)->symbol->name, (yyvsp[(1) - (1)].node)->type, NULL);
        }
        (yyval.node) = (yyvsp[(1) - (1)].node);
        (yyvsp[(1) - (1)].node)->next = NULL;
    ;}
    break;

  case 90:

/* Line 1455 of yacc.c  */
#line 754 "parser.y"
    {
        Node *last = (yyvsp[(1) - (3)].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[(3) - (3)].node);
        (yyvsp[(3) - (3)].node)->next = NULL;
        (yyval.node) = (yyvsp[(1) - (3)].node);
    ;}
    break;

  case 91:

/* Line 1455 of yacc.c  */
#line 762 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Falta de parametro"); yyerrok; (yyval.node) = NULL; ;}
    break;

  case 92:

/* Line 1455 of yacc.c  */
#line 764 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Virgula excedente ao final da lista de parametros"); yyerrok; (yyval.node) = NULL; ;}
    break;

  case 93:

/* Line 1455 of yacc.c  */
#line 770 "parser.y"
    {
        Symbol *sym = lookup_symbol((yyvsp[(1) - (1)].id));
        if(!sym){
            printf("\nErro Semântico: Identificador não foi declarado (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if(sym->data.var_info.is_array){
            printf("\nErro Semântico: Problema de Atribuição, uma das variaveis é um arranjo, mas nenhum indice foi colocado (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else {
            Node *n = create_node();
            n->type = sym->type;
            n->symbol = sym;
            n->op = OP_VAR;
            n->is_array = sym->data.var_info.is_array;
            n->dim = sym->data.var_info.dimensions;
            n->struct_name = NULL;
            (yyval.node) = n;
        }
    ;}
    break;

  case 94:

/* Line 1455 of yacc.c  */
#line 792 "parser.y"
    {
        Symbol *sym = lookup_symbol((yyvsp[(1) - (5)].id));
        if (!sym) {
            printf("\nErro Semântico: Identificador não foi declarado (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if (!sym->data.var_info.is_array) {
            printf("\nErro Semântico: Identificador '%s' não é um vetor (linha %d, coluna %d).\n", (yyvsp[(1) - (5)].id), line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if ((yyvsp[(3) - (5)].node) && (yyvsp[(3) - (5)].node)->type != TYPE_INT) {
            printf("\nErro Semântico: Índice de vetor deve ser inteiro (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else {
            // Verificar se todos os índices são inteiros
            Node *temp = (yyvsp[(5) - (5)].node);
            bool all_int = ((yyvsp[(3) - (5)].node) && (yyvsp[(3) - (5)].node)->type == TYPE_INT);
            while (temp && all_int) {
                if (temp->type != TYPE_INT) {
                    all_int = false;
                    break;
                }
                temp = temp->next;
            }

            if (!all_int) {
                printf("\nErro Semântico: Índices de vetor devem ser inteiros (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                // Contar número de índices fornecidos
                int num_indices = 1;
                Node *current = (yyvsp[(5) - (5)].node);
                while (current) {
                    num_indices++;
                    current = current->next;
                }

                // Contar número de dimensões esperadas
                int num_dims = 0;
                Dimension *d = sym->data.var_info.dimensions;
                while (d) {
                    num_dims++;
                    d = d->next;
                }

                if (num_indices > num_dims) {
                    printf("\nErro Semântico: Vetor '%s' possui dimensões demais (fornecido %d, esperado %d) (linha %d, coluna %d).\n",
                        (yyvsp[(1) - (5)].id), num_indices, num_dims, line_number, column_number);
                    semantic_errors++;
                    (yyval.node) = NULL;
                } else {

                    Node *idx_node = (yyvsp[(3) - (5)].node);                     // Primeiro índice
                    Dimension *dim_node = sym->data.var_info.dimensions;  // Lista de dimensões do símbolo
                    int checked_dims = 0;

                    while (idx_node != NULL && dim_node != NULL) {
                    // Verifica se índice é valor inteiro constante
                        int val = idx_node->value.int_val;
                        if (val < 0 || val >= dim_node->size) {
                            printf("\nErro Semântico: Índice [%d] fora dos limites da dimensão %d (tamanho = %d) do vetor '%s' (linha %d, coluna %d).\n",
                            val, checked_dims + 1, dim_node->size, (yyvsp[(1) - (5)].id), line_number, column_number);
                            semantic_errors++;
                            (yyval.node) = NULL;
                            break;
                        }


                    // Avança para próximo índice e próxima dimensão
                    if (checked_dims == 0)
                        idx_node = (yyvsp[(5) - (5)].node);     // var_auxiliar está no $5 (próximos índices)
                    else
                        idx_node = idx_node->next;

                    dim_node = dim_node->next;
                    checked_dims++;
                    }

                    Node *n = create_node();
                    n->type = sym->type;
                    n->symbol = sym;
                    n->op = OP_INDEX;
                    n->left = (yyvsp[(3) - (5)].node);     // primeiro índice
                    n->right = (yyvsp[(5) - (5)].node);    // índices seguintes
                    n->dim = sym->data.var_info.dimensions;

                    // Se ainda restam dimensões após os índices, é um array
                    n->is_array = (num_indices < num_dims);
                    (yyval.node) = n;
                }
            }
        }
    ;}
    break;

  case 95:

/* Line 1455 of yacc.c  */
#line 893 "parser.y"
    {
        if ((yyvsp[(3) - (4)].node) && (yyvsp[(3) - (4)].node)->type != TYPE_INT) {
            printf("\nErro Semântico: Índice de vetor deve ser inteiro (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = (yyvsp[(1) - (4)].node);
        } else {
            if ((yyvsp[(1) - (4)].node) == NULL) {
                // Começando uma nova lista de dimensões
                (yyval.node) = (yyvsp[(3) - (4)].node);
            } else {
                // Encadeia $3 no final da lista $1
                Node *temp = (yyvsp[(1) - (4)].node);
                while (temp->next != NULL) temp = temp->next;
                temp->next = (yyvsp[(3) - (4)].node);
                (yyval.node) = (yyvsp[(1) - (4)].node);
            }
        }
    ;}
    break;

  case 96:

/* Line 1455 of yacc.c  */
#line 912 "parser.y"
    { (yyval.node) = NULL; ;}
    break;



/* Line 1455 of yacc.c  */
#line 2686 "parser.tab.c"
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

#if !defined(yyoverflow) || YYERROR_VERBOSE
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



/* Line 1675 of yacc.c  */
#line 915 "parser.y"



/*------------------------ Funções auxiliares ------------------------*/

void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d, coluna %d: %s\n", line_number, column_number, s);
}

void erro_sintatico_previsto(const char *msg) {
    syntax_errors++;
    fprintf(stderr, "%s na linha %d, coluna %d\n\n", msg, line_number, column_number);
}

int main(int argc, char **argv) {
    code_output = fopen("saida.3ac", "w");
    if (!code_output) {
        perror("Erro ao abrir o arquivo de saída do código intermediário");
        return -3;
    }
    
    if (argc < 2) {
        printf("Provenha o arquivo de entrada para o compilador.\n");
        return -1;
    }

    FILE *compiled_arq = fopen(argv[1], "r");
    if (!compiled_arq) {
        printf("O arquivo não é válido.\n");
        return -2;
    }

    init_scope_stack();
    yyin = compiled_arq;
    int result = yyparse();

    printf("\n==== Resultado da Análise ====\n");
    if (result == 0) {
        printf("ANALISE CONCLUIDA COM SUCESSO!\n");
    } else {
        printf("ANALISE FALHOU DEVIDO A ERROS!\n");
    }

    printf("Total de erros léxicos: %d\n", lexical_errors);
    printf("Total de erros sintáticos: %d\n", syntax_errors);
    printf("Total de erros semânticos: %d\n", semantic_errors);

    printf("\n Código de 3 Endereços Gravado em saida.3ac \n");

    fclose(compiled_arq);
    fclose(code_output);
    // destroy_scope_stack();
    return 0;
}
