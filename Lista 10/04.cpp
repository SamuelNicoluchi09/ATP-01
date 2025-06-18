#include <stdio.h>
#include <stdlib.h>

int main() {
    int tamanho;
    int *v;
    printf("Digite o tamanho do vetor: ");
    scanf("%d", &tamanho);
    v = (int*) malloc(tamanho * sizeof(int));
    if(v == NULL) {
        printf("Erro ao alocar o vetor;");
        free(v);
        return 1;
    }
    else {
        for(int i = 0; i < tamanho; i++) {
            printf("Digite o %d° elemento do vetor: ", i+1);
            scanf("%d", &v[i]);
        }
        printf("Vetor antes da alteração: ");
        for(int i = 0; i < tamanho; i++){
            printf("%d ", v[i]);
        }
        v = (int*) realloc(v, (tamanho/2) * sizeof(int));
        if(v != NULL) {
            printf("\nMetade: ");
            for(int i = 0; i < (tamanho/2); i++){
                printf("%d ", v[i]);
            }
        }
        else {
            printf("Erro ao alocar o vetor;");
            free(v);
            return 1;
        }
    }
    getchar();
    free(v);
    return 0;
}