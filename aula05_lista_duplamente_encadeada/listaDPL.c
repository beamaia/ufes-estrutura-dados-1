#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaDPL.h"
#include "jogos.h"

struct lista {
    Jogo* jogo;
    Lista* prox,
         * ant;
};

Lista* inicializaLista (void) {
    return NULL;
}

Lista* insereLista (Lista* lista, Jogo* jogo) {
    Lista* nova = (Lista*) malloc(sizeof(Lista));

    // Insere no inicio
    nova->jogo = jogo;
    nova->prox = lista;
    nova->ant = NULL;

    if (lista != NULL) {
        lista->ant = nova;
    }

    return nova;
}

void imprimeLista (Lista* lista) {
    Lista* aux;

    for(aux = lista; aux != NULL; aux=aux->prox) {
        apresentaJogo(aux->jogo);
    }
}

/*
 * Funcao auxiliar que busca na lista um jogo pelo seu ID e retorna uma lista que inicia com este jogo
 * input: Lista*, int
 * output: Lista*
 */ 
static Lista* busca (Lista* lista, int id) {
    Lista* aux;

    for (aux = lista; aux != NULL; aux=aux->prox) {
        if (recuperaID(aux->jogo) == id) {
            return aux;
        }
    }

    return NULL;
}

Lista* retiraLista (Lista* lista, int id){
    Lista* aux = busca(lista, id);

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

void liberaLista (Lista* lista) {
    Lista* aux1 = lista,
         * aux2;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }
}