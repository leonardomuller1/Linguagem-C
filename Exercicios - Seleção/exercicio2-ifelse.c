/*
 * @brief   Sistema de notas com sistema
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
 */

/*
Questao:

Elaborar programa que escreva o conceito de um aluno, dada a sua nota. Fazer uma versão utilizando estrutura if-else e 
outra utilizando switch-case. Supor notas inteiras somente. O critério para conceitos é o seguinte:

nota inferiores a 3 conceito E
nota de 3 a 5 conceito D
notas 6 e 7 conceito C
notas 8 e 9 conceito B
nota 10 conceito A

*/

// Includes
#include <stdio.h>
#include <conio.h>

int main()
{
    //declaracao das variaveis
    int nota;

    // entrada de dados
    printf("\nQual a nota: ");
    scanf("%i",&nota);
    printf("\n"); // espacamento

    //processamento 

    if(nota == 10){
        printf("Conceito A");
    }else if ( nota >= 8 ){
         printf("Conceito B");
    }else if ( nota >= 6 ){
         printf("Conceito C");
    }else if ( nota >= 3  ){
         printf("Conceito D");
    }else{
        printf("Conceito E");
    }
    
}
