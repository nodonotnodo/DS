////ʹ��ջ��ʵ��һ���Թ���
////������һ����ά�������䵱�Թ�����������е�Ԫ��Ϊ1��˵�����λ���޷����ߣ�Ϊ0�������
////�����趨һ�������յ㣬�趨һ��Ѱ·����player��ʼλ����Ϊ��㡣
////ÿ�ζ���ʹplayer�����ϣ��£����ҵĴ������鿴��Χ��Ԫ�أ�����0�����player�任Ϊ�����ꡣ
////�����Թ���maze����������·����player�ߵ�����ͬ�о�Ҫ����ߣ������ǵ�player��ʱ�Ϳ��Ը�
////ջ�м�¼���ƶ���¼���߻�ȥ�������߻�ȥ֮���ٴ��ж���ΧԪ�ؾ�һ�����ڷ��ظղŵ�����ͬ�
////�������ǽ�player�߹���·��Ԫ�ض���Ϊ2��
//
//#include "maze.h"
//
////ջ�ĳ�ʼ��
//void stackInit(stack *stack)
//{
//	assert(stack != NULL);
//	stack->top = 0;
//}
//
////ѹջ
//void stackPush(stack *stack, datatype data1, datatype data2)
//{
//	assert(stack != NULL);
//	(stack->way)[stack->top].row = data1;
//	(stack->way)[stack->top].col = data2;
//	stack->top++;
//}
//
////��ջ
//void stackPop(stack *stack)
//{
//	assert(stack != NULL);
//	stack->top--;
//}
//
////�õ�ջ��Ԫ��,��ջ��Ϊ�գ��˴�����ջΪ�����С�
//data* GetTop(stack *stack)
//{
//	assert(stack != NULL);
//	data top;
//	top.col = stack->way[stack->top - 1].col;
//	top.row = stack->way[stack->top - 1].row;
//	return &top;
//}
//
////��ӡ�Թ�
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
//				printf("��");
//			}
//			else if (1 == maze[i][j])
//			{
//				printf("��");
//			}
//			else if (0 == maze[i][j])
//			{
//				printf("%2d", maze[i][j]);
//			}
//			else
//			{
//				printf("��");
//			}
//		}
//		printf("\n");
//	}
//}
//
////�Թ�����
//void Maze(stack *stack, datatype maze[][ROW], data start, data finish)
//{
//	//���ȣ���ʼ��playerΪ���
//	data player = start;
//	assert(stack != NULL);
//	//��һ��ѭ������playerΪ�յ�ʱѭ������
//	while (!((player.row == finish.row) && (player.col == finish.col)))
//	{
//		//���Ƚ���ǰplayer��λ����Ϣѹջ�����ҽ����λ�õ�����Ԫ�ر�Ϊ2
//		stackPush(stack, player.row, player.col);
//		maze[player.row][player.col] = 2;
//		//��·�ӣ��ҵ����ߵ�λ�ã����Ҳ������ߵ�·�������ջ����
//			//��
//		if ((player.row - 1 >= 0) && ((maze[player.row-1][player.col] == 0)))
//		{
//			player.row = player.row - 1;
//		}
//			//��
//		else if ((player.row + 1 < ROW) && ((maze[player.row+1][player.col] == 0)))
//		{
//			player.row = player.row + 1;
//		}
//			//��
//		else if ((player.col - 1 >= 0) && ((maze[player.row])[player.col-1] == 0))
//		{
//			player.col = player.col - 1;
//		}
//			//��
//		else if ((player.col + 1 < COL) && ((maze[player.row][player.col+1] == 0)))
//		{
//			player.col = player.col + 1;
//		}
//			//���ܵ�·�������ߣ�����г�ջ����
//		else
//		{
//			stackPop(stack);
//			player.row = GetTop(stack)->row;
//			player.col = GetTop(stack)->col;
//			stackPop(stack);
//		}
//		//��player�ƶ��󣬴�ӡһ���Թ�
//		Sleep(300);
//		system("cls");
//		mazePrint(maze,player);
//		printf("\n\n");
//	}
//}