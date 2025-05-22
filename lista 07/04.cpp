#include <stdio.h>
#include <stdio.h>

void same(int *A,int *B,int t)
{
   int x[5];
   for(int i = 0; i < 5; i++)
   {
    for(int j = 0; j < 5; j++) 
    {
      if(A[i]==B[j])
      {
        x[i]=A[i];
        break;
      }
      else{
         x[i]=-1;//Espaços que contem o -1, são vazios
      }
    }
   }
   printf("Os valores que estao presentes em ambos vetores sao: \n");
   for(int i = 0; i < t; i++)
   {
     printf("%d\n",x[i]);
   }
}

int main()
{
    int A[5]={1,4,5,6,7}, B[5]{3,5,4,7,8};
    same(A,B,5);

}