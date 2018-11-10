#include "SearchHash.h"

//��ϰ1
//��������һ����ϰ1���ж�һ���ַ���(ֻ��Сд��ĸ)�е�һ��ֻ����һ�ε��ַ���
//�ҵ��򷵻�����ַ���ַ�����򷵻�NULL
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

//��ϰ2���ж�һ���޷���int�������е�һ��ֻ����һ�ε����֡�
//�ҵ��򷵻�������ֵĵ�ַ�����򷵻�NULL

/*
���������޷�����������ϰ1�����ķ���ֱ�Ӹ�ʵ��ȷ��һ�����ꡣ
���Ǽ���hash2���鳤��Ϊm����ô���ǿ��Զ���һ�����ֵ��±�Ϊn%m��
���������Ļ������һ�����⣬�Ǿ���m��2m���±�һ�¡�����������ǹ�ϣ��ͻ��
���ǽ���İ취��Ϊ��ɢ�кͿ�ɢ�С�
*/

//��ɢ��
/*
��ɢ���ֽп��ŵ�ַ������������ϣ��ͻʱ�������ϣ��δ��װ������ô��ϣ��һ�����п�λ��
��ô�ͽ�key���ڹ�ϣ���е���һ����λ��
*/

//��ɢ�г�ʼ����ϣ��
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

//��ɢ�����ٹ�ϣ��
void ClosedHashErase(Hash *hash)
{
	free(hash->hash2);
	hash->capacity = 0;
	hash->size = 0;
	hash->hash2 = NULL;
}

//��ɢ�й�ϣ����ҡ��ҵ�����0��δ�ҵ�����1��
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

//��ɢ�й�ϣ������
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

//��ɢ�й�ϣ�����
void ClosedHashInsert(Hash *hash, int data)
{
	int index = data % hash->capacity;//������ݵ��±ꡣ
	int i = 1;
	while (1){
		if (hash->size * 10 / hash->capacity > 7){
			//�˴�Ӧ�����ݡ�
			/*printf("��ϣ�����˻���������\n");
			exit(EXIT_SUCCESS);*/
			ClosedHashInaertCapacity(hash);
		}
		if (hash->hash2[index].status == -1){
			//����ϣ�����λ��Ϊ�գ���ֱ�ӽ��������ݣ��ı�״̬���ı����ݼ�����
			hash->hash2[index].data = data;
			hash->hash2[index].size = 1;
			hash->hash2[index].status = 0;
			hash->size++;
			return;
		}
		else if (hash->hash2[index].status == 0){
			//����ϣ�����λ���Ѿ��������ݣ����ж��Ѵ������Ƿ���Ҫ���������ͬ
			//		��ͬ��size��1
			//		��ͬ���������Ѱ�ң�ֱ���ҵ�����λ��
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
			//����ϣ�����λ�õ����ݸոձ�ɾ������ı����ݣ��ı�״̬���ı����ݼ�����
			hash->hash2[index].data = data;
			hash->hash2[index].size = 1;
			hash->hash2[index].status = 0;
			hash->size++;
			return;
		}
	}
}

//��ɢ�й�ϣɾ����ɾ���ɹ�����0��ɾ��ʧ�ܷ���1��
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

//��ɢ��
/*
	��ɢ�У�������ϣ��ͻʱ����������ԭ���Ѵ��ڵ����ݺ������������ʽ����µ���������
*/

//��ɢ�еĳ�ʼ��
void HashBucketInit(HashBucket *hash)
{
	hash->capacity = 20;
	hash->root = (hashBdata **)malloc(sizeof(hashBdata *) * 20);
	for (int i = 0; i < hash->capacity; i++){
		hash->root[i] = NULL;
	}
}

//��ɢ�е�����
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

//��ɢ�еĲ��ҡ��ҵ����ص�ַ��δ���ҵ�����NULL��
hashBdata *HashBucketFind(HashBucket *hash, datatype data)
{
	int index = data % hash->capacity;
	if (hash->root[index] == NULL){
		//�����ϣ�����λ�û�δ��������ݣ���ô���Ҳ���
		return NULL;
	}
	else{
		//�����ϣ�����λ�ò�������ݣ���ô˳���������Ѱ�ҡ�
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

//��ɢ�еĲ���
void HashBucketInsert(HashBucket *hash, datatype data)
{
	int index = data % hash->capacity;
	hashBdata *address = HashBucketFind(hash, data);
	if (NULL == address){
		//�����ϣ�����λ��û�в����Ҫ���������
		//��ô���Ǿ�Ҫ�´���һ��Ҫ�������ݵĽṹ�壬������ṹ��ͷ�������
		hashBdata *newhb = (hashBdata *)malloc(sizeof(hashBdata));
		newhb->data = data;
		newhb->size = 1;
		hashBdata *old = hash->root[index];
		hash->root[index] = newhb;
		newhb->next = old;
	}
	else{
		//�����ϣ���Ѿ����������Ҫ��������ݣ���ôֻ��Ҫ����size+1�Ϳ�����
		address->size++;
	}
}

//��ɢ�е�ɾ��
void HashBucketDel(HashBucket *hash, datatype data)
{
	int index = data % hash->capacity;
	if (hash->root[index] == NULL){
		//�����ϣ������λ�û�δ��������ݣ���ô�޷�ɾ��
		printf("��ϣ����û��������ݣ��޷�ɾ��\n");
		exit(EXIT_SUCCESS);
	}
	hashBdata *address = HashBucketFind(hash, data);
	if (NULL == address){
		//�����ϣ�����λ��û�в����Ҫ���������,��ô�޷�ɾ��
		printf("��ϣ����û��������ݣ��޷�ɾ��\n");
		return;
	}
	else{
		//�����ϣ�����ҵ����������
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