int contadorMatriculaAluno = 0, contadorPIS = 0;
void clr()
{
    printf("\ec\e[3J");
}

int mostraPessoa(Escola escola, int contador)
{
    int menu1 = 0;
    int matricula = 0;
    int pis = 0;
    printf("1-Professor \n2-Aluno \n3-Voltar \n");
    scanf("%i", &menu1);
    getchar();
    switch (menu1)
    {
    case 1:
        printf("Digite a matricula: ");
        scanf("%i", &matricula);
        getchar();

        for (int i = 0; i < sizeof(escola.alunos); i++)
        {
            if (matricula == escola.alunos[i].matricula2)
            {
                printf("Nome: %s\n", escola.alunos[i].nome);
                printf("Matricula: %i\n", escola.alunos[i].matricula2);

                printf("\n");
            }
            else
            {
                printf("Pessoa nao encontrada\n");
            }
        }

        break;
    case 2:
        printf("Digite o PIS: ");
        scanf("%i", &pis);
        getchar();
        for (int i = 0; i < sizeof(escola.professores); i++)
        {
            if (matricula == escola.professores[i].pis)
            {
                printf("Nome: %s\n", escola.professores[i].nome);
                printf("PIS: %i\n", escola.professores[i].pis);
                printf("\n");
            }
            else
            {
                printf("Pessoa nao encontrada\n");
            }
        }

        break;
    case 3:
        return 0;
        break;
    default:
        break;
    }
    return 0;
}

int cadastraPessoa(Escola *escola, int contador)
{
    char entrada[100];
    scanf("%[^\n]s", entrada);
    getchar();
    // printf("%s", entrada);
    printf("\n");
    char pVirgula[3];
    // printf("%d", strlen(entrada));
    int cont = 0;

    /*
    Laço de repetição para verificar se foi digitado o padrão correto
    001, 010, 100... etc. E com base nisso cadastrar a pessoa.
    */
    int i;
    for (i = 0; i < strlen(entrada); i++)
    {
        if (entrada[i] == ';')
        {
            if (cont == 1 || cont == 5 || cont == 7)
            {
                if (cont == 1)
                {
                    pVirgula[0] = entrada[i + 1];
                }
                if (cont == 5)
                {
                    pVirgula[1] = entrada[i + 1];
                }
                if (cont == 7)
                {
                    pVirgula[2] = entrada[i + 1];
                }
                // printf("%c", entrada[i+1]);
            }
            // printf("%c", pVirgula[i]);
            cont++;
        }
    }

    /*
    Verificar qual o padrão foi digitado.
    */
    if (pVirgula[0] == '0' && pVirgula[1] == '0' && pVirgula[2] == '0')
    {
        cont = 0;
        char nome[20];      // Nome do aluno
        char sobrenome[20]; // Sobrenome do aluno
        char cpf[12];       // CPF do aluno
        char rg[8];         // RG do aluno
        char dtNsc[11];     // Data de nascimento do aluno
        char cep[9];        // CEP do aluno
        // nome;sobrenome;0;CPF;RG;DD/MM/AAAA;0;CEP;0

        printf("Brasileiro, não PcD e Aluno\n");

        int i, j;

        /* Incrementa a Matrícula se Aluno */
        escola->alunos[contador].matricula[0] = 2;
        escola->alunos[contador].matricula[1] = 2;

        if (sizeof(contadorMatriculaAluno) > 1)
        {
            escola->alunos[contador].matricula[3] = 0;
            escola->alunos[contador].matricula[4] = 0;
        }
        else if (sizeof(contadorMatriculaAluno) > 2)
        {
            escola->alunos[contador].matricula[3] = 0;
        }
        contadorMatriculaAluno++;
        printf("%d", contadorMatriculaAluno);
        escola->alunos[contador].matricula2 = contadorMatriculaAluno;
        for (i = 0, j = 0; i < strlen(entrada); i++)
        {

            if (entrada[i] == ';')
            {
                cont++;
            }
            if (cont == 0 && entrada[i] != ';')
            {
                nome[j] = entrada[i];
                escola->alunos[contador].nome[j] = entrada[i];
                j++;
            }
        }
        cont = 0; // Zerando o contador pro próximo loop
        for (i = 0, j = 0; i < strlen(entrada); i++)
        {
            if (entrada[i] == ';')
            {
                cont++;
            }
            if (cont == 1 && entrada[i] != ';')
            {
                sobrenome[j] = entrada[i];
                escola->alunos[contador].sobrenome[j] = entrada[i];
                j++;
            }
        }
        cont = 0; // Zerando o contador pro próximo loop
        for (i = 0, j = 0; i < strlen(entrada); i++)
        {
            if (entrada[i] == ';')
            {
                cont++;
            }
            if (cont == 3 && entrada[i] != ';')
            {
                cpf[j] = entrada[i];
                escola->alunos[contador].cpf[j] = entrada[i];
                j++;
            }
        }
        cont = 0; // Zerando o contador pro próximo loop
        for (i = 0, j = 0; i < strlen(entrada); i++)
        {
            if (entrada[i] == ';')
            {
                cont++;
            }
            if (cont == 4 && entrada[i] != ';')
            {
                rg[j] = entrada[i];
                escola->alunos[contador].rg[j] = entrada[i];
                j++;
            }
        }
        cont = 0; // Zerando o contador pro próximo loop}
        for (i = 0, j = 0; i < strlen(entrada); i++)
        {
            if (entrada[i] == ';')
            {
                cont++;
            }
            if (cont == 5 && entrada[i] != ';')
            {
                dtNsc[j] = entrada[i];
                escola->alunos[contador].dt_nasc[j] = entrada[i];
                j++;
            }
        }
        cont = 0; // Zerando o contador pro próximo loop
        for (i = 0, j = 0; i < strlen(entrada); i++)
        {
            if (entrada[i] == ';')
            {
                cont++;
            }
            if (cont == 7 && entrada[i] != ';')
            {
                cep[j] = entrada[i];
                escola->alunos[contador].cep[j] = entrada[i];
                j++;
            }
        }
        return 1;
    }
    else if (pVirgula[0] == '0' && pVirgula[1] == '1' && pVirgula[2] == '0')
    {
        printf("Brasileiro, PcD e Aluno\n");
    }
    else if (pVirgula[0] == '0' && pVirgula[1] == '0' && pVirgula[2] == '1')
    {
        printf("Brasileiro, não PcD e Professor\n");
    }
    else if (pVirgula[0] == '0' && pVirgula[1] == '1' && pVirgula[2] == '1')
    {
        printf("Brasileiro, PcD e Professor\n");
    }
    else if (pVirgula[0] == '1' && pVirgula[1] == '0' && pVirgula[2] == '0')
    {
        printf("Estrangeiro, não PcD e Aluno\n");
    }
    else if (pVirgula[0] == '1' && pVirgula[1] == '1' && pVirgula[2] == '0')
    {
        printf("Estrangeiro, PcD e Aluno\n");
    }
    else if (pVirgula[0] == '1' && pVirgula[1] == '0' && pVirgula[2] == '1')
    {
        printf("Estrangeiro, não PcD e Professor\n");
    }

    return 0;
}