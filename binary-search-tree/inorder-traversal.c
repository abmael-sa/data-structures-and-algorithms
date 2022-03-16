#include <stdio.h>
#include <stdlib.h>

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* getNewNode(int number) {
    Node* newNode = (Node*)malloc(sizeof(Node));

    newNode->data = number;

    newNode->left = NULL;
    newNode->right = NULL;

    return newNode;
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