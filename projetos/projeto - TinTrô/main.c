#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct dados {
    char nome[100];
    char fone[30];
    int status;
    char data_nascimento[30];
    char genero[30];
};

void salvar_em_arquivo(struct dados usuarios[]) {
    FILE *file;
    int i;

    file = fopen("dados.txt", "a"); // abrindo o arquivo para adicao

    if (file == NULL) {
        printf("Erro ao abrir o arquivo!\n");
        return;
    }

    // Escreve os dados no arquivo
    for (i = 0; i < 100; i++) {
        if (usuarios[i].status == 1) {
            fprintf(file, "Nome: %s\n", usuarios[i].nome);
            fprintf(file, "Telefone: %s\n", usuarios[i].fone);
            fprintf(file, "Data nascimento: %s\n", usuarios[i].data_nascimento);
            fprintf(file, "Genero: %s\n", usuarios[i].genero);
            fprintf(file, "Status: %d\n", usuarios[i].status);
            fprintf(file, "\n"); // Separador entre os usuários
        }
    }

    fclose(file); // Fecha o arquivo
}

void carregar_arquivo(struct dados usuarios[]) {
    FILE *file;
    char linha[200];
    int i = 0;

    file = fopen("dados.txt", "r"); // Abre o arquivo para leitura

    if (file == NULL) {
        printf("Arquivo nao encontrado ou erro ao abrir!\n");
        return;
    }

    while (fgets(linha, sizeof(linha), file)) {
        sscanf(linha, "Nome: %[^\n]\n", usuarios[i].nome);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Telefone: %[^\n]\n", usuarios[i].fone);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Data nascimento: %[^\n]\n", usuarios[i].data_nascimento);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Genero: %[^\n]\n", usuarios[i].genero);
        fgets(linha, sizeof(linha), file);
        sscanf(linha, "Status: %d\n", &usuarios[i].status);
        fgets(linha, sizeof(linha), file); // linha do separador e descarta
        i++;
    }

    fclose(file); // Fecha o arquivo apos a leitura
}

void formulario_cadastro(struct dados usuarios[]) {
    int i;

    // Encontrar a posicao disponível no array
    for (i = 0; i < 100; i++) {
        if (usuarios[i].status == 0) {
            break;
        }
    }

    if (i == 100) {
        printf("O limite de usuários foi atingido.\n");
        return;
    }

    printf("Nome: ");
    scanf("%s", usuarios[i].nome);

    printf("Telefone: ");
    scanf("%s", usuarios[i].fone);

    printf("Data de nascimento: ");
    scanf("%s", usuarios[i].data_nascimento);

    printf("Genero (Masculino/Feminino/Outros): ");
    scanf("%s", usuarios[i].genero);

    // Formatacao de letras minusculas
    for (int j = 0; usuarios[i].genero[j]; j++) {
        usuarios[i].genero[j] = tolower(usuarios[i].genero[j]);
    }

    usuarios[i].status = 1; // Usuario ativo

    printf("Usuario cadastrado com sucesso!\n");

    // Salvar os dados atualizados no arquivo
    salvar_em_arquivo(usuarios);
}
int main() {
    struct dados usuarios[100];
    int funcao = 0;

    FILE *fp;

    while (1) {
        printf("Qual funcao voce quer?\n\tCadastro   \t1 \n\tLeitura  \t2\n\tDeletar  \t3\n\tEdicao  \t4\n\n");
        scanf("%i", &funcao);

        switch (funcao) {
            case 1:
                formulario_cadastro(usuarios);
                break;
            /*case 2:
                leitura(usuarios);
                break;
            case 3:
                deletar(usuarios);
                break;
            case 4:
                edicao(usuarios);
                break; */
            default:
                printf("Opcao invalida!\n");
                break;
        }

        // Terminar o programa
        int termina = 0;
        printf("\nVoce deseja encerrar o programa? Digite 1 para terminar: ");
        scanf("%i", &termina);
        if (termina == 1) {
            return 0;
        }
    }
}
