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

//利用递归实现二叉树的前序遍历以及打印
void PrintBinaryTreeInVLR(BinaryTree *root)
{
	if (NULL == root){
		return;
	}
	else{
		printf("%-4d",root->data);
	}

	PrintBinaryTreeInVLR(root->left);
	PrintBinaryTreeInVLR(root->right);
}

//求一个二叉树有多少节点。
int GetNodeSizeOfBinaryTree(BinaryTree *root)
{
	/*
	递归思路：
		节点个数 = 根的节点个数（1） + 左子树的节点个数 + 右子树的节点个数
		在考虑特殊情况：1.空树；-----需要特殊处理
					   2.一个节点的树；
					   3.只有左子树且左子树只有一个节点；
					   4.只有右子树且右子树只有一个节点；
					   5.正常情况下的树。
	*/

	if (NULL == root){
		return 0;
	}

	return 1 + GetNodeSizeOfBinaryTree(root->left) + GetNodeSizeOfBinaryTree(root->right);
}

//求叶子节点个数。
int GetLeafNodeSizeOfBinaryTree(BinaryTree *root)
{
	/*
	递归思路：
		二叉树的叶子节点个数 = 根节点的叶子节点个数 + 左子树的叶子节点个数 + 右子树的叶子节点个数

		特殊情况：1.空树：0；--------需要特殊处理
				  2.只有一个节点的树：1；-------需要特殊处理
				  3.只有左子树且左子树只有一个节点；
				  4.只有右子树且右子树只有一个节点；
			      5.正常情况下的树。
	*/

	if (NULL == root){
		return 0;
	}
	if ((root->left == NULL) && (root->right == NULL)){
		return 1;
	}

	return GetLeafNodeSizeOfBinaryTree(root->left) + GetLeafNodeSizeOfBinaryTree(root->right);
}

//求第K层节点个数。
int GetKLevelNodeSize(BinaryTree *root, int k)
{
	assert(k > 0);
	/*
	递归思想：
		我们定义根节点的层数为1。
		那么第K层的节点个数 = 左子树第K-1层的节点个数 + 右子树第K-1层的节点个数

		考虑特殊情况：1.空树：0；
					  2.只有一个节点的树；
					  3.只有左子树且左子树只有一个节点；
					  4.只有右子树且右子树只有一个节点；
					  5.正常情况下的树。
	*/

	if (k == 1){
		if (root != NULL){
			return 1;
		}
		else{
			return 0;
		}
	}
	return	GetKLevelNodeSize(root->left, k - 1) + GetKLevelNodeSize(root->right, k - 1);
}

//求二叉树的高度。
int GetHeightOfBinaryTree(BinaryTree *root)
{
	/*
	递归思路：
		二叉树的高度 = 根节点的高度（1） + Max（左子树的高度，右子树的高度）

		特殊情况考虑：
			1.空树：0；----需要特殊考虑
			2.只有一个节点的树；
			3.只有左子树且左子树只有一个节点；
			4.只有右子树且右子树只有一个节点；
			5.正常情况下的树。
	*/

	if (root == NULL){
		return 0;
	}

	int heightoflefttree = GetHeightOfBinaryTree(root->left);
	int heightofrighttree = GetHeightOfBinaryTree(root->right);
	int max = (heightoflefttree > heightofrighttree) ? heightoflefttree: heightofrighttree;

	return 1 + max;
}

//查找节点，要求查找顺序为：VLR
BinaryTree *FindNodeDate(BinaryTree *root, datatype data)
{
	/*
	递归思路：
		是否查找到：顺序查看 根节点 ，左子树， 右子树内是否找到节点，若找到直接返回，不再继续
		查找。

		考虑特殊情况：
			1.空树：返回NULL；----需要特殊考虑
			2.只有一个节点的树；
			3.只有左子树且左子树只有一个节点；
			4.只有右子树且右子树只有一个节点；
			5.正常情况下的树。
	*/

	if (NULL == root){
		return NULL;
	}

	if (data == root->data){
		return root;
	}

	BinaryTree *left = FindNodeDate(root->left, data);
	if (NULL != left){
		return left;
	}
	return FindNodeDate(root->right, data);
}

//判断一个二叉树是否为完全二叉树。
void ISCompleteBinaryTree(BinaryTree *root, queue *queue)
{
	/*
	使用队列广搜进行层序遍历，若当队列的头部元素为空时，查看队列是否为空。
		为空则为完全二叉树，不为空则不是完全二叉树
	*/

	QueuePush(queue, root);
	BinaryTree *cur = queue->move[queue->front];
	while (cur != NULL){
		QueuePop(queue);
		QueuePush(queue, cur->left);
		QueuePush(queue, cur->right);
		cur = queue->move[queue->front];
	}
	while (!(queue->front >= queue->rear)){
		if (queue->move[queue->front] != NULL){
			printf("这个二叉树不是完全二叉树\n");
			return;
		}
		queue->front += 1;
	}
	printf("这个二叉树是完全二叉树\n");
}

//队列的初始化
void QueueInit(queue *queue)
{
	assert(queue != NULL);
	queue->front = 0;
	queue->rear = 0;
}

//队列的插入（队列插入只有尾插）
void QueuePush(queue *queue, datatype1 data)
{
	queue->move[queue->rear] = data;
	queue->rear++;
}

//队列的删除（岁了删除只有头删）
void QueuePop(queue *queue)
{
	assert(queue != NULL);
	if (queue->front >= queue->rear){
		printf("队列为空，无法删除\n");
		return;
	}
	queue->front++;
}