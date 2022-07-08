
int menuPrincipal, menuPessoa, menuDisciplina;
void menu_Pessoa();
void menu_Principal();
Escola escola;

void menu_Principal()
{
    menuDisciplina = 0;
    menuPrincipal = 0;
    menuPessoa = 0;
    while (menuPrincipal != 3)
    {
        // clr();
        printf("1 - Sistema de Pessoas\n");
        printf("2 - Sistema de Disciplina\n");
        printf("3 - Sair do Sistema\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &menuPrincipal);
        getchar();

        if (menuPrincipal == 0 || menuPrincipal == 1 || menuPrincipal == 2 || menuPrincipal == 3)
        {

            switch (menuPrincipal)
            {

            case 0:
                // zera as op��es
                menu_Principal();
                break;

            case 1:

                // Sistema de Pessoas
                menu_Pessoa();
                break;

            case 2:
                // sistema de Disciplina
                // menu_Disciplina();
                break;

            case 3:
                // Sair do Sistema
                exit(1);
                break;
            }
        }
        else
        {
            // clr();
            printf("\nopcao Invalida\n\n");
            // sleep(2);
        }
    }
}

void menu_Pessoa()
{
    menuDisciplina = 0;
    menuPrincipal = 0;
    menuPessoa = 0;
    int contador = 0;

    while (menuPessoa != 5)
    {
        // clr();
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Exibir dados de uma pessoa\n");
        printf("3 - Alterar dados da pessoa\n");
        printf("4 - Excluir pessoa\n");
        printf("5 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &menuPessoa);
        getchar();

        if (menuPessoa == 0 || menuPessoa == 1 || menuPessoa == 2 || menuPessoa == 3 || menuPessoa == 4 || menuPessoa == 5)
        {

            switch (menuPessoa)
            {
            case 0:

                // zera as opc�es
                menu_Pessoa();
                break;

            case 1:
                printf("\nDigite os dados a cadastrar separados por ';'.\n");
                if (cadastraPessoa(&escola, contador) == 1)
                {
                    printf("Aluno Cadastrado!\n");
                    // sleep(1);
                    contador++;
                }
                ////clr();

                break;

            case 2:
                // Exibir dados de uma pessoa
                ////clr();
                //printf("\nExibir\n");
                mostraPessoa(&escola, contador);
                // for (int i = 0; i < contador; i++)
                // {
                //     printf("Matrícula: ");
                //     printf("%d", escola.alunos[i].matricula);
                //     printf("\nAluno [%d]: \n", (i));
                //     printf("Nome: %s\n", escola.alunos[i].nome);
                //     printf("Sobrenome: %s\n", escola.alunos[i].sobrenome);
                //     printf("CPF: %s\n", escola.alunos[i].cpf);
                //     printf("RG: %s\n", escola.alunos[i].rg);
                //     printf("CEP: %s\n", escola.alunos[i].cep);
                //     printf("Data de Nascimento: %s\n", escola.alunos[i].dt_nasc);
                //     printf("\n");
                // }

                // sleep(1);
                break;

            case 3:
                // Alterar dados da pessoa
                ////clr();
                printf("\nExcluir");
                // sleep(2);
                break;

            case 4:
                // Excluir pessoa
                ////clr();
                printf("\nExcluir");
                // sleep(2);
                break;

            case 5:
                // Voltar ao menu principal
                menu_Principal();
                break;
            }
        }
        else
        {
            ////clr();
            printf("\nopcao Invalida\n\n");
            // sleep(2);
        }
    }
}

void menu_Disciplina()
{
    int opcaoInicial, opcaoPessoa, opcaoDisciplina;
    menuDisciplina = 0;
    menuPrincipal = 0;
    menuPessoa = 0;

    while (menuPessoa != 5)
    {
        ////clr();
        printf("1 - Cadastrar disciplina\n");
        printf("2 - Alterar professor da disciplina\n");
        printf("3 - Adicionar aluno na disciplina\n");
        printf("4 - Remover aluno da disciplina\n");
        printf("5 - Exibir dados da disciplina\n");
        printf("6 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &menuDisciplina);
        getchar();

        if (menuDisciplina == 0 || menuDisciplina == 1 || menuDisciplina == 2 || menuDisciplina == 3 || menuDisciplina == 4 || menuDisciplina == 5 || menuDisciplina == 6)
        {

            switch (menuDisciplina)
            {
            case 0:

                // zera as opc�es
                menu_Disciplina();
                break;

            case 1:

                // Cadastrar pessoa
                ////clr();
                printf("\nCadastrar");
                // sleep(2);
                break;

            case 2:
                // Exibir dados de uma pessoa
                ////clr();
                printf("\nAlterar professor");
                // sleep(2);
                break;

            case 3:
                // Alterar dados da pessoa
                ////clr();
                printf("\nAdicionar aluno");
                // sleep(2);
                break;

            case 4:
                // Excluir pessoa
                ////clr();
                printf("\nRemover aluno");
                // sleep(2);
                break;

            case 5:
                // Voltar ao menu principal
                ////clr();
                printf("\nExibir dados");
                // sleep(2);
                break;

            case 6:
                // Voltar ao menu principal
                menu_Principal();
                break;
            }
        }
        else
        {
            ////clr();
            printf("\nopcao Invalida\n\n");
            // sleep(2);
        }
    }
}