#include <stdio.h>
#include "professor.h"
#include "aluno.h"
#include "listaHet.h"

int main (){
    Aluno* patricia = inicializaAluno(123, "Patrícia", 10);
    Aluno* alice = inicializaAluno(656, "Alice", 5);
    Aluno* maria = inicializaAluno(21, "Maria", 9);
    Aluno* joao = inicializaAluno(999, "Joao", 8);

    Professor* roberta = inicializaProfessor(3878734, "Roberta", 9435);
    Professor* flavio = inicializaProfessor(578475, "Flavio", 7432);

    ListaHet* churrasco = inicializaLista();


    insereAluno(churrasco, patricia);
    insereProfessor(churrasco, roberta);
    insereAluno(churrasco, alice);
    insereAluno(churrasco, maria);
    insereProfessor(churrasco, flavio);
    insereAluno(churrasco, joao);

    printf("Imprimindo a lista:\n");
    imprimeListaHet(churrasco);

    printf("VALOR: %.2f \n", valorChurrasco(churrasco));

    destroLista(churrasco);

    destroiAluno(patricia);
    destroiAluno(alice);
    destroiAluno(maria);
    destroiAluno(joao);

    destroiProfessor(roberta);
    destroiProfessor(flavio);

    return 0;

}