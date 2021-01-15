#ifndef LISTA_SENTINELA_H
#define LISTA_SENTINELA_H
#include "aluno.h"


typedef struct lista Lista;

Lista* inicializaLista (void); 
void insereLista (Aluno* al, Lista* lista);
void insereListaUlt (Lista* l, Aluno* al);
Aluno* retiraPosicao (Lista* lista, int posicao);
void imprimeLista (Lista* lista);
void destroiLista (Lista* lista);

#endif