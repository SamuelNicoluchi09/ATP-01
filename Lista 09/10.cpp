#include <stdio.h>
#include <stdlib.h>

int** multplicaMatriz(int** A, int** B,int**Resultado, int linhas,int colunas )
{
    for (int i = 0; i < linhas; i++) {
        for (int j = 0; j < colunas; j++) {
            int soma = 0; 
            for (int k = 0; k < colunas; k++) { //  Esse loop calcula o produto escalar da linha i de A e coluna j de B
                soma += A[i][k] * B[k][j];
            }
            Resultado[i][j] = soma;
        }
    }
    return Resultado;
}

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
void liberaMatriz(int **A,int linhas)
{
    for(int i = 0; i < linhas; i++)
    {
        free(A[i]);
    }
    free(A);
}

int** preecheValores(int**A, int linhas, int colunas)
{
    for(int i = 0; i < linhas; i++)
    {
        for(int j = 0; j < colunas; j++)
        {
            printf("Digite o valor para a posicao[%d][%d]",i,j);
            scanf("%d",&A[i][j]);
        }
    }
    return A;
}

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
    printf("\n");
}



int main()
{
    int linhas,colunas;
    int** A;
    int** B;
    int** resultado;
    printf("Digite a quantidade de linhas e colunas das matrizes(apenas quadradas): \n");
    scanf("%d",&linhas);
    scanf("%d",&colunas);

    A = alocaMatriz(linhas,colunas);
    B = alocaMatriz(linhas,colunas);

    A = preecheValores(A,linhas,colunas);
    B = preecheValores(B,linhas,colunas);

    printf("Matriz 1: \n");
    imprime(A,linhas,colunas);

    printf("Matriz 2: \n");
    imprime(B,linhas,colunas);

    resultado = alocaMatriz(linhas,colunas);
    resultado = multplicaMatriz(A,B,resultado,linhas,colunas);

    printf("Resultado da multiplicacao escalar:\n ");
    imprime(resultado,linhas,colunas);
    
    liberaMatriz(A,linhas);
    liberaMatriz(B,linhas);
    liberaMatriz(resultado,linhas);
    getchar();
    return 0;




}