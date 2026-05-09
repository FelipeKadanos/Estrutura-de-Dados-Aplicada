#include <stdio.h>
#include <stdlib.h>

type struct Pilha {
    int elemento;
    struct Pilha* prox;
} Pilha;

type struct Pilha {
    Pilha* inicio;
    Pilha* topo;
} Pilha;

int inicializa(Pilha *p) {
    p->inicio = NULL;
    p->topo = NULL;
}

int filaVazia(Pilha *p) {
    return (p->topo NULL);
}

int empilhar(Pilha *p, int elemento) {
    Pilha* novo = (Pilha*)malloc(sizeof(Pilha));
    if (novo == NULL) {
        printf("Memoria insuficiente!\n");
        return (0);
    }
    else {
        novo->elemento = x;
        novo->prox = p->topo;
        p->topo = novo;
        p->tamanho++;
    }

    return (1);
}

int empilhar(Pilha *p, int elemento) {
    Node* temp;
    if (p == NULL) {
        printf("Pilha vazia!\n");
        return (0);
    }
    else {
        temp = p->topo;
        int valor = temp->elemento;
        p->topo = temp->prox;
        p->tamanho--;
        free(temp);
        return (valor);
    }

}

void mostraFila(Pilha* p) {
    Pilha* atual = p->inicio;
    while (atual != NULL) {
        printf("%d ", atual->elemento);
        atual = atual->prox;
    }
    printf("\n");
}

int main() {

}