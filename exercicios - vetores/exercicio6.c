/******************************************************************************
Os palpites até que ficaram bons, mas podia ser mais fácil para preencher o volante de apostas. 
Vamos melhorar o exercicio anterior, colocando os números sorteados em ordem crescente.
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
 numeros[i]=rand()%1000;// limite de atÃ© 1000
 }
 
// ordenacao antes
printf("Ordem atual dos itens no vetor:\n");
for (i = 0; i < 25; i++) {
 printf("%4d ", numeros[i]);
}
// Algoritmo de ordenaÃ§Ã£o Bubblesort:
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
