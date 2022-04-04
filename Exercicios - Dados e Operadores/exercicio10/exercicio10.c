
/*
 * @brief  Caractere maiusculo para caractere minusculo
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Peça ao usuário que digite um caractere maiusculo. Exiba o correspondente minusculo deste caractere.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>


int main()
{
    //declaracao das variaveis
    int caractere;

    // entrada de dados
    printf("\nDigite um caractere maiusculo: ");
    scanf("%c",&caractere);
    printf("\n"); // espacamento

    //processamento

    caractere = caractere + 32;

    // exibicao dos resultados
    printf("Caractere minusculo : %c", caractere);

}

