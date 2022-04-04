
/*
 * @brief  Conversor de milhas para quilometros
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    mar/2022
*/

/*
Questao:
    Escreva um programa que, a partir de uma distância dada em milhas, informe o equivalente em quilometros.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaracao das variaveis

    float milha, quilometro; 

    // entrada de dados
    printf("Conversor de milhas para quilometros\n\n");
    printf("Digite a distancia em milhas :");
    scanf("%f",&milha);
    printf("\n"); // espacamento

    // processamento

    quilometro = milha / 0.62137; //convertendo milha para quilometro

    // exibicao dos resultados
    printf("A distancia eh %f Km", quilometro);

}