#include <stdio.h>
#include <stdlib.h>
int **soma_matrizes(int A[3][3],int B[3][3])
{
    int **C= (int **)malloc(3*sizeof(int*));
    if(C==NULL)
    {
        printf("falha ao alocar a matriz!");
        return NULL;
    }
    for(int i=0; i<3; i++)
    {
        for (int j= 0; j < 3; j++) 
        {
           C[i] = (int *)malloc(3*sizeof(int));
           if(C[i]==NULL)
           {
            printf("Falha ao alocar a matriz. ");
            return NULL;
           }
        }        
    }
     for(int i=0; i<3; i++)
    {
        for (int j= 0; j < 3; j++) 
        {
           C[i][j] = A[i][j] + B[i][j];
        }        
    }
    return C;
}
int main()
{
    int A[3][3]={{3, 5, 8}, {8, 9, 6}, {7, 6, 1}};
    int B[3][3]={{80, 85, 78}, {18, 29, 76}, {47, 6, 51}};
    int **C;
    C=soma_matrizes(A,B);
    printf("Soma da matrizes: \n");
    for(int i=0; i<3; i++)
    {
        for (int j= 0; j < 3; j++)
        {
           printf("%d  ",C[i][j]);
        }
        printf("\n");
        
    }
  free(C);
  getchar();
  return 0;
}