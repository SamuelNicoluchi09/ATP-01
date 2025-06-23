#include <stdio.h>
#include <stdlib.h>
#include <math.h>

float arredonda(float valor, float casas=0)
{
    float auxiliar = pow(10,casas);//vendo por quantas casas decimais vou multiplicar o  numero para poder usar o round e arredondar
    return(round(valor * auxiliar)/auxiliar);//depois uso o round e divido pelo msm auxiliar para mater  o mesmo numero
}

int main()
{
    float n1= 3.14159, n2=89.5589;
    printf("Arredondando n1 com 1 casa: %0.1f\n ",arredonda(n1,1));
    printf("Arredondando n1 com 2 casa: %0.2f\n ",arredonda(n1,2));
    printf("Arredondando n1 com 0 casa: %0.0f\n ",arredonda(n1));
    printf("Arredondando n2 com 1 casa: %0.1f\n ",arredonda(n2,1));
    printf("Arredondando n2 com 0 casa: %0.0f\n ",arredonda(n2));

}