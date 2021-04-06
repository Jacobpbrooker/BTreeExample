#pragma once
// An AVL tree node
#define MAX 3
#define MIN 2

struct BTreeNode {
	int val[MAX + 1], count;
	struct BTreeNode* link[MAX + 1];
};

struct BTreeNode* root;

struct BTreeNode* createNode(int val, struct BTreeNode* child);
void insertNode(int val, int pos, struct BTreeNode* node, struct BTreeNode* child);
void splitNode(int val, int* pval, int pos, struct BTreeNode* node, struct BTreeNode* child, struct BTreeNode** newNode);
int setValue(int val, int* pval, struct BTreeNode* node, struct BTreeNode** child);
void insert(int val);
void search(int val, int* pos, struct BTreeNode* myNode);
void traversal(struct BTreeNode* myNode);

