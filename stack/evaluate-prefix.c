
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define EMPTY -1
#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->next = NULL;

    return temp;
}


int empty(Node* stack) {
    return stack ? FALSE : TRUE;
}


void push(Node** stack, int data) {
    Node* newItem = createNode(data);

    if(!(*stack)) {
        *stack = newItem;
        return;
    }
    else {
        newItem->next = *stack;
        *stack = newItem;
    }
}


int pop(Node** stack) {
    if(!(*stack))
        return EMPTY;

    Node* popped;
    int value;

    popped = *stack;
    value = (*stack)->data;
    *stack = (*stack)->next;

    free(popped);
    return value;
}


int top(Node* stack) {
    return stack ? stack->data : EMPTY;
}


int get_len(char* s) {
    int n;

    for(n = 0; s[n]; n++) 
        ;
        
    return n;   
}

// O(N)
int evaluate_prefix(char* s) {
    Node* stack = NULL;
    int n, i;

    n = get_len(s);

    for(i = n - 1; s[i]; i--) {
        // constant amount of work inside the body of the loop.
        if(isdigit(s[i]))
            push(&stack, s[i] - '0');

        else if (s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
            int op1;
            int op2;

            op1 = pop(&stack);
            op2 = pop(&stack);
            switch (s[i]) {
            case '*':
                push(&stack, op1 * op2);
                break;

            case '/':
                push(&stack, op1 / op2);
                break;

            case '+':
                push(&stack, op1 + op2);
                break;
                
            case '-':
                push(&stack, op1 - op2);
                break;
            } 
        }
    }
    
    return pop(&stack);
}


void initialize() {
    char* s = {"-+*23*549"};

    printf(" \n%d", evaluate_prefix(s));
}


int main() {

    initialize();

    return 0;
}