%{
    #include <stdio.h>
    #include <stdlib.h>
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

    // Tipo atual usado em uma declaração
    DataType current_type;
%}

    %union {
        int intval;
        float floatval;
        char charval;
        char* id;
        DataType type;
        Symbol* symbol;
    }

/*------------------------ Tokens ------------------------*/
%token IF ELSE WHILE RETURN
%token INT FLOAT CHAR VOID STRUCT

%token PLUS MINUS DIVISION MULTIPLY
%token EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP RIGHT_EQUAL_OP LEFT_OP RIGHT_OP
%token ASSIGN_OP

%token LEFT_BRACE RIGHT_BRACE
%token LEFT_BRACKET RIGHT_BRACKET
%token LEFT_PAREN RIGHT_PAREN

%token SEMICOLON COMMA

%token CONSTINT CONSTFLOAT CONSTCHAR CONSTSTRING
%token <id> IDENTIFIER
%type <type> tipo_especificador
%type <symbol> var

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
        if (!insert_symbol($2, $1)) {
            printf("Erro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
        }
    }
    | tipo_especificador IDENTIFIER arrayDimensao SEMICOLON
    | tipo_especificador IDENTIFIER ASSIGN_OP error SEMICOLON
    { erro_sintatico_previsto("Erro Sintático: Inicialização de variável não suportada nesta linguagem"); yyerrok; }
    | tipo_especificador IDENTIFIER error SEMICOLON 
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); yyerrok; }
    | tipo_especificador error SEMICOLON
    { erro_sintatico_previsto("Erro Sintático: Declaração de variável inválida"); yyerrok; }
    ;

arrayDimensao
    : LEFT_BRACKET CONSTINT RIGHT_BRACKET arrayDimensao
    | LEFT_BRACKET CONSTINT RIGHT_BRACKET
    | LEFT_BRACKET error RIGHT_BRACKET
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); yyerrok; }
    | LEFT_BRACKET error RIGHT_BRACKET arrayDimensao
    { erro_sintatico_previsto("Erro Sintático: Dimensao do array invalida"); yyerrok; }
    ; 

/*----- 5° -----*/
tipo_especificador
    : INT
        {   $$ = TYPE_INT;      }
    | FLOAT
        {   $$ = TYPE_FLOAT;    }
    | CHAR
        {   $$ = TYPE_CHAR;     }
    | VOID
        {   $$ = TYPE_VOID;     }
    | STRUCT IDENTIFIER LEFT_BRACE varDeclList RIGHT_BRACE
        {   $$ = TYPE_STRUCT;   }
    | STRUCT error LEFT_BRACE varDeclList RIGHT_BRACE
    { erro_sintatico_previsto("Erro Sintático: Nome de struct ausente"); $$ = TYPE_STRUCT; yyerrok; }
    ;

/*----- 6°: sequência de declarações de variáveis -----*/
varDeclList
    : var_declaracao
    | var_declaracao varDeclList
    ;

/*----- 7° -----*/
func_declaracao
    : tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN composto_decl
    {
        if (!insert_symbol($2, KIND_FUNCTION, $1)) {
            printf("Erro Semântico: Função '%s' já declarada (linha %d).\n", $2, line_number);
        } else {
            // Aqui você pode armazenar os parâmetros na symbol->data.func_info.params
            // Isso pode exigir adaptação da função de inserção
        }
    }
    | tipo_especificador error LEFT_PAREN params RIGHT_PAREN composto_decl
    { erro_sintatico_previsto("Erro Sintático: Função inexistente ou invalida apos o tipo de retorno"); yyerrok; }
    | tipo_especificador IDENTIFIER LEFT_PAREN error RIGHT_PAREN composto_decl
    { erro_sintatico_previsto("Erro Sintático: Lista de parâmetros malformada na declaração de função"); yyerrok; }
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
    { erro_sintatico_previsto("Erro Sintático: Falta de abrir colchetes"); yyerrok; }
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
                printf("Erro Semântico: Tipos incompatíveis na atribuição (linha %d).\n", line_number);
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
    { $$ = cria_symbol_temporario(TYPE_FLOAT); }
    | CONSTINT
    { $$ = cria_symbol_temporario(TYPE_INT); }
    | CONSTCHAR
    { $$ = cria_symbol_temporario(TYPE_CHAR);}
    | CONSTSTRING
    | LEFT_PAREN error RIGHT_PAREN
    { erro_sintatico_previsto("Erro Sintático: Expressao Vazia"); yyerrok; }
    ;

/*----- 25° -----*/
ativacao
    : IDENTIFIER LEFT_PAREN args RIGHT_PAREN
    {
        Symbol* s = lookup_symbol($1);
        if (!s) {
            printf("Erro Semântico: Função '%s' usada sem declaração (linha %d, coluna %d).\n", $1, line_number, column_number);
        } else if (s->kind != KIND_FUNCTION) {
            printf("Erro Semântico: '%s' não é uma função (linha %d, coluna %d).\n", $1, line_number, column_number);
        }
    }
    | IDENTIFIER LEFT_PAREN error RIGHT_PAREN
    { erro_sintatico_previsto("Erro Sintático: Argumentos invalidos no retorno da funcao"); yyerrok; }
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
    { erro_sintatico_previsto("Erro Sintático: Falta de parametro"); yyerrok; }
    | arg_lista COMMA error
    { erro_sintatico_previsto("Erro Sintático: Virgula excedente ao final da lista de parametros"); yyerrok; }
    ;

/*----- 28° -----*/
var
    : IDENTIFIER
    {
        Symbol* s = lookup_symbol($1);
        if (!s) {
            printf("Erro Semântico: Variável '%s' usada sem declaração (linha %d, coluna %d).\n", $1, line_number, column_number);
        } else if (s->kind != KIND_VARIABLE) {
            printf("Erro Semântico: '%s' não é uma variável (linha %d, coluna %d).\n", $1, line_number, column_number);
        }
        $$ = s;
    }
    | IDENTIFIER LEFT_BRACKET expressao RIGHT_BRACKET var_auxiliar
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

    fclose(compiled_arq);
    return 0;
}