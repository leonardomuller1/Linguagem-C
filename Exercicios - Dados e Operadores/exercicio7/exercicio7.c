
/*
 * @brief   Calculadora de media ponderada
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Faça um algoritmo para ler as três notas de um aluno em uma disciplina e exibe a sua média ponderada 
    (as notas tem pesos respectivos de 1, 2 e 3).
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()  
{
    //declaracao das variaveis

    float nota1,nota2,nota3,media; 

    // entrada de dados
    printf("Calculadora da nota do trimestral\n\n");
    printf("Digite a nota 1:");
    scanf("%f",&nota1);
    printf("Digite a nota 2:");
    scanf("%f",&nota2);
    printf("Digite a nota 3:");
    scanf("%f",&nota3);
    printf("\n"); // espacamento

    // processamento da media
    media = (nota1*1 + nota2*2 + nota3 *3)/(1+2+3);

    // exibicao dos resultados
    printf("A media do aluno eh %f ", media);

}