/*
 * @brief   sequência numérica
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    jul/2022
 */

/*
Questao:
Gere uma sequência numérica de 1 a 60, exibindo na tela como se fosse um cartão da megasena.
*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    int i;
    
for (i=1; i <=60; i++){
    if(i==11||i==21||i==31||i==41||i==51){
        printf("\n");
    }
    printf("%2d ",i);
}
}