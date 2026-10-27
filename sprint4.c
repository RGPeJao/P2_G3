#include <stdio.h>
#include <math.h>

#define maxLeituras 6

int main(){

    int x;
    float temp;
    float temperaturas[maxLeituras];
    int n = 0;

    printf("Digite um número entre 0 e 1023:\n(Máximo de leituras: %d)\n", maxLeituras);
    printf("Introduza -1 para encerrar o programa\n");
    
    while(n < maxLeituras) {
        if(scanf("%d", &x) != 1) {
            printf("Valor inválido. Digite um número inteiro:\n");
            while (getchar() != '\n');
            continue;
            }
        
        while (getchar() != '\n');

        if(x == -1){
            break;
        }
    
        temp = 260.00*x/1023.00 - 20.00;
        

        if( temp < -10 || temp > 190) {
            printf("Valor fora da gama. Introduza um novo valor:\n");
        } else { 
            printf("A temperatura é:\n%.2f\n" , temp);
            temperaturas[n] = temp;
            n++;
            
            if(n < maxLeituras){
            printf("Digite mais um valor:\n");
            }
        }
    }

    printf("Leitura terminada.\n");

    if ( n == 0){
        printf("Não foram lidos valores.\n");
        return 0;
    }
    
    printf("\nValores lidos:\n");
    for (int i = 0; i < n; i++) {
        printf("%d: %.2f\n", i + 1, temperaturas[i]);
    }

    float max = temperaturas[0];
    float min = temperaturas[0];
    float soma = 0;

    for (int i = 0; i < n; i++) {
        if (temperaturas[i] > max) max = temperaturas[i];
        if (temperaturas[i] < min) min = temperaturas[i];
        
        soma += temperaturas[i];
    }

    float media = soma / n;
    float soma_quadrados = 0;
    
    for (int i = 0; i < n; i++) {
        float dif = temperaturas[i] - media;
        soma_quadrados += dif * dif;
    }
    
    float desvio = sqrt(soma_quadrados / n);

    printf("\nNúmero de valores lidos: %d\n", n);
    printf("Máximo: %.2f\n", max);
    printf("Mínimo: %.2f\n", min);
    printf("Média: %.2f\n", media);
    printf("Desvio-padrão: %.2f\n", desvio);

    return 0;
}
