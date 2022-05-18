#include <stdio.h>
#include <stdlib.h>

#define EMPTY  -1
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* newNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->next = NULL;

    return temp;
}


void push(Node** stack, int data) {
    Node* newElement = newNode(data);

    if(*stack == NULL) {
        *stack = newElement;
        return;
    }

    newElement->next = *stack;
    *stack = newElement;
}


void pop(Node** stack) {
    if(*stack == NULL) {
        return;
    }

    Node* popped;

    popped = *stack;
    *stack = (*stack)->next;
    
    free(popped);
}


int top(Node* stack) {
    return stack != NULL ? stack->data : EMPTY;
}


int isEmpty(Node* stack) {
    return stack == NULL ? TRUE : FALSE;
}


void iStack() {
    Node* stack = NULL;
    int n, i;

    n = 10;
    for(i = 0; i < n ; i++) {
        push(&stack, i);
    }

    for(i = 0; i < n; i++) {
        printf(" %d", top(stack));
        pop(&stack);
    }

    printf("\n %d", isEmpty(stack));
    printf("\n %d", top(stack));
}


int main() {
    iStack();
    return 0;
}