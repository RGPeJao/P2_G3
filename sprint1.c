#include <stdio.h>

int main(){
    int x;
    float temp;

    printf("Digite um número:");
    scanf("%d", &x);

    temp = 260.0*x/1023.0-20.0;

    printf("O valor da temperatura:%.2f °C\n", temp);
    
    return 0;

}
