#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n;
    int *v=NULL;
    printf("Digite um numero: ");
    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));
    for(int i=0; i < n; i++)
    {
        v[i]=i+1;
        printf("%d \t ",v[i]);
    }
    free(v);
    return 0;
}