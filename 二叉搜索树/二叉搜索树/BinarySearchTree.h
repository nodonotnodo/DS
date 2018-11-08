#pragma once

//������������
//		1.����������<��<��
//		2.��������>��>��

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

typedef int key;

typedef struct BinarySearchTree{
	key key;
	struct BinarySearchTree *left;
	struct BinarySearchTree *right;
}BinarySearchTree;

//�����������Ĳ���
void BinarySearchTreeInsert(BinarySearchTree **root, key data);

//������������ɾ��
void BinarySearchTreeErase(BinarySearchTree **root, key data);

//�����������Ĳ���   Ҫ���ҵ��������ݵĵ�ַ
BinarySearchTree *BinarySearchTreeFind(BinarySearchTree *root, key data);

//�����������Ĳ��ҽ����ӡ
void Printf(BinarySearchTree *root, key key);