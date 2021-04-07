// C program to insert a node in AVL tree
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "btree.h"

int main() {
	int val;
	int ch;
	//srand(time(0));
	
	int runs = rand() % 10;

	for (int i = 0; i < 10; i++)
	{
		insert(rand() % 100);
	}

	traversal(root);

	printf("\n");
	search(11, &ch, root);
}