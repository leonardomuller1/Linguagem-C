#include <stdio.h>

/*
Solicite uma frase. Exiba a frase digitada, com cada palavra ocupando uma linha.
*/

int main()
{

char frase[250];
int i = 0;

    printf( "escreva uma frase: " );
    scanf( "%[^\n]", frase );
    int num =  strlen(frase);

do{
    if(frase[i] == ' '){
        printf("\n");
    }
    if(i == 0){
        printf(" ");
    }
    printf("%c",frase[i]);
    i++;
}while(i<num);

    return 0;
}
