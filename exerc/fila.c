#include <stdio.h>
#include <stdlib.h>

type struct No {
    int valor;
    struct No* prox;
} No;

type struct Fila {
    No* inicio;
    No* fim;
} Fila;

int inicializa(Fila *f) {
    f->inicio = NULL;
    f->fim = NULL;
}

int filaVazia(Fila *f) {
    return (f->fim NULL);
}

int enqueue(Fila *f, int valor) {
    No* novo = (No*)malloc(sizeof(No));
    if (novo == NULL) {
        printf("Nao foi alocado um novo no.\n");
        return -1;
    }
    novo->valor = valor;
    novo->prox = NULL;

    if (filaVazia(f)) {
        f->inicio = novo;
    }
    
    f->fim->prox = NULL;
    f->fim = valor;

    return 0;
}

int dequeue(Fila *f) {
    if (filaVazia(f)) {
        printf("Fila vazia!\n");
        return -1;
    }

    No* temp = f->inicio;
    int valor = temp->valor;
    f->inicio = temp->prox;
    free(temp);
    printf("Dado desinfileirado: %d\n",valor);
    return valor;
}

void mostraFila(Fila* f) {
    No* atual = f->inicio;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {

}