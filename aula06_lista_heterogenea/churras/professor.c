#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "professor.h"

struct professor {
    int siape;
    char* nome;
    float salario;
};

Professor* inicializaProfessor(int siape, char* nome, float salario) {
    Professor* novo = (Professor*) malloc(sizeof(Professor));

    novo->siape = siape;
    novo->salario = salario;
    novo->nome = (char*) malloc(sizeof(char) * (strlen(nome) + 1));
    strcpy(novo->nome, nome);
    
    return novo;
}

void imprimeProfessor (Professor* prof) {
    printf("Siape: %d, Nome: %s, Salário: %0.2f\n", prof->siape, prof->nome, prof->salario);
}

int retornaSiape (Professor* prof) {
    return prof->siape;
}

char* retornaNomeProfessor (Professor* prof) {
    return prof->nome;
}

float retornaSalario (Professor* prof) {
    return prof->salario;
}

void destroiProfessor (Professor* prof) {
    free(prof->nome);
    free(prof);
}