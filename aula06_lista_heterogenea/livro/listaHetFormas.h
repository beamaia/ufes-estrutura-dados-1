#ifndef LISTA_HET_FORMAS_H
#define LISTA_HET_FORMAS_H


typedef struct celula ListaHet;

/*
 * Inicializa um lista vazia
 * Input: void
 * Output: ListaHet*
 */
ListaHet* inicializaLista (void);

/*
 * Inicializa um celula com um item Retangulo
 * Input: float, float, ListaHet*
 * Output: ListaHet*
 */
ListaHet* criaRet (float b, float h, ListaHet* lh);

/*
 * Inicializa um celula com um item Triangulo
 * Input: float, float, ListaHet*
 * Output: ListaHet*
 */
ListaHet* criaTri (float b, float h, ListaHet* lh);

/*
 * Inicializa um celula com um item Circulo
 * Input: float,  ListaHet*
 * Output: ListaHet*
 */
ListaHet* criaCir (float r, ListaHet* lh);

/*
 * Verifica a maior altura
 * Input: ListaHet*
 * Output: float
 */
float maxArea (ListaHet* lh);

/*
 * Imprime lista de formas
 * Input: ListaHet*
 * Output: void
 */
void imprimeFormas (ListaHet* lh);

/*
 * Libera memoria alocada
 * Input: ListaHet*
 * Output: void
 */
void destroiLista (ListaHet* lh);

#endif