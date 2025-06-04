%{
#include <stdio.h>
#include <stdlib.h>

extern int yylex();
void yyerror(const char *s);

extern int line_number;
extern int column_number;
%}

/*------------------------ Tokens ------------------------*/
%token IF ELSE WHILE RETURN
%token INT FLOAT CHAR VOID STRUCT

%token PLUS MINUS MULTIPLY DIVISION
%token EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP RIGHT_EQUAL_OP LEFT_OP RIGHT_OP
%token ASSIGN_OP

%token LEFT_BRACE RIGHT_BRACE
%token LEFT_BRACKET RIGHT_BRACKET
%token LEFT_PAREN RIGHT_PAREN

%token SEMICOLON COMMA

%token CONSTINT CONSTFLOAT CONSTCHAR CONSTSTRING
%token IDENTIFIER

/*------------------------ Precedência ------------------------*/
%left PLUS MINUS
%left MULTIPLY DIVISION
%left EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP RIGHT_EQUAL_OP LEFT_OP RIGHT_OP

/*------------------------ Símbolo inicial ------------------------*/
%start programa

%%

/*------------------------ Regras Sintáticas ------------------------*/

programa
    : declaracao_lista
    ;

declaracao_lista
    : declaracao_lista declaracao
    | declaracao
    ;

declaracao
    : var_declaracao
    | func_declaracao
    ;

var_declaracao
    : tipo_especificador IDENTIFIER SEMICOLON
    | tipo_especificador IDENTIFIER LEFT_BRACKET CONSTINT RIGHT_BRACKET SEMICOLON
    ;

tipo_especificador
    : INT
    | FLOAT
    | CHAR
    | VOID
    | STRUCT IDENTIFIER LEFT_BRACE atributos_declaracao RIGHT_BRACE
    ;

atributos_declaracao
    : atributos_declaracao var_declaracao
    | var_declaracao
    ;

func_declaracao
    : tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN composto_decl
    ;

params
    : params_lista
    | VOID
    ;

params_lista
    : params_lista COMMA param
    | param
    ;

param
    : tipo_especificador IDENTIFIER
    | tipo_especificador IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
    ;

composto_decl
    : LEFT_BRACE local_declaracoes comando_lista RIGHT_BRACE
    ;

local_declaracoes
    : local_declaracoes var_declaracao
    | /* vazio */
    ;

comando_lista
    : comando_lista comando
    | /* vazio */
    ;

comando
    : expressao_decl
    | composto_decl
    | selecao_decl
    | iteracao_decl
    | retorno_decl
    ;

expressao_decl
    : expressao SEMICOLON
    | SEMICOLON
    ;

selecao_decl
    : IF LEFT_PAREN expressao RIGHT_PAREN comando
    | IF LEFT_PAREN expressao RIGHT_PAREN comando ELSE comando
    ;

iteracao_decl
    : WHILE LEFT_PAREN expressao RIGHT_PAREN comando
    ;

retorno_decl
    : RETURN SEMICOLON
    | RETURN expressao SEMICOLON
    ;

expressao
    : var ASSIGN_OP expressao
    | expressao_simples
    ;

expressao_simples
    : expressao_soma relacional expressao_soma
    | expressao_soma
    ;

relacional
    : LESS_EQUAL_OP
    | RIGHT_EQUAL_OP
    | EQUAL_OP
    | NOT_EQUAL_OP
    | LEFT_OP
    | RIGHT_OP
    ;

expressao_soma
    : expressao_soma soma termo
    | termo
    ;

soma
    : PLUS
    | MINUS
    ;

termo
    : termo multi fator
    | fator
    ;

multi
    : MULTIPLY
    | DIVISION
    ;

fator
    : LEFT_PAREN expressao RIGHT_PAREN
    | var
    | ativacao
    | CONSTINT
    | CONSTFLOAT
    | CONSTCHAR
    | CONSTSTRING
    ;

ativacao
    : IDENTIFIER LEFT_PAREN args RIGHT_PAREN
    ;

args
    : arg_lista
    | /* vazio */
    ;

arg_lista
    : arg_lista COMMA expressao
    | expressao
    ;

var
    : IDENTIFIER
    | IDENTIFIER indice
    ;

indice
    : indice LEFT_BRACKET expressao RIGHT_BRACKET
    | LEFT_BRACKET expressao RIGHT_BRACKET
    ;

%%

/*------------------------ Funções auxiliares ------------------------*/

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático na linha %d, coluna %d: %s\n", line_number, column_number, s);
}