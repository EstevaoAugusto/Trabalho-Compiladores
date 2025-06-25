#include <stdio.h>
#include <stdlib.h>
#include "tabelaSimbolos.h" // Inclua o cabeçalho do seu módulo

// Função auxiliar para imprimir o resultado de um lookup
void print_lookup_result(const char* name) {
    Symbol* symbol = lookup_symbol(name);
    if (symbol) {
        // Assume que o símbolo é uma variável para este teste simples
        printf("Lookup para '%s': ENCONTRADO. Tipo: %d, Kind: %d\n",
               symbol->name, symbol->data.var_info.type, symbol->kind);
    } else {
        printf("Lookup para '%s': NAO ENCONTRADO (NULL).\n", name);
    }
}

int main() {
    printf("--- INICIANDO TESTE DA TABELA DE SIMBOLOS ---\n\n");

    // 1. Inicializa a tabela
    init_scope_stack();
    printf("[TESTE] Pilha de escopos inicializada (escopo global criado).\n\n");

    // 2. Insere símbolos no escopo global
    printf("--- Testando Escopo Global ---\n");
    insert_symbol("global_var_1", TYPE_INT);
    insert_symbol("global_var_2", TYPE_FLOAT);
    printf("[TESTE] Inserido 'global_var_1' (INT) e 'global_var_2' (FLOAT).\n");
    print_lookup_result("global_var_1");
    print_lookup_result("global_var_2");
    print_lookup_result("var_nao_existe");
    printf("\n");

    // 3. Testa erro de re-declaração no mesmo escopo
    printf("--- Testando Erro de Re-declaracao ---\n");
    // Tenta inserir 'global_var_1' novamente no mesmo escopo
    if (insert_symbol("global_var_1", TYPE_CHAR) == 0) {
        printf("[OK] Erro de re-declaracao para 'global_var_1' detectado corretamente.\n\n");
    } else {
        printf("[FALHA] 'global_var_1' foi inserido duas vezes no mesmo escopo.\n\n");
    }

    // 4. Abre um novo escopo local
    printf("--- Testando Escopo Local ---\n");
    open_scope();
    printf("[TESTE] Novo escopo aberto.\n");

    // 5. Insere símbolos no escopo local
    // 'local_var' só existe aqui.
    // 'global_var_2' vai "esconder" a variável global com o mesmo nome.
    insert_symbol("local_var", TYPE_CHAR);
    insert_symbol("global_var_2", TYPE_INT); // Shadowing
    printf("[TESTE] Inserido 'local_var' (CHAR) e 'global_var_2' (INT) no escopo local.\n");

    // 6. Faz buscas com o escopo local ativo
    printf("... Realizando buscas com escopo local ativo ...\n");
    print_lookup_result("local_var");      // Deve encontrar a local
    print_lookup_result("global_var_1");   // Deve encontrar a global, pois não foi redeclarada localmente
    print_lookup_result("global_var_2");   // Deve encontrar a local (INT), e não a global (FLOAT)
    printf("\n");

    // 7. Fecha o escopo local
    printf("--- Fechando Escopo Local ---\n");
    close_scope();
    printf("[TESTE] Escopo local fechado.\n");

    // 8. Faz buscas novamente para garantir que o estado anterior foi restaurado
    printf("... Realizando buscas apos fechar o escopo ...\n");
    print_lookup_result("local_var");      // NÃO deve encontrar mais
    print_lookup_result("global_var_1");   // Deve encontrar a global
    print_lookup_result("global_var_2");   // Deve encontrar a global (FLOAT) novamente
    printf("\n");

    printf("--- TESTE CONCLUIDO ---\n");

    // Opcional: Chamar a função de destruição se você a implementou
    // destroy_scope_stack();

    return 0;
}