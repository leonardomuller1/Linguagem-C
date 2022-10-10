/******************************************************************************

Repita o exercício anterior, neste caso o vetor gita deve ser preenchido de 
forma alternada, um valor do vetor alfa seguido de um valor do vetor omega, assim sucessivamente.



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
int controle=0;

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

for(i=0;i<8;i++){
    if(controle%2){
        gita[i]= alfa[i/2];
    }else{
        gita[i]= omega[i/2];
    }
    controle++;
    
}
// Exibindo resultado
for(i=0;i<8;i++){
    printf("%3d",gita[i]);
}

}// fim main
