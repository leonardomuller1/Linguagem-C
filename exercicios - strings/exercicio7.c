#include <stdio.h>

/*
Solicite uma frase. Exiba a frase digitada, com cada palavra ocupando uma linha.
*/

int main()
{

char frase[250];
char palavra[50] = " ";
int i;
int j = 0;
int count = 1;

    printf( "escveva uma frase: " );
    scanf( "%[^\n]", frase );

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

    printf( "tem %d palavras nesta frase\n",count);


    return 0;

}
