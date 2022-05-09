#include <stdio.h>
#include <stdlib.h>

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


void push(Node** head, Node** tail, int data ){
    Node* newElement = newNode(data);

    if(*head == NULL) {
        *head = newElement;
        *tail = newElement;
        return;
    }
    else {
        newElement->next = *head;
        *head = newElement;
    }
}


Node* print(Node* head) {
    printf("\n");

    while(head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
}

// O(n) for time complexity. Iterate through the list and it's doing constant amount
// of work.

// O(1) for memory complexity. just storing constant amount of memory (2 variables of type
// pointer to node).
Node* loop_detection(Node* head) {
    if(head == NULL) {
        return NULL;
    }

    Node* slow;
    Node* fast;

    slow = head;
    fast = head->next;
    while(slow != fast) {
        slow = slow->next;
        fast = fast->next->next;
    }

    return slow->next;
}


Node* initialize() {
    Node* head = NULL;
    Node* tail = NULL;
    Node* result = NULL;
    int n, i;

    n = 15;
    for(i = 0; i < n; i++) {
        push(&head, &tail, i*3);
    }
    tail->next = head;   
     
    result = loop_detection(head);

    printf("\n %d", result->data);
}


int main() {
    initialize();

    return 0;
}