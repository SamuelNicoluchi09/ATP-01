#include <stdio.h>
#include <stdio.h>

int search(int x, int t, int *v)
{
    int z=0;
    for(int i = 0; i < t; i++)
    {
        if(v[i]==x)
        {
            z=1;
        }
        
    }
    if(z==0)
    {
        return 0;
    }
    else{
        return 1;
    }
}

int main()
{
   int v[5]={0,3,2,8,4},x;
   printf("Digite o numero que deseja encontrar: ");
   scanf("%d",&x);
   if(search(x,5,v)==0)
   {
    printf("O vetor não possui o valor %d ",x);
   }else{
    printf("O vetor possui o valor %d ",x);
   }
}