#include<string.h>
#include "metodos.h"
#include "diciplina.h"
#include "menu.h"

void menu_Disciplina();

char auxnomeDiciplina [100];
long int auxpis;
char auxnome [20] = "Rafael";
char auxsobrenome[50] = "Braga";


int i, valida = 1, auxcargahoraria, alunosmatriculados[5];
long int auxcodigo, auxmatricula;

extern Escola escola;



void cadastrarDisiplina(Escola *escola,Disciplina *disciplina, int contadordisciplina){

    escola->professores[0].pis = 1;
    escola->professores[1].pis = 2;
    escola->professores[2].pis = 3;
    escola->professores[3].pis = 4;
    escola->professores[4].pis = 5;

   
    

    printf("\nDigite o nome da diciplina: ");
    scanf("%s", auxnomeDiciplina);
    getchar();
    printf("\nDigite o codigoda disciplina: ");
    scanf("%ld", &auxcodigo);
    getchar();
    printf("\nDigite a caga horaria da disciplina: ");
    scanf("%i", &auxcargahoraria);
    getchar();
    printf("\nDigite o PIS do professor: ");
    scanf("%ld", &auxpis);
    
    for(i = 0; i < 5; i++){
            
            if (escola->professores[i].pis == auxpis){
               
                valida = 0;
            }
    }
    while (valida != 0){
        printf("\n\nProfessor nao encontrado\n");
        printf("\n\nDigite o PIS do professor: ");
        scanf("%ld", &auxpis);
        getchar();
        for(i = 0; i < 5; i++){
            if (escola->professores[i].pis == auxpis){
                valida = 0;
            }
        }

    }

    strcpy (escola->professores[0].nome, auxnome);
    strcpy (escola->professores[0].sobrenome, auxsobrenome);
    strcpy (escola->professores[1].nome, auxsobrenome);
    strcpy (escola->professores[1].sobrenome, auxnome);

    strcpy (disciplina->professor.nome, escola->professores[contadordisciplina].nome);
    strcpy (disciplina->professor.sobrenome, escola->professores[contadordisciplina].sobrenome);
    disciplina[contadordisciplina].cargaHoraria = auxcargahoraria;
    strcpy(disciplina[contadordisciplina].nomeDisciplina, auxnomeDiciplina);
    disciplina[contadordisciplina].codigo = auxcodigo;
    contadordisciplina++;



    printf("\n\nDisciplina cadastrada com sucesso\n\n");

    
}

void mudarprofessor(Escola *escola, Disciplina *disciplina, int contadordisciplina){
    
    valida = 1;
    int mudar_professor;

    printf("\ndigite o cadigo da materia: ");
    scanf("%ld",&auxcodigo);
    getchar();
    for(i = 0; i < 5; i++ ){
        if(disciplina[i].codigo == auxcodigo){
            int valida2 = 1;
            valida = 0;
            mudar_professor = i;
            printf("\nDigite o numero pis do novo professor: ");
            scanf("%ld", &auxpis);
            for(i = 0; i < 5; i++){
            
                if (escola->professores[i].pis == auxpis){
                    valida2 = 0;
                    disciplina[mudar_professor].professor = escola->professores[i];
                }
            }
            while (valida2 != 0){
                printf("\n\nProfessor nao encontrado\n");
                printf("\n\nDigite o PIS do novo professor: ");
                scanf("%ld", &auxpis);
                getchar();
                for(i = 0; i < 5; i++){
                    if (escola->professores[i].pis == auxpis){
                    valida2 = 0;
                    }
                }

            }
        }
    }
    while (valida != 0){

        printf("\nMateria nao encontrada\n");
        printf("\ndigite o cadigo da materia: ");
        scanf("%ld",&auxcodigo);
        getchar();

        for(i = 0; i < 5; i++ ){
        if(disciplina[i].codigo == auxcodigo){
            int valida2 = 1;
            valida = 0;
            mudar_professor = i;
            printf("\nDigite o numero pis do novo professor: ");
            scanf("%ld", &auxpis);
            for(i = 0; i < 5; i++){
            
                if (escola->professores[i].pis == auxpis){
                    valida2 = 0;
                    disciplina[mudar_professor].professor = escola->professores[i];
                }
            }
            while (valida2 != 0){
                printf("\n\nProfessor nao encontrado\n");
                printf("\n\nDigite o PIS do novo professor: ");
                scanf("%ld", &auxpis);
                getchar();
                for(i = 0; i < 5; i++){
                    if (escola->professores[i].pis == auxpis){
                    valida2 = 0;
                    }
                }

            }
        }
    }
    
    }
    
}

void addAluno(Escola *escola, Disciplina *disciplinas, int alunosmatriculados){
    printf("\nDigite o codigo da disciplina: ");
    scanf("%ls", &auxcodigo);
    getchar();

    int validaadd = 1, validaadd2 = 1, continuaradd = 1;

    for(i = 0; i < 5; i++ ){
        if(disciplina[i].codigo == auxcodigo){
            validaadd = 0;
            while (continuaradd != 0){
                if(alunosmatriculados[i] < 10){
                    printf("Digite a matricula do aluno");
                    scanf("%ld", auxmatricula);
                    for(i = 0; i < 30; i++){
                        if(escola->alunos[i].matricula == auxmatricula){
                            validaadd2 = 0;
                        }

                        while (validaadd2 != 0){
                            printf("Digite a matricula do aluno");
                            scanf("%ld", auxmatricula);
                            for(i = 0; i < 30; i++){
                                if(escola->alunos[i].matricula == auxmatricula){
                                    validaadd2 = 0;
                                } 
                            }
                        
                    }
                }

                else{
                    printf("\nTurma esta com o maximo de alunos");
                    continuaradd = 0;
                }
            }        
        }
    }

    while (validaadd != 0){
        printf("\n\nDisciplina nao encontrada\n");
        printf("\nDigite o codigo da disciplina: ");
        scanf("%ld", &auxcodigo);
        getchar();
        for(i = 0; i < 5; i++){
            if(disciplina[i].codigo == auxcodigo){
                validaadd = 0;
                while (continuaradd != 0){
                    if(alunosmatriculados[i] < 10){
                        printf("Digite a matricula do aluno");
                        scanf("%ld", &auxmatricula)
                    }

                    else{
                        printf("\nTurma esta com o maximo de alunos");
                        continuaradd = 0;
                    }
                }            
            }
        }
    }
}


void exibirDisciplina(Escola *escola, Disciplina *disciplina, int alunosmatriculados){

printf("\n\nDigite o codigo da disciplina: ");
scanf("%ld", &auxcodigo);
getchar();
int validaexibir = 1;

    for(i = 0; i < 5; i++ ){
        if(disciplina[i].codigo == auxcodigo){
            validaexibir = 0;
            printf("\nCodigo da disciplina: %ld" , disciplina[i].codigo);
            printf("\nNome da Disciplina: %s", disciplina[i].nomeDisciplina);
            printf("\nNome do Professor: %s %s", disciplina[i].professor.nome, disciplina[i].professor.sobrenome);
            int contador = i;
            for(i = 0; i < alunosmatriculados[contador]; i++ ){
                printf("\nAluno %i\n", i);
                printf("Nome: %s", disciplina[contador].aluno[i].nome);
                printf("\nMatricula: %ld", disciplina[contador].aluno[i].matricula);
            }
            printf("\n");
            
        }
            while (validaexibir != 0){
                printf("\n\nDisciplina nao encontrada\n");
                printf("\nDigite o codigo da disciplina: ");
                scanf("%ld", &auxcodigo);
                getchar();
                for(i = 0; i < 5; i++){
                    if(disciplina[i].codigo == auxcodigo){
                        validaexibir = 0;
                        printf("\nCodigo da disciplina: %ld" , disciplina[i].codigo);
                        printf("\nNome da Disciplina: %s", disciplina[i].nomeDisciplina);
                        printf("\nNome do Professor: %s %s", disciplina[i].professor.nome, disciplina[i].professor.sobrenome);
                       int contador = i;
                        for(i = 0; i < alunosmatriculados[contador]; i++ ){
                            printf("\nAluno %i\n", i);
                            printf("Nome: %s", disciplina[contador].aluno[i].nome);
                            printf("\nMatricula: %ld", disciplina[contador].aluno[i].matricula);
                        }
                        printf("\n");
                    }
                }

            }
    }



}