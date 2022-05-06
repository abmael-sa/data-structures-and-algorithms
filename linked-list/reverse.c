#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* newNode(int data) {
    Node* newElement = (Node*)malloc(sizeof(Node));

    newElement->data = data;
    newElement->next = NULL;

    return newElement;
}


void push(Node** head, int data) {
    Node* newElement = newNode(data);

    if(*head == NULL) {
        *head = newElement;
        return;
    }
    else {
        newElement->next = *head;
        *head = newElement;
    }
}


void print(Node* head) {
    printf("\n");

    while(head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
}


void reverse(Node** head) {
    if(*head == NULL || (*head)->next == NULL) {
        return;
    }

    Node* curr;
    Node* next;
    Node* prev;

    curr = *head;
    next = NULL;
    prev = NULL;
    while(curr != NULL) {
        next = curr->next;

        curr->next = prev;

        prev = curr;
        curr = next;
    }

    *head = prev;
}


void initialize() {
    Node* head = NULL;
    int i, n;

    n = 10;
    for(i = 0; i < n; i++) {
        push(&head, i*3);
    }

    print(head);
    reverse(&head);
    print(head);
}


int main() {
    initialize();

    return 0;
}