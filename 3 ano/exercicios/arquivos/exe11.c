#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*
Faça um programa que receba do usuário um arquivo texto. Crie outro arquivo texto contendo o texto do arquivo de entrada, mas com as vogais substituídas por ‘*’.

*/
int main(void)
{
    setlocale(LC_ALL, "portuguese"); // Definir localidade padrão

    FILE *file, *fileModificado;
    char arquivo[1000];
    char arquivoModificado[1000];

    printf("Localizacao do arquivo original: ");
    fgets(arquivo, sizeof(arquivo), stdin);
    arquivo[strcspn(arquivo, "\n")] = '\0';
    strcat(arquivo, ".txt");
    file = fopen(arquivo, "r");

    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo original.\n");
        return 1;
    }

    printf("Localizacao do arquivo modificado: ");
    fgets(arquivoModificado, sizeof(arquivoModificado), stdin);
    arquivoModificado[strcspn(arquivoModificado, "\n")] = '\0';
    strcat(arquivoModificado, ".txt");
    fileModificado = fopen(arquivoModificado, "w");

    if (fileModificado == NULL)
    {
        printf("Erro ao abrir o arquivo modificado.\n");
        return 1;
    }

    char textoOriginal[4000];
    char textoModificado[4000];
    int i = 0;

    while (fgets(textoOriginal, sizeof(textoOriginal), file))
    {
        for (i = 0; i < strlen(textoOriginal); i++)
        {
            if (textoOriginal[i] == 'a' || textoOriginal[i] == 'A' ||
                textoOriginal[i] == 'e' || textoOriginal[i] == 'E' ||
                textoOriginal[i] == 'i' || textoOriginal[i] == 'I' ||
                textoOriginal[i] == 'o' || textoOriginal[i] == 'O' ||
                textoOriginal[i] == 'u' || textoOriginal[i] == 'U')
            {
                textoModificado[i] = '*';
            }
            else
            {
                textoModificado[i] = textoOriginal[i];
            }
        }

        textoModificado[i] = '\0';
        fputs(textoModificado, fileModificado);
    }

    fclose(fileModificado);
    fclose(file);

    printf("Modificacao realizada com sucesso.\n");

    return 0;
}
