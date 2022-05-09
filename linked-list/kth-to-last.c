#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

Node* newNode(int x) {
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = x;
    temp->next = NULL;

    return temp;
}


void insert(Node** head, int x){
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


int kth_to_last(Node* head, int k) {
    if(!head) {
        return -1;
    }

    Node* fast = head;
    Node* slow = head;

    int i;   
    for(i = 0; i < k-1; i++) {
        if(fast->next == NULL) {
            printf("\nOut of range...");
            return -1;
        }
        
        fast = fast->next;
    }

    while(fast->next != NULL) {
        fast = fast->next;
        slow = slow->next;
    }

    return slow->data;
}


void initialize(Node** head) {
    int i;
    int n = 15;

    for(i = 0; i < n; i++) {
        insert(head, i*7);
    }

    printf("\n%d", kth_to_last(*head, 7));

    print(*head);
}


int main() {
    Node* head = NULL;
    initialize(&head);


    return 0;
}