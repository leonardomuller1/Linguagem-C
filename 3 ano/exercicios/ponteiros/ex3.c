/*
3. int ordena (int *n1, int *n2, int *n3, char ordem );
Função :ordena os valores passados em ordem crescente ou decrescente.
Parâmetros : n1, n2 e n3 – ponteiros com valores a serem ordenados
ordem – ‘c’ para ordenamento crescente e ‘d’ para ordenamento
decrescente. Pode ser maiusculo ou minusculo.
Retorno : 0 para função realizada, -1 para erro de parametro
*/
#include <stdio.h>

int ordena(int *n1, int *n2, int *n3, char ordem);

int main() {
    char ordemF;
    int n1 = 5, n2 = 3, n3 = 7;
    printf("Qual a ordem?");
    scanf("%c",&ordemF);
    printf("\nAntes da ordenacao: %d %d %d", n1,n2,n3);
    ordena(&n1,&n2,&n3,ordemF);
    printf("\nDepois da ordenacao: %d %d %d", n1,n2,n3);

}


int ordena(int *n1, int *n2, int *n3, char ordem) {
    if (!n1 || !n2 || !n3) {
        // Verifica se os ponteiros são nulos
        return -1;
    }
    int temp;
  if (ordem == 'c' || ordem == 'C') {
        // Ordena em ordem crescente
        if (*n1 > *n2) {
            temp = *n1;
            *n1 = *n2;
            *n2 = temp;
        }
        if (*n2 > *n3) {
            temp = *n2;
            *n2 = *n3;
            *n3 = temp;
        }
        if (*n1 > *n2) {
            temp = *n1;
            *n1 = *n2;
            *n2 = temp;
        }

    } else if (ordem == 'd' || ordem == 'D') {
        // Ordena em ordem decrescente
        if (*n1 < *n2) {
            temp = *n1;
            *n1 = *n2;
            *n2 = temp;
        }
        if (*n2 < *n3) {
            temp = *n2;
            *n2 = *n3;
            *n3 = temp;
        }
        if (*n1 < *n2) {
            temp = *n1;
            *n1 = *n2;
            *n2 = temp;
        }
    } else {
        // Se o caractere de ordem for inválido, retorna -1
        return -1;


    }


}
