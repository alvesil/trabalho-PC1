#include <stdio.h>

typedef struct
{
    char nome[20];
    char sobrenome[50];
    int nacionalidade;
    char cpf[12];
    char rg[8];
    char passaporte[9];
    char paisOrigem[20];
    char dt_nasc[11];
    int pcd;
    char laudo[10];
    char cep[9];
    int proforaluno;
    long int matricula;

} Pessoa;

typedef struct
{
    long int codigo;
    char nome[20];
    int cargaHoraria;
    Pessoa professor;
    Pessoa aluno[10];

} Disciplina;

typedef struct
{
    Pessoa alunos[30];
    Pessoa professores[5];
    Disciplina disciplina[5];

} Escola;

void clr()
{
    printf("\ec\e[3J");
}

void cadastrar_pessoa(char dados[50])
{
    printf("Processa os dados aqui");
}

void cadastrar_disciplina(char dados[50])
{
    printf("Processa os dados aqui");
}

void main()
{
    int opInicial, opP, opD;
    while (opInicial != 3)
    {
        printf("1 - Sistema de Pessoas\n");
        printf("2 - Sistema de Disciplinas\n");
        printf("3 - Sair do Sistema\n\n");
        scanf("%d", &opInicial);

        if (opInicial == 1 || opInicial == 2 || opInicial == 3)
        {
            switch (opInicial)
            {
            case 1:
                clr();
                printf("---------PESSOAS-----------\n");
                printf("1 - Cadastrar Pessoas\n");
                printf("2 - Exibir Dados de uma Pessoa\n");
                printf("3 - Alterar Dados de uma Pessoa\n");
                printf("4 - Remover Pessoa\n");
                printf("5 - Voltar ao Menu Princiapl\n\n");
                scanf("%d", &opP);
                if (opP == 1 || opP == 2 || opP == 3 || opP == 4 || opP == 5)
                {

                    if (opP == 1)
                    {
                        clr();
                        char opP1[50];
                        printf("Insira os dados separados por ';': ");
                        scanf("%s", opP1);
                        getchar();
                        cadastrar_pessoa(opP1);
                    }
                    if (opP == 5)
                    {
                        opInicial = 0;
                        clr();
                    }
                }
                else
                {
                    printf("Opção inválida\n");
                }

            case 2:
                clr();
                printf("---------DISCIPLINAS-----------\n");
                printf("1 - Cadastrar Disciplina\n");
                printf("2 - Exibir Dados de uma Disciplina\n");
                printf("3 - Alterar Dados de uma Disciplina\n");
                printf("4 - Remover Disciplina\n");
                printf("5 - Voltar ao Menu Principal\n\n");
                scanf("%d", &opD);
                if (opD == 1 || opD == 2 || opD == 3 || opD == 4 || opD == 5)
                {
                    if (opD == 1)
                    {
                        clr();
                        char opD1[50];
                        printf("Insira os dados separados por ';': ");
                        scanf("%s", opD1);
                        getchar();
                        cadastrar_disciplina(opD1);
                    }
                    if (opD == 5)
                    {
                        opInicial = 0;
                        clr();
                    }
                }
                else
                {
                    printf("Opção inválida\n");
                }

            case 3:
                clr();
                printf("Voce saiu!\n");
            }
        }
        else
        {
            clr();
            printf("\nOpcao invalida!!!\n\n");
        }
    }
}