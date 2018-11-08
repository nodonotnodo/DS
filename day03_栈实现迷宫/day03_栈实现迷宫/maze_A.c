#include "maze_A.h"

//迷宫寻路函数
void Maze(data *player, data finish, int maze[][COL])
{
	assert(player != NULL);
	maze[(*player).row][(*player).col] = 2;
	while (!(((*player).row == finish.row) && ((*player).col == finish.col)))
	{
		//上
		if (((*player).row - 1 >= 0) && (maze[(*player).row-1][(*player).col] == 0))
		{
			data player1;
			player1.row = (*player).row - 1;
			player1.col = (*player).col;
			MazePrint(maze, player1);
			Maze(&player1, finish, maze);
		}
		//下
		if (((*player).row+1 <= 9) &&(maze[(*player).row+1][(*player).col] == 0))
		{
			data player2;
			player2.row = (*player).row + 1;
			player2.col = (*player).col;
			MazePrint(maze, player2);
			Maze(&player2, finish, maze);
		}
		//左
		if (((*player).col - 1 >= 0) && (maze[(*player).row][(*player).col - 1])==0)
		{
			data player3;
			player3.row = (*player).row;
			player3.col = (*player).col - 1;
			MazePrint(maze, player3);
			Maze(&player3, finish, maze);
		}
		//右
		if (((*player).col + 1 <= 9) && (maze[(*player).row][(*player).col + 1]) == 0)
		{
			data player4;
			player4.row = (*player).row;
			player4.col = (*player).col + 1;
			MazePrint(maze, player4);
			Maze(&player4, finish, maze);
		}
		maze[(*player).row][(*player).col] = 2;
		return;
	}
	printf("找到出口\n");
	exit(EXIT_SUCCESS);
}

//打印迷宫
void MazePrint(int maze[][COL], data player)
{
	Sleep(100); 
	system("cls");
	int i = 0;
	int j = 0;
	for (i = 0; i < ROW; i++)
	{
		for (j = 0; j < COL; j++)
		{
			if ((i == player.row) && (j == player.col))
			{
				printf("⊙");
			}
			else if (1 == maze[i][j])
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