/*
 * @brief   sequência numérica
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    ago/2022
 */

/*
Questao:
Solicite ao usuário um intervalo numérico. Exiba os números primos presentes neste intervalo.
*/

#include <stdio.h>

int main(){
int primo=0, a = 0,b = 0 ,tem_primo = 0;
printf("Numeros primos::.\n");


printf("Digite o numero a:\n");
scanf("%d",&a);
printf("Digite o numero b:\n");
scanf("%d",&b);


for(int i = a; i<=b; i++){

  //Inicia o verificador sempre como zero
  primo=0;

  for (int x = 1; x <=i; x++) {
    if(i % x == 0){
      primo++;
    }
  }
  if(primo==2){

    //Mostra na tela os numeros primos um a um
    printf("%d ", i);
    tem_primo = 1;
  }
}

//Verifica se há primos no intervalo
if(tem_primo == 0){
  printf("\nNao possui primos no intervalo");
}
}
