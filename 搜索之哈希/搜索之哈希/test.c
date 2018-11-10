#include "SearchHash.h"

void Printf1(char *address)
{
	if (address == NULL){
		printf("这个字符串中没有只出现一次的字符。\n");
	}
	else{
		printf("这个字符串第一个只出现一次的字符:0x%p-->%-2d\n",address,*address);
	}
}

void Printf2(hashBdata *address)
{
	if (address == NULL){
		printf("这个字符串中没有出现这个数据。\n");
	}
	else{
		printf("这个字符串第一个只出现一次的字符:0x%p-->%-2d\n", address, address->data);
	}
}

int main()
{
	//练习1
	char str1[] = { 'a','v','e','c','e','c','a','e','a','v' };
	int size1 = sizeof(str1) / sizeof(char);
	char *result1 = Practice1(str1, size1);
	Printf1(result1);

	//练习2

	//闭散列
	Hash hash;
	ClosedHashInit(&hash);
	ClosedHashInsert(&hash, 23);
	ClosedHashInsert(&hash, 14);
	ClosedHashInsert(&hash, 46);
	ClosedHashInsert(&hash, 34);
	ClosedHashInsert(&hash, 98);
	ClosedHashInsert(&hash, 23);
	ClosedHashInsert(&hash, 5);
	ClosedHashInsert(&hash, 1);
	ClosedHashInsert(&hash, 90);
	ClosedHashInsert(&hash, 34);
	ClosedHashInsert(&hash, 23);
	ClosedHashInsert(&hash, 54);
	ClosedHashInsert(&hash, 98);
	ClosedHashInsert(&hash, 25);
	ClosedHashInsert(&hash, 97);
	ClosedHashInsert(&hash, 96);
	ClosedHashInsert(&hash, 21);
	ClosedHashInsert(&hash, 83);
	ClosedHashInsert(&hash, 84);
	ClosedHashInsert(&hash, 85);
	ClosedHashInsert(&hash, 86);
	ClosedHashInsert(&hash, 87);
	ClosedHashInsert(&hash, 88);
	int i = ClosedHashFind(&hash, 14);
	int j = ClosedHashFind(&hash, 20);
	i = ClosedHashDel(&hash, 14);
	j = ClosedHashDel(&hash, 20);
	ClosedHashErase(&hash);

	//开散列

	HashBucket hash2;
	HashBucketInit(&hash2);
	HashBucketInsert(&hash2, 9);
	HashBucketInsert(&hash2, 3);
	HashBucketInsert(&hash2, 8);
	HashBucketInsert(&hash2, 1);
	HashBucketInsert(&hash2, 9);
	HashBucketInsert(&hash2, 29);
	HashBucketInsert(&hash2, 49);
	HashBucketInsert(&hash2, 49);
	Printf2(HashBucketFind(&hash2, 0));
	Printf2(HashBucketFind(&hash2, 49));
	Printf2(HashBucketFind(&hash2, 9));
	HashBucketDel(&hash2, 9);
	HashBucketDel(&hash2, 49);
	HashBucketDel(&hash2, 29);
	HashBucketDel(&hash2, 29);
	HashBucketDel(&hash2, 49);
	HashBucketErase(&hash2);
}