int idade;
float salario;
char letra;
int notas[8];
float tabela[4][2];

struct produto {
    int codigo;
    float preco;
    char categoria;
}

int multiplicar(int x, int y) {
    int resultado;

    resultado = x * y + y - 3;

    return resultado;
}

int calcularSequencia(void) {
    int a;
    int b;
    int resultado;

    a = 2;
    b = 3;

    resultado = a * b + b;

    return resultado;
}

void atualizarValores(int dados[], int tamanho) {
    int i;

    i = 0;

    while (i < tamanho) {
        if (dados[i] < 50) {
            dados[i] = multiplicar(dados[i], 2);
        }
        else {
            dados[i] = 100;
        }
        i = i + 1;
    }
}

void main() {
    int contador;
    float media;
    int valores[4];

    contador = 0;
    media = 0.0;

    valores[0] = 12;
    valores[1] = 25;
    valores[2] = 48;
    valores[3] = 60;

    while (contador < 4) {
        if (valores[contador] >= 40) {
            valores[contador] = multiplicar(valores[contador], 2);
        }
        else {
            if (valores[contador] <= 20) {
                valores[contador] = valores[contador] + 10;
            }
        }

        contador = contador + 1;
    }

    media = (valores[0] + valores[1] + valores[2] + valores[3]) / 4;

    atualizarValores(valores, 4);

    if (media == 100.0) {
        contador = 200;
    }

    if (media != 0.0) {
        if (contador > 100) {
            contador = contador - 50;
        }
    }

    contador = (contador + 5) * (calcularSequencia() + 1);

    ;

    return;
}
