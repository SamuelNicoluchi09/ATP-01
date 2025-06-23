#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

int main()
{

    int cod[MAX];
    char n[MAX][50];
    float p[MAX];
    int qtd;
    int pedidoCodigos[MAX], pedidoQuantidades[MAX], totalPedidos = 0;
    char continuar = 's';
    FILE *f = fopen("menu.txt", "r");
    if (f == NULL)
    {
        perror("Erro ao abrir menu.txt");
        return 1;
    }

    fscanf(f, "%d", &qtd);

    // Lê os itens do menu
    for (int i = 0; i < qtd; i++)
    {
        fscanf(f, "%d %s %f", &cod[i], n[i], &p[i]);
    }

    // Mostrar menu
    printf("=== MENU ===\n");
    for (int i = 0; i < qtd; i++)
    {
        printf("%d - %-15s R$ %.2f\n", cod[i], n[i], p[i]);
    }

    while (continuar == 's' || continuar == 'S')
    {
        int cod, qtd;
        printf("Digite o código do item: ");
        scanf("%d", &cod);
        printf("Digite a quantidade: ");
        scanf("%d", &qtd);

        pedidoCodigos[totalPedidos] = cod;
        pedidoQuantidades[totalPedidos] = qtd;
        totalPedidos++;

        printf("Deseja adicionar mais itens? (s/n): ");
        scanf(" %c", &continuar);
    }

    // Gerar boleto.txt
    FILE *fbol = fopen("boleto.txt", "w");
    if (fbol == NULL)
    {
        perror("Erro ao criar boleto.txt");
        return 1;
    }

    fprintf(fbol, "========== BOLETO ==========\n");
    float total = 0.0;

    for (int i = 0; i < totalPedidos; i++)
    {
        int cod_ = pedidoCodigos[i];
        int qtd_ = pedidoQuantidades[i];
        for (int j = 0; j < qtd; j++)
        {
            if (cod[j] == cod_)
            {
                float subtotal = p[j] * qtd_;
                fprintf(fbol, "%-15s x%d  R$ %.2f\n", n[j], qtd, subtotal);
                total += subtotal;
                break;
            }
        }
    }

    fprintf(fbol, "----------------------------\n");
    fprintf(fbol, "TOTAL:              R$ %.2f\n", total);
    fprintf(fbol, "============================\n");

    printf("\nPedido salvo em boleto.txt!\n");

    fclose(f);
    fclose(fbol);
    return 0;
}
