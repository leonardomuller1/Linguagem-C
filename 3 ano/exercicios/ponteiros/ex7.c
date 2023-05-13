/*
7. void ordena_alfa (char *p1, char *p2 );
Função :coloca as palavras p1 e p2 em ordem alfabética
Parâmetros : p1 e p2 – duas strings a serem ordenadas
Dica : use a função strcmp();
*/
#include <stdio.h>
#include <conio.h>

void ordena_alfa (char *p1, char *p2 );

int main() {
    char p1[500];
    char p2[500];

    printf("Qual a primeira palavra?");
    scanf(" %[^\n]",&p1);

    printf("Qual a segunda palavra?");
    scanf(" %[^\n]",&p2);

    ordena_alfa(&p1,&p2);


    printf("Palavra 1: %s\n", p1);
    printf("Palavra 2: %s\n", p2);
}

void ordena_alfa (char *p1, char *p2 ){

    /* EXEMPLO: de como funciona a strcmp
    p1 = a
    p2 = b
    ordem = -1

    p1 = b
    p2 = a
    ordem = 1

    p1 = a
    p2 = a
    ordem = 0
    */
    int ordem  = strcmp(p1,p2);

    char cloneP1[500];
    char cloneP2[500];
    strcpy (cloneP1,p1); // copia o conteudo de P1 para cloneP1
    strcpy (cloneP2,p2);

    if(ordem == 1){
        strcpy (p1,cloneP2);
        strcpy (p2,cloneP1);
    }


}
