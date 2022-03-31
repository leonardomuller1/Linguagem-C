
/*
 * @brief  Calculadora de circuito AC
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    mar/2022
*/

/*
Questao:

Calcule a tensão Vout do circuito abaixo, dados R1, R2 e Vin.
    a)Tensão de pico da senoide.
    b)Corrente RMS se esta tensão foi aplicada a uma carga de 156 ohms.

*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaracao das variaveis

    float vrms; //tensao rms do sistema
    float vp; //tensao de pico
    float corrente; //corrente na carga

    const float resistencia=156; // resistencia do circuito


    // entrada de dados
    printf("Calculo circuito AC\n\n");
    printf("Digite o valor rms da tensao :");
    scanf("%f",&vrms);
    printf("\n"); // espacamento

    // processamento
    vp = vrms/0.707;
    corrente = vrms / resistencia;

    // exibicao dos resultados

    printf("Uma tensao senoidal com %.2f vrms tem %.2f V de pico\n\n",vrms,vp);
    printf("Colocada uma carga de %.2f ohms produz uma corrente de %.2f A\n",resistencia,corrente);

}