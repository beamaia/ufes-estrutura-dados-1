#ifndef LISTA_ALUNO_H
#define LISTA_ALUNO_H
#include "listagen.h"

/*
 * Retira um aluno da lista de acordo com sua matricula
 * Input: ListaGen*, int
 * Output: ListaGen*
 */ 
ListaGen* retiraAluno (ListaGen* lista, int matricula);

/*
 * Verifica se um aluno existe na lista
 * Input: ListaGen*, int
 * Output: int
 */ 
int pertenceAluno (ListaGen* lista, int matricula);

/*
 * Imprime alunos da lista
 * Input: ListaGen*
 * Output: void
 */ 
void imprimeListaAlunos (ListaGen* lista);

/*
 * Calcula a media da turma
 * Input: ListaGen*
 * Output: float
 */ 
float mediaTurma (ListaGen* lista);

#endif