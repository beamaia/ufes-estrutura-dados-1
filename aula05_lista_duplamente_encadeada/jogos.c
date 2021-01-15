#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "jogos.h"

/*
 * Estrutura jogo
 * Nome: nome do jogo
 * Tipo: B, E, J ou C
 * Ano: ano que o jogo foi lancado
 * ID: id do jogo no programa
 * Avaliacao: nota do jogo de 0-10, sendo 0 pessimo e 10 otimo
 */ 
struct jogo{
    char* nome;
    char tipo;
    int ano,
        id;
    float avaliacao;
};

/*
 * Funcao auxiliar para leitura de nome do jogo 
 * Utilizado apenas em Jogo* inicializaJogo (void) 
 * input: void
 * output: char*
 */ 
static char* auxNome (void){
    char aux[100], * nome;

    printf("Digite o nome do jogo\n");
    if(scanf("%[^\n]%*c", aux)) {
        nome = (char*) malloc(sizeof(char) * (strlen(aux) + 1));
        strcpy(nome, aux);
        return nome;
    }

    return NULL;
}

/*
 * Funcao auxiliar para leitura do tipo do jogo 
 * Utilizado apenas em Jogo* inicializaJogo (void) 
 * input: void
 * output: char
 */ 
static char auxTipo (void) {
    char tipo = '0';

    printf("Digite a letra indicada por ""()"" para indicar o tipo de jogo\n");
    printf("(B) - Base | (E) - Pacote de Expansão | (J) - Pacote de Jogo | (C) Coleção de Objetos\n");
    
    scanf("%c%*c", &tipo);
    tipo = toupper(tipo);

    int cont = 0;
    while (tipo != 'B' && tipo != 'E' && tipo != 'J' && tipo != 'C') {
        printf("Você digitou: %c\n", tipo);
        printf("Esse código não existe! Digite um código que existe\n");
        scanf("%c%*c", &tipo);
        tipo = toupper(tipo);

        cont++;
        if (cont == 3) {
            printf("Você não entrou com um código existente :(\n Vamos fechar o programa...");
            exit(1);
        }
    }

    return tipo;
}

/*
 * Funcao auxiliar para leitura do ano de lancamento do jogo 
 * Utilizado apenas em Jogo* inicializaJogo (void) 
 * input: void
 * output: int
 */ 
static int auxAno (void) {
    int ano;
    
    printf("Em qual ano ele foi lançado?\n");
    scanf("%d%*c", &ano);

    return ano;
}

/*
 * Funcao auxiliar para leitura do ID do jogo 
 * Utilizado apenas em Jogo* inicializaJogo (void) 
 * input: void
 * output: int
 */ 
static int auxID (void) {
    int id;
    
    printf("Qual é o ID do jogo?\n");
    scanf("%d%*c", &id);

    return id;    
}

/*
 * Funcao auxiliar para leitura da avaliacao do jogo 
 * Utilizado apenas em Jogo* inicializaJogo (void) 
 * input: void
 * output: float
 */ 
static float auxAvaliacao (void) {
    float avaliacao;

    printf("Digite a nota do jogo de 0 a 10\n");
    scanf("%f%*c", &avaliacao);

    int cont = 0;
    while (avaliacao < 0 || avaliacao > 10) {
        printf("Digite uma nota de 0 a 10\n");
        scanf("%f%*c", &avaliacao);

        cont++;
        if (cont == 3) {
            printf("Você não entrou uma nota de 0 a 10. Vamos fechar o programa...");
            exit(1);
        }
    }

    return avaliacao;
}

Jogo* inicializaJogo (void) {
    Jogo* jogo;

    jogo = (Jogo*) malloc(sizeof(Jogo));

    jogo->nome = auxNome();
    jogo->tipo = auxTipo();
    jogo->ano = auxAno();
    jogo->id = auxID();
    jogo->avaliacao = auxAvaliacao();

    return jogo;  
}

Jogo* inicializaJogoCliente (char* nome, char tipo, int ano, int id, float avaliacao) {
    Jogo* jogo;

    jogo = (Jogo*) malloc(sizeof(Jogo));

    jogo->nome = (char*) malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(jogo->nome, nome);

    jogo->tipo = tipo;
    jogo->ano = ano;
    jogo->id = id;
    jogo->avaliacao = avaliacao;

    return jogo; 
}

int recuperaID (Jogo* jogo) {
    return jogo->id;
}

void modificaID (Jogo* jogo, int id) {
    jogo->id = id;
}

float recuperaAvaliacao (Jogo* jogo) {
    return jogo->avaliacao;
}

void modificaAvaliacao (Jogo *jogo, float nova) {
    jogo->avaliacao = nova;
}

/*
 * Funcao auxiliar que apresenta o tipo de jogo por extenso 
 * Utilizado apenas em Jogo* inicializaJogo (void) 
 * input: Jogo*
 * output: void
 */ 
static void apresentaTipoJogo (Jogo* jogo) {
    switch (jogo->tipo){
        case 'B': printf("Jogo Base");
                  break;
        case 'E': printf("Pacote de Expansão");
                  break;
        case 'C': printf("Coleção de Objetos");
                  break;
        case 'J': printf("Pacote de Jogo");
    }
}

void apresentaJogo (Jogo* jogo) {
    if (jogo == NULL) {
        printf("Não tem jogo para apresentar.");
        return;
    }

    printf("ID: %d - ", jogo->id);
    apresentaTipoJogo(jogo);
    printf(" - %s - Ano: %d - Nota: %.2f\n", jogo->nome, jogo->ano, jogo->avaliacao);
}

void liberaJogo (Jogo* jogo) {
    free(jogo->nome);
    free(jogo);
}