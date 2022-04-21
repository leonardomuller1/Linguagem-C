/*
 * @brief   Verificador se eh letra,numero ou simbolo
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Elabore um programa que solicite a digitação de uma tecla. Classifique a tecla
digitada em letra (a - z, maiúsculas e minúsculas), numero (0 - 9 ) ou símbolo (se não for letra ou
numero).

*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    //declaracao das variaveis
    char caractere;

    // entrada de dados
    printf("Digite um caractere: ");
    scanf("%c", &caractere);
    printf("\n"); // espacamento

    //processamento 

    if(caractere >= 65 && caractere <=90 || caractere >= 97 && caractere <=122){
        printf("O caractere digitado %c eh uma letra",caractere);
    } else if (caractere >= 48 && caractere <=57){
        printf("O caractere digitado %c eh um numero",caractere);
    }else{
        printf("O caractere digitado %c eh um simbolo",caractere);
    }
    
}