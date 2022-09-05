/*
 * @brief   conversor de temperatura de f para c
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    set/2022
 */

/*
Questao:
Converta um valor de temperatura expressa em oF para oC.
Parametros : float
Retorno : float

*/
#include <stdio.h>
#include <stdlib.h>
//prototipo
char FahrenheitparaCelsius (float grauf);

int main(){

float grauf;
float grauoriginal;
do{
    fflush(stdin);
    printf("Entre com o grau em Fahrenheit:");
    scanf("%f",&grauf);
    printf("\n");

    grauoriginal = grauf;
    grauf = FahrenheitparaCelsius (grauf);
    printf("%c -> %c\n\n",grauoriginal,grauf);

}while(1);

}

char FahrenheitparaCelsius(float grauf){
    int grauc;
    
    grauc = grauf -  32;
     
    
    return grauc;
}
