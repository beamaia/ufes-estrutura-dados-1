#ifndef JOGOS_H
#define JOGOS_H

/*
 * Estrutura de jogo
 */
typedef struct jogo Jogo;

/*
 * Inicializa o jogo com entradas no terminal
 * input: void
 * A funcao recebe do terminal: char* nome do jogo, char tipo, int ano, int id e float avaliacao
 * output: Jogo*
 */ 
Jogo* inicializaJogo (void);

/* 
 * Inicializa o jogo pelo cliente sem receber as entradas no terminal
 * input: char*, char, int, int, float
 * output: Jogo*
 */
Jogo* inicializaJogoCliente (char* nome, char tipo, int ano, int id, float avaliacao);

/* 
 * Retorna o numero do ID do jogo
 * input: Jogo*
 * output: int
 */
int recuperaID (Jogo*);

/* 
 * Modifica o numero do ID do jogo
 * input: Jogo*, int
 * output: void
 */
void modificaID (Jogo*, int);

/* 
 * Retorna a avaliacao do jogo
 * input: Jogo*
 * output: ifloat
 */
float recuperaAvaliacao (Jogo*);

/* 
 * Modifica a avaliacao do jogo
 * input: Jogo*, int
 * output: void
 */
void modificaAvaliacao (Jogo*, float);

/* 
 * Imprime no terminal as informacoes do jogo
 * input: Jogo*
 * output: void
 */
void apresentaJogo (Jogo*);

/* 
 * Libera o espaco alocado do jogo
 * input: Jogo*
 * output: void
 */
void liberaJogo (Jogo*);

#endif
