#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int cont=0;

int contagem(int n)
{
 
    if(n<10){
        cont++;// se o numero for menor qque 10, logo terá apenas um digito, então quebra o loop.
        return 0;
    }
    else{
        contagem(n/10);// vai chamar a função mais uma vez, até o número for menor que dez
        cont++;//como os nossos numeros sao decimaiss, ent sempre que ele for divisivel por 10, então ele terá umm digito, atee´ficar menor que 10
    }  //o cont fica numa variavel global para facilitar sua mudança
  
}

int main()
{
    int n;
    printf("Digite um numero: \n");
    scanf("%d",&n);
    contagem(n);// apenas chma a funçõa e como ela nn retorna nada, pois ela altera a vaariavel globarl, logo não preciso atribuir a nada, aapenas chama-la
    printf("O numero de digitos eh %d:",cont);//printa a variavel global
    return 0;

}