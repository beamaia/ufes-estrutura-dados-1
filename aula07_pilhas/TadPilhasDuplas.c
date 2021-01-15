#include <stdio.h>
#include <stdlib.h>
#include "TadPilhasDuplas.h"
#include "aluno.h"
#define TAM 100

/* 
 * Estrutura com indice da base e do topo da pilha. 
 * int base: base da pilha
 * int topo: topo da pilha
 */
typedef struct{
    int base, topo;
} IndicePilha; 

/* 
 * Estrutura de pilha com duas divisoes: pilha 1 e pilha2
 * IndicePilha pilha1: indices de base e topo da primeira lista
 * IndicePilha pilha2: indices de base e topo da segunda lista
 * Alunos* aluno[TAM]: Um vetor de alunos com limite TAM 
 */
struct tipoPilhaDupla{
    IndicePilha pilha1, 
                pilha2;
    Aluno* alunos[TAM];

};

TipoPilhaDupla* inicializaPilhaDupla () {
    TipoPilhaDupla* p = (TipoPilhaDupla*) malloc (sizeof(TipoPilhaDupla));
    p->pilha1.base = 0;
    p->pilha2.base = TAM - 1;
    p->pilha1.topo = -1;
    p->pilha2.topo = TAM;

    return p;
}

void push (TipoPilhaDupla* p, Aluno* al, int pilha) {
    if (p == NULL) {
        printf("Pilha NULL\n");
        return;
    } else if (al == NULL) {
        printf("Aluno NULL\n");
        return;
    } else if (p->pilha1.topo == p->pilha2.topo || p->pilha1.topo == p->pilha2.base || p->pilha2.topo == p->pilha1.base) {
        printf("Pilha cheia!\n");
        return;
    }

    if (pilha == 1) { 
        p->pilha1.topo++;
        p->alunos[p->pilha1.topo] = al;

    } else if (pilha == 2) {  
        p->pilha2.topo--;      
        p->alunos[p->pilha2.topo] = al;
    }
}

Aluno* pop (TipoPilhaDupla* p, int pilha) {
    if (p == NULL) {
        printf("Pilha NULL\n");
        return NULL;
    }

    Aluno* al;
    if (pilha == 1) {
        if (p->pilha1.topo == -1) {
            printf("Pilha vazia!\n");
            return NULL;
        }

        al = p->alunos[p->pilha1.topo];
        p->pilha1.topo--;

    } else if (pilha == 2) {
        if (p->pilha2.topo == TAM) {
            printf("Pilha vazia!\n");
            return NULL;
        }

        al = p->alunos[p->pilha2.topo];
        p->pilha2.topo++;
    }

    
    return al;
}

void imprimePilhaEspecifica (TipoPilhaDupla* p, int pilha) {
    if (p == NULL) 
        return; 

    int i;

    if (pilha == 1) {   
        for (i = (p->pilha1.topo); i >= 0; i--) 
            imprimeAluno(p->alunos[i]);
    } else if (pilha == 2) {
        for (i = (p->pilha2.topo); i < TAM; i++) 
            imprimeAluno(p->alunos[i]);
    }   
}

void imprime (TipoPilhaDupla* p) {
    imprimePilhaEspecifica (p, 1);
    imprimePilhaEspecifica (p, 2);
}

void destroi (TipoPilhaDupla* p) {
    if (p == NULL)
        return;
    
    free(p);
}