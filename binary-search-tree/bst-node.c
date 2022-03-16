
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

    return;
}