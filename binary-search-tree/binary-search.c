
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* search(Node* root, int requestedElement) {
    if(root == NULL) {
        return NULL;
    }

    // For clarity.
    Node* current = root;

    while(current) {
        if(requestedElement == current->data) {
            return current;
        }

        if(requestedElement <= current->data) {
            current = current->left;
        }
        else {
            current = current->right;
        }
    }
}