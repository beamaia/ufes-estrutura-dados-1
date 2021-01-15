#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "abb.h"
#include "aluno.h"

struct arvoreBinaria {
    Aluno* aluno;
    Arv* esq;
    Arv* dir;
};
 
Arv* abbCria (void) {
    return NULL;
}

int arvVazia (Arv* a) {
    return a == NULL;
}

Arv* abbInsere (Arv* a, Aluno* al) {
    if (arvVazia(a)) {
        a = (Arv*) malloc (sizeof(Arv));
        a->aluno = al;
        a->esq = a->dir = NULL;
    } else {
        int matAluno = getMatricula(al);
        int matAlunoArv = getMatricula(a->aluno);

        if (matAluno < matAlunoArv) {
            a->esq = abbInsere(a->esq, al);
        } else {
            a->dir = abbInsere(a->dir, al);
        }
    }

    return a;
}

Arv* abbRetira (Arv* a, int mat) {
    if (arvVazia(a)) {
        return NULL;
    } 

    int matAlunoArv = getMatricula(a->aluno);

    if (matAlunoArv > mat) {
        a->esq = abbRetira(a->esq, mat);
    } else if (matAlunoArv < mat) {
        a->dir = abbRetira(a->dir, mat);
    } 

    // Achou o aluno
    else {
        // Se eh um no folha
        if (arvVazia(a->esq) && arvVazia(a->dir)) {
            free(a);
            a = NULL;
        } 

        // Se eh um no com um filho (pode ser um filho a esquerda ou a direita)
        else if (arvVazia(a->esq)) {
            Arv* t = a;
            a = a->dir;
            free(t);
        } else if (arvVazia(a->dir)) {
            Arv* t = a;
            a = a->esq;
            free(t);
        } 

        // Se eh um no com dois filhos
        else {
            Arv* f = a->esq;

            while (!arvVazia(f->dir)) {
                f = f->dir;
            }

            Aluno* t = a->aluno;
            a->aluno = f->aluno;
            f->aluno = t;

            a->esq = abbRetira(a->esq, mat);
        }
    }

    return a;
}

Arv* abbBusca (Arv* a, int chave) {
    if (arvVazia(a)) {
        return NULL;
    } 
    
    int matricula = getMatricula(a->aluno);

    if (matricula > chave) {
        return abbBusca(a->esq, chave);
    } else if (matricula < chave) {
        return abbBusca(a->dir, chave);
    } else {
        return a;
    }
}

void abbImprime (Arv* a) {
    if (!arvVazia(a)) {
        abbImprime(a->esq);
        imprimeAluno(a->aluno);
        abbImprime(a->dir);
    }
}

void arvImprimeTextual (Arv* a) {
    printf("<");

    if (!arvVazia(a)) {
        printf(" %s ", getNome(a->aluno));
        arvImprimeTextual(a->esq);
        arvImprimeTextual(a->dir);
    }

    printf("> ");
}

int arvPertence (Arv* a, char* nome) {
    if (arvVazia(a)) {
        return 0;
    } else {
        return (strcmp(getNome(a->aluno), nome) == 0) || arvPertence(a->esq, nome) || arvPertence(a->dir, nome);
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
}

void arvLibera (Arv* a) {
    if (!arvVazia(a)) {
        arvLibera(a->esq);
        arvLibera(a->dir);
        free(a);
    }
}