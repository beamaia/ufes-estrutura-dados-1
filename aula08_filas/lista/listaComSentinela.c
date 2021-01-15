#include <stdio.h>
#include <stdlib.h>
#include "listaComSentinela.h"
#include "aluno.h"

typedef struct celula Celula;
struct celula {
    Aluno* aluno;
    Celula* prox;
};

struct lista {
    Celula* prim,
          * ult;
};

Lista* inicializaLista (void) {
    Lista* lista = (Lista*) malloc (sizeof(Lista));
    lista->prim = lista->ult = NULL;

    return lista;
} 

void insereLista (Aluno* al, Lista* lista) {
    Celula* novaCelula = (Celula*) malloc (sizeof(Celula));
    
    novaCelula->aluno = al;
    novaCelula->prox = lista->prim;
    lista->prim = novaCelula;

    // Se a lista estiver vazia anteriormente
    if (lista->ult == NULL) {
        lista->ult = novaCelula;
    }
}

void insereListaUlt (Lista* l, Aluno* al) {
    Celula* nova = (Celula*) malloc (sizeof(Celula));

    nova->aluno = al;
    nova->prox = NULL;

    if (l->ult == NULL) {
        l->prim = l->ult = nova;
        return;
    }

    l->ult->prox = nova;
    l->ult = nova;
}

Aluno* retiraPosicao (Lista* lista, int posicao) {
    //Posicao inicia em 0.

    Aluno* aluno_aux;
    Celula* aux, * anterior;
    int aux_pos = 0;

    aux = lista->prim;
    anterior = NULL;

    // Quando aux_pos == posicao, aux comecera com o item que queremos remover
    // Quando aux == NULL, a lista eh vazia 
    while (aux != NULL && (aux_pos != posicao)) {
        anterior = aux;
        aux = aux->prox;
        aux_pos++;
    }

    // Retorna NULL caso a lista eh vazia
    if(aux == NULL) {
        printf("Lista vazia ou aluno não encontrado!\n");
        return NULL;
    }
    
    // Matriz que iremos retirar, salvando para retornar depois
    aluno_aux = aux->aluno;

    if (aux == lista->prim && aux == lista->ult) {
        // Caso a matriz eh a unica da lista
        lista->prim = lista->ult = NULL;
    } else if (aux == lista->prim) {
        // Caso a matriz eh o primeiro da lista
        lista->prim = aux->prox;

    } else if (aux == lista->ult) {
        // Caso a matriz eh a ultima da lista
        lista->ult = anterior;
        lista->ult->prox = NULL; 
    } else {
        // Caso a matriz esteja no meio da lista
        anterior->prox = aux->prox;
    }
    
    free(aux);

    return aluno_aux;
}

void imprimeLista (Lista* lista) {
    Celula* aux;

    for (aux = lista->prim; aux != NULL; aux = aux->prox) {
        imprimeAluno(aux->aluno);
    }
}

void destroiLista (Lista* lista) {
    Celula* aux1,* aux2;
    
    aux1 = lista->prim;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        free(aux1);
        aux1 = aux2;
    }

    free(lista);
}