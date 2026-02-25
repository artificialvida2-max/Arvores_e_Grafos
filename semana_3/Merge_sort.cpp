#include <stdio.h>
#include <time.h>

void printArray(int arr[], int n){
    for(int i=0;i<n;i++) printf("%d ", arr[i]);
    printf("\n");
}

void merge(int arr[], int l, int m, int r){
    int n1=m-l+1;
    int n2=r-m;

    int L[n1],R[n2]; // divide o vetor repetidamente em duas partes menores

    for(int i=0;i<n1;i++) L[i]=arr[l+i]; // Quando cada parte possui um elemento, inicia-se a intercalação
    for(int j=0;j<n2;j++) R[j]=arr[m+1+j];

    int i=0,j=0,k=l;

    while(i<n1 && j<n2){ // as partes são combinadas novamente de forma ordenada
        if(L[i]<=R[j]) arr[k++]=L[i++];
        else arr[k++]=R[j++];
    }

    while(i<n1) arr[k++]=L[i++]; // o processo continua até reconstruir o vetor totalmente ordenado
    while(j<n2) arr[k++]=R[j++];
}

void mergeSort(int arr[], int l, int r){
    if(l<r){
        int m=l+(r-l)/2;
        mergeSort(arr,l,m);
        mergeSort(arr,m+1,r);
        merge(arr,l,m,r);
    }
}

int main(){
    int arr[]={45, 41, 38, 36, 32, 28, 25, 22, 21, 19, 18, 17, 16, 10, 9, 8, 7, 6, 5, 4};
    int n=sizeof(arr)/sizeof(arr[0]);

    printf("Original:\n");
    printArray(arr,n);

    mergeSort(arr,0,n-1);

    clock_t inicio, fim;
    
    double tempo;

    inicio = clock();

    fim = clock();

    tempo = (double)(fim - inicio) / CLOCKS_PER_SEC;


    printf("Ordenado:\n");
    printArray(arr,n);

    
    printf("Tempo de execucao: %f segundos\n", tempo);

    return 0;
}
