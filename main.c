#include <stdio.h>
#include <string.h>

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

int cadastraAluno(Escola *escola)
{
    char entrada[100];
    scanf("%s", entrada);
    //printf("%s", entrada);
    printf("\n");
    char pVirgula[3];
    //printf("%d", strlen(entrada));
    int cont = 0;
    
    /*
    Laço de repetição para verificar se foi digitado o padrão correto
    001, 010, 100... etc. E com base nisso cadastrar a pessoa.
    */
    int i;
    for (i = 0; i < strlen(entrada); i++)
    {
        if(entrada[i] == ';')
        { 
            if (cont == 1 || cont == 5 || cont == 7)
            {
                if(cont == 1){
                  pVirgula[0] = entrada[i+1];
                }
                if(cont == 5){
                  pVirgula[1] = entrada[i+1];
                }
                if(cont == 7){
                  pVirgula[2] = entrada[i+1];
                }
                //printf("%c", entrada[i+1]);
            }
            //printf("%c", pVirgula[i]);
            cont++;
        }
    }

    /*
    Verificar qual o padrão foi digitado.
    */
    if (pVirgula[0] == '0' && pVirgula[1] == '0' && pVirgula[2] == '0')
    {
        cont = 0;
        char nome[20];  //Nome do aluno
        char sobrenome[20]; //Sobrenome do aluno
        char cpf[12]; //CPF do aluno
        char rg[8]; //RG do aluno
        char dtNsc[11]; //Data de nascimento do aluno
        char cep [9]; //CEP do aluno

        printf("Brasileiro, não PcD e Aluno\n");
        int i, j;
        for (i = 0, j = 0; i < strlen(entrada); i++)
        {
    	 	if(entrada[i] == ';'){
            	cont ++;
	            //TODO: separar os dados para gravar o tipo de pessoa.
            }
            if(cont == 0 && entrada[i] != ';'){
                nome[j] = entrada[i];
            	escola->alunos->nome[j] = entrada[i];
                j++;
            } 
        }
        cont = 0; //Zerando o contador pro próximo loop
        for(i = 0, j = 0; i < strlen(entrada); i++){
        	if(entrada[i] == ';'){
            	cont ++;
            }
        	if (cont == 1 && entrada[i] != ';'){
                sobrenome[j] = entrada[i];
                escola->alunos->sobrenome[j] = entrada[i];
                j++;
            }
		}
		cont = 0; //Zerando o contador pro próximo loop
		for(i = 0, j = 0; i < strlen(entrada); i++){
			if(entrada[i] == ';'){
            	cont ++;
            }
			if (cont == 3 && entrada[i] != ';'){
                cpf[j] = entrada[i];
                escola->alunos->cpf[j] = entrada[i];
                j++;
            }
		}
		cont = 0; //Zerando o contador pro próximo loop
		for(i = 0, j = 0; i < strlen(entrada); i++){
			if(entrada[i] == ';'){
            	cont ++;
            }
			if (cont == 4 && entrada[i] != ';'){
                rg[j] = entrada[i];
                escola->alunos->rg[j] = entrada[i];
                j++;
            }
        }
		cont = 0; //Zerando o contador pro próximo loop}
		for(i = 0, j = 0; i < strlen(entrada); i++){
			if(entrada[i] == ';'){
            	cont ++;
            }
			if (cont == 5 && entrada[i] != ';'){
                dtNsc[j] = entrada[i];
                escola->alunos->dt_nasc[j] = entrada[i];
                j++;
            }
		}
		cont = 0; //Zerando o contador pro próximo loop
		for(i = 0, j = 0; i < strlen(entrada); i++){
			if(entrada[i] == ';'){
            	cont ++;
            }
			if (cont == 7 && entrada[i] != ';'){
            	cep[j] = entrada[i];
                escola->alunos->cep[j] = entrada[i];
                j++;
            }
		}

        //printf("%s\n", nome); 
        //printf("%s\n", escola->alunos->nome);
        //printf("%s\n", sobrenome); 
        //printf("%s\n",escola->alunos->sobrenome);
        //printf("%s\n", cpf); 
        //printf("%s\n", escola->alunos->cpf);
        //printf("%s\n", rg); 
        //printf("%s\n", escola->alunos->rg);
        //printf("%s\n", dtNsc); 
        //printf("%s\n", escola->alunos->dt_nasc);
        //printf("%s\n", cep); 
        //printf("%s\n", escola->alunos->cep);
        
        //scanf("%s", entrada);

        return 1;
        
    }else if (pVirgula[0] == '0' && pVirgula[1] == '1' && pVirgula[2] == '0')
    {
        printf("Brasileiro, PcD e Aluno\n");
    }else if (pVirgula[0] == '0' && pVirgula[1] == '0' && pVirgula[2] == '1')
    {
        printf("Brasileiro, não PcD e Professor\n");
    }else if(pVirgula[0] == '0' && pVirgula[1] == '1' && pVirgula[2] == '1')
    {
        printf("Brasileiro, PcD e Professor\n");
    }else if (pVirgula[0] == '1' && pVirgula[1] == '0' && pVirgula[2] == '0')
    {
        printf("Estrangeiro, não PcD e Aluno\n");
    }else if (pVirgula[0] == '1' && pVirgula[1] == '1' && pVirgula[2] == '0')
    {
        printf("Estrangeiro, PcD e Aluno\n");
    }else if (pVirgula[0] == '1' && pVirgula[1] == '0' && pVirgula[2] == '1')
    {
        printf("Estrangeiro, não PcD e Professor\n");
    }

    //printf("%d\n", cont);
    /*for (i = 0; i < 3; i++)
    {
        printf("%c", pVirgula[i]);
    }
    */
    //printf("%d", strlen(pVirgula));
    
    //printf("%s", pVirgula);
   
    //scanf("%s", entrada);

    return 0;
}

void cadastrar_pessoa(Pessoa pessoas [20])
{
    int i;
    printf("digite 0 se for professor ou 1 se for aluno: ");
    scanf("%i", &i );
    while(i != 0 || i != 1)
    {
        if(i == 0){
            //Cadastro de aluno
            clr();
            printf("Digite 0 se dor Brasileiro e 1 se for estrangeiro: ");
            scanf("%i", &i);

            while( i != 0 || i != 1){
                //Aluno Brasileiro
                if(i==0){
                    printf("\nDigite 0 para nao PcD ou 1 para PcD: ");
                    scanf("%i", &i);
                    while(i !=0 || i != 0){

                    }

                }
                //Aluno Extrangeiro
                else if(i==1){

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
        }
        else{
            //Opção errada
            clr();
            printf("\nOpcao nao valida\n");            
            printf("\ndigite 0 se for professor ou 1 se for aluno: ");
            scanf("%i", &i );
        }
    }
}

void cadastrar_disciplina(char dados[50])
{
    printf("Processa os dados aqui");
}

int main()
{
    int opcaoInicial, opcaoPessoa, opcaoDisciplina;
    Escola escola;

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
                        if (cadastraAluno(&escola) == 1)
                        {
                            //clr();
                            printf("Aluno cadastrado com sucesso.");
                            return 0;
                            //getchar();
                        }else{
                            printf("Aluno não cadastrado.");
                            return 0;
                            //getchar();
                        }
                        
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