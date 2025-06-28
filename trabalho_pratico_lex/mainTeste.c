#include <stdio.h>
#include <stdlib.h>
#include "tabelaSimbolos.h" // Inclui o cabeçalho do seu módulo

/**
 * @brief Função auxiliar para imprimir os detalhes de um símbolo encontrado.
 * Esta função agora usa um switch para tratar cada 'kind' de símbolo de forma diferente.
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
            printf("  -> Tipo: %d\n", symbol->data.var_info.type);
            break;

        case KIND_ARRAY:
            printf("  -> Categoria: Array\n");
            printf("  -> Tipo Base: %d\n", symbol->data.var_info.type);
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
            printf("  -> Tipo de Retorno: %d\n", symbol->data.func_info.return_type);
            printf("  -> Parametros:\n");
            Param* param = symbol->data.func_info.params;
            if (!param) {
                printf("    (void)\n");
            }
            while (param) {
                printf("    - Nome: %s, Tipo: %d, E' array? %s\n",
                       param->name, param->type, param->is_array ? "Sim" : "Nao");
                param = param->next;
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

    // --- 1. Testando Insercao de Variavel Simples ---
    printf("--- Testando Variavel ---\n");
    insert_variable("contador", TYPE_INT);
    print_symbol_details("contador");
    printf("\n");

    // --- 2. Testando Insercao de Array ---
    printf("--- Testando Array ---\n");
    // Simulando a criação de dimensões para: float matrix[10][20];
    Dimension* dim2 = (Dimension*)malloc(sizeof(Dimension));
    dim2->size = 20;
    dim2->next = NULL;

    Dimension* dim1 = (Dimension*)malloc(sizeof(Dimension));
    dim1->size = 10;
    dim1->next = dim2;
    
    insert_array("matrix", TYPE_FLOAT, dim1);
    print_symbol_details("matrix");
    printf("\n");

    // --- 3. Testando Insercao de Funcao ---
    printf("--- Testando Funcao ---\n");
    // Simulando a criação de parâmetros para: int soma(int a, char b_array[])
    Param* param_b = (Param*)malloc(sizeof(Param));
    param_b->name = "b_array";
    param_b->type = TYPE_CHAR;
    param_b->is_array = true;
    param_b->next = NULL;

    Param* param_a = (Param*)malloc(sizeof(Param));
    param_a->name = "a";
    param_a->type = TYPE_INT;
    param_a->is_array = false;
    param_a->next = param_b;

    insert_function("soma", TYPE_INT, param_a);
    print_symbol_details("soma");
    printf("\n");

    // --- 4. Verificando se tudo ainda está na tabela ---
    printf("--- Verificacao Geral ---\n");
    print_symbol_details("contador");
    print_symbol_details("matrix");
    print_symbol_details("soma");
    print_symbol_details("nao_existe");
    printf("\n");

    // --- 5. Limpando a memória ---
    printf("--- Limpando Memoria ---\n");
    destroy_scope_stack();
    // Libera a memória alocada para o teste (as listas de dims e params)
    // Em um compilador real, isso seria gerenciado pela árvore sintática.
    free(dim1);
    free(dim2);
    free(param_a);
    free(param_b);
    printf("Teste finalizado.\n");

    return 0;
}