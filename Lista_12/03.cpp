#include <stdio.h>
#include <stdlib.h>



typedef struct no
{
    int coluna, x;
    struct no *prox;
} No;

typedef struct linha
{
    int linha;
    No *primeiro;
    struct linha *prox;
} Linha;

typedef struct
{
    int linha, coluna;
    Linha *primeira;
} Matriz;

Matriz* gerando(int linha, int coluna)
{
    Matriz *m=(Matriz*)calloc(linha,sizeof(Matriz));
    m->linha=linha;
    m->coluna=coluna;
    m->primeira=NULL;
    return m;
}

void inserirValor(Matriz* m, int linha, int coluna, int valor) {

    Linha* l = m->primeira;
    Linha* antLinha = NULL;
    while (l != NULL && l->linha < linha) {
        antLinha = l;
        l = l->prox;
    }

    if (l == NULL || l->linha != linha) {
        // Cria nova linha
        Linha* novaLinha = (Linha*)malloc(sizeof(Linha));
        novaLinha->linha = linha;
        novaLinha->primeiro = NULL;
        novaLinha->prox = l;

        if (antLinha == NULL) {
            m->primeira = novaLinha;
        } else {
            antLinha->prox = novaLinha;
        }

        l = novaLinha;
    }

    No* n = l->primeiro;
    No* antCelula = NULL; //inserindo os nos
    while (n != NULL && n->coluna < coluna) {
        antCelula = n;
        n = n->prox;
    }

    if (n != NULL && n->coluna == coluna) {
        n->x = valor; // att os valores
    } else {
        No* novaCelula = (No*)malloc(sizeof(No));
        novaCelula->coluna = coluna;
        novaCelula->x = valor;
        novaCelula->prox = n;

        if (antCelula == NULL) {
            l->primeiro = novaCelula;
        } else {
            antCelula->prox = novaCelula;
        }
    }
}
void imprimirMatriz(Matriz* m) {
    for (int i = 0; i < m->linha; i++) {
        Linha* l = m->primeira;
        while (l != NULL && l->linha < i) l = l->prox;

        No* c = (l != NULL && l->linha == i) ? l->primeiro : NULL;

        for (int j = 0; j < m->coluna; j++) {
            if (c != NULL && c->coluna == j) {
                printf("%3d ", c->x);
                c = c->prox;
            } else {
                printf("  0 ");
            }
        }
        printf("\n");
    }
}
int main() {
    Matriz* m = gerando(2, 3);

    inserirValor(m, 1, 2, 2);
    inserirValor(m, 1, 3, 8);
    inserirValor(m, 0, 2, 4);
    inserirValor(m, 0, 0, 1);

    imprimirMatriz(m);

    return 0;
}


