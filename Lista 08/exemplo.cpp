#include <stdio.h>
#include <stdlib.h>

int main()
{
    int* v;
    int quanto, tamanho, um_inteiro;
   /*
    quanto = 100;
    v = (int*) malloc(quanto * sizeof(int));
    free(v);*/
    um_inteiro=sizeof(int);
    scanf("%d",&quanto);
    tamanho=um_inteiro*quanto;
    v = (int*) malloc(tamanho);
    free(v);
}