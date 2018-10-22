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

//���÷ǵݹ�ʵ�ֶ�������ǰ������Լ���ӡ
void NORecursionPrintBinaryTreeInVLR(BinaryTree *root)
{
	//����һ���򵥵�ջ
	BinaryTree *stack[10] = {0};
	int size = 0;

	while (!((size <= 0)&&(root == NULL))){
		//ÿ�ν��ڵ����ݴ�ӡ�������ڵ��ַ����ջ�С�
		if (root == NULL){
			root = stack[size - 1]->right;
			size--;
			continue;
		}
		printf("%-4d", root->data);
		stack[size] = root;
		size++;

		//��ʼ����root��������
		root = root->left;
	}	
}

//���õݹ�ʵ�ֶ���������������Լ���ӡ
void PrintBinaryTreeInLVR(BinaryTree *root)
{
	/*
	�ݹ�˼·��
		�ȴ�ӡ���������ڴ�ӡ��������ӡ��������

		��������Ŀ��ǣ�
				1.������return-----��Ҫ���⴦��
				2.һ���ڵ��������ӡ���ڵ����ݣ�
				3.ֻ����������������ֻ��һ���ڵ㣻
			    4.ֻ����������������ֻ��һ���ڵ㣻
				5.��������µ���
	*/

	if (NULL == root){
		return;
	}

	PrintBinaryTreeInLVR(root->left);
	printf("%-4d", root->data);
	PrintBinaryTreeInLVR(root->right);
}

//���÷ǵݹ�ʵ�ֶ���������������Լ���ӡ
void NORecursionPrintBinaryTreeInLVR(BinaryTree *root)
{
	//����һ����ջ��
	BinaryTree *stack[10] = { 0 };
	int size = 0;

	while (!((root == NULL) && (size == 0))){
		
		//rootΪ�գ����������1.������Ϊ�գ���ӡջ��Ԫ�����ݣ�����ʼ����������
		//					 2.������Ϊ�գ���ӡջ��Ԫ�����ݣ�����ʼ����������
		if (root == NULL){
			printf("%-4d", stack[size - 1]->data);
			root = stack[size - 1]->right;
			size--;
			continue;
		}

		//������ڵ��ַ��ջ��
		stack[size] = root;
		size++;

		//��ʼ����������
		root = root->left;
	}
}

//���õݹ�ʵ�ֶ������ĺ�������Լ���ӡ
void PrintBiaryTreeInLRV(BinaryTree *root)
{
	if (NULL == root){
		return;
	}

	PrintBiaryTreeInLRV(root->left);
	PrintBiaryTreeInLRV(root->right);
	printf("%-4d", root->data);
}

//���÷ǵݹ�ʵ�ֶ������ĺ�������Լ���ӡ
void NORecursionPrintBinaryTreeInLRV(BinaryTree *root)
{
	//ʵ��һ����ջ��
	BinaryTree *stack[10] = { 0 };
	int size = 0;
	BinaryTree *last = NULL;
	while (!((root == NULL) && (size == 0))){
		//�ȱ���������
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

//�������ľ���
void ImageBinaryTree(BinaryTree *root)
{
	/*
	�ݹ鿼�ǣ�
			���ڵ㾵������������������������������Ҳ��Ҫ����
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

//�õ�Ѱ�ҽڵ��·��
BinaryTree ** GetWayForFindNode(BinaryTree *root, BinaryTree *child, int *size)
{
	//ʵ��һ����ջ��
	BinaryTree *stack[10] = {0};
	BinaryTree *last = NULL;
	while (root != child){
		//�ȱ���������
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

//�������ڵ������������Ƚڵ�(��ͬһ������)
BinaryTree *FindPublicParentNodeForTwoNode(BinaryTree *root, BinaryTree *child1, BinaryTree *child2)
{
	//child1��·����
	int size1 = 0;
	BinaryTree *stack1[10] = { 0 };
	BinaryTree **stack3 = GetWayForFindNode(root, child1, &size1);
	for (int i = 0; i < size1; i++){
		stack1[i] = *(stack3++);
	}

	//child2��·����
	int size2 = 0;
	BinaryTree *stack2[10] = { 0 };
	BinaryTree **stack4 = GetWayForFindNode(root, child2, &size2);
	for (int i = 0; i < size2; i++){
		stack2[i] = *(stack4++);
	}

	//֪����child1��child2��·�������ǾͿ����ҵ����ǵĹ������Ƚڵ��ˡ�
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

//�ж�һ�����Ƿ�Ϊƽ����������Ƿ���0�����Ƿ���-1
int ISBlancedBinaryTree(BinaryTree *root)
{
	/*
		ƽ�������������������߶Ȳ����1��������������Ҳ��ƽ���������
		�ݹ�˼�룺�õ��������߶Ⱥ��������߶ȣ��ж��Ƿ�Ϊƽ�����������������ˡ�
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

//�����������Զ�����ڵ�ľ��롣
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

//����һ����������ǰ����������������ؽ����������
BinaryTree *GetBinaryTreeFromVLRAndLVR(datatype *VLR, datatype *LVR, int size)
{
	/*
	�����������ǰ��������Ϊ��1   2   3   5   6   7
	���������������������Ϊ��3   2   5   1   7   6
	����������ĺ���������Ϊ��3   5   2   7   6   1

		ǰ��
		����
		ǰ��õ����ڵ����ݣ��ڴ������еõ�����������������ǰ��������Դ˵ݹ顣
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

//����һ���������ĺ�����������������ؽ����������
BinaryTree *GetBinaryTreeFromLRVAndLVR(datatype *LRV, datatype *LVR, int size)
{
	/*
	�����������ǰ��������Ϊ��1   2   3   5   6   7
	���������������������Ϊ��3   2   5   1   7   6
	����������ĺ���������Ϊ��3   5   2   7   6   1

	ǰ��
	����
	ǰ��õ����ڵ����ݣ��ڴ������еõ����������������ĺ���������Դ˵ݹ顣
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