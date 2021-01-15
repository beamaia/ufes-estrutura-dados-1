#include "matriz.h"
#include <stdio.h>
#include <stdlib.h>

//Tipo matriz (tipo opaco)
struct matriz {
    int ** mat;
    int linhas,colunas;
};

/*Inicializa uma matriz de nlinhas e ncolunas
 * inputs: nlinhas (no de linhas) e ncolunas (no de colunas)
 * output: ponteiro para a matriz inicializada
 * pre-condicao: nlinhas e ncolunas diferentes de 0
 * pos-condicao: matriz de retorno existe e contem nlinhas e ncolunas
 */
Matriz* inicializaMatriz (int nlinhas, int ncolunas) {
    Matriz *mat = (Matriz *) malloc(sizeof( Matriz));

    mat->linhas = nlinhas;
    mat->colunas = ncolunas;

    mat->mat = (int **) malloc(sizeof(int*) * nlinhas);
    for (int i = 0; i < nlinhas; i++) {
        mat->mat[i] = (int *) malloc(sizeof(int) * ncolunas);
    }

    return mat;
}

/*Modifica o elemento [linha][coluna] da matriz mat
 * inputs: a matriz, a linha, a coluna, e o novo elemento
 * output: nenhum
 * pre-condicao: matriz mat existe, linha e coluna são válidos na
matriz
 * pos-condicao: elemento [linha][coluna] da matriz modificado
 */
void modificaElemento (Matriz* mat, int linha, int coluna, int elem) {
    mat->mat[linha][coluna] = elem;
}

/*Retorna o elemento mat[linha][coluna]
 * inputs: a matriz, a linha e a coluna
 * output: elemento mat[linha][coluna]
 * pre-condicao: matriz mat existe, linha e coluna são válidos na
matriz
 * pos-condicao: mat não é modificada
 */
int recuperaElemento(Matriz* mat, int linha, int coluna) {
    return mat->mat[linha][coluna];
}

/*Retorna o número de colunas da matriz mat
 * inputs: a matriz
 * output: o número de colunas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada
 */
int recuperaNColunas (Matriz* mat) {
    return mat->colunas;
}

/*Retorna o número de linhas da matriz mat
 * inputs: a matriz
 * output: o número de linhas da matriz
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada
 */
int recuperaNLinhas (Matriz* mat) {
    return mat->linhas;
}

/*Retorna a matriz transposta de mat
 * inputs: a matriz
 * output: a matriz transposta
 * pre-condicao: matriz mat existe
 * pos-condicao: mat não é modificada e matriz transposta existe
 */
Matriz* transposta (Matriz* mat) {
    Matriz * t = inicializaMatriz(mat->colunas, mat->linhas);

    for(int i = 0; i < t->linhas; i++) {
        for (int j = 0; j < t->colunas; j++) {
            t->mat[i][j] = (mat->mat[j][i]);
        }
    }
    return t;
}

/*Retorna a matriz multiplicacao entre mat1 e mat2
 * inputs: as matrizes mat1 e mat2
 * output: a matriz multiplicação
 * pre-condicao: matrizes mat1 e mat2 existem, e o numero de colunas
de mat1
 * correponde ao numero de linhas de mat2
 * pos-condicao: mat1 e mat2 não são modificadas e a matriz
multiplicacao existe
 */
Matriz* multiplicacao (Matriz* mat1, Matriz* mat2) {
    Matriz *mult = inicializaMatriz(mat1->linhas, mat2->colunas);
    int soma = 0;

    for (int linha = 0; linha < mat1->linhas; linha++) {
        for(int coluna = 0; coluna < mat2->colunas; coluna++) {
            for (int aux = 0; aux < mat1->colunas; aux++) {
                soma += (mat1->mat[linha][aux] * mat2->mat[aux][coluna]);
            }
            mult->mat[linha][coluna] = soma;
            soma = 0;
        }
    }

    return mult;
}

/*Imprime a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: nenhuma
 */
void imprimeMatriz(Matriz* mat) {
    for (int i = 0; i < mat->linhas; i++) {
        for (int j = 0; j < mat->colunas; j++) {
            printf("%d ", mat->mat[i][j]);
        }
        printf("\n");
    }
}

/*Libera memória alocada para a matriz
 * inputs: matriz mat
 * output: nenhum
 * pre-condicao: matriz mat existe
 * pos-condicao: toda a memória alocada para matriz foi liberada
 */
void destroiMatriz(Matriz* mat) {
    for(int i = 0; i < mat->linhas; i++) {
        free(mat->mat[i]);
    }

    free(mat->mat);
    free(mat);
}
