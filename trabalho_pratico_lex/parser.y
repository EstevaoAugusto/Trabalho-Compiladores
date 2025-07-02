%code requires {
    #include "tabelaSimbolos.h"
}
 
%{
    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include "tabelaSimbolos.h"

    extern FILE *yyin;
    extern int yylex();
    extern int yyparse();

    extern int line_number;
    extern int column_number;

    extern int lexical_errors;
    int syntax_errors = 0;
    int semantic_errors = 0;


    void yyerror(const char *s);
    void erro_sintatico_previsto(const char *msg);

%}


%union {
    int intval;
    float floatval;
    char charval;
    char id;
    char sval;
    DataType type;
    Symbol* symbol;
    Dimension* dim;
    Param* param;
    HashTable* members;
}

/*------------------------ Tokens ------------------------*/
%token IF ELSE WHILE RETURN
%token <param> INT FLOAT CHAR VOID STRUCT

%token <charval>PLUS MINUS DIVISION MULTIPLY
%token <sval> EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP RIGHT_EQUAL_OP LEFT_OP RIGHT_OP
%token <charval> ASSIGN_OP

%token LEFT_BRACE RIGHT_BRACE
%token LEFT_BRACKET RIGHT_BRACKET
%token LEFT_PAREN RIGHT_PAREN

%token SEMICOLON COMMA

%token <intval>CONSTINT <floatval>CONSTFLOAT <charval>CONSTCHAR <id>CONSTSTRING
%token <id> IDENTIFIER

%type <sval> relacional
%type <symbol> var var_declaracao tipo_especificador func_declaracao ativacao
%type <dim> arrayDimensao
%type <param> params param params_lista
%type <members> varDeclList

/*------------------------ Precedências ------------------------*/

%left PLUS
%left MULTIPLY
%right ASSIGN_OP
%left EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP
%left  RIGHT_EQUAL_OP LEFT_OP RIGHT_OP
%nonassoc LOWER_THAN_ELSE
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
    | declaracao_lista error SEMICOLON
    { erro_sintatico_previsto("Erro Sintático: Declaracao mal formada e não reconhecida"); yyerrok; }
    ;

/*----- 3° -----*/
declaracao
    : func_declaracao
    | var_declaracao
    ;

/*----- 4° -----*/
var_declaracao
    : tipo_especificador IDENTIFIER SEMICOLON
    {
        if($1 == NULL){
            printf("Erro Semântico: Declaração de struct possui erro sintático (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if($1.kind == KIND_STRUCT_DEF){
            if(!insert_struct_def($1->name, $1->struct_info.members)){
                printf("Erro Semântico: Struct '%s' já foi declarada (linha %d, coluna %d).\n", $1.name, line_number, column_number);
                semantic_errors++;
            } else if(strcmp($1->name, $2)  == 0){
                printf("Erro Semântico: O identificador '%s' é o mesmo da struct declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
                semantic_errors++;
            } else {
                insert_variable($2, TYPE_STRUCT, $1.name);
            }
        } else if (!insert_variable($2, $1->var_info.type, NULL)) {
            printf("Erro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
            semantic_errors++;
        }
    }
    | tipo_especificador IDENTIFIER arrayDimensao SEMICOLON
    {
        if($1 == NULL){
            printf("Erro Semântico: Declaração de struct possui erro sintático (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if($1->kind == KIND_STRUCT_DEF){
            if(!insert_struct_def($1->name, $1->struct_info.members)){
                printf("Erro Semântico: Struct '%s' já foi declarada (linha %d, coluna %d).\n", $1->name, line_number, column_number);
                semantic_errors++;
            } else if(strcmp($1->name, $2) == 0){
                printf("Erro Semântico: O identificador '%s' é o mesmo da struct declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
                semantic_errors++;
            } else {
                insert_array($2, TYPE_STRUCT, $1->struct_info.members, $3);
            }
        } else if (!insert_array($2, $1->var_info.type, NULL, $3)) {
            printf("Erro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
            semantic_errors++;
        }
    }
    | tipo_especificador IDENTIFIER ASSIGN_OP error SEMICOLON
    { erro_sintatico_previsto("Erro Sintático: Inicialização de variável não suportada nesta linguagem"); $$ = NULL; yyerrok; }
    | tipo_especificador IDENTIFIER error SEMICOLON 
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); $$ = NULL; yyerrok; }
    | tipo_especificador error SEMICOLON
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); $$ = NULL; yyerrok;  }
    ;

arrayDimensao
    : LEFT_BRACKET CONSTINT RIGHT_BRACKET arrayDimensao
    {
        if($2 > 0){
            $$ = new_dimension($2, $4);
        } else {
            printf("Erro Semântico: Vetor com tamanho 0 é invalido (linha %d, coluna %d).\n", $2, line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        }
    }
    | LEFT_BRACKET CONSTINT RIGHT_BRACKET
    {
        if($2 > 0){
            $$ = new_dimension($2, NULL);
        } else {
            printf("Erro Semântico: Vetor com tamanho 0 é invalido (linha %d, coluna %d).\n", $2, line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        }
    }
    | LEFT_BRACKET error RIGHT_BRACKET
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); $$ = NULL; yyerrok; }
    | LEFT_BRACKET error RIGHT_BRACKET arrayDimensao
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); $$ = NULL; yyerrok; }
    ; 

/*----- 5° -----*/
tipo_especificador
    : INT       
    {   
        $$ = cria_symbol_temporario(TYPE_INT, KIND_VARIABLE);
    }
    | FLOAT     
    {   
        $$ = cria_symbol_temporario(TYPE_FLOAT, KIND_VARIABLE);
    }
    | CHAR      
    {   
        $$ = cria_symbol_temporario(TYPE_CHAR, KIND_VARIABLE);
    }
    | VOID      
    {   
        $$ = cria_symbol_temporario(TYPE_VOID, KIND_VARIABLE);
    }
    | STRUCT IDENTIFIER LEFT_BRACE varDeclList RIGHT_BRACE
    {   
        $$ = cria_symbol_temporario(TYPE_VOID, KIND_STRUCT_DEF);
        $$->name = strdup($2);
        $$->struct_info.members = $4;  
    }
    | STRUCT error LEFT_BRACE varDeclList RIGHT_BRACE
    { erro_sintatico_previsto("Erro Sintático: Nome de struct ausente"); $$ = NULL;  yyerrok; }
    ;

/*----- 6°: sequência de declarações de variáveis -----*/
varDeclList
    : var_declaracao
    {
        $$ = initialize_hash_table();
        if(!insert_struct_member($1, $$)){
            printf("Erro Semântico: O identificador '%s' já existe dentro da struct (linha %d, coluna %d).\n", $1.name, line_number, column_number);
            semantic_errors++;
        }
    }
    | var_declaracao varDeclList
    {
        $$ = $2;
        if(!insert_struct_member($1, $$)){
            printf("Erro Semântico: O identificador '%s' já existe dentro da struct (linha %d, coluna %d).\n", $1.name, line_number, column_number);
            semantic_errors++;
        }
    }
    ;

/*----- 7° -----*/
func_declaracao
    : tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN abre_escopo_funcao composto_decl
    {
        if($1 == NULL || $1->kind == KIND_STRUCT_DEF){
            printf("Erro Semântico: Struct nao é aceito como tipo de retorno (linha %d, coluna %d).\n", $2, line_number, column_number);
            semantic_errors++;
        } else if(!insert_function($2, $1->type, NULL, $4)){
            printf("Erro Semântico: Função '%s' já declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
            semantic_errors++;
        }
    }
    | tipo_especificador error LEFT_PAREN params RIGHT_PAREN composto_decl
    { erro_sintatico_previsto("Erro Sintático: Função inexistente ou invalida apos o tipo de retorno"); $$ = NULL; yyerrok; }
    | tipo_especificador IDENTIFIER LEFT_PAREN error RIGHT_PAREN composto_decl
    { erro_sintatico_previsto("Erro Sintático: Lista de parâmetros malformada na declaração de função"); $$ = NULL; yyerrok; }
    ;

abre_escopo_funcao 
    :       { open_scope(); }
    ;

/*----- 8° -----*/
params
    : params_lista
    {
        $$ = $1;
    }
    | VOID
    {
        $$ = NULL;
    }
    ;

/*----- 9° -----*/
params_lista
    : param
    {
        $$ = $1;
    }
    | param COMMA params_lista
    {
        $1->next = $3;
        $$ = $1;
    }
    ;

/*----- 10° -----*/
param
    : tipo_especificador IDENTIFIER
    {
        if($1 == NULL || $1->kind == KIND_STRUCT_DEF){
            printf("Erro Semântico: Struct não pode ser utilizado como tipo de retorno (linha %d, coluna %d).", $1.name, line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else {
            $$ = create_param($1->name, $1->var_info.type, $1->var_info.is_array);
        }
    }
    | tipo_especificador IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
    {
        if($1 == NULL || $1->kind == KIND_STRUCT_DEF){
            printf("Erro Semântico: Struct não pode ser utilizado como tipo de retorno (linha %d, coluna %d).", $1.name, line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else {
            $$ = create_param($1->name, $1->var_info.type, $1->var_info.is_array);
        }
    }
    | tipo_especificador IDENTIFIER error RIGHT_BRACKET
    { erro_sintatico_previsto("Erro Sintático: Falta de abrir colchetes"); $$ = NULL; yyerrok; }
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
    { erro_sintatico_previsto("Erro Sintático: Comando invalido sintaticamente ou incompleto"); yyerrok; }
    ;

/*----- 15° -----*/
expressao_decl
    : expressao SEMICOLON
    | SEMICOLON
    ;

selecao_decl
    : IF LEFT_PAREN expressao RIGHT_PAREN comando %prec LOWER_THAN_ELSE
    | IF LEFT_PAREN expressao RIGHT_PAREN comando ELSE comando
    | IF LEFT_PAREN error RIGHT_PAREN comando
    { erro_sintatico_previsto("Erro Sintático: Condição errada no comando IF"); yyerrok;}
    ;

/*----- 17° -----*/
iteracao_decl
    : WHILE LEFT_PAREN expressao RIGHT_PAREN comando
    | WHILE LEFT_PAREN error RIGHT_PAREN comando
    { erro_sintatico_previsto("Erro Sintático: Comando WHILE invalido"); yyerrok; }
    ;

/*----- 18° -----*/
retorno_decl
    : RETURN SEMICOLON
    | RETURN expressao SEMICOLON
    | RETURN error SEMICOLON
    { erro_sintatico_previsto("Erro Sintático: Retorno invalido"); yyerrok;}
    ;

/*----- 19° -----*/
expressao
    : var ASSIGN_OP expressao
    {
        if ($1 && $3) {
            DataType tipo_var = $1->data.var_info.type;
            DataType tipo_expr = $3->data.var_info.type;

            if (tipo_var != tipo_expr) {
                printf("Erro Semântico: Tipos incompatíveis na atribuição (linha %d, coluna %d).\n", line_number, column_number);
                semantic_erros++;
            }
        }
    }
    | var ASSIGN_OP error
    { erro_sintatico_previsto("Erro Sintático: Atribuição sem expressão à direita"); yyerrok; }
    | expressao_simples
    ;

/*----- 20° -----*/
expressao_simples
    : exp_soma relacional exp_soma
    {

    }
    | exp_soma
    ;

/*----- 21° -----*/
relacional
    : LEFT_OP           {   $$ = $1;    }
    | RIGHT_OP          {   $$ = $1;    }
    | LESS_EQUAL_OP     {   $$ = $1;    }
    | RIGHT_EQUAL_OP    {   $$ = $1;    }
    | EQUAL_OP          {   $$ = $1;    }
    | NOT_EQUAL_OP      {   $$ = $1;    }
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
    { erro_sintatico_previsto("Erro Sintático: Operação de '*' sem o fator"); yyerrok; }
    | termo DIVISION fator error 
    { erro_sintatico_previsto("Erro Sintático: Operação de '/' sem o fator"); yyerrok; }
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
    { erro_sintatico_previsto("Erro Sintático: Expressao Vazia"); yyerrok; }
    ;

/*----- 25° -----*/
ativacao
    : IDENTIFIER LEFT_PAREN args RIGHT_PAREN
    {
        $$ = lookup_symbol($1);
        if(!$$){
            printf("Erro Semântico: Função '%s' foi chamada sem ser declarada (linha %d, coluna %d).", $1, line_number, column_number);
            semantic_errors++;
        }
    }
    | IDENTIFIER LEFT_PAREN error RIGHT_PAREN
    { erro_sintatico_previsto("Erro Sintático: Argumentos invalidos no retorno da funcao"); $$ = NULL; yyerrok; }
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
    { erro_sintatico_previsto("Erro Sintático: Falta de parametro"); yyerrok; $$ = NULL; }
    | arg_lista COMMA error
    { erro_sintatico_previsto("Erro Sintático: Virgula excedente ao final da lista de parametros"); yyerrok; $$ = NULL; }
    ;

/*----- 28° -----*/
var
    : IDENTIFIER
    {
        $$ = lookup_symbol($1);
        if(!$$){
            printf("Erro: Identificador '%s' não foi declarado (linha %d, coluna %d).\n", $1, line_number, height_number);
            semantic_errors++;
        }
    }
    | IDENTIFIER LEFT_BRACKET expressao RIGHT_BRACKET var_auxiliar
    {
        $$ = lookup_symbol($1);
        if(!$$){
            printf("Erro: Identificador '%s' não foi declarado (linha %d, coluna %d).\n", $1, line_number, height_number);
            semantic_errors++;
        }
    }
    ;

/*---- 29° ----*/

var_auxiliar
    : var_auxiliar LEFT_BRACKET expressao RIGHT_BRACKET
    |
    ;

%%


/*------------------------ Funções auxiliares ------------------------*/

void yyerror(const char *s) {
    fprintf(stderr, "Erro na linha %d, coluna %d: %s\n", line_number, column_number, s);
}

void erro_sintatico_previsto(const char *msg) {
    syntax_errors++;
    fprintf(stderr, "%s na linha %d, coluna %d\n\n", msg, line_number, column_number);
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

    init_scope_stack();
    yyin = compiled_arq;
    int result = yyparse();

    printf("\n=== Resultado da Análise ===\n");
    if (result == 0) {
        printf("ANALISE SINTATICA CONCLUIDA COM SUCESSO!\n");
    } else {
        printf("ANALISE SINTATICA FALHOU DEVIDO A ERROS!\n");
    }

    printf("Total de erros léxicos: %d\n", lexical_errors);
    printf("Total de erros sintáticos: %d\n", syntax_errors);
    printf("Total de erros semânticos: %d\n", semantic_errors);

    fclose(compiled_arq);
    destroy_scope_stack();
    return 0;
}