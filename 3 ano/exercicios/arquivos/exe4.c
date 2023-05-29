#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

/*
Escrever um programa que lê o conteúdo de um arquivo
e escreve em maiúsculo no mesmo arquivo.
*/

int main(void)
{
    FILE *file;
    char arquivo[] = "C:\\Users\\leona\\Desktop\\teste.txt";
    char texto[100];

    file = fopen(arquivo, "r+"); // abrindo o arquivo em modo de leitura e escrita
    if (file == NULL) { // validação de erros
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    while (fgets(texto, sizeof(texto), file)) {
        // Convertendo para maiúsculas
        int i;
        for (i = 0; i < strlen(texto); i++) {
            texto[i] = toupper(texto[i]);
        }

        // Voltando ao início da texto no arquivo
        fseek(file, -strlen(texto), SEEK_CUR);

        // Escrevendo a texto em maiúsculo no arquivo
        fputs(texto, file);
    }

    fclose(file); // fecha o arquivo

    printf("Texto gravado em maiúsculo no arquivo.\n");

    return 0;
}
