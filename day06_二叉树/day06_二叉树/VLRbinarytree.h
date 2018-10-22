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

//利用非递归实现二叉树的前序遍历以及打印
void NORecursionPrintBinaryTreeInVLR(BinaryTree *root);

//利用递归实现二叉树的中序遍历以及打印
void PrintBinaryTreeInLVR(BinaryTree *root);

//利用非递归实现二叉树的中序遍历以及打印
void NORecursionPrintBinaryTreeInLVR(BinaryTree *root);

//利用递归实现二叉树的中序遍历以及打印
void PrintBiaryTreeInLRV(BinaryTree *root);

//利用非递归实现二叉树的后序遍历以及打印
void NORecursionPrintBinaryTreeInLRV(BinaryTree *root);

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

//二叉树的镜像
void ImageBinaryTree(BinaryTree *root);

//得到寻找节点的路径
BinaryTree **GetWayForFindNode(BinaryTree *root, BinaryTree *child, int *size);

//求两个节点的左近公共祖先节点(在同一颗树里)
BinaryTree *FindPublicParentNodeForTwoNode(BinaryTree *root, BinaryTree *child1, BinaryTree *child2);

//判断一个树是否为平衡二叉树，是返回0，不是返回-1
int ISBlancedBinaryTree(BinaryTree *root);

//求二叉树中最远两个节点的距离。
int GetLongest(BinaryTree *root);

//给出一个二叉树的前序和中序遍历结果，重建这个二叉树
BinaryTree *GetBinaryTreeFromVLRAndLVR(datatype *VLR, datatype *LVR, int size);

//给出一个二叉树的后序和中序遍历结果，重建这个二叉树
BinaryTree *GetBinaryTreeFromLRVAndLVR(datatype *LRV, datatype *LVR, int size);

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