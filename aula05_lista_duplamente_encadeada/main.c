#include <stdio.h>
#include "jogos.h"
#include "listaDPL.h"

/*
 * O cliente inicialmente utilizava as funcoes inicializaJogo para criar jogos. 
 * Esta funcao utiliza entradas do terminal.
 * 
 * Para simplificar o exercicio foi criado a funcao inicializaJogoCliente. 
 * Esta funcao nao utiliza entrada do terminal. 
 * Todas as informacoes sao informadas como parametros da funcao.
 * 
 * A segunda funcao foi criada bem depois da primeira, e nao a substitui por querer preservar 
 * o trabalho feito anteriormente.
 */ 

int main () {
    Jogo* sims4,* sims_sustentavel, * sims_familia, * sims_compacta;
    Jogo* stardew,* dontStarve;

    // Inicializa jogos utilizando o terminal para receber entradas
    // sims4 = inicializaJogo();
    // sims_sustentavel = inicializaJogo();
    // sims_familia = inicializaJogo();
    // sims_compacta = inicializaJogo();
    // stardew = inicializaJogo();
    // dontStarve = inicializaJogo();

    // Inicializa jogos sem receber entradas
    sims4 = inicializaJogoCliente("Sims 4", 'B', 2014, 1, 7.8);
    sims_sustentavel = inicializaJogoCliente("Sims 4: Vida Sustentável", 'E', 2020, 2, 8.8);
    sims_familia = inicializaJogoCliente("Sims 4: Vida em Família", 'C', 2017, 3, 8);
    sims_compacta = inicializaJogoCliente("Sims 4: Vida Compacta", 'J', 2020, 4, 8.5);
    stardew = inicializaJogoCliente("Stardew Valley", 'B', 2016, 5, 9);
    dontStarve = inicializaJogoCliente("Don't Starve Together", 'B', 2016, 6, 8.5);

    // Testa funcoes de modificar avaliacao e ID
    modificaAvaliacao(sims4, 6);
    modificaID(stardew, 1);
    modificaID(dontStarve, 2);

    // Cria lista de jogos da origin e jogods da stream
    Lista* origin,* stream;

    origin = inicializaLista();
    stream = inicializaLista();

    // Adiciona a lista origin os jogos do the sims 4
    origin = insereLista(origin, sims4);
    origin = insereLista(origin, sims_sustentavel);
    origin = insereLista(origin, sims_familia);
    origin = insereLista(origin, sims_compacta);

    // Adiciona a lista stream os jogos que sao da stream
    stream = insereLista(stream, stardew);
    stream = insereLista(stream, dontStarve);

    // Imprime listas
    printf("\nLista de jogos da origin\n");
    imprimeLista(origin);

    printf("\nLista de jogos da stream\n");
    imprimeLista(stream);

    // Removendo  o ultimo item da lista
    stream = retiraLista(stream, 1);
    printf("\nLista de jogos da stream sem o id 1\n");
    imprimeLista(stream);

    // Removendo o primeiro (e unico) item da lista
    stream = retiraLista(stream, 2);
    printf("\nLista de jogos da stream sem o id 2\n");
    imprimeLista(stream);

    // Tentando remover algo que nao existe
    stream = retiraLista(stream, 3);
    printf("\nLista de jogos da stream sem o id 3\n");
    imprimeLista(stream);

    // Adicionando itens e vendo se imprime
    stream = insereLista(stream, dontStarve);
    stream = insereLista(stream, stardew);

    printf("\nLista de jogos da stream\n");
    imprimeLista(stream);

    // Retira um elemento no meio da lista
    origin = retiraLista(origin, 3);
    printf("\nLista de jogos da origin sem o id 3\n");
    imprimeLista(origin);

    // Retornando o elemento sims_familia
    origin = insereLista(origin, sims_familia);
    printf("\nLista de jogos da origin\n");
    imprimeLista(origin);

    // Liberando o espaço alocado na memoria
    liberaLista(origin);
    liberaLista(stream);

    liberaJogo(sims4);
    liberaJogo(sims_sustentavel);
    liberaJogo(sims_familia);
    liberaJogo(sims_compacta);
    liberaJogo(stardew);
    liberaJogo(dontStarve);

    return 0;
}