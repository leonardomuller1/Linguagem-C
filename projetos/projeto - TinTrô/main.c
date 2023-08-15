#include <stdio.h>
#include <string.h>
#include <stdbool.h>

struct Hobbies
{
    int musica;
    int leitura;
    int esportes;
    int cozinhar;
};

struct Local
{
    int viajar;
    int ficarEmCasa;
    int praia;
};

struct Filmes
{
    int acao;
    int aventura;
    int comedia;
    int drama;
    int terror;
    int trash;
};

struct Pessoa
{
    char nome[100];
    int idade;
    char cidade[100];
    char genero[20];
    char fone[20];
    struct Hobbies hobbies;
    struct Local local;
    struct Filmes filmes;
};

int obterOpcao()
{
    int opcao;
    while (1)
    {
        scanf("%d", &opcao);
        if (opcao == 0 || opcao == 1)
        {
            break;
        }
        else
        {
            printf("Opcao invalida. Digite 0 ou 1: ");
        }
    }
    return opcao;
}

const char *opcaoString(int opcao)
{
    return opcao == 1 ? "Sim" : "Nao";
}

int ValidacaoIdade(){
    int idade;
    while (1)
    {
        scanf("%d", &idade);
        if (idade > 0 && idade < 150)
        {
            break;
        }
        else
        {
            printf("Idade invalida. Digite novamente: ");
        }
    }
    return idade;
}

void ValidacaoGenero(char *genero) {
    while (1) {
        scanf(" %c", genero);

        if (*genero == 'M') {
            strcpy(genero, "Masculino");
            break;
        } else if (*genero == 'F') {
            strcpy(genero, "Feminino");
            break;
        } else if (*genero == 'O') {
            strcpy(genero, "Outros");
            break;
        } else {
            printf("Genero inválido. Digite novamente: ");
        }
    }
}

void preencherDados(struct Pessoa *pessoa)
{
    printf("Nome: ");
    getchar();
    fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
    pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0';

    printf("Idade: ");
    pessoa->idade = ValidacaoIdade();

    printf("Cidade: ");
    getchar();
    fgets(pessoa->cidade, sizeof(pessoa->cidade), stdin);
    pessoa->cidade[strcspn(pessoa->cidade, "\n")] = '\0';

    printf("Genero: (M/F/O)");
    ValidacaoGenero(pessoa->genero);
    getchar();

    printf("Fone: ");
    fgets(pessoa->fone, sizeof(pessoa->fone), stdin);
    pessoa->fone[strcspn(pessoa->fone, "\n")] = '\0';

    printf("Hobbies:\n");
    printf("Musica (1/0): ");
    pessoa->hobbies.musica = obterOpcao();
    printf("Leitura (1/0): ");
    pessoa->hobbies.leitura = obterOpcao();
    printf("Esportes (1/0): ");
    pessoa->hobbies.esportes = obterOpcao();
    printf("Cozinhar (1/0): ");
    pessoa->hobbies.cozinhar = obterOpcao();

    printf("Local:\n");
    printf("Viajar (1/0): ");
    pessoa->local.viajar = obterOpcao();
    printf("Ficar em casa (1/0): ");
    pessoa->local.ficarEmCasa = obterOpcao();
    printf("Praia (1/0): ");
    pessoa->local.praia = obterOpcao();

    printf("Filmes:\n");
    printf("Acao (1/0): ");
    pessoa->filmes.acao = obterOpcao();
    printf("Aventura (1/0): ");
    pessoa->filmes.aventura = obterOpcao();
    printf("Comedia (1/0): ");
    pessoa->filmes.comedia = obterOpcao();
    printf("Drama (1/0): ");
    pessoa->filmes.drama = obterOpcao();
    printf("Terror (1/0): ");
    pessoa->filmes.terror = obterOpcao();
    printf("Trash (1/0): ");
    pessoa->filmes.trash = obterOpcao();
}

void listarUsuarios()
{
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo != NULL)
    {
        char linha[500];
        while (fgets(linha, sizeof(linha), arquivo) != NULL)
        {
            printf("%s", linha);
        }
        fclose(arquivo);
    }
    else
    {
        printf("Não foi possível abrir o arquivo para leitura.\n");
    }
}

int main()
{
    int menu;
    int numPessoas;
while(1){
    printf("\nMenu:\n");
    printf("1. Adicionar Usuarios\n");
    printf("2. Listar Usuarios\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &menu);

    switch (menu)
    {
    case 1:
        printf("Quantas pessoas deseja adicionar? ");
        scanf("%d", &numPessoas);

        struct Pessoa *pessoas = (struct Pessoa *)malloc(numPessoas * sizeof(struct Pessoa));

        if (pessoas == NULL)
        {
            printf("Erro ao abrir o arquivo.\n");
            return 1;
        }

         for (int i = 0; i < numPessoas; i++)
        {
            preencherDados(&pessoas[i]);
        }

        FILE *arquivo = fopen("dados.txt", "a");
        if (arquivo != NULL)
        {
            for (int i = 0; i < numPessoas; i++)
            {
                fprintf(arquivo, "Nome: %s\n", pessoas[i].nome);
                fprintf(arquivo, "Idade: %d\n", pessoas[i].idade);
                fprintf(arquivo, "Cidade: %s\n", pessoas[i].cidade);
                fprintf(arquivo, "Genero: %s\n", pessoas[i].genero);
                fprintf(arquivo, "Fone: %s\n", pessoas[i].fone);
                fprintf(arquivo, "Hobbies: Musica: %s, Leitura: %s, Esportes: %s, Cozinhar: %s\n",
                        opcaoString(pessoas[i].hobbies.musica), opcaoString(pessoas[i].hobbies.leitura),
                        opcaoString(pessoas[i].hobbies.esportes), opcaoString(pessoas[i].hobbies.cozinhar));
                fprintf(arquivo, "Local: Viajar: %s, Ficar em casa: %s, Praia: %s\n",
                        opcaoString(pessoas[i].local.viajar), opcaoString(pessoas[i].local.ficarEmCasa),
                        opcaoString(pessoas[i].local.praia));
                fprintf(arquivo, "Filmes: Acao: %s, Aventura: %s, Comedia: %s, Drama: %s, Terror: %s, Trash: %s\n",
                        opcaoString(pessoas[i].filmes.acao), opcaoString(pessoas[i].filmes.aventura),
                        opcaoString(pessoas[i].filmes.comedia), opcaoString(pessoas[i].filmes.drama),
                        opcaoString(pessoas[i].filmes.terror), opcaoString(pessoas[i].filmes.trash));
                fprintf(arquivo, "\n");
            }
            fclose(arquivo);
            printf("\nDados adicionados com sucesso ao arquivo 'dados.txt'.\n");
        }
        else
        {
            printf("\nNao foi possivel abrir o arquivo para salvar os dados.\n");
        }
        break;
    case 2:
        listarUsuarios();
        break;
    case 0:
        return 0;
    default:
        printf("Erro, opcao invalida");
        return 0;
    }
}
}
