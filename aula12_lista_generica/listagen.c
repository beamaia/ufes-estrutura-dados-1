#include <stdio.h>
#include <stdlib.h>
#include "listagen.h"

struct listagen {
    void* item;
    ListaGen* prox;
    ListaGen* ant;
};

ListaGen* criaLista (void) {
    return NULL;
}

ListaGen* insereLista (ListaGen* lista, void* item) {
    ListaGen* nova = (ListaGen*) malloc (sizeof(ListaGen));
    nova->item = item;
    nova->prox = lista;
    nova->ant = NULL;

    if (lista != NULL) 
        lista->ant = nova;

    return nova;
}

static ListaGen* busca (ListaGen* lista, int (*cb)(void*, void*), void* chave) {
    ListaGen* aux;

    for (aux = lista; aux != NULL; aux=aux->prox) {
        if (cb(aux->item, chave) == 0) {
            return aux;
        }
    }

    return NULL; 
}

ListaGen* retiraLista (ListaGen* lista, int (*cb)(void*, void*), void* chave) {
   ListaGen* aux = busca(lista, cb, chave);

    // Caso nao precisa retirar algo
    if (aux == NULL) {
        return lista;
    }
    
    if (lista == aux) {
    // Quando o primeiro elemento eh o q precisa ser retirado
        lista = aux->prox;
    } else {
    // Quando eh outro elemento que precisa ser retirado
        aux->ant->prox = aux->prox;
    }

    // Se o elemento que precisa ser retirado eh o ultimo
    if (aux->prox != NULL) {
        aux->prox->ant = aux->ant;
    }
    
    // Libera a celula
    free(aux);
    
    return lista;
}

int percorreLista (ListaGen* lista, int(*cb)(void*, void*), void* dado) {
    ListaGen* p;

    for (p = lista; p != NULL; p = p->prox) {
        int r = cb(p->item, dado);
        if (r == 0)
            return r;
    }

    return 1;
}

void liberaLista (ListaGen* lista) {
    ListaGen* p = lista;
    ListaGen* t;

    while (p != NULL) {
        t = p->prox;
        free(p);
        p = t;
    }
}