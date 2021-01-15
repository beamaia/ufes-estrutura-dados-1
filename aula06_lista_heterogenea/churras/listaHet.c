#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaHet.h"
#include "professor.h"
#include "aluno.h"

#define PROF 0
#define ALUN 1

typedef struct celula Celula;

/*
 * Estrutura de celula
 * Celula* prox
 * void* pessoa
 * int tipo
 */ 
struct celula {
    Celula* prox;
    void* pessoa;
    int tipo;
};


struct listaHet {
    Celula* prim;
    Celula* ult;
};

ListaHet* inicializaLista (void) {
    ListaHet* lista = (ListaHet*) malloc (sizeof(ListaHet));
    lista->prim = NULL;
    lista->ult = NULL;
    return lista;
}

void insereAluno (ListaHet* lista, Aluno *al) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->pessoa = al;
    nova->tipo = ALUN;
    nova->prox = lista->prim;
    lista->prim = nova;

    if (lista->ult == NULL)
        lista->ult = nova;

}

void insereProfessor (ListaHet* lista, Professor* prof) {
    Celula* nova = (Celula*) malloc(sizeof(Celula));
    nova->pessoa = prof;
    nova->tipo = PROF;
    nova->prox = lista->prim;
    lista->prim = nova;

    if (lista->ult == NULL)
        lista->ult = nova;
}

void imprimeListaHet (ListaHet* lista) {
    Celula* aux;

    for(aux = lista->prim; aux != NULL; aux = aux->prox) {
        if(aux->tipo == ALUN) {    
            printf("ALUNO: ");    
            imprimeAluno((Aluno*) aux->pessoa);
        } else if (aux->tipo == PROF) {
            printf("PROFESSOR: ");
            imprimeProfessor((Professor*) aux->pessoa);
        }
    }
}

float valorChurrasco (ListaHet* lista) {
    Celula* aux;
    float valor = 0;

    for(aux = lista->prim; aux != NULL; aux = aux->prox) {
        if(aux->tipo == ALUN) {    
            valor += 30;
        } else if (aux->tipo == PROF) {
            valor += 0.02 * retornaSalario((Professor*) aux->pessoa);
        }
    }

    return valor;
}

void destroLista (ListaHet* lista) {
    Celula* aux1,* aux2;
    aux1 = lista->prim;

    while(aux1 != NULL) {
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }

    free(lista);
}