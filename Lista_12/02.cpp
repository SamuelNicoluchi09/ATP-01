#include <stdlib.h>
#include <stdio.h>
#include <string.h>

typedef struct
{
    char nome[50];
    float prova1, prova2, lista;
} Alunos;

typedef struct no
{
    Alunos *aluno;
    struct no *prox;
} No;

float calculaMedia(Alunos *a)
{
    return (((a->prova1 * 0.4) + (a->prova2 * 0.6)) * 0.8 + a->lista * 0.2);
}

void imprimeMedia(No *listaAluno)
{
    No *atual = listaAluno;
    while (atual != NULL)
    {
        printf("%s: %0.2f", atual->aluno->nome, calculaMedia(atual->aluno));
        atual = atual->prox;
        printf("\n");
    }
}

int main()
{
    Alunos a;
    Alunos b;
    No na, nb;
    strcpy(a.nome, "Samuel");
    a.prova1 = 10;
    a.prova2 = 8;
    a.lista = 10;
    strcpy(b.nome, "Roberto");
    b.prova1 = 8;
    b.prova2 = 7;
    b.lista = 10;
    na.aluno = &a;
    na.prox = &nb;
    nb.aluno = &b;
    nb.prox = NULL;
    printf("Printando os alunos e suas medias: \n");
    imprimeMedia(&na);
    getchar();
    return 0;
}