#include <stdio.h>
#include <stdlib.h>

int* par(int *v, int n)
{
    int cont=0,j=0;
    int *s;
    for(int i=0; i < n; i++)
     {
      if(v[i]%2==0)
      {
       cont++; //verifica o tamanho do vtor necessário de acordo com a qtd de par no vetor original v.
      }
    }
    s = (int*) malloc(cont * sizeof(int));

    for(int i=0; i < n; i++)
     {
      if(v[i]%2==0)
      {
         s[j]=v[i];//caso o elemento do vetor original for par, ele é atribuido em s.
         j++; //o j funciona como uma variavel que mostrara onde no vetor s ele será alocado, por isso começa como 0 e
         //sempre que é atribuido um valor em s, o j é acrecido em 1, para andar para o proximo local do vetor     
      }
    }
    
    return s;
}

int main()
{
    int n,x,p=0;
    int *v=NULL;
    int *s=NULL;
    printf("Digite um numero: ");
    scanf("%d", &n);
    v = (int*) malloc(n * sizeof(int));
    
    for(int i=0; i < n; i++)
    {
        printf("Digite o valor para o elemento %d do vetor: \n",i);
        scanf("%d",&x);
        if(x%2) p++;  //verifica quantos pares há no vetor para printar com o for no final     
        v[i]=x;
        
    }
    if(v == NULL)
    {
        printf("Falha ao instanciar o vetor v.");
        return 1;
    }
    s = par(v,n);
    if(s == NULL)
    {
        printf("Falha ao instanciar o vetor s.");
        return 1;
    }
    printf("\n Novo vetor, somente com pares: \n");
    for(int i=0; i < p; i++)
    {
        printf("%d \t ",s[i]);
    }
    free(v);
    free(s);
    getchar();
    return 0;
}