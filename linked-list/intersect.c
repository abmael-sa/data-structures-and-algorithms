#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* next;
}Node;

Node* newNode(int data ) {
    Node* temp = (Node*)malloc(sizeof(Node));

    temp->data = data;
    temp->next = NULL;

    return temp;
}


void print(Node* head) {
    printf("\n");
    while(head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
}


int get_length(Node* head) {
    int n;

    n = 0;
    while(head != NULL) {
        n += 1;
        
        head = head->next;      
    }

    return n;
}



Node* intersect(Node* head1, Node* head2) {
    int n1, n2;
    int i;
    Node* intersectionNode;

    n1 = get_length(head1);
    n2 = get_length(head2);

    if(n1 > n2) {
        int diff;

        diff = n1 - n2;
        for(i = 0; i < diff; i++) {
            head1 = head1->next;
        }
    }
    
    else if(n2 > n1) {
        int diff;

        diff = n2 - n1;
        for(i = 0; i < diff; i++) {
            head2 = head2->next;
        }
    }


    for(i = 0; head1 != NULL || head2 != NULL; i++) {
        if(head1->next == head2->next) {
            intersectionNode = head1->next;
            
            return intersectionNode;
        }

        head1 = head1->next;
        head2 = head2->next;
    }

    return NULL;
    
}


void initialize() {
    Node* head1 = NULL;
    Node* head2 = NULL;
    Node* head3 = NULL;

    head3 = newNode(3);
    head3->next = newNode(4);
    head3->next->next = newNode(5);

    head1 = newNode(1);
    head1->next = newNode(1);
    head1->next->next = newNode(1);
    head1->next->next->next = NULL;

    head2 = newNode(2);
    head2->next = newNode(2);
    head2->next->next = newNode(2);
    head2->next->next->next = head3;

    Node* exercise = NULL;

    exercise = intersect(head1, head2);

    if(exercise != NULL) {
        printf("\nIntersect!, %d", exercise->data);
    }
}


int main() {

    initialize();

    return 0;
}