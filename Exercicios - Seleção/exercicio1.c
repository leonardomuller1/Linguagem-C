/*
 * @brief   Verificador de numero se eh positivo e negativo, par e impar
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Escreva um programa que leia um número inteiro. Se o número lido for positivo, escreva uma mensagem indicando se ele é 
par ou ímpar. Se o número for negativo, escreva a seguinte mensagem : “Este número não é positivo”.
*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    //declaracao das variaveis
    int numero;

    // entrada de dados
    printf("\nQual o numero: ");
    scanf("%i",&numero);
    printf("\n"); // espacamento

    //processamento 

    if (numero % 2 == 0){ // validador se o numero eh par
        printf ("\nO numero %i eh par e ",numero);
    }else {
        printf("\nO numero %i eh impar e ",numero); 
    }
    if( numero > 0){ // validador se o numero eh positivo
        printf("positivo"); 
    } else{
        printf("negativo"); 
    }

}
