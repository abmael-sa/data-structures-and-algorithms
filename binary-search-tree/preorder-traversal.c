
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

void preorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    printf(" %d", root->data);
    preorderTraversal(root->left);
    preorderTraversal(root->right);
}