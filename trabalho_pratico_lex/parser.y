%{
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
    void msg_erro(const char *msg, int line, int column);
%}

/*------------------------ Tokens ------------------------*/
%token IF ELSE WHILE RETURN
%token INT FLOAT CHAR VOID STRUCT

%token PLUS MINUS DIVISION
%token EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP RIGHT_EQUAL_OP LEFT_OP RIGHT_OP
%token ASSIGN_OP

%token LEFT_BRACE RIGHT_BRACE
%token LEFT_BRACKET RIGHT_BRACKET
%token LEFT_PAREN RIGHT_PAREN

%token SEMICOLON COMMA

%token CONSTINT CONSTFLOAT CONSTCHAR CONSTSTRING
%token IDENTIFIER

/*------------------------ Precedências ------------------------*/

%left PLUS
%left MULTIPLY
%right ASSIGN_OP
%left EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP
%left  RIGHT_EQUAL_OP LEFT_OP RIGHT_OP
%nonassoc "then"
%nonassoc ELSE

%%

/*------------------------ Regras Sintáticas ------------------------*/

/*----- 1° -----*/
programa
    : declaracao_lista
    ;

/*----- 2° -----*/
declaracao_lista
    : declaracao
    | declaracao_lista declaracao
    ;

/*----- 3° -----*/
declaracao
    : func_declaracao
    | var_declaracao
    ;

/*----- 4° -----*/
var_declaracao
    : tipo_especificador IDENTIFIER SEMICOLON
    | tipo_especificador IDENTIFIER arrayDimensao SEMICOLON
    | STRUCT IDENTIFIER LEFT_BRACE varDeclList RIGHT_BRACE SEMICOLON
    | tipo_especificador IDENTIFIER error SEMICOLON
    { msg_erro("ERRO: Declaracao de variavel invalida", line_number, column_number); yyerrok; }
    | tipo_especificador error SEMICOLON
    { msg_erro("ERRO: Declaracao de variavel invalida", line_number, column_number); yyerrok; }
    ;

arrayDimensao
    : LEFT_BRACKET CONSTINT RIGHT_BRACKET arrayDimensao
    | LEFT_BRACKET CONSTINT RIGHT_BRACKET
    | LEFT_BRACKET error RIGHT_BRACKET
    { msg_erro("ERRO: Dimensao do array invalida", line_number, column_number); yyerrok; }
    ; 

/*----- 5° -----*/
tipo_especificador
    : INT
    | FLOAT
    | CHAR
    | VOID
    | STRUCT IDENTIFIER LEFT_BRACE varDeclList RIGHT_BRACE
    ;

/*----- 6°: sequência de declarações de variáveis -----*/
varDeclList
    : var_declaracao
    | var_declaracao varDeclList
    ;

/*----- 7° -----*/
func_declaracao
    : tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN composto_decl
    | tipo_especificador error LEFT_PAREN params RIGHT_PAREN composto_decl
    { msg_erro("ERRO: Função inexistente ou invalida apos o tipo de retorno", line_number, column_number); yyerrok; }
    | tipo_especificador IDENTIFIER LEFT_PAREN error RIGHT_PAREN composto_decl
    { msg_erro("ERRO: Lista de parâmetros malformada na declaração de função", line_number, column_number); yyerrok; }
    ;

/*----- 8° -----*/
params
    : params_lista
    | VOID
    ;

/*----- 9° -----*/
params_lista
    : param
    | param COMMA params_lista
    ;

/*----- 10° -----*/
param
    : tipo_especificador IDENTIFIER
    | tipo_especificador IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
    | tipo_especificador IDENTIFIER error RIGHT_BRACKET
    { msg_erro("ERRO: Falta de abrir colchetes", line_number, column_number); yyerrok; }
    ;

/*----- 11° -----*/
composto_decl
    : LEFT_BRACE local_declaracoes comando_lista RIGHT_BRACE
    ;

/*----- 12° -----*/
local_declaracoes
    : local_declaracoes var_declaracao
    | /* vazio */
    ;

/*----- 13° -----*/
comando_lista
    : comando_lista comando
    | /* vazio */
    ;

/*----- 14° -----*/
comando
    : expressao_decl
    | composto_decl
    | selecao_decl
    | iteracao_decl
    | retorno_decl
    | error SEMICOLON
    { msg_erro("ERRO: Comando invalido sintaticamente ou incompleto", line_number, column_number); yyerrok; }
    ;

/*----- 15° -----*/
expressao_decl
    : expressao SEMICOLON
    | SEMICOLON
    ;

selecao_decl
    : IF LEFT_PAREN expressao RIGHT_PAREN comando %prec "then"
    | IF LEFT_PAREN expressao RIGHT_PAREN comando ELSE comando
    | IF LEFT_PAREN error RIGHT_PAREN comando
    { msg_erro("ERRO: Condição errada no comando IF", line_number, column_number); yyerrok;}

/*----- 17° -----*/
iteracao_decl
    : WHILE LEFT_PAREN expressao RIGHT_PAREN comando
    | WHILE LEFT_PAREN error RIGHT_PAREN comando
    { msg_erro("ERRO: Comando WHILE invalido", line_number, column_number); yyerrok; }
    ;

/*----- 18° -----*/
retorno_decl
    : RETURN SEMICOLON
    | RETURN expressao SEMICOLON
    | RETURN error SEMICOLON
    { msg_erro("ERRO: Retorno invalido", line_number, column_number); yyerrok;}
    ;

/*----- 19° -----*/
expressao
    : var ASSIGN_OP expressao
    | expressao_simples
    ;

/*----- 20° -----*/
expressao_simples
    : exp_soma relacional exp_soma
    | exp_soma
    ;

/*----- 21° -----*/
relacional
    : LEFT_OP
    | RIGHT_OP
    | LESS_EQUAL_OP
    | RIGHT_EQUAL_OP
    | EQUAL_OP
    | NOT_EQUAL_OP
    ;

/*----- 23°: Operação de Soma mesmo -----*/
exp_soma
    : termo
    | exp_soma PLUS termo
    | exp_soma MINUS termo
    ;

termo 
    : fator
    | termo MULTIPLY fator
    | termo DIVISION fator
    | termo MULTIPLY fator error
    { msg_erro("ERRO: Operação de '*' sem o fator", line_number, column_number); yyerrok; }
    | termo DIVISION fator error 
    { msg_erro("ERRO: Operação de '/' sem o fator", line_number, column_number); yyerrok; }
    ;

/*----- 24° -----*/
fator
    : LEFT_PAREN expressao RIGHT_PAREN
    | var
    | ativacao
    | CONSTFLOAT
    | CONSTINT
    | CONSTCHAR
    | CONSTSTRING
    | LEFT_PAREN error RIGHT_PAREN
    { msg_erro("ERRO: Expressao Vazia", line_number, column_number); yyerrok; }
    ;

/*----- 25° -----*/
ativacao
    : IDENTIFIER LEFT_PAREN args RIGHT_PAREN
    | IDENTIFIER LEFT_PAREN error RIGHT_PAREN
    { msg_erro("ERRO: Argumentos invalidos no retorno da funcao", line_number, column_number); yyerrok; }
    ;

/*----- 26° -----*/
args
    : arg_lista
    | 
    ;

/*----- 27° -----*/
arg_lista
    : expressao 
    | arg_lista COMMA expressao
    | arg_lista COMMA COMMA error
    { msg_erro("ERRO: Falta de parametro", line_number, column_number); yyerrok; }
    | arg_lista COMMA error
    { msg_erro("ERRO: Virgula excedente ao final da lista de parametros.", line_number, column_number); yyerrok; }
    ;

/*----- 28° -----*/
var
    : IDENTIFIER
    | IDENTIFIER LEFT_BRACKET expressao RIGHT_BRACKET var_auxiliar
    ;

/*---- 29° ----*/

var_auxiliar
    : var_auxiliar LEFT_BRACKET expressao RIGHT_BRACKET
    |
    ;

%%

/*---- 30° ----*/

/*
ident
    :
*/

/*---- 31° ----*/

/*
letra
    : a 
*/



/*------------------------ Funções auxiliares ------------------------*/

void yyerror(const char *s) {
    syntax_errors++;
    fprintf(stderr, "Erro na linha %d, coluna %d: %s\n", line_number, column_number, s);
}

void msg_erro(const char *msg, int line, int column) {
    fprintf(stderr, "%s na linha %d, coluna %d\n\n", msg, line, column);
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
        printf("ANALISE SINTATICA CONCLUIDA!\n");
    } else {
        printf("ANALISE SINTATICA CONCLUIDA COM ERROS!!!\n");
    }

    printf("Total de erros léxicos: %d\n", lexical_errors);
    printf("Total de erros sintáticos: %d\n", syntax_errors);

    fclose(compiled_arq);
    return 0;
}