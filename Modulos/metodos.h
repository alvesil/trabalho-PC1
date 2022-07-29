#ifndef METODOS_H
#define METODOS_H

#include <stdio.h>
#include <time.h>
#include <string.h>

typedef struct
{
    char nome[20];
    char sobrenome[50];
    int nacionalidade;
    char cpf[15];
    char rg[8];
    char passaporte[20];
    char paisOrigem[20];
    char dt_nasc[11];
    int pcd;
    char laudo[10];
    char cep[9];
    int proforaluno;
    int matricula;
    char pis [12] ;

} Pessoa;

typedef struct
{
    long int codigo;
    char nomeDisciplina[20];
    int cargaHoraria;
    int quantidadealuno;
    Pessoa professor;
    Pessoa aluno[10];

} Disciplina;

typedef struct
{
    Pessoa alunos[30];
    Pessoa professores[5];
    Disciplina disciplina[5];

} Escola;

Escola escola;

void clr();

void mostraPessoa(Escola *escola, int contadoraluno, int contadorprofessor);

void cadastraPessoa(Escola *escola, int contadoraluno, int contadorprofessor);

void alterardadopessoa(Escola *escola, int contadoraluno, int contadorprofessor);


#endif