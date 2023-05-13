/*
6. int divisorTensao (float ve, float vs, float *r1, float *r2*);
Função :Calcula os valores de r1 e/ou r2 para os valores de ve e vs dados.
    Se um dos valores de r1 ou r2 forem 0, calcular o valor deste componente com
        base no valor do outro.
    Se ambos forem zero, notificar erro de parametro
Parâmetros : ve – tensão de entrada
            vs – tesão de saída
            r1 e r2 – resistores do divisor

Retorno : 0 para função realizada, -1 r1 e r2 em zero, -2 para vs > ve.
*/
#include <stdio.h>
#include <conio.h>

int divisorTensao(float ve, float vs, float *r1, float *r2);

int main() {
    float ve=0,vs=0,r1=0,r2=0;

    printf("Qual a tensao de entrada:");
    scanf("%f",&ve);

    printf("\nQual a tensao de saida:");
    scanf("%f",&vs);

    printf("\nQual o R1:");
    scanf("%f",&r1);

    printf("\nQual o R2:");
    scanf("%f",&r2);

    printf("\nRetorno da funcao : %i",divisorTensao(ve,vs,&r1,&r2)); // passa R1 e R2 via ponteiros

    printf("\ntensao de entrada: %2.f",ve);
    printf("\ntensao de saida: %2.f",vs);
    printf("\n R1: %2.f",r1);
    printf("\n R2: %2.f",r2);


}

int divisorTensao (float ve, float vs, float *r1, float *r2){


    if(*r1 == 0 && *r2 ==0){
        printf("Valores de resistores invalidos");
        return 0;
    }else if( vs > ve ){
        printf("Valor de saida maior que da fonte");
        return -2;
    }else if(*r1 == 0){
        float tensaoR1 = ve - vs;
        float correnteR2 = vs /(*r2);
        *r1 =  tensaoR1 / correnteR2;
        return -1;
    }else if(*r2 == 0){
        printf("\n\nopa\n");
        float tensaoR1 = ve - vs;
        float correnteR1 = tensaoR1 /(*r1);
        *r2 =  vs / correnteR1;
        return -1;
    }



}
