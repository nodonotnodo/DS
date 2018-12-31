#include "Sort.h"

//��������
void InsertSort(datatype *data, int size)
{
	int insert = 1;
	assert(data != NULL);
	//������������ֻ��һ�����ݣ���ô�Ѿ����򣬲����ٽ�������
	if (size == 1){
		return;
	}
	for (; insert < size; insert++){//insert-size-1�����ݶ�������ģ���Ҫ����������
		//�ҵ�data[insert]Ӧ�ò��뵽��������λ��
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
		if (tmp >= data[left]){//�ж�data��Ҫ����λ�����ݵĴ�С��ϵ��Ϊ��֤�ȶ��ԣ�data���ڵ���ʱ������λ�ú��档
			for (int i = insert; i > left+1; i--){
				data[i] = data[i - 1];
			}
			data[left + 1] = tmp;
		}
		else{//dataС��ʱ������λ��ǰ��
			for (int i = insert; i > left; i--){
				data[i] = data[i - 1];
			}
			data[left] = tmp;
		}
	}
}

//ϣ������
/*
ϣ��������ʵ���ǲ��������������
���Ƿ��֣���������ĺ�ʱ�������ݵ�����̶��ǳɷ��ȵġ�
�������ǿ����ڲ���֮ǰ�����ݽ��д���ʹ������̶����ӣ������ϣ������
	������š�
*/
void ShellSort(datatype *data, int size)
{
	assert(data != NULL);
	for (int i = 0; i < 3; i++){
		//������������ֻ��һ�����ݣ���ô�Ѿ����򣬲����ٽ�������
		for (int insert = i+3; insert < size; insert+=3){//insert-size-1�����ݶ�������ģ���Ҫ����������
			//�ҵ�data[insert]Ӧ�ò��뵽��������λ��
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
			if (tmp >= data[left]){//�ж�data��Ҫ����λ�����ݵĴ�С��ϵ��Ϊ��֤�ȶ��ԣ�data���ڵ���ʱ������λ�ú��档
				for (int i = insert; i > left + 3; i-=3){
					data[i] = data[i - 3];
				}
				data[left + 3] = tmp;
			}
			else{//dataС��ʱ������λ��ǰ��
				for (int i = insert; i > left; i-=3){
					data[i] = data[i - -3];
				}
				data[left] = tmp;
			}
		}
	}
	InsertSort(data, size);
}

//ѡ������
/*
ѡ������������������ҵ�������С�����ݣ��������Ӧ�÷ŵ�λ�á�
�������Ͻ��У�ֱ��������������
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

//������
/*
��������ǽ������ʼ��Ϊһ���ѣ�Ȼ���öѶ�Ԫ�������һ��Ԫ�ؽ�����
���Ͻ������ϲ�����ֱ���߼�����Ϊ�ա�
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
//������һ�����
	int start = size / 2 - 1;
	for (; start >= 0; start--){
		AdjustDown(data, size, start);
	}
	datatype tmp = data[0];
	data[0] = data[size - 1];
	data[size - 1] = tmp;
	HeapSort(data, size - 1);
}

//��������
/*
���������������ľ���ð������
ÿһ�˽�һ�����ݷŵ���ȷ��λ�ã�ֱ��������
*/
void BubbleSort(datatype *data, int size)
{
	for (int i = 0; i < size - 1; i++){//����
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

//����
/*
���ž�����һ���������ҵ�һ����׼ֵ��Ȼ�����ݷ�Ϊ�����֣�
1.С�ڻ�׼ֵ����2.��׼ֵ��3.���ڻ�׼ֵ��
��1����3���ڽ���ͬ���Ĳ�����ֱ��1����3��ֻʣ��һ�����ݻ�û�����ݣ���ʱ������ɡ�
*/
//�ڿӷ�
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
	RealQuickSort(data, left, L - 1);//���С�ڻ�׼ֵ������
	RealQuickSort(data, L + 1, right);//�ұߴ��ڻ�׼ֵ������
}

void QuickSort(datatype *data, int size)
{
	RealQuickSort(data, 0, size-1);
}

//�鲢����
/*
�鲢������ǽ�һ�����ݷ�Ϊ����С���ݣ�ʹ������С����������ٽ�������ϲ���
�����˼����С�����в��Ϲ᳹��ȥ��ֱ��С���������ݸ���ֻʣһ����Ϊ��ʱ����ʼ���ء�
*/

void RealMergeSort(datatype *data, int start, int end)
{
	if (start >= end){//С���������ݸ���ֻʣһ����Ϊ��
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