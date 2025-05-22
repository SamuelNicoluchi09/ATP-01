#include<stdio.h>
#include <stdlib.h>

int main()
{
    int vetor[5]={78,5,98,444,-1};
    int *p;
    for(p = vetor; *p != -1; p++)
    {
       printf("%d\n", *p);
    }
    return 0;
}