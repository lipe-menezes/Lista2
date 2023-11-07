#include <stdio.h>

float calcularForcaPonderada(int forcaGoleiro, int forcaLaterais[], int forcaZagueiros[], int forcaVolantes[], int forcaMeias[], int forcaAtacantes[]) {
    float forcaTotal = (8 * forcaGoleiro + 10 * (forcaLaterais[0] + forcaLaterais[1]) +
                        5 * (forcaZagueiros[0] + forcaZagueiros[1]) +
                        8 * (forcaVolantes[0] + forcaVolantes[1]) +
                        11 * (forcaMeias[0] + forcaMeias[1]) +
                        12 * (forcaAtacantes[0] + forcaAtacantes[1])) / 100.0;
    return forcaTotal;
}

int main() {
    char nomeTime[2][31];
    int forcaGoleiro[2];
    int forcaLaterais[2][2];
    int forcaZagueiros[2][2];
    int forcaVolantes[2][2];
    int forcaMeias[2][2];
    int forcaAtacantes[2][2];

    int i, j;

    for (i = 0; i < 2; i++) {
        printf("Nome do time %d: ", i + 1);
        scanf("%30s", nomeTime[i]);

        forcaGoleiro[i] = 0;
        forcaLaterais[i][0] = forcaLaterais[i][1] = 0;
        forcaZagueiros[i][0] = forcaZagueiros[i][1] = 0;
        forcaVolantes[i][0] = forcaVolantes[i][1] = 0;
        forcaMeias[i][0] = forcaMeias[i][1] = 0;
        forcaAtacantes[i][0] = forcaAtacantes[i][1] = 0;

        printf("Jogadores do time %d:\n", i + 1);
        for (j = 0; j < 11; j++) {
            char nomeJogador[31];
            char posicao[2];
            int forca;

            printf("Nome, Posicao, Forca (separados por virgula): ");
            scanf("%30s, %c, %d", nomeJogador, posicao, &forca);

            switch (posicao[0]) {
                case 'G':
                    forcaGoleiro[i] = forca;
                    break;
                case 'L':
                    forcaLaterais[i][0] = forca;
                    forcaLaterais[i][1] = forca;
                    break;
                case 'Z':
                    forcaZagueiros[i][0] = forca;
                    forcaZagueiros[i][1] = forca;
                    break;
                case 'V':
                    forcaVolantes[i][0] = forca;
                    forcaVolantes[i][1] = forca;
                    break;
                case 'M':
                    forcaMeias[i][0] = forca;
                    forcaMeias[i][1] = forca;
                    break;
                case 'A':
                    forcaAtacantes[i][0] = forca;
                    forcaAtacantes[i][1] = forca;
                    break;
                default:
                    printf("Posicao invalida. Use G, L, Z, V, M ou A.\n");
                    j--;
                    break;
            }
        }
    }

    float forcaTime1 = calcularForcaPonderada(forcaGoleiro[0], forcaLaterais[0], forcaZagueiros[0], forcaVolantes[0], forcaMeias[0], forcaAtacantes[0]);
    float forcaTime2 = calcularForcaPonderada(forcaGoleiro[1], forcaLaterais[1], forcaZagueiros[1], forcaVolantes[1], forcaMeias[1], forcaAtacantes[1]);

    printf("Forca do %s: %.2f\n", nomeTime[0], forcaTime1);
    printf("Forca do %s: %.2f\n", nomeTime[1], forcaTime2);

    if (forcaTime1 > forcaTime2) {
        printf("%s e o time mais forte.\n", nomeTime[0]);
    } else if (forcaTime2 > forcaTime1) {
        printf("%s e o time mais forte.\n", nomeTime[1]);
    } else {
        printf("Os times tem a mesma forca.\n");
    }

    return 0;
}
