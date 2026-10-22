#include "vetor_desordenado.h"

void criar_desordenado(int* vetor, int tamanho){
     for(int i =0; i<tamanho;i++){
            vetor[i] = i;
        }



        // 2. Algoritmo de Fisher-Yates para embaralhar o vetor
        for (int i = tamanho - 1; i > 0; i--) {
            unsigned int j = ((rand() << 15) | rand()) % (i + 1);

            // Troca os elementos de posição
            int temp = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = temp;
        }
}

double busca(int *vetor, int *procurados, int tam){
    clock_t inicio,fim;
    int cont =0;
    double comparacao_media=0;
    inicio = clock();
    for(int i =0;i<5000;i++){
        for(int j=0;j<tam;j++){
            cont++;
            if(vetor[j] == procurados[i]){
                break;
            }
        }
        comparacao_media += cont;
        cont =0;
    }
    fim = clock();
    printf("Tempo medio para buscar: %f segundos\n", (double)(fim-inicio)/CLOCKS_PER_SEC);
    printf("Quantidade de comparacoes media para buscar: %f\n",comparacao_media/5000);
    return comparacao_media;
}

void criar_busca_desordenado(int *busca, int tamanho){
    // calloc já inicializa todas as 150001 posições com 0
    int *usados = (int *) calloc(tamanho + 1, sizeof(int));


    int preenchidos = 0;

    while (preenchidos < 5000) {
        // Gera número entre 0 e 150000
        unsigned int numero_sorteado = ((rand() << 15) | rand()) % (tamanho + 1);

        // Verifica se o número já foi usado
        if (usados[numero_sorteado] == 0) {
            busca[preenchidos] = numero_sorteado;
            usados[numero_sorteado] = 1; // Marca como usado
            preenchidos++;
        }
    }
    free(usados);
}
