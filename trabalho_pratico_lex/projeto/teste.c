#include <stdio.h>
#include <stdbool.h>  // Adiciona suporte ao tipo bool

// Comentário de uma linha
/*
   Comentário de múltiplas linhas
   Continua aqui...
*/

int main() {
    int idade = 25;
    float altura = 1.75;
    char letra = 'A';
    double salario = 12345.67E+2;  // Notação científica
    bool ativo = true;

    if (idade >= 18) {
        printf("Maior de idade\n");
    } else {
        printf("Menor de idade\n");
    }

    while (idade < 30) {
        idade = idade + 1;
    }

    return 0;
}
