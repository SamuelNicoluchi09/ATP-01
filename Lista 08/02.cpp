#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n,x;
    int* v=NULL;
    printf("Digite o tamanho do vetor ");
    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));
    for(int i=0; i < n; i++)
    {
        printf("Digite o valor para o %dº elemento do vetor: \n",i);
        scanf("%d",&x);
        v[i]=x;
        
    }
    for(int i=0; i < n; i++)
    {
    printf("%d \t ",v[i]);
    }
    free(v);
    getchar();
    return 0;
}