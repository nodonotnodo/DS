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

//利用非递归实现二叉树的前序遍历以及打印
void NORecursionPrintBinaryTreeInVLR(BinaryTree *root)
{
	//定义一个简单的栈
	BinaryTree *stack[10] = {0};
	int size = 0;

	while (!((size <= 0)&&(root == NULL))){
		//每次将节点数据打印，并将节点地址存入栈中。
		if (root == NULL){
			root = stack[size - 1]->right;
			size--;
			continue;
		}
		printf("%-4d", root->data);
		stack[size] = root;
		size++;

		//开始遍历root的左子树
		root = root->left;
	}	
}

//利用递归实现二叉树的中序遍历以及打印
void PrintBinaryTreeInLVR(BinaryTree *root)
{
	/*
	递归思路：
		先打印左子树，在打印根，最后打印右子树。

		特殊情况的考虑：
				1.空树：return-----需要特殊处理；
				2.一个节点的树：打印根节点数据；
				3.只有左子树且左子树只有一个节点；
			    4.只有右子树且右子树只有一个节点；
				5.正常情况下的树
	*/

	if (NULL == root){
		return;
	}

	PrintBinaryTreeInLVR(root->left);
	printf("%-4d", root->data);
	PrintBinaryTreeInLVR(root->right);
}

//利用非递归实现二叉树的中序遍历以及打印
void NORecursionPrintBinaryTreeInLVR(BinaryTree *root)
{
	//定义一个简单栈。
	BinaryTree *stack[10] = { 0 };
	int size = 0;

	while (!((root == NULL) && (size == 0))){
		
		//root为空，两种情况：1.左子树为空，打印栈顶元素数据，并开始遍历右子树
		//					 2.右子树为空，打印栈顶元素数据，并开始遍历右子树
		if (root == NULL){
			printf("%-4d", stack[size - 1]->data);
			root = stack[size - 1]->right;
			size--;
			continue;
		}

		//将这个节点地址入栈。
		stack[size] = root;
		size++;

		//开始遍历左子树
		root = root->left;
	}
}

//利用递归实现二叉树的后序遍历以及打印
void PrintBiaryTreeInLRV(BinaryTree *root)
{
	if (NULL == root){
		return;
	}

	PrintBiaryTreeInLRV(root->left);
	PrintBiaryTreeInLRV(root->right);
	printf("%-4d", root->data);
}

//利用非递归实现二叉树的后序遍历以及打印
void NORecursionPrintBinaryTreeInLRV(BinaryTree *root)
{
	//实现一个简单栈。
	BinaryTree *stack[10] = { 0 };
	int size = 0;
	BinaryTree *last = NULL;
	while (!((root == NULL) && (size == 0))){
		//先遍历左子树
		while (root != NULL){
			stack[size] = root;
			size++;
			root = root->left;
		}
		if ((stack[size-1]->right == NULL)||(stack[size-1]->right == last)){
			printf("%-4d", stack[size-1]->data);
			last = stack[size-1];
			size--;
		}
		else{
			root = stack[size - 1]->right;
		}
	}
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

//二叉树的镜像
void ImageBinaryTree(BinaryTree *root)
{
	/*
	递归考虑：
			根节点镜像，左子树与右子树互换。但是子树也需要镜像。
	*/
	if (root == NULL){
		return;
	}
	BinaryTree *tmp = root->left;
	root->left = root->right;
	root->right = tmp;
	ImageBinaryTree(root->left);
	ImageBinaryTree(root->right);
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

//得到寻找节点的路径
BinaryTree ** GetWayForFindNode(BinaryTree *root, BinaryTree *child, int *size)
{
	//实现一个简单栈。
	BinaryTree *stack[10] = {0};
	BinaryTree *last = NULL;
	while (root != child){
		//先遍历左子树
		while (root != NULL){
			if (root == child){
				return stack;
			}
			stack[(*size)] = root;
			(*size)++;
			if (root == child){
				return stack[10];
			}
			root = root->left;
		}
		if ((stack[(*size) - 1]->right == NULL) || (stack[(*size) - 1]->right == last)){
			last = stack[(*size) - 1];
			(*size)--;
		}
		else{
			root = stack[(*size) - 1]->right;
		}
	}
	return stack;
}

//求两个节点的左近公共祖先节点(在同一颗树里)
BinaryTree *FindPublicParentNodeForTwoNode(BinaryTree *root, BinaryTree *child1, BinaryTree *child2)
{
	//child1的路径。
	int size1 = 0;
	BinaryTree *stack1[10] = { 0 };
	BinaryTree **stack3 = GetWayForFindNode(root, child1, &size1);
	for (int i = 0; i < size1; i++){
		stack1[i] = *(stack3++);
	}

	//child2的路径。
	int size2 = 0;
	BinaryTree *stack2[10] = { 0 };
	BinaryTree **stack4 = GetWayForFindNode(root, child2, &size2);
	for (int i = 0; i < size2; i++){
		stack2[i] = *(stack4++);
	}

	//知道了child1和child2的路径后，我们就可以找到它们的公共祖先节点了。
	if (size1 > size2){
		while (size2 >= 0){
			--size2;
			if (stack1[size2] == stack2[size2]){
				return stack1[size2];
			}
		}
	}
	else{
		while (size1 >= 0){
			--size1;
			if (stack1[size1] == stack2[size1]){
				return stack1[size1];
			}
		}
	}
}

//判断一个树是否为平衡二叉树，是返回0，不是返回-1
int ISBlancedBinaryTree(BinaryTree *root)
{
	/*
		平衡二叉树概念：左右子树高度差不超过1，并且左右子树也是平衡二叉树。
		递归思想：得到左子树高度和右子树高度，判断是否为平衡二叉树。子树亦如此。
	*/
	if (root == NULL){
		return 0;
	}
	int HeightOfleft = GetHeightOfBinaryTree(root->left);
	int HeightOfright = GetHeightOfBinaryTree(root->right);
	int differenceHeightOFleftAndright = HeightOfleft - HeightOfright;
	if (differenceHeightOFleftAndright*differenceHeightOFleftAndright <= 1){
		ISBlancedBinaryTree(root->left);
		ISBlancedBinaryTree(root->right);
	}
	else{
		return -1;
	}
}

int maxnum(int a, int b, int c)
{
	int max = a;
	if (max < b){
		max = b;
	}
	if (max < c){
		max = c;
	}
	return max;
}

//求二叉树中最远两个节点的距离。
int GetLongest(BinaryTree *root)
{
	if (root == NULL){
		return 0;
	}
	else if (root->left == NULL && root->right == NULL){
		return 1;
	}
	else{
		int left = GetLongest(root->left);
		int right = GetLongest(root->right);
		int self = GetHeightOfBinaryTree(root->left) + GetHeightOfBinaryTree(root->right);
		return maxnum(left, right, self);
	}
}

//给出一个二叉树的前序和中序遍历结果，重建这个二叉树
BinaryTree *GetBinaryTreeFromVLRAndLVR(datatype *VLR, datatype *LVR, int size)
{
	/*
	这个二叉树的前序遍历结果为：1   2   3   5   6   7
	这个二叉树的中序遍历结果为：3   2   5   1   7   6
	这个二叉树的后序遍历结果为：3   5   2   7   6   1

		前序：
		后序：
		前序得到根节点数据，在从中序中得到左子树和右子树的前序和中序，以此递归。
	*/
	if (size <= 0){
		return NULL;
	}
	BinaryTree *root = (BinaryTree *)malloc(sizeof(BinaryTree *));
	root->data = VLR[0];
	int num = 0;
	while (num < size){
		if (LVR[num] == root->data){
			break;
		}
		num++;
	}
	if (1 >= size){
		root->left = NULL;
	} else{
		root->left = GetBinaryTreeFromVLRAndLVR(VLR + 1, LVR, num);
	}
	if (1 + num >= size){
		root->right = NULL;
	}
	else{
		root->right = GetBinaryTreeFromVLRAndLVR(VLR + 1 + num, LVR + num + 1, size-1-num);
	}
	return root;
}

//给出一个二叉树的后序和中序遍历结果，重建这个二叉树
BinaryTree *GetBinaryTreeFromLRVAndLVR(datatype *LRV, datatype *LVR, int size)
{
	/*
	这个二叉树的前序遍历结果为：1   2   3   5   6   7
	这个二叉树的中序遍历结果为：3   2   5   1   7   6
	这个二叉树的后序遍历结果为：3   5   2   7   6   1

	前序：
	后序：
	前序得到根节点数据，在从中序中得到左子树和右子树的后序和中序，以此递归。
	*/
	if (size <= 0){
		return NULL;
	}
	BinaryTree *root = (BinaryTree *)malloc(sizeof(BinaryTree *));
	root->data = LRV[size-1];
	int num = 0;
	while (num < size){
		if (LVR[num] == root->data){
			break;
		}
		num++;
	}
	root->left = GetBinaryTreeFromLRVAndLVR(LRV, LVR, num);
	root->right = GetBinaryTreeFromLRVAndLVR(LRV + num, LVR + num + 1, size - 1 - num);
	return root;
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