    int x  /* Erro 1: Falta de ponto-e-vírgula na declaração de x */
    real y;
    bool flag;

    x = 10  /* Erro 2: Falta de ponto-e-vírgula após a atribuição */
    y = 3.14; 
    flag = true;

    if x > 0 then {  /* Erro 3: Parênteses ausentes na condição do if */
        write("Positive");
    } else 
        write("Non-positive");  /* Erro 4: Bloco do else sem chaves */

    while (x > 0 {  /* Erro 5: Parêntese de fechamento ausente na condição do while */
        x = x - 1;
        write(x);
    }

    for int i = 0; i < 5; i = i + 1) {  /* Erro 6: Estrutura incorreta do for (falta abrir parênteses após "for") */
        write("i: ");
        write(i);
    }

    switch (x) {
        case 0: 
            write("Zero");
        case )10: {  /* Erro 7: Parêntese extra e sintaxe incorreta no case para o número 10 */
            write("Ten");
        break;        /* Erro 8: 'break' mal posicionado devido à estrutura incorreta do case */
        default: {
            write("Other");
        }
    /* Erro 9: Chave de fechamento ausente para o bloco switch */

    fucntion soma(int a, int b) {  /* Erro 10: Palavra-chave incorreta ("fucntion" em vez de "function") */
        return a + b;
    /* Erro 11: Chave de fechamento ausente para o corpo da função 'soma' */

    int result;
    result = soma(x, 5);
    write("Result: ");
    write(result);
