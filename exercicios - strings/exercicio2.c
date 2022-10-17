/******************************************************************************* 
 
Solicite ao usuário que escreva uma palavra. Exiba esta palavra com todas as letras maiúsculas.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{

char palavra[50];
int caracteres;
printf("palavra em maiuscula\n");

printf("Digite sua palavra:");
scanf("%s",palavra);

caracteres=0;
while(palavra[caracteres]!='\0')
{
    printf("%c",(palavra[caracteres]-32));
    caracteres++;
}

}
