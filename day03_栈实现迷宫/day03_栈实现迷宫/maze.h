//#pragma once
////这个是深搜实现的迷宫。
////深搜就是一个搜索器一直搜索，遇到错误就进行回溯直到这个搜索器搜索到目标。
////与深搜对应的就是广搜，广搜每次遇到分支就会产生新的搜索器，直到有搜索器搜索到目标。
//
//#include <stdio.h>
//#include <stdlib.h>
//#include <assert.h>
//#include <Windows.h>
//
//#define ROW 10
//#define COL 10
//#define datatype int
//
//
//typedef struct data{
//	datatype row;
//	datatype col;
//}data;
//
//
//
//typedef struct stack{
//	int top;
//	data way[ROW*COL];
//}stack;
//
////栈的初始化
//void stackInit(stack *stack);
//
////压栈
//void stackPush(stack *stack, datatype data1, datatype data2);
//
////出栈
//void stackPop(stack *stack);
//
////得到栈顶元素,若栈中为空，返回0。
//data* GetTop(stack *stack);
//
////迷宫函数
//void Maze(stack *stack, datatype maze[][ROW], data start, data finish);
