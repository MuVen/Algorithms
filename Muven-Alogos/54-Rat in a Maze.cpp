// Rat in a Maze.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define N 5

/*int maze[N][N]  =  
      { {1, 0, 0, 0},
        {1, 1, 0, 1},
        {0, 1, 0, 0},
        {1, 1, 1, 1}
      };*/

int maze[N][N]  =  
{
	{1,1,1,0,0},
	{0,0,1,1,0},
	{1,0,0,1,0},
	{0,1,0,1,1},
	{0,0,0,0,1}
};

int solution[N][N] = {0};

void printPath(){
	for(int i = 0; i < N; i++, printf("\n"))
		for(int j = 0; j < N; j++)
			printf("%d\t",solution[i][j]);
}

bool isValid(int cx, int cy){
	if(cx < 0 || cx > N-1 || cy < 0 || cy > N-1 || !maze[cx][cy]) 
		return false;
	return true;
}

bool mazePath(int x, int y){
	if(!isValid(x, y))
		return false;

	solution[x][y] = 1;

	if(x == N-1 && y == N-1)
		return true;

	int cx, cy;
	cx = x + 1; cy = y;
	if(mazePath(cx, cy))
		return true;

	cx = x; cy = y + 1;
	if(mazePath(cx, cy))
		return true;

	solution[x][y] = 0;
	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	bool foundPath = mazePath(0, 0);
	if(foundPath)
		printPath();
	else
		printf("Path not found\n");
	return 0;
}

