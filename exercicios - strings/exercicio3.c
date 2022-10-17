/******************************************************************************* 
 
Solicite ao usuário uma palavra. Exiba esta palavra com a primeira letra maiúscula e as demais letras minúsculas.

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
if(caracteres==0){
    printf("%c",(palavra[caracteres]-32));
    caracteres++;
}
while(palavra[caracteres]!='\0')
{
    printf("%c",palavra[caracteres]);
    caracteres++;
}

}
