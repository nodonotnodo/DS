#pragma once

typedef int datatype;

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>


//插入排序：
/*
将数据分为二部分：有序部分，无序部分。每次在无序部分拿出一个数据，插入到有序部分，
使有序部分依然有序。
*/

//插入排序
void InsertSort(datatype *data, int size);

//希尔排序
/*
	希尔排序其实就是插入排序的升级。
	我们发现，插入排序的耗时与其数据的有序程度是成反比的。
	所以我们可以在插排之前对数据进行处理，使其有序程度增加，这就是希尔排序。
*/
//void ShellSort(datatype *data, int size);

//选择排序
/*
	选择排序就是在数据中找到最大或最小的数据，将其放在应该放的位置。
	这样不断进行，直到整个数组有序。
*/
void SelectSort(datatype *data, int size);

//堆排序
/*
	堆排序就是将数组初始化为一个堆，然后用堆顶元素与最后一个元素交换。
	不断进行以上操作，直到逻辑数组为空。
*/
void HeapSort(datatype *data, int size);

//交换排序
/*
	交换排序最著名的就是冒泡排序。
	每一趟将一个数据放到正确的位置，直到结束。
*/
void BubbleSort(datatype *data, int size);

//快排
/*
	快排就是在一组数据中找到一个基准值，然后将数据分为三部分：
			1.小于基准值区，2.基准值，3.大于基准值区
	将1区与3区在进行同样的操作，直到1区与3区只剩下一个数据或没有数据，此时排序完成。
*/
//挖坑法
void QuickSort(datatype *data, int size);

//归并排序
/*
	归并排序就是将一组数据分为两组小数据，使这两组小数据有序后再进行有序合并。
	将这个思想在小数据中不断贯彻下去，直到小数据在数据个数只剩一个或为空时，开始返回。
*/
void MergeSort(datatype *data, int size);