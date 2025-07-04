#include "tabelaSimbolos.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

// A variável global estática para o topo da pilha.
Scope* current_scope = NULL;

// Função de Hash (exemplo: djb2)
static unsigned long hash_function(const char* str) {
    unsigned long hash = 5381;
    int c;
    while ((c = *str++)) {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % HASH_TABLE_SIZE;
}

Param* create_param(const char* name, const DataType type, bool is_array){
    Param* new_param = (Param*)malloc(sizeof(Param));

    new_param->is_array = is_array;
    new_param->name = strdup(name);
    new_param->type = type;
    new_param->struct_name = NULL;
    new_param->next = NULL;

    return new_param;
}


static int internal_insert(Symbol* new_symbol) {
    if (!current_scope) return 0; // Não deveria acontecer se init foi chamado

    unsigned long index = hash_function(new_symbol->name);
    HashTable* ht = current_scope->table;

    // VERIFICAR SE O SÍMBOLO JÁ EXISTE NO ESCOPO ATUAL
    Symbol* current = ht->table[index];
    while (current) {
        if (strcmp(current->name, new_symbol->name) == 0) {
            // Erro: Redeclaração. Libera a memória do símbolo que não será usado.
            free(new_symbol->name);
            free(new_symbol);
            return 0;
        }
        current = current->next;
    }

    // Insere o novo símbolo no início da lista ligada
    new_symbol->next = ht->table[index];
    ht->table[index] = new_symbol;

    return 1; // Sucesso
}

Symbol* insert_variable(const char* name, DataType type, const char* struct_name) {
    if(type == TYPE_STRUCT && struct_name == NULL) return NULL; // Falha (variavel é do tipo struct, mas nao tem seu identificador)

    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->kind = KIND_VARIABLE;
    new_symbol->type = type;
    new_symbol->data.var_info.is_array = false;
    new_symbol->data.var_info.dimensions = NULL;
    new_symbol->data.var_info.relative_address = 0; // A ser definido na geração de código
    
    new_symbol->data.var_info.struct_name = struct_name ? strdup(struct_name) : NULL;
    Symbol* struct_sym = struct_name ? lookup_symbol(struct_name) : NULL;
    if (type == TYPE_STRUCT && (!struct_sym || struct_sym->kind != KIND_STRUCT_DEF)) {
        return NULL; // struct inválida ou não declarada
    }
    new_symbol->data.var_info.members = struct_sym ? clone_struct_members(struct_sym->data.struct_info.members) : NULL;


    if (internal_insert(new_symbol)) {
        return new_symbol; // Sucesso na inserção
    }
    return NULL; // Falha (símbolo já existia)
}

Symbol* insert_array(const char* name, DataType type, const char* struct_name, Dimension* dims) {
    if(type == TYPE_STRUCT && struct_name == NULL) return NULL; // Falha (variavel é do tipo struct, mas nao tem seu identificador)

    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->kind = KIND_ARRAY;
    new_symbol->type = type;
    new_symbol->data.var_info.is_array = true;
    new_symbol->data.var_info.dimensions = dims; // Guarda a lista de dimensões
    new_symbol->data.var_info.relative_address = 0;
    new_symbol->data.var_info.struct_name = struct_name ? strdup(struct_name) : NULL;

    Symbol* struct_sym = struct_name ? lookup_symbol(struct_name) : NULL;
    if (type == TYPE_STRUCT && (!struct_sym || struct_sym->kind != KIND_STRUCT_DEF)) {
        return NULL; // struct inválida ou não declarada
    }
    new_symbol->data.var_info.members = struct_sym ? clone_struct_members(struct_sym->data.struct_info.members) : NULL;

    if (internal_insert(new_symbol)) {
        return new_symbol; // Sucesso
    }
    return NULL; // Falha
}

HashTable* create_hash_table(){
    HashTable* table = (HashTable*)malloc(sizeof(HashTable));
    if (!table) {
        perror("Erro de alocação de hash table");
        exit(EXIT_FAILURE);
    }

    initialize_hash_table(table);

    return table;
}


Symbol* insert_function(const char* name, DataType return_type, const char* struct_name, Param* params) {
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->kind = KIND_FUNCTION;
    new_symbol->type = return_type;
    new_symbol->data.func_info.params = params; // Guarda a lista de parâmetros
    new_symbol->data.func_info.struct_name = struct_name ? strdup(struct_name) : NULL;

    if (internal_insert(new_symbol)) {
        return new_symbol; // Sucesso
    }
    return NULL; // Falha
}

Symbol* insert_struct_def(const char* name, HashTable* members) {
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->kind = KIND_STRUCT_DEF;
    new_symbol->data.struct_info.members = members;

    if (internal_insert(new_symbol)) return new_symbol;
    return NULL;
}

void init_scope_stack() {
    // A pilha começa vazia, open_scope() criará o primeiro (global) escopo.
    current_scope = NULL;
    open_scope(); // Cria o escopo global
}

void open_scope() {
    // Aloca memória para um novo escopo
    Scope* new_scope = (Scope*)malloc(sizeof(Scope));
    if (!new_scope) { /* erro de alocação */ return; }

    // Aloca memória para a nova tabela de hash
    new_scope->table = (HashTable*)malloc(sizeof(HashTable));
    if (!new_scope->table) { /* erro de alocação */ free(new_scope); return; }

    // Inicializa a tabela com NULLs
    initialize_hash_table(new_scope->table);

    // Empilha o novo escopo
    new_scope->next = current_scope;
    current_scope = new_scope;
}

int insert_struct_members(Symbol* symbol, HashTable* table){
    if (!symbol || !table || !symbol->name) return 0;
    if(lookup_struct_hash_table(symbol, table)){
        return 0;
    }

    unsigned long index = hash_function(symbol->name);
    // Encadeia o novo símbolo no início da lista
    symbol->next = table->table[index];
    table->table[index] = symbol;

    return 1;
}

Dimension* new_dimension(int size, Dimension* next) {
    if(size < 1){
        return NULL;
    }

    Dimension* d = (Dimension*)malloc(sizeof(Dimension));
    d->size = size;
    d->next = next;
    return d;
}

// Essa funcao serve para checar se existem identificadores iguais em structs
bool lookup_struct_hash_table(const Symbol* symbol, const HashTable* table){
    if (!symbol || !table || !symbol->name) return false;

    unsigned long index = hash_function(symbol->name);
    Symbol* current = table->table[index];

    while (current) {
        if (strcmp(current->name, symbol->name) == 0) {
            return true;
        }
        current = current->next;
    }

    return false;
}


void initialize_hash_table(HashTable* table){
    // Inicializa a tabela com NULLs
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        table->table[i] = NULL;
    }
}


Symbol* lookup_symbol(const char* name) {
    Scope* scope_iterator = current_scope;

    // Itera da pilha do topo para baixo (escopo atual -> global)
    while (scope_iterator) {
        unsigned long index = hash_function(name);
        Symbol* current = scope_iterator->table->table[index];

        // Procura na lista ligada daquele índice
        while (current) {
            if (strcmp(current->name, name) == 0) {
                return current; // Símbolo encontrado!
            }
            current = current->next;
        }
        
        // Vai para o escopo pai (anterior na pilha)
        scope_iterator = scope_iterator->next;
    }

    return NULL; // Símbolo não encontrado em nenhum escopo visível
}

void close_scope() {
    if (!current_scope) return;

    Scope* scope_to_delete = current_scope;
    
    // Libera todos os símbolos dentro da tabela do escopo que está sendo fechado
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        Symbol* current = scope_to_delete->table->table[i];
        while (current) {
            Symbol* temp = current;
            current = current->next;
            free(temp->name); // Libera a string duplicada
            free(temp);       // Libera o nó do símbolo
        }
    }
    
    // Libera a tabela de hash
    free(scope_to_delete->table);

    // Avança o topo da pilha para o escopo anterior
    current_scope = scope_to_delete->next;
    
    // Libera a estrutura do escopo
    free(scope_to_delete);
}

void destroy_scope_stack(){
    while(current_scope){
        close_scope();
    }
}


Symbol* cria_symbol_temporario(DataType tipo, SymbolKind kind) {
    Symbol* sym = (Symbol*) malloc(sizeof(Symbol));
    if (!sym) {
        printf(stderr, "Erro: falha na alocação de Symbol.\n");
        exit(EXIT_FAILURE);
    }
    
    sym->name = NULL;
    sym->kind = kind;
    sym->type = tipo;

    // Inicializa dados conforme kind
    switch (kind) {
        case KIND_VARIABLE:
        case KIND_ARRAY:
            sym->data.var_info.relative_address = 0; // Exemplo de valor padrão
            sym->data.var_info.is_array = (kind == KIND_ARRAY);
            sym->data.var_info.dimensions = NULL;
            sym->data.var_info.struct_name = NULL;
            sym->data.var_info.members = NULL;
            break;

        case KIND_FUNCTION:
            sym->data.func_info.struct_name = NULL;
            sym->data.func_info.params = NULL;
            break;

        case KIND_STRUCT_DEF:
            sym->data.struct_info.members = NULL; // Deve ser setado depois
            break;

        default:
            printf(stderr, "Aviso: Kind desconhecido em cria_symbol_temporario.\n");
            break;
    }

    sym->next = NULL;

    return sym;
}


bool symbols_compatible(const Symbol* s1, const Symbol* s2){
    DataType t1 = s1->type;
    DataType t2 = s2->type;
    if (t1 != TYPE_STRUCT || t2 != TYPE_STRUCT)
        return tipos_sao_compatíveis(t1, t2);

    // Se forem structs, compara os nomes
    return s1->data.var_info.struct_name &&
           s2->data.var_info.struct_name &&
           strcmp(s1->data.var_info.struct_name,
                  s2->data.var_info.struct_name) == 0;
}

Operator operador_para_enum(const char* op_str) {
    if (strcmp(op_str, "<") == 0) {
        return LEFT_OP;
    } else if (strcmp(op_str, ">") == 0) {
        return RIGHT_OP;
    } else if (strcmp(op_str, "<=") == 0) {
        return LESS_EQUAL_OP;
    } else if (strcmp(op_str, ">=") == 0) {
        return RIGHT_EQUAL_OP;
    } else if (strcmp(op_str, "==") == 0) {
        return EQUAL_OP;
    } else if (strcmp(op_str, "!=") == 0) {
        return NOT_EQUAL_OP;
    } else {
        return NONE_OP;  // operador desconhecido ou inválido
    }
}

Node* create_node() {
    Node* node = (Node*) malloc(sizeof(Node));
    if (!node) {
        fprintf(stderr, "Erro: falha ao alocar memória para Node.\n");
        exit(EXIT_FAILURE);
    }

    // Inicializa os campos do Node com valores padrão
    node->type = TYPE_INVALID;
    node->symbol = NULL;
    node->kind = KIND_VARIABLE;  // ou OP_NONE, conforme faça sentido
    node->is_array = false;
    node->dim = NULL;
    node->struct_name = NULL;

    // Zera o union de valores
    memset(&node->value, 0, sizeof(node->value));

    node->op = NONE_OP;
    node->left = NULL;
    node->right = NULL;

    return node;
}

bool types_compatible(const DataType* a, const DataType* b){
    if (a == b) {
        return true;
    }

    // Permitir conversão enteiro → float
    if ((a == TYPE_FLOAT && b == TYPE_INT) || (a == TYPE_INT && b == TYPE_FLOAT)) return true;

    // Suporta compatibilidade entre char e int (promovido em expressões)
    if ((a == TYPE_INT && b == TYPE_CHAR) || (a == TYPE_CHAR && b == TYPE_INT)) return true;

    // Compatibilidade para void em contextos onde não há valor (e.g., retorno de função)
    if (a == TYPE_VOID && b == TYPE_VOID) return true;

    // Para structs: só se o nome do struct for o mesmo
    if (a == TYPE_STRUCT && b == TYPE_STRUCT) {
        // Aqui você deve comparar os struct_names, armazenados em Symbol
        // Exemplo:
        // if (strcmp(symA->data.var_info.struct_name, symB->data.var_info.struct_name) == 0) return true;
        // Mas como essa função não tem os Symbols, você pode delegar essa verificação externamente.
        return false;
    }

    return false;
}

int verifica_argumentos(Symbol *func, Node *args) {
    if (!func) {
        printf("Erro Semântico: Função não declarada.\n");
        return 0;
    }
    if (func->kind != KIND_FUNCTION) {
        printf("Erro Semântico: Símbolo '%s' não é uma função.\n", func->name);
        return 0;
    }

    Param *param = func->data.func_info.params;  // Lista de parâmetros da função
    Node *arg = args;                            // Lista encadeada de argumentos (via right)

    int index = 1;  // Para indicar qual argumento está sendo verificado

    while (param && arg) {
        // Verifica se os tipos batem
        if (param->type != arg->type) {
            printf("Erro Semântico: Tipos oferecidos nao batem ");
            return 0;
        }

        // Verifica se ambos são arrays ou não
        if (param->is_array != arg->is_array) {
            printf("Erro Semântico: Argumento %d da função '%s' deve %sarray, mas recebeu %sarray ",
                index, func->name,
                param->is_array ? "" : "não ",
                arg->is_array ? "" : "não ");
            return 0;
        }

        param = param->next;
        arg = arg->right;  // Avança para o próximo argumento
        index++;
    }

    // Se sobrou parâmetro ou argumento, quantidade diferente
    if (param != NULL) {
        printf("Erro Semântico: Função '%s' espera %d parâmetros, mas recebeu menos ",
            func->name, index - 1 + 1);
        return 0;
    }
    if (arg != NULL) {
        printf("Erro Semântico: Função '%s' espera %d parâmetros, mas recebeu mais %d ",
            func->name, index - 1);
        return 0;
    }

    return 1;  // Tudo certo
}

// Função para clonar lista de dimensões
static Dimension* clone_dimensions(const Dimension* dims) {
    if (!dims) return NULL;
    Dimension* new_dim = malloc(sizeof(Dimension));
    new_dim->size = dims->size;
    new_dim->next = clone_dimensions(dims->next);
    return new_dim;
}

// Clona os membros da tabela hash de structs
HashTable* clone_struct_members(const HashTable* members) {
    if (!members) return NULL;

    HashTable* cloned_table = create_hash_table(); // usa sua função
    for (int i = 0; i < HASH_TABLE_SIZE; ++i) {
        Symbol* current = members->table[i];
        while (current) {
            Symbol* cloned_sym = clone_symbol(current);
            // Inserção no início da lista do bucket
            unsigned long index = hash_function(cloned_sym->name);
            cloned_sym->next = cloned_table->table[index];
            cloned_table->table[index] = cloned_sym;

            current = current->next;
        }
    }
    return cloned_table;
}

static Symbol* clone_symbol(const Symbol* sym) {
    if (!sym) return NULL;

    Symbol* new_sym = malloc(sizeof(Symbol));
    new_sym->name = strdup(sym->name);
    new_sym->kind = sym->kind;
    new_sym->type = sym->type;
    new_sym->next = NULL;

    switch (sym->kind) {
        case KIND_VARIABLE:
        case KIND_ARRAY:
            new_sym->data.var_info.relative_address = sym->data.var_info.relative_address;
            new_sym->data.var_info.is_array = sym->data.var_info.is_array;
            new_sym->data.var_info.dimensions = clone_dimensions(sym->data.var_info.dimensions);
            new_sym->data.var_info.struct_name = sym->data.var_info.struct_name ? strdup(sym->data.var_info.struct_name) : NULL;
            new_sym->data.var_info.members = clone_struct_members(sym->data.var_info.members);
            break;

        case KIND_FUNCTION:
            new_sym->data.func_info.struct_name = sym->data.func_info.struct_name ? strdup(sym->data.func_info.struct_name) : NULL;
            new_sym->data.func_info.params = NULL; // você pode implementar clone de Param se quiser
            break;

        case KIND_STRUCT_DEF:
            new_sym->data.struct_info.members = clone_struct_members(sym->data.struct_info.members);
            break;
    }

    return new_sym;
}
