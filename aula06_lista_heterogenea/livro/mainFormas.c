#include <stdio.h>
#include <stdlib.h>
#include "listaHetFormas.h"
#include "formas.h"


/*
 * Para o exercicio, adicionei uma funcao a mais de imprimeFormas (imprime a lista) para verificar todos elementos
 */ 
int main() {
    ListaHet* formas = inicializaLista();

    formas = criaRet(2, 2, formas);
    formas = criaTri(4, 2, formas);
    formas = criaCir(1, formas);
    formas = criaCir(2, formas);
    formas = criaCir(3, formas);
    formas = criaTri(3, 5.2, formas);
    formas = criaTri(2.5, 2.5, formas);
    formas = criaRet(2, 5, formas);
    formas = criaRet(3, 2.4, formas);

    imprimeFormas(formas);
    float area = maxArea(formas);

    printf("A maior área é: %.2f\n", area);

    destroiLista(formas);
    return 0;
}
