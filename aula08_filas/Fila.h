#ifndef FILA_H
#define FILA_H
#include "aluno.h"
typedef struct fila Fila;

/* Inicializa uma fila vazia
 * Input: void
 * Output: Fila*
 */ 
Fila* inicializaFila (void);

/* Insere na fila um aluno
 * Input: Fila*, Aluno*
 * Output: void
 */ 
void insereFila (Fila* f, Aluno* al);

/* Retira o primeiro aluno da fila e retorna o aluno retirado
 * Input: Fila*
 * Output: Aluno*
 */ 
Aluno* retiraFila (Fila* f);

/* Imprime as informacoes dos alunos da fila
 * Input: Fila*
 * Output: void
 */ 
void imprimeFila (Fila* f);

/* Libera o espaco alocado pela fila
 * Input: Fila*
 * Output: voids
 */ 
void destroiFila (Fila* f);
#endif