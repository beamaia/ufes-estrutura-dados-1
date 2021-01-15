#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "palavra.h"

struct palavra {
    char* string;
    int n;
    Palavra* prox;
};

Palavra* inicPalavra (char* str) {
    Palavra* pal = (Palavra*) malloc (sizeof(Palavra));
    pal->string = strdup(str);
    pal->n = 0;
    pal->prox = NULL;
    return pal;
}

char* retornaString (Palavra* pal) {
    return pal->string;
}

void atualizaOcorrencias (Palavra* pal) {
    pal->n++;
}

int retornaOcorrencias (Palavra* pal) {
    return pal->n;
}

Palavra* buscaPalavra (Palavra* pal, char* string) {
    Palavra* aux;
    
    for (aux = pal; aux != NULL; aux = aux->prox) {
        if (strcmp (string, aux->string) == 0)
            return aux;
    }

    return NULL;
}

Palavra* inserePalavraLista (Palavra* lista, Palavra* p) {
    p->prox = lista;
    return p;
}

int contaPalavrasLista (Palavra* p) {
    Palavra* aux;
    int qtd = 0;

    for (aux = p; aux != NULL; aux = aux->prox) {
        qtd++;
    }

    return qtd;
}

void imprimeLista (Palavra* pal) {
    Palavra* aux;

    for (aux = pal; aux != NULL; aux = aux->prox) {
        printf("String: %s - Ocorrencia: %d \n", aux->string, aux->n);
    }
}

void liberaListaPalavra (Palavra* pal) {
    Palavra* aux1 = pal;
    Palavra* aux2;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        free(aux1->string);
        free(aux1);
        aux1 = aux2;
    }
}