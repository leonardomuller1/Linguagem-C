/*
 * @brief   Sistema de numero maior e organiza eles
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Elabore um programa que lê três valores quaisquer e exibe os três em ordem
crescente.

*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    // declaracao das variaveis
    int numero1, numero2, numero3;

    // entrada de dados
    printf("Digite tres valores: ");
    scanf("%d%d%d", &numero1, &numero2, &numero3);
    printf("\n"); // espacamento

    // processamento

    if (numero1 <= numero2 && numero2 <= numero3){
        printf("A ordem crescente: %d %d %d\n", numero1, numero2, numero3);
    }else if (numero1 <= numero3 && numero3 <= numero2){
        printf("A ordem crescente: %d %d %d\n", numero1, numero3, numero2);
    }else if (numero2 <= numero1 && numero1 <= numero3){
        printf("A ordem crescente: %d %d %d\n", numero2, numero1, numero3);
    }else if (numero2 <= numero3 && numero3 <= numero1){
        printf("A ordem crescente: %d %d %d\n", numero2, numero3, numero1);
    }else if (numero3 <= numero1 && numero1 <= numero2){
        printf("A ordem crescente: %d %d %d\n", numero3, numero1, numero2);
    }else if (numero3 <= numero2 && numero2 <= numero1){
        printf("A ordem crescente: %d %d %d\n", numero3, numero2, numero1);
    }
}