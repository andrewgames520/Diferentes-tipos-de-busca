#include "arvore_AVL.h"

void cria_arvore_avl(Arvore_AVL* arv) {
    arv->raiz = NULL;
}

boolean eh_nulo_avl(Vertice* raiz) {
    return (raiz == NULL);
}

int get_altura_avl(Vertice* n) {
    if (n == NULL) return -1;
    return n->altura;
}

Vertice* insere_avl(int cod, Vertice* raiz) {
    if(eh_nulo_avl(raiz)) {
        raiz = (Vertice*) malloc(sizeof(Vertice));
        raiz->codigo = cod;
        raiz->esquerda = NULL;
        raiz->direita = NULL;
        raiz->altura = 0;
    }
    else if(cod < raiz->codigo) {
        raiz->esquerda = insere_avl(cod, raiz->esquerda);
    }
    else if(cod > raiz->codigo) {
        raiz->direita = insere_avl(cod, raiz->direita);
    }
    else {
        return raiz;
    }

    int altEsq = get_altura_avl(raiz->esquerda);
    int altDir = get_altura_avl(raiz->direita);

    raiz->altura = 1 + (altEsq > altDir ? altEsq : altDir);

    int fb = fatorBalanceamento_avl(raiz);

    if (fb > 1 && cod < raiz->esquerda->codigo) {
        return rotacaoDireita_avl(raiz);
    }
    if (fb < -1 && cod > raiz->direita->codigo) {
        return rotacaoEsquerda_avl(raiz);
    }

    if (fb > 1 && cod > raiz->esquerda->codigo) {
        return rotacaoDuplaDireita_avl(raiz);
    }

    if (fb < -1 && cod < raiz->direita->codigo) {
        return rotacaoDuplaEsquerda_avl(raiz);
    }
    return raiz;
}

int fatorBalanceamento_avl(Vertice *raiz){
    return get_altura_avl(raiz->esquerda) - get_altura_avl(raiz->direita);
}

Vertice* rotacaoDireita_avl(Vertice* raiz){
    Vertice* novaRaiz = raiz->esquerda;
    raiz->esquerda = novaRaiz->direita;
    novaRaiz->direita = raiz;

    int altEsq = get_altura_avl(raiz->esquerda);
    int altDir = get_altura_avl(raiz->direita);
    raiz->altura = 1 + (altEsq > altDir ? altEsq : altDir);

    altEsq = get_altura_avl(novaRaiz->esquerda);
    altDir = get_altura_avl(novaRaiz->direita);
    novaRaiz->altura = 1 + (altEsq > altDir ? altEsq : altDir);

    return novaRaiz;
}

Vertice* rotacaoEsquerda_avl(Vertice* raiz){
    Vertice* novaRaiz = raiz->direita;
    raiz->direita = novaRaiz->esquerda;
    novaRaiz->esquerda = raiz;

    int altEsq = get_altura_avl(raiz->esquerda);
    int altDir = get_altura_avl(raiz->direita);
    raiz->altura = 1 + (altEsq > altDir ? altEsq : altDir);

    altEsq = get_altura_avl(novaRaiz->esquerda);
    altDir = get_altura_avl(novaRaiz->direita);
    novaRaiz->altura = 1 + (altEsq > altDir ? altEsq : altDir);

    return novaRaiz;
}

Vertice* rotacaoDuplaDireita_avl(Vertice* raiz){
    raiz->esquerda = rotacaoEsquerda_avl(raiz->esquerda);
    return rotacaoDireita_avl(raiz);
}

Vertice* rotacaoDuplaEsquerda_avl(Vertice* raiz){
    raiz->direita = rotacaoDireita_avl(raiz->direita);
    return rotacaoEsquerda_avl(raiz);
}

void pre_ordem_avl(Vertice* raiz) {
    if(raiz != NULL) {
        printf("%d \n", raiz->codigo);
        pre_ordem_avl(raiz->esquerda);
        pre_ordem_avl(raiz->direita);
    }
}

Vertice* insere_varios_avl(Vertice* raiz,int *valores, int tam){
    for(int i=0;i<tam;i++){
        raiz = insere_avl(valores[i],raiz);
    }
    return raiz;
}
double medir_tempo_avl(Vertice *raiz, int *procurados){
    clock_t inicio,fim;
    double comparacao_media=0;
    inicio = clock();
    for(int i=0;i<5000;i++){
    comparacao_media +=pesquisa_avl(procurados[i],raiz,0);
    }
    fim = clock();
    printf("Tempo medio para buscar: %f segundos\n", (double)(fim-inicio)/CLOCKS_PER_SEC);
    printf("Quantidade de comparacoes media para buscar: %f\n",comparacao_media/5000);
    return comparacao_media;
}

int pesquisa_avl(int cod, Vertice* raiz, int cont) {
    if(raiz == NULL) {
        return -1;
    }
    else if(cod < raiz->codigo) {
        return pesquisa_avl(cod, raiz->esquerda,cont+1);
    }
    else if(cod > raiz->codigo) {
        return pesquisa_avl(cod, raiz->direita,cont+1);
    }
    else {
        return cont+1;
    }
}
