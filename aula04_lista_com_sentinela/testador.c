#include <stdio.h>
#include "matriz.h"
#include "listaMat.h"
#define NLINHAS 4
#define NCOLUNAS 3

// Funcao auxiliar para poder apresentar mensagens na hora de retirar matrizes da lista
Matriz* mensagemRetira (int pos, Lista *lista) {
    Matriz* retirada;

    printf("Retirando matriz (indice = %d) da lista\n", pos);
    retirada = retira(pos, lista);
    
    if (retirada != NULL) {
        printf("Matrizes restantes\n");
        imprimeLista(lista);
    } else {
        printf("Não foi possivel retirar a matriz do indice %d. Ela não existe :/", pos);
    }

    return retirada;
}

int main()
{
    // Cria matrizes e as preenchem
    Matriz* mat1, * mat2, * mat3, *mat4;

    mat1 = inicializaMatriz(NLINHAS, NCOLUNAS);
    mat2 = inicializaMatriz(NLINHAS, NCOLUNAS);
    mat3 = inicializaMatriz(NLINHAS, NCOLUNAS);
    mat4 = inicializaMatriz(NLINHAS, NCOLUNAS);

    int i, j;
    for (i = 0; i < NLINHAS; i++)
        for (j=0;j<NCOLUNAS; j++) {
            modificaElemento(mat1, i, j, i + j);
            modificaElemento(mat2, i, j, 2*i + j);
            modificaElemento(mat3, i, j, i);
            modificaElemento(mat4, i, j, j);
        }


    // Cria lista e a preenche
    Lista* lista;
    lista = inicializaLista();

    insere(mat1, lista);
    insere(mat2, lista);
    insere(mat3, lista);
    insere(mat4, lista);


    // Cria matrizes transpostas e as preenchem
    Matriz* transMat1, * transMat2, * transMat3, *transMat4;

    transMat1 = transposta(mat1);
    transMat2 = transposta(mat2);
    transMat3 = transposta(mat3);
    transMat4 = transposta(mat4);

    // Cria lista e a preenche
    Lista* listaTransposta; 
    listaTransposta = inicializaLista();

    insere(transMat1, listaTransposta);
    insere(transMat2, listaTransposta);
    insere(transMat3, listaTransposta);
    insere(transMat4, listaTransposta);

    // Imprime listas
    printf("Matrizes\n");
    imprimeLista(lista);
    printf("Matrizes transpostas\n");
    imprimeLista(listaTransposta);

    Matriz* retiraPrimeiroElemento,* retiraUltimoElemento,
          * retiraElementoMeio,* retiraElementoNaoExiste;

    // Retirando primeiro e ultimo elemento da lista
    int pos = 0;
    retiraPrimeiroElemento = mensagemRetira(pos, lista);
    
    pos = 2; 
    retiraUltimoElemento = mensagemRetira(pos, lista);

    // Inserindo mat1 e mat4 novamente para a lista
    printf("Retornando matrizes para a lista...\n\n");
    insere(mat1, lista);
    insere(mat4, lista);
    imprimeLista(lista);
    
    // Retirando um elemento do meio da lista
    pos = 1;
    retiraElementoMeio = mensagemRetira(pos, lista);

    printf("Retornando matriz para a lista...\n\n");
    insere(retiraElementoMeio, lista);
    imprimeLista(lista);

    retiraElementoMeio = mensagemRetira(pos, lista);    

    // Retirando um elemento que nao existe
    pos = 10;
    retiraElementoNaoExiste = mensagemRetira(pos, lista);

    // Liberando lista
    liberaLista(lista);
    liberaLista(listaTransposta);

    // Liberando matrizes
    destroiMatriz(mat1);
    destroiMatriz(mat2);
    destroiMatriz(mat3);
    destroiMatriz(mat4);
    destroiMatriz(transMat1);    
    destroiMatriz(transMat2);
    destroiMatriz(transMat3);
    destroiMatriz(transMat4);

    return 0;
}