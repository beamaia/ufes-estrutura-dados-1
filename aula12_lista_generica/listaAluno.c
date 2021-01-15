#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "aluno.h"
#include "listagen.h"
#include "listaAluno.h"

struct cr {
    float CR; 
    int qtd;
};

static int comparacaoMat (void* aluno1, void* mat) {
    Aluno* a1 = (Aluno*) aluno1;
    int* matricula = (int*) mat;

    if (getMatricula(a1) == *matricula)
        return 0;
    
    return 1;
}

static int imprime (void* aluno, void* dado) {
    imprimeAluno(aluno);

    return 1;
}

static int acumula (void* aluno, void* dado) {
    struct cr* acumulado = (struct cr*) dado;

    acumulado->CR += getCR((Aluno*) aluno);
    acumulado->qtd++;

    return 1;
}

ListaGen* retiraAluno (ListaGen* lista, int matricula) {
    return retiraLista (lista, comparacaoMat, &matricula);
}

int pertenceAluno (ListaGen* lista, int matricula) {
    return percorreLista(lista, comparacaoMat, &matricula);
}

void imprimeListaAlunos (ListaGen* lista) {
    percorreLista(lista, imprime, NULL);
}

float mediaTurma (ListaGen* lista) {
    struct cr* acumulado = (struct cr*) malloc(sizeof (struct cr));
    acumulado->CR = 0;
    acumulado->qtd = 0;

    percorreLista(lista, acumula, acumulado);

    float media = (float) (acumulado->CR/acumulado->qtd);
    
    free(acumulado);
    
    return media;
    
}