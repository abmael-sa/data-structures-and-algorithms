
#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* setNewNode(int element) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = element;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
}


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


void insert(Node** root, int newElement) {
    if(*root == NULL) {
        *root = setNewNode(newElement);
        return;
    }

    Node* parent = NULL;
    Node* current = *root;

    while(1) {
        parent = current;

        if(newElement <= current->data) {
            current = current->left;

            if(current == NULL) {
                parent->left = setNewNode(newElement);
                break;
            } 
        }
        else {
            current = current->right;

            if(current == NULL) {
                parent->right = setNewNode(newElement);
                break;
            }
        }
    }
}


void inorderTraversal(Node* root) {
    // Exit statement and exception handle.
    if(root == NULL) {
        return;
    }

    inorderTraversal(root->left);
    printf("%d ", root->data);
    inorderTraversal(root->right);
}


