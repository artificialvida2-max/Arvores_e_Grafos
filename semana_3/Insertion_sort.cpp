#include <stdio.h>
#include <time.h>

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void insertionSort(int arr[], int n){
    for(int i = 1; i < n; i++){
        int key = arr[i]; // constrói o vetor ordenado gradualmente
        int j = i - 1;

        while(j >= 0 && arr[j] > key){
            arr[j+1] = arr[j];
            j--;
        }
        arr[j+1] = key;
    }
}

int main(){

    int arr[] = {45, 41, 38, 36, 32, 28, 25, 22, 21, 19, 18, 17, 16, 10, 9, 8, 7, 6, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);

    insertionSort(arr, n);

    clock_t inicio, fim;
    
    double tempo;

    inicio = clock();

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;

    printf("Array ordenado:\n");
    printArray(arr, n);

    printf("Tempo de execucao: %f segundos\n", tempo);

    return 0;
}
