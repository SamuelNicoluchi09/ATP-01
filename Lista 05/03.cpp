#include<stdlib.h>
#include<stdio.h>

float celsius_para_fahrenheit(float c){
 return((c*9)/5+32);//faz a conversão e já retorna
}
int main(){
    float c,resultado;
    printf("Digite uma temperatura em celcius: \n");
    scanf("%f",&c);
    resultado = celsius_para_fahrenheit(c);//chama a funçao de conversão passando a temperatura em celcius digitado pelo user e atribui o valo em resultado
    printf("O valor da temperatura em fahrenheit eh:  ",resultado);
    return(0);
    getchar();
}