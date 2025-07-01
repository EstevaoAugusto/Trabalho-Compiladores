%{
/*-------------------------- Definitions --------------------------*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "parser.tab.h"

int line_number = 1;
int column_number = 1;
int lexical_errors = 0;

#define TAB_SIZE 4
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

comment                         "/*"([^*]|\*+[^/])*\*+"/"
char_literal                    \'([^\\\n]|\\.)\'
other                           .


%%
%{
/*----------------------------- Regras -----------------------------*/
%}

\n              { line_number++; column_number = 1; }
[ ]+            { column_number += yyleng; }
\t+           {
                  for (int i = 0; i < yyleng; i++) {
                      column_number += TAB_SIZE - ((column_number - 1) % TAB_SIZE); 
                  }
              }

{comment}           { column_number += yyleng; }
"if"                { column_number += yyleng; return IF; }
"else"              { column_number += yyleng; return ELSE; }
"while"             { column_number += yyleng; return WHILE; }
"return"            { column_number += yyleng; return RETURN; }
"int"               { column_number += yyleng; return INT; }
"float"             { column_number += yyleng; return FLOAT; }
"char"              { column_number += yyleng; return CHAR; }
"struct"            { column_number += yyleng; return STRUCT; }
"void"              { column_number += yyleng; return VOID; }

{num_int}           { yylval.intval = atoi(yytext);       column_number += yyleng; return CONSTINT; }
{num}               { yylval.floatval = atof(yytext);   column_number += yyleng; return CONSTFLOAT; }
{ident}             { yylval.id = strdup(yytext);       column_number += yyleng; return IDENTIFIER; }

"=="                { yylval.sval = strdup(yytext);     column_number += yyleng; return EQUAL_OP;       }
"!="                { yylval.sval = strdup(yytext);     column_number += yyleng; return NOT_EQUAL_OP;   }
"<="                { yylval.sval = strdup(yytext);     column_number += yyleng; return LESS_EQUAL_OP;  }
">="                { yylval.sval = strdup(yytext);     column_number += yyleng; return RIGHT_EQUAL_OP; }
"<"                 { yylval.sval = strdup(yytext);     column_number += yyleng; return LEFT_OP;        }
">"                 { yylval.sval = strdup(yytext);     column_number += yyleng; return RIGHT_OP;       }
"="                 { yylval.sval = strdup(yytext);     column_number += yyleng; return ASSIGN_OP;      }

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

{num_int}{ident}        { 
                            fprintf(yyout, "Erro Léxico: identificador invalido iniciado com numero na linha %d, coluna %d: %s\n", line_number, column_number, yytext); 
                            column_number += yyleng;
                            lexical_errors++;    
                        }

[\u201C\u201D]          {
                            fprintf(yyout, "Erro Léxico: uso de aspas invalidas (aspas curvas) na linha %d, coluna %d: %s\n", line_number, column_number, yytext); 
                            column_number += yyleng;
                            lexical_errors++;    
                        }

\'([^\\\n]|\\.){2,}\'   { 
                            fprintf(yyout, "Erro Léxico: constante char com mais de um caractere na linha %d, coluna %d: %s\n", line_number, column_number, yytext); 
                            column_number += yyleng;
                            lexical_errors++;    
                        }

\"([^\\\"\n]|\\.)*      { 
                            fprintf(yyout, "Erro Léxico: string nao fechada na linha %d, coluna %d: %s\n", line_number, column_number, yytext); 
                            column_number += yyleng;
                            lexical_errors++;
                        }  

{other}                 { 
                            fprintf(yyout, "Erro Léxico: simbolo lexico invalido na linha %d, coluna %d: %s\n", line_number, column_number, yytext); 
                            column_number += yyleng;
                            lexical_errors++;    
                        }

%%
