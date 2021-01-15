#ifndef ARV_H
#define ARV_H
#include <stdio.h>
#include "aluno.h"

typedef struct arv Arv;

/*
 * Inicializa uma arvore vazia
 * Input: void
 * Output: Arv*
 */
Arv* arvCriaVazia (void);

/*
 * Inicializa uma arvore nao vazia
 * Input: Aluno*, Arv*, Arv*
 * Output: Arv*
 */
Arv* arvCria (Aluno *al, Arv* e, Arv* d);

/*
 * Libera os nos da arvore
 * Input: Arv*
 * Output: Arv*
 */
Arv* arvLibera (Arv* a);

/*
 * Verifica se a arvore esta vazia
 * Input: Arv*
 * Output: int
 */
int arvVazia (Arv* a);

/*
 * Verifica se um aluno identificado por "nome" pertence a arvore
 * Input: Arv*, char*
 * Output: int
 */
int arvPertence (Arv* a, char* nome);


/*
 * Imprime os alunos da árvore
 * Input: Arv*
 * Output: void
 */
void arvImprime (Arv* a);

/*
 * Verifica a altura da arvore
 * Input: Arv*
 * Output: int
 */
int altura (Arv*a);

/*
 * Verifica a quantidade de folhas da arvore
 * Input: Arv*
 * Output: int
 */
int folhas (Arv* a);

/*
 * Verifica a ocorrencia de alunos como um mesmo nome na arvore
 * Input: Arv*, char*
 * Output: int
 */
int ocorrencias (Arv* a, char* nome);

#endif