%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>

    void yyerror(const char *s);
    int yylex();
    
    // Estrutura da tabela de símbolos
    typedef struct {
        char nome[64];
        char tipo[16]; // "int", "float", "char", "string"
    } Simbolo;

    Simbolo tabela[100];
    int tabela_index = 0;

    void insere_simbolo(const char *nome, const char *tipo);
    const char* busca_tipo(const char *nome);
    void yyerror(const char *s);
    int yylex();
%}

/* Declaração dos tokens (precisa bater com os retornos do léxico) */
%token IF ELSE WHILE RETURN
%token INT FLOAT CHAR VOID STRUCT
%token IDENTIFIER CONSTINT CONSTFLOAT CONSTCHAR CONSTSTRING
%token ASSIGN_OP 
%token PLUS MINUS MULTIPLY DIVISION
%token LEFT_OP RIGHT_OP EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP RIGHT_EQUAL_OP
%token LEFT_BRACE RIGHT_BRACE
%token LEFT_BRACKET RIGHT_BRACKET
%token LEFT_PAREN RIGHT_PAREN
%token SEMICOLON COMMA

/* Definição de precedência e associatividade para resolver conflitos */
%left PLUS MINUS
%left MULTIPLY DIVISION
%nonassoc LEFT_OP RIGHT_OP LESS_EQUAL_OP RIGHT_EQUAL_OP EQUAL_OP NOT_EQUAL_OP

/* Definir o símbolo inicial */
%start programa

%union {
    char nome[64];   // Para nomes de variáveis e identificadores
    char tipo[16];   // Para tipos de dados ("int", "float", etc.)
}

%token <nome> IDENTIFIER
%token <tipo> INT FLOAT CHAR STRING

%type <tipo> tipo_especificador
%type <tipo> expressao expressao_simples termo fator


/*----------------- Funções Auxiliares -----------------*/

void insere_simbolo(const char *nome, const char *tipo) {
    for (int i = 0; i < tabela_index; i++) {
        if (strcmp(tabela[i].nome, nome) == 0) {
            printf("Erro Semântico: Variável '%s' já foi declarada.\n", nome);
            return;
        }
    }
    strcpy(tabela[tabela_index].nome, nome);
    strcpy(tabela[tabela_index].tipo, tipo);
    tabela_index++;
}

const char* busca_tipo(const char *nome) {
    for (int i = 0; i < tabela_index; i++) {
        if (strcmp(tabela[i].nome, nome) == 0) {
            return tabela[i].tipo;
        }
    }
    printf("Erro Semântico: Variável '%s' não declarada.\n", nome);
    return NULL;
}

void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}


%%

/*----------------- Regras de Produção -----------------*/

programa:
    declaracao_lista
;

declaracao_lista:
    declaracao_lista declaracao
    | declaracao
;

declaracao:
    var_declaracao
    | func_declaracao
;

var_declaracao:
    tipo_especificador IDENTIFIER SEMICOLON
    | tipo_especificador IDENTIFIER LEFT_BRACKET CONSTINT RIGHT_BRACKET SEMICOLON
;

tipo_especificador:
    INT
    | FLOAT
    | CHAR
    | VOID
    | STRUCT IDENTIFIER LEFT_BRACE atributos_declaracao RIGHT_BRACE
;

atributos_declaracao:
    atributos_declaracao var_declaracao
    | var_declaracao
;

func_declaracao:
    tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN composto_decl
;

params:
    param_lista
    | VOID
;

param_lista:
    param_lista COMMA param
    | param
;

param:
    tipo_especificador IDENTIFIER
    | tipo_especificador IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
;

composto_decl:
    LEFT_BRACE local_declaracoes comando_lista RIGHT_BRACE
;

local_declaracoes:
    local_declaracoes var_declaracao
    | /* vazio */
;

comando_lista:
    comando_lista comando
    | /* vazio */
;

comando:
    expressao_decl
    | composto_decl
    | selecao_decl
    | iteracao_decl
    | retorno_decl
;

expressao_decl:
    expressao SEMICOLON
    | SEMICOLON
;

selecao_decl:
    IF LEFT_PAREN expressao RIGHT_PAREN comando
    | IF LEFT_PAREN expressao RIGHT_PAREN comando ELSE comando
;

iteracao_decl:
    WHILE LEFT_PAREN expressao RIGHT_PAREN comando
;

retorno_decl:
    RETURN SEMICOLON
    | RETURN expressao SEMICOLON
;

/* EXPRESSÕES */

expressao:
    var ASSIGN_OP expressao
    | expressao_simples
;

var:
    IDENTIFIER
    | IDENTIFIER LEFT_BRACKET expressao RIGHT_BRACKET
;

expressao_simples:
    expressao_soma relacional expressao_soma
    | expressao_soma
;

relacional:
    LEFT_OP
    | RIGHT_OP
    | LESS_EQUAL_OP
    | RIGHT_EQUAL_OP
    | EQUAL_OP
    | NOT_EQUAL_OP
;

expressao_soma:
    expressao_soma soma termo
    | termo
;

soma:
    PLUS
    | MINUS
;

termo:
    termo multi fator
    | fator
;

multi:
    MULTIPLY
    | DIVISION
;

fator:
    LEFT_PAREN expressao RIGHT_PAREN
    | var
    | ativacao
    | CONSTINT
    | CONSTFLOAT
    | CONSTCHAR
;

ativacao:
    IDENTIFIER LEFT_PAREN args RIGHT_PAREN
;

args:
    arg_lista
    | /* vazio */
;

arg_lista:
    arg_lista COMMA expressao
    | expressao
;

%%


/* --------------- Funções auxiliares --------------- */
void yyerror(const char *s) {
    fprintf(stderr, "Erro de sintaxe: %s\n", s);
}