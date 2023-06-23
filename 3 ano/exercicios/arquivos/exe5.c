#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Elaborar um programa em C que lê uma string de no máximo
80 caracteres e a escreve num arquivo de nome “string.tx_” da
seguinte forma:
a) Toda a string;
b) Uma linha em branco;
c) A string invertida;
d) Uma linha em branco;
e) Cada palavra da string numa linha;
f) Uma linha em branco;
g) Cada letra da string numa linha;
h) Uma linha em branco;
i) Cada caracter da string e quantas vezes ele esta
presente na string;

Posteriormente, abrir o arquivo “string.tx_” e escrever o seu
conteúdo.
*/
int main(void)
{
    FILE *file;
    char arquivo[] = "C:\\Users\\leona\\Desktop\\string.txt";
    char texto[80];

    file = fopen(arquivo, "w"); // abrindo o arquivo em modo de escrita
    if (file == NULL)   // validação de erros
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    printf("Qual a string:");
    fgets(texto, sizeof(texto), stdin); // ler a string

    int i, j;
    char tempo;
    char tempInvert[80];
    char tempPalavra[80];
    char tempLetra[161]; // 80 * 2 + 1 = 161
    tempLetra[0] = '\0'; // Limpa o lixo da memória
    strcpy(tempInvert, texto);
    strcpy(tempPalavra, texto);

    // Inversor
    for (i = 0, j = strlen(tempInvert) - 1; i < j; i++, j--)
    {
        tempo = tempInvert[i];
        tempInvert[i] = tempInvert[j];
        tempInvert[j] = tempo;
    }

    // Cada palavra em uma linha
    for (i = 0; i < strlen(tempPalavra); i++)
    {
        if (tempPalavra[i] == ' ')
        {
            tempPalavra[i] = '\n';
        }
    }

    // Cada letra em uma linha
    for (i = 0, j = 0; i < strlen(texto); i++)
    {
        tempLetra[j++] = texto[i];
        tempLetra[j++] = '\n';
    }
    tempLetra[j] = '\0'; // Adiciona o caractere nulo ao final de tempLetra

    strcat(texto, tempInvert); // Juntando os valores
    strcat(texto, "\n\n"); // Linha em branco
    strcat(texto, tempPalavra); // Juntando os valores
    strcat(texto, "\n\n"); // Linha em branco
    strcat(texto, tempLetra); // Linha em branco

    // Contagem de caracteres
    for (i = 0; i < 80; i++) {
        int contador=0;
        char caractere = texto[i];
        for (j = 0; j < 80; j++){
            if(caractere == texto[j]){
                contador++;
            }
        }
        printf("%c: %i",caractere,contador);

    }
    // Escrevendo a string no arquivo
    fputs(texto, file);
    fclose(file); // fecha o arquivo

    printf("Texto gravado no arquivo.\n");

    return 0;
}
