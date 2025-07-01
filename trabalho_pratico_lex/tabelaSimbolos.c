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
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->kind = KIND_VARIABLE;
    new_symbol->data.var_info.type = type;
    new_symbol->data.var_info.is_array = false;
    new_symbol->data.var_info.dimensions = NULL;
    new_symbol->data.var_info.relative_address = 0; // A ser definido na geração de código
    new_symbol->data.var_info.struct_name = struct_name ? strdup(struct_name) : NULL;
    new_symbol->data.var_info.members = struct_name ? lookup_symbol(struct_name)->data.struct_info.members : NULL;

    if (internal_insert(new_symbol)) {
        return new_symbol; // Sucesso na inserção
    }
    return NULL; // Falha (símbolo já existia)
}

Symbol* insert_array(const char* name, DataType type, const char* struct_name, Dimension* dims) {
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->kind = KIND_ARRAY;
    new_symbol->data.var_info.type = type;
    new_symbol->data.var_info.is_array = true;
    new_symbol->data.var_info.dimensions = dims; // Guarda a lista de dimensões
    new_symbol->data.var_info.relative_address = 0;
    new_symbol->data.var_info.struct_name = struct_name ? strdup(struct_name) : NULL;
    new_symbol->data.var_info.members = struct_name ? lookup_symbol(struct_name)->data.struct_info.members : NULL;

    if (internal_insert(new_symbol)) {
        return new_symbol; // Sucesso
    }
    return NULL; // Falha
}

Symbol* insert_function(const char* name, DataType return_type, const char* struct_name, Param* params) {
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name);
    new_symbol->kind = KIND_FUNCTION;
    new_symbol->data.func_info.return_type = return_type;
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
    for (int i = 0; i < HASH_TABLE_SIZE; i++) {
        new_scope->table->table[i] = NULL;
    }

    // Empilha o novo escopo
    new_scope->next = current_scope;
    current_scope = new_scope;
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


Symbol* cria_symbol_temporario(DataType tipo) {
    Symbol* temp = malloc(sizeof(Symbol));
    temp->kind = KIND_VARIABLE;
    temp->data.var_info.type = tipo;
    return temp;
}
