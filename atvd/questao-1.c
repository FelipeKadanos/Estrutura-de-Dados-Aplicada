#include <stdio.h>

/* Quantidade maxima de clientes que a fila consegue armazenar. */
#define MAX 100

/**
 * Representa uma fila circular de clientes.
 * dados guarda os IDs, inicio aponta para o proximo atendimento, fim aponta para a proxima posicao livre e tamanho controla quantos clientes existem.
 */
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

/**
 * Define a fila como vazia antes do primeiro uso.
 * @param fila Ponteiro para a fila que sera inicializada.
 * @return Nao retorna valor.
 */
void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

/**
 * Verifica se nao existe nenhum cliente aguardando atendimento.
 * @param fila Fila que sera consultada.
 * @return int|bool 1|true se a fila estiver vazia ou 0|false caso contrario.
 */
int filaVazia(Fila *fila) {
    return fila->tamanho == 0;
}

/**
 * Verifica se a fila ja atingiu a capacidade maxima.
 * @param fila Fila que sera consultada.
 * @return int|bool 1|true se a fila estiver cheia ou 0|false caso contrario.
 */
int filaCheia(Fila *fila) {
    return fila->tamanho == MAX;
}

/**
 * Insere um cliente no fim da fila de atendimento.
 * @param fila Fila que recebera o cliente.
 * @param id Identificador do cliente que sera inserido.
 * @return int|bool 1|true se a insercao ocorrer ou 0|false se a fila estiver cheia.
 */
int inserirFila(Fila *fila, int id) {
    if (filaCheia(fila)) {
        return 0;
    }

    /* O cliente entra no fim da fila, respeitando a ordem de chegada. */
    fila->dados[fila->fim] = id;
    fila->fim = (fila->fim + 1) % MAX;
    fila->tamanho++;
    return 1;
}

/**
 * Remove o cliente que esta no inicio da fila para atendimento.
 * @param fila Fila de onde o cliente sera removido.
 * @param id Ponteiro que recebera o ID do cliente atendido.
 * @return int|bool 1|true se a remocao ocorrer ou 0|false se a fila estiver vazia.
 */
int removerFila(Fila *fila, int *id) {
    if (filaVazia(fila)) {
        return 0;
    }

    /* A remocao sempre acontece pelo inicio, mantendo o comportamento FIFO. */
    *id = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->tamanho--;
    return 1;
}

/**
 * Consulta o proximo cliente sem remove-lo da fila.
 * @param fila Fila que sera consultada.
 * @param id Ponteiro que recebera o ID do proximo cliente.
 * @return int|bool 1|true se existir proximo cliente ou 0|false se a fila estiver vazia.
 */
int proximoFila(Fila *fila, int *id) {
    if (filaVazia(fila)) {
        return 0;
    }

    *id = fila->dados[fila->inicio];
    return 1;
}

/**
 * Exibe o menu da questao 1 e executa as operacoes da fila de atendimento.
 * @return int Codigo de encerramento do programa.
 */
int main(void) {
    Fila fila;
    int opcao;
    int id;

    inicializarFila(&fila);

    do {
        printf("\n--- Questao 1: Fila de atendimento ---\n");
        printf("1 - Inserir cliente\n");
        printf("2 - Atender cliente\n");
        printf("3 - Mostrar proximo cliente\n");
        printf("4 - Mostrar tamanho da fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o ID do cliente: ");
                scanf("%d", &id);

                if (inserirFila(&fila, id)) {
                    printf("Cliente %d inserido na fila.\n", id);
                } else {
                    printf("A fila esta cheia.\n");
                }
                break;
            case 2:
                if (removerFila(&fila, &id)) {
                    printf("\nCliente %d atendido e removido da fila.\n", id);
                } else {
                    printf("\nNao ha clientes para atender.\n");
                }
                break;
            case 3:
                if (proximoFila(&fila, &id)) {
                    printf("\nProximo cliente: %d\n", id);
                } else {
                    printf("\nA fila esta vazia.\n");
                }
                break;
            case 4:
                printf("\nTamanho da fila: %d\n", fila.tamanho);
                break;
            case 0:
                printf("\nEncerrando questao 1.\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
