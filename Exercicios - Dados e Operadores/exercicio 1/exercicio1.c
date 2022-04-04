/*
 * @brief   Desenho na tela usando a tabela ASCII
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    mar/2022
 */

/*
Questao:

Exiba na tela um desenho / figura montada a partir dos caracteres da tabela ASCII, utilizando a função printf(). 
Escolha algum tema relacionado ao curso.
*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    char trilha, diodo1, diodo2;

    trilha=45;  //carectere representando a trilha do circuito
    diodo1=124; //carectere metade do diodo sendo a parte reta do diodo
    diodo2=62; //carectere metade do diodo sendo a parte da seta

    printf("%c%c%c%c%c%c%c%c",trilha,trilha,trilha,trilha,diodo1,diodo2,diodo1,trilha); 
    //mostra no conselo o desenho usando as partes do "char desenho's"

}
