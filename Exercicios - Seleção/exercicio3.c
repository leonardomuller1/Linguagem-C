/*
 * @brief   Sistema de numero maior
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Escreva um programa que lê três valores quaisquer e exibe o maior deles.

*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    //declaracao das variaveis
    int a, b, c, menor, maior;

    // entrada de dados
    printf("Digite tres valores: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("\n"); // espacamento

    //processamento 

    if(a > b){
        if(a > c)
            maior = a;
        else
            maior = c;
    }
    else{
        if(b > c)
            maior = b;
        else
            maior = c;
    }

     printf("Maior: %d\n",maior);
}