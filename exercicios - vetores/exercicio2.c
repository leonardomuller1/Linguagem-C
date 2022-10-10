/******************************************************************************

Declare dois vetores tipo int, alfa e omega, cada um com 4 elementos, e um  vetor de 8 elementos, gita.
Solicite ao usuário valores para preencher os vetores alfa e omega.
Copie para o vetor gita o conteúdo dos vetores alfa e omega, nesta ordem.
Exiba os vetores resultantes.



*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

// Parametros do programa

int main(void)
{
int alfa[4];
int omega[4];
int gita[8];
int i;

// preenchendo os vetores com valores 
for (i=0;i<4;i++)
{
    printf("Valor de alfa %d:",i+1);
    scanf("%d",&alfa[i]);
}
for (i=0;i<4;i++)
{
    printf("Valor de omega %d:",i+1);
    scanf("%d",&omega[i]);
}

// processamento 

for(i=0;i<7;i++){
    if(i<4){
        gita[i]= alfa[i];
    }else{
        gita[i]= omega[i/2];
    }
    
}
// Exibindo resultado
for(i=0;i<7;i++){
    printf("%3d",gita[i]);
}

}// fim main