#include<stdlib.h>
#include<stdio.h>

void calcular_circulo(float raio, float *area, float *perimetro){
*perimetro = 2*raio* 3.14;
*area = raio * raio *3.14; //altera o valor do endereço de area e perimetro de acordo com o calculo feito
}
int main(){
    float raio,area,perimetro;
    printf("Digite o raio do circulo: \n");
    scanf("%f",&raio);
    calcular_circulo(raio,&area,&perimetro);//chama a função passando o valor do raio e o endereço das variaveis e perimetro
    printf("O valor da area: %3.f\n",area);
    printf("O valor do perimetro: %3.f\n",perimetro);
    return(0);
    getchar();
}