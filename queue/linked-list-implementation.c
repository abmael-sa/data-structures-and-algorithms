
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* previous;
}Node;

Node* createnode(int data) {
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->data = data;
    temp->previous = NULL;;

    return temp;
}


void enqueue(Node** tail, Node** head, int data) {
    Node* newelement = createnode(data);

    if(!(*head)) {
        *tail = newelement;
        *head = newelement;

        return;
    } 
    else {
        (*tail)->previous = newelement;
        *tail = newelement;
    }
}


void dequeue(Node** tail, Node** head) {
    Node* dequeued_element;
    
    dequeued_element = *head;
    *head = (*head)->previous;

    if(!(*head)) {
        *tail = NULL;
    }

    free(dequeued_element);
}


int empty(Node* head, Node* tail) {
    return head == tail ? TRUE : FALSE;
}


void print(Node* temporary) {
    while(temporary) {
        printf(" %d", temporary->data);
        temporary = temporary->previous;
    }
    printf("\n");
}

int main() {

    return 0;
}