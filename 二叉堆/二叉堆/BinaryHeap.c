#include "BinaryHeap.h"

int Max(int *data, int childleft, int childright)
{
	return data[childleft] >= data[childright] ? childleft : childright;
}

//���µ���
void AdjustDown(BinaryHeap *heap, int size, int par)
{
	if((par*2+1) < size){
		int childleft = par * 2 + 1;
		int childright = par * 2 + 2;
		int maxchild;
		if (childright >= size){
			maxchild = childleft;
		}
		else{
			maxchild = Max(heap->array, childleft, childright);
		}
		if (heap->array[par] < heap->array[maxchild]){
			int tmp = heap->array[par];
			heap->array[par] = heap->array[maxchild];
			heap->array[maxchild] = tmp;
		}
		AdjustDown(heap, size, par * 2 + 1);
		AdjustDown(heap, size, par * 2 + 2);
	}
	return;
}

//��һ�������ʼ��Ϊһ������Ѵ��
void BinaryHeapInit(int *data, int size, BinaryHeap *heap)
{
	int i = 0;
	for (; i < size; i++){
		heap->array[i] = data[i];
	}
	heap->size = size;
	assert(data != NULL);
	int lastnoleaf = size/2 - 1;
	for (; lastnoleaf >= 0; lastnoleaf--){
		AdjustDown(heap, size, lastnoleaf);
	}
}

//����ѵ�ɾ��
void BinaryHeapErase(BinaryHeap *heap)
{
	heap->array[0] = heap->array[heap->size - 1];
	heap->size--;
	BinaryHeapInit(heap->array, heap->size, heap);
}

//����ѵĲ���
void BinaryHeapIncase(BinaryHeap *heap, int data)
{
	heap->array[heap->size] = data;
	heap->size++;
	BinaryHeapInit(heap->array, heap->size, heap);
}