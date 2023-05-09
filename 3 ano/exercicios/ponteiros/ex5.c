/*
5. int triangulo-retangulo(float *oposto, *float adjacente, float *hipotenusa);
Função : Calcula o segmento do triângulo retângulo cujo valor é zero.
Parâmetros : oposto – cateto oposto
adjacente – cateto adjacente
hipotenusa - hipotenusa

Retorno : 0 para função realizada, -1 para erro de parametro (dois ou mais parametros
em zero)
*/
#include <stdio.h>
#include <conio.h>

int tri (float *oposto, float *adjacente, float *hipotenusa);

int main() {
    float oposto, adjacente, hipotenusa;

    printf("Qual o oposto?");
    scanf("%f",&oposto);

    printf("Qual o adjacente?");
    scanf("%f",&adjacente);

    printf("Qual a hipotenusa?");
    scanf("%f",&hipotenusa);

    printf("\n A funcao retornou: %i\n",tri(&oposto,&adjacente,&hipotenusa));

    printf("\nA oposto eh %f",oposto);
    printf("\nO adjacente eh %f",adjacente);
    printf("\nO hipotenusa eh %f",hipotenusa);


}

int tri (float *oposto, float *adjacente, float *hipotenusa){

    if(*oposto != 0 && *adjacente != 0 && *hipotenusa == 0){
        float auxOposto = *oposto;
        float auxAdjacente = *adjacente;
        float auxHipotenusa = *hipotenusa;
        auxHipotenusa = auxAdjacente*auxAdjacente + auxOposto*auxOposto;
        auxHipotenusa = sqrt (auxHipotenusa);
        *oposto = auxOposto;
        *adjacente = auxAdjacente;
        *hipotenusa = auxHipotenusa;
        return 0;
    }if(*oposto != 0 && *adjacente == 0 && *hipotenusa != 0){
        float auxOposto = *oposto;
        float auxAdjacente = *adjacente;
        float auxHipotenusa = *hipotenusa;
        auxAdjacente = auxHipotenusa*auxHipotenusa - auxOposto*auxOposto;
        auxAdjacente = sqrt (auxAdjacente);
        *oposto = auxOposto;
        *adjacente = auxAdjacente;
        *hipotenusa = auxHipotenusa;
        return 0;
    }if(*oposto == 0 && *adjacente != 0 && *hipotenusa != 0){
        float auxOposto = *oposto;
        float auxAdjacente = *adjacente;
        float auxHipotenusa = *hipotenusa;
        auxOposto = auxHipotenusa*auxHipotenusa - auxAdjacente*auxAdjacente;
        auxOposto = sqrt (auxOposto);
        *oposto = auxOposto;
        *adjacente = auxAdjacente;
        *hipotenusa = auxHipotenusa;
        return 0;
    }else {
        return -1;
    }
}
