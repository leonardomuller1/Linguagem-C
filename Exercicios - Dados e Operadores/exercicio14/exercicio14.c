
/*
 * @brief  Binário para decimal
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Escrever um algoritmo que lê um valor em binario (1 byte) e escreve o decimal correspondente.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaracao das variaveis
    int bin, dec = 0, i;

    // entrada de dados
    printf("\nValor em binario: ");
    scanf("%d", &bin);

    //processamento
    for(i = 0; bin > 0; i++)
    {
        dec = dec + pow(2, i) * (bin % 10);
        bin = bin / 10;
    }

    // exibicao dos resultados
    printf("\nValor em decimal: %d\n", dec);

}