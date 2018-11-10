#include "Sort.h"

//插入排序
void InsertSort(datatype *data, int size)
{
	int insert = 1;
	assert(data != NULL);
	//如果这个数组中只有一个数据，那么已经有序，不用再进行排序。
	if (size == 1){
		return;
	}
	for (; insert < size; insert++){//insert-size-1的数据都是无序的，需要插入有序区
		//找到data[insert]应该插入到有序区的位置
		int left = 0;
		int right = insert-1;
		while (left < right){
			int mid = left + (right - left) / 2;
			if (data[mid] <= data[insert]){
				left = mid + 1;
			}
			else{
				right = mid - 1;
			}
		}
		
		int tmp = data[insert];
		if (tmp >= data[left]){//判断data与要插入位置数据的大小关系，为保证稳定性，data大于等于时插入在位置后面。
			for (int i = insert; i > left+1; i--){
				data[i] = data[i - 1];
			}
			data[left + 1] = tmp;
		}
		else{//data小于时插入在位置前面
			for (int i = insert; i > left; i--){
				data[i] = data[i - 1];
			}
			data[left] = tmp;
		}
	}
}

//希尔排序
/*
希尔排序其实就是插入排序的升级。
我们发现，插入排序的耗时与其数据的有序程度是成反比的。
所以我们可以在插排之前对数据进行处理，使其有序程度增加，这就是希尔排序。
	分组插排。
*/
void ShellSort(datatype *data, int size)
{
	assert(data != NULL);
	for (int i = 0; i < 3; i++){
		//如果这个数组中只有一个数据，那么已经有序，不用再进行排序。
		for (int insert = i+3; insert < size; insert+=3){//insert-size-1的数据都是无序的，需要插入有序区
			//找到data[insert]应该插入到有序区的位置
			int left = i;
			int right = insert - 3;
			while (left < right){
				int mid = (left/3 + (right/3 - left/3) / 2)*3+i;
				if (data[mid] <= data[insert]){
					left = mid + 3;
				}
				else{
					right = mid - 3;
				}
			}

			int tmp = data[insert];
			if (tmp >= data[left]){//判断data与要插入位置数据的大小关系，为保证稳定性，data大于等于时插入在位置后面。
				for (int i = insert; i > left + 3; i-=3){
					data[i] = data[i - 3];
				}
				data[left + 3] = tmp;
			}
			else{//data小于时插入在位置前面
				for (int i = insert; i > left; i-=3){
					data[i] = data[i - -3];
				}
				data[left] = tmp;
			}
		}
	}
	InsertSort(data, size);
}