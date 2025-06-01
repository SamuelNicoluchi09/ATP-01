#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *v=NULL;
    v = (int *) calloc(6,sizeof(int));
    for(int i=1; i <= 6; i++) //i começa em um para que eu consiga quabra a linha quando i for igual divisivel por 3
    {
        printf("%d    ",v[i-1]);//i-1 pois i começa em 1 no for e não e 0
        if((i%3==0)&&(i!=0))//verificação para a quebra de linha
        {
            printf("\n");
        }
    }
    getchar();
    return 0;
}