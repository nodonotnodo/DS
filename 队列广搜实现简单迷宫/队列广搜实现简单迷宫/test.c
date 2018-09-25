#include "ExtensiveSearchForMaze.h"

void test(queue *queue, datatype maze[][COL], Way start, Way finish)
{
	ExtensiveSearchForMaze(queue, maze, start, finish);
}

int main()
{
	Way start; start.x = 9; start.y = 1; start.numofway = 0;
	Way finish; finish.x = 6; finish.y = 9;
	queue queue;
	QueueInit(&queue);
	datatype maze[ROW][COL] = {
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
	test(&queue, maze, start, finish);
	return 0;
}