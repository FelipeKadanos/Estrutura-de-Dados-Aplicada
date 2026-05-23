#include <stdio.h>

// Função para juntar (merge) duas metades ordenadas
void merge(int vetor[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    // Vetores temporários
    int L[n1], R[n2];

    // Copiar dados para vetores temporários
    for (i = 0; i < n1; i++)
        L[i] = vetor[esquerda + i];
    for (j = 0; j < n2; j++)
        R[j] = vetor[meio + 1 + j];

    // Mesclar os vetores temporários de volta ao vetor original
    i = 0; 
    j = 0; 
    k = esquerda;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            vetor[k] = L[i];
            i++;
        } else {
            vetor[k] = R[j];
            j++;
        }
        k++;
    }

    // Copiar os elementos restantes
    while (i < n1) {
        vetor[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        vetor[k] = R[j];
        j++;
        k++;
    }
}

// Função recursiva do Merge Sort
void mergeSort(int vetor[], int esquerda, int direita) {
    if (esquerda < direita) {
        int meio = esquerda + (direita - esquerda) / 2;

        // Ordena a primeira metade
        mergeSort(vetor, esquerda, meio);

        // Ordena a segunda metade
        mergeSort(vetor, meio + 1, direita);

        // Junta as duas metades
        merge(vetor, esquerda, meio, direita);
    }
}

void imprimirVetor(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        printf("%d ", vetor[i]);
    }
    printf("\n");
}

int main() {
    int vetor[] = {38, 27, 43, 3, 9, 82, 10};
    int tamanho = sizeof(vetor) / sizeof(vetor[0]);

    printf("Vetor original:\n");
    imprimirVetor(vetor, tamanho);

    mergeSort(vetor, 0, tamanho - 1);

    printf("Vetor ordenado:\n");
    imprimirVetor(vetor, tamanho);

    return 0;
}


