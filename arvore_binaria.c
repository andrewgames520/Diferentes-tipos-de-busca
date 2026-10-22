#include "arvore_binaria.h"

void cria_arvore(Arvore* arv) {
    arv->raiz = NULL;
}

boolean eh_nulo(No* raiz) {
    return (raiz == NULL);
}
No* insere(int cod, No* raiz) {
    // Cria o novo nó
    No* novo = (No*) malloc(sizeof(No));
    novo->codigo = cod;
    novo->esquerda = NULL;
    novo->direita = NULL;

    // Se a árvore estiver vazia, o novo nó é a raiz
    if (raiz == NULL) {
        return novo;
    }

    No* atual = raiz;
    No* pai = NULL;

    // Percorre a árvore até achar a posição vazia (NULL)
    while (atual != NULL) {
        pai = atual;
        if (cod < atual->codigo) {
            atual = atual->esquerda;
        } else if (cod > atual->codigo) {
            atual = atual->direita;
        } else {
            // Se o número já existir, não faz nada
            free(novo);
            return raiz;
        }
    }

    // Insere o novo nó no pai encontrado
    if (cod < pai->codigo) {
        pai->esquerda = novo;
    } else {
        pai->direita = novo;
    }

    return raiz;
}

int pesquisa(int cod, No* raiz) {
    No* atual = raiz;
    int cont =0;
    // Percorre a árvore com um laço em vez de chamar a si mesma
    while (atual != NULL) {
            cont ++;
        if (cod == atual->codigo) {
            return cont; // Achou
        }
        else if (cod < atual->codigo) {
            atual = atual->esquerda;
        }
        else {
            atual = atual->direita;
        }
    }

    return -1; // Chegou no fim (NULL) e não achou
}

No* antecessor(No *atual, No *ant) {
    if(ant->direita != NULL)
        ant->direita = antecessor(atual, ant->direita);
    else {
        No *aux;
        atual->codigo = ant->codigo;
        aux = ant;
        ant = ant->esquerda;
        free(aux);
    }
    return ant;
}

No* remocao(int cod, No* raiz) {
    No* aux;
    if(raiz == NULL)
        return NULL;
    else if(cod < raiz->codigo)
        raiz->esquerda = remocao(cod, raiz->esquerda);
    else if(cod > raiz->codigo)
        raiz->direita = remocao(cod, raiz->direita);
    else if(raiz->direita == NULL) {
        aux = raiz;
        raiz = raiz->esquerda;
        free(aux);
    }
    else if(raiz->esquerda == NULL) {
        aux = raiz;
        raiz = raiz->direita;
        free(aux);
    }
    else {
        raiz->esquerda = antecessor(raiz, raiz->esquerda);
    }
    return raiz;
}

void pre_ordem(No* raiz) {
    if(raiz != NULL) {
        printf("%d \n", raiz->codigo);
        pre_ordem(raiz->esquerda);
        pre_ordem(raiz->direita);
    }
}

void acharMaior(No *raiz){
    if(raiz != NULL){
        acharMaior(raiz->direita);
        if(raiz->direita == NULL){
            printf("%d\n", raiz->codigo);
        }
    }
}

No* insere_varios(No* raiz,int *valores, int tam){
    for(int i=0;i<tam;i++){
        raiz = insere(valores[i],raiz);
    }
    return raiz;
}

double medir_tempo(No* raiz, int *procurados){
    clock_t inicio,fim;
    double comparacao_media=0;
    inicio = clock();

    for(int i =0;i<5000;i++){
       comparacao_media += pesquisa(procurados[i],raiz);
    }
    fim = clock();
    printf("Tempo medio para buscar: %f segundos\n", (double)(fim-inicio)/CLOCKS_PER_SEC);
    printf("Quantidade de comparacoes media para buscar: %f\n",comparacao_media/5000);
    return comparacao_media;
}
