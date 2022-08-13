/*
 * @brief   Gerador de numeros aleatorios até 1000
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    ago/2022
 */

/*
Questao:
Gere uma série de N números aleatórios, com valores entre 0 e 1000, quantidade esta definida pelo usuário. Exiba  na tela a série gerada e, ao final:
a - O maior valor da série;
b - O menor valor da série;
c - A média aritmética da série;
d - A quantidade de números primos desta série.

*/
#include <stdio.h>
#include <stdlib.h> // Necessario para a funcao srand

int main()
{

    printf("Gerador aleatorio de variaveis e analise");

    /* Variaveis */
    int i, x, g, j, numeros, menor, cont;
    int maior = 0;
    int primos, totalprimos = 0;
    float soma = 0, media; 

    printf("\n\nQuantos numeros voce quer que seja gerado?\n");
    scanf("%d", &numeros);

    srand(time(NULL));            // A cada execucao o valor da "semente" sera diferente, assim gera numeros diferentes
    for (i = 0; i < numeros; i++) // Loop para criar as variaveis e soma-las
    {
        x = rand() % 1000; // Cria variaveis aleatorias
        printf("%d ", x);  // Exibe as variaveis aleatorias
        soma = soma + x;

        /* Maior e menor */
        if (maior < x)
        {
            maior = x;
        }
        if (menor > x)
        {
            menor = x;
        }

        // numeros primos verificador

        for (g = x; g <= x; g++)
        {
            if (g == 0 || g == 1)
            {
                primos = 0;
            }
            else
            {
                primos = 1; // considero inicialmente que o número é primos
                for (j = 2; j < x; j++)
                { // tento provar que ele não é primos
                    if (x % j == 0)
                    {
                        primos = 0; // consigo provar que ele não é primos
                    }
                }
            }
            if (primos == 1)
            {
                totalprimos = totalprimos + 1;
            }
        }
    }

    printf("\n\n\nO maior numero eh:%.2d", maior); // Resultado maior
    printf("\n\nO menor numero eh:%.2d", menor);   // Resultado menor

    // media
    media = soma / numeros;            // Formula da media
    printf("\nA media e:%.2f", media); // Resultado media

    // primos
    printf("\n\nTotal de primos %d", totalprimos);
}
