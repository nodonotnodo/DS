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
				int mid = left + (right/3 - left/3) / 2 * 3;
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

//选择排序
/*
选择排序就是在数据中找到最大或最小的数据，将其放在应该放的位置。
这样不断进行，直到整个数组有序。
*/
void SelectSort(datatype *data, int size)
{
	int left = 0;
	int right = size - 1;
	while (left < right){
		int max = left;
		int min = left;
		for (int i = left; i <= right; i++){
			if (data[max] < data[i]){
				max = i;
			}
			if (data[min] > data[i]){
				min = i;
			}
		}
		datatype tmp = data[right];
		data[right] = data[max];
		data[max] = tmp;
		if (min == right){
			min = max;
		}
		tmp = data[left];
		data[left] = data[min];
		data[min] = tmp;
		left++;
		right--;
	}
}

//堆排序
/*
堆排序就是将数组初始化为一个堆，然后用堆顶元素与最后一个元素交换。
不断进行以上操作，直到逻辑数组为空。
*/

int Max(int *data, int childleft, int childright)
{
	return data[childleft] >= data[childright] ? childleft : childright;
}

void AdjustDown(datatype *data, int size, int par)
{
	if ((par * 2 + 1) < size){
		int childleft = par * 2 + 1;
		int childright = par * 2 + 2;
		int maxchild;
		if (childright >= size){
			maxchild = childleft;
		}
		else{
			maxchild = Max(data, childleft, childright);
		}
		if (data[par] < data[maxchild]){
			int tmp = data[par];
			data[par] = data[maxchild];
			data[maxchild] = tmp;
		}
		AdjustDown(data, size, par * 2 + 1);
		AdjustDown(data, size, par * 2 + 2);
	}
	return;
}

void HeapSort(datatype *data, int size)
{
	if (1 == size){
		return;
	}
//创建了一个大堆
	int start = size / 2 - 1;
	for (; start >= 0; start--){
		AdjustDown(data, size, start);
	}
	datatype tmp = data[0];
	data[0] = data[size - 1];
	data[size - 1] = tmp;
	HeapSort(data, size - 1);
}

//交换排序
/*
交换排序最著名的就是冒泡排序。
每一趟将一个数据放到正确的位置，直到结束。
*/
void BubbleSort(datatype *data, int size)
{
	for (int i = 0; i < size - 1; i++){//趟数
		int max = 0;
		int flag = 0;
		for (int j = 0; j < size - i - 1; j++){
			if (data[max] <= data[j]){
				max = j;
				flag = 1;
			}
		}
		if (0 == flag){
			return;
		}
		datatype tmp = data[max];
		data[max] = data[size - i - 2];
		data[size - i - 2] = tmp;
	}
}

//快排
/*
快排就是在一组数据中找到一个基准值，然后将数据分为三部分：
1.小于基准值区，2.基准值，3.大于基准值区
将1区与3区在进行同样的操作，直到1区与3区只剩下一个数据或没有数据，此时排序完成。
*/
//挖坑法
void RealQuickSort(datatype *data, int left, int right)
{
	if (left >= right){
		return;
	}
	int div = left + (right - left) / 2;
	datatype tmp = data[div];
	data[div] = data[right];
	int L = left, R = right;
	while (L < R){
		while ((L < R) && (data[L] <= tmp)){
			L++;
		}
		data[R] = data[L];
		while ((L < R) && (data[R] > tmp)){
			R--;
		}
		data[L] = data[R];
	}
	data[L] = tmp;
	RealQuickSort(data, left, L - 1);//左边小于基准值的区间
	RealQuickSort(data, L + 1, right);//右边大于基准值的区间
}

void QuickSort(datatype *data, int size)
{
	RealQuickSort(data, 0, size-1);
}

//归并排序
/*
归并排序就是将一组数据分为两组小数据，使这两组小数据有序后再进行有序合并。
将这个思想在小数据中不断贯彻下去，直到小数据在数据个数只剩一个或为空时，开始返回。
*/

void RealMergeSort(datatype *data, int start, int end)
{
	if (start >= end){//小数据在数据个数只剩一个或为空
		return;
	}
	int mid = start + (end - start) / 2;
	RealMergeSort(data, start, mid);
	RealMergeSort(data, mid+1, end);
	datatype *newdata = (datatype *)malloc(sizeof(datatype)*(end - start + 1));
	int leftdata = start, leftsize = mid - start + 1;
	int rightdata = mid + 1, rightsize = end - mid;
	int i = 0, j = 0, k = 0;
	while (j < leftsize&&k < rightsize){
		if (data[leftdata + j] <= data[rightdata + k]){
			newdata[i] = data[leftdata + j];
			i++;
			j++;
		}
		else{
			newdata[i] = data[rightdata + k];
			i++;
			k++;
		}
	}
	if (j == leftsize){
		for (; k < rightsize; k++){
			newdata[i] = data[rightdata + k];
			i++;
		}
	}
	else if(k == rightsize){
		for (; j < leftsize; j++){
			newdata[i] = data[leftdata + j];
			i++;
		}
	}
	for (i = 0; i < end - start + 1; i++){
		data[i+start] = newdata[i];
	}
	free(newdata);
}

void MergeSort(datatype *data, int size)
{
	RealMergeSort(data, 0, size-1);//[start,end]
}