#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define NUM_CARTELAS 2


void embaralhar(int *v, int tamanho)// pegando nnumero aleatorios apra aquele vetor
{
    for (int i = tamanho - 1; i > 0; i--)
    {
        int j = rand() % (i + 1);
        int temp = v[i];
        v[i] = v[j];
        v[j] = temp;
    }
}

void preencher_coluna(int *coluna, int min, int max, int free)
{
    int intervalo = max - min + 1; // pegando a quantidade de numeros do intervalo dado
    int x[intervalo];              // criando um vetor com a quantidade de numeros nescessário em cada intervalo

    for (int i = 0; i < intervalo; i++)
    {
        x[i] = min + i;
    }

    embaralhar(x, intervalo);

    for (int i = 0, j = 0; j < 5; i++)
    {
        if (free && j == 2)
        { // vendo se haverá free naquele espaço
            coluna[j++] = -1;
            continue;
        }
        coluna[j++] = x[i]; // colocando valores na coluna daquele vetor
    }
}

int main()
{
    srand(time(NULL));

    FILE *f = fopen("bingo.csv", "w");
    if (!f)
    {
        printf("Erro!");
        return 1;
    }

    fprintf(f, "B,I,N,G,O\n"); // colocando a primeira linha

    for (int c = 0; c < NUM_CARTELAS; c++)
    {
        int b[5], i[5], n[5], g[5], o[5];

        preencher_coluna(b, 1, 15, 0);
        preencher_coluna(i, 16, 30, 0);
        preencher_coluna(n, 31, 45, 1); // a coluna que haverá um free
        preencher_coluna(g, 46, 60, 0);
        preencher_coluna(o, 61, 75, 0);

        for (int linha = 0; linha < 5; linha++) //printando cada linha, para formar a tablea
        {
            fprintf(f, "%d,", b[linha]);
            fprintf(f, "%d,", i[linha]);
            if (n[linha] == -1)
                fprintf(f, "FREE,");
            else
                fprintf(f, "%d,", n[linha]);
            fprintf(f, "%d,", g[linha]);
            fprintf(f, "%d\n", o[linha]);
        }
        if (c < NUM_CARTELAS - 1)
            fprintf(f, "\n"); // serve para separar as cartelas
    }

    fclose(f);
    getchar();
    return 0;
}
