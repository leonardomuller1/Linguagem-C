/*
 * @brief   jogo de dados
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    ago/2022
 */

/*
Questao:
Solicite ao usuário dois valores numéricos de 1 a 6. Simule o lançamento de dois dados .
Informe ao usuário quantos lançamentos foram necessários para obter os valores escolhidos por ele.

*/
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int a, b, lances, dadoa, dadob, lance = 0;

    printf("Digite o numero dado a:\n");
    scanf("%d", &a);
    printf("Digite o numero dado b:\n");
    scanf("%d", &b);


    if (a > 6 || b > 6 || a <= 0 || b <= 0)
    { // dado não pode ser maior que 6 e nulo
        printf("O dado esta com um valor invalido\n");
        printf("Por favor verifique os valores\n");
        exit(1);
    }

    while (lance >= 0)
    {
        dadoa = rand() % 6 + 1; // sorteando
        dadob = rand() % 6 + 1; // sorteando
        lance = lance + 1;

        if (a == dadoa && b == dadob)
        {
            printf(" Numero de lances %d", lance);
            exit(1);
        }
    }
}