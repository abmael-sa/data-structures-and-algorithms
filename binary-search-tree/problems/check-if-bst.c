#include <stdio.h>
#include <stdlib.h>

#define TRUE 1
#define FALSE 0

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


int isBstUtil(Node* root, int minValue, int maxValue) {
    if(root == NULL) {
        return TRUE;
    }

    if( root->data >= minValue 
        && root->data <= maxValue
        && isBstUtil(root->left, minValue, root->data)
        && isBstUtil(root->right, root->data, maxValue) 
        ){
            return TRUE;
    }
    else {
        return FALSE;
    }
}

int isBinarySearchTree(Node* root) {
    return isBstUtil(root, INT_MIN, INT_MAX);
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


int main() {
    int array[] = { 54, 34, 63, 1, 6, 812, 21, 8,
                    745, 91, 15, 124, 73, 25, 7 };

    Node* root = NULL;

    int i;
    for(i = 0; i < 16; i++) {
        insert(&root, array[i]);
    }

    inorderTraversal(root);

    if(isBinarySearchTree(root)) {
        printf("\nThis IS a binary search tree!");
    }
    else {
        printf("\nThis ISN'T a binary search tree!");
    }

    return 0;
    }