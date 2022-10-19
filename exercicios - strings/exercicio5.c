#include <stdio.h>
#include <stdlib.h>


int main()
{
    
char nome[50];
char sobrenome[50];
char nomeCompleto[100];
int i;
int j;
printf("Digite seu nome:");
scanf ( "%[^\n]", nome);

printf("Digite seu sobrenome:");
scanf ( "%[^\n]", sobrenome);

i=0;
do{
    nomeCompleto[i]=nome[i];

}while(nome[i++]!='\0');
i--;

nomeCompleto[i++]=' ';

j=0;
do{
    nomeCompleto[i++]=sobrenome[j];

}while(sobrenome[j++]!='\0');

printf("Bem vindo, %s\n",nomeCompleto);


}
