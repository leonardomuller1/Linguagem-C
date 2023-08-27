#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <time.h>
#include <locale.h>
/*Structs*/
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
    int diaNascimento;
    int mesNascimento;
    int anoNascimento;
    char cidade[100];
    char genero[20];
    char fone[20];
    struct Hobbies hobbies;
    struct Local local;
    struct Filmes filmes;
};

/*Variaveis Globais*/
int numPessoas;
struct Pessoa *pessoas = NULL;
FILE *arquivo;

/* Protótipos de Funções */
void adicionarPessoa();
void preencherDados(struct Pessoa *pessoa);
int ValidacaoIdade(int opcao);
void ValidacaoGenero(char *genero);
int obterOpcao();
void listarPessoas();
void exibicaoPessoa(struct Pessoa *pessoa);
const char *opcaoString(int opcao);
int calcularIdade(int diaNascimento, int mesNascimento, int anoNascimento) ;
void compararPessoas();
float analiseCompatibilidade(struct Pessoa pessoa1, struct Pessoa pessoa2);
void asciiArtInicio();
void asciiArtFinal();

int main()
{
    setlocale(LC_ALL, "Portuguese");
    asciiArtInicio();
    int menu;
    while(1)
    {
        printf("\nMenu:\n");
        printf("1. Adicionar Pessoas\n");
        printf("2. Listar Pessoas\n");
        printf("3. Analise de compatibilidade\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");

        scanf("%d", &menu);

        switch (menu)
        {
        case 1:
            adicionarPessoa();
            break;

        case 2:
            listarPessoas();
            break;
        case 3:
            compararPessoas();
            break;
        case 0:
            asciiArtFinal();
            return 0;
        default:
            printf("Erro, opcao invalida");
            return 0;
        }
    }
}

/*--------FORMULARIO--------*/
void adicionarPessoa()
{
    printf("Quantas pessoas deseja adicionar? ");
    scanf("%d", &numPessoas);

    pessoas = (struct Pessoa *)malloc(numPessoas * sizeof(struct Pessoa));
    if (pessoas == NULL)
    {
        printf("Erro ao alocar memória.\n");
        return;
    }

    for (int i = 0; i < numPessoas; i++)
    {
        preencherDados(&pessoas[i]);
    }

    arquivo = fopen("dados.txt", "a");
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
}

void preencherDados(struct Pessoa *pessoa)
{
    printf("Nome: ");
    getchar();
    fgets(pessoa->nome, sizeof(pessoa->nome), stdin);
    pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0';

    printf("Idade: Dia: ");
    pessoa->diaNascimento = ValidacaoIdade(1);

    printf("Idade: Mes: ");
    pessoa->mesNascimento = ValidacaoIdade(2);

    printf("Idade: Ano: ");
    pessoa->anoNascimento = ValidacaoIdade(3);

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

//VALIDACOES
// VERIFICA A IDADE SE É VERDADEIRA
int ValidacaoIdade(int opcao)
{
    int data;
    while (1)
    {
        scanf("%d", &data);
        if(opcao == 1 && (data > 0 && data<=31 ))
        {
            break;
        }
        else if(opcao == 2 && (data > 0 && data<=12))
        {
            break;
        }
        else if(opcao == 3 && (data > 1900 && data<=2050))
        {
            break;
        }
        else
        {
            printf("Opcao invalida.Digite um valor valido: ");
        }
    }
    return data;
}

// VALIDA SE ESTA CORRETO O GENERO
void ValidacaoGenero(char *genero)
{
    while (1)
    {
        scanf(" %c", genero);

        if (*genero == 'M' || *genero == 'm')
        {
            strcpy(genero, "Masculino");
            break;
        }
        else if (*genero == 'F' || *genero == 'f')
        {
            strcpy(genero, "Feminino");
            break;
        }
        else if (*genero == 'O' || *genero == 'o')
        {
            strcpy(genero, "Outros");
            break;
        }
        else
        {
            printf("Genero invalido. Digite novamente: ");
        }
    }
}

// VERIFICA SE É 0 OU 1
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

/*--------LISTAGEM PESSOAS--------*/

void listarPessoas()
{
    int menu;
    int genero;
    int idade;
    char nome[500];
    char linha[500];
    FILE *arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Não foi possível abrir o arquivo para leitura.\n");
        fclose(arquivo);
    }
    printf("\nSub-menu:\n");
    printf("1. Listar todos as pessoas\n");
    printf("2. Filtrar por genero masculino\n");
    printf("3. Filtrar por genero feminino\n");
    printf("4. Filtrar por genero outros\n");
    printf("5. Filtrar por pessoa especifica\n");
    printf("6. Filtrar por idade\n");
    printf("7. Filtrar por hobby\n"); // Nova opção para filtrar por hobby
    printf("8. Filtrar por local\n"); // Nova opção para filtrar por local
    printf("9. Filtrar por genero de filme\n"); // Nova opção para filtrar por gênero de filme
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &menu);

    switch (menu)
    {
    case 1: // Listar Todos as Pessoas
        printf("Listando todos as pessoas:\n");
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
    case 5:
        printf("\nFiltrando por pessoa especifica:\n");
        printf("Nome: ");
        scanf("%s",nome);
        printf("\n");

        while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
        {
            if (strcmp(pessoa.nome, nome) == 0)
            {
                exibicaoPessoa(&pessoa);
            }
        }
        fclose(arquivo);
        break;
    case 6:
        printf("\nFiltrando por idade:\n");
        printf("Idade: ");
        scanf("%d", &idade);
        printf("\n");

        while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
        {
            if (calcularIdade(pessoa.diaNascimento, pessoa.mesNascimento, pessoa.anoNascimento) == idade)
            {
                exibicaoPessoa(&pessoa);
            }
        }
        fclose(arquivo);
        break;
    case 7: // Filtro por hobby
        printf("\nFiltrando por hobby:\n");
        int hobbyFiltro;
        printf("Escolha um hobby:\n");
        printf("1. Musica\n");
        printf("2. Leitura\n");
        printf("3. Esportes\n");
        printf("4. Cozinhar\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &hobbyFiltro);

        while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
        {
            int hobbySelecionado = 0;
            switch (hobbyFiltro)
            {
            case 1:
                hobbySelecionado = pessoa.hobbies.musica;
                break;
            case 2:
                hobbySelecionado = pessoa.hobbies.leitura;
                break;
            case 3:
                hobbySelecionado = pessoa.hobbies.esportes;
                break;
            case 4:
                hobbySelecionado = pessoa.hobbies.cozinhar;
                break;
            }

            if (hobbySelecionado == 1)
            {
                exibicaoPessoa(&pessoa);
            }
        }
        fclose(arquivo);
        break;

    case 8: // Filtro por local
        printf("\nFiltrando por local:\n");
        int localFiltro;
        printf("Escolha um local:\n");
        printf("1. Viajar\n");
        printf("2. Ficar em casa\n");
        printf("3. Praia\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &localFiltro);

        while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
        {
            int localSelecionado = 0;
            switch (localFiltro)
            {
            case 1:
                localSelecionado = pessoa.local.viajar;
                break;
            case 2:
                localSelecionado = pessoa.local.ficarEmCasa;
                break;
            case 3:
                localSelecionado = pessoa.local.praia;
                break;
            }

            if (localSelecionado == 1)
            {
                exibicaoPessoa(&pessoa);
            }
        }
        fclose(arquivo);
        break;

    case 9: // Filtro por gênero de filme
        printf("\nFiltrando por genero de filme:\n");
        int generoFilmeFiltro;
        printf("Escolha um genero de filme:\n");
        printf("1. Acao\n");
        printf("2. Aventura\n");
        printf("3. Comedia\n");
        printf("4. Drama\n");
        printf("5. Terror\n");
        printf("6. Trash\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &generoFilmeFiltro);

        while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
        {
            int generoFilmeSelecionado = 0;
            switch (generoFilmeFiltro)
            {
            case 1:
                generoFilmeSelecionado = pessoa.filmes.acao;
                break;
            case 2:
                generoFilmeSelecionado = pessoa.filmes.aventura;
                break;
            case 3:
                generoFilmeSelecionado = pessoa.filmes.comedia;
                break;
            case 4:
                generoFilmeSelecionado = pessoa.filmes.drama;
                break;
            case 5:
                generoFilmeSelecionado = pessoa.filmes.terror;
                break;
            case 6:
                generoFilmeSelecionado = pessoa.filmes.trash;
                break;
            }

            if (generoFilmeSelecionado == 1)
            {
                exibicaoPessoa(&pessoa);
            }
        }
    case 0:
        break;
    default:
        printf("Erro, opcao invalida");
        break;
    }
}

void exibicaoPessoa(struct Pessoa *pessoa)
{
    printf("Nome: %s\n", pessoa->nome);

    printf("Idade: %d\n", calcularIdade(pessoa->diaNascimento,pessoa->mesNascimento,pessoa->anoNascimento));
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

const char *opcaoString(int opcao)
{
    return opcao == 1 ? "Sim" : "Nao";
}

int calcularIdade(int diaNascimento, int mesNascimento, int anoNascimento)
{
    time_t t = time(NULL);
    struct tm tempo = *localtime(&t);

    int idade = tempo.tm_year + 1900 - anoNascimento;
    if (mesNascimento > tempo.tm_mon + 1 ||
            (mesNascimento == tempo.tm_mon + 1 && diaNascimento > tempo.tm_mday))
    {
        idade--;
    }

    return idade;
}

/*--------COMPATIBILIDADE--------*/

void compararPessoas()
{
    int idadeMinima, idadeMaxima;
    char generoDesejado[20];
    arquivo = fopen("dados.txt", "r");
    if (arquivo == NULL)
    {
        printf("Nao foi possivel abrir o arquivo para leitura.\n");
        return 1;
    }
    numPessoas = 0;
    struct Pessoa pessoa;
    while (fread(&pessoa, sizeof(struct Pessoa), 1, arquivo) == 1)
    {
        numPessoas++;
    }
    pessoas = (struct Pessoa *)malloc(numPessoas * sizeof(struct Pessoa));
    if (pessoas == NULL)
    {
        printf("Erro ao alocar memória.\n");
        fclose(arquivo);
        return 1;
    }

    rewind(arquivo);
    int i = 0;
    while (fread(&pessoas[i], sizeof(struct Pessoa), 1, arquivo) == 1)
    {
        i++;
    }
    fclose(arquivo);

    int submenu;
    printf("\nSubmenu - Analise a compatibilidade:\n");
    printf("1. Comparar todos as pessoas\n");
    printf("2. Exibir compatibilidade de pessoa especifica\n");
    printf("3. Exibir compatibilidade entre duas pessoas especificas\n");
    printf("3. Exibir entre duas idades\n");
    printf("3. Exibir compatibilidade entre genero especifico\n");
    printf("3. Exibir compatibilidade entre hobbies especifico\n");
    printf("0. Voltar ao menu principal\n");
    printf("Escolha uma opcao: ");

    scanf("%d", &submenu);

    switch (submenu)
    {
    case 1:
        for (int i = 0; i < numPessoas; i++)
        {
            for (int j = i + 1; j < numPessoas; j++)
            {
                float compatibilidade = analiseCompatibilidade(pessoas[i], pessoas[j]);
                printf("Compatibilidade entre %s e %s: %.2f%%\n", pessoas[i].nome, pessoas[j].nome, compatibilidade);
            }
        }
        break;
    case 2:
        printf("Digite o nome da pessoa para comparar: ");
        char nomePessoaComparar[100];
        getchar();  // Limpar o caractere de nova linha pendente no buffer
        fgets(nomePessoaComparar, sizeof(nomePessoaComparar), stdin);
        nomePessoaComparar[strcspn(nomePessoaComparar, "\n")] = '\0';

        struct Pessoa pessoaComparar;
        int encontrouPessoaComparar = 0;

        for (int i = 0; i < numPessoas; i++)
        {
            if (strcmp(pessoas[i].nome, nomePessoaComparar) == 0)
            {
                pessoaComparar = pessoas[i];
                encontrouPessoaComparar = 1;
                break;
            }
        }

        if (encontrouPessoaComparar)
        {
            for (int i = 0; i < numPessoas; i++)
            {
                if (strcmp(pessoas[i].nome, pessoaComparar.nome) != 0)
                {
                    float compatibilidade = analiseCompatibilidade(pessoaComparar, pessoas[i]);
                    printf("Compatibilidade entre %s e %s: %.2f%%\n",pessoaComparar.nome, pessoas[i].nome, compatibilidade);
                }
            }
        }
        else
        {
            printf("A pessoa especificada para comparar não foi encontrada.\n");
        }
        break;


    case 3:
        getchar();
        printf("Digite o nome da primeira pessoa: ");
        char nomePessoa1[100];
        fgets(nomePessoa1, sizeof(nomePessoa1), stdin);
        nomePessoa1[strcspn(nomePessoa1, "\n")] = '\0';

        printf("Digite o nome da segunda pessoa: ");
        char nomePessoa2[100];
        fgets(nomePessoa2, sizeof(nomePessoa2), stdin);
        nomePessoa2[strcspn(nomePessoa2, "\n")] = '\0';

        struct Pessoa pessoa1, pessoa2;
        int encontrouPessoa1 = 0, encontrouPessoa2 = 0;

        for (int i = 0; i < numPessoas; i++)
        {
            if (strcmp(pessoas[i].nome, nomePessoa1) == 0)
            {
                pessoa1 = pessoas[i];
                encontrouPessoa1 = 1;
                break;
            }
        }

        for (int i = 0; i < numPessoas; i++)
        {
            if (strcmp(pessoas[i].nome, nomePessoa2) == 0)
            {
                pessoa2 = pessoas[i];
                encontrouPessoa2 = 1;
                break;
            }
        }

        if (encontrouPessoa1 && encontrouPessoa2)
        {
            float compatibilidade = analiseCompatibilidade(pessoa1, pessoa2);
            printf("Compatibilidade entre %s e %s: %.2f%%\n", pessoa1.nome, pessoa2.nome, compatibilidade);
        }
        else
        {
            printf("Uma das pessoas especificadas não foi encontrada.\n");
        }
        break;

    case 4:
        printf("Digite a idade minima desejada: ");
        scanf("%d", &idadeMinima);
        printf("Digite a idade maxima desejada: ");
        scanf("%d", &idadeMaxima);

        for (int i = 0; i < numPessoas; i++)
        {
            for (int j = i + 1; j < numPessoas; j++)
            {
                if (calcularIdade(pessoas[i].diaNascimento,pessoas[i].mesNascimento,pessoas[i].anoNascimento) >= idadeMinima && calcularIdade(pessoas[i].diaNascimento,pessoas[i].mesNascimento,pessoas[i].anoNascimento) <= idadeMaxima &&
                        calcularIdade(pessoas[j].diaNascimento,pessoas[j].mesNascimento,pessoas[j].anoNascimento) >= idadeMinima && calcularIdade(pessoas[j].diaNascimento,pessoas[j].mesNascimento,pessoas[j].anoNascimento) <= idadeMaxima)
                {
                    float compatibilidade = analiseCompatibilidade(pessoas[i], pessoas[j]);
                    printf("Compatibilidade entre %s e %s: %.2f%%\n", pessoas[i].nome, pessoas[j].nome, compatibilidade);
                }
            }
        }
        break;

    case 5:
    printf("Escolha o genero desejado:\n");
    printf("M. Masculino\n");
    printf("F. Feminino\n");
    printf("O. Outros\n");
    getchar();
    scanf("%c", &generoDesejado);

    if (generoDesejado[0] == 'M' || generoDesejado[0] == 'm')
    {
        strcpy(generoDesejado, "Masculino");
    }
    else if (generoDesejado[0] == 'F' || generoDesejado[0] == 'f')
    {
        strcpy(generoDesejado, "Feminino");
    }
    else if (generoDesejado[0] == 'O' || generoDesejado[0] == 'o')
    {
        strcpy(generoDesejado, "Outros");
    }
    else
    {
        printf("Genero errado\n");
        break;
    }

    for (int i = 0; i < numPessoas; i++)
    {
        if (strcmp(pessoas[i].genero, generoDesejado) == 0)
        {
            for (int j = i + 1; j < numPessoas; j++)
            {
                if (strcmp(pessoas[j].genero, generoDesejado) == 0)
                {
                    float compatibilidade = analiseCompatibilidade(pessoas[i], pessoas[j]);
                    printf("Compatibilidade entre %s e %s: %.2f%%\n", pessoas[i].nome, pessoas[j].nome, compatibilidade);
                }
            }
        }
    }
    case 0:
        printf("Voltando ao menu principal.\n");
        return;

    default:
        printf("Opcao invalida.\n");
        break;
    }
}


float analiseCompatibilidade(struct Pessoa pessoa1, struct Pessoa pessoa2)
{
    int totalInteresses = 0;
    int interessesComuns = 0;

    // Hobbies
    int interessesHobbies = 0;
    if (pessoa1.hobbies.musica == pessoa2.hobbies.musica)
    {
        interessesHobbies++;
    }
    if (pessoa1.hobbies.leitura == pessoa2.hobbies.leitura)
    {
        interessesHobbies++;
    }
    if (pessoa1.hobbies.esportes == pessoa2.hobbies.esportes)
    {
        interessesHobbies++;
    }
    if (pessoa1.hobbies.cozinhar == pessoa2.hobbies.cozinhar)
    {
        interessesHobbies++;
    }

    if (interessesHobbies == 4)
    {
        interessesComuns += 32;
    }
    else if (interessesHobbies == 3)
    {
        interessesComuns += 16;
    }
    else if (interessesHobbies == 2)
    {
        interessesComuns += 8;
    }
    else if (interessesHobbies == 1)
    {
        interessesComuns += 4;
    }
    totalInteresses += 32;

    // Locais
    int interessesLocais = 0;
    if (pessoa1.local.viajar == pessoa2.local.viajar)
    {
        interessesLocais++;
    }
    if (pessoa1.local.ficarEmCasa == pessoa2.local.ficarEmCasa)
    {
        interessesLocais++;
    }
    if (pessoa1.local.praia == pessoa2.local.praia)
    {
        interessesLocais++;
    }

    if (interessesLocais == 3)
    {
        interessesComuns += 32;
    }
    else if (interessesLocais == 2)
    {
        interessesComuns += 16;
    }
    else if (interessesLocais == 1)
    {
        interessesComuns += 8;
    }
    totalInteresses += 32;

    // Filmes
    int interessesFilmes = 0;
    if (pessoa1.filmes.acao == pessoa2.filmes.acao)
    {
        interessesFilmes++;
    }
    if (pessoa1.filmes.aventura == pessoa2.filmes.aventura)
    {
        interessesFilmes++;
    }
    if (pessoa1.filmes.comedia == pessoa2.filmes.comedia)
    {
        interessesFilmes++;
    }
    if (pessoa1.filmes.drama == pessoa2.filmes.drama)
    {
        interessesFilmes++;
    }
    if (pessoa1.filmes.terror == pessoa2.filmes.terror)
    {
        interessesFilmes++;
    }
    if (pessoa1.filmes.trash == pessoa2.filmes.trash)
    {
        interessesFilmes++;
    }

    if (interessesFilmes  == 6)
    {
        interessesComuns += 32;
    }
    else if (interessesFilmes == 5)
    {
        interessesComuns += 16;
    }
    else if (interessesFilmes == 4)
    {
        interessesComuns += 8;
    }
    else if (interessesFilmes == 3)
    {
        interessesComuns += 4;
    }
    else if (interessesFilmes == 2)
    {
        interessesComuns += 2;
    }
    else if (interessesFilmes == 1)
    {
        interessesComuns += 1;
    }
    totalInteresses += 32;

    // Calcular a porcentagem de interesses comuns
    return (float)interessesComuns / totalInteresses * 100;
}


/*--------ASCII ART--------*/
void asciiArtInicio()
{
    printf(" /$$$$$$$$ /$$$$$$ /$$   /$$ /$$$$$$$$ /$$$$$$$   /$$$$$$ \n");
    printf("|__  $$__/|_  $$_/| $$$ | $$|__  $$__/| $$__  $$ /$$__  $$\n");
    printf("   | $$     | $$  | $$$$| $$   | $$   | $$  \\ $$| $$  \\ $$\n");
    printf("   | $$     | $$  | $$ $$ $$   | $$   | $$$$$$$/| $$  | $$\n");
    printf("   | $$     | $$  | $$  $$$$   | $$   | $$__  $$| $$  | $$\n");
    printf("   | $$     | $$  | $$\\  $$$   | $$   | $$  \\ $$| $$  | $$\n");
    printf("   | $$    /$$$$$$| $$ \\  $$   | $$   | $$  | $$|  $$$$$$/\n");
    printf("   |__/   |______/|__/  \\__/   |__/   |__/  |__/ \\______/ \n");
    printf("                                                          \n");
    printf("                                                          \n");
    printf("      ");
}

void asciiArtFinal()
{
    printf("               _,.---\"\"'\"''\"'\"\"`\"\"''`--..__\n");
    printf("            _.-'                                `-._\n");
    printf("          ,\"                                        `-._\n");
    printf("        ,'                                              `._\n");
    printf("      .'                                                   `-._\n");
    printf("    ,'         _                                               \".\n");
    printf("   /       . \"                                                   `.\n");
    printf("  /    . '      _ .                                                `.\n");
    printf(" .   .      . '                                                      `.\n");
    printf(" ' .'   . '            __   ,. . ..__                                  `.\n");
    printf("j .   .  .      _. --\" ___.......__ ` -._                               `\n");
    printf("|'  .' .'     .' _,.-\"\"'            `\"--._ `-._                           \\\n");
    printf(":  .  .   . .' ,'                         `\"._ `                           \\\n");
    printf("| .  /   . , .'                               `._`.                         \\\n");
    printf("|   .   ' . /                                    `. .                        .\n");
    printf(".      ' / /                                       `. .                       .\n");
    printf("|  '  . ' /;                                         . `. .                   |\n");
    printf("'  |  | |j ,                                          `. ` `.                 :\n");
    printf(" . '  | |:'  _.,..,._              _..,-.,.._         , \\  ` `                |\n");
    printf(" 'j   | |,  ._,.:,:;..\".         .:\".;..;.:. `,      . ,',\\   .`.              |\n");
    printf("  |   ' . ,'             `                   `\".     . : .   \\ `             '\n");
    printf("  '   . |'    _.....__    .        _....._      `.     ^. ,\\   . '\n");
    printf("   .    |     _,.--.._`.            _.--._`.     .     , .`.   \\ \\        /\n");
    printf("   |   j     \"..(_)___`.  '       .\"_(_)__`-.           ` : :.   . \\      /\n");
    printf("   '   :|                                               ,\" ; | __| `.    /\n");
    printf("    \\  ||              . '        ` .                    .' .\"'   `.|   .\n");
    printf("     \\.'|            ,' .             .                 , .'  ,`\"| |'  /\n");
    printf("      , .          '   /                .               . | .'   | |  /\n");
    printf("     . ,|        '   .'         '\".                  . ; \"| |.   | | /\n");
    printf("     '. '           :              .`            . ' . ` '| | `  | '.\n");
    printf("    , ' .`          `.._     _..__.' `        \" , \". ,  : '  `._.'.'\n");
    printf("     ; \"  ,'        .' ,`---' ; '.`.         , : ' ,  \"  '. \" ; ./\n");
    printf("      , '.  .      '. ': , \" .', :. ,`.     : .  \"  ; . `, ` . ,/\n");
    printf("      . ,  ; .   \". ;.-\"\"`-:.--'\"\"-._'.      . '  :  ' . .' \" ^.\n");
    printf("       . ` . '  ',.'                 `\".   ` ,  \"  . `, . .,'.,'\n");
    printf("     '  , . : .   :-----==========-----:   '. ^  ;  `. : ^ , '/\n");
    printf("      ;  .`  ,   ,`.                 _.'   ` . ' . \"  . ,` . ,\n");
    printf("    .  ,  ,'. ` ' , `\"-...-----...--' \" '. , ' \" . , ' . '. /\n");
    printf("      . \"  . , ; . \" ` . ,` '. \" . \". ^ ` .  .  ' `  . :' ;/\n");
    printf("     ' ` . ' , ` ; `  ' :  ` ' , : , . ,  ` .  `  . ^.          `\"-_\n");
    printf("       ' , : . '  `. '. , ^ . \" . . \" .  ` . , ^  ,  .'      `\".._\n");
    printf("        _.  ` :  ^  \" .   .  '  ,  , ' \" ,  ` .  `  . ^.          `\"-..\n");
    printf("    _.-\"  ; .  . ' ',  ' \"  ` `: .`  ,' . ' \"  , ' . , \\`.              `-_");
    printf("_.-\"     '  ` ; , , . . `  ' ;  . , . ^   . ^ :  . '  . \\ \\\\`.               \"._\n");
    printf("         ` . , \" .  `  .` \" . .  ` . , : ^  '   '  ; , ' \\ . `.\n");
    printf("            ' , ' .   .  \" , .                           |     \\.  \\\n");
    printf("             `\"'. ` :,`, \" '   '                          |     `-. \\\n");
    printf("              `..  . `  '   `                           |        ` \\\n");
    printf("              .  .  `.   .                              |          `.     mh\n");
}
