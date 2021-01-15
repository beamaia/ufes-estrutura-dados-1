#ifndef PALAVRAS_H
#define PALAVRAS_H

typedef struct palavra Palavra;

/*
 * Inicializa a palavra
 * Input: char*
 * Output: Palavra*
 */ 
Palavra* inicPalavra (char* str);

/* 
 * Retorna a string da palavra
 * Input: Palavra*
 * Output: char*
 */ 
char* retornaString (Palavra* pal);

/* 
 * Atualiza n da struct palavra. Referente a ocorrencias daquela palavra
 * Input: Palavra*
 * Output: void
 */ 
void atualizaOcorrencias (Palavra* pal);

/* 
 * Retorna o numero de ocorrencias daquela palavra
 * Input: Palavra*
 * Output: int
 */ 
int retornaOcorrencias (Palavra* pal);

/*
 * Verifica se a palavra existe dentro da lista de palavras
 * Input: Palavra*, char*
 * Output: Palavra*
 */ 
Palavra* buscaPalavra (Palavra* pal, char* string);

/*
 * Insere palavra *lista* a palavra *p* 
 * Input: Palavra*, Palavra*
 * Output: Palavra*
 */ 
Palavra* inserePalavraLista (Palavra* lista, Palavra* p);

/*
 * Conta a quantidade de palavras na lista
 * Input: Palavra*
 * Output: int
 */ 
int contaPalavrasLista (Palavra* p);

/*
 * Imprime lista de palavras
 * Input: Palavra*
 * Output: void
 */ 
void imprimeLista (Palavra* pal);

/*
 * Libera memoria alocada pela lista de palavras
 * Input: Palavra*
 * Output: void
 */ 
void liberaListaPalavra (Palavra* pal);

#endif