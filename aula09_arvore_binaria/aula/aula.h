#ifndef AULA_ARV_H
#define AULA_ARV_H
typedef struct arv Arv;

Arv* arvCriaVazia (void);
Arv* arvCria (char c, Arv* e, Arv* d);
Arv* arvLibera (Arv* a);
int arvVazia (Arv* a);
int arvPertence (Arv* a, char c);
void arvImprime (Arv* a);

#endif