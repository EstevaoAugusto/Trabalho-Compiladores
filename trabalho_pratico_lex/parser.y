%{
    #include <stdio.h>
    #include <stdlib.h>

    extern FILE *yyin;
    extern int yylex();
    extern int yyparse(void);
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

/*------------------------ Precedências ------------------------*/

%left PLUS MULTIPLY
%right UMINUS


%%

/*------------------------ Regras Sintáticas ------------------------*/

/*----- 1° -----*/
programa
    : declaracao_lista
    { printf("Redução: programa -> declaracao_Lista\n"); }
    ;

/*----- 2° -----*/
declaracao_lista
    : declaracao_lista declaracao
    { printf("Redução: declaracao_Lista -> declaracao\n"); }
    | declaracao_Lista declaracao
    { printf("Redução: declaracao_Lista -> declaracao_Lista declaracao\n"); }
    ;

/*----- 3° -----*/
declaracao
    : funDeclaracao
    { printf("Redução: declaracao -> funDeclaracao\n"); }
    | var_declaracao
    { printf("Redução: declaracao -> var_declaracao\n"); }
    ;

/*----- 4° -----*/
varDeclaracao
    : tipo_especificador IDENTIFIER SEMICOLON
    { printf("Redução: varDeclaracao -> tipo_especificador IDENTIFIER SEMICOLON\n"); }
    | tipo_especificador IDENTIFIER LEFT_BRACKET CONSTINT RIGHT_BRACKET SEMICOLON
    | STRUCT IDENTIFIER LEFT_BRACE varDeclList RIGHT_BRACE
    { printf("Redução: varDeclaracao -> tipo_especificador IDENTIFIER LEFT_BRACKET CONSTINT RIGHT_BRACKET arrayDimensao SEMICOLON\n"); }
    ;

arrayDimensao
    : LEFT_BRACKET CONSTINT RIGHT_BRACKET arrayDimensao
    { printf("Redução: arrayDimensao -> LEFT_BRACKET CONSTINT RIGHT_BRACKET arrayDimensao\n"); }
    | /* vazio */
    { printf("Redução: arrayDimensao -> ε\n"); }
    ; 

/*----- 5° -----*/
tipo_especificador
    : INT
    { printf("Redução: tipo_especificador -> INT\n"); }
    | FLOAT
    { printf("Redução: tipo_especificador -> FLOAT\n"); }
    | CHAR
    { printf("Redução: tipo_especificador -> CHAR\n"); }
    | VOID
    { printf("Redução: tipo_especificador -> VOID\n"); }
    ;

/*----- 6°: sequência de declarações de variáveis -----*/
varDeclList
    : varDeclaracao 
    { printf("Redução: varDeclList -> varDeclaracao\n"); }
    | varDeclaracao varDeclList
    { printf("Redução: varDeclList -> varDeclaracao varDeclList\n"); }
    ;

/*----- 7° -----*/
func_declaracao
    : tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN composto_decl
    { printf("Redução: func_declaracao -> tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN composto_decl\n"); }
    | error '\n' { printf("Redução: Erro na reducao para func_declaracao\n"); yyerrok;}
    ;

/*----- 8° -----*/
params
    : params_lista
    { printf("Redução: params -> params_lista\n"); }
    | VOID
    { printf("Redução: params -> VOID\n"); }
    ;

/*----- 9° -----*/
params_lista
    : param
    { printf("Redução: params_lista -> param\n"); }
    | params_lista COMMA param
    { printf("Redução: params_lista -> params_lista COMMA param\n"); }
    ;

/*----- 10° -----*/
param
    : tipo_especificador IDENTIFIER
    { printf("Redução: param -> tipo_especificador IDENTIFIER\n"); }
    | tipo_especificador IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
    { printf("Redução: param -> tipo_especificador IDENTIFIER LEFT_BRACKET RIGHT_BRACKET\n"); }
    ;

/*----- 11° -----*/
composto_decl
    : LEFT_BRACE local_declaracoes comando_lista RIGHT_BRACE
    { printf("Redução: composto_decl -> LEFT_BRACE local_declaracoes comando_lista RIGHT_BRACE\n"); }
    ;

/*----- 12° -----*/
local_declaracoes
    : local_declaracoes var_declaracao
    { printf("Redução: local_declaracoes -> local_declaracoes var_declaracao\n"); }
    | /* vazio */
    { printf("Redução: local_declaracoes -> ε\n"); }
    ;

/*----- 13° -----*/
comando_lista
    : comando_lista comando
    { printf("Redução: comando_lista -> comando_lista comando\n"); }
    | /* vazio */
    { printf("Redução: comando_lista -> ε\n"); }
    ;

/*----- 14° -----*/
comando
    : expressao_decl
    { printf("Redução: comando -> expressao_decl\n"); }
    | composto_decl
    { printf("Redução: comando -> composto_decl\n"); }
    | selecao_decl
    { printf("Redução: comando -> selecao_decl\n"); }
    | iteracao_decl
    { printf("Redução: comando -> iteracao_decl\n"); }
    | retorno_decl
    { printf("Redução: comando -> retorno_decl\n"); }
    ;

/*----- 15° -----*/
expressao_decl
    : expressao SEMICOLON
    { printf("Redução: expressao_decl -> expressao SEMICOLON\n"); }
    | SEMICOLON
    { printf("Redução: expressao_decl -> SEMICOLON\n"); }
    ;

/*----- 16° -----*/
selecao_decl
    : IF LEFT_PAREN expressao RIGHT_PAREN comando
    { printf("Redução: selecao_decl -> IF LEFT_PAREN expressao RIGHT_PAREN comando\n"); }
    | IF LEFT_PAREN expressao RIGHT_PAREN comando ELSE comando
    { printf("Redução: selecao_decl -> IF LEFT_PAREN expressao RIGHT_PAREN comando ELSE comando\n"); }
    ;

/*----- 17° -----*/
iteracao_decl
    : WHILE LEFT_PAREN expressao RIGHT_PAREN comando
    { printf("Redução: iteracao_decl -> WHILE LEFT_PAREN expressao RIGHT_PAREN comando\n"); }
    ;

/*----- 18° -----*/
retorno_decl
    : RETURN SEMICOLON
    { printf("Redução: retorno_decl -> RETURN SEMICOLON\n"); }
    | RETURN expressao SEMICOLON
    { printf("Redução: retorno_decl -> RETURN expressao SEMICOLON\n"); }
    ;

/*----- 19° -----*/
expressao
    : var ASSIGN_OP expressao
    { printf("Redução: expressao -> var ASSIGN_OP expressao\n"); }
    | expressao_simples
    { printf("Redução: expressao -> expressao_simples\n"); }
    ;

/*----- 20° -----*/
expressao_simples
    : expressao_soma relacional expressao_soma
    { printf("Redução: expressao_simples -> expressao_soma relacional expressao_soma\n"); }
    | expressao_soma
    { printf("Redução: expressao_simples -> expressao_soma\n"); }
    ;

/*----- 21° -----*/
relacional
    : LEFT_OP
    { printf("Redução: relacional -> LEFT_OP\n"); }
    | RIGHT_OP
    { printf("Redução: relacional -> RIGHT_OP\n"); }
    | LESS_EQUAL_OP
    { printf("Redução: relacional -> LESS_EQUAL_OP\n"); }
    | RIGHT_EQUAL_OP
    { printf("Redução: relacional -> RIGHT_EQUAL_OP\n"); }
    | EQUAL_OP
    { printf("Redução: relacional -> EQUAL_OP\n"); }
    | NOT_EQUAL_OP
    { printf("Redução: relacional -> NOT_EQUAL_OP\n"); }
    ;

/*----- 22° -----*/
expressao_soma
    : expressao_soma PLUS termo
    { printf("Redução: expressao_soma -> expressao_soma PLUS termo\n"); $$ = $1 + $3;}
    | termo
    { printf("Redução: expressao_soma -> termo\n"); }
    ;

/*----- 23° -----*/
termo
    : termo MULTIPLY fator
    { printf("Redução: termo -> termo MULTIPLY fator\n"); }
    | fator
    { printf("Redução: termo -> fator\n"); }
    ;

/*----- 24° -----*/
fator
    : LEFT_PAREN expressao RIGHT_PAREN
    { printf("Redução: fator -> LEFT_PAREN expressao RIGHT_PAREN\n"); $$ = $2;}
    | var
    { printf("Redução: fator -> var\n"); }
    | ativacao
    { printf("Redução: fator -> ativacao\n"); }
    | CONSTINT
    { printf("Redução: fator -> CONSTINT\n"); }
    | CONSTFLOAT
    { printf("Redução: fator -> CONSTFLOAT\n"); }
    | CONSTCHAR
    { printf("Redução: fator -> CONSTCHAR\n"); }
    | CONSTSTRING
    { printf("Redução: fator -> CONSTSTRING\n"); }
    | '-' fator %prec UMINUS
    { printf("Redução: fator -> - fator\n"); }
    ;

/*----- 25° -----*/
ativacao
    : IDENTIFIER LEFT_PAREN args RIGHT_PAREN
    { printf("Redução: ativacao -> IDENTIFIER LEFT_PAREN args RIGHT_PAREN\n"); }
    ;

/*----- 26° -----*/
args
    : arg_lista
    { printf("Redução: args -> arg_lista\n"); }
    | /* vazio */
    { printf("Redução: args -> ε\n"); }
    ;

/*----- 27° -----*/
arg_lista
    : arg_lista COMMA expressao
    { printf("Redução: arg_lista -> arg_lista COMMA expressao\n"); }
    | expressao
    { printf("Redução: arg_lista -> expressao\n"); }
    ;

/*----- 28° -----*/
var
    : IDENTIFIER
    { printf("Redução: var -> IDENTIFIER\n"); }
    | IDENTIFIER LEFT_BRACKET expressao RIGHT_BRACKET indice
    { printf("Redução: var -> IDENTIFIER LEFT_BRACKET expressao RIGHT_BRACKET indice\n"); $$ = $1;}
    ;

indice
    : indice LEFT_BRACKET expressao RIGHT_BRACKET
    { printf("Redução: indice -> indice LEFT_BRACKET expressao RIGHT_BRACKET\n"); }
    | /* vazio */
    { printf("Redução: indice -> ε\n"); }
    ;

%%

/*------------------------ Funções auxiliares ------------------------*/

void yyerror(const char *s) {
    fprintf(stderr, "Erro sintático na linha %d, coluna %d: %s\n", s, line_number, column_number);
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
    if (yyparse() == 0) {
        printf("Analise sintatica concluida!\n");
    }

    fclose(compiled_arq);
    return 0;
}