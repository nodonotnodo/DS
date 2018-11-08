#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

//����ѽṹ�壨��������߼�����һ����ȫ��������
typedef struct BinaryHeap{
	int array[100];
	int size;
}BinaryHeap;

//���µ���
void AdjustDown(BinaryHeap *heap, int size, int par);

//Ϊһ�����鴴������һ������Ѵ��
void BinaryHeapInit(int *data, int size, BinaryHeap *heap);

//����ѵ�ɾ��
void BinaryHeapErase(BinaryHeap *heap);

//����ѵĲ���
void BinaryHeapIncase(BinaryHeap *heap, int data);