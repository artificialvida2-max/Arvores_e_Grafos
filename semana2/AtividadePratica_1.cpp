#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// variaveis globais para os dois algoritmos
long long comparacoes = 0;
long long movimentacoes = 0;

// funcao p resetar antes de cada comparacao
void resetarContadores() {
    comparacoes = 0;
    movimentacoes = 0;
}


void bubbleSort(int *vetor, int tamanho) {
    int i, j, temp;
    for (i = 0; i < tamanho - 1; i++) {
        for (j = 0; j < tamanho - i - 1; j++) {
            comparacoes++; // conta cada comparacao
            if (vetor[j] > vetor[j + 1]) {
                // realiza troca e conta o movimento
                temp = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = temp;
                movimentacoes++; 
            }
        }
    }
}


void selectionSort(int *vetor, int tamanho) {
    int i, j, min_idx, temp;
    for (i = 0; i < tamanho - 1; i++) {
        min_idx = i; // marca a posicao q tem o menor numero inicio 0
        for (j = i + 1; j < tamanho; j++) {
            comparacoes++; // contagem de comparacao
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j; //troca a posicao do index caso o num dentro da posicao vetor[j] for menor
            }
        }
        // verifica se na posicao i esta o menor numero
        if (min_idx != i) {
            temp = vetor[min_idx];
            vetor[min_idx] = vetor[i];
            vetor[i] = temp;
            movimentacoes++;
        }
    }
}

// preencher o vetor em ordem decrescente
void preencherVetor(int *vetor, int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = tamanho - i;
    }
}

int main() {
    int tamanhos[] = {100, 1000, 10000}; 
    int num_tamanhos = 3;
    
    printf("----------------------------------------------------------------------------------\n");
    printf("| %-14s | %-7s | %-10s | %-15s | %-15s |\n", "Algoritmo", "Tamanho", "Tempo(ms)", "Comparacoes", "Movimentacoes");
    printf("----------------------------------------------------------------------------------\n");

    // teste bubble
    for (int k = 0; k < num_tamanhos; k++) {
        int N = tamanhos[k];
        int *vetor = (int *)malloc(N * sizeof(int)); // alocacao dinamica

        //
        preencherVetor(vetor, N);
        resetarContadores();
        
        // config do tempo
        clock_t inicio = clock();
        bubbleSort(vetor, N);
        clock_t fim = clock();
        double tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;


        printf("| %-14s | %-7d | %-10.4f | %-15lld | %-15lld |\n", 
               "Bubble Sort", N, tempo_ms, comparacoes, movimentacoes);

        free(vetor);
    }

    // teste sort
    for (int k = 0; k < num_tamanhos; k++) {
        int N = tamanhos[k];
        int *vetor = (int *)malloc(N * sizeof(int)); 

        
        preencherVetor(vetor, N);
        resetarContadores();
        
        
        clock_t inicio = clock();
        selectionSort(vetor, N);
        clock_t fim = clock();
        double tempo_ms = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

        
        printf("| %-14s | %-7d | %-10.4f | %-15lld | %-15lld |\n", 
               "Selection Sort", N, tempo_ms, comparacoes, movimentacoes);

        free(vetor);
    }
    

    return 0;
}
/* Comparando os dois algoritmos pode-se perceber que bubble sort e selection sort possuem a mesma quantidade de comparacoes
levando em conta o pior cenário e também escalam seu tempo de execução conforme o vetor aumenta, o que os torna inadequados para
grandes volumes de dados.
Selection Sort possui um tempo de execução menor por executar menos trocas/escritas o que pode ser bom para a vida útil da memoria ram
*/
