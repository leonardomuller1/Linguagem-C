/******************************************************************************

Para realizar este exercício, é imprescindível o conceito de struct, pois para cada
conjunto de dados digitados, uma struct será utilizada para armazenar os valores que,
posteriormente, serão consultados para gerar os resultados. Será realizada uma
pesquisa de algumas características físicas da população da região do Vale dos Sinos,
onde serão coletados os seguintes dados: idade, sexo(1=M e 2=F), cor dos olhos
(1=azuis, 2=verdes e 3=castanho) e cor do cabelo (1=louro, 2=castanho e 3=preto).
Fazer um programa em C que lê a idade, sexo, cor dos olhos e cabelo das pessoas que
serão pesquisadas e, para finalizar esta digitação, a idade deverá ser igual 0.
Exibir os seguintes resultados:
a) Total de pessoas pesquisadas;
b) Média de idade das pessoas pesquisadas;
c) Percentual de homens e mulheres;
d) Quantidade de mulheres com idade entre 20 e 30 anos que possuem olhos azuis
e cabelo louro;
e) Percentual de cabelos louros, castanhos e pretos;
f) Percentual de olhos azuis, verdes e castanhos.

*******************************************************************************/

#include <stdio.h>
#include <string.h>
int main()
{
    struct dados {
        int idade;
        int sexo;
        int corDoOlho;
        int corDoCabelo;
    };

    struct dados pessoa[30];


    int totalPessoas = 0, totalHomens = 0, totalMulheres = 0, totalAzul = 0, totalVerde = 0, totalCastanho = 0, totalLouro = 0, totalCabCastanho = 0, totalPreto = 0, totalIdade = 0, mulherOlhosAzuisCabelhosLouros = 0 ;
    float PorcentoPessoas = 0, PorcentoHomens = 0, PorcentoMulheres = 0, PorcentoAzul = 0, PorcentoVerde = 0, PorcentoCastanho = 0, PorcentoLouro = 0, PorcentoCabCastanho = 0, PorcentoPreto = 0, PorcentoIdade = 0;
    int numero_pessoas = 30;
    int terminar = 0;
    int filtroOlho = 0;
    int i = 0 ; // validador de terminar ou não
    //entradas dos dados
    for (i = 0; i < numero_pessoas; i++){
        printf("Idade: ");
        while (1){
            scanf("%i", &pessoa[i].idade);
            if( pessoa[i].idade == 0){ // caso a idade for 0, termina a captura de dados
                terminar = 1;
                break;
            }
            if (pessoa[i].idade < 0 ){
                printf("Valor errado digite novamente.\n");
            }else {
                break;
            }
        }
        if(terminar == 1){
            break;
        }
        printf("Sexo (1=M e 2=F) : ");
        while(1){
            scanf("%i", &pessoa[i].sexo);
            if (pessoa[i].sexo < 0 || pessoa[i].sexo > 2 ){
                printf("Valor errado digite novamente.\n");
            }else {
                break;
            }
        }
        printf("Cor dos olhos (1=azuis, 2=verdes e 3=castanho): ");
        while(1){
            scanf("%i", &pessoa[i].corDoOlho);
            if (pessoa[i].corDoOlho < 0 || pessoa[i].corDoOlho > 3 ){
                printf("Valor errado digite novamente.\n");
            }else {
                break;
            }
        }
        printf("cor do cabelo (1=louro, 2=castanho e 3=preto): ");
        while(1){
            scanf("%i", &pessoa[i].corDoCabelo);
            if (pessoa[i].corDoCabelo < 0 || pessoa[i].corDoCabelo > 3 ){
                printf("Valor errado digite novamente.\n");
            }else {
                break;
            }
        }

        // parte de processamento dos dados
            // total de pessoas
        totalPessoas = totalPessoas + 1;
            //total idade

        totalIdade = pessoa[i].idade + totalIdade;
            // sexo
        if(pessoa[i].sexo == 1){
            totalHomens = totalHomens + 1;
        }else{
            totalMulheres = totalMulheres + 1;
        }

            // corDoOlho
        if(pessoa[i].corDoOlho == 1){
            totalAzul = totalAzul + 1;
        }else if(pessoa[i].corDoOlho == 2){
            totalVerde = totalVerde + 1;
        }else {
            totalCastanho = totalCastanho + 1;
        };

            //corDoCabelo
        if(pessoa[i].corDoCabelo == 1){
            totalLouro = totalLouro + 1;
        }else if(pessoa[i].corDoCabelo == 2){
            totalCabCastanho = totalCabCastanho+ 1;
        }else {
            totalPreto = totalPreto + 1;
        };

      // mulheres com idade entre 20 e 30 anos que possuem olhos azuis e cabelo louro
        if(pessoa[i].sexo == 2  && pessoa[i].corDoOlho == 1 && pessoa[i].corDoCabelo == 1){
            if(pessoa[i].idade >= 20 && pessoa[i].idade <= 30){
                mulherOlhosAzuisCabelhosLouros = mulherOlhosAzuisCabelhosLouros + 1;
            }
        }
    };
    // processamento das medias
        // idade
        PorcentoIdade =  (float) totalIdade / totalPessoas;

        //Percentual de homens e mulheres
        PorcentoHomens = 100 *(float) totalHomens / totalPessoas; // multiplicado por 100 para colocar em %
        PorcentoMulheres =100 * (float) totalMulheres / totalPessoas; // multiplicado por 100 para colocar em %

        //Percentual de cabelos louros, castanhos e pretos
        PorcentoLouro = 100 *(float) totalLouro / totalPessoas; // multiplicado por 100 para colocar em %
        PorcentoCabCastanho = 100 *(float) totalCabCastanho / totalPessoas; // multiplicado por 100 para colocar em %
        PorcentoPreto = 100 *(float) totalPreto / totalPessoas; // multiplicado por 100 para colocar em %

        //Percentual de olhos azuis, verdes e castanhos
        PorcentoAzul = 100 *(float) totalAzul / totalPessoas; // multiplicado por 100 para colocar em %
        PorcentoVerde = 100 *(float) totalVerde / totalPessoas; // multiplicado por 100 para colocar em %
        PorcentoCastanho = 100 *(float) totalCastanho / totalPessoas; // multiplicado por 100 para colocar em %


    // exibição dos resultados
     while(1){
            printf("Cor dos olhos (1=azuis, 2=verdes e 3=castanho): ");
            scanf("%i", &filtroOlho);
            if (filtroOlho < 0 || filtroOlho > 3 ){
                printf("Valor errado digite novamente.\n");
            }else {
                break;
            }
        }

    if(filtroOlho == 1 ){
        for (i = 0; i < numero_pessoas; i++){
            if(pessoa[i].corDoOlho == 1){
                printf("\nPessoa entrevistada %i\n", i);
                printf("\nIdade :%i",pessoa[i].idade);
                printf("\nSexo : %i",pessoa[i].sexo);
                printf("\nCor do Olho: %i",pessoa[i].corDoOlho);
                printf("\nCor do cabelho: %i",pessoa[i].corDoCabelo);
            }
        }
    }else if(filtroOlho == 2){
        for (i = 0; i < numero_pessoas; i++){
            if(pessoa[i].corDoOlho == 2){
                printf("\nPessoa entrevistada %i\n", i);
                printf("\nIdade : %i",pessoa[i].idade);
                printf("\nSexo : %i",pessoa[i].sexo);
                printf("\nCor do Olho: %i",pessoa[i].corDoOlho);
                printf("\nCor do cabelho: %i",pessoa[i].corDoCabelo);
            }
        }
    }else{
        for (i = 0; i < numero_pessoas; i++){
            if(pessoa[i].corDoOlho == 2){
                printf("\nPessoa entrevistada %i\n", i);
                printf("\nIdade: %i",pessoa[i].idade);
                printf("\nSexo: %i",pessoa[i].sexo);
                printf("\nCor do Olho: %i",pessoa[i].corDoOlho);
                printf("\nCor do cabelho: %i",pessoa[i].corDoCabelo);
            }
        }
    }
    return 0;
}
