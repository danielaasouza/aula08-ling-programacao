#include <stdio.h>

void preencherArray(int arr[], int n) {
    for(int i=0;i<n;i++) {
        printf("Número %d: ", i+1);
        scanf("%d", &arr[i]);
    }
}

void exibirArray(const int arr[], int n) {
    printf("[");
    for(int i=0;i<n;i++) {
        printf("%d", arr[i]);
        if(i<n-1) printf(", ");
    }
    printf("]\n");
}

int maior(const int arr[], int n) {
    int m = arr[0];
    for(int i=1;i<n;i++) if(arr[i]>m) m=arr[i];
    return m;
}

int menor(const int arr[], int n) {
    int m = arr[0];
    for(int i=1;i<n;i++) if(arr[i]<m) m=arr[i];
    return m;
}

float media(const int arr[], int n) {
    int soma=0;
    for(int i=0;i<n;i++) soma += arr[i];
    return (float)soma/n;
}

void ordenar(int arr[], int n) {
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            if(arr[j] < arr[i]) {
                int temp=arr[i]; arr[i]=arr[j]; arr[j]=temp;
            }
        }
    }
}

int main() {
    int n=10;
    int arr[10];
    printf("Digite 10 números:\n");
    preencherArray(arr,n);

    printf("Array original: "); 
    exibirArray(arr,n);
    
    printf("Maior valor: %d\n", maior(arr,n));
    printf("Menor valor: %d\n", menor(arr,n));
    printf("Média: %.2f\n", media(arr,n));
    ordenar(arr,n);
    printf("Array ordenado: "); exibirArray(arr,n);
    return 0;
}

