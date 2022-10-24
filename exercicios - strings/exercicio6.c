#include <stdio.h>
#include <stdlib.h>

/*
Solicite ao usuário que digite seu nome e último sobrenome (uma variável).
Separe a variável em duas, garantindo que a primeira letra é maiúscula e as demais são minúsculas. Exiba o resultado
*/

int main()
{

char nome[50];
char sobrenome[50];
char nomeCompleto[50];
int i;
int j;
printf("Digite seu nome completo:");
scanf ( "%[^\n]", nomeCompleto);

i=0;
do{
    nome[i]=nomeCompleto[i];
    if(nome[i]>= 'A' && nome[i] <= 'Z'){
        nome[i] = nome[i] +('a'- 'A');
    }
    if(nome[0]>= 'a' && nome[0] <= 'z'){
        nome[0] = nome[0] -('a'- 'A');
    }

}while(nome[i++]!='\0');

j=0;

do{
    sobrenome[j]=nomeCompleto[i];
    if(sobrenome[j]>= 'A' && sobrenome[j] <= 'Z'){
        sobrenome[j] = sobrenome[j] +('a'- 'A');
    }
    if(sobrenome[0]>= 'a' && sobrenome[0] <= 'z'){
        sobrenome[0] = sobrenome[0] -('a'- 'A');
    }
    i++;
}while(nome[j++]!='\0');

printf("Bem vindo, %s %s",nome,sobrenome);
}
