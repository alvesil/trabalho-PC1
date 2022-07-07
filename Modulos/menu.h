#ifdef MENU_H
#define MENU_H

#include<stdio.h>
#include <stdlib.h>


#if def_WIN32
#include <Windows.h>
#else
#include <unistd.h>
#endif

int menuPessoa;
int menuDisciplina;
int contador;
int menuPrincipal;

void menu_Pessoa();
void menu_Disciplina();
void menu_Principal();

#endif