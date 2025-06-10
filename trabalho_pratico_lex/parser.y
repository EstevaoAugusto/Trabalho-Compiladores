%{
    #include <stdio.h>
    #include <stdlib.h>

    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();

    extern int line_number;
    extern int column_number;

    void yyerror(const char *s);
    void msg_erro(const char *msg);
    int syntax_error = 0;
%}

/*------------------------ Tokens ------------------------*/
%token IF ELSE WHILE RETURN
%token INT FLOAT CHAR
%token VOID STRUCT

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
%left EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP RIGHT_EQUAL_OP LEFT_OP RIGHT_OP


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
    | tipo_especificador IDENTIFIER error
    { msg_erro("ERRO: Declaracao de variavel invalida"); yyerrok; }
    ;

arrayDimensao
    : LEFT_BRACKET CONSTINT RIGHT_BRACKET arrayDimensao
    | LEFT_BRACKET CONSTINT RIGHT_BRACKET
    | LEFT_BRACKET error RIGHT_BRACKET
    { msg_erro("ERRO: Dimensao do array invalida"); yyerrok; }
    ; 

/*----- 5° -----*/
tipo_especificador
    : INT
    | FLOAT
    | CHAR
    | VOID
    | STRUCT IDENTIFIER LEFT_BRACE varDeclList RIGHT_BRACE SEMICOLON
    ;

/*----- 6°: sequência de declarações de variáveis -----*/
varDeclList
    : var_declaracao
    | var_declaracao varDeclList
    ;

/*----- 7° -----*/
func_declaracao
    : tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN composto_decl
    | tipo_especificador IDENTIFIER LEFT_PAREN params error RIGHT_PAREN composto_decl
    { msg_erro("ERRO: Função inexistente ou invalida apos o tipo de retorno"); yyerrok; }
    | tipo_especificador IDENTIFIER LEFT_PAREN error RIGHT_PAREN composto_decl
    { msg_erro("ERRO: Lista de parametros malformada na declaracao de funcao"); yyerrok; }
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
    { msg_erro("ERRO: Falta de abrir colchetes"); yyerrok; }
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
    : comando comando_lista
    | /* vazio */
    ;

/*----- 14° -----*/
comando
    : expressao_decl
    | composto_decl
    | iteracao_decl
    | retorno_decl
    ;

/*----- 15° -----*/
expressao_decl
    : expressao SEMICOLON
    | SEMICOLON
    ;

/*----- 17° -----*/
iteracao_decl
    : WHILE LEFT_PAREN expressao RIGHT_PAREN comando
    | WHILE LEFT_PAREN error RIGHT_PAREN
    { msg_erro("ERRO: Comando WHILE invalido"); yyerrok; }
    ;

/*----- 18° -----*/
retorno_decl
    : RETURN SEMICOLON
    | RETURN expressao SEMICOLON
    | RETURN error SEMICOLON
    { msg_erro("ERRO: Retorno invalido"); yyerrok; }
    ;

/*----- 19° -----*/
expressao
    : var ASSIGN_OP expressao
    | expressao_simples
    ;

/*----- 20° -----*/
expressao_simples
    : expressao_soma relacional expressao_soma
    | expressao_soma
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

/*----- 22° -----*/
expressao_soma
    : termo
    | termo exp_soma
    | error exp_soma
    { msg_erro("ERRO: Expressao invalida, falta um operador ou operando"); yyerrok; }
    ;

/*----- 23°: Operação de Soma mesmo -----*/
exp_soma
    : PLUS termo
    | PLUS termo exp_soma
    ;

termo
    : fator termo_auxiliar
    | fator
    ;

termo_auxiliar
    : MULTIPLY fator
    | MULTIPLY fator termo_auxiliar
    ;

/*----- 24° -----*/
fator
    : LEFT_PAREN expressao RIGHT_PAREN
    | var
    | ativacao
    | CONSTINT
    | CONSTFLOAT
    | CONSTCHAR
    | CONSTSTRING
    | LEFT_PAREN error RIGHT_PAREN
    { msg_erro("ERRO: Expressao Vazia"); yyerrok; }
    ;

/*----- 25° -----*/
ativacao
    : IDENTIFIER LEFT_PAREN args RIGHT_PAREN
    | IDENTIFIER LEFT_PAREN error RIGHT_PAREN
    { msg_erro("ERRO: Argumentos invalidos no retorno da funcao"); yyerrok; }
    ;

/*----- 26° -----*/
args
    : arg_lista
    | /* vazio */
    ;

/*----- 27° -----*/
arg_lista
    : expressao COMMA arg_lista 
    | expressao
    ;

/*----- 28° -----*/
var
    : IDENTIFIER
    | IDENTIFIER var_auxiliar
    ;

var_auxiliar
    : LEFT_BRACKET expressao RIGHT_BRACKET
    | LEFT_BRACKET expressao RIGHT_BRACKET var_auxiliar
    | LEFT_BRACKET error RIGHT_BRACKET
    { msg_erro("ERRO: Acesso invalido do array"); yyerrok; }
    ;

%%

/*------------------------ Funções auxiliares ------------------------*/

void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d, coluna %d:\n", line_number, column_number);
    syntax_error++;
}

void msg_erro(const char *msg) {
    fprintf(stderr, "ATENCAO: %s\n\n", msg);
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
    yyparse();

    if (syntax_error == 0) {
        printf("ANALISE SINTATICA CONCLUIDA!\n");
    } else {
        printf("ANALISE SINTATICA CONCLUIDA COM ERROS!!!\n");
        printf("Foram encontrados %d erro(s) sintatico(s).\n", syntax_error);
    }

    fclose(compiled_arq);
    return 0;
}