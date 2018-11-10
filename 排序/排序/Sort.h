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
void ShellSort(datatype *data, int size);

//选择排序
/*
	选择排序就是在数据中找到最大或最小的数据，将其放在应该放的位置。
	这样不断进行，知道整个数组有序。
*/