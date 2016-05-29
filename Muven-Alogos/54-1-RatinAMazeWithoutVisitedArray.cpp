// Rat in a Maze.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define N 4

int maze[N][N]  =  
{
	{1,1,1,1},
	{0,1,0,1},
	{0,1,0,1},
	{0,1,1,1}
};

/*
#define N 5

int maze[N][N]  =  
{
	{1,1,1,0,0},
	{1,0,1,0,0},
	{1,0,1,1,0},
	{1,0,0,1,1},
	{1,1,1,1,1}
};*/

int xM[] = {-1, 1, 0, 0};
int yM[] = {0,  0, 1, -1};

void printPath(){
	for(int i = 0; i < N; i++, printf("\n"))
		for(int j = 0; j < N; j++)
			printf("%d\t",maze[i][j]);
}

bool isValid(int x, int y){
	if(x < 0 || x > N-1 || y < 0 || y > N-1 || (maze[x][y] == 0) || (maze[x][y] == 5))
		return false;
	return true;
}

int pathNumber = 0;
void mazePath(int x, int y){
	if(!isValid(x, y))
		return;

	int temp = maze[x][y];
	maze[x][y] = 5;

	if(x == N-1 && y == N-1){
		printf("Path: %d\n",++pathNumber);
		printPath();
		printf("\n");
		maze[x][y] = temp;
		return;
	}

	int cx, cy;
	for(int i = 0; i < 4; i++){
		cx = x + xM[i];
		cy = y + yM[i];
		mazePath(cx, cy);
	}

	maze[x][y] = temp;
}

int _tmain(int argc, _TCHAR* argv[])
{
	mazePath(0, 0);
	return 0;
}

