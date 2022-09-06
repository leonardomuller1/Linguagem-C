/*
 * @brief   conversor de freqência para sinal
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Calcule a freqência de um sinal a partir de seu período
Parametros : float
Retorno : float
*/
#include <stdio.h>
#include <stdlib.h>
//prototipo
float FrequenciaParaSinal (float frequencia);

int main(){

float frequencia;
float frequenciaoriginal;
do{
    fflush(stdin);
    printf("Entre com o frequencia:");
    scanf("%f",&frequencia);
    printf("\n");

    frequenciaoriginal = frequencia;
    frequencia = FrequenciaParaSinal (frequencia);
    printf("A frequencia %.2f HZ tem um periodo %f\n\n",frequenciaoriginal,frequencia);

}while(1);

}

float FrequenciaParaSinal (float frequencia){
    float sinal;
    sinal = 1/frequencia; // F = 1 / T
    return sinal;
}
