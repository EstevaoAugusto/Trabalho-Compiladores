/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

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

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_TAB_H_INCLUDED
# define YY_YY_PARSER_TAB_H_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IF = 258,                      /* IF  */
    ELSE = 259,                    /* ELSE  */
    WHILE = 260,                   /* WHILE  */
    RETURN = 261,                  /* RETURN  */
    INT = 262,                     /* INT  */
    FLOAT = 263,                   /* FLOAT  */
    CHAR = 264,                    /* CHAR  */
    VOID = 265,                    /* VOID  */
    STRUCT = 266,                  /* STRUCT  */
    PLUS = 267,                    /* PLUS  */
    MINUS = 268,                   /* MINUS  */
    DIVISION = 269,                /* DIVISION  */
    EQUAL_OP = 270,                /* EQUAL_OP  */
    NOT_EQUAL_OP = 271,            /* NOT_EQUAL_OP  */
    LESS_EQUAL_OP = 272,           /* LESS_EQUAL_OP  */
    RIGHT_EQUAL_OP = 273,          /* RIGHT_EQUAL_OP  */
    LEFT_OP = 274,                 /* LEFT_OP  */
    RIGHT_OP = 275,                /* RIGHT_OP  */
    ASSIGN_OP = 276,               /* ASSIGN_OP  */
    LEFT_BRACE = 277,              /* LEFT_BRACE  */
    RIGHT_BRACE = 278,             /* RIGHT_BRACE  */
    LEFT_BRACKET = 279,            /* LEFT_BRACKET  */
    RIGHT_BRACKET = 280,           /* RIGHT_BRACKET  */
    LEFT_PAREN = 281,              /* LEFT_PAREN  */
    RIGHT_PAREN = 282,             /* RIGHT_PAREN  */
    SEMICOLON = 283,               /* SEMICOLON  */
    COMMA = 284,                   /* COMMA  */
    CONSTINT = 285,                /* CONSTINT  */
    CONSTFLOAT = 286,              /* CONSTFLOAT  */
    CONSTCHAR = 287,               /* CONSTCHAR  */
    CONSTSTRING = 288,             /* CONSTSTRING  */
    IDENTIFIER = 289,              /* IDENTIFIER  */
    MULTIPLY = 290                 /* MULTIPLY  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_TAB_H_INCLUDED  */
