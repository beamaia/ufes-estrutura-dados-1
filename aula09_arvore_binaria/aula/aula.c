// #include <stdio.h>
// #include <stdlib.h>
// #include <string.h>
// #include "aula.h"

// struct arv {
//     char info;
//     struct arv* esq;
//     struct arv* dir;
// };

// Arv* arvCriaVazia (void) {
//     return NULL;
// }

// Arv* arvCria (char c, Arv* e, Arv* d) {
//     Arv* p = (Arv*) malloc (sizeof(Arv));
//     p->info = c;
//     p->esq = e;
//     p->dir = d;

//     return p;
// }

// Arv* arvLibera (Arv* a) {
//     if (!arvVazia(a)) {
//         arvLibera(a->esq);
//         arvLibera(a->dir);
//         free(a);
//     }
// }

// int arvVazia (Arv* a) {
//     return a == NULL;
// }

// int arvPertence (Arv* a, char c) {
//     if (arvVazia(a)) {
//         return 0;
//     } else {
//         return a->info == c || arvPertence(a->esq, c) || arvPertence(a->dir, c);
//     }
// }

// void arvImprime (Arv* a) {
//     if (!arvVazia (a)) {
//         printf("%c ", a->info);
//         arvImprime(a->esq);
//         arvImprime(a->dir);
//     }
// }

// static int max2 (int a, int b) {
//     return (a > b) ? a : b;
// }

// int arvAltura (Arv*a) {
//     if (arvVazia(a)) {
//         return -1;
//     } else {
//         return 1 + max2 (arvAltura(a->esq), arvAltura(a->dir));
//     }
// }
