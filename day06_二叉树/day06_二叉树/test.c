#include "VLRbinarytree.h"

int main()
{
	datatype arr[] = { 1, 2, 3, -1,-1,5,-1,-1,6,7,-1,-1,-1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int usesize = 0;
	BinaryTree *root = AcquireBinaryTree(arr, size, &usesize);
	PrintBinaryTreeInVLR(root);
	printf("\n");
	printf("这个二叉树的节点个数为:%d\n", GetNodeSizeOfBinaryTree(root));
	printf("这个二叉树的叶子节点个数为:%d\n", GetLeafNodeSizeOfBinaryTree(root));
	printf("这个二叉树的第3层的节点个数为:%d\n", GetKLevelNodeSize(root, 3));
	printf("这个二叉树的高度为:%d\n", GetHeightOfBinaryTree(root));
	printf("在这个二叉树中查找数据为5的节点，它的节点地址为:%p  它的节点数据为:%d\n",
		FindNodeDate(root, 5), FindNodeDate(root, 5)->data);

	queue queue;
	QueueInit(&queue);
	ISCompleteBinaryTree(root, &queue);
	return 0;
}