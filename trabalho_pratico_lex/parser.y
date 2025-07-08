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
    DataType last_type_declared = TYPE_INVALID;  

%}


%union {
    int intval;
    float floatval;
    char charval;
    char* id;
    char* sval;
    DataType type;
    Symbol* symbol;
    Dimension* dim;
    Param* param;
    HashTable* members;
    Node* node;
}

/*------------------------ Tokens ------------------------*/
%token IF ELSE WHILE RETURN
%token <param> INT FLOAT CHAR VOID STRUCT

%token <charval>PLUS MINUS DIVISION MULTIPLY
%token <sval> EQUAL_OP NOT_EQUAL_OP LESS_EQUAL_OP RIGHT_EQUAL_OP LEFT_OP RIGHT_OP ASSIGN_OP

%token LEFT_BRACE RIGHT_BRACE
%token LEFT_BRACKET RIGHT_BRACKET
%token LEFT_PAREN RIGHT_PAREN

%token SEMICOLON COMMA

%token <intval>CONSTINT <floatval>CONSTFLOAT <charval>CONSTCHAR <sval>CONSTSTRING
%token <id> IDENTIFIER

%type <sval> relacional
%type <symbol> var_declaracao tipo_especificador func_declaracao
%type <node> expressao var ativacao var_auxiliar
%type <dim> arrayDimensao
%type <param> params param params_lista 
%type <node> arg_lista args
%type <members> varDeclList
%type <node> fator termo exp_soma expressao_simples

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
            printf("\nErro Sintático: Declaração de struct possui erro sintático (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if($1->type == TYPE_VOID){
            printf("\nErro Semântico: Variavel não pode ser declarada com tipo VOID (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else if($1->kind == KIND_STRUCT_DEF){
            if(!insert_struct_def($1->name, $1->data.struct_info.members)){
                printf("\nErro Semântico: Struct '%s' já foi declarada (linha %d, coluna %d).\n", $1->name, line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else if(strcmp($1->name, $2)  == 0){
                printf("\nErro Semântico: O identificador '%s' é o mesmo da struct declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                insert_variable($2, $1->type, $1->name);
                $$ = lookup_symbol($2);
            }
        } else if (!insert_variable($2, $1->type, NULL)) {
            printf("\nErro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else {
            $$ = lookup_symbol($2);
        }
    }
    | tipo_especificador IDENTIFIER arrayDimensao SEMICOLON
    {
        if($1 == NULL){
            printf("\nErro Semântico: Declaração de struct possui erro sintático (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if($1->type == TYPE_VOID) {
            printf("\nErro Semântico: Variavel não pode ser declarada com tipo VOID (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else if($1->kind == KIND_STRUCT_DEF){
            if(!insert_struct_def($1->name, $1->data.struct_info.members)){
                printf("\nErro Semântico: Struct '%s' já foi declarada (linha %d, coluna %d).\n", $1->name, line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else if(strcmp($1->name, $2) == 0){
                printf("\nErro Semântico: O identificador '%s' é o mesmo da struct declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                insert_array($2, $1->type, $1->name, $3);
            }
        } else if (!insert_array($2, $1->type, NULL, $3)) {
            printf("\nErro Semântico: Variável '%s' já foi declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
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
            printf("\nErro Semântico: Vetor com tamanho 0 é invalido (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        }
    }
    | LEFT_BRACKET CONSTINT RIGHT_BRACKET
    {
        if($2 > 0){
            $$ = new_dimension($2, NULL);
        } else {
            printf("\nErro Semântico: Vetor com tamanho 0 é invalido (linha %d, coluna %d).\n", line_number, column_number);
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
        last_type_declared = TYPE_INT;
        $$ = cria_symbol_temporario(TYPE_INT, KIND_VARIABLE);
    }
    | FLOAT     
    {   
        last_type_declared = TYPE_FLOAT;
        $$ = cria_symbol_temporario(TYPE_FLOAT, KIND_VARIABLE);
    }
    | CHAR      
    {   
        last_type_declared = TYPE_CHAR;
        $$ = cria_symbol_temporario(TYPE_CHAR, KIND_VARIABLE);
    }
    | VOID      
    {   
        last_type_declared = TYPE_VOID;
        $$ = cria_symbol_temporario(TYPE_VOID, KIND_VARIABLE);
    }
    | STRUCT IDENTIFIER LEFT_BRACE varDeclList RIGHT_BRACE
    {   
        $$ = cria_symbol_temporario(TYPE_STRUCT, KIND_STRUCT_DEF);
        $$->name = strdup($2);
        $$->data.struct_info.members = $4;
    }
    | STRUCT error LEFT_BRACE varDeclList RIGHT_BRACE
    { erro_sintatico_previsto("Erro Sintático: Nome de struct ausente"); $$ = NULL;  yyerrok; }
    ;

/*----- 6°: sequência de declarações de variáveis -----*/
varDeclList
    : var_declaracao
    {
        HashTable* members = create_hash_table();
        if(($1 != NULL) && !insert_struct_members($1, members)){
            printf("\nErro Semântico: O identificador '%s' já existe dentro da struct (linha %d, coluna %d).\n", $1->name, line_number, column_number);
            semantic_errors++;
            free(members);
            $$ = NULL;
        } else {
            $$ = members;
        }
    }
    | var_declaracao varDeclList
    {
        HashTable* members = $2;
        if(($1 != NULL) && !insert_struct_members($1, members)){
            printf("\nErro Semântico: O identificador '%s' já existe dentro da struct (linha %d, coluna %d).\n", $1->name, line_number, column_number);
            semantic_errors++;
            free(members);
            $$ = NULL;
        } else {
            $$ = members;
        }
    }
    ;

/*----- 7° -----*/
func_declaracao
    : tipo_especificador IDENTIFIER LEFT_PAREN params RIGHT_PAREN composto_decl
    {
        if($1 == NULL || $1->kind == KIND_STRUCT_DEF){
            printf("\nErro Semântico: Struct nao é aceito como tipo de retorno (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else {
            if(!insert_function($2, $1->type, NULL, $4)){
                printf("\nErro Semântico: Função '%s' já declarada (linha %d, coluna %d).\n", $2, line_number, column_number);
                semantic_errors++;
                last_type_declared = TYPE_INVALID;
            }
        } 
    }
    | tipo_especificador error LEFT_PAREN params RIGHT_PAREN composto_decl 
    { 
        erro_sintatico_previsto("Erro Sintático: Função inexistente ou invalida apos o tipo de retorno"); 
        last_type_declared = TYPE_INVALID; 
        $$ = NULL; 
        yyerrok; 
    }
    | tipo_especificador IDENTIFIER LEFT_PAREN error RIGHT_PAREN composto_decl 
    { 
        erro_sintatico_previsto("Erro Sintático: Lista de parâmetros malformada na declaração de função"); 
        last_type_declared = TYPE_INVALID;
        $$ = NULL; 
        yyerrok; 
    }
    ;

abre_escopo_funcao 
    :       { open_scope(last_type_declared); }
    ;

fecha_escopo_funcao
    :       { close_scope(); last_type_declared = TYPE_INVALID; }
    ;

/*----- 8° -----*/
params
    : params_lista
    { $$ = $1; }
    | VOID
    { $$ = NULL; }
    ;

/*----- 9° -----*/
params_lista
    : param
    { $$ = $1; }
    | param COMMA params_lista
    { $1->next = $3; $$ = $1; }
    ;

/*----- 10° -----*/
param
    : tipo_especificador IDENTIFIER
    {
        if($1 == NULL || $1->kind == KIND_STRUCT_DEF){
            printf("\nErro Semântico: Struct não pode ser utilizado como parametro (linha %d, coluna %d).", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else {
            $$ = create_param($2, $1->type, $1->data.var_info.is_array);
            insert_variable($2, $1->type, NULL);
        }
    }
    | tipo_especificador IDENTIFIER LEFT_BRACKET RIGHT_BRACKET
    {
        if($1 == NULL || $1->kind == KIND_STRUCT_DEF){
            printf("\nErro Semântico: Struct não pode ser utilizado como parametro (linha %d, coluna %d).", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else {
            $$ = create_param($2, $1->type, $1->data.var_info.is_array);
            insert_array($2, $1->type, NULL, NULL);
        }
    }
    | tipo_especificador IDENTIFIER error RIGHT_BRACKET
    { erro_sintatico_previsto("Erro Sintático: Falta de abrir colchetes"); $$ = NULL; yyerrok; }
    ;

/*----- 11° -----*/
composto_decl
    : LEFT_BRACE abre_escopo_funcao local_declaracoes comando_lista RIGHT_BRACE fecha_escopo_funcao
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
    { erro_sintatico_previsto("\nErro Sintático: Comando invalido sintaticamente ou incompleto"); yyerrok; }
    ;

/*----- 15° -----*/
expressao_decl
    : expressao SEMICOLON
    {
        if ($1) {
            generate_code($1);
        }
    }
    | SEMICOLON
    ;

selecao_decl
    : IF LEFT_PAREN expressao RIGHT_PAREN comando %prec LOWER_THAN_ELSE
    {
        if ($3 && $3->type != TYPE_INT) {
            printf("\nErro Semântico: Expressão condicional do 'if' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
        char* Ltrue = new_label();
        char* Lend = new_label();
        char* cond = generate_code($3);

        fprintf(code_output, "if %s goto %s\n", cond, Ltrue);
        fprintf(code_output, "goto %s\n", Lend);
        fprintf(code_output, "%s:\n", Ltrue);
        // código do comando ($5) será gerado automaticamente
        fprintf(code_output, "%s:\n", Lend);
    }
    | IF LEFT_PAREN expressao RIGHT_PAREN comando ELSE comando
    {
        if ($3 && $3->type != TYPE_INT) {
            printf("\nErro Semântico: Expressão condicional do 'if' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
        char* Ltrue = new_label();
        char* Lfalse = new_label();
        char* Lend = new_label();
        char* cond = generate_code($3);

        fprintf(code_output, "if %s goto %s\n", cond, Ltrue);
        fprintf(code_output, "goto %s\n", Lfalse);
        fprintf(code_output, "%s:\n", Ltrue);
        // código do comando $5
        fprintf(code_output, "goto %s\n", Lend);
        fprintf(code_output, "%s:\n", Lfalse);
        // código do comando $7
        fprintf(code_output, "%s:\n", Lend);
    }
    | IF LEFT_PAREN error RIGHT_PAREN comando
    { erro_sintatico_previsto("Erro Sintático: Condição errada no comando IF"); yyerrok;}
    ;

/*----- 17° -----*/
iteracao_decl
    : WHILE LEFT_PAREN expressao RIGHT_PAREN comando
    {
        if ($3 && $3->type != TYPE_INT) {
            printf("\nErro Semântico: Expressão condicional do 'while' deve ser do tipo int (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
        char* Lstart = new_label();
        char* Lcond = new_label();
        char* Lend = new_label();

        fprintf(code_output, "%s:\n", Lcond);
        char* cond = generate_code($3);
        fprintf(code_output, "if %s goto %s\n", cond, Lstart);
        fprintf(code_output, "goto %s\n", Lend);
        fprintf(code_output, "%s:\n", Lstart);
        // código do comando $5
        fprintf(code_output, "goto %s\n", Lcond);
        fprintf(code_output, "%s:\n", Lend);
    }
    | WHILE LEFT_PAREN error RIGHT_PAREN comando
    { erro_sintatico_previsto("Erro Sintático: Comando WHILE invalido"); yyerrok; }
    ;

/*----- 18° -----*/
retorno_decl
    : RETURN SEMICOLON    {
        DataType type = find_current_function_type();
        if (type != TYPE_VOID) {
            printf("\nErro Semântico: Retorno sem valor em função que exige retorno (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
    }
    | RETURN expressao SEMICOLON    {
        DataType type = find_current_function_type();
        if ($2 && $2->type != type) {
            printf("\nErro Semântico: Tipo do valor de retorno incompatível com a função (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        } else if ($2) {
        char* temp = generate_code($2);
        fprintf(code_output, "return %s\n", temp);
        }
    }
    | RETURN error SEMICOLON
    { erro_sintatico_previsto("Erro Sintático: Retorno invalido"); yyerrok;}
    ;

/*----- 19° -----*/
expressao
    : var ASSIGN_OP expressao
    {
        if ($1 && $3) {
            Node* node = create_node();
            node->op = OP_ASSIGN;
            node->type = $1->type;
            node->left = $1;
            node->right = $3;
            node->place = generate_code(node);
            $$ = node;

            if($1->symbol->data.var_info.is_from_struct){
                printf("\nErro Semântico: Acesso a membros de struct não suportado pela gramática (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                DataType tipo_var = $1->type;
                DataType tipo_expr = $3->type;

                bool tipos_compativeis = false;

                if (tipo_var == tipo_expr) {
                    tipos_compativeis = true;
                } else if ((tipo_var == TYPE_FLOAT && tipo_expr == TYPE_INT) ||  (tipo_var == TYPE_INT && tipo_expr == TYPE_FLOAT)) {
                    tipos_compativeis = true;
                } else {
                    tipos_compativeis = false;
                }

                if (!tipos_compativeis) {
                    printf("\nErro Semântico: Tipos incompatíveis na atribuição (linha %d, coluna %d).\n", line_number, column_number);
                    semantic_errors++;
                    $$ = NULL;
                } else {
                    $$ = $1;
                }
            }
        } else {
            $$ = NULL;
        }
    }
    | var ASSIGN_OP error
    { 
        erro_sintatico_previsto("Erro Sintático: Atribuição sem expressão à direita"); 
        if($1 && $1->symbol->data.var_info.is_from_struct){
            printf("\nErro Semântico: Acesso a membros de struct não suportado pela gramática (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
        }
        $$ = NULL; 
        yyerrok; }
    | expressao_simples    { $$ = $1; }
;

/*----- 20° -----*/
expressao_simples
    : exp_soma relacional exp_soma    {
        if ($1 && $3) {
            if ($1->type != $3->type) {
                printf("\nErro Semântico: Tipos incompatíveis na comparação (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                // Cria um novo node para a comparação
                Node* node = create_node();

                node->op = operador_para_enum($2); // Você precisa implementar essa função

                // O tipo do resultado de comparação normalmente é int ou bool (aqui, por simplicidade, int)
                node->type = TYPE_INT;

                node->left = $1;
                node->right = $3;

                $$ = node;
                node->place = generate_code(node);
            }
        } else { $$ = NULL; }
    }
    | exp_soma    { $$ = $1; }
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
    : termo    { $$ = $1; }
    | exp_soma PLUS termo    {
        if ($1 && $3) {
            if ($1->type != $3->type) {
                printf("\nErro Semântico: tipos incompatíveis na soma (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_PLUS;
                node->type = $1->type;   // ou aplicar promoção de tipo, se quiser
                node->left = $1;
                node->right = $3;
                node->place = generate_code(node);
                $$ = node;
            }
        } else { $$ = NULL; }
    }
    | exp_soma MINUS termo    {
        if ($1 && $3) {
            if ($1->type != $3->type) {
                printf("\nErro Semântico: tipos incompatíveis na subtração (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_MINUS;
                node->type = $1->type;
                node->left = $1;
                node->right = $3;
                $$ = node;
                node->place = generate_code(node);
            }
        } else { $$ = NULL; }
    }
;

termo
    : fator    { $$ = $1; }
    | termo MULTIPLY fator    {
        if ($1 && $3) {
            if ($1->type != $3->type) {
                printf("\nErro Semântico: tipos incompatíveis na multiplicação (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_MULTIPLY;
                node->type = $1->type; // ou fazer promoção de tipo se desejar
                node->left = $1;
                node->right = $3;
                $$ = node;
                node->place = generate_code(node);
            }
        } else { $$ = NULL; }
    }
    | termo DIVISION fator    {
        if ($1 && $3) {
            if ($1->type != $3->type) {
                printf("\nErro Semântico: tipos incompatíveis na divisão (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                Node* node = create_node();
                node->op = OP_DIVIDE;
                node->type = $1->type;
                node->left = $1;
                node->right = $3;
                $$ = node;
            }
        } else { $$ = NULL; }
    }
    | termo MULTIPLY fator error    {
        erro_sintatico_previsto("Erro Sintático: Operação de '*' sem o fator");
        yyerrok;
        $$ = NULL;
    }
    | termo DIVISION fator error    {
        erro_sintatico_previsto("Erro Sintático: Operação de '/' sem o fator");
        yyerrok;
        $$ = NULL;
    }
    ;

/*----- 24° -----*/
fator
    : LEFT_PAREN expressao RIGHT_PAREN
    {
        $$ = $2;  // Apenas propaga o Node da expressão
    }
    | var
    {
        // var retorna Node*, já preenchido com o símbolo e tipo
        $$ = $1;
    }
    | ativacao
    {
        // ativacao retorna Node* com símbolo da função e tipo de retorno
        $$ = $1;
    }
    | CONSTFLOAT
    {
        Node *n = create_node();
        n->type = TYPE_FLOAT;
        n->op = OP_NONE;
        n->value.float_val = $1;
        $$ = n;
    }
    | CONSTINT
    {
        Node *n = create_node();
        n->type = TYPE_INT;
        n->op = OP_NONE;
        n->value.int_val = $1; // ou $1
        $$ = n;
    }
    | CONSTCHAR
    {
        Node *n = create_node();
        n->type = TYPE_CHAR;
        n->op = OP_NONE;
        n->value.char_val = $1; // ignora aspas simples
        $$ = n;
    }
    | CONSTSTRING
    {
        Node *n = create_node();
        n->type = TYPE_STRING; // defina esse tipo se ainda não existir
        n->op = OP_NONE;
        n->value.string_val = strdup($1); // copia a string
        $$ = n;
    }
    | LEFT_PAREN error RIGHT_PAREN
    {
        erro_sintatico_previsto("Erro Sintático: Expressão vazia entre parênteses");
        yyerrok;
        $$ = NULL;
    }
;

/*----- 25° -----*/
ativacao
    : IDENTIFIER LEFT_PAREN args RIGHT_PAREN
    {
        Symbol *sym = lookup_symbol($1);
        if (!sym) {
            printf("\nErro Semântico: Função '%s' não declarada (linha %d, coluna %d).\n", $1, line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else if (sym->kind != KIND_FUNCTION) {
            printf("\nErro Semântico: '%s' não é uma função (linha %d, coluna %d).\n", $1, line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else if (!verifica_argumentos(sym, $3)) {
            printf("(linha %d, coluna %d)\n", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else {
            $$ = create_node();
            $$->type = sym->type;
            $$->op = OP_CALL;
            $$->left = NULL;
            $$->right = $3; // lista de argumentos
            $$->symbol = sym;

            if (sym->type == TYPE_STRUCT && sym->data.func_info.struct_name) {
                $$->struct_name = strdup(sym->data.func_info.struct_name);
            }
        }
    }
    | IDENTIFIER LEFT_PAREN error RIGHT_PAREN
    { erro_sintatico_previsto("Erro Sintático: Argumentos invalidos no retorno da funcao"); $$ = NULL; yyerrok; }
    ;

/*----- 26° -----*/
args
    : arg_lista
      { $$ = $1; }
    | /* vazio */
      { $$ = NULL; }
    ;

/*----- 27° -----*/
arg_lista
    : expressao
    {
        if($1->kind == KIND_VARIABLE){
            insert_variable($1->symbol->name, $1->type, NULL);
        }
        $$ = $1;
        $1->next = NULL;
    }
    | arg_lista COMMA expressao
    {
        Node *last = $1;
        while (last->next) last = last->next;
        last->next = $3;
        $3->next = NULL;
        $$ = $1;
    }
    | arg_lista COMMA COMMA error
    { erro_sintatico_previsto("Erro Sintático: Falta de parametro"); yyerrok; $$ = NULL; }
    | arg_lista COMMA error
    { erro_sintatico_previsto("Erro Sintático: Virgula excedente ao final da lista de parametros"); yyerrok; $$ = NULL; }
    ;

/*----- 28° -----*/
var
    : IDENTIFIER
    {
        Symbol *sym = lookup_symbol($1);
        if(!sym){
            printf("\nErro Semântico: Identificador não foi declarado (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else if(sym->data.var_info.is_array){
            printf("\nErro Semântico: Problema de Atribuição, uma das variaveis é um arranjo, mas nenhum indice foi colocado (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else {
            Node *n = create_node();
            n->type = sym->type;
            n->symbol = sym;
            n->op = OP_VAR;
            n->is_array = sym->data.var_info.is_array;
            n->dim = sym->data.var_info.dimensions;
            n->struct_name = NULL;
            $$ = n;
        }
    }
    | IDENTIFIER LEFT_BRACKET expressao RIGHT_BRACKET var_auxiliar
    {
        Symbol *sym = lookup_symbol($1);
        if (!sym) {
            printf("\nErro Semântico: Identificador não foi declarado (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else if (!sym->data.var_info.is_array) {
            printf("\nErro Semântico: Identificador '%s' não é um vetor (linha %d, coluna %d).\n", $1, line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else if ($3 && $3->type != TYPE_INT) {
            printf("\nErro Semântico: Índice de vetor deve ser inteiro (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            $$ = NULL;
        } else {
            // Verificar se todos os índices são inteiros
            Node *temp = $5;
            bool all_int = ($3 && $3->type == TYPE_INT);
            while (temp && all_int) {
                if (temp->type != TYPE_INT) {
                    all_int = false;
                    break;
                }
                temp = temp->next;
            }

            if (!all_int) {
                printf("\nErro Semântico: Índices de vetor devem ser inteiros (linha %d, coluna %d).\n", line_number, column_number);
                semantic_errors++;
                $$ = NULL;
            } else {
                // Contar número de índices fornecidos
                int num_indices = 1;
                Node *current = $5;
                while (current) {
                    num_indices++;
                    current = current->next;
                }

                // Contar número de dimensões esperadas
                int num_dims = 0;
                Dimension *d = sym->data.var_info.dimensions;
                while (d) {
                    num_dims++;
                    d = d->next;
                }

                if (num_indices > num_dims) {
                    printf("\nErro Semântico: Vetor '%s' possui dimensões demais (fornecido %d, esperado %d) (linha %d, coluna %d).\n",
                        $1, num_indices, num_dims, line_number, column_number);
                    semantic_errors++;
                    $$ = NULL;
                } else {

                    Node *idx_node = $3;                     // Primeiro índice
                    Dimension *dim_node = sym->data.var_info.dimensions;  // Lista de dimensões do símbolo
                    int checked_dims = 0;

                    while (idx_node != NULL && dim_node != NULL) {
                    // Verifica se índice é valor inteiro constante
                        int val = idx_node->value.int_val;
                        if (val < 0 || val >= dim_node->size) {
                            printf("\nErro Semântico: Índice [%d] fora dos limites da dimensão %d (tamanho = %d) do vetor '%s' (linha %d, coluna %d).\n",
                            val, checked_dims + 1, dim_node->size, $1, line_number, column_number);
                            semantic_errors++;
                            $$ = NULL;
                            break;
                        }


                    // Avança para próximo índice e próxima dimensão
                    if (checked_dims == 0)
                        idx_node = $5;     // var_auxiliar está no $5 (próximos índices)
                    else
                        idx_node = idx_node->next;

                    dim_node = dim_node->next;
                    checked_dims++;
                    }

                    Node *n = create_node();
                    n->type = sym->type;
                    n->symbol = sym;
                    n->op = OP_INDEX;
                    n->left = $3;     // primeiro índice
                    n->right = $5;    // índices seguintes
                    n->dim = sym->data.var_info.dimensions;

                    // Se ainda restam dimensões após os índices, é um array
                    n->is_array = (num_indices < num_dims);
                    $$ = n;
                }
            }
        }
    }
;

/*---- 29° ----*/

var_auxiliar
    : var_auxiliar LEFT_BRACKET expressao RIGHT_BRACKET
    {
        if ($3 && $3->type != TYPE_INT) {
            printf("\nErro Semântico: Índice de vetor deve ser inteiro (linha %d, coluna %d).\n", line_number, column_number);
            semantic_errors++;
            $$ = $1;
        } else {
            if ($1 == NULL) {
                // Começando uma nova lista de dimensões
                $$ = $3;
            } else {
                // Encadeia $3 no final da lista $1
                Node *temp = $1;
                while (temp->next != NULL) temp = temp->next;
                temp->next = $3;
                $$ = $1;
            }
        }
    }
    | // vazio
    { $$ = NULL; }
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
    code_output = fopen("saida.3ac", "w");
    if (!code_output) {
        perror("Erro ao abrir o arquivo de saída do código intermediário");
        return -3;
    }
    
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

    printf("\n==== Resultado da Análise ====\n");
    if (result == 0) {
        printf("ANALISE CONCLUIDA COM SUCESSO!\n");
    } else {
        printf("ANALISE FALHOU DEVIDO A ERROS!\n");
    }

    printf("Total de erros léxicos: %d\n", lexical_errors);
    printf("Total de erros sintáticos: %d\n", syntax_errors);
    printf("Total de erros semânticos: %d\n", semantic_errors);

    printf("\n Código de 3 Endereços Gravado em saida.3ac \n");

    fclose(compiled_arq);
    fclose(code_output);
    // destroy_scope_stack();
    return 0;
}