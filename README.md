# Comparativo de Estruturas de Busca

Este repositório contém a implementação e a análise de desempenho de diferentes estruturas de dados utilizadas para realizar buscas: Vetor Desordenado (Busca Linear), Vetor Ordenado (Busca Binária), Árvore Binária de Busca (ABB) e Árvore AVL.

O objetivo do experimento é demonstrar, na prática, como a organização dos dados e a escolha do algoritmo afetam a eficiência da pesquisa. Foram realizadas 5.000 buscas para conjuntos de dados de 50.000, 100.000 e 150.000 elementos distintos utilizando os mesmos alvos de pesquisa.

## Resultados dos Experimentos

Os tempos medidos referem-se estritamente à operação de busca, desconsiderando o tempo gasto para alocação e inserção/construção das estruturas.

### Conjunto de 50.000 Elementos

| Estrutura | Tempo Médio (s) | Comparações Médias |
|---|---|---|
| **Vetor Desordenado** | 0.229 | 25.346,15 |
| **ABB Ordenada (Pior Caso)** | 0.325 | 24.972,20 |
| **ABB Desordenada** | 0.002 | 20,88 |
| **Árvore AVL** | 0.002 | 14,93 |
| **Vetor Ordenado (Binária)** | 0.000 | 14,67 |

### Conjunto de 100.000 Elementos

| Estrutura | Tempo Médio (s) | Comparações Médias |
|---|---|---|
| **Vetor Desordenado** | 0.443 | 49.432,00 |
| **ABB Ordenada (Pior Caso)** | 0.713 | 49.987,71 |
| **ABB Desordenada** | 0.002 | 21,74 |
| **Árvore AVL** | 0.002 | 15,94 |
| **Vetor Ordenado (Binária)** | 0.001 | 15,65 |

### Conjunto de 150.000 Elementos

| Estrutura | Tempo Médio (s) | Comparações Médias |
|---|---|---|
| **Vetor Desordenado** | 0.694 | 75.858,94 |
| **ABB Ordenada (Pior Caso)** | 0.917 | 74.088,71 |
| **ABB Desordenada** | 0.002 | 21,99 |
| **Árvore AVL** | 0.002 | 16,55 |
| **Vetor Ordenado (Binária)** | 0.001 | 16,23 |

## Análise dos Resultados

Os experimentos evidenciam a divisão clara de complexidade algorítmica entre as abordagens adotadas.

* **Desempenho Logarítmico $O(\log N)$:** A Busca Binária no vetor ordenado, a Árvore AVL e a ABB desordenada demonstraram eficiência extrema, resolvendo buscas em frações de milissegundos com menos de 25 comparações, mesmo no cenário de 150.000 elementos. A Busca Binária apresentou vantagem marginal em tempo bruto devido à leitura contígua da memória (localidade de cache), enquanto a Árvore AVL garantiu o menor número de comparações entre as árvores graças ao seu rigoroso auto-balanceamento.
* **Desempenho Linear $O(N)$:** O Vetor Desordenado comportou-se de maneira linear. Conforme a base de dados dobrou e triplicou, a quantidade de comparações e o tempo de busca cresceram na mesma proporção.
* **Degradação no Pior Caso:** A inserção de dados sequenciais na ABB comum confirmou a fragilidade da estrutura sem balanceamento. A árvore degenerou-se para uma "lista encadeada", forçando a busca a operar em tempo linear. Como a navegação ocorreu por ponteiros na memória, o tempo bruto de execução da ABB ordenada foi o pior entre todas as estruturas testadas.