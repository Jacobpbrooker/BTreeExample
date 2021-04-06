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