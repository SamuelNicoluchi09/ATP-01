#include<stdio.h>
#include<stdlib.h>

typedef struct
{
    int inteiro,decimal;
}Numero;

Numero* soma(Numero *a, Numero *b)
{
    Numero *s;
    s->inteiro=a->inteiro+b->inteiro;
    s->decimal=a->decimal+b->inteiro;
    if(s->decimal>1000)//considerando que os números possuem quatro casas
    {
        s->inteiro++;
        s->decimal-=1000;
    }
   return s;
}
Numero* subtracao(Numero *a, Numero *b)
{
    Numero *s;
    s->inteiro=a->inteiro-b->inteiro;
    s->decimal=a->decimal-b->inteiro;
    if(s->decimal>0)//considerando que os números possuem quatro casas
    {
        s->inteiro--;
        s->decimal+=1000;
    }
    return s;
}

void imprime(Numero *a){
 printf("%d.%d",a->inteiro,a->decimal);
}

int main()
{
    Numero a,b;
    a={2,5897};
    b={8,8890};
    printf("Soma:\n");
    imprime(soma(&a,&b));
    printf("Subtração:\n");
    imprime(subtracao(&a,&b));
    getchar();
    return 0;

}