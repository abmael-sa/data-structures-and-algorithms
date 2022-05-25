
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>

#define EMPTY -1
#define TRUE 1
#define FALSE 0

typedef struct Node  {
    char data;
    struct Node* next;
} Node;


Node* createnode(char data) {
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->data = data;
    temp->next = NULL;

    return temp;
}


int empty(Node* stack) {
    return stack ? FALSE : TRUE;
}


void push(Node** stack, char data) {
    Node* newelement = createnode(data);

    if(!(*stack)) {
        *stack = newelement;
        return;
    }
    else {
        newelement->next = *stack;
        *stack = newelement;
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


int isoperator(char c) {
    return (c == '*' || c == '/' || c == '+' || c == '-') ? TRUE : FALSE;
}


int higher_precedence(int c, int sc) {
    if(sc == '/' && c != '*') 
        return TRUE;

    else if (sc < c) 
        return TRUE;

    else 
        return FALSE;
}


int isopen_pcbk(char c) {
    return (c == '(' || c == '[' || c == '{') ? TRUE : FALSE;
}


int isclose_pcbk(char c) {
    return (c == ')' || c == ']' || c == '}') ? TRUE : FALSE;
}


Node* infix_to_postfix(char* s) {
    Node* stack = NULL;
    Node* result = NULL;
    int i;

    // O(N)
    for(i = 0; s[i]; i++) {
        if(isalnum(s[i])) {
            push(&result, s[i]);
        }

        else if (isopen_pcbk(s[i])) {
            push(&stack, s[i]);
        }

        else if(isoperator(s[i])) {
            // while top of stack has higher precedence than s[i]
            while(higher_precedence(s[i], top(stack)) && !empty(stack) && !isopen_pcbk(top(stack))) {
                push(&result, pop(&stack));
            }
           
            push(&stack, s[i]);
        }      

        else if(isclose_pcbk(s[i])) {
            while(!isopen_pcbk(top(stack)) && !empty(stack)) {
               push(&result, pop(&stack));
            } 
            pop(&stack);
        } 
    }

    while(!empty(stack)) {
        if(isopen_pcbk(top(stack))) {
            pop(&stack);
        }
        else {
            push(&result, pop(&stack));
        }
    }

    return result;
}


void initialize() {
    char* s = {"((6+5)*4-3)*2"};
    Node* result = NULL;

    result = infix_to_postfix(s);

    while(result) {
        printf(" %c", result->data);
        result = result->next;
    }
}


int main() {

    initialize();

    return 0;
}