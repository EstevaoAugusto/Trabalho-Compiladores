
/* A Bison parser, made by GNU Bison 2.4.1.  */

/* Skeleton interface for Bison's Yacc-like parsers in C
   
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

/* "%code requires" blocks.  */

/* Line 1676 of yacc.c  */
#line 1 "parser.y"

    #include "tabelaSimbolos.h"



/* Line 1676 of yacc.c  */
#line 46 "parser.tab.h"

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

/* Line 1676 of yacc.c  */
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



/* Line 1676 of yacc.c  */
#line 115 "parser.tab.h"
} YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


