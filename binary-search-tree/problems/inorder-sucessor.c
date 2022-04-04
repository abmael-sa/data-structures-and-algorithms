
#include <stdlib.h>
#include <stdio.h>

#define TREE_IS_EMPTY -1

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
    struct Node* parent;
}Node;


Node* findMinValueAt(Node* root) {
    if(root == NULL) {
        return NULL;
    }

    Node* current = root;

    while(current->left) {
        current = current->left;
    }

    return current;
}


Node* findElementAt(int requestedElement, Node* root) {
    if(root == NULL) {
        return NULL;
    }

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


int inorderSuccessorOfElementAt(int element, Node* root) {
    if(root == NULL) {
        return TREE_IS_EMPTY;
    }

    Node* current = findElementAt(element, root);
    Node* sucessor = root;

    if(current == NULL) {
        return TREE_IS_EMPTY;
    }

    if(current->right) {
        sucessor = findMinValueAt(current->right);
    }

    else {
        Node* ancestor = root;
        while(ancestor != current) {
            ancestor = (current->data < ancestor->data) ? ancestor->left : ancestor->right;
            sucessor = (current->data < ancestor->data) ? ancestor : sucessor;
        }
    }

    return sucessor->data;
}

int main() {

    return 0;
}