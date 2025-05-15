#include<stdlib.h>
#include<stdio.h>
#include<math.h>

float distancia(int x1,int x2,int y1,int y2){
float dist=(x1-x2)*(x1-x2)+(y1-y2)*(y1-y2);//calculo da distancia
 return sqrt(dist);//retorn a raiz da dist segundo a formula
}
int main(){
    int x1,x2,y1,y2;
    float dist;
    printf("Digite a coordenada x1: \n");
    scanf("%d",&x1);
    printf("Digite a coordenada x2: \n");
    scanf("%d",&x2);
    printf("Digite a coordenada y1: \n");
    scanf("%d",&y1);
    printf("Digite a coordenada y2: \n");
    scanf("%d",&y2);
    dist = distancia(x1,x2,y1,y2); //chama e atribui o valor retornado pela funçao em dist
    printf("A distância dos pontos digitado eh: %2.f",dist);
    return(0);
    getchar();
}