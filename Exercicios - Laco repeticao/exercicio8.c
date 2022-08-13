/*
 * @brief   divisor em intervalo numerico
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    ago/2022
 */

/*
Questao:
Solicite ao usuário um intervalo numérico e  um fator de divisão entre 2 e 15. Garanta que o fator de divisão está na faixa solicitada. 
Exiba os valores do intervalo até o primeiro valor divisível pelo fator informado.

*/

#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 0, b = 0, divisor;
    float total;
    printf("Digite o numero da sequencia a:\n");
    scanf("%d", &a);
    printf("Digite o numero da sequencia b:\n");
    scanf("%d", &b);
    printf("Digite o valor do divisor: (2 a 15)\n");
    scanf("%d", &divisor);

    if (divisor > 15 || divisor < 2)
    {
        printf("divisor errado, tente novamente");
        exit(1);
    }

    printf("comecando as divisoes\n\n\n");
    for (int i = b; i >= a; i--)
    {
        printf("%d divido por %d, da:",i, divisor);
        total = i/divisor;
        printf("\n%.2f\n", total);
    }
}