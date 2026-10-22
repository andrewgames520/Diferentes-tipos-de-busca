
#ifndef ARVORE_BINARIA
#define ARVORE_BINARIA

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef enum { false, true } boolean;

typedef struct No {
    int codigo;
    struct No* esquerda;
    struct No* direita;
} No;

typedef struct {
    No* raiz;
} Arvore;

/* Protótipos (declarações) das funções */
void cria_arvore(Arvore* arv);
boolean eh_nulo(No* raiz);
No* insere(int cod, No* raiz);
int pesquisa(int cod, No* raiz);
No* antecessor(No *atual, No *ant);
No* remocao(int cod, No* raiz);
void pre_ordem(No* raiz);
void acharMaior(No *raiz);
No* insere_varios(No* raiz,int *valores, int tam);
double medir_tempo(No *raiz, int *procurados);
#endif
