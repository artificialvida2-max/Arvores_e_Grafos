#include <stdio.h>
#include <time.h>

void printArray(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");
}

int partition(int arr[], int low, int high){
    int pivot=arr[high]; // Um elemento é escolhido como pivô
    int i=low-1;

    for(int j=low;j<high;j++){ // elementos menores ficam à esquerda e maiores à direita
        if(arr[j]<pivot){
            i++;
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    int temp=arr[i+1]; // o algoritmo é aplicado recursivamente às duas partes até ordenar o vetor
    arr[i+1]=arr[high];
    arr[high]=temp;
    return i+1;
}

void quickSort(int arr[], int low, int high){
    if(low<high){
        int pi=partition(arr,low,high);
        quickSort(arr,low,pi-1);
        quickSort(arr,pi+1,high);
    }
}

int main(){
    int arr[]={45, 41, 38, 36, 32, 28, 25, 22, 21, 19, 18, 17, 16, 10, 9, 8, 7, 6, 5, 4};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original:\n");
    printArray(arr,n);

    quickSort(arr,0,n-1);
    
    clock_t inicio, fim;

    inicio = clock();

    fim = clock();

	double tempo = (double)(fim - inicio) * 1000 / CLOCKS_PER_SEC;
	
    printf("Ordenado:\n");
    printArray(arr,n);

    printf("Tempo de execucao: %f segundos\n", tempo);

    return 0;
}
