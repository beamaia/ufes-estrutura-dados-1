#ifndef PROFESSOR_H
#define PROFESSOR_H

typedef struct professor Professor;

/*
 * Inicializa professor com valores fornecido pelos parametros da funcao
 * Input: int, char*, float
 * Output: Professor*
 */
Professor* inicializaProfessor(int siape, char* nome, float salario);

/*
 * Imprime informacoes do professor
 * Input: Professor*
 * Output: void
 */
void imprimeProfessor (Professor* prof);

/*
 * Retorna o valor do siape
 * Input: Professor*
 * Output: int
 */
int retornaSiape (Professor* prof);

/*
 * Retorna nome do professor
 * Input: Professor*
 * Output: char*
 */
char* retornaNomeProfessor (Professor* prof);

/*
 * Retorna valor do salario do professor
 * Input: Professor*
 * Output: float
 */
float retornaSalario (Professor* prof);

/*
 * Libera memoria alocada 
 * Input: Professor*
 * Output: void 
 */
void destroiProfessor (Professor* prof);

#endif