/*
 * @brief   resto 5
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    jul/2022
 */

/*
Questao:
Gere números de 1000 a 1999 e escreva aqueles que, divididos por 11, tem resto igual a 5.
*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    int i;
    
for (i=1000; i <=1999; i++){
    if (i%11==5) {
            printf("%2d ",i); // exibindo a variavel de controle
    }
}
}
