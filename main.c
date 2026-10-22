#include "arvore_binaria.h"
#include "vetor_desordenado.h"
#include "arvore_AVL.h"


#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void criar_ordenado(int* vetor,int tam){
     for(int i =0; i<tam;i++){
            vetor[i] = i;
        }
}

int busca_binaria(int *vetor, int valor, int tam) {
    int i, esq, dir,cont;
    cont =0;
    if(tam == 0){
        printf("erro");
        return -1;
    }
    else {
        esq = 0;
        dir = tam - 1;
        do {
            i = (esq+dir)/2;
            if(valor > vetor[i])
                esq = i + 1;
            else
                dir = i - 1;
            cont++;
        } while(valor != vetor[i] && esq <= dir);
        if(valor == vetor[i])
            return cont;
        else
            return -1;
    }
}


double medir_tempo_ordenado(int *vetor, int *procurados, int tam){
    clock_t inicio,fim;
    double comparacao_media=0;
    inicio = clock();
    for(int i=0;i<5000;i++){
       comparacao_media += busca_binaria(vetor,procurados[i],tam);
    }
    fim = clock();
    printf("Tempo medio para buscar: %f segundos\n", (double)(fim-inicio)/CLOCKS_PER_SEC);
    printf("Quantidade de comparacoes media para buscar: %f\n",comparacao_media/5000);
    return comparacao_media;
}

int main() {
 srand((unsigned int)time(NULL));

    int *procurados1 = (int *) malloc(5000*sizeof(int));
    int *procurados2 = (int *) malloc(5000*sizeof(int));
    int *procurados3 = (int *) malloc(5000*sizeof(int));
    criar_busca_desordenado(procurados1,50000);
    criar_busca_desordenado(procurados2,100000);
    criar_busca_desordenado(procurados3,150000);


    int *vetor_desordenado1 = (int*) malloc(50000*sizeof(int));
    int *vetor_desordenado2 = (int*) malloc(100000*sizeof(int));
    int *vetor_desordenado3 = (int*) malloc(150000*sizeof(int));

    criar_desordenado(vetor_desordenado1,50000);
    criar_desordenado(vetor_desordenado2,100000);
    criar_desordenado(vetor_desordenado3,150000);

    printf("\nVetor desordenado de 50k termos\n");
    busca(vetor_desordenado1,procurados1,50000);
    printf("\nVetor desordenado de 100k termos\n");
    busca(vetor_desordenado2,procurados2,100000);
    printf("\nVetor desordenado de 50k termos\n");
    busca(vetor_desordenado3,procurados3,150000);

    Arvore ABB1, ABB2, ABB3;
    cria_arvore(&ABB1);
    cria_arvore(&ABB2);
    cria_arvore(&ABB3);

    ABB1.raiz = insere_varios(ABB1.raiz,vetor_desordenado1,50000);
    ABB2.raiz = insere_varios(ABB2.raiz,vetor_desordenado2,100000);
    ABB3.raiz = insere_varios(ABB3.raiz,vetor_desordenado3,150000);



    printf("\nABB desorndenada de 50k termos\n");
    medir_tempo(ABB1.raiz,procurados1);
     printf("\nABB desorndenada de 100k termos\n");
    medir_tempo(ABB2.raiz,procurados2);
     printf("\nABB desorndenada de 150k termos\n");
    medir_tempo(ABB3.raiz,procurados3);

    Arvore_AVL AVL1, AVL2,AVL3;
    cria_arvore_avl(&AVL1);
    cria_arvore_avl(&AVL2);
    cria_arvore_avl(&AVL3);

    AVL1.raiz = insere_varios_avl(AVL1.raiz,vetor_desordenado1,50000);
    AVL2.raiz = insere_varios_avl(AVL2.raiz,vetor_desordenado2,100000);
    AVL3.raiz = insere_varios_avl(AVL3.raiz,vetor_desordenado3,150000);

    printf("\nAVL de 50k termos\n");
    medir_tempo_avl(AVL1.raiz,procurados1);
    printf("\nAVL de 100k termos\n");
    medir_tempo_avl(AVL2.raiz,procurados2);
    printf("\nAVL de 150k termos\n");
    medir_tempo_avl(AVL3.raiz,procurados3);

    int *vetor_ordenado1 = (int*) malloc(50000*sizeof(int));
    int *vetor_ordenado2 = (int*) malloc(100000*sizeof(int));
    int *vetor_ordenado3 = (int*) malloc(150000*sizeof(int));

    criar_ordenado(vetor_ordenado1,50000);
    criar_ordenado(vetor_ordenado2,100000);
    criar_ordenado(vetor_ordenado3,150000);

    printf("\nVetor ordenado de 50k termos\n");
    medir_tempo_ordenado(vetor_ordenado1,procurados1,50000);
    printf("\nVetor ordenado de 100k termos\n");
    medir_tempo_ordenado(vetor_ordenado2,procurados2,100000);
    printf("\nVetor ordenado de 150k termos\n");
    medir_tempo_ordenado(vetor_ordenado3,procurados3,150000);


    Arvore ABB_ordenada1, ABB_ordenada2, ABB_ordenada3;

    cria_arvore(&ABB_ordenada1);
    cria_arvore(&ABB_ordenada2);
    cria_arvore(&ABB_ordenada3);

    ABB_ordenada1.raiz = insere_varios(ABB_ordenada1.raiz,vetor_ordenado1,50000);
    ABB_ordenada2.raiz = insere_varios(ABB_ordenada2.raiz,vetor_ordenado2,100000);
    ABB_ordenada3.raiz = insere_varios(ABB_ordenada3.raiz,vetor_ordenado3,150000);

    printf("\nABB ordenada de 50k termos\n");
    medir_tempo(ABB_ordenada1.raiz,procurados1);
    printf("\nABB ordenada de 100k termos\n");
    medir_tempo(ABB_ordenada2.raiz,procurados2);
    printf("\nABB ordenada de 150k termos\n");
    medir_tempo(ABB_ordenada3.raiz,procurados3);

    return 0;
}
