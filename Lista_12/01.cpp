#include <stdlib.h>
#include <stdio.h>

typedef struct
{
    float prova1, prova2, lista;

} Alunos;

float calculaMedia(Alunos a)
{
    return (((a.prova1 * 0.4) + (a.prova2 * 0.6)) * 0.8 + a.lista * 0.2);
}

int main()
{
    Alunos a;
    float media;
    a.lista=10;
    a.prova1=8;
    a.prova2=6;
    media=calculaMedia(a);
    printf("A media do aluno eh: %0.2f",media);
    getchar();
    return 0;

}