#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void preencherVetor(int* vetor, int tamanho) {
    srand(time(NULL));
    for (int i = 0; i < tamanho; i++) {
        *(vetor + i) = rand() % 100 + 1;
    }
}

void inverterVetor(int* vetor, int tamanho) {
    int *inicio = vetor;
    int *fim = vetor + tamanho - 1;
    
    while (inicio < fim) {
        int temp = *inicio;
        *inicio = *fim;
        *fim = temp;
        
        inicio++;
        fim--;
    }
}

void exibirVetor(int* vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("Posição %d: %d\n", i, *(vetor + i));
    }
}

int main() {
    int vetor[400];
    int tamanho = 400;

    preencherVetor(vetor, tamanho);
    
    printf("Vetor original:\n");
    exibirVetor(vetor, tamanho);

    inverterVetor(vetor, tamanho);
    
    printf("\nVetor invertido:\n");
    exibirVetor(vetor, tamanho);

    return 0;
}
