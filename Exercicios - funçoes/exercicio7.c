/*
 * @brief   diferença de fase apartir da frequencia e tempo
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
A partir da diferença de tempo entre o pico positivo de dois sinais e a freqência destes,
calcule a diferença de fase entre eles, em graus.
Parametros : float frequencia float tempo (não precisa ser estes os nomes das variáveis)
Retorno : float
*/
#include <stdio.h>
#include <stdlib.h>
// prototipo
float CalculoFase(float frequencia, float diferencia_de_tempo);

int main()
{
    float frequencia, diferencia_de_tempo;
    printf("Diga-me o frequencia: ");
    scanf("%f", &frequencia);
    printf("Diga-me a diferenca de tempo entre os picos extremos: ");
    scanf("%f", &diferencia_de_tempo);
    printf("Diferenca de fases: %.2f graus\n", CalculoFase(frequencia, diferencia_de_tempo));
    return 0;
}

float CalculoFase(float frequencia, float diferencia_de_tempo)
{
    float calculo;

    calculo = diferencia_de_tempo * frequencia * 360;

    return calculo;
}
