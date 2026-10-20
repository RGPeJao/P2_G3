#include <stdio.h>

int main() {
    int x;
    float temp;
    int estado_leitura;

    while (1) {
        printf("Introduza o valor do sensor (-1 para terminar): ");
        estado_leitura = scanf("%d", &x);

        while (estado_leitura != 1) {
            while (getchar() != '\n');
            printf("Valor invalido!\nPor favor, introduza um numero inteiro: ");
            estado_leitura = scanf("%d", &x);
        }

        if (x == -1) {
            break;
        }

        temp = (260.0 * x / 1023.0) - 20.0;

        if (temp >= -10.0 && temp <= 190.0) {
            printf("%.2f °C\n", temp);
        } else {
            printf("Valor fora da gama\n");
        }
    }

    return 0;
}
