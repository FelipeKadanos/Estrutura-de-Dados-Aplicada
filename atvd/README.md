# Atividade Individual

**Consulta:** com consulta  
**Valor:** 1.5 da A2

## Instruções

- Elaborar o código em C, sem uso de bibliotecas prontas de listas, pilhas ou filas, para resolver as questões desta atividade, apresentando os devidos comentários explicando como a estrutura de dado (pilha, fila) está sendo utilizada.
- Para cada questão, deve ser apresentado um menu que permita a interação com o usuário para testar as funções requisitadas.
- Um relatório de testes deve ser concebido, comprovando a execução das funcionalidades implementadas (adicionar os prints de tela como evidência, com comentários sobre o que cada teste propõe a validar). Usar valores diferentes dos exemplos.
- As entregas (código C comentado, relatório de testes) podem ser feitas diretamente no Blackboard ou através de link de repositório (e.g. github).
- No caso de identificação de cópia de código, a nota da atividade será zerada.

## Questão 1 - Simulação de fila de atendimento

Implemente um sistema de fila para atendimento:

- Cada cliente possui um número (ID).
- O sistema deve:
  - Inserir clientes na fila.
  - Atender clientes (remover da fila).
  - Mostrar o próximo cliente.
  - Mostrar tamanho da fila.

## Questão 2 - Verificação de fila palíndroma

Verifique se uma fila forma um palíndromo.

**Exemplo:**

```text
Fila: 1 2 3 2 1 -> Sim
Fila: 1 2 3 -> Não
```

## Questão 3 - Pilha com mínimo

Implemente uma pilha que, além das operações básicas (empilhar/push e desempilhar/pop), tenha:

- `getMin()` -> retorna o menor elemento da pilha em tempo real.

**Exemplo:**

```text
Push(): 5, 3, 7
getMin(): 3
Pop()
getMin(): 3
Pop()
getMin(): 5
```

## Questão 4 - Remoção de duplicatas consecutivas

Dada uma string, remova caracteres duplicados consecutivos, utilizando uma estrutura de dados de pilha.

**Exemplo:**

```text
Entrada: "AAABCCDDD"
Saída: "ABCD"
```

## Questão 5 - Histórico de navegação (Pilhas)

Simule o funcionamento de "voltar" e "avançar" de um navegador.

**Requisitos:**

- Use duas pilhas:
  - Pilha "voltar".
  - Pilha "avançar".
- Operações:
  - `VISITAR X`: acessa uma nova página.
  - `VOLTAR`: retorna para a página anterior.
  - `AVANCAR`: volta para a próxima página.

**Exemplo:**

```text
VISITAR A
VISITAR B
VISITAR C
VOLTAR -> B
VOLTAR -> A
AVANCAR -> B
```
