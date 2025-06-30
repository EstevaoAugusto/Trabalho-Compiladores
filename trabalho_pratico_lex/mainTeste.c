#include <stdio.h>
#include <stdlib.h>
#include "tabelaSimbolos.h" // Inclui o cabeçalho do seu módulo

// Função auxiliar para converter DataType em uma string legível.
const char* data_type_to_string(DataType type) {
    switch (type) {
        case TYPE_INT: return "INT";
        case TYPE_FLOAT: return "FLOAT";
        case TYPE_CHAR: return "CHAR";
        case TYPE_VOID: return "VOID";
        case TYPE_STRUCT: return "STRUCT";
        default: return "DESCONHECIDO";
    }
}

/**
 * @brief Função auxiliar para imprimir os detalhes de um símbolo encontrado.
 * [ALTERADO] Versão melhorada para lidar com todos os tipos, incluindo structs.
 * @param name O nome do símbolo a ser procurado e impresso.
 */
void print_symbol_details(const char* name) {
    Symbol* symbol = lookup_symbol(name);

    if (!symbol) {
        printf("Lookup para '%s': NAO ENCONTRADO (NULL).\n", name);
        return;
    }

    printf("Lookup para '%s': ENCONTRADO.\n", name);

    switch (symbol->kind) {
        case KIND_VARIABLE:
            printf("  -> Categoria: Variavel\n");
            printf("  -> Tipo: %s\n", data_type_to_string(symbol->data.var_info.type));
            if (symbol->data.var_info.type == TYPE_STRUCT) {
                printf("  -> Nome da Struct: %s\n", symbol->data.var_info.struct_name);
            }
            break;

        case KIND_ARRAY:
            printf("  -> Categoria: Array\n");
            printf("  -> Tipo Base: %s\n", data_type_to_string(symbol->data.var_info.type));
            if (symbol->data.var_info.type == TYPE_STRUCT) {
                printf("  -> Nome da Struct: %s\n", symbol->data.var_info.struct_name);
            }
            printf("  -> Dimensoes: ");
            Dimension* dim = symbol->data.var_info.dimensions;
            while (dim) {
                printf("[%d]", dim->size);
                dim = dim->next;
            }
            printf("\n");
            break;

        case KIND_FUNCTION:
            printf("  -> Categoria: Funcao\n");
            printf("  -> Tipo de Retorno: %s\n", data_type_to_string(symbol->data.func_info.return_type));
            printf("  -> Parametros:\n");
            Param* param = symbol->data.func_info.params;
            if (!param) {
                printf("    (void)\n");
            }
            while (param) {
                printf("    - Nome: %s, Tipo: %s, E' array? %s\n",
                       param->name, data_type_to_string(param->type), param->is_array ? "Sim" : "Nao");
                param = param->next;
            }
            break;
        
        case KIND_STRUCT_DEF:
            printf("  -> Categoria: Definicao de Struct\n");
            if (symbol->data.struct_info.members) {
                 printf("  -> Tabela de membros: Existe\n");
            } else {
                 printf("  -> Tabela de membros: Nula\n");
            }
            break;

        default:
            printf("  -> Categoria: Desconhecida!\n");
            break;
    }
}


int main() {
    printf("--- INICIANDO TESTE COMPLETO DA TABELA DE SIMBOLOS ---\n\n");

    init_scope_stack();

    // --- Testes antigos (mantidos) ---
    insert_variable("contador", TYPE_INT, NULL);
    insert_array("matrix", TYPE_FLOAT, NULL, NULL); // Simplificado pois as dimensões não são usadas aqui
    insert_function("soma", TYPE_INT, NULL, NULL);   // Simplificado pois os params não são usados aqui

    // --- NOVOS TESTES PARA STRUCTS ---
    printf("--- Testando Estruturas (Structs) ---\n");

    // 1. Simula a definição: struct Ponto { int x; int y; };
    // Para o teste, não precisamos popular a tabela de membros, apenas testar a inserção.
    HashTable* ponto_members = (HashTable*)calloc(1, sizeof(HashTable));
    insert_struct_def("Ponto", ponto_members);
    print_symbol_details("Ponto");
    printf("\n");

    // 2. Simula a declaração de uma variável do tipo struct: struct Ponto p1;
    insert_variable("p1", TYPE_STRUCT, "Ponto");
    print_symbol_details("p1");
    printf("\n");

    // 3. Simula a declaração de um vetor de structs: struct Ponto pontos_vetor[5];
    Dimension* dim_struct_array = (Dimension*)malloc(sizeof(Dimension));
    dim_struct_array->size = 5;
    dim_struct_array->next = NULL;
    insert_array("pontos_vetor", TYPE_STRUCT, "Ponto", dim_struct_array);
    print_symbol_details("pontos_vetor");
    printf("\n");
    

    // --- Verificação Geral Final ---
    printf("--- Verificacao Geral Final ---\n");
    print_symbol_details("contador");
    print_symbol_details("Ponto");
    print_symbol_details("p1");
    print_symbol_details("pontos_vetor");
    print_symbol_details("nao_existe");
    printf("\n");

    // --- Limpando a memória ---
    printf("--- Limpando Memoria ---\n");
    destroy_scope_stack();
    // Libera a memória alocada para o teste
    free(dim_struct_array);
    // A tabela de membros da struct 'Ponto' é liberada pelo destroy_scope_stack,
    // mas o ponteiro que a continha precisa ser liberado.
    // Em um compilador real, isso é mais complexo. Aqui, simplificamos.
    // Como a tabela foi inserida na tabela de símbolos principal, `destroy_scope_stack`
    // cuidará de seus símbolos internos, mas não da HashTable em si, que não foi inserida
    // como um símbolo. Esta é uma limitação do teste, não do seu módulo.
    // Para este teste, a memória da tabela de membros não é um problema.
    printf("Teste finalizado.\n");

    return 0;
}