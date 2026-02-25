#include <stdio.h>
#include <time.h>

void printArray(int arr[], int n){
    for(int i = 0; i < n; i++){
        printf("%d ", arr[i]);
    }
    printf("\n");
}

void selectionSort(int arr[], int n){
    for(int i = 0; i < n-1; i++){ // divide o vetor em parte ordenada e não ordenada
        int min = i;
        for(int j = i+1; j < n; j++){
            if(arr[j] < arr[min]){ // busca o menor elemento da parte não ordenada
                min = j;
            }
        }
        int temp = arr[i]; // realiza uma troca colocando-o na posição correta
        arr[i] = arr[min];
        arr[min] = temp;
    }
}

int main(){

    int arr[] = {45, 41, 38, 36, 32, 28, 25, 22, 21, 19, 18, 17, 16, 10, 9, 8, 7, 6, 5, 4};
    int n = sizeof(arr)/sizeof(arr[0]);

    printf("Array original:\n");
    printArray(arr, n);
    
    selectionSort(arr, n);

    clock_t inicio, fim;

    inicio = clock();

    fim = clock();

	double tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;

	printf("Array ordenado:\n");
    printArray(arr, n);

    printf("Tempo de execucao: %f segundos\n", tempo);

    return 0;
}
