%{
/*-------------------------- Definitions --------------------------*/
#include <stdio.h>
#include "parser.tab.h"

#define YYSTYPE double

int line_number = 1;
int column_number = 1;

%}

/*-------------------------- Definições --------------------------*/

letra                           [a-z]
digito                          [0-9]
ident                           {letter}({letter}|{digit}|_({letter}|{digit}))*
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

var                             {ident}|{ident}({abre_colchete}{expressao}{fecha_colchete})+
fator                           \({expressao}\)|{var}|{ativacao}|{num}|{num_int}
termo                           {fator}({multi}{fator})*
expressao_soma                  {termo}({soma}{termo})*
expressao_simples               {expressao_soma}{relacional}{expressao_soma}|{expressao_soma}
expressao                       ({var}={expressao}|{expressao_simples})

arg_lista                       {expressao}(,{expressao})*
args                            {arg_lista}?
ativacao                        {ident}\({args}\)

expressao_decl                  {expressao};|;
selecao_decl                    (if\({expressao}\){comando}|if\({expressao}\){comando}else{comando})
iteracao_decl                   while\({expressao}\){comando}
retorno_decl                    return;|return{expressao};

comando                         {expressao_decl}|{composto_decl}|{selecao_decl}|{iteracao_decl}|{retorno_decl}
comando_lista                   {comando}*
local_declaracoes               {var_declaracao}*
composto_decl                   {abre_chave}{local_declaracoes}{comando_lista}{fecha_chave}

param                           ({tipo_especificador}{ident}|{tipo_especificador}{ident}{abre_colchete}{fecha_colchete})
params_lista                    {param}(,{param})*
params                          {params_lista}|void

var_declaracao                  {tipo_especificador}{ident};|{tipo_especificador}{ident}({abre_colchete}{num_int}{fecha_colchete})+;
atributos_declaracao            {var_declaracao}+
tipo_especificador              (int|float|char|void|struct{ident}{abre_chave}{atributos_declaracao}{fecha_chave})
func_declaracao                 {tipo_especificador}{ident}\({params}\){composto_decl}
declaracao                      {var_declaracao}|{func_declaracao}
declaracao_lista                {declaracao}+
programa                        {declaracao_lista}

%%
%{
/*----------------------------- Regras -----------------------------*/
%}

\n              { line_number++; column_number = 1; }
{ws}			{ column_number += yyleng; }

{comment}       { for (int i = 0; i < yyleng; i++) {
                        if (yytext[i] == '\n') {
                            line_number++;
                            column_number = 1;
                        } else {
                            column_number++;
                        }
                    }
                }

{num_int}       { fprintf(yyout, "%-5d | %-6d | %-20s | (CONSTINT)\n", line_number, column_number, yytext); column_number += yyleng; return CONSTINT; }
{num}           { fprintf(yyout, "%-5d | %-6d | %-20s | (CONSTFLOAT)\n", line_number, column_number, yytext); column_number += yyleng; return CONSTFLOAT; }
{ident}         { fprintf(yyout, "%-5d | %-6d | %-20s | (IDENTIFIER)\n", line_number, column_number, yytext); column_number += yyleng; return IDENTIFIER; }

"if"            { fprintf(yyout, "%-5d | %-6d | %-20s | (IF)\n", line_number, column_number, yytext); column_number += yyleng; return IF}
"else"          { fprintf(yyout, "%-5d | %-6d | %-20s | (ELSE)\n", line_number, column_number, yytext); column_number += yyleng; return ELSE }
"while"         { fprintf(yyout, "%-5d | %-6d | %-20s | (WHILE)\n", line_number, column_number, yytext); column_number += yyleng; return WHILE;}
"return"        { fprintf(yyout, "%-5d | %-6d | %-20s | (RETURN)\n", line_number, column_number, yytext); column_number += yyleng; return RETURN; }
"int"           { fprintf(yyout, "%-5d | %-6d | %-20s | (INT)\n", line_number, column_number, yytext); column_number += yyleng; return INT; }
"float"         { fprintf(yyout, "%-5d | %-6d | %-20s | (FLOAT)\n", line_number, column_number, yytext); column_number += yyleng; return FLOAT; }
"char"          { fprintf(yyout, "%-5d | %-6d | %-20s | (CHAR)\n", line_number, column_number, yytext); column_number += yyleng; return CHAR; }
"boolean"       { fprintf(yyout, "%-5d | %-6d | %-20s | (BOOLEAN)\n", line_number, column_number, yytext); column_number += yyleng; return BOOLEAN; }
"struct"        { fprintf(yyout, "%-5d | %-6d | %-20s | (STRUCT)\n", line_number, column_number, yytext); column_number += yyleng; return STRUCT; }
"void"          { fprintf(yyout, "%-5d | %-6d | %-20s | (VOID)\n", line_number, column_number, yytext); column_number += yyleng; return VOID; }

"=="            { fprintf(yyout, "%-5d | %-6d | %-20s | (EQUAL_OP)\n", line_number, column_number, yytext); column_number += yyleng; return EQUAL_OP; }
"!="            { fprintf(yyout, "%-5d | %-6d | %-20s | (NOT_EQUAL_OP)\n", line_number, column_number, yytext); column_number += yyleng; return NOT_EQUAL_OP; }
"<="            { fprintf(yyout, "%-5d | %-6d | %-20s | (LESS_EQUAL_OP)\n", line_number, column_number, yytext); column_number += yyleng; return LESS_EQUAL_OP; }
">="            { fprintf(yyout, "%-5d | %-6d | %-20s | (RIGHT_EQUAL_OP)\n", line_number, column_number, yytext); column_number += yyleng; return RIGHT_EQUAL_OP; }
"<"             { fprintf(yyout, "%-5d | %-6d | %-20s | (LEFT_OP)\n", line_number, column_number, yytext); column_number += yyleng; return LEFT_OP; }
">"             { fprintf(yyout, "%-5d | %-6d | %-20s | (RIGHT_OP)\n", line_number, column_number, yytext); column_number += yyleng; return RIGHT_OP; }
"="             { fprintf(yyout, "%-5d | %-6d | %-20s | (ASSIGN_OP)\n", line_number, column_number, yytext); column_number += yyleng; return ASSIGN_OP}

{abre_chave}        { fprintf(yyout, "%-5d | %-6d | %-20s | (LEFT_BRACE)\n", line_number, column_number, yytext); column_number += yyleng; return LEFT_BRACE; }
{fecha_chave}       { fprintf(yyout, "%-5d | %-6d | %-20s | (RIGHT_BRACE)\n", line_number, column_number, yytext); column_number += yyleng; return RIGHT_BRACE; }
{abre_colchete}     { fprintf(yyout, "%-5d | %-6d | %-20s | (LEFT_BRACKET)\n", line_number, column_number, yytext); column_number += yyleng; return LEFT_BRACKET; }
{fecha_colchete}    { fprintf(yyout, "%-5d | %-6d | %-20s | (RIGHT_BRACKET)\n", line_number, column_number, yytext); column_number += yyleng; return RIGHT_BRACKET; }
{abre_parenteses}   { fprintf(yyout, "%-5d | %-6d | %-20s | (LEFT_PAREN)\n", line_number, column_number, yytext); column_number += yyleng; return LEFT_PAREN; }
{fecha_parenteses}  { fprintf(yyout, "%-5d | %-6d | %-20s | (RIGHT_PAREN)\n", line_number, column_number, yytext); column_number += yyleng; return RIGHT_PAREN; }
";"                 { fprintf(yyout, "%-5d | %-6d | %-20s | (SEMICOLON)\n", line_number, column_number, yytext); column_number += yyleng; return SEMICOLON; }
","                 { fprintf(yyout, "%-5d | %-6d | %-20s | (COMMA)\n", line_number, column_number, yytext); column_number += yyleng; return COMMA; }

{char_literal}      { fprintf(yyout, "%-5d | %-6d | %-20s | (CONSTCHAR)\n", line_number, column_number, yytext); column_number += yyleng; return CONSTCHAR; }

"+"                 { fprintf(yyout, "%-5d | %-6d | %-20s | (PLUS)\n", line_number, column_number, yytext); column_number += yyleng; return PLUS; }
"-"                 { fprintf(yyout, "%-5d | %-6d | %-20s | (MINUS)\n", line_number, column_number, yytext); column_number += yyleng; return MINUS; }
"/"                 { fprintf(yyout, "%-5d | %-6d | %-20s | (DIVISION)\n", line_number, column_number, yytext); column_number += yyleng; return DIVISION; }
"*"                 { fprintf(yyout, "%-5d | %-6d | %-20s | (MULTIPLY)\n", line_number, column_number, yytext); column_number += yyleng; return MULTIPLY; }

[0-9]+[a-zA-Z_]+        { fprintf(yyout, "%-5d | %-6d | %-20s | Lexical Error: identificador inválido iniciado com número\n", line_number, column_number, yytext); }
[\u201C\u201D]          { fprintf(yyout, "%-5d | %-6d | %-20s | Lexical Error: uso de aspas inválidas (aspas curvas)\n", line_number, column_number, yytext); }
\'([^\\\n]|\\.){2,}\'   { fprintf(yyout, "%-5d | %-6d | %-20s | Lexical Error: constante char com mais de um caractere\n", line_number, column_number, yytext); }
\"([^\\\"\n]|\\.)*      { fprintf(yyout, "%-5d | %-6d | %-20s | Lexical Error: string não fechada\n", line_number, column_number, yytext); }
.                       { fprintf(yyout, "%-5d | %-6d | %-20s | Lexical Error: símbolo inválido\n", line_number, column_number, yytext); }

%%

int yywrap(){
    return 1;
}