#include <stdio.h>
#include "listagen.h"
#include "listaAluno.h"
#include "aluno.h"

void presenca (int i) {
    if (i == 0)
        printf("%-20s\n", "Presente");
    else
        printf("%-20s\n", "Não Presente");
}

int main () {
    ListaGen* lista = criaLista();

    printf("Criando alunos...\n");
    // Criacao dos alunos 
    Aluno* numUm = inicializaAluno(1, "Nico Uno", 9);
    Aluno* numDois = inicializaAluno(2, "Horacio Genaro", 7);
    Aluno* numTres = inicializaAluno(3, "Ukibe Nokome", 4);
    Aluno* numQuatro = inicializaAluno(4, "Mauricio Melo", 4);
    Aluno* numCinco = inicializaAluno(5, "Abigail Oliveira", 9);
  
    printf("\nInserindo na lista...\n");
    // Insere alunos na lista
    lista = insereLista(lista, numCinco);
    lista = insereLista(lista, numQuatro); 
    lista = insereLista(lista, numTres);   
    lista = insereLista(lista, numDois);
    lista = insereLista(lista, numUm);
    
    printf("\nTurma do bairro:\n");
    imprimeListaAlunos(lista);

    // Testando retirar um elemento no inicio, meio e fim da lista
    printf("\nRetirando No 1, No3 e No5 da lista...\n");
    lista = retiraAluno(lista, 1);
    lista = retiraAluno(lista, 3);
    lista = retiraAluno(lista, 5);

    printf("\nTurma do bairro sem alguns dos alunos:\n");
    imprimeListaAlunos(lista);

    // Retornando alunos para a lista
    printf("\nInserindo alunos...\n");
    lista = insereLista(lista, numUm);
    lista = insereLista(lista, numTres);
    lista = insereLista(lista, numCinco);

    printf("\nTurma do bairro:\n");
    imprimeListaAlunos(lista);

    // Testando o calculo de media
    float media = mediaTurma(lista);
    printf("\nA média da Turma do Bairro é: %.2f.\n", media);

    printf("\nRetirando da lista No1...\n");
    lista = retiraAluno(lista, 1);

    // Testando o pertenceAluno
    printf("\nChamada:\n");
    int i1, i2, i3, i4, i5;
    
    i1 = pertenceAluno(lista, 1);
    i2 = pertenceAluno(lista, 2);
    i3 = pertenceAluno(lista, 3);
    i4 = pertenceAluno(lista, 4);
    i5 = pertenceAluno(lista, 5);

    printf("%-20s |%-20s\n", "Aluno", "Presença");
    printf("-----------------------------------\n");
    printf("%-20s |", getNome(numUm));
    presenca(i1);
    printf("%-20s |", getNome(numDois));
    presenca(i2);    
    printf("%-20s |", getNome(numTres));
    presenca(i3);    
    printf("%-20s |", getNome(numQuatro));
    presenca(i4);
    printf("%-20s |", getNome(numCinco));
    presenca(i5);

    // Liberando memoria
    destroiAluno(numUm);
    destroiAluno(numDois);
    destroiAluno(numTres);
    destroiAluno(numQuatro);
    destroiAluno(numCinco);
    liberaLista(lista);

    return 0;
}