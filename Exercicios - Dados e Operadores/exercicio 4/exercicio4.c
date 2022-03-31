
/*
 * @brief  sensor de temperatura LM35 variado com a sua tensao
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    mar/2022
*/

/*
Questao:

O sensor de temperatura LM35 varia sua tensao de saida em 10 mV a cada variação de grau da temperatura. 
Considerando que a 0 graus a saída apresenta uma tensão de 0,00V, escreva um programa que, dada a tensão de saída, calcule a temperatura medida.

*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaracao das variaveis

    float tensao; //tensao do sistema
    float sensor; //temperatura do sistema

    // entrada de dados
    printf("Sensor de temperatura\n\n");
    printf("Digite o valor da tensao (V) do circuito :");
    scanf("%f",&tensao);
    printf("\n"); // espacamento

    // processamento

    tensao = tensao * 1000; //convertendo V para mV

    sensor = (tensao/10); // calculando 10mw igual 1 grau

    // exibicao dos resultados
    printf("A temperatura eh %f graus", sensor);

}