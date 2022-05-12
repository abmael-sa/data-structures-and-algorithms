#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* next;
} Node;

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

    temp->next = *head;
    *head = temp;
}


Node* push (Node* head, int data) {
    Node* temp = newNode(data);

    if(head == NULL) {
        head = temp;
        return head;
    }

    temp->next = head;
    head = temp;

    return head;
}

void print(Node* head) {
    printf("\n");
    while(head != NULL) {
        printf(" %d", head->data);
        head= head->next;
    }
}


int get_length(Node* head) {
    int n;

    n = 0;
    while(head != NULL) {
        n++;
        head = head->next;
    }

    return n;
}


void advanceDiff(Node** head, int diff) {
    int i;

    for(i = 0; i < diff; i++) {
        *head = (*head)->next;
    }
}


Node* sum_ll(Node* h1, Node* h2, Node* newListHead, int* carry_over) {
    
    if(h1 == NULL && h2 == NULL) {
        return NULL;
    }

    newListHead = sum_ll(h1->next, h2->next, newListHead, carry_over);

    int sum, prodValue;

    sum = (h1->data + h2->data) + *carry_over;
    prodValue = sum % 10;
    *carry_over = sum / 10;

    insert(&newListHead, prodValue);

    return newListHead;
}


Node* addRemaining(Node* newHead, Node* head, int diff, int* carry_over) {
    if(diff == 0) {
        return newHead;
    }

    diff--;
    newHead = addRemaining(newHead, head->next, diff, carry_over);

    int sum, prodValue;
    

    sum = head->data + (*carry_over);
    prodValue = sum % 10;
    *carry_over = sum / 10;

    newHead = push(newHead, prodValue);

    return newHead;
}


Node* sum_lists(Node* head1, Node* head2) {
    int n1, n2, diff, carry_over;
    Node* sumRemaining = NULL;
    Node* newListHead = NULL;

    // it would be better to nomeate those variables (n1, n2) more clearly, but i don't do this
    // because of the lack of criativity
    n1 = get_length(head1);
    n2 = get_length(head2);


    diff = 0;


    if(n1 > n2) {
        diff = n1 - n2;
        sumRemaining = head1;

        advanceDiff(&head1, diff);
    }
    
    else if (n2 > n1) {
        diff = n2 - n1;
        sumRemaining = head2;

        advanceDiff(&head2, diff);
    }


    carry_over = 0;
    newListHead = sum_ll(head1, head2, newListHead, &carry_over);


    if(sumRemaining != NULL) {
        newListHead = addRemaining(newListHead, sumRemaining, diff, &carry_over);
    }

    if(carry_over == 1) {
        newListHead = push(newListHead, 1);
    }

    return newListHead;
}


void initialize() {
    int i;
 

    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* exerciseHead = NULL;

    
    head1 = newNode(8);
    head1->next = newNode(5);
    head1->next->next = newNode(0);
    head1->next->next->next = newNode(0);

    head2 = newNode(8);
    head2->next = newNode(5);
    head2->next->next = newNode(0);
    head2->next->next->next = newNode(0);


    print(head1);
    print(head2);

    exerciseHead = sum_lists(head1, head2);
    print(exerciseHead);
}


int main() {
    initialize();

    return 0;
}