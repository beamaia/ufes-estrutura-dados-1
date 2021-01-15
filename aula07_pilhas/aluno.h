#ifndef ALUNO_H
#define ALUNO_H

typedef struct aluno Aluno;

/*
 * Inicializa aluno com valores fornecido pelos parametros da funcao
 * Input: int, char*, float
 * Output: Aluno*
 */
Aluno* inicializaAluno (int mat, char*  nome, float CR);

/*
 * Imprime informacoes do aluno
 * Input: Aluno*
 * Output: void
 */
void imprimeAluno (Aluno* al);

/*
 * Retorna o valor da matricula
 * Input: Aluno*
 * Output: int
 */
int getMatricula (Aluno* al);

/*
 * Retorna nome do aluno
 * Input: Aluno*
 * Output: char*
 */
char* getNome (Aluno* al);

/*
 * Retorna valor do CR do aluno
 * Input: Aluno*
 * Output: float
 */
float getCR (Aluno* al);

/*
 * Libera memoria alocada 
 * Input: Aluno*
 * Output: void 
 */
void destroiAluno (Aluno* al);

#endif