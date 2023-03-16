/******************************************************************************

Crie uma estrutura representando os alunos do curso de Elementos de Programação. A
estrutura deve conter a matrícula do aluno, nome, nota da primeira prova, nota da
segunda prova e nota da terceira prova.

a. Permita ao usuário entrar com os dados de até 20 alunos;
b. Exiba a matrícula, nome e nota do aluno com maior nota na primeira prova, na
segunda prova e na terceira prova;
c. Encontre e escreva o nome do aluno, sua notas e média para o aluno com maior
média geral;
d. Encontre e escreva o nome do aluno, sua notas e média para o aluno com menor
média geral;
e. Para cada aluno, escreva seu nome e média e informe se ele foi aprovado ou
reprovado, considerando média 6 para aprovação.

*******************************************************************************/

#include <stdio.h>
#include <string.h>

struct aluno
{
    int matricula;
    char nome[50];
    float nota1,nota2,nota3;
};

int main(){
    struct aluno alunos[20];

    printf("\t\tSISTEMA DE NOTAS\n\n");

    //variaveis para controle 
    int i = 0;
    int num_alunos = 20;
    
    //entrada de dados
    for (i = 0; i < num_alunos; i++) {
        printf("Digite os dados do aluno %d:\n", i+1);
        printf("Matricula: ");
        scanf("%d", &alunos[i].matricula);
        printf("Nome: ");
        scanf(" %[^\n]", alunos[i].nome);
        printf("Nota 1: ");
        scanf("%f", &alunos[i].nota1);
        printf("Nota 2: ");
        scanf("%f", &alunos[i].nota2);
        printf("Nota 3: ");
        scanf("%f", &alunos[i].nota3);
    }
    
    //processamento

    // encontra o aluno com a maior nota em cada prova

    float maiorNota1 = -1,maiorNota2 = -1,maiorNota3 = -1;
    int indiceMaiorNota1 = -1,indiceMaiorNota2 = -1,indiceMaiorNota3 = -1;

    for (i = 0; num_alunos > i;i++){
        if(alunos[i].nota1> maiorNota1){
            maiorNota1 = alunos[i].nota1;
            indiceMaiorNota1 = i;
        }

        if(alunos[i].nota2> maiorNota2){
            maiorNota2 = alunos[i].nota2;
            indiceMaiorNota2 = i;
        }

        if(alunos[i].nota3> maiorNota3){
            maiorNota3 = alunos[i].nota3;
            indiceMaiorNota3 = i;
        }
    }

    // exibe a matricla,nome e nota do aluno com a maior nota em cada prova
    printf("\n\n\t\tAluno com maior nota na primeira prova:\n");
    printf("Matricula: %d\n", alunos[indiceMaiorNota1].matricula);
    printf("Nome: %s\n", alunos[indiceMaiorNota1].nome);
    printf("nota 1: %.2f\n", alunos[indiceMaiorNota1].nota1);

    printf("\n\t\tAluno com maior nota na segunda prova:\n");
    printf("Matricula: %d\n", alunos[indiceMaiorNota2].matricula);
    printf("Nome: %s\n", alunos[indiceMaiorNota2].nome);
    printf("nota 2: %.2f\n", alunos[indiceMaiorNota2].nota2);

    printf("\n\t\tAluno com maior nota na terceria prova:\n");
    printf("Matricula: %d\n", alunos[indiceMaiorNota3].matricula);
    printf("Nome: %s\n", alunos[indiceMaiorNota3].nome);
    printf("nota 2: %.2f\n", alunos[indiceMaiorNota3].nota3);

     // encontra o aluno com a maior média geral
    float maiorMedia = -1, menorMedia = 11;
    int indiceMaiorMedia = -1, indiceMenorMedia = -1;

    for(i = 0; i< num_alunos; i++){
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

        if(media > maiorMedia){
            maiorMedia = media;
            indiceMaiorMedia = i;
        }

        if(media < menorMedia){
            menorMedia = media;
            indiceMenorMedia = i;
        }
    }

    //maior media
    printf("\n\n\t\tAluno com maior media geral:\n");
    printf("Nome: %s\n", alunos[indiceMaiorMedia].nome);
    printf("Matricula: %d\n", alunos[indiceMaiorMedia].matricula);
    printf("nota 1: %.2f\n", alunos[indiceMaiorMedia].nota1);
    printf("nota 2: %.2f\n", alunos[indiceMaiorMedia].nota2);
    printf("nota 3: %.2f\n", alunos[indiceMaiorMedia].nota3);
    printf("Media: %.2f\n", maiorMedia);

    //menor media
    printf("\n\n\t\tAluno com menor media geral:\n");
    printf("Nome: %s\n", alunos[indiceMenorMedia].nome);
    printf("Matricula: %d\n", alunos[indiceMenorMedia].matricula);
    printf("nota 1: %.2f\n", alunos[indiceMenorMedia].nota1);
    printf("nota 2: %.2f\n", alunos[indiceMenorMedia].nota2);
    printf("nota 3: %.2f\n", alunos[indiceMenorMedia].nota3);
    printf("Media: %.2f\n", menorMedia);

    //verifica se foi aprovado ou reprovado
    printf("\n\n\t\t Situação dos alunos:\n\n");

    for(i = 0; i< num_alunos; i++){
        float media = (alunos[i].nota1 + alunos[i].nota2 + alunos[i].nota3) / 3;

        printf("%s - Media : %.2f - ", alunos[i].nome, media);

        if(media > 6){
            printf("APROVADO\n");
        }else{
            printf("REPROVADO\n");
        }
    }
    return 0;
}