#include "lista.h"

No *criar(){
    return NULL;
}

No *inserir(No *l,void *d){
    No *novo = malloc(sizeof(No));
    novo->dados = d;
    novo->prox = l;
    return novo;
}

void percorrer(No *l, void *acao(void *)){
    No *no;
    for(no = l; no != NULL; no = no->prox)    {
        acao(no->dados);
    }
}
