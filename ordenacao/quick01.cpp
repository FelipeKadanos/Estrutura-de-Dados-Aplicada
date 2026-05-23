#include <stdio.h>

// Função para trocar dois elementos
void trocar(int *a, int *b) {
    int temp = *a;
    *a = *b;
    *b = temp;
}

// Função de partição
int particao(int vetor[], int baixo, int alto) {
    int pivo = vetor[alto]; // escolhe o último elemento como pivô
    int i = (baixo - 1);

    for (int j = baixo; j < alto; j++) {
        if (vetor[j] < pivo) {
            i++;
            trocar(&vetor[i], &vetor[j]);
        }
    }

    trocar(&vetor[i + 1], &vetor[alto]);
    return (i + 1);
}

// Função recursiva do QuickSort
void quickSort(int vetor[], int baixo, int alto) {
    if (baixo < alto) {
        int pi = particao(vetor, baixo, alto);

        // Ordena elementos antes e depois do pivô
        quickSort(vetor, baixo, pi - 1);
        quickSort(vetor, pi + 1, alto);
    }
}

// Função para imprimir o vetor
void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {10, 7, 8, 9, 1, 5};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    quickSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}

