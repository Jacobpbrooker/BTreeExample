#pragma once
// An AVL tree node
typedef struct Node
{
    int key;
    struct Node* left;
    struct Node* right;
    int height;
}NODE, *PNODE;

int height(struct Node* N);
int maxOfTwo(int a, int b);
PNODE newNode(int key);
PNODE rightRotate(PNODE y);
PNODE leftRotate(PNODE x);
int getBalance(PNODE N);
PNODE insert(PNODE node, int key);
void preOrder(PNODE root);