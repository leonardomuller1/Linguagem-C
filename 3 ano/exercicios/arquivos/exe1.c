#include <stdio.h>
#include <stdlib.h>

/*
Escrever um programa que lê uma string
e a escreve em ordem inversa num
arquivo.
*/

int main(void)
{
    FILE *file;
    char texto[800];

    file = fopen("C:\\Users\\leona\\Desktop\\teste.txt", "w"); // abrindo o arquivo
    if (file == NULL) { // validação de erros
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    printf("Digite uma string: ");
    fgets(texto, sizeof(texto), stdin); //sizeof tamanho da string

    // Inverte a string
    int i, j;
    char tempo;
    for (i = 0, j = strlen(texto) - 1; i < j; i++, j--) {
        tempo = texto[i];
        texto[i] = texto[j];
        texto[j] = tempo;
    }

    fputs(texto, file); // envia a string invertida
    fclose(file); // fecha o arqutivo

    printf("String invertida gravada no arquivo.\n");

    return 0;
}
