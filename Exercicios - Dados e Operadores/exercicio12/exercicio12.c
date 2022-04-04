
/*
 * @brief  Calculadora de contas com atraso e restante de salario.
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Joao Felipe recebeu seu salario de R$ 1200,00 (líquido) e precisa pagar duas contas C1 e C2. 
    Como as contas estao atrasadas, Joao tera de pagar multa de 2% sobre cada conta, mais o percentual de 1/30 avos por dia 
    de atraso (1% ao mês). Faça um programa que lê o valor de cada uma das contas e quantos dias estao atrasadas. 
    Calcule e mostre o valor de cada conta paga e quanto restara do salario do Joao Felipe.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaracao das variaveis
    float conta1,atraso1,conta2,atraso2,restsalario, salario;

    // entrada de dados
    printf("\nDigite o valor da conta 1: ");
    scanf("%f",&conta1);
    printf("\nQuantos dias a conta 1 esta atrasada: ");
    scanf("%f",&atraso1);

    printf("\nDigite o valor da conta 2: ");
    scanf("%f",&conta2);
    printf("\nQuantos dias a conta 2 esta atrasada: ");
    scanf("%f",&atraso2);
    printf("\n"); // espacamento

    //processamento

    salario = 1200,00;
    conta1 = conta1*(1.02+atraso1/30);
    conta2 = conta2*(1.02+atraso2/30);
    salario = salario - conta1 - conta2;

    // exibicao dos resultados
    printf("\nValor da conta 1: %f",conta1 );
    printf("\nValor da conta 2: %f",conta2 );
    printf("\nValor do restante do salario: %f",salario );

}

