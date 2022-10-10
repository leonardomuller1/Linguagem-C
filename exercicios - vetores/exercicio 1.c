/******************************************************************************

Declare um vetor com 13 elementos inteiros e preencha-o com valores aleatórios na faixa de 10 a 55. 
Identifique qual é o maior e o menor valor presente no vetor, bem como a posição em que eles ocorrem. Considere a primeira ocorrência no caso de valores múltiplos.
Exiba o vetor e os valores extremos encontrados.


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// Parametros do programa
#define N_ITENS 13  // Tamanho do vetor

int main(void)
{
int sorteio[N_ITENS]; // reservando espaco para os dados
int i;   // indice para manipulacao do vetor
int maior=0;
int menor=100; // para resolver um erro do codigo
int posicaomenor;
int posicaomaior;
srand(time(NULL)); // inicializa gerador randomico

// preenchendo o vetor com valores aleatorios
for (i=0;i<N_ITENS;i++)
    {
    sorteio[i]=10+rand()%45;
    }
// Exibindo resultado
printf("Vetor :"); //exibe a string na tela, adiciona \n ao final
for (i=0;i<N_ITENS;i++)
    {
    if(maior< sorteio[i]){
        maior= sorteio[i];
        posicaomaior = i+1;
    }
    if(menor > sorteio[i]){
        menor = sorteio[i];
        posicaomenor = i+1;
    }
    printf("%3d  ",sorteio[i]);
    }
    printf("\nMaior: %3d Posicao: %3d",maior, posicaomaior);
    printf("\nMenor: %3d Posicao: %3d",menor,posicaomenor);
    printf("\nValor extremos: %3d %3d",sorteio[0],sorteio[12]);
}// fim main