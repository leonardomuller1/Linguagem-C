/*
 * @brief   numero primo
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    jul/2022
 */

/*
Questao:
Calcule se o valor fornecido pelo usuário é um número primo. (Dica : construa uma função para identificar números primos)..
*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    int num, cont=0;
    printf("Entre com um numero: ");

    scanf(" %d", &num);

    for(int i=1;i<=num; i++){
	    if(num%i == 0){
	    cont++;
    
    }if(cont == 2){
    	printf("O numero %d e primo",num);
    } else 
	    printf("O numero %d nao e primo",num);
    getch();
    return 0;
}
}