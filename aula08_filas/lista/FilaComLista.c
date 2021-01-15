#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "listaComSentinela.h"

struct fila {
    Lista* lista;
};

// Inicializa a fila com uma lista vazia
Fila* inicializaFila (void) {
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->lista = inicializaLista();
    return f;
}

// Insere um aluno no final da lista
void insereFila (Fila* f, Aluno* al) {
    insereListaUlt(f->lista, al);
}

// Retira um aluno da posicao 0 (inicial)
Aluno* retiraFila (Fila* f) {
    return retiraPosicao (f->lista, 0);
}

void imprimeFila (Fila* f) {
    imprimeLista(f->lista);
}

void destroiFila (Fila* f) {
    destroiLista(f->lista);
    free(f);
}