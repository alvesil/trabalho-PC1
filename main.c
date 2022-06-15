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

void cadastrar_pessoa(Pessoa pessoas [20])
{
    int i;
    printf("digite 0 se for professor ou 1 se for aluno: ");
    scanf("%i", &i );
    while(i != 0 || i != 1)
    {
        //Cadastrar de aluno
        if(i == 0){
            clr();
            printf("Digite 0 se dor Brasileiro e 1 se for estrangeiro: ");
            scanf("%i", &i);

            while( i != 0 || i != 1){
                //Aluno Brasileiro
                if(i==0){
                    printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                    scanf("%i", &i);
                    while(i !=0 || i != 0){
                        //Aluno PcD
                        if(i == 0){
                            //pedir os dados que faltam
                        }
                        //Aluno não PcD
                        else if(i == 1){
                            //pedir os dados que faltam
                        }
                        // Opção de aluno PcD invalida
                        else{
                            clr();
                            printf("\nOpcao nao valida\n");            
                            printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                            scanf("%i", &i );

                        }
                    }

                }
                //Aluno Extrangeiro
                else if(i==1){
                    printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                    scanf("%i", &i);
                    while(i !=0 || i != 0){
                      //Aluno PcD
                        if(i == 0){
                            //pedir os dados que faltam
                        }
                        //Aluno não PcD
                        else if(i == 1){
                            //pedir os dados que faltam
                        }
                        // Opção de aluno PcD invalida
                        else{
                            clr();
                            printf("\nOpcao nao valida\n");            
                            printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                            scanf("%i", &i );

                        }
                    }
                }
                //Opção errada
                else{
                    clr();
                    printf("\nOpcao nao valida\n");            
                    printf("\nDigite 0 se dor Brasileiro e 1 se for estrangeiro: ");
                    scanf("%i", &i );

                }
            }
        }
        else if(i == 1){
            //Cadastro de professor
            clr();
            printf("Digite 0 se dor Brasileiro e 1 se for estrangeiro");
            scanf("%i", &i);
            while( i != 0 || i != 1){
                //Professor Brasileiro
                if(i==0){
                    printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                    scanf("%i", &i);
                    while(i !=0 || i != 0){
                        //Professor PcD
                        if(i == 0){
                            //pedir os dados que faltam
                        }
                        //Professor não PcD
                        else if(i == 1){
                            //pedir os dados que faltam
                        }
                        // Opção de professor PcD invalida
                        else{
                            clr();
                            printf("\nOpcao nao valida\n");            
                            printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                            scanf("%i", &i );

                        }
                    }

                }
                //Professor Extrangeiro
                else if(i==1){
                    printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                    scanf("%i", &i);
                    while(i !=0 || i != 0){
                      //Professor PcD
                        if(i == 0){
                            //pedir os dados que faltam
                        }
                        //Professor não PcD
                        else if(i == 1){
                            //pedir os dados que faltam
                        }
                        // Opção de professor PcD invalida
                        else{
                            clr();
                            printf("\nOpcao nao valida\n");            
                            printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                            scanf("%i", &i );

                        }
                    }
                }
                //Opção professor nacionalidade errada
                else{
                    clr();
                    printf("\nOpcao nao valida\n");            
                    printf("\nDigite 0 se dor Brasileiro e 1 se for estrangeiro: ");
                    scanf("%i", &i );

                }
            }
        }
        else{
            //Opção aluno ou Professor errada
            clr();
            printf("\nOpcao nao valida\n");            
            printf("\ndigite 0 se for professor ou 1 se for aluno: ");
            scanf("%i", &i );
        }
    }
}

void cadastrar_disciplina(char dados[50])
{
   // printf("Processa os dados aqui");
}

void main()
{
    int opcaoInicial, opcaoPessoa, opcaoDisciplina;
    Pessoa pessoas[20];

    while (opcaoInicial != 3)
    {
        printf("1 - Sistema de Pessoas\n");
        printf("2 - Sistema de Disciplinas\n");
        printf("3 - Sair do Sistema\n\n");
        scanf("%d", &opcaoInicial);

        if (opcaoInicial == 1 || opcaoInicial == 2 || opcaoInicial == 3)
        {
            switch (opcaoInicial)
            {
            case 1:
                clr();
                printf("---------PESSOAS-----------\n");
                printf("1 - Cadastrar Pessoas\n");
                printf("2 - Exibir Dados de uma Pessoa\n");
                printf("3 - Alterar Dados de uma Pessoa\n");
                printf("4 - Remover Pessoa\n");
                printf("5 - Voltar ao Menu Princiapl\n\n");
                scanf("%d", &opcaoPessoa);
                if (opcaoPessoa == 1 || opcaoPessoa == 2 || opcaoPessoa == 3 || opcaoPessoa == 4 || opcaoPessoa == 5)
                {

                    if (opcaoPessoa == 1)
                    {
                        clr();
                        cadastrar_pessoa(pessoas);
                    }
                    if (opcaoPessoa == 5)
                    {
                        opcaoInicial = 0;
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
                scanf("%d", &opcaoDisciplina);
                if (opcaoDisciplina == 1 || opcaoDisciplina == 2 || opcaoDisciplina == 3 || opcaoDisciplina == 4 || opcaoDisciplina == 5)
                {
                    if (opcaoDisciplina == 1)
                    {
                        clr();
                        char opD1[50];
                        printf("Insira os dados separados por ';': ");
                        scanf("%s", opD1);
                        getchar();
                        cadastrar_disciplina(opD1);
                    }
                    if (opcaoDisciplina == 5)
                    {
                        opcaoInicial = 0;
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