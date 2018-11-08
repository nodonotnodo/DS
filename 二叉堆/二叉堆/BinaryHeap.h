#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//二叉堆结构体（二叉堆在逻辑上是一个完全二叉树）
typedef struct BinaryHeap{
	int array[100];
	int size;
}BinaryHeap;

//向下调整
void AdjustDown(BinaryHeap *heap, int size, int par);

//为一个数组创建爱你一个二叉堆大堆
void BinaryHeapInit(int *data, int size, BinaryHeap *heap);

//二叉堆的删除
void BinaryHeapErase(BinaryHeap *heap);

//二叉堆的插入
void BinaryHeapIncase(BinaryHeap *heap, int data);