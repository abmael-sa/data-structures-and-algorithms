#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* newNode(int x) {
    Node* temp = (Node*) malloc(sizeof(Node));

    temp->data = x;
    temp->next = NULL;

    return temp;
}


void insert(Node** head, int x) {
    Node* temp = newNode(x);

    if(!(*head)) {
        *head = temp;
        return;
    }

    temp->next = *head;
    *head = temp;
}


void print(Node* head) {
    printf("\n");
    while(head) {
        printf(" %d", head->data);
        head = head->next;
    }
}


void partition(Node** head, int x) {
    if(!(*head)) {
        return;
    }

    Node* tail = *head;
    Node* curr = *head;
    Node* newHead = *head;

    while(curr != NULL) {
        Node* next = curr->next;

        if(curr->data < x) {
            curr->next = newHead;
            newHead = curr;
        }
        else {
            tail->next = curr;
            tail = curr;
        }

        curr = next;
    }
    tail->next = NULL;

    *head = newHead;
}


void initialize(Node** head) {
    int i;
    int n = 15;

    for(i = 0; i < n; i++) {
        insert(head, i*3);
    }

    print(*head);

    partition(head, 9);

    print(*head);
}


int main(){ 
    Node* head= NULL;
    initialize(&head);

    return 0;
}