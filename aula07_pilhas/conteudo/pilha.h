#ifndef PILHA_H
#define PILHA_H
#include "aluno.h"

typedef struct pilha Pilha;
Pilha* inicPilha (void);
void push (Pilha* p, Aluno* al);
Aluno* pop (Pilha* p);
void imprime (Pilha* p);
void destroi (Pilha* p);


#endif