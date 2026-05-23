#include <stdio.h>

void selectionSort(int vetor[], int n) {
    int i, j, min_idx, temp;

    // Percorre todo o vetor
    for (i = 0; i < n - 1; i++) {
        // Assume que o menor elemento está na posição atual
        min_idx = i;

        // Procura o menor elemento no restante do vetor
        for (j = i + 1; j < n; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }

        // Troca o menor elemento encontrado com o elemento atual
        temp = vetor[min_idx];
        vetor[min_idx] = vetor[i];
        vetor[i] = temp;
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
    int vetor[] = {29, 10, 14, 37, 13};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    selectionSort(vetor, tamanho);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}
