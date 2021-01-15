#ifndef LISTA_DUPLAMENTE_H
#define LISTA_DUPLAMENTE_H

#include "jogos.h"

/*
 * Estrutura de lista duplamente encadeada
 */
typedef struct lista Lista;

/*
 * Inicializa a lista vazia
 * input: void
 * output: Lista* 
 */ 
Lista* inicializaLista (void);

/*
 * Insere um jogo na lista
 * input: Lista*, Jogo*
 * output: Lista*
 */ 
Lista* insereLista(Lista*, Jogo*);

/*
 * Imprime todos os elementos da lista
 * input: Lista*
 * output: void
 */ 
void imprimeLista (Lista*);

/*
 * Retira um elemento da lista e retorna a lista sem esse elemento
 * input: Lista*, int
 * output: Lista*
 */ 
Lista* retiraLista (Lista*, int);

/*
 * Libera as listas
 * input: Lista*
 * output: void
 */ 
void liberaLista (Lista* lista);

#endif