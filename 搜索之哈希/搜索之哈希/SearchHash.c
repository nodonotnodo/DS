#include "SearchHash.h"

//练习1
//首先来做一个练习1：判断一组字符串(只有小写字母)中第一个只出现一次的字符。
//找到则返回这个字符地址，否则返回NULL
char *Practice1(char *str, int size)
{
	int hash1[26];
	int i = 0;
	for (; i < 26; i++){
		hash1[i] = 0;
	}
	int index = -1;
	for (i = 0; i < size; i++){
		index = str[i] - 'a';
		hash1[index]++;
	}
	for (i = 0; i < size; i++){
		index = str[i] - 'a';
		if (1 == hash1[index]){
			return str + i;
		}
	}
	return NULL;
}

//练习2：判断一组无符号int型数据中第一个只出现一次的数字。
//找到则返回这个数字的地址，否则返回NULL

/*
这样我们无法在利用像练习1那样的方法直接给实物确定一个坐标。
我们假设hash2数组长度为m，那么我们可以定义一个数字的下标为n%m。
但是这样的话会产生一个问题，那就是m和2m的下标一致。这种情况就是哈希冲突。
我们解决的办法分为闭散列和开散列。
*/

//闭散列
/*
比散列又叫开放地址法，当发生哈希冲突时，如果哈希表未被装满，那么哈希表一定还有空位，
那么就将key放在哈希表中的下一个空位。
*/

//闭散列初始化哈希表
void ClosedHashInit(Hash *hash)
{
	hash->capacity = 23;
	hash->size = 0;
	hash->hash2 = (hashdata *)malloc(sizeof(hashdata)*hash->capacity);
	if (hash->hash2 == NULL){
		perror("error for malloc\n");
		exit(EXIT_FAILURE);
	}
	for (int i = 0; i < hash->capacity; i++){
		hash->hash2[i].data = 0;
		hash->hash2[i].status = -1;
	}
}

//闭散列销毁哈希表
void ClosedHashErase(Hash *hash)
{
	free(hash->hash2);
	hash->capacity = 0;
	hash->size = 0;
	hash->hash2 = NULL;
}

//闭散列哈希表查找。找到返回0，未找到返回1。
int ClosedHashFind(Hash *hash, int data)
{
	int index = data % hash->capacity;
	int i = 1;
	while (i < hash->capacity){
		if (hash->hash2[index].data == data && hash->hash2[index].status == 0){
			return 0;
		}
		index = (index + i) % hash->capacity;
		i++;
	}
	return 1;
}

//闭散列哈希表扩容
void ClosedHashInaertCapacity(Hash *hash)
{
	hashdata *new = (hashdata *)malloc(sizeof(hashdata)*hash->capacity * 2);
	for (int i = 0; i < hash->capacity; i++){
		new[i] = hash->hash2[i];
	}
	for (int i = hash->capacity; i < hash->capacity * 2; i++){
		new[i].data = 0;
		new[i].size = 0;
		new[i].status = -1;
	}
	hashdata *willdel = hash->hash2;
	free(willdel);
	hash->hash2 = new;
	hash->capacity *= 2;
}

//闭散列哈希表插入
void ClosedHashInsert(Hash *hash, int data)
{
	int index = data % hash->capacity;//获得数据的下标。
	int i = 1;
	while (1){
		if (hash->size * 10 / hash->capacity > 7){
			//此处应该扩容。
			/*printf("哈希表即将退化，请增容\n");
			exit(EXIT_SUCCESS);*/
			ClosedHashInaertCapacity(hash);
		}
		if (hash->hash2[index].status == -1){
			//若哈希表这个位置为空，则直接将插入数据，改变状态，改变数据计数。
			hash->hash2[index].data = data;
			hash->hash2[index].size = 1;
			hash->hash2[index].status = 0;
			hash->size++;
			return;
		}
		else if (hash->hash2[index].status == 0){
			//若哈希表这个位置已经存入数据，则判断已存数据是否与要存的数据相同
			//		相同：size加1
			//		不同：继续向后寻找，直到找到“空位”
			if (hash->hash2[index].data == data){
				hash->hash2[index].size++;
				hash->size++;
				return;
			}
			else{
					index = (index+i*i) % hash->capacity;
					i++;
			}
		}
		else{
			//若哈希表这个位置的数据刚刚被删除，则改变数据，改变状态，改变数据计数。
			hash->hash2[index].data = data;
			hash->hash2[index].size = 1;
			hash->hash2[index].status = 0;
			hash->size++;
			return;
		}
	}
}

//闭散列哈希删除。删除成功返回0，删除失败返回1。
int ClosedHashDel(Hash *hash, int data)
{
	int index = data % hash->capacity;
	int i = 1;
	while (i<hash->capacity){
		if (hash->hash2[index].data == data && hash->hash2[index].status == 0){
			hash->hash2[index].status = 1;
			hash->size--;
			return 0;
		}
		index = (index + i) % hash->capacity;
		i++;
	}
	return 1;
}

//开散列
/*
	开散列：发生哈希冲突时，将会在在原来已存在的数据后面以链表的形式添加新的数据内容
*/

//开散列的初始化
void HashBucketInit(HashBucket *hash)
{
	hash->capacity = 20;
	hash->root = (hashBdata **)malloc(sizeof(hashBdata *) * 20);
	for (int i = 0; i < hash->capacity; i++){
		hash->root[i] = NULL;
	}
}

//开散列的销毁
void HashBucketErase(HashBucket *hash)
{
	for (int i = 0; i < hash->capacity; i++){
		hashBdata *cur = hash->root[i];
		if (cur == NULL){
			continue;
		}
		hashBdata *wfree = cur->next;
		while (cur != NULL){
			free(cur);
			cur = wfree;
			if (cur == NULL){
				break;
			}
			wfree = cur->next;
		}
	}
}

//开散列的查找。找到返回地址，未能找到返回NULL。
hashBdata *HashBucketFind(HashBucket *hash, datatype data)
{
	int index = data % hash->capacity;
	if (hash->root[index] == NULL){
		//如果哈希表这个位置还未插入过数据，那么查找不到
		return NULL;
	}
	else{
		//如果哈希表这个位置插入过数据，那么顺着这个链表寻找。
		hashBdata *cur = hash->root[index];
		while (cur->next != NULL){
			if (cur->data == data){
				return cur;
			}
			cur = cur->next;
		}
		if (cur->data == data){
			return cur;
		}
	}
	return NULL;
}

//开散列的插入
void HashBucketInsert(HashBucket *hash, datatype data)
{
	int index = data % hash->capacity;
	hashBdata *address = HashBucketFind(hash, data);
	if (NULL == address){
		//如果哈希表这个位置没有插入过要插入的数据
		//那么我们就要新创建一个要插入数据的结构体，将这个结构体头插进链表。
		hashBdata *newhb = (hashBdata *)malloc(sizeof(hashBdata));
		newhb->data = data;
		newhb->size = 1;
		hashBdata *old = hash->root[index];
		hash->root[index] = newhb;
		newhb->next = old;
	}
	else{
		//如果哈希表已经插入过我们要插入的数据，那么只需要将其size+1就可以了
		address->size++;
	}
}

//开散列的删除
void HashBucketDel(HashBucket *hash, datatype data)
{
	int index = data % hash->capacity;
	if (hash->root[index] == NULL){
		//如果哈希表的这个位置还未插入过数据，那么无法删除
		printf("哈希表中没有这个数据，无法删除\n");
		exit(EXIT_SUCCESS);
	}
	hashBdata *address = HashBucketFind(hash, data);
	if (NULL == address){
		//如果哈希表这个位置没有插入过要插入的数据,那么无法删除
		printf("哈希表中没有这个数据，无法删除\n");
		return;
	}
	else{
		//如果哈希表中找到了这个数据
		if (address->size == 1){
			hashBdata *lastofdel = hash->root[index];
			hashBdata *del = address;
			hashBdata *next = address->next;
			if (lastofdel == del){
				free(del);
				hash->root[index] = next;
			}
			else{
				while (lastofdel->next != del){
					lastofdel = lastofdel->next;
				}
				free(del);
				lastofdel->next = next;
			}
		}
		else{
			address->size--;
		}
	}
}