#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* min(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    Node* current = root;

    while(current->left) {
        current = current->left;
    }

    return current;
}

Node* max(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    Node* current = root;

    while(current->right) {
        current = current->right;
    }

    return current;
}
