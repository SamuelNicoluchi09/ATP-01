#include <stdio.h>
#include <stdlib.h>

void imprime(int** A,int linhas, int colunas)
{
    if(A == NULL)return;
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf("%d  ",A[i][j]);
        }
        printf("\n");
    }
}