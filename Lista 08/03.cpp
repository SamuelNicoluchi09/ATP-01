#include <stdio.h>
#include <stdlib.h>

int main()
{
    int n=0,x=0;
    int *v=NULL;
    v = (int *) calloc(1 , sizeof(int));
    if(v==NULL) return 1;
    while (x != -1)
    {
     scanf("%d",&x); 
     getchar();
     if(x != -1)
     {
        n++;
        realloc(v , n * sizeof(int));
        v[n-1]=x;
     }  
    }
    for(int i=0; i < n; i++)
    {
    printf("%d \t ",v[i]);
    } 

    free(v);
    getchar();
    return 0;
}