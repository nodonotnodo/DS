#include "VLRbinarytree.h"

int main()
{
	datatype arr[] = { 1, 2, 3, -1, -1, 5, -1, -1, 6, 7, -1, -1, -1 };
	int size = sizeof(arr) / sizeof(arr[0]);
	int usesize = 0;
	BinaryTree *root = AcquireBinaryTree(arr, size, &usesize);
	printf("这个二叉树的前序遍历结果为：");
	PrintBinaryTreeInVLR(root);
	printf("\n");
	printf("这个二叉树的非递归前序遍历结果为：");
	NORecursionPrintBinaryTreeInVLR(root);
	printf("\n");
	printf("这个二叉树的中序遍历结果为：");
	PrintBinaryTreeInLVR(root);
	printf("\n");
	printf("这个二叉树的非递归中序遍历结果为：");
	NORecursionPrintBinaryTreeInLVR(root);
	printf("\n");
	printf("这个二叉树的后序遍历结果为：");
	PrintBiaryTreeInLRV(root);
	printf("\n");
	printf("这个二叉树的非递归后序遍历结果为：");
	NORecursionPrintBinaryTreeInLRV(root);
	printf("\n");
	printf("这个二叉树的节点个数为:%d\n", GetNodeSizeOfBinaryTree(root));
	printf("这个二叉树的叶子节点个数为:%d\n", GetLeafNodeSizeOfBinaryTree(root));
	printf("这个二叉树的第3层的节点个数为:%d\n", GetKLevelNodeSize(root, 3));
	printf("这个二叉树的高度为:%d\n", GetHeightOfBinaryTree(root));
	printf("在这个二叉树中查找数据为5的节点，它的节点地址为:%p  它的节点数据为:%d\n",
		FindNodeDate(root, 5), FindNodeDate(root, 5)->data);
	//将二叉树镜像
	ImageBinaryTree(root);
	printf("二叉树镜像后的前序遍历结果为：");
	PrintBinaryTreeInVLR(root);
	printf("\n");
	//在一棵树中寻找两个节点的公共祖先节点
	printf("%d\n", FindPublicParentNodeForTwoNode(root, FindNodeDate(root, 5), FindNodeDate(root, 3))->data);
	//判断是否是平衡二叉树
	printf("%d\n", ISBlancedBinaryTree(root));
	//求这个二叉树中最远两个节点的距离
	printf("这个二叉树中最远两个节点的距离是：%-4d\n", GetLongest(root));
	//根据一个二叉树的前序和中序遍历重建二叉树
	datatype VLR[6] = { 1, 2, 3, 5, 6, 7 };
	datatype LVR[6] = { 3, 2, 5, 1, 7, 6 };
	BinaryTree *root1 = GetBinaryTreeFromVLRAndLVR(VLR, LVR, 6);
	//根据一个二叉树的后序和中序遍历重建二叉树
	datatype LRV[6] = { 3, 5, 2, 7, 6, 1 };
	BinaryTree *root2 = GetBinaryTreeFromLRVAndLVR(LRV, LVR, 6);
	queue queue;
	QueueInit(&queue);
	ISCompleteBinaryTree(root, &queue);
	return 0;
}