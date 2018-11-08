//#include "maze.h"
//
//int main()
//{
//	stack stack;
//	data start = { 9, 1 };
//	data finish = { 6, 9 };
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
//	stackInit(&stack);
//	Maze(&stack, maze, start, finish);
//	return 0;
//}


#include "maze_A.h"

int main()
{
	data player;
	data start = { 9, 1 };
	data finish = { 6, 9 };
	int maze[ROW][COL] = {
		{ 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 0, 1, 1 },
		{ 1, 0, 0, 0, 0, 0, 0, 0, 0, 1 },
		{ 1, 0, 1, 1, 0, 1, 1, 1, 0, 1 },
		{ 1, 0, 0, 0, 0, 1, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 0, 0, 0, 1, 0, 1 },
		{ 1, 0, 1, 1, 1, 1, 0, 1, 0, 0 },
		{ 1, 0, 0, 0, 1, 1, 0, 1, 1, 1 },
		{ 1, 0, 1, 0, 1, 1, 0, 0, 1, 1 },
		{ 1, 0, 1, 1, 1, 1, 1, 1, 1, 1 },
	};
	player.col = start.col;
	player.row = start.row;
	Maze(&player, finish, maze);
	return 0;
}