/***********************
 * Aluna: Beatriz Matias
 * Matricula: 2019107651
 * Exercicios: 1 - Revisao C
 * Questao: 1
***********************/
#include <stdio.h>
#include <stdlib.h>

void mostra(int*, int*, int*, int*);
void soma(int*, int*, int*, int*);
void subtrai(int*, int*, int*, int*);
void muda(int*, int*, int*, int*);
void parOuImpar(int*, int*, int*, int*);
void selecionarAtividade(int*, int*, int*, int*);

int main() {
    int inteiro1, inteiro2, inteiro3, inteiro4;
    int *ponteiro1, *ponteiro2, *ponteiro3, *ponteiro4;

    printf("Digite 4 inteiros.\n");
    scanf(" %d %d %d %d", &inteiro1, &inteiro2, &inteiro3, &inteiro4);
    printf("\nOs números que você digitou são: %d %d %d %d.\n", inteiro1, inteiro2, inteiro3, inteiro4);

    ponteiro1 = &inteiro1;
    ponteiro2 = &inteiro2;
    ponteiro3 = &inteiro3;
    ponteiro4 = &inteiro4;

    selecionarAtividade(ponteiro1, ponteiro2, ponteiro3, ponteiro4);
    return 0;
}

/*
  * Mostra os  valores dos 4 ponteiros
  * Entrada: int*, int*, int*, int*
  * Saida: void
  */
void mostra(int* p1, int* p2, int* p3, int* p4) {
    printf("01 - %d\n02 - %d\n03 - %d\n04 - %d\n", *p1, *p2, *p3, *p4);
}

/*
  * Seleciona um ponteiro e soma um valor de sua escolha
  * Entrada: int*, int*, int*, int*
  * Saida: void
  */
void soma(int* p1, int* p2, int* p3, int* p4) {
    int soma, escolha;

    printf("Você quer somar quanto? Digite um inteiro\n");
    scanf(" %d", &soma);

    printf("Você quer somar %d a qual número?\n", soma);
    mostra(p1, p2, p3, p4);
    printf("Digita o algorismo relacionado ao número (de 1 a 4)\n");
    scanf(" %d", &escolha);

    switch (escolha) {
        case 01: *p1 += soma;
                 break;
        case 02: *p2 += soma;
                 break;
        case 03: *p3 += soma;
                 break;
        case 04: *p4 += soma;
                 break;
        default: break;
    }

    printf("Novos números:\n");
    mostra(p1, p2, p3, p4);
}

/*
  * Seleciona um ponteiro e subtrai um valor de sua escolha
  * Entrada: int*, int*, int*, int*
  * Saida: void
  */
void subtrai(int* p1, int* p2, int* p3, int* p4) {
    int subtracao, escolha;

    printf("Você quer subtrair quanto? Digite um inteiro\n");
    scanf(" %d", &subtracao);

    printf("Você quer subtrair %d a qual número?\n", subtracao);
    mostra(p1, p2, p3, p4);
    printf("Digita o algorismo relacionado ao número (de 1 a 4)\n");
    scanf(" %d", &escolha);

    switch (escolha) {
        case 01: *p1 -= subtracao;
                 break;
        case 02: *p2 -= subtracao;
                 break;
        case 03: *p3 -= subtracao;
                 break;
        case 04: *p4 -= subtracao;
                 break;
        default: break;
    }

    printf("Novos números:\n");
    mostra(p1, p2, p3, p4);
}

/*
  * Seleciona um ponteiro e muda para um valor de sua escolha
  * Entrada: int*, int*, int*, int*
  * Saida: void
  */
void muda(int* p1, int* p2, int* p3, int* p4) {
    int escolha, novoValor;

    printf("Você quer mudar qual número\n");
    mostra(p1, p2, p3, p4);
    printf("Digita o algorismo relacionado ao número (de 1 a 4)\n");
    scanf(" %d", &escolha);
    printf("\nDigite o novo valor (inteiro) do número:\n");
    scanf(" %d", &novoValor);

    switch (escolha) {
        case 01: *p1 = novoValor;
                 break;
        case 02: *p2 = novoValor;
                 break;
        case 03: *p3 = novoValor;
                 break;
        case 04: *p4 = novoValor;
                 break;
        default: break;
    }

    printf("Novos números:\n");
    mostra(p1, p2, p3, p4);
}

/*
  * Apresenta se o numero eh PAR ou IMPAR
  * Entrada: int*
  * Saida: void
  */
void auxiParOuImpar(int *p) {
    if (*p % 2) {
        printf("IMPAR\n");
    } else {
        printf("PAR\n");
    }
}

/*
  * Mostra se todos os valores sao impares ou pares
  * Entrada: int*, int*, int*, int*
  * Saida: void
  */
void parOuImpar(int* p1, int* p2, int* p3, int* p4) {
    printf("01 - %d - ", *p1);
    auxiParOuImpar(p1);

    printf("02 - %d - ", *p2);
    auxiParOuImpar(p2);

    printf("03 - %d - ", *p3);
    auxiParOuImpar(p3);

    printf("04 - %d - ", *p4);
    auxiParOuImpar(p4);
}

/*
  *  Apresenta opcoes de comandos
  * Entrada:  void
  * Saida: void
  */
void apresentarOpcoes(void) {
    printf("O que você quer fazer?\n");
    printf("01 - Somar a um número\n");
    printf("02 - Subtrair a um números\n");
    printf("03 - Mudar um número\n");
    printf("04 - Mostrar os números\n");
    printf("05 - Verificar se os números são pares ou ímpares\n");
    printf("00 - Sair do programa\n");
}

/*
  * Seleciona as atividades/opcoes de comandos
  * Entrada: int*, int*, int*, int*
  * Saida: void
  */
void selecionarAtividade(int* p1, int* p2, int* p3, int* p4) {
    int queroMostrarOpcoes = 1, escolha = 0;

    while (queroMostrarOpcoes) {
        system("clear");
        apresentarOpcoes();
        scanf("%d", &escolha);
        switch (escolha) {
            case 1: soma(p1, p2, p3, p4);
                    break;
            case 2: subtrai(p1, p2, p3, p4);
                    break;
            case 3: muda(p1, p2, p3, p4);
                    break;
            case 4: mostra(p1, p2, p3, p4);
                    break;
            case 5: parOuImpar(p1, p2, p3, p4);
                    break;
            case 0: return;
        }

        printf("Quer continuar?\n01 - SIM | 02 - NAO\n");
        scanf(" %d", &queroMostrarOpcoes);
    }
}

