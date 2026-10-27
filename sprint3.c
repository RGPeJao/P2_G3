#include <stdio.h>

int main(){

    int x;
    float temp;

    printf("Digite um número entre 0 e 1023:\n(Introduza -1 para encerrar o programa)\n");
    
    while(1) {
        if(scanf("%d", &x) != 1) {
            printf("Valor inválido. Digite um número inteiro:\n");
            while (getchar() != '\n');
            continue;
            }
        
        while (getchar() != '\n');

        if(x == -1){
            printf("Programa encerrado.\n");
            break;
        }
    
        temp = 260.00*x/1023.00 - 20.00;
        

        if( temp < -10 || temp > 190) {
            printf("Valor fora da gama. Introduza um novo valor:\n");
        } else { 
            printf("A temperatura é:\n%.2f\n" , temp);
            printf("Digite mais um valor:\n");
        }

    }

    return 0;
}
