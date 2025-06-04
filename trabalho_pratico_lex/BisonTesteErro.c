inta a;             /* Erro 1: palavra reservada incorreta "inta" */
float b
string c;           /* Erro 2: falta de ponto e vírgula na linha anterior */

a = "texto";        /* Erro 3: atribuição de string para inteiro */
b = 5..2;           /* Erro 4: número de ponto flutuante inválido */
c = Teste;          /* Erro 5: string sem aspas */

if a > 3 {          /* Erro 6: falta de parênteses no if */
    b = b + 1.0;
}

while (a < 10)      /* Erro 7: falta de chaves no while */
    a = a + 1;      /* Erro 8: falta de bloco ou chaves obrigatórias */

read();             /* Erro 9: read sem parâmetro */
write(x);           /* Erro 10: variável 'x' não declarada */
