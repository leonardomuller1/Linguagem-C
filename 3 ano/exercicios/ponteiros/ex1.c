/*
1. Qual é o resultado do seguinte programa?
#include <stdio.h>
int main(void)
{
float vet[5] = {1.1,2.2,3.3,4.4,5.5};
float *f;
int i;
f = vet;
printf("contador/valor/valor/endereco/endereco");
for(i = 0 ; i <= 4 ; i++)
{
printf("\ni = %d",i);
printf(" vet[%d] = %.1f",i, vet[i]);
printf(" *(f + %d) = %.1f",i, *(f+i));
printf(" &vet[%d] = %X",i, &vet[i]);
printf(" (f + %d) = %X",i, f+i);
}
}
Implemente a função descrita nas questões a seguir, seguindo as especificações. No mesmo
exercício, construa a função main() que utilize ou teste a função desenvolvida.
*/
#include <stdio.h>
int main(void)
{
float vet[5] = {1.1,2.2,3.3,4.4,5.5};
float *f;
int i;
f = vet;
printf("contador/valor/valor/endereco/endereco");
for(i = 0 ; i <= 4 ; i++)
    {
    printf("\ni = %d",i); //indice do looping
    printf(" vet[%d] = %.1f",i, vet[i]); //valor do vet
    printf(" *(f + %d) = %.1f",i, *(f+i)); //valor do vet usando a notação de ponteiro
    printf(" &vet[%d] = %X",i, &vet[i]); // valor da memoria
    printf(" (f + %d) = %X",i, f+i); // valor da memoria usando a notação de ponteiro
    }
    
}
