#include <stdio.h>

/*
Solicite que o usuário escreva uma frase e escolha um caractere. Exiba o número de  ocorrências do caractere na frase.
*/

int main()
{

char frase[250];
char palavra[50];
int i;
int j = 0;
int count = 0;

    printf( "escveva uma frase: " );
    scanf( "%[^\n]", frase );
    printf( "escreve um caractere: " );
    scanf( "%s", palavra );

for(int i = 0; frase[i] != '\0'; i++)

    if (palavra[j] == frase[i])
    {
        j += 1;
        if (palavra[j] == '\0')
        {
            count += 1;
            j == 0;
        }
    }
    else
    {
        j = 0;
    }

    printf( "tem %s = %d\n",palavra ,count);


    return 0;

}
