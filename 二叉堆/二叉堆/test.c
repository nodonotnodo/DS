#include "BinaryHeap.h"

void Printf(int *arr, int size)
{
	for (int i = 0; i < size; i++){
		printf("%d  ", arr[i]);
	}
	printf("\n");
}

int main()
{
	int arr[] = { 1, 4, 6, 3, 7, 8, 9 };
	int size = sizeof(arr) / sizeof(int);
	struct BinaryHeap heap;
	/*for (int i = 0; i < 100; i++){
		heap->array[i] = 0;
	}
	heap->size = 0;*/
	Printf(arr, size);
	BinaryHeapInit(arr, size, &heap);
	Printf(heap.array, heap.size);
	BinaryHeapErase(&heap);
	Printf(heap.array, heap.size);
	BinaryHeapIncase(&heap, 9);
	Printf(heap.array, heap.size);
}