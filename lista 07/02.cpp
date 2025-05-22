#include <stdio.h>
#include <stdlib.h>
int main()
{
    int a[5],b[5];
    for(int i=0; i < 5; i++)
    {
        printf("Digite o valor para o espaco %d do vetor A: ",i);
        scanf("%d",&a[i]);
        printf("Digite o valor para o espaco %d do vetor B: ",i);
        scanf("%d",&b[i]);
    }  
    for(int j = 0; j < 5; j++)
    {
        printf(" %d, %d,",a[j],b[j]); 
    }
    return 0;
}