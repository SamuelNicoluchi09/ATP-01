#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int r=0;
    r= 2 + rand()  % 11 ;// pega um nuero de 2 a 12
    printf("O numero sorteado eh: %d",r);//printa o numero obtido

}