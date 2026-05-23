#include <stdio.h>
#include <stdbool.h>
#define MAX 100


typedef int vetor[MAX];

void Trocar (int *x, int *y) { 
	int temp;  
	temp = *x; *x = *y; *y = temp;  
}


// Bubble Sort com otimização
void BubbleSort(int n, vetor V) {
    int i, p;  
    bool trocou;

    for (p = n - 2, trocou = true; p >= 0 && trocou; p--) {
        trocou = false;

        for (i = 0; i <= p; i++) {
            if (V[i] > V[i + 1]) {
                Trocar(&V[i], &V[i + 1]);  
                trocou = true;
            }
        }
    }
}


// Programa principal
int main() {
    vetor V;
    int n, i;

    printf("Quantos elementos deseja ordenar? ");
    scanf("%d", &n);

    printf("Digite os elementos:\n");
    for (i = 0; i < n; i++) {
        scanf("%d", &V[i]);
    }

    BubbleSort(n, V);

    printf("\nVetor ordenado:\n");
    for (i = 0; i < n; i++) {
        printf("%d ", V[i]);
    }

    printf("\n");
    return 0;
}


