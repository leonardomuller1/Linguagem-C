/******************************************************************************

A Megasena acumulou novamente e você quer tentar a sorte, mas não se sente inspirado para escolher os números para a aposta. 
Construa um programa capaz de gerar um volante de aposta de 6 números.
Lembre-se, os números não podem se repetir.


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main() {

    int i = 0, j, igual, vet[6];

    srand(time(NULL));
    printf("Numeros da Megasena:\n");
    do{ // faça
        vet[i] = rand() % 60; // sorteia um número
        igual = 0;
        for(j = 0; j < i; j++){ // percorre a parte do vetor já preenchida
            if(vet[j] == vet[i])
                igual = 1; // número repetido
        }

        if(igual == 0) // significa que o elemento não se repetiu
            i++;
    }while(i < 6); // enquanto não for sorteado 6 números diferentes

    for(i = 0; i < 6; i++){
        printf("%d \n", vet[i]);
    }
    printf("\n\n");

    return 0;
}