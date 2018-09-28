#include "VLRbinarytree.h"

int main()
{
	datatype arr[] = { 1, 2, 3, 4, -1, -1, -1, 5, -1, -1, 6, 7, 8, -1, -1, -1, -1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int usesize = 0;
	BinaryTree *root = AcquireBinaryTree(arr, size, &usesize);
	return 0;
}