#include<stdlib.h>
#include<stdio.h>
int a=1,b=2,c=3;
float quadratica(float x){
  return a*x*x+b*x+c; //retorna o vallor calculado  pelo x passado pelo user
}
int main(){
    float x, resultado;
    printf("Digite um x para vericar seu valor na funcao: \n");
    scanf("%f",&x);
    resultado=quadratica(x);//chama a função e armazena o resultado em resultado
    printf("O resultado eh: %2.f",resultado);
    return(0);
    getchar();
}