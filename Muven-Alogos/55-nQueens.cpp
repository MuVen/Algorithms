// 55-nQueens.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define N 4
#define min(a,b) a > b ? b : a

int board[N][N] = { 
	    {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0},
        {0, 0, 0, 0}
    };


/*int board[N][N] = { 
	    {0, 0, 0, 0, 0, 0, 0, 0},
        {0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0, 0, 0, 0}
    };*/


void printBoard(){
	for(int i = 0; i < N; i++,printf("\n"))
		for(int j = 0; j < N; j++)
			printf("%d ",board[i][j]);
}

bool isQueenSafe(int row, int col){

	int i, j;

	for(i = 0; i < col; i++){
		if(board[row][i])
			return false;
	}

	for(i = row, j = col; i >= 0 && j >= 0; i--, j--){
		if(board[i][j])
			return false;
	}

	for(i = row, j = col; i < N && j >= 0; i++, j--){
		if(board[i][j])
			return false;
	}

	return true;
}

bool nQueensBackTrack(int col){
	if(col >= N)
		return true;

	for(int i = 0; i < N; i++){
		if(isQueenSafe(i, col)){
			board[i][col] = 1;

			if(nQueensBackTrack(col + 1))
				return true;

			board[i][col] = 0;
		}
	}

    return false;
}

int _tmain(int argc, _TCHAR* argv[])
{
	if(nQueensBackTrack(0))
		printBoard();
	else
		printf("Solution Doesnt Exists\n");
	return 0;
}

