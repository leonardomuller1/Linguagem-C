/*
 * @brief   resistor para o led
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Calcule o valor do resistor série para um led, dados a tensão da fonte, corrente de
trabalho o led. Assuma led vermelho.
*/
#include <stdio.h>
#include <stdlib.h>
// prototipo
float CalculoResistor(float tensaoFonte, float corrente);

int main()
{
    do{
    float tensaoFonte, corrente, resistor;
    printf("Diga-me o tensao da fonte: ");
    scanf("%f", &tensaoFonte);
    corrente = .02; // 20mA do led vermelho    
    resistor = CalculoResistor(tensaoFonte, corrente);
    printf("O resistor %.2f ohms\n",resistor);

    } while (1);
    
}

float CalculoResistor(float tensaoFonte, float corrente)
{
    float resistor;

    resistor = tensaoFonte/ corrente;

    return resistor;
}
