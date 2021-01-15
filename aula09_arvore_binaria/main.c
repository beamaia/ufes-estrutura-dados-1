#include <stdio.h>
#include "arvAluno.h"
#include "aluno.h"

int main() {
    // Criando as sailor senshi
    Aluno* sailorMoon = inicializaAluno(1, "Usagi", 3);
    Aluno* sailorMercury = inicializaAluno(2, "Ami", 10);
    Aluno* sailorMars = inicializaAluno(3, "Rei", 8);
    Aluno* sailorJupiter = inicializaAluno(4, "Makoto", 7);
    Aluno* sailorVenus = inicializaAluno(5, "Minako", 9);
    Aluno* sailorChibiMoon = inicializaAluno(6, "Usagi", 5);
    Aluno* sailorPluto = inicializaAluno(7, "Setsuna", 6);


    Arv* arv = arvCria(sailorMoon, 
                       arvCria(sailorMercury, arvCriaVazia(), arvCriaVazia()), 
                       arvCria(sailorMars, 
                               arvCria(sailorJupiter, 
                                       arvCria(sailorChibiMoon, arvCriaVazia(), arvCriaVazia()), 
                                       arvCria(sailorPluto, arvCriaVazia(), arvCriaVazia())), 
                               arvCria(sailorVenus  , arvCriaVazia(), arvCriaVazia())));


    printf("Imprimindo informações sobre as sailor senshi\n");
    arvImprime(arv);

    printf("\nInformações sobre a àrvore:\n");
    printf("Altura da árvore: %d\n", altura(arv));
    printf("Qtd de folhas: %d\n", folhas(arv));
    printf("Ocorrências do nome Ami: %d\n", ocorrencias(arv, "Ami"));
    printf("Ocorrências do nome Usagi: %d\n", ocorrencias(arv, "Usagi")); 
    printf("Ocorrências do nome Bia: %d\n", ocorrencias(arv, "Bia")); 

    Arv* vazia = arvCriaVazia();

    printf("\nImprimindo informações duma árvore vazia\n");
    printf("Altura da árvore: %d\n", altura(vazia));
    printf("Qtd de folhas: %d\n", folhas(vazia));
    printf("Ocorrências do nome Ami: %d\n", ocorrencias(vazia, "Ami"));
    printf("Ocorrências do nome Usagi: %d\n", ocorrencias(vazia, "Usagi")); 
    printf("Ocorrências do nome Bia: %d\n", ocorrencias(vazia, "Bia")); 


    // Liberando os nos da arvore
    arvLibera(arv);

    // Liberando as sailor senshi
    destroiAluno(sailorMoon);
    destroiAluno(sailorMercury);
    destroiAluno(sailorMars);
    destroiAluno(sailorJupiter);
    destroiAluno(sailorVenus);
    destroiAluno(sailorChibiMoon);
    destroiAluno(sailorPluto);

    return 0;
}