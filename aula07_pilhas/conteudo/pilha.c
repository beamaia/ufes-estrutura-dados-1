#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "pilha.h"
#include "aluno.h"
#define TAM 50

struct pilha {
    int topo;
    Aluno* alunos[TAM];
};

Pilha* inicPilha (void) {
    Pilha* p = (Pilha*) malloc(sizeof(Pilha));
    p->topo = 0;

    return p;
}

void push (Pilha* p, Aluno* al) {
    if (p == NULL) {
        printf("Pilha NULL\n");
        return;
    } else if (al == NULL) {
        printf("Aluno NULL\n");
        return;
    } else if (p->topo >= TAM) {
        printf("Pilha cheia!\n");
        return;
    }
    
    p->alunos[p->topo] = al;
    p->topo++;

}

Aluno* pop (Pilha* p) {
    if (p == NULL) {
        printf("Pilha NULL\n");
        return NULL;
    } else if (p->topo == 0) {
        printf("Pilha vazia!\n");
        return NULL;
    }

    Aluno* al = p->alunos[p->topo - 1];
    p->topo--;
    
    return al;
}

void imprime (Pilha* p) {
    int i;

    if (p == NULL) 
        return;
    
    for (i = (p->topo - 1); i >= 0; i--) 
        imprimeAluno(p->alunos[i]);
}

void destroi (Pilha* p) {
    if (p == NULL)
        return;
    
    free(p);
}