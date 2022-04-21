/*
 * @brief   Calculadora
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Elabore um programa capaz de realizar calculos artimeticos com numeros reis a partir da entrada do usuário.
A entrada do usuário deve ser no formato valor1 op valor2, onde valor1 e valor2 são os operandos e 
operando é a operação a ser realizada ( + - / *);

*/

// Includes
#include <stdio.h>
#include <conio.h>

int main() {
    //declaracao das variaveis
    int op, valor1, valor2;

        printf("\n1 - Soma\n2 - Subtracao\n3 - Multiplicacao\n4 - Divisao\n\n\n");
        scanf("%d", &op);

        if(op > 0 && op < 5){
            printf("Digite dois valores: ");
            scanf("%d%d",&valor1, &valor2);
        }

        switch(op) {
        case 1:
            printf("Soma: %d\n", valor1 + valor2);
            break;
        case 2:
            printf("Subtracao: %d\n", valor1 - valor2);
            break;
        case 3:
            printf("Multiplicacao: %d\n", valor1 * valor2);
            break;
        case 4:
            if(valor2 == 0) {
                printf("Nao existe divisao por zero!\nDigite outro valor: ");
                scanf("%d", &valor2);
            }else{
            printf("Divisao: %d\n", valor1 / valor2);
            break;
            }
        default:
            printf("opcao inválida.\nDigite outra opcao: ");
        }
}

