#ifndef MENU_H
#define MEUNU_H

#include <stdio.h>
#include <time.h>
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
    int matricula;
    char pis;

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

Escola escola;

void clr();

void mostraPessoa(Escola *escola, int contador);

int cadastraPessoa(Escola *escola, int contador);

#endif