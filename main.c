#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#if def_WIN32
#include<Windows.h>
#else
#include <unistd.h>
#endif

void menu_Pessoa();
void menu_Principal();
void menu_Disciplina(); 


int menuPrincipal, menuPessoa, menuDisciplina;

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

    return 0;
}

void menu_Principal(){
    menuDisciplina = 0;
    menuPrincipal = 0;
    menuPessoa = 0;
    while(menuPrincipal != 3){
        clr();
        printf("1 - Sistema de Pessoas\n");
        printf("2 - Sistema de Disciplina\n");
        printf("3 - Sair do Sistema\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &menuPrincipal);

        if(menuPrincipal == 0 ||menuPrincipal == 1 || menuPrincipal == 2 || menuPrincipal == 3){
            
            switch(menuPrincipal){

                case 0:
                //zera as op��es
                menu_Principal();
                break;

                case 1:

                //Sistema de Pessoas
                menu_Pessoa();
                break;

                case 2:
                //sistema de Disciplina
                menu_Disciplina();                
                break;

                case 3:
                //Sair do Sistema
                exit(1);
                break;
            }
        }
        else{
            clr();
            printf("\nopcao Invalida\n\n");
            sleep(2);
  
        }
    }
}

void menu_Pessoa(){
    menuDisciplina = 0;
    menuPrincipal = 0;
    menuPessoa = 0;
while(menuPessoa != 5){
        clr();
        printf("1 - Cadastrar pessoa\n");
        printf("2 - Exibir dados de uma pessoa\n");
        printf("3 - Alterar dados da pessoa\n");
        printf("4 - Excluir pessoa\n");
        printf("5 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &menuPessoa);

        if(menuPessoa == 0 || menuPessoa == 1 || menuPessoa == 2 || menuPessoa == 3 || menuPessoa == 4 || menuPessoa == 5){
            
            switch(menuPessoa){
                case 0: 

                //zera as opc�es
                menu_Pessoa();
                break;

                case 1:

                //Cadastrar pessoa
                clr();
                printf("\nCadastrar");
                sleep(2);
                break;

                case 2:
                //Exibir dados de uma pessoa
                clr();
                printf("\nExibir");
                sleep(2);
                break;

                case 3:
                //Alterar dados da pessoa
                clr();
                printf("\nExcluir"); 
                sleep(2);
                break;

                  case 4:
                //Excluir pessoa
                clr();
                printf("\nExcluir");  
                sleep(2);
                break;

                case 5:
                //Voltar ao menu principal
                menu_Principal();
                break;
            }
        }
        else{
            clr();
            printf("\nopcao Invalida\n\n");
            sleep(2);

        }
    }
}
    

int main()
{
    int opcaoInicial, opcaoPessoa, opcaoDisciplina;
    Escola escola;
    menuDisciplina = 0;
    menuPrincipal = 0;
    menuPessoa = 0;

    while(menuPessoa != 5){
        clr();
        printf("1 - Cadastrar disciplina\n");
        printf("2 - Alterar professor da disciplina\n");
        printf("3 - Adicionar aluno na disciplina\n");
        printf("4 - Remover aluno da disciplina\n");
        printf("5 - Exibir dados da disciplina\n");
        printf("6 - Voltar ao menu principal\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &menuDisciplina);

        if(menuDisciplina == 0 || menuDisciplina == 1 || menuDisciplina == 2 || menuDisciplina == 3 || menuDisciplina == 4 || menuDisciplina == 5 || menuDisciplina == 6){
            
            switch(menuDisciplina){
                case 0: 

                //zera as opc�es
                menu_Disciplina();
                break;

                case 1:

                //Cadastrar pessoa
                clr();
                printf("\nCadastrar"); 
                sleep(2);
                break;

                case 2:
                //Exibir dados de uma pessoa
                clr();
                printf("\nAlterar professor");    
                sleep(2);
                break;

                case 3:
                //Alterar dados da pessoa
                clr();
                printf("\nAdicionar aluno"); 
                sleep(2);
                break;

                case 4:
                //Excluir pessoa
                clr();
                printf("\nRemover aluno");   
                sleep(2);
                break;

                  case 5:
                //Voltar ao menu principal
                clr();
                printf("\nExibir dados");
                sleep(2);
                break;

                case 6:
                //Voltar ao menu principal
                menu_Principal();
                break;
            }
        }
        else{
            clr();
            printf("\nopcao Invalida\n\n");
            sleep(2);

        }
    }
    
}

int main (){

menu_Principal();

return 0;

}