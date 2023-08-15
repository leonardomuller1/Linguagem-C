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
        if (opcao == 0 || opcao == 1){
            break;
        }else{
            printf("Opcao invalida. Digite 0 ou 1: ");
        }
    }
    return opcao;
}

int ValidacaoIdade()
{
    int idade;
    while (1)
    {
        scanf("%d", &idade);
        if (idade > 0 && idade < 150){
            break;
        }else{
            printf("Idade invalida. Digite novamente: ");
        }
    }
    return idade;
}

void ValidacaoGenero(char *genero)
{
    while (1)
    {
        scanf(" %c", genero);

        if (*genero == 'M'){
            strcpy(genero, "Masculino");
            break;
        }else if (*genero == 'F'){
            strcpy(genero, "Feminino");
            break;
        }else if (*genero == 'O'){
            strcpy(genero, "Outros");
            break;
        }else{
            printf("Genero invalido. Digite novamente: ");
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

const char *opcaoString(int opcao)
{
    return opcao == 1 ? "Sim" : "Nao";
}

void exibicaoPessoa(struct Pessoa *pessoa)
{
    printf("Nome: %s\n", pessoa->nome);
    printf("Idade: %d\n", pessoa->idade);
    printf("Cidade: %s\n", pessoa->cidade);
    printf("Genero: %s\n", pessoa->genero);

    printf("Hobbies:\n");
    printf("Musica: %s\n", opcaoString(pessoa->hobbies.musica));
    printf("Leitura: %s\n", opcaoString(pessoa->hobbies.leitura));
    printf("Esportes: %s\n", opcaoString(pessoa->hobbies.esportes));
    printf("Cozinhar: %s\n", opcaoString(pessoa->hobbies.cozinhar));

    printf("Local:\n");
    printf("Viajar: %s\n", opcaoString(pessoa->local.viajar));
    printf("Ficar em casa: %s\n", opcaoString(pessoa->local.ficarEmCasa));
    printf("Praia: %s\n", opcaoString(pessoa->local.praia));

    printf("Filmes:\n");
    printf("Acao: %s\n", opcaoString(pessoa->filmes.acao));
    printf("Aventura: %s\n", opcaoString(pessoa->filmes.aventura));
    printf("Comedia: %s\n", opcaoString(pessoa->filmes.comedia));
    printf("Drama: %s\n", opcaoString(pessoa->filmes.drama));
    printf("Terror: %s\n", opcaoString(pessoa->filmes.terror));
    printf("Trash: %s\n\n\n", opcaoString(pessoa->filmes.trash));
}

void listarUsuarios()
{
    int menu;
    int genero;
    char linha[500];
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo para leitura.\n");
        fclose(arquivo);
    }
        printf("\nSub-menu:\n");
        printf("1. Listar Todos Os Usuarios\n");
        printf("2. Filtrar por genero masculino\n");
        printf("3. Filtrar por genero feminino\n");
        printf("4. Filtrar por genero outros\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &menu);

        switch (menu)
        {
        case 1: // Listar Todos Os Usuarios
            printf("Listando todos os usuarios:\n");
            struct Pessoa pessoa;
            while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
            {
                exibicaoPessoa(&pessoa);
            }
            fclose(arquivo);
            break;
        case 2: // Filtro por genero masculino
            printf("\nFiltrando por genero Masculino:\n");
            while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
            {
                if (strcmp(pessoa.genero, "Masculino") == 0)
                {
                    exibicaoPessoa(&pessoa);
                }
            }
            fclose(arquivo);
            break;
        case 3:
            printf("\nFiltrando por genero Feminino:\n");
            while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
            {
                if (strcmp(pessoa.genero, "Feminino") == 0)
                {
                    exibicaoPessoa(&pessoa);
                }
            }
            fclose(arquivo);
            break;
        case 4:
            printf("\nFiltrando por genero Outros:\n");
            while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
            {
                if (strcmp(pessoa.genero, "Outros") == 0)
                {
                    exibicaoPessoa(&pessoa);
                }
            }
            fclose(arquivo);
            break;
        case 0:
            break;
        default:
            printf("Erro, opcao invalida");
            break;
        }
}

float analiseCompatibilidade(struct Pessoa pessoa1, struct Pessoa pessoa2) {
    int totalInteresses = 0;
    int interessesComuns = 0;

    // Hobbies
    if (pessoa1.hobbies.musica == pessoa2.hobbies.musica) {
        interessesComuns++;
    }
    if (pessoa1.hobbies.leitura == pessoa2.hobbies.leitura) {
        interessesComuns++;
    }
    if (pessoa1.hobbies.esportes == pessoa2.hobbies.esportes) {
        interessesComuns = interessesComuns + 15;
    }
    if (pessoa1.hobbies.cozinhar == pessoa2.hobbies.cozinhar) {
        interessesComuns++;
    }
    totalInteresses += 18;

    // Locais
    if (pessoa1.local.viajar == pessoa2.local.viajar) {
        interessesComuns++;
    }
    if (pessoa1.local.ficarEmCasa == pessoa2.local.ficarEmCasa) {
        interessesComuns++;
    }
    if (pessoa1.local.praia == pessoa2.local.praia) {
        interessesComuns++;
    }
    totalInteresses += 3;

    // Filmes
    if (pessoa1.filmes.acao == pessoa2.filmes.acao) {
        interessesComuns++;
    }
    if (pessoa1.filmes.aventura == pessoa2.filmes.aventura) {
        interessesComuns++;
    }
    if (pessoa1.filmes.comedia == pessoa2.filmes.comedia) {
        interessesComuns++;
    }
    if (pessoa1.filmes.drama == pessoa2.filmes.drama) {
        interessesComuns++;
    }
    if (pessoa1.filmes.terror == pessoa2.filmes.terror) {
        interessesComuns++;
    }
    if (pessoa1.filmes.trash == pessoa2.filmes.trash) {
        interessesComuns++;
    }
    totalInteresses += 6;

    // Calcular e retornar a porcentagem de compatibilidade
    return (float)interessesComuns / totalInteresses * 100;
}

void compararUsuarios(struct Pessoa pessoas[], int numPessoas) {
    for (int i = 0; i < numPessoas; i++) {
        for (int j = i + 1; j < numPessoas; j++) {
            float compatibilidade = analiseCompatibilidade(pessoas[i], pessoas[j]);
            printf("Compatibilidade entre %s e %s: %.2f%%\n", pessoas[i].nome, pessoas[j].nome, compatibilidade);
        }
    }
}


int main()
{
    int menu;
    int numPessoas;
    struct Pessoa *pessoas = NULL;
    while(1)
    {
        printf("\nMenu:\n");
        printf("1. Adicionar Usuarios\n");
        printf("2. Listar Usuarios\n");
        printf("3. Analise a compatibilidade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            printf("Quantas pessoas deseja adicionar? ");
            scanf("%d", &numPessoas);

            pessoas = (struct Pessoa *)malloc(numPessoas * sizeof(struct Pessoa));

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
                    fwrite(&pessoas[i], sizeof(struct Pessoa), 1, arquivo);
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
        case 3: // Analise a compatibilidade
            arquivo = fopen("dados.txt", "r");
            if (arquivo == NULL) {
                printf("Não foi possível abrir o arquivo para leitura.\n");
                return 1;
            }

            // Conta o número de pessoas no arquivo
            numPessoas = 0;
            struct Pessoa pessoa;  // Estrutura temporária para ler os dados do arquivo
            while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1) {
                numPessoas++;
            }

            // Alocar espaço para o array de pessoas
            pessoas = (struct Pessoa *)malloc(numPessoas * sizeof(struct Pessoa));
            if (pessoas == NULL) {
                printf("Erro ao alocar memória.\n");
                fclose(arquivo); // Fecha o arquivo se ocorrer erro na alocação de memória
                return 1;
            }

            // Reinicia o arquivo e lê os dados no array de pessoas
            rewind(arquivo);
            int i = 0;
            while (fread(&pessoas[i], sizeof(struct Pessoa), 1, arquivo) == 1) {
                i++;
            }
            fclose(arquivo);

            // Chama a função para comparar todas as pessoas
            compararUsuarios(pessoas, numPessoas);
            break;

        case 0:
            return 0;
        default:
            printf("Erro, opcao invalida");
            return 0;
        }
    }
}
