#pragma once

#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <Windows.h>

#define ROW 10
#define COL 10

typedef struct data{
	int row;
	int col;
}data;

//typedef struct Players
//{
//	int row;
//	int col;
//	int size;
//	int way[ROW*COL][2];
//}Players;
//
//typedef struct IFPlayer
//{
//	int Psize;
//	Players Players;
//}IFPlayer;

//�Թ�Ѱ·����
void Maze(data *player, data finish, int maze[][COL]);

//��ӡ�Թ�
void MazePrint(int maze[][COL],data player);