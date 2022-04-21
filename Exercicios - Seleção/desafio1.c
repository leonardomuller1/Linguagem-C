/*
 * @brief   Sistema organizador de numeros
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Faça um programa que lê 4 valores I, A, B e C onde I é um número inteiro e positivo e A, B, e
C são quaisquer valores reais. O programa deve escrever os valores lidos e:
· se I = 1, escrever os três valores A, B e C em ordem crescente;
· se I = 2, escrever os três valores A, B e C em ordem decrescente;
· se I = 3, escrever os três valores A, B, e C de forma que o maior valor fique entre os outros
dois;
· se I não for um dos três valores acima, dar uma mensagem indicando isto.

*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    // declaracao das variaveis
    int a, b, c, i;

    // entrada de dados
    printf("Digite o valor de I:");
    scanf("%d", &i);
    printf("Digite tres valores: ");
    scanf("%d%d%d", &a, &b, &c);
    printf("\n"); // espacamento

    // processamento

    switch (i)
    {
    case 1: // ordem crescente
        if (a <= b && b <= c){
            printf("A ordem crescente: %d %d %d\n", a, b, c);
        }else if (a <= c && c <= b){
            printf("A ordem crescente: %d %d %d\n", a, c, b);
        }else if (b <= a && a <= c){
            printf("A ordem crescente: %d %d %d\n", b, a, c);
        }else if (b <= c && c <= a){
            printf("A ordem crescente: %d %d %d\n", b, c, a);
        }else if (c <= a && a <= b){
            printf("A ordem crescente: %d %d %d\n", c, a, b);
        }else if (c <= a && a <= b){
            printf("A ordem crescente: %d %d %d\n", c, a, b);
        }else if (c <= b && b <= a){
            printf("A ordem crescente: %d %d %d\n", c, b, a);
        }

        break;

    case 2: // ordem decrescente
        if (a <= b && a <= c && b <= c){
            printf("A ordem decrescente: %d %d %d", c, b, a);
        }
        else if (a <= b && a <= c && c <= b){
            printf("A ordem decrescente: %d %d %d", b, c, a);
        }
        else if (b <= a && b <= c && a <= c){
            printf("A ordem decrescente: %d %d %d", c, a, b);
        }
        else if (b <= a && b <= c && c <= a){
            printf("A ordem decrescente: %d %d %d", a, c, b);
        }
        else if (c <= a && c <= b && b <= a){
            printf("A ordem decrescente: %d %d %d", a, b, c);
        }
        else if (c <= a && c <= b && a <= b){
            printf("A ordem decrescente: %d %d %d", b, a, c);
        }

        break;

    case 3: // maior no meio
        if (a <= b && a <= c && b <= c){
            printf("%d %d% d", b, c, a);
        }

        else if (a <= b && a <= c && c <= b){
            printf("%d %d %d", c, b, a);
        }

        else if (b <= a && b <= c && a <= c){
            printf("%d %d %d", a, c, b);
        }

        else if (b <= a && b <= c && c <= a){
            printf("%d %d %d", c, a, b);
        }

        else if (c <= a && c <= b && b <= a){
            printf("%d %d %d", b, a, c);
        }

        else if (c <= a && c <= b && a <= b){
            printf("%d %d %d", a, b, c);
        }

        break;

    default:
        printf("Por favor, digite I como:\n");
        printf("se I  1 - crescente\n");
        printf("se I  2 - decrescente\n");
        printf("se I  3 - maior valor no meio\n");
        break;
    }
}
