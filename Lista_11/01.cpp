#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h> 

int main(int _argc, char *argv[])
{
    bool primo=false; //primeiro argumento digitado é o fim e o segundo o começo
    if (_argc < 2)
    {
        return 1;
    }
    for (int i = atoi(argv[2]); i < atoi(argv[1]); i++)//laço começa no começo digitado e vai até o fim digitado
    {
         primo = false;
        for (int j = 2; j < atoi(argv[1]); j++)//verifica cada termo para ver se eh divisivel no espaço determinado
        {
            if (i < 2)
            {
                printf("%d", i);
            }
            if(j !=  i)
            {
                if(i % j == 0){break;}//caso o número seja divisivel por qualquer outro já paro  essee laço e vou verificar o prox item da sequencia
                else{
                    primo =true;
                }
                
            }
        }
        if(primo == true)
        {
            printf("%d  ",i);
        }else{
            continue;
        }
    }
}