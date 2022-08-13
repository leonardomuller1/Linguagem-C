/*
 * @brief   Contagem regressiva
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    ago/2022
 */

/*
Questao:
Elabore um programa que exiba na tela uma contagem regressiva iniciando de um valor escolhido pelo usuário. 
O tempo para exibição de novos valores deve ser de 1 seg.
Ao final da contagem, exibir uma mensagem alusiva ao fato.
Dica : use a função time() para medição do tempo.
A função time() pode ser encontrada no exemplo de laço while().
*/

#include <stdio.h>

int main()
{
    int segundo;
    printf("Valor de inicio da contagem: ");
    scanf("%d", &segundo);
    while (0 < segundo)
    {
        sleep(1); // delay de 1 segundo
        segundo = segundo - 1;
        if (0 != segundo)
        {
            printf("%d\n", segundo);
        }
    };
    if (segundo == 0)
    {
        printf("fim da contagem!");
    }
    return 0;
}
