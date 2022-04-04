
/*
 * @brief   Dobro do carectere digitado
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Peça ao usuário que digite um caractere numérico (faça a entrada como char). 
    Obtenha o valor numérico do correspondente caractere (0 a 9) e exiba o dobro deste valor.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>


#include <stdio.h>
int main()
{
    //declaracao das variaveis
    char caractere, dob;

    // entrada de dados
    printf("\nDigite um caractere numerico: (0 a 9): ");
    scanf("%d",&caractere);
    printf("\n"); // espacamento

    //processamento
    
    dob = 2*caractere;

    // exibicao dos resultados
    printf("Caractere digitado: %d o dobro desse numero eh: %u", caractere,dob);

}

