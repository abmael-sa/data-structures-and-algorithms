
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0
#define EMPTY -1


typedef struct Node {
    char data;
    struct Node* next;
}Node;

Node* newNode(char data) {
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->next = NULL;

    return temp;
}


int isEmpty(Node* stack) {
    return stack == NULL ? TRUE : FALSE;
}


void push(Node** stack, char data) {
    Node* newElement = newNode(data);

    if(*stack == NULL) {
        *stack = newElement;
        return;
    }
    else {
        newElement->next = *stack;
        *stack = newElement;
    }
}


void pop(Node** stack) {
    if(*stack == NULL) 
        return;

    Node* popped;

    popped = *stack;
    *stack = (*stack)->next;
    
    free(popped);
}


int top(Node* stack) {
    return stack != NULL ? stack->data : EMPTY;
}


void print(Node* stack) {
    printf("\n");

    while(stack != NULL) {
        printf(" %d", stack->data);
        stack = stack->next;
    }
}


int check_if_match(char stc, char ac) {
    if(stc == '(' && ac == ')') 
        return TRUE;
    else if(stc == '[' && ac == ']')
        return TRUE;
    else if(stc == '{' && ac == '}')
        return TRUE;
    else
        return FALSE;
}


int balanced_parentheses(char s[]) {
    Node* stack = NULL;
    int i;

    for(i = 0; s[i]; i++) {
        if(s[i] == '(' || s[i] == '[' || s[i] == '{') {
            push(&stack, s[i]);
        }
        else if (s[i] == ')' || s[i] == ']' || s[i] == '}') {
            if(isEmpty(stack)) 
                return FALSE;       
            else if(!(check_if_match(top(stack), s[i])))
                return FALSE;
            else 
                pop(&stack);
        }
    }
   
    return isEmpty(stack) ? FALSE : TRUE;
}


void exercise() {
    char s[] = {")2+1(*3+2"};
    int n, i;

    if(balanced_parentheses(s)) {
        printf("Balanced");
    }
    else {
        printf("Not Balanced");
    }
}


int main() {

    exercise(); 
    
    return 0;
}