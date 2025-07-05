/* A Bison parser, made by GNU Bison 3.5.1.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2020 Free Software Foundation,
   Inc.

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

/* Undocumented macros, especially those whose name start with YY_,
   are private implementation details.  Do not rely on them.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "3.5.1"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
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
    DataType current_function_type = TYPE_INVALID; 


#line 94 "parser.tab.c"

# ifndef YY_CAST
#  ifdef __cplusplus
#   define YY_CAST(Type, Val) static_cast<Type> (Val)
#   define YY_REINTERPRET_CAST(Type, Val) reinterpret_cast<Type> (Val)
#  else
#   define YY_CAST(Type, Val) ((Type) (Val))
#   define YY_REINTERPRET_CAST(Type, Val) ((Type) (Val))
#  endif
# endif
# ifndef YY_NULLPTR
#  if defined __cplusplus
#   if 201103L <= __cplusplus
#    define YY_NULLPTR nullptr
#   else
#    define YY_NULLPTR 0
#   endif
#  else
#   define YY_NULLPTR ((void*)0)
#  endif
# endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Use api.header.include to #include this header
   instead of duplicating it here.  */
#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif
/* "%code requires" blocks.  */
#line 1 "parser.y"

    #include "tabelaSimbolos.h"

#line 141 "parser.tab.c"

/* Token type.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
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

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
union YYSTYPE
{
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

#line 203 "parser.tab.c"

};
typedef union YYSTYPE YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;

int yyparse (void);

#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */



#ifdef short
# undef short
#endif

/* On compilers that do not define __PTRDIFF_MAX__ etc., make sure
   <limits.h> and (if available) <stdint.h> are included
   so that the code can choose integer types of a good width.  */

#ifndef __PTRDIFF_MAX__
# include <limits.h> /* INFRINGES ON USER NAME SPACE */
# if defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stdint.h> /* INFRINGES ON USER NAME SPACE */
#  define YY_STDINT_H
# endif
#endif

/* Narrow types that promote to a signed type and that can represent a
   signed or unsigned integer of at least N bits.  In tables they can
   save space and decrease cache pressure.  Promoting to a signed type
   helps avoid bugs in integer arithmetic.  */

#ifdef __INT_LEAST8_MAX__
typedef __INT_LEAST8_TYPE__ yytype_int8;
#elif defined YY_STDINT_H
typedef int_least8_t yytype_int8;
#else
typedef signed char yytype_int8;
#endif

#ifdef __INT_LEAST16_MAX__
typedef __INT_LEAST16_TYPE__ yytype_int16;
#elif defined YY_STDINT_H
typedef int_least16_t yytype_int16;
#else
typedef short yytype_int16;
#endif

#if defined __UINT_LEAST8_MAX__ && __UINT_LEAST8_MAX__ <= __INT_MAX__
typedef __UINT_LEAST8_TYPE__ yytype_uint8;
#elif (!defined __UINT_LEAST8_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST8_MAX <= INT_MAX)
typedef uint_least8_t yytype_uint8;
#elif !defined __UINT_LEAST8_MAX__ && UCHAR_MAX <= INT_MAX
typedef unsigned char yytype_uint8;
#else
typedef short yytype_uint8;
#endif

#if defined __UINT_LEAST16_MAX__ && __UINT_LEAST16_MAX__ <= __INT_MAX__
typedef __UINT_LEAST16_TYPE__ yytype_uint16;
#elif (!defined __UINT_LEAST16_MAX__ && defined YY_STDINT_H \
       && UINT_LEAST16_MAX <= INT_MAX)
typedef uint_least16_t yytype_uint16;
#elif !defined __UINT_LEAST16_MAX__ && USHRT_MAX <= INT_MAX
typedef unsigned short yytype_uint16;
#else
typedef int yytype_uint16;
#endif

#ifndef YYPTRDIFF_T
# if defined __PTRDIFF_TYPE__ && defined __PTRDIFF_MAX__
#  define YYPTRDIFF_T __PTRDIFF_TYPE__
#  define YYPTRDIFF_MAXIMUM __PTRDIFF_MAX__
# elif defined PTRDIFF_MAX
#  ifndef ptrdiff_t
#   include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  endif
#  define YYPTRDIFF_T ptrdiff_t
#  define YYPTRDIFF_MAXIMUM PTRDIFF_MAX
# else
#  define YYPTRDIFF_T long
#  define YYPTRDIFF_MAXIMUM LONG_MAX
# endif
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif defined __STDC_VERSION__ && 199901 <= __STDC_VERSION__
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned
# endif
#endif

#define YYSIZE_MAXIMUM                                  \
  YY_CAST (YYPTRDIFF_T,                                 \
           (YYPTRDIFF_MAXIMUM < YY_CAST (YYSIZE_T, -1)  \
            ? YYPTRDIFF_MAXIMUM                         \
            : YY_CAST (YYSIZE_T, -1)))

#define YYSIZEOF(X) YY_CAST (YYPTRDIFF_T, sizeof (X))

/* Stored state numbers (used for stacks). */
typedef yytype_uint8 yy_state_t;

/* State numbers in computations.  */
typedef int yy_state_fast_t;

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

#ifndef YY_ATTRIBUTE_PURE
# if defined __GNUC__ && 2 < __GNUC__ + (96 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_PURE __attribute__ ((__pure__))
# else
#  define YY_ATTRIBUTE_PURE
# endif
#endif

#ifndef YY_ATTRIBUTE_UNUSED
# if defined __GNUC__ && 2 < __GNUC__ + (7 <= __GNUC_MINOR__)
#  define YY_ATTRIBUTE_UNUSED __attribute__ ((__unused__))
# else
#  define YY_ATTRIBUTE_UNUSED
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(E) ((void) (E))
#else
# define YYUSE(E) /* empty */
#endif

#if defined __GNUC__ && ! defined __ICC && 407 <= __GNUC__ * 100 + __GNUC_MINOR__
/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
# define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                            \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# define YY_IGNORE_MAYBE_UNINITIALIZED_END      \
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

#if defined __cplusplus && defined __GNUC__ && ! defined __ICC && 6 <= __GNUC__
# define YY_IGNORE_USELESS_CAST_BEGIN                          \
    _Pragma ("GCC diagnostic push")                            \
    _Pragma ("GCC diagnostic ignored \"-Wuseless-cast\"")
# define YY_IGNORE_USELESS_CAST_END            \
    _Pragma ("GCC diagnostic pop")
#endif
#ifndef YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_BEGIN
# define YY_IGNORE_USELESS_CAST_END
#endif


#define YY_ASSERT(E) ((void) (0 && (E)))

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
  yy_state_t yyss_alloc;
  YYSTYPE yyvs_alloc;
};

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (YYSIZEOF (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (YYSIZEOF (yy_state_t) + YYSIZEOF (YYSTYPE)) \
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
        YYPTRDIFF_T yynewbytes;                                         \
        YYCOPY (&yyptr->Stack_alloc, Stack, yysize);                    \
        Stack = &yyptr->Stack_alloc;                                    \
        yynewbytes = yystacksize * YYSIZEOF (*Stack) + YYSTACK_GAP_MAXIMUM; \
        yyptr += yynewbytes / YYSIZEOF (*yyptr);                        \
      }                                                                 \
    while (0)

#endif

#if defined YYCOPY_NEEDED && YYCOPY_NEEDED
/* Copy COUNT objects from SRC to DST.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(Dst, Src, Count) \
      __builtin_memcpy (Dst, Src, YY_CAST (YYSIZE_T, (Count)) * sizeof (*(Src)))
#  else
#   define YYCOPY(Dst, Src, Count)              \
      do                                        \
        {                                       \
          YYPTRDIFF_T yyi;                      \
          for (yyi = 0; yyi < (Count); yyi++)   \
            (Dst)[yyi] = (Src)[yyi];            \
        }                                       \
      while (0)
#  endif
# endif
#endif /* !YYCOPY_NEEDED */

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
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  168

#define YYUNDEFTOK  2
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[TOKEN-NUM] -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex.  */
static const yytype_int8 yytranslate[] =
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
  /* YYRLINE[YYN] -- Source line where rule number YYN was defined.  */
static const yytype_int16 yyrline[] =
{
       0,    85,    85,    90,    91,    92,    98,    99,   104,   130,
     156,   158,   160,   165,   175,   185,   187,   193,   198,   203,
     208,   213,   219,   225,   237,   253,   266,   273,   283,   287,
     292,   294,   300,   302,   308,   318,   328,   334,   339,   340,
     345,   346,   351,   352,   353,   354,   355,   356,   362,   369,
     373,   380,   387,   393,   400,   406,   413,   420,   426,   443,
     445,   451,   476,   482,   483,   484,   485,   486,   487,   492,
     496,   515,   537,   541,   560,   579,   585,   595,   599,   604,
     609,   617,   625,   633,   641,   653,   681,   687,   690,   695,
     700,   708,   710,   716,   734,   766,   780
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || 0
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
  "var_auxiliar", YY_NULLPTR
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[NUM] -- (External) token number corresponding to the
   (internal) symbol number NUM (which must be that of a token).  */
static const yytype_int16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291
};
# endif

#define YYPACT_NINF (-134)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-89)

#define yytable_value_is_error(Yyn) \
  0

  /* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
     STATE-NUM.  */
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

  /* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
     Performed when YYTABLE does not specify something else to do.  Zero
     means the default is an error.  */
static const yytype_int8 yydefact[] =
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

  /* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -134,  -134,  -134,   248,     1,   106,     3,    -3,  -134,  -134,
    -134,   230,   203,  -134,   -24,  -134,  -134,  -133,  -134,  -134,
    -134,  -134,   -77,  -134,  -134,   139,    70,    63,  -134,  -134,
    -134,    11,  -134
};

  /* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     6,     7,     8,    30,    29,    31,    32,    11,    70,
     105,    36,    37,    38,    86,    71,    73,    87,    88,    89,
      90,    91,    92,    93,   119,    94,    95,    96,    97,   134,
     135,    98,   158
};

  /* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
     positive, shift that token.  If negative, reduce the rule whose
     number is the opposite.  If YYTABLE_NINF, syntax error.  */
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
static const yytype_int8 yystos[] =
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

  /* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_int8 yyr1[] =
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

  /* YYR2[YYN] -- Number of symbols on the right hand side of rule YYN.  */
static const yytype_int8 yyr2[] =
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


#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)
#define YYEMPTY         (-2)
#define YYEOF           0

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab


#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)                                    \
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


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YYUSE (yyoutput);
  if (!yyvaluep)
    return;
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyo, yytoknum[yytype], *yyvaluep);
# endif
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YYUSE (yytype);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo, int yytype, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yytype < YYNTOKENS ? "token" : "nterm", yytname[yytype]);

  yy_symbol_value_print (yyo, yytype, yyvaluep);
  YYFPRINTF (yyo, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

static void
yy_stack_print (yy_state_t *yybottom, yy_state_t *yytop)
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp, int yyrule)
{
  int yylno = yyrline[yyrule];
  int yynrhs = yyr2[yyrule];
  int yyi;
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %d):\n",
             yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      YYFPRINTF (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr,
                       yystos[+yyssp[yyi + 1 - yynrhs]],
                       &yyvsp[(yyi + 1) - (yynrhs)]
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
#   define yystrlen(S) (YY_CAST (YYPTRDIFF_T, strlen (S)))
#  else
/* Return the length of YYSTR.  */
static YYPTRDIFF_T
yystrlen (const char *yystr)
{
  YYPTRDIFF_T yylen;
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
static YYPTRDIFF_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYPTRDIFF_T yyn = 0;
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
            else
              goto append;

          append:
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

  if (yyres)
    return yystpcpy (yyres, yystr) - yyres;
  else
    return yystrlen (yystr);
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
yysyntax_error (YYPTRDIFF_T *yymsg_alloc, char **yymsg,
                yy_state_t *yyssp, int yytoken)
{
  enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
  /* Internationalized format string. */
  const char *yyformat = YY_NULLPTR;
  /* Arguments of yyformat: reported tokens (one for the "unexpected",
     one per "expected"). */
  char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
  /* Actual size of YYARG. */
  int yycount = 0;
  /* Cumulated lengths of YYARG.  */
  YYPTRDIFF_T yysize = 0;

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
      int yyn = yypact[+*yyssp];
      YYPTRDIFF_T yysize0 = yytnamerr (YY_NULLPTR, yytname[yytoken]);
      yysize = yysize0;
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
                  YYPTRDIFF_T yysize1
                    = yysize + yytnamerr (YY_NULLPTR, yytname[yyx]);
                  if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
                    yysize = yysize1;
                  else
                    return 2;
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
    default: /* Avoid compiler warnings. */
      YYCASE_(0, YY_("syntax error"));
      YYCASE_(1, YY_("syntax error, unexpected %s"));
      YYCASE_(2, YY_("syntax error, unexpected %s, expecting %s"));
      YYCASE_(3, YY_("syntax error, unexpected %s, expecting %s or %s"));
      YYCASE_(4, YY_("syntax error, unexpected %s, expecting %s or %s or %s"));
      YYCASE_(5, YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s"));
# undef YYCASE_
    }

  {
    /* Don't count the "%s"s in the final size, but reserve room for
       the terminator.  */
    YYPTRDIFF_T yysize1 = yysize + (yystrlen (yyformat) - 2 * yycount) + 1;
    if (yysize <= yysize1 && yysize1 <= YYSTACK_ALLOC_MAXIMUM)
      yysize = yysize1;
    else
      return 2;
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
          ++yyp;
          ++yyformat;
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
    yy_state_fast_t yystate;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus;

    /* The stacks and their tools:
       'yyss': related to states.
       'yyvs': related to semantic values.

       Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* The state stack.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss;
    yy_state_t *yyssp;

    /* The semantic value stack.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs;
    YYSTYPE *yyvsp;

    YYPTRDIFF_T yystacksize;

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
  YYPTRDIFF_T yymsg_alloc = sizeof yymsgbuf;
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
| yynewstate -- push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;


/*--------------------------------------------------------------------.
| yysetstate -- set current state (the top of the stack) to yystate.  |
`--------------------------------------------------------------------*/
yysetstate:
  YYDPRINTF ((stderr, "Entering state %d\n", yystate));
  YY_ASSERT (0 <= yystate && yystate < YYNSTATES);
  YY_IGNORE_USELESS_CAST_BEGIN
  *yyssp = YY_CAST (yy_state_t, yystate);
  YY_IGNORE_USELESS_CAST_END

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    goto yyexhaustedlab;
#else
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYPTRDIFF_T yysize = yyssp - yyss + 1;

# if defined yyoverflow
      {
        /* Give user a chance to reallocate the stack.  Use copies of
           these so that the &'s don't force the real ones into
           memory.  */
        yy_state_t *yyss1 = yyss;
        YYSTYPE *yyvs1 = yyvs;

        /* Each stack pointer address is followed by the size of the
           data in use in that stack, in bytes.  This used to be a
           conditional around just the two extra args, but that might
           be undefined if yyoverflow is a macro.  */
        yyoverflow (YY_("memory exhausted"),
                    &yyss1, yysize * YYSIZEOF (*yyssp),
                    &yyvs1, yysize * YYSIZEOF (*yyvsp),
                    &yystacksize);
        yyss = yyss1;
        yyvs = yyvs1;
      }
# else /* defined YYSTACK_RELOCATE */
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
        goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          goto yyexhaustedlab;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
# undef YYSTACK_RELOCATE
        if (yyss1 != yyssa)
          YYSTACK_FREE (yyss1);
      }
# endif

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;

      YY_IGNORE_USELESS_CAST_BEGIN
      YYDPRINTF ((stderr, "Stack size increased to %ld\n",
                  YY_CAST (long, yystacksize)));
      YY_IGNORE_USELESS_CAST_END

      if (yyss + yystacksize - 1 <= yyssp)
        YYABORT;
    }
#endif /* !defined yyoverflow && !defined YYSTACK_RELOCATE */

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
  yystate = yyn;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END

  /* Discard the shifted token.  */
  yychar = YYEMPTY;
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
| yyreduce -- do a reduction.  |
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
  case 5:
#line 93 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaracao mal formada e não reconhecida"); yyerrok; }
#line 1516 "parser.tab.c"
    break;

  case 8:
#line 105 "parser.y"
    {
        if((yyvsp[-2].symbol) == NULL){
            printf("Erro Semântico: Declaração de struct possui erro sintático (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if((yyvsp[-2].symbol)->type == TYPE_VOID){
            printf("Erro Semântico: Variavel não pode ser declarada com tipo VOID (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.symbol) = NULL;
        } else if((yyvsp[-2].symbol)->kind == KIND_STRUCT_DEF){
            if(!insert_struct_def((yyvsp[-2].symbol)->name, (yyvsp[-2].symbol)->data.struct_info.members)){
                printf("Erro Semântico: Struct '%s' já foi declarada (linha %d, coluna %d).\n", (yyvsp[-2].symbol)->name, line_number, column_number);
                semantic_errors++;
                (yyval.symbol) = NULL;
            } else if(strcmp((yyvsp[-2].symbol)->name, (yyvsp[-1].id))  == 0){
                printf("Erro Semântico: O identificador '%s' é o mesmo da struct declarada (linha %d, coluna %d).\n", (yyvsp[-1].id), line_number, column_number);
                semantic_errors++;
                (yyval.symbol) = NULL;
            } else {
                insert_variable((yyvsp[-1].id), (yyvsp[-2].symbol)->type, (yyvsp[-2].symbol)->name);
            }
        } else if (!insert_variable((yyvsp[-1].id), (yyvsp[-2].symbol)->type, NULL)) {
            printf("Erro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", (yyvsp[-1].id), line_number, column_number);
            semantic_errors++;
        }
    }
#line 1546 "parser.tab.c"
    break;

  case 9:
#line 131 "parser.y"
    {
        if((yyvsp[-3].symbol) == NULL){
            printf("Erro Semântico: Declaração de struct possui erro sintático (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if((yyvsp[-3].symbol)->type == TYPE_VOID) {
            printf("Erro Semântico: Variavel não pode ser declarada com tipo VOID (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.symbol) = NULL;
        } else if((yyvsp[-3].symbol)->kind == KIND_STRUCT_DEF){
            if(!insert_struct_def((yyvsp[-3].symbol)->name, (yyvsp[-3].symbol)->data.struct_info.members)){
                printf("Erro Semântico: Struct '%s' já foi declarada (linha %d, coluna %d).\n", (yyvsp[-3].symbol)->name, line_number, column_number);
                semantic_errors++;
                (yyval.symbol) = NULL;
            } else if(strcmp((yyvsp[-3].symbol)->name, (yyvsp[-2].id)) == 0){
                printf("Erro Semântico: O identificador '%s' é o mesmo da struct declarada (linha %d, coluna %d).\n", (yyvsp[-2].id), line_number, column_number);
                semantic_errors++;
                (yyval.symbol) = NULL;
            } else {
                insert_array((yyvsp[-2].id), (yyvsp[-3].symbol)->type, (yyvsp[-3].symbol)->name, (yyvsp[-1].dim));
            }
        } else if (!insert_array((yyvsp[-2].id), (yyvsp[-3].symbol)->type, NULL, (yyvsp[-1].dim))) {
            printf("Erro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", (yyvsp[-2].id), line_number, column_number);
            semantic_errors++;
        }
    }
#line 1576 "parser.tab.c"
    break;

  case 10:
#line 157 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Inicialização de variável não suportada nesta linguagem"); (yyval.symbol) = NULL; yyerrok; }
#line 1582 "parser.tab.c"
    break;

  case 11:
#line 159 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); (yyval.symbol) = NULL; yyerrok; }
#line 1588 "parser.tab.c"
    break;

  case 12:
#line 161 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); (yyval.symbol) = NULL; yyerrok;  }
#line 1594 "parser.tab.c"
    break;

  case 13:
#line 166 "parser.y"
    {
        if((yyvsp[-2].intval) > 0){
            (yyval.dim) = new_dimension((yyvsp[-2].intval), (yyvsp[0].dim));
        } else {
            printf("Erro Semântico: Vetor com tamanho 0 é invalido (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.dim) = NULL;
        }
    }
#line 1608 "parser.tab.c"
    break;

  case 14:
#line 176 "parser.y"
    {
        if((yyvsp[-1].intval) > 0){
            (yyval.dim) = new_dimension((yyvsp[-1].intval), NULL);
        } else {
            printf("Erro Semântico: Vetor com tamanho 0 é invalido (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.dim) = NULL;
        }
    }
#line 1622 "parser.tab.c"
    break;

  case 15:
#line 186 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); (yyval.dim) = NULL; yyerrok; }
#line 1628 "parser.tab.c"
    break;

  case 16:
#line 188 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); (yyval.dim) = NULL; yyerrok; }
#line 1634 "parser.tab.c"
    break;

  case 17:
#line 194 "parser.y"
    {   
        current_function_type = TYPE_INT;
        (yyval.symbol) = cria_symbol_temporario(TYPE_INT, KIND_VARIABLE);
    }
#line 1643 "parser.tab.c"
    break;

  case 18:
#line 199 "parser.y"
    {   
        current_function_type = TYPE_FLOAT;
        (yyval.symbol) = cria_symbol_temporario(TYPE_FLOAT, KIND_VARIABLE);
    }
#line 1652 "parser.tab.c"
    break;

  case 19:
#line 204 "parser.y"
    {   
        current_function_type = TYPE_CHAR;
        (yyval.symbol) = cria_symbol_temporario(TYPE_CHAR, KIND_VARIABLE);
    }
#line 1661 "parser.tab.c"
    break;

  case 20:
#line 209 "parser.y"
    {   
        current_function_type = TYPE_VOID;
        (yyval.symbol) = cria_symbol_temporario(TYPE_VOID, KIND_VARIABLE);
    }
#line 1670 "parser.tab.c"
    break;

  case 21:
#line 214 "parser.y"
    {   
        (yyval.symbol) = cria_symbol_temporario(TYPE_STRUCT, KIND_STRUCT_DEF);
        (yyval.symbol)->name = strdup((yyvsp[-3].id));
        (yyval.symbol)->data.struct_info.members = (yyvsp[-1].members);
    }
#line 1680 "parser.tab.c"
    break;

  case 22:
#line 220 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Nome de struct ausente"); (yyval.symbol) = NULL;  yyerrok; }
#line 1686 "parser.tab.c"
    break;

  case 23:
#line 226 "parser.y"
    {
        HashTable* members = create_hash_table();
        if(((yyvsp[0].symbol) != NULL) && !insert_struct_members((yyvsp[0].symbol), members)){
            printf("Erro Semântico: O identificador '%s' já existe dentro da struct (linha %d, coluna %d).\n", (yyvsp[0].symbol)->name, line_number, column_number);
            semantic_errors++;
            free(members);
            (yyval.members) = NULL;
        } else {
            (yyval.members) = members;
        }
    }
#line 1702 "parser.tab.c"
    break;

  case 24:
#line 238 "parser.y"
    {
        HashTable* members = (yyvsp[0].members);
        if(((yyvsp[-1].symbol) != NULL) && !insert_struct_members((yyvsp[-1].symbol), (yyval.members))){
            printf("Erro Semântico: O identificador '%s' já existe dentro da struct (linha %d, coluna %d).\n", (yyvsp[-1].symbol)->name, line_number, column_number);
            semantic_errors++;
            free(members);
            (yyval.members) = NULL;
        } else {
            (yyval.members) = members;
        }
    }
#line 1718 "parser.tab.c"
    break;

  case 25:
#line 254 "parser.y"
    {
        if((yyvsp[-5].symbol) == NULL || (yyvsp[-5].symbol)->kind == KIND_STRUCT_DEF){
            printf("Erro Semântico: Struct nao é aceito como tipo de retorno (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else {
            if(!insert_function((yyvsp[-4].id), (yyvsp[-5].symbol)->type, NULL, (yyvsp[-2].param))){
                printf("Erro Semântico: Função '%s' já declarada (linha %d, coluna %d).\n", (yyvsp[-4].id), line_number, column_number);
                semantic_errors++;
                current_function_type = TYPE_INVALID;
            }
        } 
    }
#line 1735 "parser.tab.c"
    break;

  case 26:
#line 267 "parser.y"
    { 
        erro_sintatico_previsto("Erro Sintático: Função inexistente ou invalida apos o tipo de retorno"); 
        current_function_type = TYPE_INVALID; 
        (yyval.symbol) = NULL; 
        yyerrok; 
    }
#line 1746 "parser.tab.c"
    break;

  case 27:
#line 274 "parser.y"
    { 
        erro_sintatico_previsto("Erro Sintático: Lista de parâmetros malformada na declaração de função"); 
        current_function_type = TYPE_INVALID;
        (yyval.symbol) = NULL; 
        yyerrok; 
    }
#line 1757 "parser.tab.c"
    break;

  case 28:
#line 283 "parser.y"
            { open_scope(); }
#line 1763 "parser.tab.c"
    break;

  case 29:
#line 287 "parser.y"
            { close_scope(); current_function_type = TYPE_INVALID; }
#line 1769 "parser.tab.c"
    break;

  case 30:
#line 293 "parser.y"
    { (yyval.param) = (yyvsp[0].param); }
#line 1775 "parser.tab.c"
    break;

  case 31:
#line 295 "parser.y"
    { (yyval.param) = NULL; }
#line 1781 "parser.tab.c"
    break;

  case 32:
#line 301 "parser.y"
    { (yyval.param) = (yyvsp[0].param); }
#line 1787 "parser.tab.c"
    break;

  case 33:
#line 303 "parser.y"
    { (yyvsp[-2].param)->next = (yyvsp[0].param); (yyval.param) = (yyvsp[-2].param); }
#line 1793 "parser.tab.c"
    break;

  case 34:
#line 309 "parser.y"
    {
        if((yyvsp[-1].symbol) == NULL || (yyvsp[-1].symbol)->kind == KIND_STRUCT_DEF){
            printf("Erro Semântico: Struct não pode ser utilizado como parametro (linha %d, coluna %d).", line_number, column_number);
            semantic_errors++;
            (yyval.param) = NULL;
        } else {
            (yyval.param) = create_param((yyvsp[0].id), (yyvsp[-1].symbol)->type, (yyvsp[-1].symbol)->data.var_info.is_array);
        }
    }
#line 1807 "parser.tab.c"
    break;

  case 35:
#line 319 "parser.y"
    {
        if((yyvsp[-3].symbol) == NULL || (yyvsp[-3].symbol)->kind == KIND_STRUCT_DEF){
            printf("Erro Semântico: Struct não pode ser utilizado como parametro (linha %d, coluna %d).", line_number, column_number);
            semantic_errors++;
            (yyval.param) = NULL;
        } else {
            (yyval.param) = create_param((yyvsp[-2].id), (yyvsp[-3].symbol)->type, (yyvsp[-3].symbol)->data.var_info.is_array);
        }
    }
#line 1821 "parser.tab.c"
    break;

  case 36:
#line 329 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Falta de abrir colchetes"); (yyval.param) = NULL; yyerrok; }
#line 1827 "parser.tab.c"
    break;

  case 47:
#line 357 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Comando invalido sintaticamente ou incompleto"); yyerrok; }
#line 1833 "parser.tab.c"
    break;

  case 48:
#line 363 "parser.y"
    {
        if (!(yyvsp[-1].node)) {
            printf("Erro Semântico: Expressão inválida na linha %d, coluna %d.\n", line_number, column_number);
            semantic_errors++;
        }
    }
#line 1844 "parser.tab.c"
    break;

  case 50:
#line 374 "parser.y"
    {
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->type != TYPE_INT) {
            printf("Erro Semântico: Expressão condicional do 'if' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
    }
#line 1855 "parser.tab.c"
    break;

  case 51:
#line 381 "parser.y"
    {
        if ((yyvsp[-4].node) && (yyvsp[-4].node)->type != TYPE_INT) {
            printf("Erro Semântico: Expressão condicional do 'if' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
    }
#line 1866 "parser.tab.c"
    break;

  case 52:
#line 388 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Condição errada no comando IF"); yyerrok;}
#line 1872 "parser.tab.c"
    break;

  case 53:
#line 394 "parser.y"
    {
        if ((yyvsp[-2].node) && (yyvsp[-2].node)->type != TYPE_INT) {
            printf("Erro Semântico: Expressão condicional do 'if' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
    }
#line 1883 "parser.tab.c"
    break;

  case 54:
#line 401 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Comando WHILE invalido"); yyerrok; }
#line 1889 "parser.tab.c"
    break;

  case 55:
#line 407 "parser.y"
    {
        if (current_function_type != TYPE_VOID) {
            printf("Erro Semântico: Retorno sem valor em função que exige retorno (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
    }
#line 1900 "parser.tab.c"
    break;

  case 56:
#line 414 "parser.y"
    {
        if ((yyvsp[-1].node) && (yyvsp[-1].node)->type != current_function_type) {
            printf("Erro Semântico: Tipo do valor de retorno incompatível com a função (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
    }
#line 1911 "parser.tab.c"
    break;

  case 57:
#line 421 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Retorno invalido"); yyerrok;}
#line 1917 "parser.tab.c"
    break;

  case 58:
#line 427 "parser.y"
    {
        if ((yyvsp[-2].node) && (yyvsp[0].node)) {
            DataType tipo_var = (yyvsp[-2].node)->type;
            DataType tipo_expr = (yyvsp[0].node)->type;

            if (tipo_var != tipo_expr) {
                printf("Erro Semântico: Tipos incompatíveis na atribuição (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                (yyval.node) = (yyvsp[-2].node);
            }
        } else {
            (yyval.node) = NULL;
        }
    }
#line 1938 "parser.tab.c"
    break;

  case 59:
#line 444 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Atribuição sem expressão à direita"); (yyval.node) = NULL; yyerrok; }
#line 1944 "parser.tab.c"
    break;

  case 60:
#line 446 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1950 "parser.tab.c"
    break;

  case 61:
#line 452 "parser.y"
    {
        if ((yyvsp[-2].node) && (yyvsp[0].node)) {
            if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) {
                printf("Erro Semântico: Tipos incompatíveis na comparação (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                // Cria um novo node para a comparação
                Node* node = create_node();

                node->op = operador_para_enum((yyvsp[-1].sval)); // Você precisa implementar essa função

                // O tipo do resultado de comparação normalmente é int ou bool (aqui, por simplicidade, int)
                node->type = TYPE_INT;

                node->left = (yyvsp[-2].node);
                node->right = (yyvsp[0].node);

                (yyval.node) = node;
            }
        } else {
            (yyval.node) = NULL;
        }
    }
#line 1979 "parser.tab.c"
    break;

  case 62:
#line 477 "parser.y"
    { (yyval.node) = (yyvsp[0].node); }
#line 1985 "parser.tab.c"
    break;

  case 63:
#line 482 "parser.y"
                        {   (yyval.sval) = (yyvsp[0].sval);    }
#line 1991 "parser.tab.c"
    break;

  case 64:
#line 483 "parser.y"
                        {   (yyval.sval) = (yyvsp[0].sval);    }
#line 1997 "parser.tab.c"
    break;

  case 65:
#line 484 "parser.y"
                        {   (yyval.sval) = (yyvsp[0].sval);    }
#line 2003 "parser.tab.c"
    break;

  case 66:
#line 485 "parser.y"
                        {   (yyval.sval) = (yyvsp[0].sval);    }
#line 2009 "parser.tab.c"
    break;

  case 67:
#line 486 "parser.y"
                        {   (yyval.sval) = (yyvsp[0].sval);    }
#line 2015 "parser.tab.c"
    break;

  case 68:
#line 487 "parser.y"
                        {   (yyval.sval) = (yyvsp[0].sval);    }
#line 2021 "parser.tab.c"
    break;

  case 69:
#line 493 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);  // Apenas passa o node do termo para cima
    }
#line 2029 "parser.tab.c"
    break;

  case 70:
#line 497 "parser.y"
    {
        if ((yyvsp[-2].node) && (yyvsp[0].node)) {
            if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) {
                printf("Erro Semântico: tipos incompatíveis na soma (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_PLUS;
                node->type = (yyvsp[-2].node)->type;   // ou aplicar promoção de tipo, se quiser
                node->left = (yyvsp[-2].node);
                node->right = (yyvsp[0].node);
                (yyval.node) = node;
            }
        } else {
            (yyval.node) = NULL;
        }
    }
#line 2052 "parser.tab.c"
    break;

  case 71:
#line 516 "parser.y"
    {
        if ((yyvsp[-2].node) && (yyvsp[0].node)) {
            if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) {
                printf("Erro Semântico: tipos incompatíveis na subtração (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_MINUS;
                node->type = (yyvsp[-2].node)->type;
                node->left = (yyvsp[-2].node);
                node->right = (yyvsp[0].node);
                (yyval.node) = node;
            }
        } else {
            (yyval.node) = NULL;
        }
    }
#line 2075 "parser.tab.c"
    break;

  case 72:
#line 538 "parser.y"
    {
        (yyval.node) = (yyvsp[0].node);  // Só propaga o node do fator
    }
#line 2083 "parser.tab.c"
    break;

  case 73:
#line 542 "parser.y"
    {
        if ((yyvsp[-2].node) && (yyvsp[0].node)) {
            if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) {
                printf("Erro Semântico: tipos incompatíveis na multiplicação (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_MULTIPLY;
                node->type = (yyvsp[-2].node)->type; // ou fazer promoção de tipo se desejar
                node->left = (yyvsp[-2].node);
                node->right = (yyvsp[0].node);
                (yyval.node) = node;
            }
        } else {
            (yyval.node) = NULL;
        }
    }
#line 2106 "parser.tab.c"
    break;

  case 74:
#line 561 "parser.y"
    {
        if ((yyvsp[-2].node) && (yyvsp[0].node)) {
            if ((yyvsp[-2].node)->type != (yyvsp[0].node)->type) {
                printf("Erro Semântico: tipos incompatíveis na divisão (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                (yyval.node) = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_DIVIDE;
                node->type = (yyvsp[-2].node)->type;
                node->left = (yyvsp[-2].node);
                node->right = (yyvsp[0].node);
                (yyval.node) = node;
            }
        } else {
            (yyval.node) = NULL;
        }
    }
#line 2129 "parser.tab.c"
    break;

  case 75:
#line 580 "parser.y"
    {
        erro_sintatico_previsto("Erro Sintático: Operação de '*' sem o fator");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 2139 "parser.tab.c"
    break;

  case 76:
#line 586 "parser.y"
    {
        erro_sintatico_previsto("Erro Sintático: Operação de '/' sem o fator");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 2149 "parser.tab.c"
    break;

  case 77:
#line 596 "parser.y"
    {
        (yyval.node) = (yyvsp[-1].node);  // Apenas propaga o Node da expressão
    }
#line 2157 "parser.tab.c"
    break;

  case 78:
#line 600 "parser.y"
    {
        // var retorna Node*, já preenchido com o símbolo e tipo
        (yyval.node) = (yyvsp[0].node);
    }
#line 2166 "parser.tab.c"
    break;

  case 79:
#line 605 "parser.y"
    {
        // ativacao retorna Node* com símbolo da função e tipo de retorno
        (yyval.node) = (yyvsp[0].node);
    }
#line 2175 "parser.tab.c"
    break;

  case 80:
#line 610 "parser.y"
    {
        Node *n = create_node();
        n->type = TYPE_FLOAT;
        n->op = OP_NONE;
        n->value.float_val = (yyvsp[0].floatval);
        (yyval.node) = n;
    }
#line 2187 "parser.tab.c"
    break;

  case 81:
#line 618 "parser.y"
    {
        Node *n = create_node();
        n->type = TYPE_INT;
        n->op = OP_NONE;
        n->value.int_val = (yyvsp[0].intval); // ou $1
        (yyval.node) = n;
    }
#line 2199 "parser.tab.c"
    break;

  case 82:
#line 626 "parser.y"
    {
        Node *n = create_node();
        n->type = TYPE_CHAR;
        n->op = OP_NONE;
        n->value.char_val = (yyvsp[0].charval); // ignora aspas simples
        (yyval.node) = n;
    }
#line 2211 "parser.tab.c"
    break;

  case 83:
#line 634 "parser.y"
    {
        Node *n = create_node();
        n->type = TYPE_STRING; // defina esse tipo se ainda não existir
        n->op = OP_NONE;
        n->value.string_val = (yyvsp[0].sval); // copia a string
        (yyval.node) = n;
    }
#line 2223 "parser.tab.c"
    break;

  case 84:
#line 642 "parser.y"
    {
        erro_sintatico_previsto("Erro Sintático: Expressão vazia entre parênteses");
        yyerrok;
        (yyval.node) = NULL;
    }
#line 2233 "parser.tab.c"
    break;

  case 85:
#line 654 "parser.y"
    {
        Symbol *sym = lookup_symbol((yyvsp[-3].id));
        if (!sym) {
            printf("Erro Semântico: Função '%s' não declarada (linha %d, coluna %d).\n", (yyvsp[-3].id), line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if (sym->kind != KIND_FUNCTION) {
            printf("Erro Semântico: '%s' não é uma função (linha %d, coluna %d).\n", (yyvsp[-3].id), line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if (!verifica_argumentos(sym, (yyvsp[-1].node))) {
            printf("(linha %d, coluna %d)\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else {
            (yyval.node) = create_node();
            (yyval.node)->type = sym->type;
            (yyval.node)->op = OP_CALL;
            (yyval.node)->left = NULL;
            (yyval.node)->right = (yyvsp[-1].node); // lista de argumentos
            (yyval.node)->symbol = sym;

            if (sym->type == TYPE_STRUCT && sym->data.func_info.struct_name) {
                (yyval.node)->struct_name = strdup(sym->data.func_info.struct_name);
            }
        }
    }
#line 2265 "parser.tab.c"
    break;

  case 86:
#line 682 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Argumentos invalidos no retorno da funcao"); (yyval.node) = NULL; yyerrok; }
#line 2271 "parser.tab.c"
    break;

  case 87:
#line 688 "parser.y"
      { (yyval.node) = (yyvsp[0].node); }
#line 2277 "parser.tab.c"
    break;

  case 88:
#line 690 "parser.y"
      { (yyval.node) = NULL; }
#line 2283 "parser.tab.c"
    break;

  case 89:
#line 696 "parser.y"
    {
          (yyval.node) = (yyvsp[0].node);
          (yyvsp[0].node)->next = NULL;
    }
#line 2292 "parser.tab.c"
    break;

  case 90:
#line 701 "parser.y"
    {
        Node *last = (yyvsp[-2].node);
        while (last->next) last = last->next;
        last->next = (yyvsp[0].node);
        (yyvsp[0].node)->next = NULL;
        (yyval.node) = (yyvsp[-2].node);
    }
#line 2304 "parser.tab.c"
    break;

  case 91:
#line 709 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Falta de parametro"); yyerrok; (yyval.node) = NULL; }
#line 2310 "parser.tab.c"
    break;

  case 92:
#line 711 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Virgula excedente ao final da lista de parametros"); yyerrok; (yyval.node) = NULL; }
#line 2316 "parser.tab.c"
    break;

  case 93:
#line 717 "parser.y"
    {
        Symbol *sym = lookup_symbol((yyvsp[0].id));
        if(!sym){
            printf("Erro: Identificador '%s' não foi declarado (linha %d, coluna %d).\n", (yyvsp[0].id), line_number, column_number);
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
    }
#line 2338 "parser.tab.c"
    break;

  case 94:
#line 735 "parser.y"
    {
        Symbol *sym = lookup_symbol((yyvsp[-4].id));
        if (!sym) {
            printf("Erro: Identificador '%s' não foi declarado (linha %d, coluna %d).\n", (yyvsp[-4].id), line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if (!sym->data.var_info.is_array) {
            printf("Erro Semântico: Identificador '%s' não é um vetor (linha %d, coluna %d).\n", (yyvsp[-4].id), line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if ((yyvsp[-2].node) && (yyvsp[-2].node)->type != TYPE_INT) {
            printf("Erro Semântico: Índice de vetor deve ser inteiro (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else {
            Node *n = create_node();
            n->type = sym->type;
            n->symbol = sym;
            n->op = OP_INDEX;
            n->left = (yyvsp[-2].node);  // expressão de índice
            n->right = (yyvsp[0].node); // profundidade adicional
            n->is_array = true; // se ainda tiver dimensões restantes
            n->dim = sym->data.var_info.dimensions != NULL ? sym->data.var_info.dimensions->next : NULL;
            (yyval.node) = n;
        }
    }
#line 2369 "parser.tab.c"
    break;

  case 95:
#line 767 "parser.y"
    {
        if ((yyvsp[-3].node) && (yyvsp[-3].node)->type != TYPE_INT) {
            printf("Erro Semântico: Índice de vetor deve ser inteiro (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            (yyval.node) = NULL;
        } else if ((yyvsp[-1].node)) {
            (yyvsp[-3].node)->next = (yyvsp[-1].node);
            (yyval.node) = (yyvsp[-3].node);
        } else {
            (yyval.node) = (yyvsp[-3].node);
        }
    }
#line 2386 "parser.tab.c"
    break;

  case 96:
#line 780 "parser.y"
    {
        (yyval.node) = NULL;
    }
#line 2394 "parser.tab.c"
    break;


#line 2398 "parser.tab.c"

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
  {
    const int yylhs = yyr1[yyn] - YYNTOKENS;
    const int yyi = yypgoto[yylhs] + *yyssp;
    yystate = (0 <= yyi && yyi <= YYLAST && yycheck[yyi] == *yyssp
               ? yytable[yyi]
               : yydefgoto[yylhs]);
  }

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
            yymsg = YY_CAST (char *, YYSTACK_ALLOC (YY_CAST (YYSIZE_T, yymsg_alloc)));
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
  /* Pacify compilers when the user code never invokes YYERROR and the
     label yyerrorlab therefore never appears in user code.  */
  if (0)
    YYERROR;

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


/*-----------------------------------------------------.
| yyreturn -- parsing is finished, return the result.  |
`-----------------------------------------------------*/
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
                  yystos[+*yyssp], yyvsp);
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
#line 785 "parser.y"



/*------------------------ Funções auxiliares ------------------------*/

void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d, coluna %d: %s\n", line_number, column_number, s);
}

void erro_sintatico_previsto(const char *msg) {
    syntax_errors++;
    fprintf(stderr, "%s na linha %d, coluna %d\n\n", msg, line_number, column_number);
}

int main(int argc, char **argv) {
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

    printf("\n=== Resultado da Análise ===\n");
    if (result == 0) {
        printf("ANALISE SINTATICA CONCLUIDA COM SUCESSO!\n");
    } else {
        printf("ANALISE SINTATICA FALHOU DEVIDO A ERROS!\n");
    }

    printf("Total de erros léxicos: %d\n", lexical_errors);
    printf("Total de erros sintáticos: %d\n", syntax_errors);
    printf("Total de erros semânticos: %d\n", semantic_errors);

    fclose(compiled_arq);
    destroy_scope_stack();
    return 0;
}
