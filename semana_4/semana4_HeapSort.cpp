#include <stdio.h>

// troca dois valores
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// mantem a regra do max-heap: pai maior que filhos
void heapify(int arr[], int n, int i) {
    int maior = i;             // assume que a raiz e a maior
    int esquerda = 2 * i + 1;  // pega o filho da esquerda
    int direita = 2 * i + 2;   // pega o filho da direita

    // ve se o filho esquerdo e maior
    if (esquerda < n && arr[esquerda] > arr[maior]) {
        maior = esquerda;
    }

    // ve se o filho direito e o maior de todos
    if (direita < n && arr[direita] > arr[maior]) {
        maior = direita;
    }

    // se a raiz nao for a maior, troca
    if (maior != i) {
        trocar(&arr[i], &arr[maior]);
        
        // arruma os filhos de novo
        heapify(arr, n, maior);
    }
}

// transforma vetor normal em max-heap
void construirMaxHeap(int arr[], int n) {
    // sobe do ultimo pai ate a raiz
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }
}

// imprime o vetor
void imprimirVetor(int arr[], int n) {
    printf("[ ");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("]\n");
}

int main() {
    // vetor do exercicio
    int arr[] = {30, 12, 45, 6, 18, 3};
    int n = sizeof(arr) / sizeof(arr[0]);

    printf("Vetor original\n");
    imprimirVetor(arr, n);

    // === resposta a ===
    construirMaxHeap(arr, n);
    
    printf("\nVetor apos construir o max heap\n");
    imprimirVetor(arr, n);

    // === resposta b ===
    
    // joga o maior valor pro final
    trocar(&arr[0], &arr[n - 1]);
    
    // diminui o tamanho do heap
    int tamanho_heap = n - 1;
    
    // arruma a nova raiz
    heapify(arr, tamanho_heap, 0);

    printf("\nVetor apos a primeira extracao da raiz\n");
    imprimirVetor(arr, n); // mostra tudo com o 45 no fim

    return 0;
}
