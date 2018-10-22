#include "VLRbinarytree.h"

int main()
{
	datatype arr[] = { 1, 2, 3, -1, -1, 5, -1, -1, 6, 7, -1, -1, -1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int usesize = 0;
	BinaryTree *root = AcquireBinaryTree(arr, size, &usesize);
	printf("�����������ǰ��������Ϊ��");
	PrintBinaryTreeInVLR(root);
	printf("\n");
	printf("����������ķǵݹ�ǰ��������Ϊ��");
	NORecursionPrintBinaryTreeInVLR(root);
	printf("\n");
	printf("���������������������Ϊ��");
	PrintBinaryTreeInLVR(root);
	printf("\n");
	printf("����������ķǵݹ�����������Ϊ��");
	NORecursionPrintBinaryTreeInLVR(root);
	printf("\n");
	printf("����������ĺ���������Ϊ��");
	PrintBiaryTreeInLRV(root);
	printf("\n");
	printf("����������ķǵݹ����������Ϊ��");
	NORecursionPrintBinaryTreeInLRV(root);
	printf("\n");
	printf("����������Ľڵ����Ϊ:%d\n", GetNodeSizeOfBinaryTree(root));
	printf("�����������Ҷ�ӽڵ����Ϊ:%d\n", GetLeafNodeSizeOfBinaryTree(root));
	printf("����������ĵ�3��Ľڵ����Ϊ:%d\n", GetKLevelNodeSize(root, 3));
	printf("����������ĸ߶�Ϊ:%d\n", GetHeightOfBinaryTree(root));
	printf("������������в�������Ϊ5�Ľڵ㣬���Ľڵ��ַΪ:%p  ���Ľڵ�����Ϊ:%d\n",
		FindNodeDate(root, 5), FindNodeDate(root, 5)->data);
	//������������
	ImageBinaryTree(root);
	printf("������������ǰ��������Ϊ��");
	PrintBinaryTreeInVLR(root);
	printf("\n");
	//��һ������Ѱ�������ڵ�Ĺ������Ƚڵ�
	printf("%d\n", FindPublicParentNodeForTwoNode(root, FindNodeDate(root, 5), FindNodeDate(root, 3))->data);
	//�ж��Ƿ���ƽ�������
	printf("%d\n", ISBlancedBinaryTree(root));
	//���������������Զ�����ڵ�ľ���
	printf("�������������Զ�����ڵ�ľ����ǣ�%-4d\n", GetLongest(root));
	//����һ����������ǰ�����������ؽ�������
	datatype VLR[6] = { 1, 2, 3, 5, 6, 7 };
	datatype LVR[6] = { 3, 2, 5, 1, 7, 6 };
	BinaryTree *root1 = GetBinaryTreeFromVLRAndLVR(VLR, LVR, 6);
	//����һ���������ĺ������������ؽ�������
	datatype LRV[6] = { 3, 5, 2, 7, 6, 1 };
	BinaryTree *root2 = GetBinaryTreeFromLRVAndLVR(LRV, LVR, 6);
	queue queue;
	QueueInit(&queue);
	ISCompleteBinaryTree(root, &queue);
	return 0;
}