#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "formas.h"
#define PI 3.14

/*
 * Estrutura retangulo
 * b: base do retangulo
 * h: altura do retangulo
 */
struct retangulo {
    float b;
    float h;
};

typedef struct retangulo Retangulo;

/*
 * Estrutura triangulo
 * b: base do triangulo
 * h: altura do triangulo
 */
struct triangulo {
    float b;
    float h;
};

typedef struct triangulo Triangulo;

/*
 * Estrutura circulo
 * r: raio do circulo
 */
struct circulo {
    float r;
};

typedef struct circulo Circulo;

Retangulo* inicializaRetangulo (float b, float h) {
    Retangulo* r = (Retangulo*) malloc(sizeof(Retangulo));
    r->b = b;
    r->h = h;
    return r;
}

Triangulo* inicializaTriangulo (float b, float h) {
    Triangulo* t = (Triangulo*) malloc(sizeof(Triangulo));
    t->b = b;
    t->h = h;
    return t;
}

Circulo* inicializaCirculo (float r) {
    Circulo* c = (Circulo*) malloc(sizeof(Circulo));
    c->r = r;
    return c;
}

float retornaAreaRetangulo (Retangulo* r) {
    return r->b * r->h;
}

float retornaAreaTriangulo (Triangulo* t) {
    return t->b * t->h / 2;
}

float retornaAreaCirculo (Circulo* c) {
    return PI * c->r * c->r;
}

void imprimeRetangulo (Retangulo* r) {
    printf("RETANGULO - Base: %.2f Altura: %.2f - Area: %.2f\n", r->b, r->h, retornaAreaRetangulo(r));
}

void imprimeTriangulo (Triangulo* t) {
    printf("TRIANGULO - Base: %.2f Altura: %.2f - Area: %.2f\n", t->b, t->h, retornaAreaTriangulo(t));
}

void imprimeCirculo (Circulo* c) {
    printf("CIRCULO - Raio: %.2f - Area: %.2f\n", c->r, retornaAreaCirculo(c));
}