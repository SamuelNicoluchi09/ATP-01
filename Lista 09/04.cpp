#include <stdio.h>
#include <stdlib.h>

void somaDiagonal(int A[3][3])
{
    int soma=0;
    for(int i=0; i < 3; i++)
    {
        for (int j= 0; j < 3; j++)
        {
           if(i == j)
           {
            soma += A[i][j];
           }
        }  
    }
    printf("A soma da diagonal priincipal da matriz eh: %d", soma);
}

int main()
{
    int A[3][3] = {{1,2,3}, {78,99,66}, {44,652,396}};
    somaDiagonal(A);
    getchar();
    return 0;
}