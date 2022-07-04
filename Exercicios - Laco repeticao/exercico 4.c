/*
 * @brief   sequência numérica
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    jul/2022
 */

/*
Questao:
 Modifique o programa do exercício anterior de forma a exibir XX no lugar dos valores múltiplos de 6.
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
    }else if(i%6==0){
        printf("XX ");
    }else{
          printf("%2d ",i);  
    }
}
}