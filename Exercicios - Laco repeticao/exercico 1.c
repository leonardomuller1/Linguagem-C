/*
 * @brief   sequência numérica
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    mar/2022
 */

/*
Questao:
Exiba na tela uma sequência numérica de 15 valores, todos múltiplos de 7, começando pelo valor 7.
*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    int i;
    
    for (i=7;i<=107;i+=7) 
        { // bloco de repeticao
            printf("%2d ",i); // exibindo a variavel de controle
    }
}