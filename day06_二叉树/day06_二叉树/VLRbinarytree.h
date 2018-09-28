#pragma once

#include <stdio.h>
#include <stdlib.h>

typedef int datatype;

//���ȶ���һ��������
typedef struct BinaryTree{
	datatype data;
	struct BinaryTree *left;
	struct BinaryTree *right;
} BinaryTree;

//���Ǹ�һ��ǰ����������飬�����������ú�ʵ�������������
BinaryTree *AcquireBinaryTree(datatype arr[], int size, int* usesize);