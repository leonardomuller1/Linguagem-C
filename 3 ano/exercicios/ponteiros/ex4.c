/*
4. int sinal(float *frequencia, float *periodo );
Função : Calcula o parâmetro cujo valor é zero.
Parâmetros : frequencia – ponteiro para o valor de frequencia do sinal
             periodo – ponteiro para o valor do periodo do sinal

Retorno : 0 para função realizada, -1 para erro de parametro (dois parametros
em zero)
*/
#include <stdio.h>

int sinal(float *frequencia, float *periodo );

int main() {
    float frequencia, periodo;

    printf("Qual a frequencia?");
    scanf("%f",&frequencia);

    printf("Qual a periodo?");
    scanf("%f",&periodo);

    printf("\n\nA funcao retornou %i\n\n",sinal(&frequencia,&periodo));

    printf("\nA frequencia eh %f",frequencia);
    printf("\nO periodo eh %f",periodo);

}

int sinal(float *frequencia, float *periodo ) {
   if(*frequencia == 0 && *periodo == 0){
        return -1;
   }else if(*frequencia && *periodo){
           return -2;
   }else if(*frequencia == 0){
        float aux = *periodo;
        float inv = 1 / aux;
        *frequencia = inv;
        return 0;
   }else if(*periodo == 0){
        float aux = *frequencia;
        float inv = 1 / aux;
        *periodo = inv;
        return 0;
   }
}
