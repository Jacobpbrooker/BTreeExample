// C program to insert a node in AVL tree
#include<stdio.h>
#include<stdlib.h>

#include "btree.h"

int main() {
	int val, ch;

	insert(8);
	insert(9);
	insert(10);
	insert(11);
	insert(15);
	insert(16);
	insert(17);
	insert(18);
	insert(20);
	insert(23);

	traversal(root);

	printf("\n");
	search(11, &ch, root);
}