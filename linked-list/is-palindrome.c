#include<stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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


void print(Node* head) {
    printf("\n");
    while(head != NULL) {
        printf(" %d", head->data);
        head = head->next;
    }
}

// O(n) iterate through up to the end of the list, then returns
// doing constant amount of work. Can be 'theta of n' if i'm not wrong.
// O(n) for memory complexity as well.
void check(Node* mainPointer, Node** referencePointer, int* verify) {
    if(mainPointer == NULL) {
        return;
    }

    check(mainPointer->next, referencePointer, verify);
    
    if(*verify == FALSE) {
        return;
    }

    if(mainPointer->data != (*referencePointer)->data) {
        *verify = FALSE;
    }
    *referencePointer = (*referencePointer)->next;
}


void inform_result(int result) {
    if(result == TRUE) {
        printf("\nPalindrome.");
    }
    else {
        printf("\nNot a palindrome.");
    }
}


void is_Palindrome(Node* listHead) {
    int verify = TRUE;
    Node* comparationPointer = listHead;
    
    check(listHead, &comparationPointer, &verify);

    inform_result(verify);
}


void initialize() {
    Node* head = NULL;
    int i, n;

    head = newNode(1);
    head->next = newNode(3);
    head->next->next = newNode(2);
    head->next->next->next = newNode(3);
    head->next->next->next->next = newNode(1);

    print(head);

    is_Palindrome(head);
}


int main() {
    initialize();

    return 0;
}