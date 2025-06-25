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

int insert_symbol(const char* name, DataType type) {
    if (!current_scope) return 0; // Não há escopo aberto

    unsigned long index = hash_function(name);
    HashTable* ht = current_scope->table;

    // 1. VERIFICAR SE O SÍMBOLO JÁ EXISTE NO ESCOPO ATUAL
    Symbol* current = ht->table[index];
    while (current) {
        if (strcmp(current->name, name) == 0) {
            // Erro: Redeclaração no mesmo escopo
            return 0;
        }
        current = current->next;
    }

    // 2. INSERIR O NOVO SÍMBOLO
    Symbol* new_symbol = (Symbol*)malloc(sizeof(Symbol));
    new_symbol->name = strdup(name); // Duplica a string para ter uma cópia local
    
    // --- CORREÇÃO APLICADA AQUI ---
    // Define a categoria do símbolo. Essencial para usar a union corretamente.
    new_symbol->kind = KIND_VARIABLE; 
    
    // Acessa os campos através da union 'data' e da struct 'var_info'
    new_symbol->data.var_info.type = type;
    new_symbol->data.var_info.relative_address = 0; // O endereço será gerenciado depois
    
    // Insere no início da lista ligada (tratamento de colisão)
    new_symbol->next = ht->table[index];
    ht->table[index] = new_symbol;

    return 1;
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
