#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "listaHetFormas.h"
#include "formas.h"
#define RET 0
#define TRI 1
#define CIR 2

struct celula {
    int tipo;
    void* forma;
    ListaHet* prox;
};

ListaHet* inicializaLista (void) {
    ListaHet* lista = (ListaHet*) malloc (sizeof(ListaHet));

    lista->tipo = -1;
    lista->forma = NULL;
    lista->prox = NULL;

    return lista;
}

ListaHet* criaRet (float b, float h, ListaHet* lh) {
    Retangulo* r = inicializaRetangulo(b, h);

    ListaHet*  lista = (ListaHet*) malloc(sizeof(ListaHet));
    lista->tipo = RET;
    lista->forma = r;

    lista->prox = lh;
    lh = lista;

    return lista;
}

ListaHet* criaTri (float b, float h, ListaHet* lh) {
    Triangulo* t = inicializaTriangulo(b, h);

    ListaHet*  lista = (ListaHet*) malloc(sizeof(ListaHet));
    lista->tipo = TRI;
    lista->forma = t;

    lista->prox = lh;
    lh = lista;

    return lista;
}

ListaHet* criaCir (float r, ListaHet* lh) {
    Circulo* c = inicializaCirculo(r);

    ListaHet*  lista = (ListaHet*) malloc(sizeof(ListaHet));
    lista->tipo = CIR;
    lista->forma = c;

    lista->prox = lh;
    lh = lista;

    return lista;   
}

static float areaForma (ListaHet* lh) {
    float area;

    switch (lh->tipo) {
        case RET: area = retornaAreaRetangulo((Retangulo*)lh->forma);
                  break;
        case TRI: area = retornaAreaTriangulo((Triangulo*) lh->forma);
                  break;
        case CIR: area = retornaAreaCirculo((Circulo*)lh->forma);
                  break;
        default:  area = -1;
    }

    return area;
}

float maxArea (ListaHet* lh) {
    ListaHet* aux;
    float area, maxArea = 0;

    for (aux = lh; aux != NULL; aux=aux->prox) {
        area = areaForma(aux);
        if(area > maxArea)
            maxArea = area;
    }

    return maxArea;
}

void imprimeFormas (ListaHet* lh) {
    ListaHet* aux;

    for (aux = lh; aux != NULL; aux = aux->prox) {
        switch (aux->tipo) {
            case RET: imprimeRetangulo((Retangulo*)aux->forma);
                      break;
            case TRI: imprimeTriangulo((Triangulo*) aux->forma);
                      break;
            case CIR: imprimeCirculo((Circulo*)aux->forma);
                      break;
        }
    }
}

void destroiLista (ListaHet* lh) {
    ListaHet* aux1,* aux2;
    aux1 = lh;

    while (aux1 != NULL) {
        aux2 = aux1->prox;
        free(aux1->forma);
        free(aux1);
        aux1 = aux2;
    }
}