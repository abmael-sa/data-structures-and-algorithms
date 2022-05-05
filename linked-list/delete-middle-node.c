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


void delete_mn(Node** head) {
    if(!(*head)) {
        return;
    }

    Node* fast = (*head)->next;
    Node* slow = NULL;
    while(fast->next != NULL) {
        if(fast->next->next == NULL) {
            fast = fast->next;
        }
        else {
            fast = fast->next->next;
        }

        if(slow == NULL) {
            slow = *head;
        }
        else {
            slow = slow->next;
        }
    }

    Node* aux = slow->next;
    slow->next = slow->next->next;

    free(aux);
}


void initialize(Node** head) {
    int i, n = 16;
    for(i = 0; i < n; i++) {
        insert(head, i *5);
    }

    print(*head);
    delete_mn(head);
    print(*head);
}


int main() {
    Node* head = NULL;
    initialize(&head);
    return 0;
}