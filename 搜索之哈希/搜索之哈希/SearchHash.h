#pragma once

/*
	��ϣ��
		ʵ��----����ϣ������--->�±�
		��ϣʵ���Ͼ��ǰ�һ��ʵ�ﾭ���ض��ĺ���ת��Ϊһ���±꣬����ض��������ǹ�ϣ������
*/

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

//��������һ����ϰ1���ж�һ���ַ����е�һ��ֻ����һ�ε��ַ����ҵ��򷵻�����ַ���ַ�����򷵻�NULL
char *Practice1(char *str, int size);

//��ϰ2���ж�һ���޷���int�������е�һ��ֻ����һ�ε����֡�
//�ҵ��򷵻�������ֵĵ�ַ�����򷵻�NULL

/*
���������޷�����������ϰ1�����ķ���ֱ�Ӹ�ʵ��ȷ��һ�����ꡣ
���Ǽ���hash2���鳤��Ϊm����ô���ǿ��Զ���һ�����ֵ��±�Ϊn%m��
���������Ļ������һ�����⣬�Ǿ���m��2m���±�һ�¡�����������ǹ�ϣ��ͻ��
���ǽ���İ취��Ϊ��ɢ�кͿ�ɢ�С�
*/

typedef int datatype;

typedef struct hashdata{
	datatype data;//��ʾ���λ�����������
	int size;//��ʾ���λ���������ݳ��ֵĸ���
	int status;//��ʾ���λ������״̬��-1--�գ�0--�������ݣ�1--���ݱ�ɾ��
}hashdata;

typedef struct Hash{
	struct hashdata *hash2;
	int size;
	int capacity;
}Hash;

//��ɢ��

//��ɢ�г�ʼ����ϣ��
void ClosedHashInit(Hash *hash);

//��ɢ�����ٹ�ϣ��
void ClosedHashErase(Hash *hash);

//��ɢ�й�ϣ�����
void ClosedHashInsert(Hash *hash, int data);

//��ɢ�й�ϣ����ҡ��ҵ�����1��δ�ҵ�����0��
int ClosedHashFind(Hash *hash, int data);

//��ɢ�й�ϣɾ����ɾ���ɹ�����0��ɾ��ʧ�ܷ���1��
int ClosedHashDel(Hash *hash, int data);

//��ɢ�й�ϣ������
void ClosedHashInaertCapacity(Hash *hash);

//��ɢ��

typedef struct hashBdata{
	datatype data;//��ŵ�����
	int size;//������ݳ��ֵĸ���
	struct hashBdata *next;
}hashBdata;

typedef struct HashBucket{
	struct hashBdata **root;
	int capacity;//��ϣ������
}HashBucket;

//��ɢ�еĳ�ʼ��
void HashBucketInit(HashBucket *hash);

//��ɢ�е�����
void HashBucketErase(HashBucket *hash);

//��ɢ�еĲ��ҡ��ҵ����ص�ַ��δ���ҵ�����NULL��
hashBdata *HashBucketFind(HashBucket *hash, datatype data);

//��ɢ�еĲ���
void HashBucketInsert(HashBucket *hash, datatype data);

//��ɢ�е�ɾ��
void HashBucketDel(HashBucket *hash, datatype data);