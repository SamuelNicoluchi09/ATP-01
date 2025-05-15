#include<stdlib.h>
#include<stdio.h>

int eh_palindromo(int n) {
    int original = n;
    int invertido = 0;
    while (n > 0) { //invertendo o numero
        int digito = n % 10;
        invertido = invertido * 10 + digito;
        n /= 10;
    }
    if (original == invertido)//retorna 1 se eh palindormo e 0 caaso contrario
        return 1;
    else
        return 0;
}

int main() {
    int n;
    printf("Digite um número: ");
    scanf("%d", &n);
    if (eh_palindromo(n))
        printf("%d eh  pallindromo.\n", n);
    else
        printf("%d não eh palindromo.\n", n);
    return 0;
}
