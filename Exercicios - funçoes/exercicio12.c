/*
 * @brief   validador de numero par
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Recebe um valor inteiro. Retorna com 1 se este valor for par, caso contrário retorna com
zero.
*/
#include <stdio.h>
#include <stdlib.h>
// prototipo
int numeroPar(int numero);

int main()
{
    do
    {
        int numero,numerodado;
        printf("Diga-me um numero: \n");
        scanf("%d", &numero);
        numerodado = numero;
        numero = numeroPar(numero);
        if (numero == 1)
        {
            printf("%d eh par\n", numerodado);
        }
        if (numero == 0)
        {
            printf("%d eh impar\n", numerodado);
        }

    } while (1);
}

int numeroPar(int numero)
{
    int num = numero;
    if(num%2==0){
        num = 1;

    } else{
        num = 0;
    }

    return num;
}
