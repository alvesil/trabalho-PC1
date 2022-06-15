#include <stdio.h>

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
    while(menuPrincipal != 3){
        clr();
        printf("1 - Sistema de Pessoas\n");
        printf("2 - Sistema de Disciplina\n");
        printf("3 - Sair do Sistema\n");
        printf("\nDigite a opcao: ");
        scanf("%i", &menuPrincipal);

        if(menuPrincipal == 1 || menuPrincipal == 2 || menuPrincipal == 3){
            
            switch(menuPrincipal){

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
                break;
            }
        }
        else{
            clr();
            printf("\nopcao Invalida\n\n");
            printf("1 - Sistema de Pessoas\n");
            printf("2 - Sistema de Disciplina\n");
            printf("3 - Sair do Sistema\n");
            printf("\nDigite a opcao: ");
            scanf("%i", &menuPrincipal);
        }
    }
}

void menu_Pessoa(){
    clr();
    printf("entro no menu pessoa");
    scanf("%i", &menuPessoa);
    
}

void menu_Disciplina(){
    clr();
    printf("entro no menu Disciplina");
    scanf("%i", &menuDisciplina);
    
}

int main (){

menu_Principal();

return 0;

}