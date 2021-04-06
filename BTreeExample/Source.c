// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>

#include "btree.h"

/* Driver program to test above function*/
int main()
{
    struct Node* root = NULL;

    /* Constructing tree given in the above figure */
    root = insert(root, 10);
    root = insert(root, 20);
    root = insert(root, 30);
    root = insert(root, 40);
    root = insert(root, 50);
    root = insert(root, 25);

    /* The constructed AVL Tree would be
              30
             /  \
           20   40
          /  \     \
         10  25    50
    */

    printf("Preorder traversal of the constructed AVL"
        " tree is \n");
    preOrder(root);

    return 0;
}