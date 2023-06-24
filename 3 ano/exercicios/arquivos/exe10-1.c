#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(void)
{
    FILE *file;
    char arquivo[100];
    printf("Localizacao do arquivo:");
    fgets(arquivo, sizeof(arquivo), stdin);
    arquivo[strcspn(arquivo, "\n")] = '\0';
    strcat(arquivo, ".txt");

    char texto[4000];
    int contador[26]={0};  // Array para contar as letras do alfabeto

    file = fopen(arquivo, "r");
    if (file == NULL)
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    
    while(fgets(texto, sizeof(texto), file)){
        for (int i = 0; i < strlen(texto); i++)
        {
            char letra= texto[i];
            if (letra >= 'a' && letra <= 'z') 
            {
                contador[letra - 'a']++;
            }
            if (letra >= 'A' && letra <= 'Z') 
            {
                contador[letra - 'A']++;
            }
        }
    }    

    printf("Ocorrências das letras do alfabeto:\n");
    for (i = 0; i < 26; i++)
    {
        printf("%c: %d\n", 'a' + i, contador[i]);
    }

    fclose(file);

    return 0;
}
