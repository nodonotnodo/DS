#include "VLRbinarytree.h"

//���Ǹ�һ��ǰ����������飬�����������ú�ʵ�������������
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

//���õݹ�ʵ�ֶ�������ǰ������Լ���ӡ
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

//��һ���������ж��ٽڵ㡣
int GetNodeSizeOfBinaryTree(BinaryTree *root)
{
	/*
	�ݹ�˼·��
		�ڵ���� = ���Ľڵ������1�� + �������Ľڵ���� + �������Ľڵ����
		�ڿ������������1.������-----��Ҫ���⴦��
					   2.һ���ڵ������
					   3.ֻ����������������ֻ��һ���ڵ㣻
					   4.ֻ����������������ֻ��һ���ڵ㣻
					   5.��������µ�����
	*/

	if (NULL == root){
		return 0;
	}

	return 1 + GetNodeSizeOfBinaryTree(root->left) + GetNodeSizeOfBinaryTree(root->right);
}

//��Ҷ�ӽڵ������
int GetLeafNodeSizeOfBinaryTree(BinaryTree *root)
{
	/*
	�ݹ�˼·��
		��������Ҷ�ӽڵ���� = ���ڵ��Ҷ�ӽڵ���� + ��������Ҷ�ӽڵ���� + ��������Ҷ�ӽڵ����

		���������1.������0��--------��Ҫ���⴦��
				  2.ֻ��һ���ڵ������1��-------��Ҫ���⴦��
				  3.ֻ����������������ֻ��һ���ڵ㣻
				  4.ֻ����������������ֻ��һ���ڵ㣻
			      5.��������µ�����
	*/

	if (NULL == root){
		return 0;
	}
	if ((root->left == NULL) && (root->right == NULL)){
		return 1;
	}

	return GetLeafNodeSizeOfBinaryTree(root->left) + GetLeafNodeSizeOfBinaryTree(root->right);
}

//���K��ڵ������
int GetKLevelNodeSize(BinaryTree *root, int k)
{
	assert(k > 0);
	/*
	�ݹ�˼�룺
		���Ƕ�����ڵ�Ĳ���Ϊ1��
		��ô��K��Ľڵ���� = ��������K-1��Ľڵ���� + ��������K-1��Ľڵ����

		�������������1.������0��
					  2.ֻ��һ���ڵ������
					  3.ֻ����������������ֻ��һ���ڵ㣻
					  4.ֻ����������������ֻ��һ���ڵ㣻
					  5.��������µ�����
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

//��������ĸ߶ȡ�
int GetHeightOfBinaryTree(BinaryTree *root)
{
	/*
	�ݹ�˼·��
		�������ĸ߶� = ���ڵ�ĸ߶ȣ�1�� + Max���������ĸ߶ȣ��������ĸ߶ȣ�

		����������ǣ�
			1.������0��----��Ҫ���⿼��
			2.ֻ��һ���ڵ������
			3.ֻ����������������ֻ��һ���ڵ㣻
			4.ֻ����������������ֻ��һ���ڵ㣻
			5.��������µ�����
	*/

	if (root == NULL){
		return 0;
	}

	int heightoflefttree = GetHeightOfBinaryTree(root->left);
	int heightofrighttree = GetHeightOfBinaryTree(root->right);
	int max = (heightoflefttree > heightofrighttree) ? heightoflefttree: heightofrighttree;

	return 1 + max;
}

//���ҽڵ㣬Ҫ�����˳��Ϊ��VLR
BinaryTree *FindNodeDate(BinaryTree *root, datatype data)
{
	/*
	�ݹ�˼·��
		�Ƿ���ҵ���˳��鿴 ���ڵ� ���������� ���������Ƿ��ҵ��ڵ㣬���ҵ�ֱ�ӷ��أ����ټ���
		���ҡ�

		�������������
			1.����������NULL��----��Ҫ���⿼��
			2.ֻ��һ���ڵ������
			3.ֻ����������������ֻ��һ���ڵ㣻
			4.ֻ����������������ֻ��һ���ڵ㣻
			5.��������µ�����
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

//�ж�һ���������Ƿ�Ϊ��ȫ��������
void ISCompleteBinaryTree(BinaryTree *root, queue *queue)
{
	/*
	ʹ�ö��й��ѽ��в���������������е�ͷ��Ԫ��Ϊ��ʱ���鿴�����Ƿ�Ϊ�ա�
		Ϊ����Ϊ��ȫ����������Ϊ��������ȫ������
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
			printf("���������������ȫ������\n");
			return;
		}
		queue->front += 1;
	}
	printf("�������������ȫ������\n");
}

//���еĳ�ʼ��
void QueueInit(queue *queue)
{
	assert(queue != NULL);
	queue->front = 0;
	queue->rear = 0;
}

//���еĲ��루���в���ֻ��β�壩
void QueuePush(queue *queue, datatype1 data)
{
	queue->move[queue->rear] = data;
	queue->rear++;
}

//���е�ɾ��������ɾ��ֻ��ͷɾ��
void QueuePop(queue *queue)
{
	assert(queue != NULL);
	if (queue->front >= queue->rear){
		printf("����Ϊ�գ��޷�ɾ��\n");
		return;
	}
	queue->front++;
}