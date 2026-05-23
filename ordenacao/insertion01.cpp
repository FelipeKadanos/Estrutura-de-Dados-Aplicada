#include <stdio.h>

void insertionSort(int vetor[], int n) {
    int i, chave, j;

    // Percorre o vetor a partir do segundo elemento
    for (i = 1; i < n; i++) {
        chave = vetor[i];
        j = i - 1;

        // Move os elementos maiores que a chave
        // uma posição à frente
        while (j >= 0 && vetor[j] > chave) {
            vetor[j + 1] = vetor[j];
            j = j - 1;
        }

        // Insere a chave na posição correta
        vetor[j + 1] = chave;
    }
}

void imprimirVetor(int vetor[], int n) {
    int i;
    for (i = 0; i < n; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {12, 11, 13, 5, 6};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    insertionSort(vetor, tamanho);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
