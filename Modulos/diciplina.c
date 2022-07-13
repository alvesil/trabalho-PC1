#include<string.h>
#include "metodos.h"
#include "diciplina.h"


char auxnomeDiciplina [100];
char auxpis [14];


int i, valida = 1, auxcargahoraria;
long int auxcodigo;

void cadastrarDisiplina(Escola *escola,Disciplina *disciplina, int contadordiciplina){

printf("Digite o nome da diciplina: ");
scanf("%s", auxnomeDiciplina);
getchar();
printf("\nDigite o codigoda disciplina: ");
scanf("%ld", &auxcodigo);
getchar();
printf("\nDigite a caga horaria da disciplina: ");
scanf("%i", &auxcargahoraria);
getchar();

do{

    printf("\nDigite o PIS do professor: ");
    scanf("%s", auxpis);
    getchar();
    for(i = 0; i < 5; i++){
        valida = strcmp(escola->professores[i].pis, auxpis);
    }

}
while (valida != 0)
{
    printf("\nProfessore nao cadastrado\n");
    printf("\nDigite o PIS do professor: ");
    scanf("%s", auxpis);
    getchar();
    for(i = 0; i < 5; i++){
        valida = strcmp(escola->professores[i].pis, auxpis);
    }
}

        disciplina[contadordiciplina]->professor = escola->professores[i];
        disciplina[contadordiciplina].cargaHoraria = auxcargahoraria;
        disciplina[contadordiciplina].nome = auxnomeDiciplina;
        disciplina[contadordiciplina].codigo = auxcodigo;
        contadordiciplina++;

        printf("\n\nDisciplina cadastrada com sucesso\n\n");

    
}

/* void mudarprofessor(){
    printf("digite o cadigo da materia: ");
    scanf("%ld",&auxcodigo);
    for(i = 0; i < 5; i++ ){
        if(diciplinas->codigo[i] == auxcodigo){
            printf("Digite o pis do novo professor: ");
            scanf("%s", &auxpis);
            getchar();
            for(i = 0; i < 5; i++){
                valida = strcmp(professores[i]->professores->pis, auxpis);
                if(valida != 0){
                      diciplinas->professor = professores->professores[i];
                 }
                else{
                     printf("Professor não cadastrado");
                 }

            }
        }
    }
}

void addAluno(Escola *escola, Disciplina *diciplinas){



} */