#include <stdio.h>

/* Quantidade maxima de valores que cada pilha consegue armazenar. */
#define MAX 100

/**
 * Representa uma pilha de numeros inteiros.
 * dados guarda os valores e topo indica a ultima posicao ocupada.
 */
typedef struct {
    int dados[MAX];
    int topo;
} Pilha;

/**
 * Define a pilha como vazia antes do primeiro uso.
 * @param pilha Ponteiro para a pilha que sera inicializada.
 * @return Nao retorna valor.
 */
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

/**
 * Verifica se a pilha ainda nao possui elementos.
 * @param pilha Pilha que sera consultada.
 * @return int|bool 1|true se a pilha estiver vazia ou 0|false caso contrario.
 */
int pilhaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

/**
 * Verifica se a pilha atingiu a capacidade maxima.
 * @param pilha Pilha que sera consultada.
 * @return int|bool 1|true se a pilha estiver cheia ou 0|false caso contrario.
 */
int pilhaCheia(Pilha *pilha) {
    return pilha->topo == MAX - 1;
}

/**
 * Insere um valor no topo da pilha.
 * @param pilha Pilha que recebera o valor.
 * @param valor Numero que sera empilhado.
 * @return int|bool 1|true se a insercao ocorrer ou 0|false se a pilha estiver cheia.
 */
int empilhar(Pilha *pilha, int valor) {
    if (pilhaCheia(pilha)) {
        return 0;
    }

    /* O novo elemento sempre entra no topo da pilha. */
    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
    return 1;
}

/**
 * Remove o valor que esta no topo da pilha.
 * @param pilha Pilha de onde o valor sera removido.
 * @param valor Ponteiro que recebera o numero desempilhado.
 * @return int|bool 1|true se a remocao ocorrer ou 0|false se a pilha estiver vazia.
 */
int desempilhar(Pilha *pilha, int *valor) {
    if (pilhaVazia(pilha)) {
        return 0;
    }

    /* A remocao acontece pelo topo, seguindo o comportamento LIFO da pilha. */
    *valor = pilha->dados[pilha->topo];
    pilha->topo--;
    return 1;
}

/**
 * Consulta o valor do topo sem remove-lo da pilha.
 * @param pilha Pilha que sera consultada.
 * @param valor Ponteiro que recebera o valor do topo.
 * @return int|bool 1|true se existir valor no topo ou 0|false se a pilha estiver vazia.
 */
int consultarTopo(Pilha *pilha, int *valor) {
    if (pilhaVazia(pilha)) {
        return 0;
    }

    *valor = pilha->dados[pilha->topo];
    return 1;
}

/**
 * Exibe o menu da questao 3 e controla a pilha principal e a pilha de minimos.
 * @return int Codigo de encerramento do programa.
 */
int main(void) {
    Pilha pilha;
    Pilha minimos;
    int opcao;
    int valor;
    int minimoAtual;

    inicializarPilha(&pilha);
    inicializarPilha(&minimos);

    do {
        printf("\n--- Questao 3: Pilha com minimo ---\n");
        printf("1 - Push/Empilhar\n");
        printf("2 - Pop/Desempilhar\n");
        printf("3 - getMin\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                printf("\nDigite o valor: ");
                scanf("%d", &valor);

                if (pilhaCheia(&pilha)) {
                    printf("A pilha esta cheia.\n");
                    break;
                }

                empilhar(&pilha, valor);

                /* A pilha minimos acompanha a pilha principal. Cada topo de
                   minimos guarda o menor valor existente na pilha principal. */
                if (pilhaVazia(&minimos)) {
                    empilhar(&minimos, valor);
                } else {
                    consultarTopo(&minimos, &minimoAtual);
                    empilhar(&minimos, valor < minimoAtual ? valor : minimoAtual);
                }

                printf("Valor %d empilhado.\n", valor);
                break;
            case 2:
                if (desempilhar(&pilha, &valor)) {
                    desempilhar(&minimos, &minimoAtual);
                    printf("\nValor %d desempilhado.\n", valor);
                } else {
                    printf("A pilha esta vazia.\n");
                }
                break;
            case 3:
                if (consultarTopo(&minimos, &minimoAtual)) {
                    printf("\nMenor elemento atual: %d\n", minimoAtual);
                } else {
                    printf("\nA pilha esta vazia.\n");
                }
                break;
            case 0:
                printf("\nEncerrando questao 3.\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
