#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necessário p/ as funções rand() e srand()
#include <stdio.h>
#include <time.h>//necessário p/ função time()

#define MAX 50 //definição do tamanho
#define MAXNUMEROS 1000 // limitacão de valores gerados

int verificarPrimo(int num){ //verificação separada de um numero por vez
	
	int contagem = 0;
	
	for(int i=1; i<=num; i++) {
		if(num % i == 0) {
			contagem ++;
		}
	}
		
	
	return (contagem == 2); //se contagem ficar com valor de 2, nao primo, logo retornara� 1, senao 0.
}

int main(){
	
	int vetor[MAX], cont=0;
	
	// geração dos numeros
	for(int i=0; i<MAX; i++){
	    vetor[i]= rand()%MAXNUMEROS; 
	}
	
	for(int i=0; i<MAX; i++)
		if(verificarPrimo(vetor[i])){ //se retornar 1 é um primo, e logo será incrementado
			cont++;
	       printf("%d ", vetor[i]);
		}
	printf("\n\nTotal de Numeros Primos: %d\n\n", cont);
	
	return 0;
}
