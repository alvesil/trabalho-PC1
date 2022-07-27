#ifndef DICIPLINA_H
#define DICIPLINA_H

#include <stdio.h>
#include <time.h>
#include <string.h>
#include "metodos.h"
#include "menu.h"

Disciplina disciplina;

void cadastrarDisiplina(Escola *escolas, Disciplina *disciplina, int contadordiciplina);
void mudarprofessor(Escola *escola, Disciplina *disciplina, int contadordisciplina);
void exibirDisciplina(Escola *escola, Disciplina *disciplina);
void addAluno(Escola *escola, Disciplina *disciplina);
void excluirAluno (Escola *escola, Disciplina *disciplina);

#endif