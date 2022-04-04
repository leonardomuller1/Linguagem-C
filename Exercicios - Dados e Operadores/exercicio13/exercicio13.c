/*
 * @brief  Calculadora de area de um cilindrico e custo da mao de obra para a pintura dele.
 * @author  Leonardo Muller
 *
 * @version 0.1
 * @date    abr/2022
*/

/*
Questao:
    Necessita-se pintar um tanque cilindrico, com tampa, por dentro e por fora, com exceçao da base do tanque que se apoia 
    sobre o solo. Com 1 litro de tinta, pinta-se 3 metros quadrados do tanque. A mao de obra é calculada ao custo de R$ 10,00 
    por metro quadrado. Fazer um programa que le a altura e o diametro do cilindro e informa quantos litros de tinta serão 
    necessários e qual será o custo de mao de obra.
*/

// Includes
#include <stdio.h>
#include <stdlib.h>

int main()
{
    //declaracao das variaveis
    float altura,raio,mao_de_obra,tinta,area;

    // entrada de dados
    printf("\nQual a altura do cilindro: ");
    scanf("%f",&altura);
    printf("\nQual o diametro do cilindro: ");
    scanf("%f",&raio);

    printf("\n"); // espacamento

    //processamento
    area = 2*3.1415*raio*(raio+altura);
    tinta = area/3;
    mao_de_obra = area*10.00;

    // exibicao dos resultados
    printf("\nValor da area do cilindro: %0.2f",area );
    printf("\nValor da mao de obra: R$ %0.2f",mao_de_obra );
    printf("\nQuantidade de litros de tinta necessario: %0.2f L",tinta );

}

