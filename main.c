#include <stdio.h>
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

void menu_Principal(){
    menuDisciplina = 0;
    menuPrincipal = 0;
    menuPessoa = 0;
    while(menuPrincipal != 3){
        clr();
        printf("--------PRINCIPAL--------\n");
        printf("1 - Sistema de Pessoas\n");
        printf("2 - Sistema de Disciplina\n");
        printf("3 - Sair do Sistema\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &menuPrincipal);

        if(menuPrincipal == 0 ||menuPrincipal == 1 || menuPrincipal == 2 || menuPrincipal == 3){
            
            switch(menuPrincipal){

                case 0:
                //zera as opções
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
        printf("---------PESSOA---------\n");
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

                //zera as opcões
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
    

void menu_Disciplina(){

    menuDisciplina = 0;
    menuPrincipal = 0;
    menuPessoa = 0;

    while(menuPessoa != 5){
        clr();
        printf("--------DISCIPLINA--------\n");
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

                //zera as opcões
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