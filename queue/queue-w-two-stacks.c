
#include <stdio.h>
#include <stdlib.h>

#define TEST_MAX_SIZE 15

// Elements of the stack
typedef struct Node {
    int data;
    struct Node* next;
}Node;


// MyStack struct 
typedef struct MyQueue {
    Node* fStack;
    Node* sStack;
} MyQueue;


Node*  createNode(int data) {
    Node* temporary = (Node*)malloc(sizeof(Node));

    temporary->data = data;
    temporary->next = NULL;

    return temporary;
}

// "Global functions" that'll work for both stacks.

// Return if stack is empty
int empty(Node* stack) {
    return !(stack);
}

// Insert element on the stack
void push(Node** stack, int data) {
    Node* newElement = createNode(data);
    
    if(empty(*stack)) {
        *stack = newElement;
        return;
    }
    else {
        newElement->next = *stack;
        *stack = newElement;
    }
}

// Pop element from the stack
int pop(Node** stack) {
    Node* poppedElement = *stack;
    int value = (*stack)->data;
    
    *stack = (*stack)->next;

    free(poppedElement);
    return value;
}


// Copy one stack to another (respecting the LIFO discipline of course).
void copy(Node** source, Node** destination) {
    if(!(*source)) {
        printf("Nothing on source stack!\n"); 
        return;
    }

    while(*source) {
        push(destination, pop(source));       
    }
}


void print(Node* head) {
    if(!head) return;

    while(head) {
        printf(" %d", head->data);
        head = head->next;
    }
    printf("\n");
}


int emptyQueue(MyQueue queue) {
    return !(queue.fStack) && !(queue.sStack);
}


void enqueue(MyQueue* queue, int data) {
    // If first stack is empty, but second stack not: copy back the elements to first stack.
    if(!(queue->fStack) && queue->sStack) {
        copy(&(queue->sStack), &(queue->fStack));
    }
    
    // Push element to first stack.
    push(&(queue->fStack), data);   
}


int dequeue(MyQueue* queue) {
    if(emptyQueue(*queue)) {
        printf("Queue empty!\n");
        return -1;
    }

    int value;
    
    // if second stack empty: copy elements of first stack to second stack.
    if(!(queue->sStack) && queue->fStack) {
        copy(&(queue->fStack), &(queue->sStack));
    }
     
    // Pop from second stack.
    value = pop(&(queue->sStack));

    return value;
}

int main() {

    return 0;
}
