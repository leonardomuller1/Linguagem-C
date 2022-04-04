
/*
 * @brief  Calculadora da nota do trimestral
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Em uma escola, todas as notas são expressas em uma escala de 0 a 10, em regime trimestral.
    A nota do trimestre é composta por duas avaliações individuais A1 e A2 e um trabalho em grupo, TG.
    Cada avaliação compõe de 35% da nota trimestral, sendo completada pela nota do TG, proporcionalmente.
    Elabore um programa que calcule a nota trimestral a partir das notas parciais.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()  
{
    //declaracao das variaveis

    float A1,A2,TG,media; 

    // entrada de dados
    printf("Calculadora da nota do trimestral\n\n");
    printf("Digite a nota da avaliacao 1:");
    scanf("%f",&A1);
    printf("Digite a nota da avaliacao 2:");
    scanf("%f",&A2);
    printf("Digite a nota do trabalho em grupo :");
    scanf("%f",&TG);
    printf("\n"); // espacamento

    // processamento da media
    media = ((A1 + A2)*0.7) + (TG*0.3);

    // exibicao dos resultados
    printf("A media do aluno eh %f ", media);

}