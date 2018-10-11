#include "VLRbinarytree.h"

int main()
{
	datatype arr[] = { 1, 2, 3, -1,-1,5,-1,-1,6,7,-1,-1,-1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int usesize = 0;
	BinaryTree *root = AcquireBinaryTree(arr, size, &usesize);
	PrintBinaryTreeInVLR(root);
	printf("\n");
	printf("����������Ľڵ����Ϊ:%d\n", GetNodeSizeOfBinaryTree(root));
	printf("�����������Ҷ�ӽڵ����Ϊ:%d\n", GetLeafNodeSizeOfBinaryTree(root));
	printf("����������ĵ�3��Ľڵ����Ϊ:%d\n", GetKLevelNodeSize(root, 3));
	printf("����������ĸ߶�Ϊ:%d\n", GetHeightOfBinaryTree(root));
	printf("������������в�������Ϊ5�Ľڵ㣬���Ľڵ��ַΪ:%p  ���Ľڵ�����Ϊ:%d\n",
		FindNodeDate(root, 5), FindNodeDate(root, 5)->data);

	queue queue;
	QueueInit(&queue);
	ISCompleteBinaryTree(root, &queue);
	return 0;
}