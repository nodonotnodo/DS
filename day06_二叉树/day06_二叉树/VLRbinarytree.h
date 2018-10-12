#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int datatype;

//���ȶ���һ��������
typedef struct BinaryTree{
	datatype data;
	struct BinaryTree *left;
	struct BinaryTree *right;
} BinaryTree;

//���Ǹ�һ��ǰ����������飬�����������ú�ʵ�������������
BinaryTree *AcquireBinaryTree(datatype arr[], int size, int* usesize);

//���õݹ�ʵ�ֶ�������ǰ������Լ���ӡ
void PrintBinaryTreeInVLR(BinaryTree *root);

//���õݹ�ʵ�ֶ���������������Լ���ӡ
void PrintBinaryTreeInLVR(BinaryTree *root);

//���õݹ�ʵ�ֶ���������������Լ���ӡ
void PrintBiaryTreeInLRV(BinaryTree *root);

//��һ���������ж��ٽڵ㡣
int GetNodeSizeOfBinaryTree(BinaryTree *root);

//��Ҷ�ӽڵ������
int GetLeafNodeSizeOfBinaryTree(BinaryTree *root);

//���K��ڵ������
int GetKLevelNodeSize(BinaryTree *root, int k);

//��������ĸ߶ȡ�
int GetHeightOfBinaryTree(BinaryTree *root);

//���ҽڵ㣬Ҫ�����˳��Ϊ��VLR
BinaryTree *FindNodeDate(BinaryTree *root, datatype data);



//����

#define ROW (10)
#define COL (10)
typedef BinaryTree* datatype1;

//������У������е���ϢӦ��Ϊһ���ṹ�����飬����ṹ�����·����Ϣ�����˶��ٲ�
typedef struct queue{
	datatype1 move[ROW*COL];
	int front;
	int rear;
}queue;

//��ʼʵ�ֶ���

//���еĳ�ʼ��
void QueueInit(queue *queue);

//���еĲ��루���в���ֻ��β�壩
void QueuePush(queue *queue, datatype1 data);

//���е�ɾ��������ɾ��ֻ��ͷɾ��
void QueuePop(queue *queue);

//�ж�һ���������Ƿ�Ϊ��ȫ��������
void ISCompleteBinaryTree(BinaryTree *root, queue *queue);