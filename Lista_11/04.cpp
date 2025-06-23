#include <stdio.h>
#include <stdlib.h>

int main()
{
    int x;
    int **A;
    int **B;
    int **S;
    FILE *f = fopen("matriz.txt", "r");
    if (f == NULL)
    {
        printf("Erro!");
        return 1;
    }

    fscanf(f, "%d", &x); // pegando a ordem da matriz
    A = (int **)calloc(x, sizeof(int *));
    if (A == NULL)
    {
        return 1;
    }
    for (int i = 0; i < x; i++)
    {
        A[i] = (int *)calloc(x, sizeof(int *));
        if (A[i] == NULL)
        {
            return 1;
        }
    }
    B = (int **)calloc(x, sizeof(int *));
    if (B == NULL)
    {
        return 1;
    }
    for (int i = 0; i < x; i++)
    {
        B[i] = (int *)calloc(x, sizeof(int *));
        if (B[i] == NULL)
        {
            return 1;
        }
    }
    S = (int **)calloc(x, sizeof(int *));
    if (S == NULL)
    {
        return 1;
    }
    for (int i = 0; i < x; i++)
    {
        S[i] = (int *)calloc(x, sizeof(int *));
        if (S[i] == NULL)
        {
            return 1;
        }
    }

    for (int i = 0; i < x; i++)//Matriz A
    {
        for (int j = 0; j < x; j++)
            fscanf(f, "%d", &A[i][j]);
    }

    
    for (int i = 0; i < x; i++){//MAtriz B
        for (int j = 0; j < x; j++)
            fscanf(f, "%d", &B[i][j]);
    }
    for (int i = 0; i < x; i++)//soma
    {
        for (int j = 0; j < x; j++)
            S[i][j] = A[i][j] + B[i][j];
    }   
    printf("Soma:\n");
    for (int i = 0; i < x; i++)
    {
        for (int j = 0; j < x; j++)
            printf("%d ", S[i][j]);
        printf("\n");
    }

    fclose(f);
    return 0;
}
