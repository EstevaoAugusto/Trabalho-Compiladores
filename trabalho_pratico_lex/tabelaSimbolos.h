#ifndef SYMBOL_TABLE_H_
#define SYMBOL_TABLE_H_

#include <stdbool.h> // Para usar o tipo 'bool'

// ... (as seções 1 e 2 com Enums e structs Param/Dimension continuam iguais) ...

//---------------------------------------------------------------------
// 1. ENUMS PARA REPRESENTAR TIPOS, CATEGORIAS E OPERADORES
//---------------------------------------------------------------------

typedef enum {
    TYPE_INT, TYPE_FLOAT, TYPE_CHAR, TYPE_VOID, TYPE_STRUCT, TYPE_STRING, TYPE_INVALID
} DataType;

typedef enum {
    KIND_VARIABLE, KIND_ARRAY, KIND_FUNCTION, KIND_STRUCT_DEF
} SymbolKind;

// Enum para operadores comuns (opcional)
typedef enum {
    OP_EQUAL,         // ==
    OP_NOT_EQUAL,     // !=
    OP_LESS_EQUAL,    // <=
    OP_GREATER_EQUAL, // >= (antes RIGHT_EQUAL_OP)
    OP_LESS,          // <  (antes LEFT_OP)
    OP_GREATER,       // >  (antes RIGHT_OP)
    OP_ASSIGN,        // =
    OP_PLUS,          // +
    OP_MINUS,         // -
    OP_DIVIDE,        // /
    OP_MULTIPLY,      // *
    OP_NONE,           // nenhum operador / default
    OP_VAR,
    OP_CALL,
    OP_INDEX
} Operator;



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

struct Symbol;

typedef struct Dimension {
    int size;
    struct Dimension* next;
} Dimension;

typedef struct Node {
    DataType type;          // Usar valor direto, não ponteiro
    struct Symbol* symbol;  // Ponteiro para símbolo, NULL se não aplicável
    SymbolKind kind;        // Usar valor direto
    bool is_array;
    Dimension* dim;
    char *struct_name;
    char* true_label;
    char* false_label;

    union {
        int int_val;
        float float_val;
        char char_val;
        char *string_val;
    } value;

    Operator op;
    // filhos da árvore de expressão (como a + b, a vai em left, b em right).
    struct Node *left;
    struct Node *right;
    // usado quando os nós estão encadeados como lista (ex: argumentos de função).
    struct Node *next;
    char *place; // Local onde o resultado será armazenado
} Node;


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
    DataType function_return_type;
    struct Scope* next; // Ponteiro para o escopo anterior (formando uma pilha)
} Scope;

struct Symbol;

/**
 * @brief Estrutura principal que representa um identificador na Tabela de Símbolos.
 */
typedef struct Symbol {
    char* name;
    SymbolKind kind;
    DataType type;

    union {
        struct {
            int relative_address;
            bool is_from_struct;
            bool is_array;
            Dimension* dimensions;
            char* struct_name;
            HashTable* members;
        } var_info;

        struct {
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
void open_scope(DataType function_return_type);
void close_scope();
void destroy_scope_stack();
DataType find_current_function_type();

// Funções de Manipulação de Símbolos
Symbol* lookup_symbol(const char* name);

Symbol* insert_variable(const char* name, DataType type, const char* struct_name);

Symbol* insert_array(const char* name, DataType type, const char* struct_name, Dimension* dims);

Symbol* insert_function(const char* name, DataType return_type, const char* struct_name, Param* params);

Symbol* insert_struct_def(const char* name, HashTable* members);

// Funções auxiliares

Param* clone_param_list(const Param* original);

void free_param_list(Param* p);

void free_symbol(Symbol* sym);

void free_hash_table(HashTable* table);

void free_dimension_list(Dimension* d);

int verifica_argumentos(Symbol *func, Node *args);

HashTable* create_hash_table();

void initialize_hash_table(HashTable* table);

int insert_struct_members(Symbol* symbol, HashTable* table);

HashTable* clone_struct_members(const HashTable* members);

char* generate_code(Node* node);
const char* op_to_str(Operator op);
char* new_temp();

int count_args(Node* args);

char* new_label();

// Essa funcao serve para checar se existem identificadores iguais em structs
bool lookup_struct_hash_table(const Symbol* symbol, const HashTable* table);

Node* create_node();

Operator operador_para_enum(const char* op_str);

Symbol* cria_symbol_temporario(DataType tipo, SymbolKind kind);

Param* create_param(const char* name, const DataType type, bool is_array);

Dimension* new_dimension(int size, Dimension* next);

bool symbols_compatible(const Symbol* s1, const Symbol* s2);

bool types_compatible(const DataType a, const DataType b);

Node* find_node_by_name(Node* list, const char* name);

Param* clone_param_list(const Param* params);

HashTable* clone_struct_members(const HashTable* members);

#endif // SYMBOL_TABLE_H_;