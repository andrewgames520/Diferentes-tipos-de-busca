#ifndef ARVORE_AVL_H
#define ARVORE_AVL_H

#include "arvore_binaria.h" // Reaproveita o tipo boolean
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct Vertice {
    int codigo;
    int chave;
    int altura;
    struct Vertice * esquerda;
    struct Vertice * direita;
} Vertice;

typedef struct {
    Vertice * raiz;
} Arvore_AVL;

void cria_arvore_avl(Arvore_AVL* arv);
boolean eh_nulo_avl(Vertice* raiz);
int get_altura_avl(Vertice* n);
Vertice* insere_avl(int cod, Vertice* raiz);
int fatorBalanceamento_avl(Vertice *raiz);
Vertice* rotacaoDireita_avl(Vertice* raiz);
Vertice* rotacaoEsquerda_avl(Vertice* raiz);
Vertice* rotacaoDuplaEsquerda_avl(Vertice* raiz);
Vertice* rotacaoDuplaDireita_avl(Vertice* raiz);
void pre_ordem_avl(Vertice* raiz);
Vertice* insere_varios_avl(Vertice* raiz,int *valores, int tam);
double medir_tempo_avl(Vertice *raiz, int *procurados);
int pesquisa_avl(int cod, Vertice* raiz, int cont);
#endif // ARVORE_AVL_H
