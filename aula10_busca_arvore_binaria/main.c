#include <stdio.h>
#include "abb.h"
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

    Arv* arv = abbCria();
    arv = abbInsere(arv, sailorJupiter);
    arv = abbInsere(arv, sailorMoon);
    arv = abbInsere(arv, sailorMars);
    arv = abbInsere(arv, sailorVenus);
    arv = abbInsere(arv, sailorPluto);
    arv = abbInsere(arv, sailorMercury);
    arv = abbInsere(arv, sailorChibiMoon);

    printf("Imprimindo informações sobre as sailor senshi\n");
    abbImprime(arv);

    printf("\nInformações sobre a àrvore:\n");
    printf("Altura da árvore: %d\n", altura(arv));
    printf("Qtd de folhas: %d\n", folhas(arv));

    printf("\nPesquisando se existe algumas matriculas.\n(1) = Sim (0) = Não\n");
    printf("Existe a mátricula 1?: %d\n", (abbBusca(arv, 1) != NULL));
    printf("Existe a mátricula 4?: %d\n", (abbBusca(arv, 4) != NULL));
	printf("Existe a mátricula 7?: %d\n", (abbBusca(arv, 7) != NULL));
    printf("Existe a mátricula 9?: %d\n", (abbBusca(arv, 9) != NULL));

	Arv* vazia = abbCria();

    printf("\nImprimindo informações duma árvore vazia\n");
	abbImprime(vazia);

    printf("\nInformações sobre a àrvore:\n");
    printf("Altura da árvore: %d\n", altura(vazia));
    printf("Qtd de folhas: %d\n", folhas(vazia));

    printf("\nPesquisando se existe algumas matriculas.\n(1) = Sim (0) = Não\n");
    printf("Existe a mátricula 1?: %d\n", (abbBusca(vazia, 1) != NULL));
    printf("Existe a mátricula 4?: %d\n", (abbBusca(vazia, 4) != NULL));

	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);

	//----------------------Retirando uma folha a direita da raiz----------------------
	printf("\n\nRetirando a sailor senshi sailorChibiMoon mat 6...\n");
	arv = abbRetira(arv, 6);

	printf("\nSailor Senshi:\n");
	abbImprime(arv);

	// imprimindo arvore com notacao textual
	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);

	printf("\nAdicionando sailorChibiMoon...\n");
	arv = abbInsere(arv, sailorChibiMoon);

	// imprimindo arvore com notacao textual
	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);

	//----------------------Retirando uma folha a esquerda da raiz----------------------
	printf("\n\nRetirando a sailor senshi sailorMercury mat 2...\n");
	arv = abbRetira(arv, 2);

	printf("\nSailor Senshi:\n");
	abbImprime(arv);

	// imprimindo arvore com notacao textual
	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);

	printf("\nAdicionando sailorMercury...\n");
	arv = abbInsere(arv, sailorMercury);

	// imprimindo arvore com notacao textual
	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);

	//----------------------Retirando um no com 1 folha----------------------
	printf("\n\nRetirando a sailor senshi sailorMoon mat 1...\n");
	arv = abbRetira(arv, 1);

	printf("\nSailor Senshi:\n");
	abbImprime(arv);

	// imprimindo arvore com notacao textual
	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);

	printf("\nAdicionando sailorMoon...\n");
	arv = abbInsere(arv, sailorMoon);

	// imprimindo arvore com notacao textual
	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);


	//----------------------Retirando um no com duas folhas----------------------
	printf("\n\nRetirando a sailor senshi sailorJupiter mat 4...\n");
	arv = abbRetira(arv, 4);

	printf("\nSailor Senshi:\n");
	abbImprime(arv);

	// imprimindo arvore com notacao textual
	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);

	printf("\nAdicionando sailorJupiter...\n");
	arv = abbInsere(arv, sailorJupiter);

	// imprimindo arvore com notacao textual
	printf("\nArvore com notação textual: \n");
	arvImprimeTextual(arv);
	printf("\n");

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