#pragma once
// BTree header file
// C program for B-Tree
// Base code sample taken from https://www.programiz.com/dsa/b-tree
//
// Modified by: Jacob Brooker
// 
// PROG 71040 OS and Security
//
// April 09, 2021

#define MAX 3							// this B-Tree is of degree MAX
#define MIN 2							// the node must have at minumum 

typedef struct BTreeNode {
	int val[MAX + 1];					// int will act as the 'key' for the node
	int count;							// the number of 'keys' in the node
	struct BTreeNode* link[MAX + 1];	// this is an array of pointers for the children of the node
}TREENODE, *PTREENODE;

PTREENODE root;							// the root node of the tree

PTREENODE createNode(int val, PTREENODE child);	// create a new node and return pointer to node
void insertNode(int val, int pos, PTREENODE node, PTREENODE child);
void splitNode(int val, int* pval, int pos, PTREENODE node, PTREENODE child, PTREENODE* newNode);
int setValue(int val, int* pval, PTREENODE node, PTREENODE* child);
void insert(int val);
void search(int val, int* pos, PTREENODE myNode);
void traversal(PTREENODE myNode);


