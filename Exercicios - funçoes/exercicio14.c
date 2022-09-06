/*
 * @brief   validador de letra maiscula
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Recebe um caractere. Retorna com 1 se este caracter corresponde a uma letra
maiúscula, caso contrário retorna com zero.
*/
#include <stdio.h>
#include <stdlib.h>
// prototipo
char ehMaisculo(char caracter);

int main()
{
        int caracter,caracteroriginal;
        printf("Digite um caractere: \n");
        scanf("%c", &caracter);
        caracteroriginal = caracter;
        caracter = ehMaisculo(caracter);
        if (caracter == 1)
        {
            printf("%c eh uma letra Maiscula\n", caracteroriginal);
        }
        if (caracter == 0)
        {
            printf("%c nao uma letra Maiscula\n", caracteroriginal);
        }
}

char ehMaisculo(char caracter)
{
    int valor;
    if(caracter > 64 && caracter < 91 ){
        valor = 1;

    } else{
        valor = 0;
    }

    return valor;
}
