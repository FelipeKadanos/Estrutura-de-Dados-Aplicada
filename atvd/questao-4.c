#include <stdio.h>

/* Quantidade maxima de caracteres que a pilha consegue armazenar. */
#define MAX 100

/**
 * Representa uma pilha de caracteres.
 * dados guarda os caracteres mantidos na resposta e topo indica o ultimo item.
 */
typedef struct {
    char dados[MAX];
    int topo;
} Pilha;

/**
 * Define a pilha de caracteres como vazia antes do teste.
 * @param pilha Ponteiro para a pilha que sera inicializada.
 * @return Nao retorna valor.
 */
void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

/**
 * Verifica se a pilha de caracteres atingiu a capacidade maxima.
 * @param pilha Pilha que sera consultada.
 * @return int|bool 1|true se a pilha estiver cheia ou 0|false caso contrario.
 */
int pilhaCheia(Pilha *pilha) {
    return pilha->topo == MAX - 1;
}

/**
 * Insere um caractere no topo da pilha.
 * @param pilha Pilha que recebera o caractere.
 * @param valor Caractere que sera empilhado.
 * @return int|bool 1|true se a insercao ocorrer ou 0|false se a pilha estiver cheia.
 */
int empilhar(Pilha *pilha, char valor) {
    if (pilhaCheia(pilha)) {
        return 0;
    }

    pilha->topo++;
    pilha->dados[pilha->topo] = valor;
    return 1;
}

/**
 * Consulta o caractere armazenado no topo da pilha.
 * @param pilha Pilha que sera consultada.
 * @return char Caractere que esta no topo da pilha.
 */
char consultarTopo(Pilha *pilha) {
    return pilha->dados[pilha->topo];
}

/**
 * Le uma string e remove caracteres duplicados consecutivos usando pilha.
 * @return Nao retorna valor.
 */
void removerDuplicatas(void) {
    Pilha pilha;
    char entrada[MAX];
    int i;

    inicializarPilha(&pilha);

    printf("\nDigite uma string sem espacos: ");
    scanf("%99s", entrada);

    /* A pilha guarda o ultimo caractere valido no topo. Quando o caractere lido
       e igual ao topo, ele nao e empilhado porque e duplicado consecutivo. */
    for (i = 0; entrada[i] != '\0'; i++) {
        if (pilha.topo == -1 || entrada[i] != consultarTopo(&pilha)) {
            empilhar(&pilha, entrada[i]);
        }
    }

    printf("Saida: ");
    for (i = 0; i <= pilha.topo; i++) {
        printf("%c", pilha.dados[i]);
    }
    printf("\n");
}

/**
 * Exibe o menu da questao 4 e chama o teste de remocao de duplicatas.
 * @return int Codigo de encerramento do programa.
 */
int main(void) {
    int opcao;

    do {
        printf("\n--- Questao 4: Remocao de duplicatas consecutivas ---\n");
        printf("1 - Testar uma string\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                removerDuplicatas();
                break;
            case 0:
                printf("\nEncerrando questao 4.\n");
                break;
            default:
                printf("\nOpcao invalida.\n");
        }
    } while (opcao != 0);

    return 0;
}
