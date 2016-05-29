// 58-Sudoku.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define N 9
#define FORI for(i = 0; i < N; i++)
#define FORJ for(j = 0; j < N; j++)
int i, j;

//int grid[N][N] = {    {3, 0, 6, 5, 0, 8, 4, 0, 0},
//                      {5, 2, 0, 0, 0, 0, 0, 0, 0},
//                      {0, 8, 7, 0, 0, 0, 0, 3, 1},
//                      {0, 0, 3, 0, 1, 0, 0, 8, 0},
//                      {9, 0, 0, 8, 6, 3, 0, 0, 5},
//                      {0, 5, 0, 0, 9, 0, 6, 0, 0},
//                      {1, 3, 0, 0, 0, 0, 2, 5, 0},
//                      {0, 0, 0, 0, 0, 0, 0, 7, 4},
//                      {0, 0, 5, 2, 0, 6, 3, 0, 0}};

int grid[N][N] = 
{{0, 6, 0, 1, 0, 4, 0, 5, 0},
{0, 0, 8, 3, 0, 5, 6, 0, 0},
{2, 0, 0, 0, 0, 0, 0, 0, 1},
{8, 0, 0, 4, 0, 7, 0, 0, 6},
{0, 0, 6, 0, 0, 0, 3, 0, 0},
{7, 0, 0, 9, 0, 1, 0, 0, 4},
{5, 0, 0, 0, 0, 0, 0, 0, 2},
{0, 0, 7, 2, 0, 6, 9, 0, 0},
{0, 4, 0, 5, 0, 8, 0, 7, 0}};

void printGrid()
{
    for (int row = 0; row < N; row++)
    {
       for (int col = 0; col < N; col++)
             printf("%2d", grid[row][col]);
        printf("\n");
    }
}

bool FindUnAssignedPosition(int& x, int& y){
	for(x = 0; x < 9; x++) {
		for(y = 0; y < 9; y++) {
			if(grid[x][y] == 0) {
				return true;
			}
		}
	}
	return false;
}

bool isNumPlacedInRow(int x, int num){
	for(i = 0; i < 9; i++){
		if(grid[x][i] == num)
			return true;
	}
	return false;
}

bool isNumPlacedInColumn(int y, int num){
	for(i = 0; i < 9; i++){
		if(grid[i][y] == num)
			return true;
	}
	return false;
}

bool isNumPlacedInSubGrid(int x, int y, int num){
	for(i = 0; i < 3; i++){
		for(j = 0; j < 3; j++){
			if(grid[i+x][j+y] == num)
				return true;
		}
	}
	return false;
}

bool isNumSafeAtXY(int x, int y, int num){
	return !isNumPlacedInRow(x, num) && 
		   !isNumPlacedInColumn(y, num) && 
		   !isNumPlacedInSubGrid(x - x%3, y - y%3, num);
}

bool solveSudoko(){
	int x, y;

	if(!FindUnAssignedPosition(x,y))
		return true;

	for(int num = 1; num <= 9; num++){
		if(isNumSafeAtXY(x, y, num)){

			grid[x][y] = num;

			if(solveSudoko())
				return true;

			grid[x][y] = 0;
		}
	}

	return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	solveSudoko() ? printGrid() : printf("Solution Doesnt Exists\n");
	return 0;
}

