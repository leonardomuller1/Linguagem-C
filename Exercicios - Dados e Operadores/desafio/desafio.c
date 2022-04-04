
/*
 * @brief   Decomposição de notas/moedas
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:
    Escreva um algoritmo que lê um valor em R$ e o decompõe no menor número de notas/moedas possíveis de
    0,01, 0,05, 0,10, 0,25, 0,50, 1, 2, 5, 10, 20, 50 e 100.
    Escrever o número lido e a quantidade de notas necessárias.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    // declaracao das variaveis
    float valor, moeda001, moeda005, moeda010, moeda025, moeda050, moeda1, nota2, nota5, nota10, nota20, nota50, nota100;

    // entrada de dados
    printf("\nQual o valor R$ ");
    scanf("%f", &valor);

    printf("\n"); // espacamento

    // processamento

    // moedas
    moeda001 = valor * 100;
    moeda005 = valor * 20;
    moeda010 = valor * 10;
    moeda025 = valor * 4;
    moeda050 = valor * 2;
    moeda1 = valor * 1;

    // notas
    // nota2 = valor * 0.5; 
    // nota5 = valor * 0.2;
    // nota10 = valor * 0.1;
    // nota20 = valor * 0.05;
    // nota50 = valor * 0.02;
    // nota100 = valor * 0.01;

    // exibicao dos resultados
    // moedas
    printf("\nValor R$ %f em  %.0f moedas de 1 centavo;", valor, moeda001);
    printf("\nValor R$ %f em  %.0f moedas de 5 centavos;", valor, moeda005);
    printf("\nValor R$ %f em  %.0f moedas de 10 centavos;", valor, moeda010);
    printf("\nValor R$ %f em  %.0f moedas de 25 centavos;", valor, moeda025);
    printf("\nValor R$ %f em  %.0f moedas de 50 centavos;", valor, moeda050);
    printf("\nValor R$ %f em  %.0f moedas de 1 real;", valor, moeda1);

    // notas
    // printf("\nValor R$ %f eh  %.0f notas de 2 reias;", valor, nota2);
    // printf("\nValor R$ %f eh  %.0f notas de 5 reias;", valor, nota5);
    // printf("\nValor R$ %f eh  %.0f notas de 10 reias;", valor, nota10);
    // printf("\nValor R$ %f eh  %.0f notas de 20 reias;", valor, nota20);
    // printf("\nValor R$ %f eh  %.0f notas de 50 reias;", valor, nota50);
    // printf("\nValor R$ %f eh  %.0f notas de 100 reias;", valor, nota100);

}
