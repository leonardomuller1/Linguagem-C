#include <stdio.h>
#include <conio.h>
#include <stdlib.h>// necesario p/ as funcoes rand() e srand()
#include <stdio.h>
#include <time.h>//necesario p/ funcao time()

#define MAX 50 //definicao do tamanho
#define MAXNUMEROS 100 // limitacao de valores gerados

int verificarPrimo(int num){ //verificacao separada de um numero por vez
	
	int contagem = 0;
	
	for(int i=1; i<=num; i++) {
		if(num % i == 0) {
			contagem ++;
		}
	}
		
	
	return (contagem == 2); //se contagem ficar com valor de 2, nao primo, logo retornara¡ 1, senao 0.
}

int main(){
	
	int vetor[MAX], cont=0,maior,posMaior, menor, posMenor;
	
	srand(time(NULL)); // deixa "aleatorio" a geracao dos valores
	
	// geracao dos numeros
	for(int i=0; i<MAX; i++){
	    vetor[i]= rand()%(MAXNUMEROS - 1) + 1; // valor minimo 1 e maximo pelo MAXNUMEROS
	}
	
	// maior valor do vetor
	maior = vetor[0]; // sempre inicializa com o primeiro valor do vetor
	posMaior = 0; // posicao do maior comeca em zero
	for(int i=1; i<MAX; i++){
	   if(vetor[i]> maior){
	       maior = vetor[i];
	       posMaior = i;
	   }
	}   
    	// exibicao do maior valor do vetor
    	printf("\n\n O maior valor do vetor eh: %d , na posicao %d",maior,posMaior);
    	
    // menor valor do vetor
	menor = vetor[0]; // sempre inicializa com o primeiro valor do vetor
	posMenor = 0; // posicao do menor comeca em zero
	for(int i=1; i<MAX; i++){
	   if(vetor[i]< menor){
	       menor = vetor[i];
	       posMenor = i;
	   }
	}   
    	// exibicao do menor valor do vetor
    	printf("\n\n O menor valor do vetor eh: %d , na posicao %d",menor,posMenor);
	
	
	// numeros primos
	printf("\n\n Os numeros primos do vetor eh: ");
	for(int i=0; i<MAX; i++)
		if(verificarPrimo(vetor[i])){ //se retornar 1 eh um primo, e logo serao incrementado
		    cont++;
            printf("%d ", vetor[i]);
		}
	
	return 0;
}