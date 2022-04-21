/*
 * @brief   Sistema de notas
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Um usuário quer um programa onde possa escolher que tipo de média deseja calcular a partir de 3 notas.
Você esta sendo contratado para elaborar um programa que leia as notas e a opção escolhida pelo usuário.
Calcule e escreva as três notas, a média e o tipo de média calculada.

a) aritmética
b) ponderada (pesos 3,3,4 – para a maior nota)
c) harmônica
d) geométrica
*/

// Includes
#include <stdio.h>
#include <math.h>

int main()
{
    // declaracao das variaveis
    float nota1, nota2, nota3;
    int escolha;

    printf("Qual a media deseja?\n1 - aritmetica\n2 - ponderada\n3 - harmonica\n4 - geometrica\n");
    scanf("%i", &escolha);

    printf("Digite as tres notas: ");
    scanf("%f%f%f", &nota1, &nota2, &nota3);

    // processamento
    if (escolha = 1){
        printf("Media aritmetica: %.2f\n", (nota1 + nota2 + nota3) / 3);
    }else if (escolha = 2){
        printf("Media ponderada: %.2f\n", (nota1 * 3 + nota2 * 3 + nota3 * 4) / 10);
    }else if (escolha = 3){
        printf("Media harmonica: %.2f\n", (3/(1/nota1 + 1/nota2 + 1/nota3)));
    }else if (escolha = 4){
        //variavies para a media geometrica

        float produto,expoente,media;
        expoente = 1.0/3;
        produto = nota1 * nota2 * nota3;
        media = pow(produto,expoente);

        printf("Media geometrica: %.2f\n", media);
    }

}