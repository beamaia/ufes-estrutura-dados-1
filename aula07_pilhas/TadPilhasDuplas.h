#ifndef PILHAS_DUPLAS_H
#define PILHAS_DUPLAS_H
#include "aluno.h"

typedef struct tipoPilhaDupla TipoPilhaDupla;

/* 
 * Inicializa a pilha, o topo e a base de cada parte da pilha
 * Input: void
 * Output: TipoPilha*
 */
TipoPilhaDupla* inicializaPilhaDupla (void);

/* 
 * Adiciona um item para a pilha especificada. 
 * Pilha = 1, adiciona a primeira pilha 
 * Pilha = 2, adiciona a segunda pilha
 * Input: TipoPilhaDupla*, Aluno*, int
 * Output: void
 */
void push (TipoPilhaDupla* p, Aluno* al, int pilha);

/* 
 * Retira um item da pilha especificada. 
 * Pilha = 1, retira a primeira pilha 
 * Pilha = 2, retira a segunda pilha
 * Input: TipoPilhaDupla*, int
 * Output: Aluno*
 */
Aluno* pop (TipoPilhaDupla* p, int pilha);

/* 
 * Imprime uma lista especificada. 
 * Pilha = 1, imprime a primeira pilha 
 * Pilha = 2, imprime a segunda pilha
 * Input: TipoPilhaDupla*, int
 * Output: void
 */
void imprimePilhaEspecifica (TipoPilhaDupla* p, int pilha);

/* 
 * Imprime as duas pilhas
 * Input: TipoPilhaDupla*
 * Output: void
 */
void imprime (TipoPilhaDupla* p);

/* 
 * Destroi a pilha
 * Input: TipoPilhaDupla*
 * Output: void
 */
void destroi (TipoPilhaDupla* p);

#endif