#pragma once
// BTree header file
#define MAX 3
#define MIN 2

typedef struct BTreeNode {
	int val[MAX + 1]; 
	int count;
	struct BTreeNode* link[MAX + 1];
}TREENODE, *PTREENODE;

PTREENODE root;

PTREENODE createNode(int val, PTREENODE child);
void insertNode(int val, int pos, PTREENODE node, PTREENODE child);
void splitNode(int val, int* pval, int pos, PTREENODE node, PTREENODE child, PTREENODE* newNode);
int setValue(int val, int* pval, PTREENODE node, PTREENODE* child);
void insert(int val);
void search(int val, int* pos, PTREENODE myNode);
void traversal(PTREENODE myNode);

