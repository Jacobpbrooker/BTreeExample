// C program for B-Tree
// Base code samplee taken from https://www.programiz.com/dsa/b-tree
//
// Modified by: Jacob Brooker
// 
// PROG 71040 OS and Security
//
// April 09, 2021

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "btree.h"

#define INSERTRUN 10

int main() 
{
	int ch;
	//srand(time(0));

	for (int i = 0; i < INSERTRUN; i++)
	{
		insert(rand() % 100 + 1);			// insert a random number between 1 and 100
	}

	traversal(root);

	printf("\n");

	search(70, &ch, root);

	exit(EXIT_SUCCESS);
}