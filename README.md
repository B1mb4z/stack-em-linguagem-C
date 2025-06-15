```markdown
# Stack de Processos em C

## Visão Geral
Este projeto implementa uma estrutura de dados do tipo **Stack** (pilha) em C, especializada para armazenar informações de processos (PID e nome do comando). A implementação utiliza listas ligadas e inclui operações básicas como `Push`, `Pop` e verificação de estado.

## Estruturas de Dados

### `valueT`
Armazena os dados de um processo:
```c
typedef struct {
    int pid;            // Identificador do processo
    char comando[100];  // Nome do comando/programa
} valueT;
```

### `nodeT`
Nó da lista ligada:
```c
typedef struct _nodeT {
    valueT value;       // Valor armazenado
    struct _nodeT *next; // Ponteiro para o próximo nó
} nodeT;
```

### `stackT`
Estrutura principal da Stack:
```c
typedef struct {
    nodeT *head;        // Ponteiro para o topo
} stackT;
```

##  Funções Implementadas

| Função         | Descrição                                      |
|----------------|-----------------------------------------------|
| `NewNode()`    | Aloca um novo nó na memória heap              |
| `NewStack()`   | Inicializa uma Stack vazia                    |
| `Push()`       | Insere um elemento no topo                    |
| `Pop()`        | Remove e retorna o elemento do topo           |
| `EmptyStack()` | Esvazia a Stack                               |
| `FreeStack()`  | Libera a memória da Stack (se vazia)          |
| `isEmpty()`    | Verifica se a Stack está vazia                |

##  Exemplo de Uso
```c
int main() {
    stackT *myStack = NewStack(); // Cria Stack
    
    // Adiciona processos
    Push(myStack, (valueT){1, "chrome.exe"});
    Push(myStack, (valueT){2, "notepad.exe"});
    
    // Remove e imprime (ordem LIFO)
    while (!isEmpty(myStack)) {
        valueT p = Pop(myStack);
        printf("PID: %d, Comando: %s\n", p.pid, p.comando);
    }
    
    FreeStack(myStack); // Libera memória
    return 0;
}
```

## Compilação e Execução
```bash
gcc stack.c -o stack && ./stack
```

## Saída Esperada
```
PID: 2, Comando: notepad.exe
PID: 1, Comando: chrome.exe
```

## Observações
- **Tratamento de erros**: Inclui verificação para alocação de memória e operações inválidas.
- **Regras de liberação**: `FreeStack()` só funciona se a Stack estiver vazia.
- **Extensibilidade**: Pode ser adaptado para outros tipos de dados alterando `valueT`.

## Licença
Código livre para uso e modificação. Contribuições são bem-vindas!
