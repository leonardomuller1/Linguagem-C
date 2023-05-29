#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Escrever um programa que lê uma string
s[30] e escreve cada palavra desta string
numa nova linha dentro de um arquivo.
*/

int main(void)
{
    FILE *file;
    char texto[30];

    file = fopen("C:\\Users\\leona\\Desktop\\teste.txt", "w"); // abrindo o arquivo
    if (file == NULL) { // validação de erros
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    printf("Digite uma string: ");
    fgets(texto, sizeof(texto), stdin); //sizeof tamanho da string

    // função
    int i;
    for (i = 0; i < sizeof(texto); i++) {
        if(texto[i]== ' '){
            texto[i] = '\n';
        }
    }

    fputs(texto, file); // envia a string invertida
    fclose(file); // fecha o arqutivo

    printf("Dados gravados no arquivo.\n");

    return 0;
}
