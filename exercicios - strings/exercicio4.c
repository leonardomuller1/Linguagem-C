/******************************************************************************* 
 
Faça um programa em C que leia uma palavra pelo teclado e faça a impressão conforme o exemplo a seguir para a palavra OLA.
O
OL
OLA


*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

int main()
{

char palavra[50];
int caracteres = 0;
int i = 0;
int k = 0;

printf("Digite sua palavra:");
scanf("%s",palavra);

while(palavra[caracteres]!='\0'){
	i = caracteres;
	k= 0;
	while(i>=0){
		printf("%c",palavra[k]);
		i--;
		k++;
	}
		printf("\n");
	caracteres++;
}






}
