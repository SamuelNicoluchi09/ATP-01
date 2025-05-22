#include <stdio.h>
#include <stdio.h>

void inverte(int *A, int t) {
    int *comeco = A,temp=0;
    int *final = A + t - 1; //menos 1 pois ele começa no zero e não no 1   
    while (comeco < final) {
         temp = *comeco; // faço a troca dos valores utilizando uma variavel temporaria
        *comeco = *final;
        *final = temp;
        comeco++; //avaço uma cas do vetor do começo para frente eu recuo uma do vetor do final, para trocalas de posição
        final--;
    }
   
}

int main ()
{
    int A[5]={1,2,3,4,5};
    printf("Vetor original: \n");
      for(int i = 0; i < 5; i++)
    {
        printf("%d\t",A[i]);
    }

    inverte(A,5);
    printf("\nO vetor invertido: \n");
     for(int i = 0; i < 5; i++)
    {
        printf("%d\t",A[i]);
    }

}