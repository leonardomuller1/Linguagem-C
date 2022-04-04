
/*
 * @brief   Proximo caractere da tabela ASCII
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Elabore um programa que, a partir de um caractere fornecido pelo usuário, exiba o caractere seguinte da tabela ASCII.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
int main()
{
    //declaracao das variaveis
    int caractere, seg;

    // entrada de dados
    printf("\nDigite um caractere: ");
    scanf("%c",&caractere);
    printf("\n"); // espacamento

    //processamento
    seg = caractere + 1;

    // exibicao dos resultados
    printf("Caractere digitado: %c codigo do seguinte carectete ASCII: %c", caractere,seg);

}
