#include "ExtensiveSearchForMaze.h"

//���еĳ�ʼ��
void QueueInit(queue *queue)
{
	assert(queue != NULL);
	queue->front = 0;
	queue->rear = 0;
	queue->move[queue->rear].numofway = 0;
}

//���еĲ��루���в���ֻ��β�壩
void QueuePush(queue *queue, datatype x, datatype y, datatype num)
{
	queue->move[queue->rear].x = x;
	queue->move[queue->rear].y = y;
	queue->move[queue->rear].numofway = num;
	queue->rear++;
}

//���е�ɾ��������ɾ��ֻ��ͷɾ��
void QueuePop(queue *queue)
{
	assert(queue != NULL);
	if (queue->front >= queue->rear){
		printf("����Ϊ�գ��޷�ɾ��\n");
		return;
	}
	queue->front++;
}

//����ʵ�ּ��Թ�������ʵ��
void ExtensiveSearchForMaze(queue *queue, datatype maze[][COL], Way start, Way finish)
{
	//�Ƚ�start�������
/*
	��ʼѭ�����̣�
			1.�����õ������ж��������ݣ�
			2.�����ж�����Ӧ��mazeԪ�ظ�Ϊ2����־���ﱻ�߹�
			3.������Զ��ж��������ݽ�����Ե��ϡ��¡�����Ԫ���������У��ж��Ƿ�Ϊ���ڡ�
			4.�����г�����һ�Ρ�
*/
	//�Ƚ�start�������
	QueuePush(queue, start.x, start.y, start.numofway);

	//��ӡ�Թ�
	MazePrint(maze);

	//��ʼѭ������

	while (!(queue->front >= queue->rear)){

		//1.�����õ����ж�������
		Way cur = queue->move[queue->front];

		//2.�����ж�����Ӧ��mazeԪ�ظ�Ϊ2����־���ﱻ�߹�
		maze[cur.x][cur.y] = 2;

		//�����ｫnumforway+1����ʾ�ߵĲ�������һ��
		datatype data = ++cur.numofway;

		//3.������Զ��ж��������ݽ�����Ե��ϡ��¡�����Ԫ���������У��ж��Ƿ�Ϊ���ڡ�
		//��
		if (0 == maze[cur.x - 1][cur.y]){
			QueuePush(queue, cur.x - 1, cur.y, data);
			//��ӡ�Թ�
			MazePrint(maze);
			if (finish.x == cur.x - 1 && finish.y == cur.y){
				printf("�ҵ����ڣ�һ������%d��\n", cur.numofway);
				exit(EXIT_FAILURE);
			}
		}

		//��
		if (0 == maze[cur.x + 1][cur.y]){
			QueuePush(queue, cur.x + 1, cur.y, data);
			//��ӡ�Թ�
			MazePrint(maze);
			if (finish.x == cur.x + 1 && finish.y == cur.y){
				printf("�ҵ����ڣ�һ������%d��\n", cur.numofway);
				exit(EXIT_FAILURE);
			}
		}

		//��
		if (0 == maze[cur.x][cur.y - 1]){
			QueuePush(queue, cur.x, cur.y - 1, data);
			//��ӡ�Թ�
			MazePrint(maze);
			if (finish.x == cur.x && finish.y == cur.y - 1){
				printf("�ҵ����ڣ�һ������%d��\n", cur.numofway);
				exit(EXIT_FAILURE);
			}
		}

		//��
		if (0 == maze[cur.x][cur.y + 1]){
			QueuePush(queue, cur.x, cur.y + 1, data);
			//��ӡ�Թ�
			MazePrint(maze);
			if (finish.x == cur.x && finish.y == cur.y + 1){
				printf("�ҵ����ڣ�һ������%d��\n", cur.numofway);
				exit(EXIT_FAILURE);
			}
		}

		//4.�����г�����һ�Ρ�
		QueuePop(queue);
	}
}

//��ӡ�Թ�
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
				printf("��");
			}
			else if (0 == maze[i][j])
			{
				printf("%2d", maze[i][j]);
			}
			else
			{
				printf("��", maze[i][j]);
			}
		}
		printf("\n");
	}
}