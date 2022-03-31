
#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;


Node* delete(Node* root, int request) {
    if(root == NULL) {
        return NULL;
    }

    else if(request < root->data) {
        root->left = delete(root->left, request);
    }

    else if(request > root->data) {
        root->right = delete(root->right, request);
    }

    else {
        if(root->left == NULL && root->right == NULL) {
            free(root);
            root = NULL;
        }

        else if(root->left == NULL) {
            Node* temp = root;
            root = root->right;
            free(temp);
        }

        else if(root->right == NULL) {
            Node* temp = root;
            root = root->left;
            free(temp);
        }

        else {
            Node* temp = findMin(root->right);
            root->data = temp->data;
            root->right = delete(root->right, temp->data);
        }
    }
    return root;
}


int main() {
   

    return 0;
}