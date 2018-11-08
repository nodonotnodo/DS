#include "BinarySearchTree.h"

int main()
{
	BinarySearchTree *root = NULL;
	BinarySearchTreeInsert(&root, 9);
	BinarySearchTreeInsert(&root, 2);
	BinarySearchTreeInsert(&root, 4);
	BinarySearchTreeInsert(&root, 8);
	BinarySearchTreeInsert(&root, 12);
	BinarySearchTreeInsert(&root, 1);
	BinarySearchTreeInsert(&root, 27);
	BinarySearchTreeInsert(&root, 5);
	BinarySearchTreeInsert(&root, 3);
	BinarySearchTreeInsert(&root, 19);
	Printf(BinarySearchTreeFind(root, 9), 9);
	Printf(BinarySearchTreeFind(root, 10), 10);
	BinarySearchTreeErase(&root, 9);
	return 0;
}