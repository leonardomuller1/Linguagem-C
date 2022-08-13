/*
 * @brief   números perfeitos
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    ago/2022
 */

/*
Questao:
Elabore um algoritmo que escreva os cinco primeiros números perfeitos. São números perfeitos, todos aqueles em que a soma dos seus divisores é igual ao número em questão. EX: 6 = 1 + 2 + 3.

*/
#include <stdio.h>
#include <stdlib.h>

int ehPerfeito(int n)
{
    int i, soma = 0, perfeito;

    for (i = 1; i <= n / 2; i++)
    {
        if (n % i == 0)
            soma += i;
    }
    if (soma == n)
        return 1; // é perfeito
    else
        return 0; // não é perfeito
}

int main()
{
    int n, quantidade = 0, perfeito, i = 1, soma = 0;

    n = 5;

    while (quantidade < n)
    {
        perfeito = ehPerfeito(i);
        if (perfeito)
        {
            quantidade++;
            printf("%d: ", quantidade);
            printf("%d\n", i);
        }
        i++;
    }
    return 0;
}