/*
 * @brief   potencia de uma carga registiva
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Dados os valores de tensão e corrente em uma carga resistiva, calcula a potência
dissipada por ela.
*/
#include <stdio.h>
#include <stdlib.h>
// prototipo
float CalculoPotencia(float tensaoFonte, float corrente);

int main()
{
    do{
    float tensaoFonte, corrente, potencia;
    printf("Diga-me a tensao : (V)");
    scanf("%f", &tensaoFonte);
    printf("Diga-me a corrrente : (A)");
    scanf("%f", &corrente); 
    potencia = CalculoPotencia(tensaoFonte, corrente);
    printf("A potencia %.2f W\n",potencia);

    } while (1);
    
}

float CalculoPotencia(float tensaoFonte, float corrente)
{
    float potencia;

    potencia = tensaoFonte * corrente;

    return potencia;
}