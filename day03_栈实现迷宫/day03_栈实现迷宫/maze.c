////使用栈来实现一个迷宫。
////我们用一个二维数组来充当迷宫，这个数组中的元素为1则说明这个位置无法行走，为0则可行走
////我们设定一个起点和终点，设定一个寻路变量player起始位置则为起点。
////每次都会使player依照上，下，左，右的次序来查看周围的元素，碰到0则可以player变换为其坐标。
////但是迷宫（maze）中有许多岔路，当player走到死胡同中就要向回走，而我们的player此时就可以根
////栈中记录的移动记录来走回去。但是走回去之后再次判断周围元素就一定会在返回刚才的死胡同里，
////所以我们将player走过的路的元素都变为2。
//
//#include "maze.h"
//
////栈的初始化
//void stackInit(stack *stack)
//{
//	assert(stack != NULL);
//	stack->top = 0;
//}
//
////压栈
//void stackPush(stack *stack, datatype data1, datatype data2)
//{
//	assert(stack != NULL);
//	(stack->way)[stack->top].row = data1;
//	(stack->way)[stack->top].col = data2;
//	stack->top++;
//}
//
////出栈
//void stackPop(stack *stack)
//{
//	assert(stack != NULL);
//	stack->top--;
//}
//
////得到栈顶元素,若栈中为空，此处由于栈为空这中。
//data* GetTop(stack *stack)
//{
//	assert(stack != NULL);
//	data top;
//	top.col = stack->way[stack->top - 1].col;
//	top.row = stack->way[stack->top - 1].row;
//	return &top;
//}
//
////打印迷宫
//void mazePrint(datatype maze[][ROW],data player)
//{
//	int i = 0;
//	int j = 0;
//	for (i=0; i < ROW; i++)
//	{
//		for (j=0; j < COL; j++)
//		{
//			if ((i == player.row) && (j == player.col))
//			{
//				printf("⊙");
//			}
//			else if (1 == maze[i][j])
//			{
//				printf("▉");
//			}
//			else if (0 == maze[i][j])
//			{
//				printf("%2d", maze[i][j]);
//			}
//			else
//			{
//				printf("◆");
//			}
//		}
//		printf("\n");
//	}
//}
//
////迷宫函数
//void Maze(stack *stack, datatype maze[][ROW], data start, data finish)
//{
//	//首先，初始化player为起点
//	data player = start;
//	assert(stack != NULL);
//	//做一个循环，当player为终点时循环结束
//	while (!((player.row == finish.row) && (player.col == finish.col)))
//	{
//		//首先将当前player的位置信息压栈，并且将这个位置的数组元素变为2
//		stackPush(stack, player.row, player.col);
//		maze[player.row][player.col] = 2;
//		//找路子，找到能走的位置，若找不到能走的路，则进行栈回溯
//			//上
//		if ((player.row - 1 >= 0) && ((maze[player.row-1][player.col] == 0)))
//		{
//			player.row = player.row - 1;
//		}
//			//下
//		else if ((player.row + 1 < ROW) && ((maze[player.row+1][player.col] == 0)))
//		{
//			player.row = player.row + 1;
//		}
//			//左
//		else if ((player.col - 1 >= 0) && ((maze[player.row])[player.col-1] == 0))
//		{
//			player.col = player.col - 1;
//		}
//			//右
//		else if ((player.col + 1 < COL) && ((maze[player.row][player.col+1] == 0)))
//		{
//			player.col = player.col + 1;
//		}
//			//四周的路都不能走，则进行出栈回溯
//		else
//		{
//			stackPop(stack);
//			player.row = GetTop(stack)->row;
//			player.col = GetTop(stack)->col;
//			stackPop(stack);
//		}
//		//在player移动后，打印一次迷宫
//		Sleep(300);
//		system("cls");
//		mazePrint(maze,player);
//		printf("\n\n");
//	}
//}