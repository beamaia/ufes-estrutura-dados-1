#ifndef LISTA_MAT
#define LISTA_MAT
#include "matriz.h"

/* 
 * Estrutura que define a lista
 * Usada em lista com sentinela
 */
typedef struct lista Lista;

/*
 * Inicialiaza o sentinela da lista
 * Input: void
 * Output: Sentinela da lista, com primeiro e ultimo campo apontando para NULL
 */
Lista* inicializaLista (void); 

/*
 * Insere uma matriz na primeira posicao da lista de matrizes
 * Input: Matriz*, Lista*
 * Output: void
 */
void insere (Matriz* matriz, Lista* lista);

/*
 * Retira uma matriz da lista de matrizes dado a posicao informad. Retorna o ítem removido.
 * A posicao eh de acordo com o indice do elemento da lista em C. O primeiro elemento esta no indice 0, 
 * logo sua posicao = 0.
 * Input: int, Lista*
 * Output: Matriz*
 */ 
Matriz* retira (int posicao, Lista* lista);

/*
 * Imprime os elementos da lista
 * Input: Lista*
 * Output: void
 */
void imprimeLista (Lista* lista);

/*
 * Libera a memoria alaoca para a lista (nao as matrizes)
 * Input: Lista*
 * Output: void
 */
void liberaLista (Lista* lista);

#endif