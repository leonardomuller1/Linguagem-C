#include <stdio.h>

/*
Solicite que o usuário escreva uma frase, escolha um caractere para busca e um caractere para substituição.
Realize a substituição escolhida. Exiba o resultado.
*/

int main()
{

char frase[250];
char caractere[2];
char novo_caractere[2];
int i;
int j = 0;
int count = 0;

    printf( "escveva uma frase: " );
    scanf( "%[^\n]", frase); //ignora o espaço
    printf( "qual o caractere: " );
    scanf( "%s", caractere);
    printf( "qual o novo caractere: " );
    scanf( "%s", novo_caractere);


for(int i = 0; frase[i] != '\0'; i++){ // enquanto a frase não terminar roda o codigo

    if (caractere[j] == frase[i])
    {
        j += 1;
        if (caractere[j] == '\0')
        {
            frase[i]= novo_caractere[0];
            count++; // contador de caracteres trocados
            j = 0;
        }
    }
    else
    {
        j = 0;
    }
}

    printf("FRASE MODIFICADA:\n\n");
    i = 0; // reinicia o index
    // exibi a frase modificada
    while(frase[i]!='\0')
    {
        printf("%c",(frase[i]));
        i++;
    }
    // numeros de caracteres trocados
    printf( "\nnumero de caracteres trocados = %d\n",count);
    return 0;

}
