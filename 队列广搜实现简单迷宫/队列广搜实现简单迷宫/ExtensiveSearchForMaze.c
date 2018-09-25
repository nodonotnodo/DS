#include "ExtensiveSearchForMaze.h"

//队列的初始化
void QueueInit(queue *queue)
{
	assert(queue != NULL);
	queue->front = 0;
	queue->rear = 0;
	queue->move[queue->rear].numofway = 0;
}

//队列的插入（队列插入只有尾插）
void QueuePush(queue *queue, datatype x, datatype y, datatype num)
{
	queue->move[queue->rear].x = x;
	queue->move[queue->rear].y = y;
	queue->move[queue->rear].numofway = num;
	queue->rear++;
}

//队列的删除（岁了删除只有头删）
void QueuePop(queue *queue)
{
	assert(queue != NULL);
	if (queue->front >= queue->rear){
		printf("队列为空，无法删除\n");
		return;
	}
	queue->front++;
}

//广搜实现简单迷宫的流程实现
void ExtensiveSearchForMaze(queue *queue, datatype maze[][COL], Way start, Way finish)
{
	//先将start插入队列
/*
	开始循环流程：
			1.首先拿到队列列顶部的数据，
			2.将队列顶部对应的maze元素改为2，标志这里被走过
			3.在这里对队列顶部的数据进行相对的上、下、左、右元素逐个入队列，判断是否为出口。
			4.将队列出队列一次。
*/
	//先将start插入队列
	QueuePush(queue, start.x, start.y, start.numofway);

	//打印迷宫
	MazePrint(maze);

	//开始循环流程

	while (!(queue->front >= queue->rear)){

		//1.首先拿到队列顶部数据
		Way cur = queue->move[queue->front];

		//2.将队列顶部对应的maze元素改为2，标志这里被走过
		maze[cur.x][cur.y] = 2;

		//在这里将numforway+1，表示走的步数多了一步
		datatype data = ++cur.numofway;

		//3.在这里对队列顶部的数据进行相对的上、下、左、右元素逐个入队列，判断是否为出口。
		//上
		if (0 == maze[cur.x - 1][cur.y]){
			QueuePush(queue, cur.x - 1, cur.y, data);
			//打印迷宫
			MazePrint(maze);
			if (finish.x == cur.x - 1 && finish.y == cur.y){
				printf("找到出口，一共走了%d步\n", cur.numofway);
				exit(EXIT_FAILURE);
			}
		}

		//下
		if (0 == maze[cur.x + 1][cur.y]){
			QueuePush(queue, cur.x + 1, cur.y, data);
			//打印迷宫
			MazePrint(maze);
			if (finish.x == cur.x + 1 && finish.y == cur.y){
				printf("找到出口，一共走了%d步\n", cur.numofway);
				exit(EXIT_FAILURE);
			}
		}

		//左
		if (0 == maze[cur.x][cur.y - 1]){
			QueuePush(queue, cur.x, cur.y - 1, data);
			//打印迷宫
			MazePrint(maze);
			if (finish.x == cur.x && finish.y == cur.y - 1){
				printf("找到出口，一共走了%d步\n", cur.numofway);
				exit(EXIT_FAILURE);
			}
		}

		//右
		if (0 == maze[cur.x][cur.y + 1]){
			QueuePush(queue, cur.x, cur.y + 1, data);
			//打印迷宫
			MazePrint(maze);
			if (finish.x == cur.x && finish.y == cur.y + 1){
				printf("找到出口，一共走了%d步\n", cur.numofway);
				exit(EXIT_FAILURE);
			}
		}

		//4.将队列出队列一次。
		QueuePop(queue);
	}
}

//打印迷宫
void MazePrint(datatype maze[][COL])
{
	Sleep(100);
	system("cls");
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if (1 == maze[i][j])
			{
				printf("▉");
			}
			else if (0 == maze[i][j])
			{
				printf("%2d", maze[i][j]);
			}
			else
			{
				printf("◆", maze[i][j]);
			}
		}
		printf("\n");
	}
}