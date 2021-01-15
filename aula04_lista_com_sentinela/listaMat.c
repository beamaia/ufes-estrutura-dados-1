#include <stdio.h>
#include <stdlib.h>
#include "listaMat.h"
#include "matriz.h"

typedef struct celula Celula;
struct celula {
    Matriz* matriz;
    Celula* prox;
};

struct lista {
    Celula* prim,
          * ult;
};

// Lista* inicializaLista (void) {
//     Lista* lista = (Lista*) malloc (sizeof(Lista));
//     lista->prim = lista->ult = NULL;
// } 

// void insere (Matriz* matriz, Lista* lista) {
//     Celula* novaCelula = (Celula*) malloc (sizeof(Celula));
    
//     novaCelula->matriz = matriz;
//     novaCelula->prox = lista->prim;
//     lista->prim = novaCelula;

//     // Se a lista estiver vazia anteriormente
//     if (lista->ult == NULL) {
//         lista->ult = novaCelula;
//     }
// }

// Matriz* retira (int posicao, Lista* lista) {
//     //Posicao inicia em 0.

//     Matriz* matriz_aux;
//     Celula* aux, * anterior;
//     int aux_pos;

//     aux = lista->prim;
//     anterior = NULL;
//     aux_pos = 0;

//     // Quando aux_pos == posicao, aux comecera com o item que queremos remover
//     // Quando aux == NULL, a lista eh vazia 
//     while (aux != NULL && (aux_pos != posicao)) {
//         anterior = aux;
//         aux = aux->prox;
//         aux_pos++;
//     }

//     // Retorna NULL caso a lista eh vazia
//     if(aux == NULL) {
//         return NULL;
//     }
    
//     // Matriz que iremos retirar, salvando para retornar depois
//     matriz_aux = aux->matriz;

//     if (aux == lista->prim && aux == lista->ult) {
//         // Caso a matriz eh a unica da lista
//         lista->prim = lista->ult = NULL;
//     } else if (aux == lista->prim) {
//         // Caso a matriz eh o primeiro da lista
//         lista->prim = aux->prox;

//     } else if (aux == lista->ult) {
//         // Caso a matriz eh a ultima da lista
//         lista->ult = anterior;
//         lista->ult->prox = NULL; 
//     } else {
//         // Caso a matriz esteja no meio da lista
//         anterior->prox = aux->prox;
//     }
    
//     free(aux);

//     return matriz_aux;
// }

// /*
//  * Imprime os elementos da lista
//  * Input: Lista*
//  * Output: void
//  */
// void imprimeLista (Lista* lista) {
//     Celula* aux;

//     for (aux = lista->prim; aux != NULL; aux = aux->prox) {
//         imprimeMatriz(aux->matriz);
//         printf("\n\n");
//     }
// }

// /*
//  * Libera a memoria alaoca para a lista (nao as matrizes)
//  * Input: Lista*
//  * Output: void
//  */
// void liberaLista (Lista* lista) {
//     Celula* aux1,* aux2;
    
//     aux1 = lista->prim;

//     while (aux1 != NULL) {
//         aux2 = aux1->prox;
//         free(aux1);
//         aux1 = aux2;
//     }

//     free(lista);
// }