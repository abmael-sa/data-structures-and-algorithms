#include <stdio.h>
#include <stdlib.h>

#define EMPTY -1
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* newNode(int data) {
    Node* temp = (Node*) malloc(sizeof(Node));

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

//O(N)
void reverse(char s[]) {
    Node* stack = NULL;
    int i;

    //O(N)
    for(i = 0; s[i]; i++) {
        push(&stack, s[i]);
    }

    //O(N)
    for(i = 0; !(isEmpty(stack)); i++) {
        s[i] = top(stack);
        pop(&stack);
    }
}


int len(char s[]) {
    int n;

    for(n = 0; s[n]; n++);

    return n;
}


void reverse_string(char s[]) {
    int i, j;


    i = 0;
    j = len(s) - 1;

    while(i < j) {
        char c;
        
        c = s[i];
        s[i] = s[j];
        s[j] = c;

        i++;
        j--;
    }
}


void iStack() {
    char s[] = {"banana"};

    reverse_string(s);
    printf("%s", s);
}


int main() {

    iStack();

    return 0;
}