/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison implementation for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
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
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output, and Bison version.  */
#define YYBISON 30802

/* Bison version string.  */
#define YYBISON_VERSION "3.8.2"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 0

/* Push parsers.  */
#define YYPUSH 0

/* Pull parsers.  */
#define YYPULL 1




/* First part of user prologue.  */
#line 1 "parser.y"

    #include <stdio.h>
    #include <stdlib.h>

    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();

    extern int line_number;
    extern int column_number;

    extern int lexical_errors;
    int syntax_errors = 0;


    void yyerror(const char *s);
    void erro_sintatico_previsto(const char *msg);

#line 90 "parser.tab.c"

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

#include "parser.tab.h"
/* Symbol kind.  */
enum yysymbol_kind_t
{
  YYSYMBOL_YYEMPTY = -2,
  YYSYMBOL_YYEOF = 0,                      /* "end of file"  */
  YYSYMBOL_YYerror = 1,                    /* error  */
  YYSYMBOL_YYUNDEF = 2,                    /* "invalid token"  */
  YYSYMBOL_IF = 3,                         /* IF  */
  YYSYMBOL_ELSE = 4,                       /* ELSE  */
  YYSYMBOL_WHILE = 5,                      /* WHILE  */
  YYSYMBOL_RETURN = 6,                     /* RETURN  */
  YYSYMBOL_INT = 7,                        /* INT  */
  YYSYMBOL_FLOAT = 8,                      /* FLOAT  */
  YYSYMBOL_CHAR = 9,                       /* CHAR  */
  YYSYMBOL_VOID = 10,                      /* VOID  */
  YYSYMBOL_STRUCT = 11,                    /* STRUCT  */
  YYSYMBOL_PLUS = 12,                      /* PLUS  */
  YYSYMBOL_MINUS = 13,                     /* MINUS  */
  YYSYMBOL_DIVISION = 14,                  /* DIVISION  */
  YYSYMBOL_MULTIPLY = 15,                  /* MULTIPLY  */
  YYSYMBOL_EQUAL_OP = 16,                  /* EQUAL_OP  */
  YYSYMBOL_NOT_EQUAL_OP = 17,              /* NOT_EQUAL_OP  */
  YYSYMBOL_LESS_EQUAL_OP = 18,             /* LESS_EQUAL_OP  */
  YYSYMBOL_RIGHT_EQUAL_OP = 19,            /* RIGHT_EQUAL_OP  */
  YYSYMBOL_LEFT_OP = 20,                   /* LEFT_OP  */
  YYSYMBOL_RIGHT_OP = 21,                  /* RIGHT_OP  */
  YYSYMBOL_ASSIGN_OP = 22,                 /* ASSIGN_OP  */
  YYSYMBOL_LEFT_BRACE = 23,                /* LEFT_BRACE  */
  YYSYMBOL_RIGHT_BRACE = 24,               /* RIGHT_BRACE  */
  YYSYMBOL_LEFT_BRACKET = 25,              /* LEFT_BRACKET  */
  YYSYMBOL_RIGHT_BRACKET = 26,             /* RIGHT_BRACKET  */
  YYSYMBOL_LEFT_PAREN = 27,                /* LEFT_PAREN  */
  YYSYMBOL_RIGHT_PAREN = 28,               /* RIGHT_PAREN  */
  YYSYMBOL_SEMICOLON = 29,                 /* SEMICOLON  */
  YYSYMBOL_COMMA = 30,                     /* COMMA  */
  YYSYMBOL_CONSTINT = 31,                  /* CONSTINT  */
  YYSYMBOL_CONSTFLOAT = 32,                /* CONSTFLOAT  */
  YYSYMBOL_CONSTCHAR = 33,                 /* CONSTCHAR  */
  YYSYMBOL_CONSTSTRING = 34,               /* CONSTSTRING  */
  YYSYMBOL_IDENTIFIER = 35,                /* IDENTIFIER  */
  YYSYMBOL_LOWER_THAN_ELSE = 36,           /* LOWER_THAN_ELSE  */
  YYSYMBOL_YYACCEPT = 37,                  /* $accept  */
  YYSYMBOL_programa = 38,                  /* programa  */
  YYSYMBOL_declaracao_lista = 39,          /* declaracao_lista  */
  YYSYMBOL_declaracao = 40,                /* declaracao  */
  YYSYMBOL_var_declaracao = 41,            /* var_declaracao  */
  YYSYMBOL_arrayDimensao = 42,             /* arrayDimensao  */
  YYSYMBOL_tipo_especificador = 43,        /* tipo_especificador  */
  YYSYMBOL_varDeclList = 44,               /* varDeclList  */
  YYSYMBOL_func_declaracao = 45,           /* func_declaracao  */
  YYSYMBOL_params = 46,                    /* params  */
  YYSYMBOL_params_lista = 47,              /* params_lista  */
  YYSYMBOL_param = 48,                     /* param  */
  YYSYMBOL_composto_decl = 49,             /* composto_decl  */
  YYSYMBOL_local_declaracoes = 50,         /* local_declaracoes  */
  YYSYMBOL_comando_lista = 51,             /* comando_lista  */
  YYSYMBOL_comando = 52,                   /* comando  */
  YYSYMBOL_expressao_decl = 53,            /* expressao_decl  */
  YYSYMBOL_selecao_decl = 54,              /* selecao_decl  */
  YYSYMBOL_iteracao_decl = 55,             /* iteracao_decl  */
  YYSYMBOL_retorno_decl = 56,              /* retorno_decl  */
  YYSYMBOL_expressao = 57,                 /* expressao  */
  YYSYMBOL_expressao_simples = 58,         /* expressao_simples  */
  YYSYMBOL_relacional = 59,                /* relacional  */
  YYSYMBOL_exp_soma = 60,                  /* exp_soma  */
  YYSYMBOL_termo = 61,                     /* termo  */
  YYSYMBOL_fator = 62,                     /* fator  */
  YYSYMBOL_ativacao = 63,                  /* ativacao  */
  YYSYMBOL_args = 64,                      /* args  */
  YYSYMBOL_arg_lista = 65,                 /* arg_lista  */
  YYSYMBOL_var = 66,                       /* var  */
  YYSYMBOL_var_auxiliar = 67               /* var_auxiliar  */
};
typedef enum yysymbol_kind_t yysymbol_kind_t;




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

/* Work around bug in HP-UX 11.23, which defines these macros
   incorrectly for preprocessor constants.  This workaround can likely
   be removed in 2023, as HPE has promised support for HP-UX 11.23
   (aka HP-UX 11i v2) only through the end of 2022; see Table 2 of
   <https://h20195.www2.hpe.com/V2/getpdf.aspx/4AA4-7673ENW.pdf>.  */
#ifdef __hpux
# undef UINT_LEAST8_MAX
# undef UINT_LEAST16_MAX
# define UINT_LEAST8_MAX 255
# define UINT_LEAST16_MAX 65535
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
# define YY_USE(E) ((void) (E))
#else
# define YY_USE(E) /* empty */
#endif

/* Suppress an incorrect diagnostic about yylval being uninitialized.  */
#if defined __GNUC__ && ! defined __ICC && 406 <= __GNUC__ * 100 + __GNUC_MINOR__
# if __GNUC__ * 100 + __GNUC_MINOR__ < 407
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")
# else
#  define YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN                           \
    _Pragma ("GCC diagnostic push")                                     \
    _Pragma ("GCC diagnostic ignored \"-Wuninitialized\"")              \
    _Pragma ("GCC diagnostic ignored \"-Wmaybe-uninitialized\"")
# endif
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

#if !defined yyoverflow

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
#endif /* !defined yyoverflow */

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
#define YYNNTS  31
/* YYNRULES -- Number of rules.  */
#define YYNRULES  94
/* YYNSTATES -- Number of states.  */
#define YYNSTATES  166

/* YYMAXUTOK -- Last valid token kind.  */
#define YYMAXUTOK   291


/* YYTRANSLATE(TOKEN-NUM) -- Symbol number corresponding to TOKEN-NUM
   as returned by yylex, with out-of-bounds checking.  */
#define YYTRANSLATE(YYX)                                \
  (0 <= (YYX) && (YYX) <= YYMAXUTOK                     \
   ? YY_CAST (yysymbol_kind_t, yytranslate[YYX])        \
   : YYSYMBOL_YYUNDEF)

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
       0,    53,    53,    58,    59,    60,    66,    67,    72,    73,
      74,    76,    78,    83,    84,    85,    87,    93,    94,    95,
      96,    97,    98,   104,   105,   110,   111,   113,   119,   120,
     125,   126,   131,   132,   133,   139,   144,   145,   150,   151,
     156,   157,   158,   159,   160,   161,   167,   168,   172,   173,
     174,   180,   181,   187,   188,   189,   195,   196,   198,   203,
     204,   209,   210,   211,   212,   213,   214,   219,   220,   221,
     225,   226,   227,   228,   230,   236,   237,   238,   239,   240,
     241,   242,   243,   249,   250,   256,   257,   262,   263,   264,
     266,   272,   273,   279,   280
};
#endif

/** Accessing symbol of state STATE.  */
#define YY_ACCESSING_SYMBOL(State) YY_CAST (yysymbol_kind_t, yystos[State])

#if YYDEBUG || 0
/* The user-facing name of the symbol whose (internal) number is
   YYSYMBOL.  No bounds checking.  */
static const char *yysymbol_name (yysymbol_kind_t yysymbol) YY_ATTRIBUTE_UNUSED;

/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "\"end of file\"", "error", "\"invalid token\"", "IF", "ELSE", "WHILE",
  "RETURN", "INT", "FLOAT", "CHAR", "VOID", "STRUCT", "PLUS", "MINUS",
  "DIVISION", "MULTIPLY", "EQUAL_OP", "NOT_EQUAL_OP", "LESS_EQUAL_OP",
  "RIGHT_EQUAL_OP", "LEFT_OP", "RIGHT_OP", "ASSIGN_OP", "LEFT_BRACE",
  "RIGHT_BRACE", "LEFT_BRACKET", "RIGHT_BRACKET", "LEFT_PAREN",
  "RIGHT_PAREN", "SEMICOLON", "COMMA", "CONSTINT", "CONSTFLOAT",
  "CONSTCHAR", "CONSTSTRING", "IDENTIFIER", "LOWER_THAN_ELSE", "$accept",
  "programa", "declaracao_lista", "declaracao", "var_declaracao",
  "arrayDimensao", "tipo_especificador", "varDeclList", "func_declaracao",
  "params", "params_lista", "param", "composto_decl", "local_declaracoes",
  "comando_lista", "comando", "expressao_decl", "selecao_decl",
  "iteracao_decl", "retorno_decl", "expressao", "expressao_simples",
  "relacional", "exp_soma", "termo", "fator", "ativacao", "args",
  "arg_lista", "var", "var_auxiliar", YY_NULLPTR
};

static const char *
yysymbol_name (yysymbol_kind_t yysymbol)
{
  return yytname[yysymbol];
}
#endif

#define YYPACT_NINF (-77)

#define yypact_value_is_default(Yyn) \
  ((Yyn) == YYPACT_NINF)

#define YYTABLE_NINF (-87)

#define yytable_value_is_error(Yyn) \
  0

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
static const yytype_int16 yypact[] =
{
     203,   -77,   -77,   -77,   -77,    21,     7,   208,   -77,   -77,
      27,   -77,    -5,    17,   -77,    -8,   -77,   -23,   174,   203,
     203,   -77,   244,   -77,     0,    41,     8,   219,   -77,    22,
     203,    33,    29,    46,    61,    42,    76,   -77,    66,   -77,
      28,   100,   108,   107,   113,   -77,   -77,   114,   155,   -77,
     -77,   162,   119,   203,   -77,   130,   130,   119,   119,   131,
     133,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,   -77,
     203,   -77,    14,   135,   149,   151,    32,   -77,    78,   -77,
     -77,   -77,   -77,   -77,   -11,   -77,   -77,   -77,   -77,   -77,
     -77,   156,   -77,   220,    -4,   -77,   -77,   164,   -77,    87,
      96,   160,   -77,   166,   163,   169,   215,    59,   -77,   215,
     215,   -77,   -77,   -77,   -77,   -77,   -77,   215,   215,   215,
     105,   170,   172,   193,   195,   -77,   -77,   -77,   -77,   176,
     196,   -77,   197,   201,    -4,   -77,    -4,    13,   132,   153,
     -77,   -77,    49,    49,    49,    49,   -77,   -77,   -77,    68,
     -77,   -77,   -77,   230,   -77,   -77,   210,   -77,   242,   -77,
      49,   215,   -77,   -77,   218,   -77
};

/* YYDEFACT[STATE-NUM] -- Default reduction number in state STATE-NUM.
   Performed when YYTABLE does not specify something else to do.  Zero
   means the default is an error.  */
static const yytype_int8 yydefact[] =
{
       0,    17,    18,    19,    20,     0,     0,     0,     3,     7,
       0,     6,     0,     0,     1,     0,     4,     0,     0,     0,
       0,     5,     0,    12,     0,     0,     0,     0,     8,     0,
      23,     0,     0,     0,    20,     0,     0,    28,    30,    11,
       0,     0,     0,     0,     0,     9,    24,     0,     0,    22,
      21,     0,     0,     0,    10,    15,    14,     0,     0,     0,
       0,    37,    26,    31,    16,    13,    27,    25,    34,    33,
      39,    36,     0,     0,     0,     0,     0,    35,     0,    47,
      79,    78,    80,    81,    91,    41,    38,    40,    42,    43,
      44,     0,    58,    60,    67,    70,    77,    76,    45,     0,
       0,     0,    53,     0,     0,     0,     0,     0,    46,     0,
       0,    65,    66,    63,    64,    61,    62,     0,     0,     0,
       0,     0,     0,     0,     0,    55,    54,    82,    75,     0,
       0,    87,     0,    85,    68,    76,    69,    59,     0,     0,
      57,    56,     0,     0,     0,     0,    94,    84,    83,     0,
      74,    73,    50,    48,    52,    51,    92,    90,     0,    88,
       0,     0,    89,    49,     0,    93
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
     -77,   -77,   -77,   238,     1,   -20,     5,   -17,   -77,   229,
     204,   -77,   136,   -77,   -77,    62,   -77,   -77,   -77,   -77,
     -76,   -77,   -77,   141,   -35,     6,   -77,   -77,   -77,    -2,
     -77
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_uint8 yydefgoto[] =
{
       0,     6,     7,     8,    30,    29,    31,    32,    11,    36,
      37,    38,    85,    70,    72,    86,    87,    88,    89,    90,
      91,    92,   117,    93,    94,    95,    96,   132,   133,    97,
     156
};

/* YYTABLE[YYPACT[STATE-NUM]] -- What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule whose
   number is the opposite.  If YYTABLE_NINF, syntax error.  */
static const yytype_int16 yytable[] =
{
     103,     9,   105,    33,    22,    10,    23,    14,     9,    41,
     118,   119,    10,    46,   106,    73,   107,    74,    19,    75,
      76,    21,    12,   122,   124,   109,   110,    35,    17,    39,
     129,   131,    35,   101,    47,    64,    65,    61,    77,    42,
      20,    78,    40,    79,   141,    80,    81,    82,    83,    84,
      73,    45,    74,    49,    75,    76,    13,    54,    35,    78,
     130,   102,    18,    80,    81,    82,    83,    84,    48,   157,
      50,    71,    61,   159,   134,   136,    78,    51,    79,   104,
      80,    81,    82,    83,    84,   164,    78,   -86,   121,   -29,
      80,    81,    82,    83,    84,    78,    53,   123,   158,    80,
      81,    82,    83,    84,    52,    78,   140,   135,   135,    80,
      81,    82,    83,    84,    78,   135,   135,   135,    80,    81,
      82,    83,    84,    78,   138,   139,    55,    80,    81,    82,
      83,    84,    78,   150,    56,    57,    80,    81,    82,    83,
      84,    58,    61,    23,   -72,   -72,   -72,   -72,   -72,   -72,
     -72,   -72,   -72,   -72,   151,    26,    24,    68,   -72,    69,
     -72,   -72,   -72,    59,    98,   -71,   -71,   -71,   -71,   -71,
     -71,   -71,   -71,   -71,   -71,    24,    99,    25,   100,   -71,
      26,   -71,   -71,   -71,    28,   108,   120,    60,    62,   125,
     -32,   127,   -32,    66,    67,   126,    25,   128,   142,    26,
     143,    27,   146,    28,   152,   153,   154,   155,    -2,    15,
       1,     2,     3,     4,     5,     1,     2,     3,     4,     5,
      43,   144,   163,   145,   147,   148,     1,     2,     3,    34,
       5,   149,   109,   110,   160,   161,   111,   112,   113,   114,
     115,   116,    78,   162,   165,    16,    80,    81,    82,    83,
      84,     1,     2,     3,    34,     5,    44,    63,   137
};

static const yytype_uint8 yycheck[] =
{
      76,     0,    78,    20,    27,     0,    29,     0,     7,     1,
      14,    15,     7,    30,    25,     1,    27,     3,    23,     5,
       6,    29,     1,    99,   100,    12,    13,    22,     1,    29,
     106,   107,    27,     1,     1,    55,    56,    23,    24,    31,
      23,    27,     1,    29,   120,    31,    32,    33,    34,    35,
       1,    29,     3,    24,     5,     6,    35,    29,    53,    27,
       1,    29,    35,    31,    32,    33,    34,    35,    35,     1,
      24,    70,    23,   149,   109,   110,    27,    35,    29,     1,
      31,    32,    33,    34,    35,   161,    27,    28,     1,    28,
      31,    32,    33,    34,    35,    27,    30,     1,    30,    31,
      32,    33,    34,    35,    28,    27,     1,   109,   110,    31,
      32,    33,    34,    35,    27,   117,   118,   119,    31,    32,
      33,    34,    35,    27,   118,   119,    26,    31,    32,    33,
      34,    35,    27,     1,    26,    28,    31,    32,    33,    34,
      35,    28,    23,    29,    12,    13,    14,    15,    16,    17,
      18,    19,    20,    21,     1,    25,     1,    26,    26,    26,
      28,    29,    30,     1,    29,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,     1,    27,    22,    27,    26,
      25,    28,    29,    30,    29,    29,    22,    25,    52,    29,
      28,    28,    30,    57,    58,    29,    22,    28,    28,    25,
      28,    27,    26,    29,   142,   143,   144,   145,     0,     1,
       7,     8,     9,    10,    11,     7,     8,     9,    10,    11,
       1,    28,   160,    28,    28,    28,     7,     8,     9,    10,
      11,    30,    12,    13,     4,    25,    16,    17,    18,    19,
      20,    21,    27,     1,    26,     7,    31,    32,    33,    34,
      35,     7,     8,     9,    10,    11,    27,    53,   117
};

/* YYSTOS[STATE-NUM] -- The symbol kind of the accessing symbol of
   state STATE-NUM.  */
static const yytype_int8 yystos[] =
{
       0,     7,     8,     9,    10,    11,    38,    39,    40,    41,
      43,    45,     1,    35,     0,     1,    40,     1,    35,    23,
      23,    29,    27,    29,     1,    22,    25,    27,    29,    42,
      41,    43,    44,    44,    10,    43,    46,    47,    48,    29,
       1,     1,    31,     1,    46,    29,    44,     1,    35,    24,
      24,    35,    28,    30,    29,    26,    26,    28,    28,     1,
      25,    23,    49,    47,    42,    42,    49,    49,    26,    26,
      50,    41,    51,     1,     3,     5,     6,    24,    27,    29,
      31,    32,    33,    34,    35,    49,    52,    53,    54,    55,
      56,    57,    58,    60,    61,    62,    63,    66,    29,    27,
      27,     1,    29,    57,     1,    57,    25,    27,    29,    12,
      13,    16,    17,    18,    19,    20,    21,    59,    14,    15,
      22,     1,    57,     1,    57,    29,    29,    28,    28,    57,
       1,    57,    64,    65,    61,    66,    61,    60,    62,    62,
       1,    57,    28,    28,    28,    28,    26,    28,    28,    30,
       1,     1,    52,    52,    52,    52,    67,     1,    30,    57,
       4,    25,     1,    52,    57,    26
};

/* YYR1[RULE-NUM] -- Symbol kind of the left-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr1[] =
{
       0,    37,    38,    39,    39,    39,    40,    40,    41,    41,
      41,    41,    41,    42,    42,    42,    42,    43,    43,    43,
      43,    43,    43,    44,    44,    45,    45,    45,    46,    46,
      47,    47,    48,    48,    48,    49,    50,    50,    51,    51,
      52,    52,    52,    52,    52,    52,    53,    53,    54,    54,
      54,    55,    55,    56,    56,    56,    57,    57,    57,    58,
      58,    59,    59,    59,    59,    59,    59,    60,    60,    60,
      61,    61,    61,    61,    61,    62,    62,    62,    62,    62,
      62,    62,    62,    63,    63,    64,    64,    65,    65,    65,
      65,    66,    66,    67,    67
};

/* YYR2[RULE-NUM] -- Number of symbols on the right-hand side of rule RULE-NUM.  */
static const yytype_int8 yyr2[] =
{
       0,     2,     1,     1,     2,     3,     1,     1,     3,     4,
       5,     4,     3,     4,     3,     3,     4,     1,     1,     1,
       1,     5,     5,     1,     2,     6,     6,     6,     1,     1,
       1,     3,     2,     4,     4,     4,     2,     0,     2,     0,
       1,     1,     1,     1,     1,     2,     2,     1,     5,     7,
       5,     5,     5,     2,     3,     3,     3,     3,     1,     3,
       1,     1,     1,     1,     1,     1,     1,     1,     3,     3,
       1,     3,     3,     4,     4,     3,     1,     1,     1,     1,
       1,     1,     3,     4,     4,     1,     0,     1,     3,     4,
       3,     1,     5,     4,     0
};


enum { YYENOMEM = -2 };

#define yyerrok         (yyerrstatus = 0)
#define yyclearin       (yychar = YYEMPTY)

#define YYACCEPT        goto yyacceptlab
#define YYABORT         goto yyabortlab
#define YYERROR         goto yyerrorlab
#define YYNOMEM         goto yyexhaustedlab


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

/* Backward compatibility with an undocumented macro.
   Use YYerror or YYUNDEF. */
#define YYERRCODE YYUNDEF


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




# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)                    \
do {                                                                      \
  if (yydebug)                                                            \
    {                                                                     \
      YYFPRINTF (stderr, "%s ", Title);                                   \
      yy_symbol_print (stderr,                                            \
                  Kind, Value); \
      YYFPRINTF (stderr, "\n");                                           \
    }                                                                     \
} while (0)


/*-----------------------------------.
| Print this symbol's value on YYO.  |
`-----------------------------------*/

static void
yy_symbol_value_print (FILE *yyo,
                       yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  FILE *yyoutput = yyo;
  YY_USE (yyoutput);
  if (!yyvaluep)
    return;
  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/*---------------------------.
| Print this symbol on YYO.  |
`---------------------------*/

static void
yy_symbol_print (FILE *yyo,
                 yysymbol_kind_t yykind, YYSTYPE const * const yyvaluep)
{
  YYFPRINTF (yyo, "%s %s (",
             yykind < YYNTOKENS ? "token" : "nterm", yysymbol_name (yykind));

  yy_symbol_value_print (yyo, yykind, yyvaluep);
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
yy_reduce_print (yy_state_t *yyssp, YYSTYPE *yyvsp,
                 int yyrule)
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
                       YY_ACCESSING_SYMBOL (+yyssp[yyi + 1 - yynrhs]),
                       &yyvsp[(yyi + 1) - (yynrhs)]);
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
# define YYDPRINTF(Args) ((void) 0)
# define YY_SYMBOL_PRINT(Title, Kind, Value, Location)
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






/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

static void
yydestruct (const char *yymsg,
            yysymbol_kind_t yykind, YYSTYPE *yyvaluep)
{
  YY_USE (yyvaluep);
  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yykind, yyvaluep, yylocationp);

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  YY_USE (yykind);
  YY_IGNORE_MAYBE_UNINITIALIZED_END
}


/* Lookahead token kind.  */
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
    yy_state_fast_t yystate = 0;
    /* Number of tokens to shift before error messages enabled.  */
    int yyerrstatus = 0;

    /* Refer to the stacks through separate pointers, to allow yyoverflow
       to reallocate them elsewhere.  */

    /* Their size.  */
    YYPTRDIFF_T yystacksize = YYINITDEPTH;

    /* The state stack: array, bottom, top.  */
    yy_state_t yyssa[YYINITDEPTH];
    yy_state_t *yyss = yyssa;
    yy_state_t *yyssp = yyss;

    /* The semantic value stack: array, bottom, top.  */
    YYSTYPE yyvsa[YYINITDEPTH];
    YYSTYPE *yyvs = yyvsa;
    YYSTYPE *yyvsp = yyvs;

  int yyn;
  /* The return value of yyparse.  */
  int yyresult;
  /* Lookahead symbol kind.  */
  yysymbol_kind_t yytoken = YYSYMBOL_YYEMPTY;
  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

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
  YY_STACK_PRINT (yyss, yyssp);

  if (yyss + yystacksize - 1 <= yyssp)
#if !defined yyoverflow && !defined YYSTACK_RELOCATE
    YYNOMEM;
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
        YYNOMEM;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
        yystacksize = YYMAXDEPTH;

      {
        yy_state_t *yyss1 = yyss;
        union yyalloc *yyptr =
          YY_CAST (union yyalloc *,
                   YYSTACK_ALLOC (YY_CAST (YYSIZE_T, YYSTACK_BYTES (yystacksize))));
        if (! yyptr)
          YYNOMEM;
        YYSTACK_RELOCATE (yyss_alloc, yyss);
        YYSTACK_RELOCATE (yyvs_alloc, yyvs);
#  undef YYSTACK_RELOCATE
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

  /* YYCHAR is either empty, or end-of-input, or a valid lookahead.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token\n"));
      yychar = yylex ();
    }

  if (yychar <= YYEOF)
    {
      yychar = YYEOF;
      yytoken = YYSYMBOL_YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else if (yychar == YYerror)
    {
      /* The scanner already issued an error message, process directly
         to error recovery.  But do not keep the error token as
         lookahead, it is too special and may lead us to an endless
         loop in error recovery. */
      yychar = YYUNDEF;
      yytoken = YYSYMBOL_YYerror;
      goto yyerrlab1;
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
  case 5: /* declaracao_lista: declaracao_lista error SEMICOLON  */
#line 61 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaracao mal formada e não reconhecida"); yyerrok; }
#line 1277 "parser.tab.c"
    break;

  case 10: /* var_declaracao: tipo_especificador IDENTIFIER ASSIGN_OP error SEMICOLON  */
#line 75 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Inicialização de variável não suportada nesta linguagem"); yyerrok; }
#line 1283 "parser.tab.c"
    break;

  case 11: /* var_declaracao: tipo_especificador IDENTIFIER error SEMICOLON  */
#line 77 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); yyerrok; }
#line 1289 "parser.tab.c"
    break;

  case 12: /* var_declaracao: tipo_especificador error SEMICOLON  */
#line 79 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); yyerrok; }
#line 1295 "parser.tab.c"
    break;

  case 15: /* arrayDimensao: LEFT_BRACKET error RIGHT_BRACKET  */
#line 86 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); yyerrok; }
#line 1301 "parser.tab.c"
    break;

  case 16: /* arrayDimensao: LEFT_BRACKET error RIGHT_BRACKET arrayDimensao  */
#line 88 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); yyerrok; }
#line 1307 "parser.tab.c"
    break;

  case 22: /* tipo_especificador: STRUCT error LEFT_BRACE varDeclList RIGHT_BRACE  */
#line 99 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Nome de struct ausente"); yyerrok; }
#line 1313 "parser.tab.c"
    break;

  case 26: /* func_declaracao: tipo_especificador error LEFT_PAREN params RIGHT_PAREN composto_decl  */
#line 112 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Função inexistente ou invalida apos o tipo de retorno"); yyerrok; }
#line 1319 "parser.tab.c"
    break;

  case 27: /* func_declaracao: tipo_especificador IDENTIFIER LEFT_PAREN error RIGHT_PAREN composto_decl  */
#line 114 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Lista de parâmetros malformada na declaração de função"); yyerrok; }
#line 1325 "parser.tab.c"
    break;

  case 34: /* param: tipo_especificador IDENTIFIER error RIGHT_BRACKET  */
#line 134 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Falta de abrir colchetes"); yyerrok; }
#line 1331 "parser.tab.c"
    break;

  case 45: /* comando: error SEMICOLON  */
#line 162 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Comando invalido sintaticamente ou incompleto"); yyerrok; }
#line 1337 "parser.tab.c"
    break;

  case 50: /* selecao_decl: IF LEFT_PAREN error RIGHT_PAREN comando  */
#line 175 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Condição errada no comando IF"); yyerrok;}
#line 1343 "parser.tab.c"
    break;

  case 52: /* iteracao_decl: WHILE LEFT_PAREN error RIGHT_PAREN comando  */
#line 182 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Comando WHILE invalido"); yyerrok; }
#line 1349 "parser.tab.c"
    break;

  case 55: /* retorno_decl: RETURN error SEMICOLON  */
#line 190 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Retorno invalido"); yyerrok;}
#line 1355 "parser.tab.c"
    break;

  case 57: /* expressao: var ASSIGN_OP error  */
#line 197 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Atribuição sem expressão à direita"); yyerrok; }
#line 1361 "parser.tab.c"
    break;

  case 73: /* termo: termo MULTIPLY fator error  */
#line 229 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Operação de '*' sem o fator"); yyerrok; }
#line 1367 "parser.tab.c"
    break;

  case 74: /* termo: termo DIVISION fator error  */
#line 231 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Operação de '/' sem o fator"); yyerrok; }
#line 1373 "parser.tab.c"
    break;

  case 82: /* fator: LEFT_PAREN error RIGHT_PAREN  */
#line 244 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Expressao Vazia"); yyerrok; }
#line 1379 "parser.tab.c"
    break;

  case 84: /* ativacao: IDENTIFIER LEFT_PAREN error RIGHT_PAREN  */
#line 251 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Argumentos invalidos no retorno da funcao"); yyerrok; }
#line 1385 "parser.tab.c"
    break;

  case 89: /* arg_lista: arg_lista COMMA COMMA error  */
#line 265 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Falta de parametro"); yyerrok; }
#line 1391 "parser.tab.c"
    break;

  case 90: /* arg_lista: arg_lista COMMA error  */
#line 267 "parser.y"
    { erro_sintatico_previsto("Erro Sintático: Virgula excedente ao final da lista de parametros"); yyerrok; }
#line 1397 "parser.tab.c"
    break;


#line 1401 "parser.tab.c"

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
  YY_SYMBOL_PRINT ("-> $$ =", YY_CAST (yysymbol_kind_t, yyr1[yyn]), &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;

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
  yytoken = yychar == YYEMPTY ? YYSYMBOL_YYEMPTY : YYTRANSLATE (yychar);
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
      yyerror (YY_("syntax error"));
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
  ++yynerrs;

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

  /* Pop stack until we find a state that shifts the error token.  */
  for (;;)
    {
      yyn = yypact[yystate];
      if (!yypact_value_is_default (yyn))
        {
          yyn += YYSYMBOL_YYerror;
          if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYSYMBOL_YYerror)
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
                  YY_ACCESSING_SYMBOL (yystate), yyvsp);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  YY_IGNORE_MAYBE_UNINITIALIZED_BEGIN
  *++yyvsp = yylval;
  YY_IGNORE_MAYBE_UNINITIALIZED_END


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", YY_ACCESSING_SYMBOL (yyn), yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturnlab;


/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturnlab;


/*-----------------------------------------------------------.
| yyexhaustedlab -- YYNOMEM (memory exhaustion) comes here.  |
`-----------------------------------------------------------*/
yyexhaustedlab:
  yyerror (YY_("memory exhausted"));
  yyresult = 2;
  goto yyreturnlab;


/*----------------------------------------------------------.
| yyreturnlab -- parsing is finished, clean up and return.  |
`----------------------------------------------------------*/
yyreturnlab:
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
                  YY_ACCESSING_SYMBOL (+*yyssp), yyvsp);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif

  return yyresult;
}

#line 283 "parser.y"



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

    fclose(compiled_arq);
    return 0;
}
