/***********************
 * Aluna: Beatriz Matias
 * Matricula: 2019107651
 * Exercicios: 1 - Revisao C
 * Questao: 2
***********************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#define PI 3.14

/*******************************************************
 * Funcoes: calc_esfera, raizes, pares, inverte e avalia.
 * Cada funcao eh indicada pelo numero do exercicio, ex:.: 2.3
 *******************************************************/

/*
 * 2.1 Calcula area de supercie e o volume de uma esfera
 *  Entrada: float*, float*, float*
 *  Saida: void 
 */
void calc_esfera (float *r, float *area, float *volume)
{
    *area = pow(*r, 2) * PI * 4;
    *volume = pow(*r, 3) * PI * 4 / 3;
}

/*
 * 2.2 Calcula as raizes e diz a quantidade de raizes diferentes
 *  Entrada: float, float, float, float*, float*
 *  Saida: void
 */
int raizes (float a, float b, float c, float *x1, float *x2)
{
    float delta;

    delta = (b * b) - (4 * a * c);
    if (!a) {
        printf("O A é nulo! A equação é de primeiro grau!\n");
        *x1 = - c / b;
        x2 = x1;
        return 1;
    }

    if (delta >= 0) {
        *x1 = ((-b) + sqrt(delta)) / (2 * a);
        *x2 = ((-b) - sqrt(delta)) / (2 * a);
    } else {
        x1 = NULL;
        x2 = NULL;
        return 0;
    }

    if (*x1 == *x2)
        return 1;
    else
        return 2;
}

/* 
 * 2.3 Retorna quanto pares em um vetor 
 * Entrada: int, int*
 * Saida: int
 */
int pares (int n, int* vet) {
    int cont = 0;

    for (int i = 0; i < n; i++) {
        if (!(vet[i] % 2)) {
            cont++;
        }
    }

    return cont;
}

/*
 * 2.4 Inverte a ordem dos elementos armazenados em um vetor
 *  Entrada: int, int*
 *  Saida: void
 */ 
void inverte (int n, int* vet) {
    int aux;
    for (int i = 0; i < n/2; i++) {
        aux = vet[i];
        vet[i] = vet[n - i -1];
        vet[n - i - 1] = aux;
    }
}

/*
 * 2.5 Avaliacao de polinomios, retorno o valor da equacao polinomial/avalia o polinomio
 * Entrada: double*, int, double
 * Saida: double
 */ 
double avalia (double * poli, int grau, double x) {
    double valorTotal = 0;
    for (int i = 0; i <= grau; i++) {
        valorTotal +=  pow(x, i) * poli [i];
    }

    return valorTotal;
}

/******************************************************************
 * Funcoes main + auxiliares 
 * As funcoes mains foram comentadas, com excecao da atividade 2.5
*******************************************************************/

//2.1 Calcula area de supercie e o volume de uma esfera
// int main () {
//    float r, *area, *volume;
// 
//    printf("Digite um número\n");
//    scanf(" %f", &r);
// 
//    area = (float *) malloc((sizeof(float)));
//    volume = (float *) malloc(sizeof(float));
// 
//    calc_esfera(&r, area, volume);
//    printf("Area: %.2f\nVolume: %.2f\n", *area, *volume);
// 
//    free(area);
//    free(volume);
//    return 0;
// }

// 2.2 Funcao que calcula as raizes e diz se ha diferentes
// int main () {
//     float a, b, c;
//     float *x1, *x2;
// 
//     x1 = (float *)malloc((sizeof(float)));
//     x2 = (float *)malloc((sizeof(float)));
// 
//     printf("Digite os valores de A, B e C\n");
//     scanf(" %f %f %f", &a, &b, &c);
// 
//     int temRaizes;
// 
//     temRaizes = raizes(a, b, c, x1, x2);
// 
//     if (temRaizes == 2)
//         printf("Tem 2 raízes: %.2f, %.2f\n", *x1, *x2);
//     else if (temRaizes == 1)
//         printf("Tem 1 raíz: %.2f", *x1);
//     else
//         printf("Tem nenhuma raíz. O delta é negativo\n");
// 
//     free(x1);
//     free(x2);
//     return 0;
// }

void falaQtdPares(int qtd) {
    if (qtd == 1) {
        printf("Há 1 número par.\n");
    } else if (qtd) {
        printf("Tem %d números pares.\n", qtd);
    } else {
        printf("Tem 0 pares.\n");
    }
}

void preencheVetor (int n, int *vet) {
    if (!n)
        return;
    
    if (n == 1)
        printf ("Digite 1 numero. Ele precisa ser inteiro\n");
    else
        printf ("Digite %d números. Eles precisam ser números inteiros\n", n);
    for (int i = 0; i < n; i++) {
        scanf(" %d", &vet[i]);
    } 
}

//2.3 Retorna quantos numeros pares num vetor
// int main () {
//     int n, *vet;
// 
//     printf("Qual é o tamanho do seu vetor?\n");
//     scanf("%i", &n);
// 
//     vet = (int *) malloc (sizeof(int) * n);
// 
//     preencheVetor(n, vet);
// 
//     int qtd_pares;
//     qtd_pares = pares(n, vet);
//     falaQtdPares(qtd_pares);
// 
//     free(vet);
//     return 0;
// }

void apresentaVetor(int n, int* vet) {
    if ( !n) 
        return;

    for (int i = 0; i < n; i++)
        printf("%d ", vet[i]);
    printf("\n");
}

//2.4 Inverte a ordem dos elementos armazenados em um vetor
// int main () {
//     int n, *vet;
// 
//     printf("Qual é o tamanho do seu vetor?\n");
//     scanf("%i", &n);
// 
//     vet = (int *) malloc (sizeof(int) * n);    
// 
//     preencheVetor(n, vet);
//     inverte(n, vet);
//     apresentaVetor(n, vet);
//  
//     free(vet);
//     return 0;
// }

//2.5 Avaliacao de polinomios, retorno o valor da equacao polinomial/avalia o polinomio
int main () {
    int grau;
    double *poli, x, valorTotal;

    printf ("Digita o grau do seu polinomio:\n");
    scanf(" %d", &grau);

    poli = (double *) malloc(sizeof(double) * (grau + 1));

    printf ("Digita os valores do seus coeficientes, do coeficiente de menor grau ao maior grau.\n");
    printf ("Como você escolheu grau %d, voce precisa digitar %d numeros.\n", grau, grau + 1);
    for (int i = 0; i <= grau; i++) {
        scanf(" %lf", &poli[i]);
    }

    printf ("Digita o valor de x:\n");
    scanf (" %lf", &x);

    valorTotal = avalia(poli, grau, x);
 
    printf ("O polinômio avaliado em %.2lf", valorTotal);

    free(poli);
    return 0;
}