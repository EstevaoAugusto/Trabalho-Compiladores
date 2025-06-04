
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
     IDENTIFIER = 267,
     CONSTINT = 268,
     CONSTFLOAT = 269,
     CONSTCHAR = 270,
     CONSTSTRING = 271,
     ASSIGN_OP = 272,
     PLUS = 273,
     MINUS = 274,
     MULTIPLY = 275,
     DIVISION = 276,
     LEFT_OP = 277,
     RIGHT_OP = 278,
     EQUAL_OP = 279,
     NOT_EQUAL_OP = 280,
     LESS_EQUAL_OP = 281,
     RIGHT_EQUAL_OP = 282,
     LEFT_BRACE = 283,
     RIGHT_BRACE = 284,
     LEFT_BRACKET = 285,
     RIGHT_BRACKET = 286,
     LEFT_PAREN = 287,
     RIGHT_PAREN = 288,
     SEMICOLON = 289,
     COMMA = 290
   };
#endif



#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
#endif

extern YYSTYPE yylval;


