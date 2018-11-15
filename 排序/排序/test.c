#include "Sort.h"

void Printf(datatype *data, int size)
{
	for (int i = 0; i < size; i++){
		printf("%-4d", data[i]);
	}
	printf("\n");
}

int main()
{
	datatype data[] = { 23, 54, 1, 24, 56, 76, 34, 23, 67, 34, 65 };
	int size = sizeof(data) / sizeof(datatype);
	Printf(data, size);
	/*InsertSort(data, size);
	Printf(data, size);*/
	//ShellSort(data, size);//Ï£¶ûÅÅÐòÓÐÎÊÌâ
	//Printf(data, size);
	/*SelectSort(data, size);
	Printf(data, size);*/
	/*QuickSort(data, size);
	Printf(data, size);*/
	/*HeapSort(data, size);
	Printf(data, size);*/
	/*BubbleSort(data, size);
	Printf(data, size);*/
	MergeSort(data, size);
	Printf(data, size);
}
