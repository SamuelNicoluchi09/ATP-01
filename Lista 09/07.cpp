#include <stdio.h>
#include <stdlib.h>

void liberaMatriz(int **A,int linhas)
{
    for(int i = 0; i < linhas; i++)
    {
        free(A[i]);
    }
    free(A);
}
//Achei meio desnecessario fazer main para esse exercicio por isso comentei a main e deixei so a função 
/*int main()
{
    int** A;
    int linhas, colunas;
    printf("Digite o número de linhas e colunas da matriz: \n");
    scanf("%d",&linhas);
    scanf("%d",&colunas);
    A = (int**)calloc(linhas,sizeof(int));
    liberaMatriz(A,linhas);
}*/