
/*
 * @brief  Calculador a tensão (Vout) do circuito, recebendo dois resistores e calculando a tensão.
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    mar/2022
*/

/*
questao:

Calcule a tensão Vout do circuito abaixo, dados R1, R2 e Vin.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    float fonte, resistor1, resistor2, corrente, v1, v2,resistor, vout; // declara as variaveis

    printf("Calculadora de tensao de saida do circuito\n\n"); //mensagem do que o programa realiza

    // Entrada dos dados 
    printf("Digite a tensao da fonte em V: ");
    scanf("%f", &fonte);

    printf("\nDigite a resistencia do resistor: ");
    scanf("%f", &resistor1);

    printf("\nDigite a resistencia do resistor: ");
    scanf("%f", &resistor2);

    //processamento
    resistor = resistor1 + resistor2;

    corrente = fonte /resistor; //calculada a corrente do circuito

    v1 = resistor1 * corrente; // calculada a tensão do resistor R1
    v2 = resistor2 * corrente; // calculada a tensão do resistor R2

    vout = v2; // a tensão da saida Vout vai ser igual a do R2

    // Exibi o resultado
    printf("A tensao de saida do Vout eh : %f V", vout);

    return 0;
}