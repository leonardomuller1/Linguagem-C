#include stdio.h
#include string.h
#include locale.h
struct pessoa{
    char nome[50];
    int turma;
    char telefone[16];
};

int main()
{
    setlocale(LC_ALL, Portuguese);

     invocação da struct
    struct pessoa p[10];

     input dados
    int i = 0;

    while (i10){

    puts(Digite o nome da pessoa );
    gets(p[i].nome);
    fflush(stdin);
    puts(Digite a turma da pessoa );
    scanf(%s, &p[i].turma);
    fflush(stdin);
    puts(Digite o telefone da pessoa );
    gets(p[i].telefone);
    fflush(stdin);

    i++;
    };


     exibicacao dos dados
    i = 0;
    printf(EXIBIÇÕES DOS DADOS n);
    while (i10){
    printf(INFORMAÇÕES PESSOA n);
    printf(Nome %sn, p[i].nome);
    printf(Turma %i n, p[i].turma);
    printf(Telefone %sn, p[i].telefone);
    i++;
    };

    return 0;
    
}
