#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

typedef int datatype;

//首先定义一个二叉树
typedef struct BinaryTree{
	datatype data;
	struct BinaryTree *left;
	struct BinaryTree *right;
} BinaryTree;

//我们给一个前序二叉树数组，经过函数调用后实现这个二叉树。
BinaryTree *AcquireBinaryTree(datatype arr[], int size, int* usesize);

//利用递归实现二叉树的前序遍历以及打印
void PrintBinaryTreeInVLR(BinaryTree *root);

//利用递归实现二叉树的中序遍历以及打印
void PrintBinaryTreeInLVR(BinaryTree *root);

//利用递归实现二叉树的中序遍历以及打印
void PrintBiaryTreeInLRV(BinaryTree *root);

//求一个二叉树有多少节点。
int GetNodeSizeOfBinaryTree(BinaryTree *root);

//求叶子节点个数。
int GetLeafNodeSizeOfBinaryTree(BinaryTree *root);

//求第K层节点个数。
int GetKLevelNodeSize(BinaryTree *root, int k);

//求二叉树的高度。
int GetHeightOfBinaryTree(BinaryTree *root);

//查找节点，要求查找顺序为：VLR
BinaryTree *FindNodeDate(BinaryTree *root, datatype data);



//队列

#define ROW (10)
#define COL (10)
typedef BinaryTree* datatype1;

//定义队列，队列中的信息应该为一个结构体数组，这个结构体包括路的信息和走了多少步
typedef struct queue{
	datatype1 move[ROW*COL];
	int front;
	int rear;
}queue;

//开始实现队列

//队列的初始化
void QueueInit(queue *queue);

//队列的插入（队列插入只有尾插）
void QueuePush(queue *queue, datatype1 data);

//队列的删除（岁了删除只有头删）
void QueuePop(queue *queue);

//判断一个二叉树是否为完全二叉树。
void ISCompleteBinaryTree(BinaryTree *root, queue *queue);