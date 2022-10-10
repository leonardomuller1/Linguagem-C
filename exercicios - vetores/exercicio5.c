/******************************************************************************
Crie um vetor de 25  números inteiros, preenchido com valores aleatórios.
Ordene este vetor em ordem decrescente utilizando o algoritmo bublesort.
*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
int main()
{
 //variaveis 
 int numeros[25];
 int i, aux, contador;
 
 // geracao dos valores
 for (i = 0; i < 25; i++) {
 numeros[i]=rand()%1000;// limite de até 1000
 }
 
// ordenacao antes
printf("Ordem atual dos itens no vetor:\n");
for (i = 0; i < 25; i++) {
 printf("%4d ", numeros[i]);
}
// Algoritmo de ordenação Bubblesort:
 for (contador = 1; contador < 25; contador++) {
   for (i = 0; i < 25 - 1; i++) {
     if (numeros[i] > numeros[i + 1]) {
       aux = numeros[i];
       numeros[i] = numeros[i + 1];
       numeros[i + 1] = aux;
     }
   }
 }
printf("\nElementos do vetor em ordem crescente:\n");
for (i = 0; i < 25; i++) {
 printf("%4d ", numeros[i]);
}
return 0;
}