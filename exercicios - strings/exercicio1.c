/******************************************************************************* 
 
Solicite que o usuário digite uma palavra.
Exiba a palavra na ordem contrária (de trás para frente).
Informe a quantidade de caracteres desta palavra

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{

char palavra[50];
int ordemcontraria;
int caracteres;
int i;
printf("palavra na ordem contraria\n");

printf("Digite sua palavra:");
scanf("%s",palavra);

caracteres=0;
while(palavra[caracteres]!='\0')
{
    caracteres++;
}
printf("\n\npalavra contraria: ");
for(i=caracteres;i>=0;i--){
    printf("%c",palavra[i]);
}
    printf("\n\nNumero de caracteres: %i",caracteres);

}
