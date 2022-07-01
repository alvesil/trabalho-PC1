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
    int pis;

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
    system("cls");
}

void menu_Principal(Escola *escola){
	
	// DADOS MOCK
	// Excluir apos testes/finalizar
	//##############################################################################{
	
	escola->professores[0].pis = 1;
	strncpy(escola->professores[0].nome,"Thais",20);
	
	escola->professores[1].pis = 2;
	strncpy(escola->professores[1].nome,"William",20);
	
	escola->alunos[0].matricula = 1;
	strncpy(escola->alunos[0].nome,"Johhnie",20);
	
	escola->alunos[1].matricula = 2;
	strncpy(escola->alunos[1].nome,"Arthur",20);
	
	escola->disciplina[5].codigo = 0; //cod 1 para considerar todas disciplinas cadastradas

	//##############################################################################}
	
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
        getchar();

        switch(menuPrincipal){

            case 1:
                //Sistema de Pessoas
                menu_Pessoa();
                break;

            case 2:
                //sistema de Disciplina
                menu_Disciplina(escola);                
                break;

            case 3:
                //Sair do Sistema
                break;
            
            //Opcao invalida
        	default:
	        	clr();
	            printf("Opcao Invalida");
	            sleep(2);
	            break;
        }
    }
}

void menu_Pessoa(Escola *escola){
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
        getchar();

        if(menuPessoa == 0 || menuPessoa == 1 || menuPessoa == 2 || menuPessoa == 3 || menuPessoa == 4 || menuPessoa == 5){
            
            switch(menuPessoa){
                case 0: 

                //zera as opcões
                menu_Pessoa(escola);
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
                menu_Principal(escola);
                break;
            }
        }
        else{
            clr();
            printf("\n Opcao Invalida\n\n");
            sleep(2);

        }
    }
}
    

void menu_Disciplina(Escola *escola){
	
	int i, a, b = 0;
	int codigoDisciplina;
	char nomeDisciplina[20];
	int cargaHoraria;
	int pisProfessor;
	Pessoa professorDisciplina;
	int matriculaAluno;
	
    menuDisciplina = 0;
    
	while(menuDisciplina != 6){
	    clr();
	    printf("--------DISCIPLINA--------\n");
	    printf("1 - Cadastrar disciplina\n");
	    printf("2 - Alterar professor da disciplina\n");
	    printf("3 - Adicionar aluno na disciplina\n");
	    printf("4 - Remover aluno da disciplina\n");
	    printf("5 - Exibir dados da disciplina\n");
	    printf("6 - Voltar ao menu principal\n");
	    printf("\n Digite a opcao: ");
	    scanf("%i", &menuDisciplina);
	    getchar();
	
	    switch(menuDisciplina){
	    	 //Cadastrar disciplina
	        case 1:
		        clr();
		        printf("Cadastrar Disciplina");
		        printf("\n\n");
				
				if(escola->disciplina[5].codigo != 0){
					clr();
					printf("Maximo de disciplinas cadastradas");
					sleep(2);
					menu_Principal(escola);	
				}
				
				printf("Codigo: ");
				scanf("%d",&codigoDisciplina);
				
				for(i=0 ; i<5 ; i++){
					if(escola->disciplina[i].codigo == codigoDisciplina){
						clr();
						printf("Disciplina ja cadastrada");
						sleep(2);
						menu_Principal(escola);
					}
				}
				
				printf("Nome: ");
       			scanf("%s",&nomeDisciplina);
       			
       			printf("Carga: ");
				scanf("%d",&cargaHoraria);
				
				printf("PIS: ");
				scanf("%d",&pisProfessor);
				
				int existeProfessor = 0;
				for(i=0 ; i<5 ; i++){
					if(escola->professores[i].pis == pisProfessor){
						existeProfessor = 1;
						professorDisciplina = escola->professores[i];
					}
				}
				if(existeProfessor == 0){
					clr();
					printf("Professor nao cadastrado");
					sleep(2);
					menu_Principal(escola);	
				}
				
				for(i=0;i<5;i++){
					if(escola->disciplina[i].codigo == NULL){
						escola->disciplina[i].codigo = codigoDisciplina;
						strncpy(escola->disciplina[i].nome, nomeDisciplina, 20);
						escola->disciplina[i].cargaHoraria = cargaHoraria;
						escola->disciplina[i].professor = professorDisciplina;
						for(a=0;a<10;a++){
							escola->disciplina[i].aluno[a].matricula = NULL;	
						}
						break;
					}
				}
				
				clr();
				printf("Disciplina cadastrada com sucesso");
				sleep(2);
				
		        break;
	
			//Alterar professor de uma disciplina
	        case 2:
		        clr();
		        printf("Alterar professor");
		        printf("\n\n");
		        
		        printf("Codigo: ");
				scanf("%d",&codigoDisciplina);
		        
		        for(i=0;i<5;i++){
					if(escola->disciplina[i].codigo == codigoDisciplina){
						printf("PIS: ");
						scanf("%d",&pisProfessor);
						for(a=0 ; a<5 ; a++){
							if(escola->professores[a].pis == pisProfessor){
								escola->disciplina[i].professor = escola->professores[a];
								clr();
								printf("Professor alterado com sucesso");
								sleep(2);
								menu_Disciplina(escola); 
							}
						}
						clr();
						printf("Professor nao cadastrado");
						sleep(2);
						menu_Disciplina(escola); 
					}
				}
				clr();
				printf("Disciplina nao cadastrada");
				sleep(2);
		        break;
	
			//Adicionar um aluno a uma disciplina
	        case 3:
		        clr();
		        printf("Adicionar aluno");
		        printf("\n\n");
		        
		        printf("Codigo: ");
				scanf("%d",&codigoDisciplina);
		        
		        for(i=0;i<5;i++){
					if(escola->disciplina[i].codigo == codigoDisciplina){
						printf("Matricula Aluno: ");
						scanf("%d",&matriculaAluno);
						for(a=0 ; a<30 ; a++){
							if(escola->alunos[a].matricula == matriculaAluno){
								for(b=0 ; b<10 ; b++){
									if(escola->disciplina[i].aluno[b].matricula == matriculaAluno){
										clr();
										printf("Aluno ja matriculado");
										sleep(2);
										menu_Disciplina(escola); 
									}
								}
								for(b=0 ; b<10 ; b++){
									if(escola->disciplina[i].aluno[b].matricula == NULL){
										escola->disciplina[i].aluno[b] = escola->alunos[a];
										clr();
										printf("Aluno matriculado com sucesso");
										sleep(2);
										menu_Disciplina(escola); 
									}
								}
							}
						}
						clr();
						printf("Aluno nao cadastrado");
						sleep(2);
						menu_Disciplina(escola); 
					}
				}
				clr();
				printf("Disciplina nao cadastrada");
				sleep(2);
		        break;
	
	         //Remover aluno de uma disciplina
			case 4:
				clr();
		        printf("Remover aluno");
		        printf("\n\n");
				
				printf("Codigo: ");
				scanf("%d",&codigoDisciplina);
		        
		        for(i=0;i<5;i++){
					if(escola->disciplina[i].codigo == codigoDisciplina){
						printf("Matricula Aluno: ");
						scanf("%d",&matriculaAluno);
						for(a=0 ; a<30 ; a++){
							if(escola->alunos[a].matricula == matriculaAluno){
								for(b=0 ; b<10 ; b++){
									if(escola->disciplina[i].aluno[b].matricula == matriculaAluno){
										escola->disciplina[i].aluno[b].matricula = NULL;
										clr();
										printf("Aluno removido com sucesso");
										sleep(2);
										menu_Disciplina(escola); 
									}
								}
								clr();
								printf("Aluno nao matriculado");
								sleep(2);
								menu_Disciplina(escola);
							}
						}
						clr();
						printf("Aluno nao cadastrado");
						sleep(2);
						menu_Disciplina(escola); 
					}
				}
				clr();
				printf("Disciplina nao cadastrada");
				sleep(2);
		        break;
	
			//Exibir dados de uma disciplina
	        case 5:
	            clr();
	            printf("Exibir dados");
	            printf("\n\n");
	            
	            //int codigoDisciplina;
	            
	            printf("Codigo: ");
				scanf("%d",&codigoDisciplina);
				
				for(i=0;i<5;i++){
					if(escola->disciplina[i].codigo == codigoDisciplina){
						printf("\n\n");
						printf("-----DISCIPLINA-----\n");
						printf("Codigo: %d \n",escola->disciplina[i].codigo);
						printf("Nome: %s \n",escola->disciplina[i].nome);
						printf("Professor: %s \n",escola->disciplina[i].professor.nome); 
						printf("Alunos:\n");
						for(a=0;a<10;a++){
							if(escola->disciplina[i].aluno[a].matricula != NULL){
								printf("     Matricula: %d | Nome: %s \n",escola->disciplina[i].aluno[a].matricula, escola->disciplina[i].aluno[a].nome);	
							}
						}
						printf("\n\n");
						system("pause");
						menu_Disciplina(escola);
					}
				}
	            clr();
				printf("Disciplina nao cadastrada");
				sleep(2);
	            break;
			
			//Voltar ao menu principal
	        case 6:
	            menu_Principal(escola);
	            break;
	        
	        //Opcao invalida
	        default:
	        	clr();
	            printf("Opcao Invalida");
	            sleep(2);
	            break;
	    }
	}	
    
}

int main (){
	Escola escola;
	menu_Principal(&escola);
	return 0;
}
