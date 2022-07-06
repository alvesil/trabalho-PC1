#include <stdio.h>
#include <time.h>
#include <string.h>

#ifndef metodos_h
    #define metodos_h
    #include "structs.h"

int contadorMatriculaAluno = 0, contadorPIS = 0;


void clr()
{
    printf("\ec\e[3J");
}

void mostraPessoa(Escola *escola, int contador)
{
    int menu1 = 0;
    int matricula = 0;
    int pis = 0;
    printf("1-Aluno \n2-Professor \n3-Voltar \n");
    scanf("%i", &menu1);
    getchar();
    switch (menu1)
    {
    case 1:
        printf("Digite a matricula: ");
        scanf("%d", &matricula);
        getchar();

        int aux = 0;
        for (int i = 0; i < contador; i++)
        {
            if (matricula == escola->alunos[i].matricula)
            {
                printf("Matricula: %i\n", escola->alunos[i].matricula);
                printf("Nome: %s\n", escola->alunos[i].nome);
                printf("Sobrenome: %s\n", escola->alunos[i].sobrenome);
                if (escola->alunos->nacionalidade == 0)
                {
                    printf("CPF: %s\n", escola->alunos[i].cpf);
                    printf("CPF: %s\n", escola->alunos[i].rg);
                }
                else
                {
                    printf("Passaporte: %s\n", escola->alunos[i].passaporte);
                    printf("País de Origem: %s\n", escola->alunos[i].paisOrigem);
                }
                printf("Data de Nascimento: %s\n", escola->alunos[i].dt_nasc);
                if (escola->alunos->pcd == 1)
                {
                    printf("CPF: %s\n", escola->alunos[i].laudo);
                }
                printf("\n");
                aux = 1;
            }
        }
        if (aux == 0)
        {
            printf("Pessoa nao encontrada\n");
        }

        break;
    case 2:
        printf("Digite o PIS: ");
        scanf("%d", &pis);
        getchar();
        for (int i = 0; i < contador; i++)
        {
            if (pis == escola->professores[i].pis)
            {
                printf("Matricula: %i\n", escola->professores[i].pis);
                printf("Nome: %s\n", escola->professores[i].nome);
                printf("Sobrenome: %s\n", escola->professores[i].sobrenome);
                if (escola->professores->nacionalidade == 0)
                {
                    printf("CPF: %s\n", escola->professores[i].cpf);
                    printf("CPF: %s\n", escola->professores[i].rg);
                }
                else
                {
                    printf("Passaporte: %s\n", escola->professores[i].passaporte);
                    printf("País de Origem: %s\n", escola->professores[i].paisOrigem);
                }
                printf("Data de Nascimento: %s\n", escola->professores[i].dt_nasc);
                if (escola->professores->pcd == 1)
                {
                    printf("CPF: %s\n", escola->alunos[i].laudo);
                }
                printf("\n");
                aux = 1;
            }
        }
        if (aux == 0)
        {
            printf("Pessoa nao encontrada\n");
        }
        break;
    case 3:
        break;
    default:
        break;
    }
}

int cadastraPessoa(Escola *escola, int contador)
{
    char entrada[100];
    scanf("%[^\n]s", entrada);
    getchar();
    // printf("%s", entrada);
    printf("\n");
    char pVirgula[2];
    // printf("%d", strlen(entrada));
    int cont = 0;
    int cont2 = 0;
    int cont3 = 0;

    /*
    Laço de repetição para verificar se foi digitado o padrão correto
    001, 010, 100... etc. E com base nisso cadastrar a pessoa.
    */
    int i, j;
    for (i = 0; i < strlen(entrada); i++)
    {
        if (entrada[i] == ';')
        {
            cont2++;
        }
    }
    if (cont2 == 8)
    {
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
                }
                cont++;
            }
        }
    }
    if (cont2 == 9)
    {
        for (j = 0; j < strlen(entrada); j++)
        {
            if (entrada[j] == ';')
            {
                cont3++;
            }
            if (cont3 == 9 && entrada[j + 1] == '0')
            {
                for (i = 0; i < strlen(entrada); i++)
                {
                    if (entrada[i] == ';')
                    {

                        if (cont == 1 || cont == 5 || cont == 8)
                        {
                            if (cont == 1)
                            {
                                pVirgula[0] = entrada[i + 1];
                            }
                            if (cont == 5)
                            {
                                pVirgula[1] = entrada[i + 1];
                            }
                            if (cont == 8)
                            {
                                pVirgula[2] = entrada[i + 1];
                            }
                        }
                        cont++;
                    }
                }
            }
            else
            {
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
                        }
                        cont++;
                    }
                }
            }
        }
    }
    if (cont2 == 10)
    {
        for (i = 0; i < strlen(entrada); i++)
        {
            if (entrada[i] == ';')
            {

                if (cont == 1 || cont == 5 || cont == 8)
                {
                    if (cont == 1)
                    {
                        pVirgula[0] = entrada[i + 1];
                    }
                    if (cont == 5)
                    {
                        pVirgula[1] = entrada[i + 1];
                    }
                    if (cont == 8)
                    {
                        pVirgula[2] = entrada[i + 1];
                    }
                }
                cont++;
            }
        }
    }

    /*
    Verificar e validar qual o padrão foi digitado.
    */
    printf("%d\n", cont);
    printf("%d\n", cont2);
    printf("%c", pVirgula[0]);
    printf("%c", pVirgula[1]);
    printf("%c", pVirgula[2]);
    if (cont == 8 || cont == 9)
    {

        if (pVirgula[0] == '0' && pVirgula[1] == '0' && pVirgula[2] == '0')
        {
            cont = 0;
            // nome;sobrenome;0;CPF;RG;DD/MM/AAAA;0;CEP;0

            printf("Brasileiro, não PcD e Aluno\n");

            int i, j;
            long int matricula = 0;

            /* Incrementa a Matrícula se Aluno */

            matricula = matricula + contadorMatriculaAluno;

            int anoAtual;
            time_t data_ano;
            time(&data_ano);

            struct tm *data = localtime(&data_ano);

            anoAtual = (data->tm_year - 100);
            anoAtual = (anoAtual * 1000) + matricula;

            escola->alunos[contador].matricula = anoAtual;
            contadorMatriculaAluno++;

            for (i = 0, j = 0; i < strlen(entrada); i++)
            {

                if (entrada[i] == ';')
                {
                    cont++;
                }
                if (cont == 0 && entrada[i] != ';')
                {
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
                    escola->alunos[contador].cep[j] = entrada[i];
                    j++;
                }
            }
            escola->alunos[contador].nacionalidade = 0;
            escola->alunos[contador].pcd = 0;

            return 1;
        }
        else if (pVirgula[0] == '0' && pVirgula[1] == '1' && pVirgula[2] == '0')
        {
            printf("Brasileiro, PcD e Aluno\n");
            cont = 0;
            // nome;sobrenome;0;CPF;RG;DD/MM/AAAA;1;laudo;CEP;0

            int i, j;
            long int matricula = 0;

            /* Incrementa a Matrícula se Aluno */

            matricula = matricula + contadorMatriculaAluno;

            int anoAtual;
            time_t data_ano;
            time(&data_ano);

            struct tm *data = localtime(&data_ano);

            anoAtual = (data->tm_year - 100);
            anoAtual = (anoAtual * 1000) + matricula;

            escola->alunos[contador].matricula = anoAtual;
            contadorMatriculaAluno++;

            for (i = 0, j = 0; i < strlen(entrada); i++)
            {

                if (entrada[i] == ';')
                {
                    cont++;
                }
                if (cont == 0 && entrada[i] != ';')
                {
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
                    escola->alunos[contador].laudo[j] = entrada[i];
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
                if (cont == 8 && entrada[i] != ';')
                {
                    escola->alunos[contador].cep[j] = entrada[i];
                    j++;
                }
            }
            escola->alunos[contador].nacionalidade = 0;
            escola->alunos[contador].pcd = 1;

            return 1;
        }
        else if (pVirgula[0] == '0' && pVirgula[1] == '0' && pVirgula[2] == '1')
        {
            printf("Brasileiro, não PcD e Professor\n");
            cont = 0;
            // nome;sobrenome;0;CPF;RG;DD/MM/AAAA;0;CEP;1;pis

            int i, j;
            long int matricula = 0;

            for (i = 0, j = 0; i < strlen(entrada); i++)
            {

                if (entrada[i] == ';')
                {
                    cont++;
                }
                if (cont == 0 && entrada[i] != ';')
                {
                    escola->professores[contador].nome[j] = entrada[i];
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
                    escola->professores[contador].sobrenome[j] = entrada[i];
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
                    escola->professores[contador].cpf[j] = entrada[i];
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
                    escola->professores[contador].rg[j] = entrada[i];
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
                    escola->professores[contador].dt_nasc[j] = entrada[i];
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
                    escola->professores[contador].cep[j] = entrada[i];
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
                if (cont == 9 && entrada[i] != ';')
                {
                    escola->professores[contador].pis = entrada[i];
                    j++;
                }
            }
            escola->alunos[contador].nacionalidade = 0;
            escola->alunos[contador].pcd = 0;

            return 1;
        }
        else if (pVirgula[0] == '0' && pVirgula[1] == '1' && pVirgula[2] == '1')
        {
            printf("Brasileiro, PcD e Professor\n");
            cont = 0;
            // nome;sobrenome;0;CPF;RG;DD/MM/AAAA;1;laudo;CEP;1;pis

            int i, j;
            long int matricula = 0;

            for (i = 0, j = 0; i < strlen(entrada); i++)
            {

                if (entrada[i] == ';')
                {
                    cont++;
                }
                if (cont == 0 && entrada[i] != ';')
                {
                    escola->professores[contador].nome[j] = entrada[i];
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
                    escola->professores[contador].sobrenome[j] = entrada[i];
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
                    escola->professores[contador].cpf[j] = entrada[i];
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
                    escola->professores[contador].rg[j] = entrada[i];
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
                    escola->professores[contador].dt_nasc[j] = entrada[i];
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
                if (cont == 6 && entrada[i] != ';')
                {
                    escola->professores[contador].laudo[j] = entrada[i];
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
                    escola->professores[contador].cep[j] = entrada[i];
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
                if (cont == 8 && entrada[i] != ';')
                {
                    escola->professores[contador].pis = entrada[i];
                    j++;
                }
            }
            escola->alunos[contador].nacionalidade = 0;
            escola->alunos[contador].pcd = 0;

            return 1;
        }
        else if (pVirgula[0] == '1' && pVirgula[1] == '0' && pVirgula[2] == '0')
        {
            printf("Estrangeiro, não PcD e Aluno\n");

            int i, j;
            long int matricula = 0;
            // nome;sobrenome;1;passaporte;paisOrigem;DD/MM/AAAA;0;CEP;0
            /* Incrementa a Matrícula se Aluno */

            matricula = matricula + contadorMatriculaAluno;

            int anoAtual;
            time_t data_ano;
            time(&data_ano);

            struct tm *data = localtime(&data_ano);

            anoAtual = (data->tm_year - 100);
            anoAtual = (anoAtual * 1000) + matricula;

            escola->alunos[contador].matricula = anoAtual;
            contadorMatriculaAluno++;

            for (i = 0, j = 0; i < strlen(entrada); i++)
            {

                if (entrada[i] == ';')
                {
                    cont++;
                }
                if (cont == 0 && entrada[i] != ';')
                {
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
                    escola->alunos[contador].passaporte[j] = entrada[i];
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
                    escola->alunos[contador].paisOrigem[j] = entrada[i];
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
                    escola->alunos[contador].cep[j] = entrada[i];
                    j++;
                }
            }
            escola->alunos[contador].nacionalidade = 1;
            escola->alunos[contador].pcd = 0;

            return 1;
        }
        else if (pVirgula[0] == '1' && pVirgula[1] == '1' && pVirgula[2] == '0')
        {
            printf("Estrangeiro, PcD e Aluno\n");
            // nome;sobrenome;1;passaporte;paisOrigem;DD/MM/AAAA;1;laudo;CEP;0

            int i, j;
            long int matricula = 0;

            /* Incrementa a Matrícula se Aluno */

            matricula = matricula + contadorMatriculaAluno;

            int anoAtual;
            time_t data_ano;
            time(&data_ano);

            struct tm *data = localtime(&data_ano);

            anoAtual = (data->tm_year - 100);
            anoAtual = (anoAtual * 1000) + matricula;

            escola->alunos[contador].matricula = anoAtual;
            contadorMatriculaAluno++;

            for (i = 0, j = 0; i < strlen(entrada); i++)
            {

                if (entrada[i] == ';')
                {
                    cont++;
                }
                if (cont == 0 && entrada[i] != ';')
                {
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
                    escola->alunos[contador].passaporte[j] = entrada[i];
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
                    escola->alunos[contador].paisOrigem[j] = entrada[i];
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
                if (cont == 6 && entrada[i] != ';')
                {
                    escola->alunos[contador].laudo[j] = entrada[i];
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
                    escola->alunos[contador].cep[j] = entrada[i];
                    j++;
                }
            }
            escola->alunos[contador].nacionalidade = 1;
            escola->alunos[contador].pcd = 1;

            return 1;
        }
        else if (pVirgula[0] == '1' && pVirgula[1] == '0' && pVirgula[2] == '1')
        {
            printf("Estrangeiro, não PcD e Professor\n");
            cont = 0;
            // nome;sobrenome;1;passaporte;paisOrigem;DD/MM/AAAA;0;CEP;1;pis

            int i, j;
            long int matricula = 0;

            for (i = 0, j = 0; i < strlen(entrada); i++)
            {

                if (entrada[i] == ';')
                {
                    cont++;
                }
                if (cont == 0 && entrada[i] != ';')
                {
                    escola->professores[contador].nome[j] = entrada[i];
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
                    escola->professores[contador].sobrenome[j] = entrada[i];
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
                    escola->professores[contador].passaporte[j] = entrada[i];
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
                    escola->professores[contador].paisOrigem[j] = entrada[i];
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
                    escola->professores[contador].dt_nasc[j] = entrada[i];
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
                    escola->professores[contador].cep[j] = entrada[i];
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
                if (cont == 8 && entrada[i] != ';')
                {
                    escola->professores[contador].pis = entrada[i];
                    j++;
                }
            }
            escola->alunos[contador].nacionalidade = 1;
            escola->alunos[contador].pcd = 0;

            return 1;
        }
        else if (pVirgula[0] == '1' && pVirgula[1] == '1' && pVirgula[2] == '1')
        {
            printf("Estrangeiro, não PcD e Professor\n");
            cont = 0;
            // nome;sobrenome;1;passaporte;paisOrigem;DD/MM/AAAA;1;laudo;CEP;1;pis

            int i, j;
            long int matricula = 0;

            for (i = 0, j = 0; i < strlen(entrada); i++)
            {

                if (entrada[i] == ';')
                {
                    cont++;
                }
                if (cont == 0 && entrada[i] != ';')
                {
                    escola->professores[contador].nome[j] = entrada[i];
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
                    escola->professores[contador].sobrenome[j] = entrada[i];
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
                    escola->professores[contador].passaporte[j] = entrada[i];
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
                    escola->professores[contador].paisOrigem[j] = entrada[i];
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
                    escola->professores[contador].dt_nasc[j] = entrada[i];
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
                if (cont == 8 && entrada[i] != ';')
                {
                    escola->professores[contador].laudo[j] = entrada[i];
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
                    escola->professores[contador].cep[j] = entrada[i];
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
                if (cont == 8 && entrada[i] != ';')
                {
                    escola->professores[contador].pis = entrada[i];
                    j++;
                }
            }
            escola->alunos[contador].nacionalidade = 1;
            escola->alunos[contador].pcd = 0;

            return 1;
        }
    }
    else
    {
        printf("Erro no padrão de entrada\n");
    }

    return 0;
}

#endif