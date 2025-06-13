%{
/*-------------------------- Definitions --------------------------*/
#include <stdio.h>
#include<string.h>
#include "parser.tab.h"


int line_number = 1;
int column_number = 1;

%}

%option noyywrap

/*-------------------------- Definições --------------------------*/

letra                           [a-z]
digito                          [0-9]
ident                           {letra}({letra}|{digito})*
num_int                         {digito}+
num                             [+-]?[0-9]+(\.[0-9]+)?([E][+-]?[0-9]+)?

abre_chave                      \{
fecha_chave                     \}
abre_colchete                   \[
fecha_colchete                  \]
abre_parenteses                 \(
fecha_parenteses                \)

delim                           [ \t]
ws                              {delim}+
comment                         "/*"([^*]|\*+[^/])*\*+"/"
char_literal                    \'([^\\\n]|\\.)\'
other                           .

soma                            \+|\-
multi                           \/|\*

%%
%{
/*----------------------------- Regras -----------------------------*/
%}

\n              { line_number++; column_number = 1; }
{ws}			{ column_number += yyleng; }
{comment}       { column_number += yyleng; }

"if"                { column_number += yyleng; return IF; }
"else"              { column_number += yyleng; return ELSE; }
"while"             { column_number += yyleng; return WHILE; }
"return"            { column_number += yyleng; return RETURN; }
"int"               { column_number += yyleng; return INT; }
"float"             { column_number += yyleng; return FLOAT; }
"char"              { column_number += yyleng; return CHAR; }
"struct"            { column_number += yyleng; return STRUCT; }
"void"              { column_number += yyleng; return VOID; }

{num_int}           { column_number += yyleng; return CONSTINT; }
{num}               { column_number += yyleng; return CONSTFLOAT; }
{ident}             { column_number += yyleng; return IDENTIFIER; }

"=="                { column_number += yyleng; return EQUAL_OP; }
"!="                { column_number += yyleng; return NOT_EQUAL_OP; }
"<="                { column_number += yyleng; return LESS_EQUAL_OP; }
">="                { column_number += yyleng; return RIGHT_EQUAL_OP; }
"<"                 { column_number += yyleng; return LEFT_OP; }
">"                 { column_number += yyleng; return RIGHT_OP; }
"="                 { column_number += yyleng; return ASSIGN_OP; }

{abre_chave}        { column_number += yyleng; return LEFT_BRACE; }
{fecha_chave}       { column_number += yyleng; return RIGHT_BRACE; }
{abre_colchete}     { column_number += yyleng; return LEFT_BRACKET; }
{fecha_colchete}    { column_number += yyleng; return RIGHT_BRACKET; }
{abre_parenteses}   { column_number += yyleng; return LEFT_PAREN; }
{fecha_parenteses}  { column_number += yyleng; return RIGHT_PAREN; }
";"                 { column_number += yyleng; return SEMICOLON; }
","                 { column_number += yyleng; return COMMA; }

{char_literal}          { column_number += yyleng; return CONSTCHAR; }
\"([^\\\"\n]|\\.)*\"    { column_number += yyleng; return CONSTSTRING; }

"+"                 { column_number += yyleng; return PLUS; }
"-"                 { column_number += yyleng; return MINUS; }
"/"                 { column_number += yyleng; return DIVISION; }
"*"                 { column_number += yyleng; return MULTIPLY; }

[0-9]+[a-zA-Z_]+        { fprintf(yyout, "Lexical Error: identificador invalido iniciado com numero na linha %d, coluna %d: %s\n", line_number, column_number, yytext); }
[\u201C\u201D]          { fprintf(yyout, "Lexical Error: uso de aspas invalidas (aspas curvas) na linha %d, coluna %d: %s\n", line_number, column_number, yytext); }
\'([^\\\n]|\\.){2,}\'   { fprintf(yyout, "Lexical Error: constante char com mais de um caractere na linha %d, coluna %d: %s\n", line_number, column_number, yytext); }
\"([^\\\"\n]|\\.)*      { fprintf(yyout, "Lexical Error: string nao fechada na linha %d, coluna %d: %s\n", line_number, column_number, yytext); }
{other}                 { fprintf(yyout, "Lexical Error: simbolo invalido na linha %d, coluna %d: %s\n", line_number, column_number, yytext); }

%%
