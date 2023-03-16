/******************************************************************************

Escreva um programa que receba dia, mês e ano para dois structs do tipo dma, cada um
representando uma data válida. Calcule e escreva o número de dias que decorreram
entre as duas datas.
Obs: considerar todas as possibilidades de datas.
struct dma
{
int dia;
int mes;
int ano;
};

*******************************************************************************/

#include <stdio.h>
#include <string.h>
#include <locale.h>

struct dma
{
    int dia;
    int mes;
    int ano;
} dataInicial, dataFinal;

// funções

/*
função para retornar o numero de dias no mes, com anos bissextos
*/
    int DiasNoMes(int mes, int ano) {
        int dias;
        if(mes == 2){
            int controle = 0;
            controle = ano % 4 == 0 && (ano % 100 != 0 || ano % 400 == 0);
            if(controle == 1){
                dias = 29;
            }else{
                dias = 28;
            }
        }if( mes == 1 || mes == 3|| mes == 5|| mes == 7|| mes == 9 || mes == 11){
            dias = 31;
        }else{
            dias = 30;
        }

        return dias;
    }


/*
função numero de dias que passaram no ano
*/

    int DiasCorridosNoAno(struct dma data) {
        int dias = 0;
        int i;

        for (i = 1; i < data.mes; i++) {
            dias = DiasNoMes(i, data.ano) + dias;
        }

        dias = data.dia + dias;

        return dias;
    }


int main()
{
    setlocale(LC_ALL, "Portuguese");

    // entrada dos dados
    printf("Data Inicial: dd mm aaaa\n");
    while (1)
    {
        scanf("%d %d %d", &dataInicial.dia, &dataInicial.mes, &dataInicial.ano);
        if (dataInicial.dia < 1 || dataInicial.dia > 31 || dataInicial.mes < 1 || dataInicial.mes > 12)
        {
            printf("Data invalida,digite novamente.\n");
            printf("Data Inicial: dd mm aaaa: \n");
        }
        else
        {
            break;
        }
    }

    printf("Data Final: dd mm aaaa\n");
    while (1)
    {
        scanf("%d %d %d", &dataFinal.dia, &dataFinal.mes, &dataFinal.ano);
        if (dataFinal.dia < 1 || dataFinal.dia > 31 || dataFinal.mes < 1 || dataFinal.mes > 12)
        {
            printf("Data invalida,digite novamente.\n");
            printf("Data Final: dd mm aaaa: \n");
        }
        else
        {
            break;
        }
    }

    // processamento
    int diasTotais = 0;

    if(dataInicial.ano == dataFinal.ano){
        diasTotais = DiasCorridosNoAno(dataInicial) - DiasCorridosNoAno(dataInicial);
    }  else{
        int i;

        //soma dos dias restante do primeiro ano
        diasTotais = diasTotais + DiasNoMes(dataInicial.mes, dataInicial.ano) - dataInicial.dia;

        // soma os dias dos anos inteiros entre as datas
        for (i = dataInicial.ano + 1; dataFinal.ano > i; i++){
            int x = (i % 4 == 0 && (i % 100 != 0 || i % 400 == 0));
                if (x == 1)
                {
                    x = 29;
                }
                else
                {
                    x = 28;
                }
            diasTotais = diasTotais + x;
        }

        // soma os dias do último ano
        for (i = 1; dataFinal.mes > i; i++){
            diasTotais = diasTotais + DiasNoMes(i, dataFinal.ano);
        }
    }

        if (dataInicial.ano == dataFinal.ano) {
        diasTotais = DiasCorridosNoAno(dataFinal) - DiasCorridosNoAno(dataInicial);
        } else {
            int i;

            // soma os dias restantes do primeiro ano
            diasTotais = (DiasNoMes(dataInicial.mes, dataInicial.ano) - dataInicial.dia) + diasTotais;
            for (i = dataInicial.mes + 1; i <= 12; i++) {
                diasTotais = DiasNoMes(i, dataInicial.ano) + diasTotais;
            }

            // soma os dias de anos inteiros entre as datas
            for (i = dataInicial.ano + 1; i < dataFinal.ano; i++) {
                int controle = 0;
                controle = i % 4 == 0 && (i % 100 != 0 || i % 400 == 0);
                if(controle == 1 ){
                    diasTotais = diasTotais + 366;
                }else{
                    diasTotais = diasTotais + 365;
                }
            }

            // soma os dias do último ano
            for (i = 1; i < dataFinal.mes; i++) {
                diasTotais = DiasNoMes(i, dataFinal.ano) + diasTotais;
            }
            diasTotais = dataFinal.dia + diasTotais;
        }


    printf("Diferenca em dias: %d\n", diasTotais);

    return 0;
}
