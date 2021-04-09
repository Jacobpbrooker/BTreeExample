// C program for B-Tree
// Base code sample taken from https://www.programiz.com/dsa/b-tree
//
// Modified by: Jacob Brooker
// 
// PROG 71040 OS and Security
//
// April 09, 2021

#include<stdio.h>
#include<stdlib.h>

#include "btree.h"

// Create a node
PTREENODE createNode(int val, PTREENODE child)                              // will only be called if root node is NULL or child node needs to be split
{   
    PTREENODE newNode;

    newNode = (PTREENODE)malloc(sizeof(struct BTreeNode));
    
    if (!newNode)
    {
        printf("Failed to allocate memory to newNode (createNode)\n");
        exit(EXIT_FAILURE);
    }

    newNode->val[1] = val;                                                  // set the value at position 1 to the passed 'key'
    newNode->count = 1;                                                     // set the count of the new node (number of keys) to 1
    newNode->link[0] = root;                                                // set the pointer of the the first position of the array to the root node
    newNode->link[1] = child;                                               // set the pointer of the second position of array to the child node (passed)
    return newNode;
}

// Insert node
void insertNode(int val, int pos, PTREENODE node, PTREENODE child) {
    int j = node->count;
   
    while (j > pos) {                                                       // while the counter is greater than the position of the passed key (the passed value is less than the previous)
        node->val[j + 1] = node->val[j];                                    // continously increment the data in the array
        node->link[j + 1] = node->link[j];                                  
        j--;
    }
    
    node->val[j + 1] = val;                                                 // set the new value in the opened spot from above
    node->link[j + 1] = child;
    node->count++;                                                          // incremement the number of keys in the node
}

// Split node
void splitNode(int val, int* pval, int pos, PTREENODE node, PTREENODE child, PTREENODE* newNode) 
{                                                                           // if we try to exceed the namixmum number of keys in a node we must split the keys into new nodes
    int median; 
    int j;

    if (pos > MIN)                                                          // firstly, find the median value (this will be promoted to the node above)
        median = MIN + 1;
    else
        median = MIN;

    *newNode = (PTREENODE)malloc(sizeof(struct BTreeNode));
    
    if (!*newNode)
    {
        printf("Failed to allocate memory to newNode (splitNode)\n");
        exit(EXIT_FAILURE);
    }

    j = median + 1;

    while (j <= MAX)                                                        // next, every value greater than the median will need to be placed in a new node 
    {
        (*newNode)->val[j - median] = node->val[j];
        (*newNode)->link[j - median] = node->link[j];
        j++;
    }

    node->count = median;                                                   // set the number of keys in the node to the number of keys remaining
    
    (*newNode)->count = MAX - median;                                       // set the number of keys in the newNode to the number of keys moved

    if (pos <= MIN) {
        insertNode(val, pos, node, child);                                  // insert the new key into the newly cleared node
    }
    else {
        insertNode(val, pos - median, *newNode, child);                     // otherwise insert the new key into the newNode
    }

    *pval = node->val[node->count];                                         // set the node count and link pointers
    (*newNode)->link[0] = node->link[node->count];
    node->count--;                                                          // decrement the count of keys in the node
}

// Set the value
int setValue(int val, int* pval, PTREENODE node, PTREENODE* child) 
{
    int pos;
    if (!node)                                                                  // if the node is NULL (no current node) 
    {
        *pval = val;                                                            // set the int pointer to the value of the int passed
        *child = NULL;                                                          // set the child pointer to null
        return 1;                                                               // return 1 to set insert() to create a node
    }

    if (val < node->val[1])                                                     // is this new value less than the value in the node at position 1
    {
        pos = 0;                                                                // if it is, set the position of this to 0 (we always want the order to be smallest to largest)
    }
    else 
    {
        for (pos = node->count; (val < node->val[pos] && pos > 1); pos--);      // since we only checked for less than, we now need to check for duplicates
            if (val == node->val[pos]) {
                printf("Duplicates are not permitted\n");                       // completely arbitrary (we made duplicates not allowed)
                return 0;                                                       // new insert is a duplicate, therefor we do not insert into tree and return
            }
    }
    
    if (setValue(val, pval, node->link[pos], child))                            // recursive call to setValue, check the child node to see if there is too many keys, and the further if child / parents need splits
    {
        if (node->count < MAX)                                                  // node is not full, and we can insert the key 
        {
            insertNode(*pval, pos, node, *child);
        }
        else {
            splitNode(*pval, pval, pos, node, *child, child);                   // otherwise node is full and we need to split
            return 1;
        }
    }
    return 0;
}

// Insert the value
void insert(int val) {
    int flag; 
    int i;

    PTREENODE child;                                                            // create a pointer to a treeNode called child

    flag = setValue(val, &i, root, &child);                                     // returns a 1 if a new node needs to be created (in instance of a NULL root node and if the node needs to be split)
    if (flag == 1)
        root = createNode(i, child);                                            // new node is required (root node is NULL or node is full and we need to split)
}

// Search node
void search(int val, int* pos, PTREENODE myNode) {
    if (!myNode)            
    {
        return;
    }

    if (val < myNode->val[1])                                                   // if the search value is less than the first key, set the position to 0 
    {
        *pos = 0;
    }
    else 
    {
        for (*pos = myNode->count; (val < myNode->val[*pos] && *pos > 1); (*pos)--);
            if (val == myNode->val[*pos])                                       // look though the keys in current node for hit
            {
                printf("%d is found", val);
                return;
            }
    }
    
    search(val, pos, myNode->link[*pos]);                                       // recursively call again with key either right or left

    return;
}

// Traverse then nodes
void traversal(PTREENODE myNode) {
    int i;
    if (myNode) {
        for (i = 0; i < myNode->count; i++) 
        {
            traversal(myNode->link[i]);                                         // recursive search follow each key in the root node
            printf("%d ", myNode->val[i + 1]);                                  // print the key value at each node
        }
        traversal(myNode->link[i]);
    }
}