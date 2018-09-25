#pragma once

#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <Windows.h>

/*
	先来理一下思路：广搜实现一个简单迷宫，我们首先确定要使用队列来实现。
		Mode：我们首先考虑它的Mode，迷宫很简单，因为是一个小迷宫，我们可以用一个二位数组来定义
		迷宫；接下来，我们要考虑路线的问题，因为广搜是要多路同时进行，所以我们要将路线的数据一
		边向前行进一步，行进一步后停下并且将原来的路的数据删掉，将新的数据存下等下一轮的行进。
		而这个新的数据下一轮的行进顺序应该与这一轮顺序相同，所以这其实就是队列的先进先出，这不
		过在这里变为了先存先处理。所以我们要用一个队列来实现这个路径。
		
		View：根据自己喜好，不做考虑

		Controller：我们的流程控制是这样的：由于队列开始位置的路径数据都是先入的，所以我们每次
		都要将先处理队列头的路径数据，将它的所有可走路径均向前推进一步并且记录下来，不要忘记将
		上一步的在出队列。然后继续处理队列头部的数据。
*/

#define ROW (10)
#define COL (10)
typedef int datatype;

//	datatype maze[ROW][COL] = {
//		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
//		{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
//		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
//		{ 1, 0, 1, 1, 0, 1, 1, 1, 0, 1 },
//		{ 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
//		{ 1, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
//		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
//		{ 1, 0, 0, 0, 1, 1, 0, 1, 1, 1 },
//		{ 1, 0, 1, 0, 1, 1, 0, 0, 1, 1 },
//		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
//	};

//定义一个结构体，这个结构体包括路的信息和走了多少步
typedef struct Way{
	datatype x;
	datatype y;
	datatype numofway;
} Way;

//定义队列，队列中的信息应该为一个结构体数组，这个结构体包括路的信息和走了多少步
typedef struct queue{
	struct Way move[ROW*COL];
	//struct Way *move[ROW*COL];
	datatype front;
	datatype rear;
}queue;

//开始实现队列

//队列的初始化
void QueueInit(queue *queue);

//队列的插入（队列插入只有尾插）
void QueuePush(queue *queue, datatype x, datatype y, datatype num);

//队列的删除（岁了删除只有头删）
void QueuePop(queue *queue);

//广搜实现简单迷宫的流程实现
void ExtensiveSearchForMaze(queue *queue, datatype maze[][COL], Way start, Way finish);

//打印迷宫
void MazePrint(datatype maze[][COL]);