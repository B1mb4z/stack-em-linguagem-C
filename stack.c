#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Estrutura para representar um processo
typedef struct {
    int pid;            // Identificador do processo
    char comando[100];  // Nome do comando/programa
} valueT;

// Estrutura para um nó da lista ligada
typedef struct _nodeT {
    valueT value;       // Valor armazenado no nó
    struct _nodeT *next; // Ponteiro para o próximo nó
} nodeT;

// Estrutura para a Stack
typedef struct {
    nodeT *head;        // Ponteiro para o topo da Stack
} stackT;

// Protótipos das funções
nodeT *NewNode(void);
stackT *NewStack(void);
void Push(stackT *stack, valueT processo);
valueT Pop(stackT *stack);
void EmptyStack(stackT *stack);
void FreeStack(stackT *stack);
int isEmpty(stackT *stack);


nodeT *NewNode(void) {
    nodeT *newNode = (nodeT *)malloc(sizeof(nodeT));
    if (newNode == NULL) {
        fprintf(stderr, "Erro: Não há espaço disponível na heap para criar novo nó.\n");
        return NULL;
    }
    newNode->next = NULL;
    return newNode;
}


stackT *NewStack(void) {
    stackT *newStack = (stackT *)malloc(sizeof(stackT));
    if (newStack == NULL) {
        fprintf(stderr, "Erro: Não há espaço disponível na heap para criar nova Stack.\n");
        return NULL;
    }
    newStack->head = NULL;
    return newStack;
}


void Push(stackT *stack, valueT processo) {
    nodeT *newNode = NewNode();
    if (newNode == NULL) {
        return; // Erro já foi tratado em NewNode
    }
    
    newNode->value = processo;
    newNode->next = stack->head;
    stack->head = newNode;
}

valueT Pop(stackT *stack) {
    valueT emptyValue = {0, ""};
    
    if (isEmpty(stack)) {
        fprintf(stderr, "Erro: Stack está vazia.\n");
        return emptyValue;
    }
    
    nodeT *temp = stack->head;
    valueT result = temp->value;
    stack->head = temp->next;
    free(temp);
    
    return result;
}

void EmptyStack(stackT *stack) {
    while (!isEmpty(stack)) {
        Pop(stack); // Remove todos os elementos
    }
}


void FreeStack(stackT *stack) {
    if (!isEmpty(stack)) {
        fprintf(stderr, "Erro: Não é possível liberar a Stack pois não está vazia.\n");
        return;
    }
    
    free(stack);
}


int isEmpty(stackT *stack) {
    return (stack->head == NULL);
}


int main() {
    // Criar uma nova Stack
    stackT *myStack = NewStack();
    if (myStack == NULL) {
        return 1; // Erro ao criar Stack
    }
    
    // Criar alguns processos de exemplo
    valueT processo1 = {1, "chrome.exe"};
    valueT processo2 = {2, "notepad.exe"};
    valueT processo3 = {3, "cmd.exe"};
    
    // Adicionar processos à Stack
    Push(myStack, processo1);
    Push(myStack, processo2);
    Push(myStack, processo3);
    
    // Mostrar conteúdo da Stack (removendo elementos)
    printf("Conteúdo da Stack (ordem de remoção):\n");
    while (!isEmpty(myStack)) {
        valueT p = Pop(myStack);
        printf("  PID: %d, Comando: %s\n", p.pid, p.comando);
    }
    
    // Tentar remover de Stack vazia (deve mostrar erro)
    Pop(myStack);
    
    // Liberar a Stack
    FreeStack(myStack);
    
    return 0;
}
