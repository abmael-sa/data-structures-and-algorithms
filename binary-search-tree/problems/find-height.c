
#include <stdio.h>
#include <stdlib.h>

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

// Height is the number of edges from a node to a leaf node.
int findHeight(Node* root) {
    if(root == NULL) {
        return -1;
    }

    int leftHeight;
    int rightHeight;

    leftHeight = findHeight(root->left);
    rightHeight = findHeight(root->right);

    return (leftHeight >= rightHeight ? leftHeight : rightHeight) + 1;
}
