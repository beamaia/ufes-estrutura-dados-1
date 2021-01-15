#ifndef ARV_BIN_H
#define ARV_BIN_H
#include <stdio.h>
#include "aluno.h"

typedef struct arvoreBinaria Arv;

/*
 * Cria uma arvore vazia
 * Input: void
 * Output: Arv* (NULL)
 */ 
Arv* abbCria (void);

/*
 * Verifica se a arvore esta vazia
 * Input: Arv*
 * Output: int
 */ 
int arvVazia (Arv* a);

/*
 * Insere um aluno na arvore
 * Input: Arv*, Aluno*
 * Output: Arv* 
 */ 
Arv* abbInsere (Arv* a, Aluno* al);

/*
 * Retira um aluno da arvore referente a um numero de matricula
 * Input: Arv*, int
 * Output: Arv* 
 */ 
Arv* abbRetira (Arv* a, int mat);

/*
 * Busca por um aluno dado um numero de matricula
 * Input: Arv*, int
 * Output: Arv* 
 */ 
Arv* abbBusca (Arv* a, int chave);

/*
 * Imprime as informacoes dos alunos na arvore
 * Input: Arv*
 * Output: void 
 */ 
void abbImprime (Arv* a);

/*
 * Imprime a arvore em notacao textual
 * Input: Arv*
 * Output: void 
 */
void arvImprimeTextual (Arv* a);

/*
 * Verifica se um aluno identificado por "nome" pertence a arvore
 * Input: Arv*, char*
 * Output: int
 */
int arvPertence (Arv* a, char* nome);

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

/*
 * Libera os nos da arvore
 * Input: Arv*
 * Output: Arv*
 */
void arvLibera (Arv* a);

#endif