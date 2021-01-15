#include <stdio.h>
#include "Fila.h"
#include "aluno.h"

int main () {
    Aluno* patricia = inicializaAluno(123, "Patrícia", 10);
    Aluno* alice = inicializaAluno(656, "Alice", 5);
    Aluno* maria = inicializaAluno(21, "Maria", 9);
    Aluno* joao = inicializaAluno(999, "Joao", 8);

    Fila* f1 = inicializaFila();
    Fila* f2 = inicializaFila();

    insereFila(f1, patricia);
    insereFila(f1, alice);
    insereFila(f1, maria);
    insereFila(f1, joao);

    printf("\nImprimindo fila f1:\n");
    imprimeFila(f1);

    printf("\nImprimindo fila f2 - 1a vez:\n");
    insereFila(f2, retiraFila(f1));
    imprimeFila(f2);

    printf("\nImprimindo fila f2 - 2a vez:\n");
    insereFila(f2, retiraFila(f1));
    imprimeFila(f2);

    printf("\nImprimindo fila f2 - 3a vez:\n");
    insereFila(f2, retiraFila(f1));
    imprimeFila(f2);

    printf("\nImprimindo fila f2 - 4a vez:\n");
    insereFila(f2, retiraFila(f1));
    imprimeFila(f2);

    printf("\nTentando retirar duma fila vazia:\n");
    retiraFila(f1);

    printf("\nAdicionando elementos a fila f1\n");
    insereFila(f1, patricia);
    insereFila(f1, alice);

    printf("\nImprimindo as duas filas");
    printf("\nFila f1:\n");
    imprimeFila(f1);

    printf("\nFila f2\n");
    imprimeFila(f2);

    destroiAluno(patricia);
    destroiAluno(alice);
    destroiAluno(maria);
    destroiAluno(joao);
    
    destroiFila(f1);
    destroiFila(f2);
}