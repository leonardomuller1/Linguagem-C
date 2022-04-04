
/*
 * @brief  Caractere minusculo para caractere maiusculo
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Peça ao usuário que digite um caractere minúsculo. Exiba o correspondente maiúsculodeste caractere.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
int main()
{
    //declaracao das variaveis
    int caractere;

    // entrada de dados
    printf("\nDigite um caractere minusculo: ");
    scanf("%c",&caractere);
    printf("\n"); // espacamento

    //processamento

    caractere = caractere - 32;

    // exibicao dos resultados
    printf("Caractere maiusculo: %c", caractere);

}

