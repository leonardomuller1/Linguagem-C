/*
 * @brief   retorno letra maiúsculo
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Receba um caractere minúsculo e retorne o correspondente maiúsculo.
Parametros : char
Retorno : char

*/
#include <stdio.h>
#include <stdlib.h>
//prototipo
char pMaiusculo(char caracter);

int main(){

char letra,letram;

do{
    fflush(stdin);
    printf("Entre com um caractere :");
    scanf("%c",&letra);
    printf("\n");

    letram = letra;
    letra = pMaiusculo (letra);
    printf("%c -> %c\n\n", letra,letram);

}while(1);

}

char pMaiusculo(char caracter){
    char minusculo;
    if(caracter >= 'a' && caracter <= 'z'){
        minusculo = caracter - ('a'- 'A');
        return minusculo;
    }else{ // validação de minusculos
        minusculo = caracter;
        return minusculo;
    }
}
