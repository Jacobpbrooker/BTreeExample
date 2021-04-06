#pragma once
// An AVL tree node
struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
};

int height(struct Node* N);
int maxOfTwo(int a, int b);
struct Node* newNode(int key);
struct Node* rightRotate(struct Node* y);
struct Node* leftRotate(struct Node* x);
int getBalance(struct Node* N);
struct Node* insert(struct Node* node, int key);
void preOrder(struct Node* root);