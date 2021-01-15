#include <stdio.h>
#include "aluno.h"
#include "TadPilhasDuplas.h"


/*
 * No exercicio, o tipo TipoPilaDupla possui uma lista de TipoItem. Substitui TipoItem por o tipo Aluno
 */ 
int main (){
    Aluno* patricia = inicializaAluno(123, "Patrícia", 10);
    Aluno* alice = inicializaAluno(656, "Alice", 5);
    Aluno* maria = inicializaAluno(21, "Maria", 9);
    Aluno* joao = inicializaAluno(999, "Joao", 8);

    TipoPilhaDupla* p1 = inicializaPilhaDupla();

    push(p1, patricia, 1);
    push(p1, alice, 1);
    push(p1, maria, 1);
    push(p1, joao, 1);

    printf("Imprimindo pilha 1a vez\n");
    imprime(p1);
    printf("\n");

    push(p1, pop(p1, 1), 2);
    push(p1, pop(p1, 1), 2);
    push(p1, pop(p1, 1), 2);
    push(p1, pop(p1, 1), 2);

    printf("Imprimindo pilha 2a vez\n");
    imprime(p1);
    printf("\n");

    printf("Imprimindo pilha 3a vez\n");
    push(p1, pop(p1, 1), 2);

    imprime(p1);
    printf("\n");

    destroiAluno(patricia);
    destroiAluno(alice);
    destroiAluno(maria);
    destroiAluno(joao);
    
    destroi(p1);
    return 0;

}