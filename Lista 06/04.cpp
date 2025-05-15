#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int potencia(int base,int expoente)
{
    if(expoente<=0){
        return 1;//quando o expoente for menor ou igual a 1 ele retorna 1, para quebrar o loop
    }
    return base*potencia(base,expoente-1);//vai multiplicar base x base, a quantidade de vezes que é indicada pelo expoente, o expoente serve como um contador
}

int main()
{
    int base,expoente;
    printf("Digite a base e o expoente: \n");
    scanf("%d %d",&base,&expoente);//leitura da base e expoente
    printf("A potencia eh eh %d.",potencia(base,expoente));//chamada de função já printando o valor retornado

}