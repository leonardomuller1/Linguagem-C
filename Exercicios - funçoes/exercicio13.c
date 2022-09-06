/*
 * @brief   validador de numero par
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Recebe um caractere. Retorna com 1 se este caracter corresponde a um dígito
numérico, caso contrário retorna com zero.
*/
#include <stdio.h>
#include <stdlib.h>
// prototipo
char ehNumero(char caracter);

int main()
{
        int caracter,caracteroriginal;
        printf("Digite um caractere: \n");
        scanf("%c", &caracter);
        caracteroriginal = caracter;
        caracter = ehNumero(caracter);
        if (caracter == 1)
        {
            printf("%c eh um numero\n", caracteroriginal);
        }
        if (caracter == 0)
        {
            printf("%c nao eh um numero\n", caracteroriginal);
        }
}

char ehNumero(char caracter)
{
    int valor;
    if(caracter > 47 && caracter < 58 ){
        valor = 1;

    } else{
        valor = 0;
    }

    return valor;
}
