#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Elaborar um programa em C que lê uma string de no máximo
40 caracteres e a escreve num arquivo, com o nome definido
pelo usuário, da seguinte forma:
a) Toda a string numa linha;
b) Uma linha em branco;
c) Dois caracteres por linha, separados por uma
tabulação. O primeiro caracter corresponde ao
minúsculo e o segundo ao maiúsculo da primeira
ocorrência da string. Na próxima linha do arquivo, a
segunda ocorrência da string.

Exemplo: “uma”

uma
u U
m M
a A
*/
int main(void)
{
    FILE *file;
    char arquivo[100];
    printf("Localizacao do arquivo:");
    gets(arquivo);
    strcat(arquivo,".txt");

    char texto[40];
    char temp[80];
    int i,j;
    file = fopen(arquivo, "w"); // abrindo o arquivo em modo de escrita
    if (file == NULL)   // validação de erros
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    printf("Qual a string:");
    fgets(texto, sizeof(texto), stdin); // ler a string
    fprintf(file,"%s \n",texto);

    for (i = 0, j = 0; i < strlen(texto); i++)
    {
        char letra = texto[i];
        fprintf(file, "%c\t%c\n", tolower(letra), toupper(letra));
    }
    temp[j] = '\0'; // Adiciona o caractere nulo ao final de tempLetra

    // Escrevendo a string no arquivo
    fclose(file); // fecha o arquivo

    printf("Texto gravado no arquivo.\n");

    return 0;
}
