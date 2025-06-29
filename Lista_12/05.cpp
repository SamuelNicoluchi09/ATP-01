#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX 100

// Struct do Produto
typedef struct {
    int codigo;
    char nome[50];
    float preco;
} Produto;

// Struct do Menu (lista de produtos)
typedef struct {
    Produto produtos[MAX];
    int quantidade;
} Menu;

// Inicializa um produto
Produto criarProduto(int codigo, const char *nome, float preco) {
    Produto p;
    p.codigo = codigo;
    strcpy(p.nome, nome);
    p.preco = preco;
    return p;
}

// Lê o menu de um arquivo
int lerMenu(const char *nomeArquivo, Menu *menu) {
    FILE *f = fopen(nomeArquivo, "r");
    if (f == NULL) {
        perror("Erro ao abrir menu.txt");
        return 0;
    }

    fscanf(f, "%d", &menu->quantidade);
    for (int i = 0; i < menu->quantidade; i++) {
        int cod;
        char nome[50];
        float preco;
        fscanf(f, "%d %s %f", &cod, nome, &preco);
        menu->produtos[i] = criarProduto(cod, nome, preco);
    }

    fclose(f);
    return 1;
}

// Busca um produto no menu pelo código
Produto *buscarProduto(Menu *menu, int codigo) {
    for (int i = 0; i < menu->quantidade; i++) {
        if (menu->produtos[i].codigo == codigo) {
            return &menu->produtos[i];
        }
    }
    return NULL;
}

// ------------------------
// Main com pedido e boleto
// ------------------------

int main() {
    Menu menu;
    if (!lerMenu("menu.txt", &menu)) {
        return 1;
    }

    int pedidoCodigos[MAX], pedidoQuantidades[MAX], totalPedidos = 0;
    char continuar = 's';

    // Mostrar menu
    printf("=== MENU ===\n");
    for (int i = 0; i < menu.quantidade; i++) {
        Produto p = menu.produtos[i];
        printf("%d - %-15s R$ %.2f\n", p.codigo, p.nome, p.preco);
    }

    // Loop de pedido
    while (continuar == 's' || continuar == 'S') {
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

    // Gera boleto.txt
    FILE *fbol = fopen("boleto.txt", "w");
    if (fbol == NULL) {
        perror("Erro ao criar boleto.txt");
        return 1;
    }

    fprintf(fbol, "========== BOLETO ==========\n");
    float total = 0.0;

    for (int i = 0; i < totalPedidos; i++) {
        int cod_ = pedidoCodigos[i];
        int qtd_ = pedidoQuantidades[i];
        Produto *p = buscarProduto(&menu, cod_);
        if (p != NULL) {
            float subtotal = p->preco * qtd_;
            fprintf(fbol, "%-15s x%d  R$ %.2f\n", p->nome, qtd_, subtotal);
            total += subtotal;
        }
    }

    fprintf(fbol, "----------------------------\n");
    fprintf(fbol, "TOTAL:              R$ %.2f\n", total);
    fprintf(fbol, "============================\n");

    printf("\nPedido salvo em boleto.txt!\n");

    fclose(fbol);
    return 0;
}
