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
    int** A;
    int** B;
    int** resultado;


    A = alocaMatriz(3,3);
    B = alocaMatriz(3,3);

    A = preecheValores(A,3,3);
    B = preecheValores(B,3,3);

    printf("Matriz 1: \n");
    imprime(A,3,3);

    printf("Matriz 2: \n");
    imprime(B,3,3);

    resultado = alocaMatriz(3,3);
    resultado = multplicaMatriz(A,B,resultado,3,3);

    printf("Resultado da multiplicacao escalar: ");
    imprime(resultado,3,3);
    
    liberaMatriz(A,3);
    liberaMatriz(B,3);
    liberaMatriz(resultado,3);
    getchar();
    return 0;




}