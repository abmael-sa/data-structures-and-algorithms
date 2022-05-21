
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

#define EMPTY -1
#define TRUE 1
#define FALSE 0

typedef struct Node {
    char data;
    struct Node* next;
}Node;

Node* createNode(int data) {
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->data = data;
    temp->next = NULL;

    return temp;
}


int empty(Node* stack) {
    return stack ? FALSE : TRUE;
}


void push(Node** stack, int data) {
    Node* newElement = createNode(data);

    if(!(*stack)) {
        *stack = newElement;
        return;
    }

    newElement->next = *stack;
    *stack = newElement;
}


int pop(Node** stack) {
    if(!(*stack)) 
        return EMPTY;
    
    Node* popped;
    int value;

    popped = *stack;
    value = popped->data;
    *stack = (*stack)->next;

    free(popped);

    return value;
}


int top(Node* stack) {
    return stack ? stack->data : EMPTY;
}


void print(Node* stack) {
    printf("\n");

    while(stack) {
        printf(" %d", stack->data);
        stack = stack->next;
    }
}


int evaluate_postfix(char* s) {
    Node* stack = NULL;
    int i;

    for(i = 0; s[i]; i++) {
        if(isdigit(s[i])) {
            push(&stack, s[i] - '0');
        }

        else if(s[i] == '*' || s[i] == '/' || s[i] == '+' || s[i] == '-') {
            int op1;
            int op2;

            op1 = pop(&stack);
            op2 = pop(&stack);

            switch (s[i]) {
                case '*':
                    push(&stack, op2 * op1);
                    break;

                case '/':
                    push(&stack, op2 / op1);
                    break;
            
                case '+':
                    push(&stack, op2 + op1);
                    break;
            
                case '-':
                    push(&stack, op2 - op1);
                    break;          
            }
        }
    }
    
    return pop(&stack);
}


void initialize() {
    char* s = {"23*54*+9-"};

    printf(" %d\n", evaluate_postfix(s));
}


int main() {

    initialize();

    return 0;
}