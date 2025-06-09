#include <stdio.h>
#include <stdlib.h>
int **alocaMatriz(int linhas,int colunas)
{
    int **A = (int **)calloc(linhas,sizeof(int*));
    if(A == NULL)
    {
        printf("Erro ao alocar!!");
        return NULL;
    }
    for(int i=0; i < linhas; i++)
    {
        A[i] = (int*)calloc(colunas,sizeof(int));
        if(A[i] == NULL)
        {
        printf("Erro ao alocar!!");
        return NULL;
        }
    }
    return A;
}
int main()
{
    int linhas,colunas;
    int **A;
    printf("Digite o número de linhas e colunas: \n");
    scanf("%d",&linhas);
    scanf("%d",&colunas);
    A=alocaMatriz(linhas,colunas);
    printf("Matriz: \n");
    for(int i=0; i < linhas; i++)
    {
        for (int j= 0; j < colunas; j++)
        {
           printf("%d ",A[i][j]);
        }
        printf("\n");
        
    }
    free(A);
    getchar();
    return 0;
}