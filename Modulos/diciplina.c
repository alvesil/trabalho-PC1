#include<string.h>
#include "metodos.h"
#include "diciplina.h"
#include "menu.h"

void menu_Disciplina();

char auxnomeDiciplina [100];
long int auxpis;


int i, valida = 1, auxcargahoraria;
long int auxcodigo;

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

    disciplina[contadordisciplina].professor = escola->professores[i];
    disciplina[contadordisciplina].cargaHoraria = auxcargahoraria;
    strcpy(disciplina[contadordisciplina].nome, auxnomeDiciplina);
    disciplina[contadordisciplina].codigo = auxcodigo;
    contadordisciplina++;
    

    printf("\n\nDisciplina cadastrada com sucesso\n\n");

    
}

void mudarprofessor(Escola *escola, Disciplina *disciplina, int contadordisciplina){
    
    valida = 1;
    int mudar_professor;

    printf("digite o cadigo da materia: ");
    scanf("%ld",&auxcodigo);
    for(i = 0; i < 5; i++ ){
        if(disciplina[i].codigo == auxcodigo){
            int valida2 = 1;
            valida = 0;
            mudar_professor = i;
            printf("\nDigite o numero pis do novo professor: "\n);
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
    while (validar != 0)
    {
        printf("\nMateria nao encontrada\n");
        printf("digite o cadigo da materia: ");
    scanf("%ld",&auxcodigo);
    for(i = 0; i < 5; i++ ){
        if(disciplina[i].codigo == auxcodigo){

        }
    }
    }
    
}

void addAluno(Escola *escola, Disciplina *diciplinas){



}