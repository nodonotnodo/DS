#pragma once

//二叉搜索树：
//		1.有序升序：左<根<右
//		2.有序降序：左>根>右

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int key;

typedef struct BinarySearchTree{
	key key;
	struct BinarySearchTree *left;
	struct BinarySearchTree *right;
}BinarySearchTree;

//二叉搜索树的插入
void BinarySearchTreeInsert(BinarySearchTree **root, key data);

//二叉搜索树的删除
void BinarySearchTreeErase(BinarySearchTree **root, key data);

//二叉搜索树的查找   要求：找到返回数据的地址
BinarySearchTree *BinarySearchTreeFind(BinarySearchTree *root, key data);

//二叉搜索树的查找结果打印
void Printf(BinarySearchTree *root, key key);