
#include <stdio.h>
#include <stdlib.h>

// I decided to let all the code that i thought through here, not just
// the main one. 

typedef struct Node {
    int data;
    struct Node* left;
    struct Node* right;
}Node;


typedef struct QNode {
    Node* node;
    struct QNode* previous;
}QNode;


QNode* setNewQueueNode(Node* node) {
    QNode* newElement = (QNode*)malloc(sizeof(QNode));

    newElement->node = node;
    newElement->previous = NULL;

    return newElement; 
}


void enqueue(QNode** head, QNode** tail, Node* foo) {
    if(*head == NULL) {
        *head = setNewQueueNode(foo);
        *tail = *head;
        return;
    }

    QNode* newBar = setNewQueueNode(foo);
    
    (*tail)->previous = newBar;
    *tail = newBar;
}


void dequeue(QNode** head, QNode** tail) {
    if(*head == NULL) {
        return;
    }

    QNode* dequeuedElement = *head;
    *head = (*head)->previous;

    if(*head == NULL) {
        *tail = NULL;
    }

    free(dequeuedElement);
}


void levelOrderTraversal(Node* root) {
    if(root == NULL) {
        return;
    }

    QNode* queue = NULL;
    QNode* tail = NULL;

    enqueue(&queue, &tail, root);

    while(queue) {
        Node* current = queue->node;

        printf(" %d", current->data);

        if(current->left != NULL) {
            enqueue(&queue, &tail, current->left);
        }

        if(current->right != NULL) {
            enqueue(&queue, &tail, current->right);
        }

        dequeue(&queue, &tail);
    }
}


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