/*
 * @brief   conversor de sinal para frequencia
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Calcule o período de um sinal a partir da sua frequência
Parametros : float
Retorno : float
*/
#include <stdio.h>
#include <stdlib.h>
//prototipo
float SinalParaFrequencia (float sinal);

int main(){

float sinal;
float sinaloriginal;
do{
    fflush(stdin);
    printf("Entre com o sinal:");
    scanf("%f",&sinal);
    printf("\n");

    sinaloriginal = sinal;
    sinal = SinalParaFrequencia (sinal);
    printf("O sinal %.2f tem uma frequencia %f HZ\n\n",sinaloriginal,sinal);

}while(1);

}

float SinalParaFrequencia(float sinal){
    float frequencia;
    frequencia = T/2*3.14; // F = 1/ T
    return frequencia;
}
