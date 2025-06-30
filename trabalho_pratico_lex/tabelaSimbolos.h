#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <stdbool.h> // Para usar o tipo 'bool'

// ... (as seções 1 e 2 com Enums e structs Param/Dimension continuam iguais) ...

//---------------------------------------------------------------------
// 1. ENUMS PARA REPRESENTAR TIPOS E CATEGORIAS
//---------------------------------------------------------------------

typedef enum {
    TYPE_INT, TYPE_FLOAT, TYPE_CHAR, TYPE_VOID, TYPE_STRUCT
} DataType;

typedef enum {
    KIND_VARIABLE, KIND_ARRAY, KIND_FUNCTION, KIND_STRUCT_DEF
} SymbolKind;

//---------------------------------------------------------------------
// 2. ESTRUTURAS AUXILIARES PARA FUNÇÕES E ARRANJOS
//---------------------------------------------------------------------

typedef struct Param {
    char* name;
    DataType type;
    char* struct_name;
    bool is_array;
    struct Param* next;
} Param;

typedef struct Dimension {
    int size;
    struct Dimension* next;
} Dimension;


//---------------------------------------------------------------------
// 3. ESTRUTURA PRINCIPAL DO SÍMBOLO E TABELAS
//---------------------------------------------------------------------

// --- ALTERAÇÃO IMPORTANTE: DEFINIÇÃO DE HASHTABLE VEIO PARA CIMA ---

/**
 * @brief Estrutura da Tabela de Hash.
 * Conforme exigido, a tabela de símbolos deve ser implementada com hash.
 */
#define HASH_TABLE_SIZE 211
typedef struct HashTable {
    struct Symbol* table[HASH_TABLE_SIZE];
} HashTable;

/**
 * @brief Estrutura que representa um escopo na pilha.
 * Agora o compilador já sabe o que é HashTable quando lê esta parte.
 */
typedef struct Scope {
    HashTable* table;
    struct Scope* next; // Ponteiro para o escopo anterior (formando uma pilha)
} Scope;


/**
 * @brief Estrutura principal que representa um identificador na Tabela de Símbolos.
 */
typedef struct Symbol {
    char* name;
    SymbolKind kind;

    union {
        struct {
            DataType type;
            int relative_address;
            bool is_array;
            Dimension* dimensions;
            char* struct_name;
        } var_info;

        struct {
            DataType return_type;
            char* struct_name;
            Param* params;
        } func_info;

        struct {
            HashTable* members;
        } struct_info;
    } data;

    struct Symbol* next;
} Symbol;

//---------------------------------------------------------------------
// 4. PROTÓTIPOS DAS FUNÇÕES PÚBLICAS
//---------------------------------------------------------------------

// O topo da nossa pilha de escopos.
extern Scope* current_scope;

// Funções de Gerenciamento de Escopo
void init_scope_stack();
void open_scope();
void close_scope();
void destroy_scope_stack();

// Funções de Manipulação de Símbolos
Symbol* lookup_symbol(const char* name);

Symbol* insert_variable(const char* name, DataType type, const char* struct_name);

Symbol* insert_array(const char* name, DataType type, const char* struct_name, Dimension* dims);

Symbol* insert_function(const char* name, DataType return_type, const char* struct_name, Param* params);

Symbol* insert_struct_def(const char* name, HashTable* members);

Symbol* cria_symbol_temporario(DataType tipo);


#endif // SYMBOL_TABLE_H_