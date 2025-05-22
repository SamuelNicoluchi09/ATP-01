#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    char palavra[100];
    printf("Digite uma palavra: \n");
    scanf("%s",palavra);
    printf("A palavra: %s comeca com: %c",palavra,palavra[0]);
    return 0;
 
}