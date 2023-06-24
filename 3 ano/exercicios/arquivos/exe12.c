#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>
/*
 Faça um programa que leia o conteúdo de um arquivo e crie um arquivo com o mesmo conteúdo, mas com todas as letras minúsculas convertidas para maiúsculas. Os nomes dos arquivos serão fornecidos, via teclado, pelo usuário. A função que converte maiúscula para minúscula é  toupper(). Ela é aplicada em cada caractere da string.
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
            textoModificado[i] = toupper(textoOriginal[i]);
        }

        textoModificado[i] = '\0';
        fputs(textoModificado, fileModificado);
    }

    fclose(fileModificado);
    fclose(file);

    printf("Modificacao realizada com sucesso.\n");

    return 0;
}
