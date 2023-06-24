#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas letras são vogais e quantas são consoantes.
 */
int main(void)
{
    FILE *file;
    char arquivo[100];
    printf("Localizacao do arquivo:");
    fgets(arquivo, sizeof(arquivo), stdin);
    arquivo[strcspn(arquivo, "\n")] = '\0';
    strcat(arquivo, ".txt");

    char texto[4000];
    int vogais = 0, consoantes = 0;

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
            char letra = tolower(texto[j]);
            if (letra == 'a' || letra == 'e' || letra == 'i' || letra == 'o' || letra == 'u')
            {
                vogais++;
            }
            else if (letra >= 'a' && letra <= 'z')
            {
                consoantes++;
            }
        }
    }

    printf("Vogais: %i\n", vogais);
    printf("Consoantes: %i\n", consoantes);

    fclose(file);

    return 0;
}
