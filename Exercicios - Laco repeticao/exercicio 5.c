/*
 * @brief   numero primo
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    jul/2022
 */

/*
Questao:
Calcule se o valor fornecido pelo usuário é um número primo. (Dica : construa uma função para identificar números primos)..
*/

// Includes
#include<stdio.h>
#include <locale.h>
 
int main() {
 int num, i, resultado = 0;
 
 printf("Digite um número: ");
 scanf("%d", &num);
 
 for (i = 2; i <= num / 2; i++) {
    if (num % i == 0) {
       resultado++;
       break;
    }
 }
 
 if (resultado == 0)
    printf("%d é um número primo\n", num);
 else
    printf("%d não é um número primo\n", num);
 
 return 0;
}