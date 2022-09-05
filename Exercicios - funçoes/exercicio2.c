/*
 * @brief   retorno letra minusculo
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Receba um caractere maiúsculo e retorne o correspondente minúsculo.
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
    printf("%c -> %c\n\n", letram,letra);

}while(1);

}

char pMaiusculo(char caracter){
    char minusculo;
    if(caracter >= 'A' && caracter <= 'Z'){
        minusculo = caracter + ('a'- 'A');
        return minusculo;
    }else{ // validação de minusculos
        minusculo = caracter;
        return minusculo;
    }
}
