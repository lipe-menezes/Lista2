#include <stdio.h>

void lerMatriz(int matriz[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            scanf("%d", &matriz[i][j]);
        }
    }
}

void somarMatrizes(int matrizA[4][4], int matrizB[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            matrizA[i][j] += matrizB[i][j];
        }
    }
}


void subtrairMatrizes(int matrizA[4][4], int matrizB[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            matrizA[i][j] -= matrizB[i][j];
        }
    }
}


void multiplicarMatrizes(int matrizA[4][4], int matrizB[4][4], int resultado[4][4]) {
    int i, j, k;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            resultado[i][j] = 0;
            for (k = 0; k < 4; k++) {
                resultado[i][j] += matrizA[i][k] * matrizB[k][j];
            }
        }
    }
}

void imprimirMatriz(int matriz[4][4]) {
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 4; j++) {
            printf("%4d", matriz[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int matrizA[4][4], matrizB[4][4], resultado[4][4];
    char operacao[10];

    lerMatriz(matrizA);
    lerMatriz(matrizB);

    scanf("%s", operacao);

    if (operacao[0] == 's' && operacao[1] == 'u') { 
        subtrairMatrizes(matrizA, matrizB);
    } else if (operacao[0] == 'm') { 
        multiplicarMatrizes(matrizA, matrizB, resultado);
        imprimirMatriz(resultado);
        return 0;
    } else {
        somarMatrizes(matrizA, matrizB);
    }

    imprimirMatriz(matrizA);

    return 0;
}


