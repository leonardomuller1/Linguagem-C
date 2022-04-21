/*
 * @brief   Verificador se eh minuscula ou maiscula
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Elabore um programa que solicita a digitação de uma letra. Indique se a letra digitada é maiúscula ou minúscula. 
Se não for letra, aponte o fato também.

*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    //declaracao das variaveis
    char letra;

    // entrada de dados
    printf("Digite uma letra: ");
    scanf("%c", &letra);
    printf("\n"); // espacamento

    //processamento 

    if(letra >= 65 && letra <=90){
        printf("A letra %c eh maiscula",letra);
    } else if (letra >= 97 && letra <=122){
         printf("A letra %c eh minuscula",letra);
    }else{
        printf("O %c nao eh uma letra",letra);
    }
    
}