#include<stdlib.h>
#include<stdio.h>

int eh_primo(int x){
    int verificacao=1;
    if(x==1||x==2){
        verificacao=1;

    }
    for(int i=2;i<x;i++){
        if(x%i==0){
            verificacao=0;//se x for divisivel por aalgum outro número lo nn é primo
            break;        
        }
       
    }
    return verificacao;//retornar 1 ou 0

}
int main(){
    int x,verificado=0;
    printf("digite um numero paara verificar se eh primo: \n");
    scanf("%d",&x);
    verificado=eh_primo(x);//chama a função e atribui o valor retonado em verificado
    if(verificado==0){//verifica se retornou 1 para primo ou 0 para não primo
        printf("O numero nao eh primo");
    }else{
        printf("O numero eh primo");
    }
    return(0);
    getchar();
}