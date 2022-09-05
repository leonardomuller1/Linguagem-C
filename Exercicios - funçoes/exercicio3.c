/*
 * @brief   conversor de numero char para int
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Receba um caractere numérico e retorne o correspondente valor nominal (de 0 a 9).
Parametros : char
Retorno : int

*/
#include <stdio.h>
#include <stdlib.h>
//prototipo
char numeroNominal(char numero);

int main(){

char numero;
int nominal;
do{
    fflush(stdin);
    printf("Entre com um numero :");
    scanf("%c",&numero);
    printf("\n");

    nominal = numero;
    numero = numeroNominal (numero);
    printf("%c -> %c\n\n",nominal,numero);

}while(1);

}

char numeroNominal(char numero){
    int num;
    if(numero >= '0' && numero <= '9'){
        num = numero;
        return num;
    }else{ // validação de minusculos
        num = numero;
        return num;
    }
}
