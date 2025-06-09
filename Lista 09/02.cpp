#include <stdlib.h>
#include <stdio.h>

int** transposta(int A[3][3])
{
   int** B=(int**) calloc(3,sizeof(int*));
   if(B==NULL)
   {
     printf("Falha ao alocar a matriz. ");
     return NULL;
   }
   for(int i = 0; i <= 3; i++)
   {
    B[i] = (int*) calloc(3,sizeof(int));
    if(B[i]==NULL)
    {
     printf("Falha ao alocar a matriz. ");
     return NULL;
    }
   }
   for(int i = 0; i < 3; i++)
   {
    for(int j = 0; j < 3; j++)
    {
        B[i][j]=A[j][i];
    }
   }
   return B;

}

int main()
{
  int A[3][3]={{3,5,9},{1,2,7},{1,6,4}};
  int** B;
  B=transposta(A);
  for(int i = 0; i < 3; i++)
  {
    for(int j = 0; j < 3; j++)
    {
        printf("%d  ",B[i][j]);
    } 
    printf("\n");
  }
  free(B);
  getchar();
  return 0;

}