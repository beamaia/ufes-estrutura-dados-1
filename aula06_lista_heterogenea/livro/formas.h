#ifndef FORMAS_H
#define FORMAS_H

typedef struct retangulo Retangulo;
typedef struct triangulo Triangulo;
typedef struct circulo Circulo;

/*
 * Inicializa a estrutura Retangulo de acordo com os parametros
 * Input: float, float
 * Output: Retangulo*
 */ 
Retangulo* inicializaRetangulo (float b, float h);

/*
 * Inicializa a estrutura Triangulo de acordo com os parametros
 * Input: float, float
 * Output: Triangulo*
 */ 
Triangulo* inicializaTriangulo (float b, float h);

/*
 * Inicializa a estrutura Circulo de acordo com os parametros
 * Input: float
 * Output: Circulo*
 */ 
Circulo* inicializaCirculo (float r);

/*
 * Retorna a area da estrutura do tipo Retangulo
 * Input: Retangulo*
 * Output: float
 */
float retornaAreaRetangulo (Retangulo* r);

/*
 * Retorna a area da estrutura do tipo Triangulo
 * Input: Triangulo*
 * Output: float
 */
float retornaAreaTriangulo (Triangulo* t);

/*
 * Retorna a area da estrutura do tipo Circulo
 * Input: Circulo*
 * Output: float
 */
float retornaAreaCirculo (Circulo* c);

/*
 * Imprime as informacoes da estrutura do tipo Retangulo
 * Input: Retangulo*
 * Output: void
 */
void imprimeRetangulo (Retangulo* r);

/*
 * Imprime as informacoes da estrutura do tipo Triangulo
 * Input: Triangulo*
 * Output: void
 */
void imprimeTriangulo (Triangulo* t);

/*
 * Imprime as informacoes da estrutura do tipo Circulo
 * Input: Circulo*
 * Output: void
 */
void imprimeCirculo (Circulo* c);
#endif