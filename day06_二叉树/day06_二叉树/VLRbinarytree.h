#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

//首先定义一个二叉树
typedef struct BinaryTree{
	datatype data;
	struct BinaryTree *left;
	struct BinaryTree *right;
} BinaryTree;

//我们给一个前序二叉树数组，经过函数调用后实现这个二叉树。
BinaryTree *AcquireBinaryTree(datatype arr[], int size, int* usesize);