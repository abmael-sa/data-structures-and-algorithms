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


void insert(Node** root, int newElement) {
    // If there isn't any node in the tree.
    if(*root == NULL) {
        *root = getNewNode(newElement); 
        return;   
    }

    Node* parent = NULL;
    Node* current = *root;

    while(1) {
        // Make the 'parent' variable point to the current node.
        parent = current;

        // If newElement is lesser or equal to 'current->data' then go to the left node.
        if(newElement <= current->data) {         
            current = current->left;

            // If current is NULL, then make the left pointer of the parent node 
            // point to the new node.
            if(current == NULL) {
                parent->left = getNewNode(newElement);
                break;
            }
        }

        // The case above is not true, then newElement is greater than 'current->data'.
        // Go to the right node.
        else {           
            current = current->right;

            // If current is NULL, then make the RIGHT pointer of the parent node 
            // point to the new node.
            if(current == NULL) {
                parent->right = getNewNode(newElement);
                break;
            }
        }
    }
}
