#include <stdio.h>
#include <stdlib.h>
#include "Fila.h"
#include "aluno.h"
#define TAM 10

/* Estrutura de fila com vetor
 * int ini: indice de onde inicia a fila
 * int qtd: a quantidade de alunos na fila
 * Aluno* alunos[TAM]: vetor de alunos
 */ 
struct fila {
    int ini;
    int qtd;
    Aluno* alunos [TAM];
};

// Inicializa a fila com ini = 0 e qtd = 0
Fila* inicializaFila (void) {
    Fila* f = (Fila*) malloc (sizeof(Fila));
    f->ini = 0;
    f->qtd = 0;

    return f;
}

// Insere no final da lista e atualiza fila->qtd
void insereFila (Fila* f, Aluno* al) {
    if (f == NULL || f->qtd >= TAM) {
        printf("Pilha invalida ou cheia!\n");
        return;
    }

    int pos = (f->ini + f->qtd) % TAM;

    f->alunos[pos] = al;
    f->qtd++;
}

// Retira o primeiro aluno da fila e atualiza fila->qtd
Aluno* retiraFila (Fila* f) {
    if (f == NULL || f->qtd == 0) {
        printf("Pilha invalida ou vazia!\n");
        return NULL;
    }
   
    Aluno* al = f->alunos[f->ini];
    f->ini = (f->ini + 1) % TAM;
    f->qtd--;

    return al;
}

void imprimeFila (Fila* f) {
    int pos = 0;

    if (f == NULL)
        return;

    for (int i = 0; i < f->qtd; i++) {
        pos = (f->ini + i) % TAM;
        imprimeAluno(f->alunos[pos]);
    }
}

void destroiFila (Fila* f) {
    if (f == NULL)
        return;
    
    free(f);
}