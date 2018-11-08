#include "BinarySearchTree.h"

//二叉搜索树的插入
void BinarySearchTreeInsert(BinarySearchTree **root, key data)
{
	assert(root != NULL);
	//空树插入
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
		printf("数据重复，插入失败。\n");
		exit(EXIT_SUCCESS);
	}
	else if ((*root)->key < data){
		BinarySearchTreeInsert(&((*root)->right), data);
	}
	else{
		BinarySearchTreeInsert(&((*root)->left), data);
	}
}

//二叉搜索树的删除
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
				//此时要删除的节点左右子树都不为空
				//此时要用右子树中最小的数据把这个节点替换掉
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
	printf("无此数据,删除失败\n");
}

//二叉搜索树的查找   要求：找到返回数据的地址
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

//二叉搜索树的查找结果打印
void Printf(BinarySearchTree *root, key key)
{
	printf("在这个二叉树中搜索%d，搜索结果为:0x%p", key, root);
	if (root != NULL){
		printf("-->%d", root->key);
	}
	printf("\n");
}