#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "arvAluno.h"
#include "aluno.h"

struct arv {
    Aluno* aluno;
    struct arv* esq;
    struct arv* dir;
};

Arv* arvCriaVazia (void) {
    return NULL;
}

Arv* arvCria (Aluno *al, Arv* e, Arv* d) {
    Arv* p = (Arv*) malloc (sizeof(Arv));
    p->aluno = al;
    p->esq = e;
    p->dir = d;

    return p;
}

Arv* arvLibera (Arv* a) {
    if (!arvVazia(a)) {
        arvLibera(a->esq);
        arvLibera(a->dir);
        free(a);
    }
}

int arvVazia (Arv* a) {
    return a == NULL;
}

int arvPertence (Arv* a, char* nome) {
    if (arvVazia(a)) {
        return 0;
    } else {
        return (strcmp(getNome(a->aluno), nome) == 0) || arvPertence(a->esq, nome) || arvPertence(a->dir, nome);
    }
}

void arvImprime (Arv* a) {
    if (!arvVazia (a)) {
        imprimeAluno(a->aluno);
        arvImprime(a->esq);
        arvImprime(a->dir);
    }
}

static int max2 (int a, int b) {
    return (a > b) ? a : b;
}

int altura (Arv*a) {
    if (arvVazia(a)) {
        return -1;
    } else {
        return 1 + max2 (altura(a->esq), altura(a->dir));
    }
}

int folhas (Arv* a) {
    if (arvVazia(a))
        return 0;
    else if (!arvVazia(a->esq) && !arvVazia(a->dir)) {
        return folhas(a->esq) + folhas(a->dir);
    } else if (!arvVazia(a->esq)) {
        return folhas(a->esq);
    } else if (!arvVazia(a->dir)) {
        return folhas(a->dir);
    } else if (arvVazia(a->esq) && arvVazia(a->dir)) {
        return 1;
    }
}

int ocorrencias (Arv* a, char* nome) {
    if (arvVazia(a)) {
        return 0;
    } else if (strcmp(getNome(a->aluno), nome) == 0) {
        return (1 + ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome));
    }
    
    return ocorrencias(a->esq, nome) + ocorrencias(a->dir, nome);
}
