#include <stdio.h>
#include <math.h>

#define MAX_LEITURAS      6
#define SENTINELA         -1
#define SENSOR_MAX        1023.00
#define TEMP_ESCALA       260.00
#define TEMP_OFFSET       20.00
#define TEMP_MIN_VALIDA   -10.0
#define TEMP_MAX_VALIDA   190.0

float converter_para_temperatura(int valor_sensor) {
    return TEMP_ESCALA * valor_sensor / SENSOR_MAX - TEMP_OFFSET;
}

int temperatura_valida(float temperatura) {
    return temperatura >= TEMP_MIN_VALIDA && temperatura <= TEMP_MAX_VALIDA;
}


float calcular_minimo(const float valores[], int n) {
    float minimo = valores[0];
    for (int i = 1; i < n; i++) {
        if (valores[i] < minimo) minimo = valores[i];
    }
    return minimo;
}

float calcular_maximo(const float valores[], int n) {
    float maximo = valores[0];
    for (int i = 1; i < n; i++) {
        if (valores[i] > maximo) maximo = valores[i];
    }
    return maximo;
}

float calcular_media(const float valores[], int n) {
    float soma = 0;
    for (int i = 0; i < n; i++) {
        soma += valores[i];
    }
    return soma / n;
}

float calcular_desvio_padrao(const float valores[], int n, float media) {
    float soma_quadrados = 0;
    for (int i = 0; i < n; i++) {
        float dif = valores[i] - media;
        soma_quadrados += dif * dif;
    }
    return sqrt(soma_quadrados / n);
}

void limpar_buffer_entrada(void) {
    while (getchar() != '\n');
}

int ler_leituras(float temperaturas[], int max_leituras) {
    int n = 0;
    int valor_sensor;

    while (n < max_leituras) {
        if (scanf("%d", &valor_sensor) != 1) {
            printf("Valor inválido. Digite um número inteiro:\n");
            limpar_buffer_entrada();
            continue;
        }

        limpar_buffer_entrada();

        if (valor_sensor == SENTINELA) {
            break;
        }

        float temperatura = converter_para_temperatura(valor_sensor);

        if (temperatura_valida(temperatura) == 0) {
            printf("Valor fora da gama. Introduza um novo valor:\n");
        } else {
            printf("A temperatura é:\n%.2f\n", temperatura);
            temperaturas[n] = temperatura;
            n++;

            if (n < max_leituras) {
                printf("Digite mais um valor:\n");
            }
        }
    }
    return n;
}

void apresentar_instrucoes(int max_leituras) {
    printf("Digite um número entre 0 e 1023:\n(Máximo de leituras: %d)\n", max_leituras);
    printf("Introduza -1 para encerrar o programa\n");
}

void apresentar_valores(const float valores[], int n) {
    printf("\nValores lidos:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %.2f\n", i + 1, valores[i]);
    }
}

void apresentar_estatisticas(const float valores[], int n) {
    float media = calcular_media(valores, n);

    printf("\nNúmero de valores lidos: %d\n", n);
    printf("Máximo: %.2f\n", calcular_maximo(valores, n));
    printf("Mínimo: %.2f\n", calcular_minimo(valores, n));
    printf("Média: %.2f\n", media);
    printf("Desvio-padrão: %.2f\n", calcular_desvio_padrao(valores, n, media));
}

int main(void) {
    float temperaturas[MAX_LEITURAS];

    apresentar_instrucoes(MAX_LEITURAS);
    int n = ler_leituras(temperaturas, MAX_LEITURAS);

    printf("Leitura terminada.\n");

    if (n == 0) {
        printf("Não foram lidos valores.\n");
        return 0;
    }

    apresentar_valores(temperaturas, n);
    apresentar_estatisticas(temperaturas, n);

    return 0;
}
