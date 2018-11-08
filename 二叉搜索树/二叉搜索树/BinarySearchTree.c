#include "BinarySearchTree.h"

//�����������Ĳ���
void BinarySearchTreeInsert(BinarySearchTree **root, key data)
{
	assert(root != NULL);
	//��������
	if (*root == NULL){
		BinarySearchTree *node = (BinarySearchTree *)malloc(sizeof(BinarySearchTree));
		if (node == NULL){
			printf("error for make newnode\n");
			exit(EXIT_FAILURE);
		}
		node->key = data;
		node->left = NULL;
		node->right = NULL;
		*root = node;
		return;
	}
	if ((*root)->key == data){
		printf("�����ظ�������ʧ�ܡ�\n");
		exit(EXIT_SUCCESS);
	}
	else if ((*root)->key < data){
		BinarySearchTreeInsert(&((*root)->right), data);
	}
	else{
		BinarySearchTreeInsert(&((*root)->left), data);
	}
}

//������������ɾ��
void BinarySearchTreeErase(BinarySearchTree **root, key data)
{
	assert(root != NULL);
	BinarySearchTree *cur = *root;
	BinarySearchTree *par = NULL;
	while (!(cur == NULL)){
		if (cur->key == data){
			if (cur->left == NULL){
				free(cur);
				if (par == NULL){
					*root = NULL;
				}
				else if(data < par->key){
					par->left = cur->right;
				}
				else{
					par->right = cur->right;
				}
				return;
			}
			else if (cur->right == NULL){
				free(cur);
				if (par == NULL){
					*root = NULL;
				}
				else if (data < par->key){
					par->left = cur->left;
				}
				else{
					par->right = cur->left;
				}
				return;
			}
			else{
				//��ʱҪɾ���Ľڵ�������������Ϊ��
				//��ʱҪ������������С�����ݰ�����ڵ��滻��
				BinarySearchTree *del = cur->right;
				BinarySearchTree *pardel = cur;
				while (del->left != NULL){
					pardel = del;
					del = del->left;
				}
				cur->key = del->key;
				if (pardel == cur){
					pardel->right = del->right;
				}
				else{
					pardel->left = del->right;
				}
				free(del);
				return;
			}
		}
	}
	printf("�޴�����,ɾ��ʧ��\n");
}

//�����������Ĳ���   Ҫ���ҵ��������ݵĵ�ַ
BinarySearchTree *BinarySearchTreeFind(BinarySearchTree *root, key data)
{
	BinarySearchTree *cur = root;
	while (!(cur == NULL)){
		if (cur->key == data){
			return cur;
		}
		else if (cur->key > data){
			return BinarySearchTreeFind(cur->left, data);
		}
		else{
			return BinarySearchTreeFind(cur->right, data);
		}
	}
	return NULL;
}

//�����������Ĳ��ҽ����ӡ
void Printf(BinarySearchTree *root, key key)
{
	printf("�����������������%d���������Ϊ:0x%p", key, root);
	if (root != NULL){
		printf("-->%d", root->key);
	}
	printf("\n");
}