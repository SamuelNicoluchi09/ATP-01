#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int soma(int n)
{
    if(n<=1){
        return 1;//quebra o loop
    }
    return n+soma(n-1);//soma o numero mais o seu antecessor até chegar em um
}

int main()
{
    int n;
    printf("Digite um numero: \n");
    scanf("%d",&n);
    printf("A soma eh %d:",soma(n));

}