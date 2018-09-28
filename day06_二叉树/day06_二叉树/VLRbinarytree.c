#include "VLRbinarytree.h"

//我们给一个前序二叉树数组，经过函数调用后实现这个二叉树。
BinaryTree *AcquireBinaryTree(datatype arr[], int size, int* usesize)
{
	if (size <= 0){
		*usesize = 0;
		return NULL;
	}
	if (-1 == arr[0]){
		*usesize = 1;
		return NULL;
	}
	int leftuse, rightuse;
	BinaryTree *root = (BinaryTree *)malloc(sizeof(BinaryTree));
	root->data = arr[0];
	root->left = root->right = NULL;

	root->left = AcquireBinaryTree(arr + 1, size - 1, &leftuse);
	root->right = AcquireBinaryTree(arr + 1 + leftuse, size - 1 - leftuse, &rightuse);
	*usesize = 1 + leftuse + rightuse;

	return root;
}