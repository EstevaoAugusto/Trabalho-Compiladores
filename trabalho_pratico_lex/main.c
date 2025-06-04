#include <stdio.h>

extern FILE *yyin;
extern int yyparse();

int main(int argc, char *argv[]) {
    if (argc < 2) {
        fprintf(stderr, "Uso: %s <arquivo_de_entrada>\n", argv[0]);
        return 1;
    }

    yyin = fopen(argv[1], "r");
    if (!yyin) {
        perror("Nao foi possível abrir o arquivo");
        return 1;
    }

    yyparse();
    fclose(yyin);

    printf("Analise concluida com sucesso.\n");
    return 0;
}
