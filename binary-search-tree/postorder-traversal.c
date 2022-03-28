
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
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
    if(*root == NULL) {
        *root = getNewNode(newElement); 
        return;   
    }

    Node* parent = NULL;
    Node* current = *root;

    while(1) {
        parent = current;

        if(newElement <= current->data) {         
            current = current->left;

            if(current == NULL) {
                parent->left = getNewNode(newElement);
                break;
            }
        }

        else {           
            current = current->right;

            if(current == NULL) {
                parent->right = getNewNode(newElement);
                break;
            }
        }
    }
}

void postorderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    postorderTraversal(root->left);
    postorderTraversal(root->right);
    printf(" %d", root->data);
}

int main() {

    int array[] = { 54, 34, 63, 1, 6, 812, 21, 8,
                    745, 91, 15, 124, 73, 25, 7 };

    Node* root = NULL;

    int i;
    for(i = 0; i < 16; i++) {
        insert(&root, array[i]);
    }

    postorderTraversal(root);

    return 0;
}