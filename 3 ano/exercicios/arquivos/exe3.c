#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Escrever um programa que lê o nome do arquivo
e escreve na tela o seu conteúdo.
*/

int main(void)
{
    FILE *file;
    char arquivo[]="C:\\Users\\leona\\Desktop\\teste.txt";
    char linha[100];

    file = fopen(arquivo, "r"); // abrindo o arquivo
    if (file == NULL) { // validação de erros
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    printf("Conteudo do arquivo: %s",arquivo);
    while (fgets(linha, sizeof(linha), file)) {
        printf("%s", linha);
    }

    fclose(file); // fecha o arqutivo

    return 0;
}
