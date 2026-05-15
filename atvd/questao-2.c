#include <stdio.h>

/* Quantidade maxima de valores que a fila consegue armazenar. */
#define MAX 100

/**
 * Representa uma fila circular de numeros.
 * dados guarda os valores, inicio aponta para o primeiro elemento, fim aponta para a proxima posicao livre e tamanho controla a quantidade armazenada.
 */
typedef struct {
    int dados[MAX];
    int inicio;
    int fim;
    int tamanho;
} Fila;

/**
 * Define a fila como vazia antes de receber os valores do teste.
 * @param fila Ponteiro para a fila que sera inicializada.
 * @return Nao retorna valor.
 */
void inicializarFila(Fila *fila) {
    fila->inicio = 0;
    fila->fim = 0;
    fila->tamanho = 0;
}

/**
 * Verifica se nao existe nenhum valor armazenado na fila.
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
 * Insere um valor no fim da fila.
 * @param fila Fila que recebera o valor.
 * @param valor Numero que sera inserido.
 * @return int|bool 1|true se a insercao ocorrer ou 0|false se a fila estiver cheia.
 */
int inserirFila(Fila *fila, int valor) {
    if (filaCheia(fila)) {
        return 0;
    }

    /* A insercao ocorre no fim para preservar a ordem informada pelo usuario. */
    fila->dados[fila->fim] = valor;
    fila->fim = (fila->fim + 1) % MAX;
    fila->tamanho++;
    return 1;
}

/**
 * Remove o valor que esta no inicio da fila.
 * @param fila Fila de onde o valor sera removido.
 * @param valor Ponteiro que recebera o numero removido.
 * @return int|bool 1|true se a remocao ocorrer ou 0|false se a fila estiver vazia.
 */
int removerFila(Fila *fila, int *valor) {
    if (filaVazia(fila)) {
        return 0;
    }

    /* A fila entrega os valores na mesma ordem em que eles foram inseridos. */
    *valor = fila->dados[fila->inicio];
    fila->inicio = (fila->inicio + 1) % MAX;
    fila->tamanho--;
    return 1;
}

/**
 * Le os valores da fila e verifica se a sequencia forma um palindromo.
 * @return Nao retorna valor.
 */
void testarPalindromo(void) {
    Fila fila;
    int vetor[MAX];
    int quantidade;
    int valor;
    int palindromo = 1;
    int i;

    inicializarFila(&fila);

    printf("\nQuantos numeros deseja inserir na fila? ");
    scanf("%d", &quantidade);

    if (quantidade < 1 || quantidade > MAX) {
        printf("Quantidade invalida. Use um valor entre 1 e %d.\n", MAX);
        return;
    }

    for (i = 0; i < quantidade; i++) {
        printf("Digite o %do numero: ", i + 1);
        scanf("%d", &valor);
        inserirFila(&fila, valor);
    }

    /* A fila guarda a ordem de entrada. Para verificar o palindromo, os valores
       sao removidos na ordem da fila e comparados por um vetor auxiliar. */
    for (i = 0; i < quantidade; i++) {
        removerFila(&fila, &vetor[i]);
    }

    for (i = 0; i < quantidade / 2; i++) {
        if (vetor[i] != vetor[quantidade - 1 - i]) {
            palindromo = 0;
            break;
        }
    }

    printf("\nFila informada: ");
    for (i = 0; i < quantidade; i++) {
        printf("%d ", vetor[i]);
    }

    if (palindromo) {
        printf("-> Sim, forma um palindromo.\n");
    } else {
        printf("-> Nao forma um palindromo.\n");
    }
}

/**
 * Exibe o menu da questao 2 e chama o teste de fila palindroma.
 * @return int Codigo de encerramento do programa.
 */
int main(void) {
    int opcao;

    do {
        printf("\n--- Questao 2: Fila palindroma ---\n");
        printf("1 - Testar uma fila\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                testarPalindromo();
                break;
            case 0:
                printf("Encerrando questao 2.\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
