#include<stdlib.h>
#include<stdio.h>

int calcula_imc(float peso, float altura){
    float imc= peso/(altura*altura);//faz o calculo com os valores peso e altura passados da main para a imprimaa e da imprima para essa função
    if(imc<18.5){//em cada condição retornará um número de acordo ccom o valor em q o imc encontra
        return 0;
    }else if(imc>=18.5 && imc<=24.9){
        return 1;
    }else if(imc>=25 && imc<=29.9){
        return 2;
    }else{
        return 3;
    }
}

void imprima_imc(float peso, float altura){
    int x=calcula_imc(peso,altura);//chama a função para calcular o imc, e conforme o valor atribuido em x, dirá a condiçãem que a pessoa está
    if(x==0){
        printf("A pessoa esta com magreza ");
    }else if(x==1){
        printf("A pessoa esta saudavel ");
    }else if(x==2){
        printf("A pessoa esta com sobrepeso ");
    }else if(x==3){
        printf("A pessoa esta com obesidade ");
    }
}
int main(){
   float altura,peso;
   printf("Digite a altura: \n");
   scanf("%f",&altura);
   printf("Digite o peso: \n");
   scanf("%f",&peso);
   imprima_imc(peso,altura);//chama a funnção passsando a altura e peso
   return 0;
   getchar();
}