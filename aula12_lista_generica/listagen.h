#ifndef LISTA_GEN_H
#define LISTA_GEN_H

typedef struct listagen ListaGen;

/*
 * Cria uma lista vazia
 * Input: void
 * Output: ListaGen*
 */ 
ListaGen* criaLista (void);

/*
 * Insere um item na lista
 * Input: ListaGen*, void*
 * Output: ListaGen*
 */ 
ListaGen* insereLista (ListaGen* lista, void* item);

/*
 * Retira um item da lista, apos informar uma funcao e uma chave
 * Input: ListaGen*, int (*cb)(void*, void*), void*
 * Output: ListaGen*
 */ 
ListaGen* retiraLista (ListaGen* lista, int (*cb)(void*, void*), void* chave);

/*
 * Pecorre na lista e retorna 0 caso o dado encontra se nela, encontrado atravez da funcao informada, e 1 caso contrario
 * Input: ListaGen*, int (*cb)(void*, void*), void*
 * Output: int
 */ 
int percorreLista (ListaGen* lista, int(*cb)(void*, void*), void* dado);

/*
 * Libera o espaco alocado
 * Input: ListaGen*
 * Output: void
 */ 
void liberaLista (ListaGen* lista);

#endif