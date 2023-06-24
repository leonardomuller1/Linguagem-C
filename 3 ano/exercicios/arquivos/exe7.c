#include <stdio.h>
#include <stdlib.h>
#include <string.h>
/*
Faça um programa que receba do usuário um arquivo texto e mostre na tela quantas letras são vogais.
*/
int main(void)
{
    FILE *file;
    char arquivo[100];
    printf("Localizacao do arquivo:");
    gets(arquivo);
    strcat(arquivo,".txt");

    char texto[4000];
    int a=0,e=0,i=0,o=0,u=0;
    file = fopen(arquivo, "r"); // abrindo o arquivo em modo de escrita
    if (file == NULL)   // validação de erros
    {
        printf("Erro ao abrir o arquivo.");
        return 1;
    }
    fgets(texto,sizeof(texto),file);//obtem o texto do arquivo 

    for (int j = 0; j < strlen(texto); j++) {
            char letra = tolower(texto[j]);
            if (letra == 'a') {
                a++;
            } else if (letra == 'e') {
                e++;
            } else if (letra == 'i') {
                i++;
            } else if (letra == 'o') {
                o++;
            } else if (letra == 'u') {
                u++;
            }
    }

     printf("A: %i\n",a);
     printf("E: %i\n",e);
     printf("I: %i\n",i);
     printf("O: %i\n",o);
     printf("U: %i\n",u);
    fclose(file); // fecha o arquivo

    return 0;
}
