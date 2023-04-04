#include <stdio.h>
#include <stdlib.h>
/*
Considere uma estrutura (struct) para representar informações de uma pessoa, contendo os seguintes campos:

Nome (string)
Idade (inteiro)
Altura (real)
Peso (real)
Escreva um programa em C que leia os dados de 5 pessoas, armazene-os em um vetor de structs e, em seguida, calcule e exiba as seguintes informações:

A média de idade das pessoas
A média de altura das pessoas
A média de peso das pessoas
O nome e a idade da pessoa mais velha
O nome e a altura da pessoa mais alta
O nome e o peso da pessoa mais pesada
*/

struct pessoa{
    char nome[50];
    int idade;
    float altura, peso;
}pessoas[5];
int main()
{
    //variaveis
    float mediaIdade=0,mediaAltura=0,mediaPeso=0;
    int maisVelho = 0, maisAlto = 0,maisPesado=0;
    int indiceNomeMaisVelho=0,indiceNomeMaisAlto=0,indiceNomeMaisPesado=0;
    //entrada de dados
    for(int i=1;i<=5;i++){
        printf("Qual o nome da pessoa %i: ",i);
        scanf(" %[^\n]",&pessoas[i].nome);
        printf("Qual a idade da pessoa %i: ",i);
        scanf("%i",&pessoas[i].idade);
        printf("Qual a altura da pessoa %i: ",i);
        scanf("%f",&pessoas[i].altura);
        printf("Qual o peso da pessoa %i: ",i);
        scanf("%f",&pessoas[i].peso);

        //processamento das medias
        mediaIdade = mediaIdade + pessoas[i].idade;
        mediaAltura = mediaAltura + pessoas[i].altura;
        mediaPeso = mediaPeso + pessoas[i].peso;


        if(pessoas[i].idade > maisVelho){
            maisVelho = pessoas[i].idade;
            indiceNomeMaisVelho = i;
        }
        if(pessoas[i].altura > maisAlto){
            maisAlto = pessoas[i].altura;
            indiceNomeMaisAlto = i;
        }
        if(pessoas[i].peso > maisPesado){
            maisPesado = pessoas[i].peso;
            indiceNomeMaisPesado = i;
        }
    }
    mediaIdade = mediaIdade / 5;
    mediaAltura = mediaAltura / 5;
    mediaPeso = mediaPeso / 5;


    //exibição
    printf("\n\nMedia idade: %.2f",mediaIdade);
    printf("\n\nMedia altura: %.2f",mediaAltura);
    printf("\n\nMedia peso: %.2f",mediaPeso);

    printf("\n%s eh o mais velho, com %i",pessoas[indiceNomeMaisVelho].nome,maisVelho);
    printf("\n%s eh o mais alto, com %i",pessoas[indiceNomeMaisAlto].nome,maisAlto);
    printf("\n%s eh o mais pesado, com %i",pessoas[indiceNomeMaisPesado].nome,maisPesado);
}
