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

void insert(Node** head, int data) {
    Node* temp = newNode(data);

    if(*head == NULL) {
        *head = temp;
        return;
    }

    Node* aux = *head;
    while(aux->next != NULL) {
        aux = aux->next;
    }

    aux->next = temp;
}


void print(Node* head) {
    printf("\n");
    while(head) {
        printf(" %d", head->data);
        head = head->next;
    }
}

// O(m+n)
Node* sum_lists(Node* fstHead, Node* secHead) {
    Node* newListHead = NULL;
    Node* addRemaining = NULL;
    int carry_over = 0;

    while(fstHead != NULL && secHead != NULL) {
        int sum;
        int prodValue;

        sum = (fstHead->data + secHead->data) + carry_over;
        prodValue = sum % 10;
        carry_over = sum / 10;
        
        insert(&newListHead, prodValue);

        if(fstHead->next == NULL && secHead->next != NULL) {
            addRemaining = secHead->next;
        }
        
        else if (secHead->next == NULL && fstHead->next != NULL) {
            addRemaining = fstHead->next;
        }

        fstHead = fstHead->next;
        secHead = secHead->next;
    }

    if(addRemaining != NULL) {
        while(addRemaining != NULL) {
            int sum;
            int prodValue;

            sum = addRemaining->data + carry_over;
            prodValue = sum % 10;
            carry_over = sum / 10;

            insert(&newListHead, prodValue);

            addRemaining = addRemaining->next;
        }
    }

    return newListHead;
}


void initialize() {
    int i;    
    int n1 = 8;
    int n2 = 6;
    
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;

    for(i = n1; i > 0; i--) {
        insert(&head1, i);
    }

    for(i = 0; i < n2; i++) {
        insert(&head2, i);
    }
    
    print(head1);
    print(head2);

    head3 = sum_lists(head1, head2);
    print(head3);
}


int main() {
    initialize();

    return 0;
}