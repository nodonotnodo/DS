#pragma once

/*
	哈希：
		实物----（哈希函数）--->下标
		哈希实际上就是把一个实物经过特定的函数转换为一个下标，这个特定函数就是哈希函数。
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//首先来做一个练习1：判断一组字符串中第一个只出现一次的字符。找到则返回这个字符地址，否则返回NULL
char *Practice1(char *str, int size);

//练习2：判断一组无符号int型数据中第一个只出现一次的数字。
//找到则返回这个数字的地址，否则返回NULL

/*
这样我们无法在利用像练习1那样的方法直接给实物确定一个坐标。
我们假设hash2数组长度为m，那么我们可以定义一个数字的下标为n%m。
但是这样的话会产生一个问题，那就是m和2m的下标一致。这种情况就是哈希冲突。
我们解决的办法分为闭散列和开散列。
*/

typedef int datatype;

typedef struct hashdata{
	datatype data;//表示这个位置所存的数据
	int size;//表示这个位置所存数据出现的个数
	int status;//表示这个位置所属状态，-1--空，0--存有数据，1--数据被删除
}hashdata;

typedef struct Hash{
	struct hashdata *hash2;
	int size;
	int capacity;
}Hash;

//闭散列

//闭散列初始化哈希表
void ClosedHashInit(Hash *hash);

//闭散列销毁哈希表
void ClosedHashErase(Hash *hash);

//闭散列哈希表插入
void ClosedHashInsert(Hash *hash, int data);

//闭散列哈希表查找。找到返回1，未找到返回0。
int ClosedHashFind(Hash *hash, int data);

//闭散列哈希删除。删除成功返回0，删除失败返回1。
int ClosedHashDel(Hash *hash, int data);

//闭散列哈希表扩容
void ClosedHashInaertCapacity(Hash *hash);

//开散列

typedef struct hashBdata{
	datatype data;//存放的数据
	int size;//这个数据出现的个数
	struct hashBdata *next;
}hashBdata;

typedef struct HashBucket{
	struct hashBdata **root;
	int capacity;//哈希表容量
}HashBucket;

//开散列的初始化
void HashBucketInit(HashBucket *hash);

//开散列的销毁
void HashBucketErase(HashBucket *hash);

//开散列的查找。找到返回地址，未能找到返回NULL。
hashBdata *HashBucketFind(HashBucket *hash, datatype data);

//开散列的插入
void HashBucketInsert(HashBucket *hash, datatype data);

//开散列的删除
void HashBucketDel(HashBucket *hash, datatype data);