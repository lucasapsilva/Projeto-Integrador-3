#include<stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct No{
    void *dados;
    struct No *prox;
}No;

No *criar();
No *inserir(No *, void *);
