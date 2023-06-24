#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Faça um programa que receba do usuário um arquivo texto e um caracter. Mostre na tela quantas vezes aquele caractere ocorre dentro do arquivo.
 */
int main(void)
{
    FILE *file;
    char arquivo[100];
    printf("Localizacao do arquivo:");
    fgets(arquivo, sizeof(arquivo), stdin);
    arquivo[strcspn(arquivo, "\n")] = '\0';
    strcat(arquivo, ".txt");

    char letra;
    char texto[4000];
    int i = 0;
    printf("Qual a letra:");
    scanf("%c",&letra);


    file = fopen(arquivo, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }

    while (fgets(texto, sizeof(texto), file))
    {
        for (int j = 0; j < strlen(texto); j++)
        {
            if (letra == texto[j])
            {
                i++;
            }
        }
    }

    printf("A letra '%c' tem : %i\n", letra,i);

    fclose(file);

    return 0;
}
