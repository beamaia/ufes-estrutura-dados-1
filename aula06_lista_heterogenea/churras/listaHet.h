#ifndef LISTA_HET_H
#define LISTA_HET_H
#include "professor.h"
#include "aluno.h"

typedef struct listaHet ListaHet;

/*
 * Inicializa a lista heterogenea vazia
 * Input: void
 * Output: ListaHet*
 */ 
ListaHet* inicializaLista (void);

/*
 * Insere aluno na lista heterogenea
 * Input: ListaHet*, Aluno*
 * Output: void
 */
void insereAluno (ListaHet* lista, Aluno* al);

/*
 * Insere professor na lista heterogenea
 * Input: ListaHet*, Professor*
 * Output: void
 */
void insereProfessor (ListaHet* lista, Professor* prof);

/*
 * Imprime aula
 * Input: ListaHet*
 * Output: void
 */
void imprimeListaHet (ListaHet* lista);

/*
 * Calcula valor do churrasco
 * Input: ListaHet*
 * Output: float
 */
float valorChurrasco (ListaHet* lista);

/*
 * Libera memoria alocada
 * Input: ListaHet*
 * Output: void
 */
void destroLista (ListaHet* lista);
#endif