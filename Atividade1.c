#include <stdio.h>

int main() {
    int valores[10];
    int novos_valores[10];
    int i;

    for (i = 0; i < 10; i++) {
        scanf("%d", &valores[i]);
    }

    int iteracoes = 0; 
    while (iteracoes < 10) {
        int novo_tamanho = 10 - iteracoes;

        for (i = 0; i < novo_tamanho; i++) {
            printf("%d", valores[i]);
            if (i < novo_tamanho - 1) {
                printf(" ");
            }
        }
        printf("\n");

        if (novo_tamanho == 1) {
            break; 
        }

        for (i = 0; i < novo_tamanho - 1; i++) {
            novos_valores[i] = valores[i] + valores[i + 1];
        }

        for (i = 0; i < novo_tamanho - 1; i++) {
            valores[i] = novos_valores[i];
        }

        iteracoes++; 
    }

    return 0;
}