// 7-RowColoumZeroMatrix.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>

void setRowZero(int a[][4], int r) {
    for(int j = 0; j < 4; j++)
		a[r][j] = 0;
}

void setColZero(int a[][4], int c) {
	for(int i = 0; i < 4; i++)
		a[i][c] = 0;
}

void setMatrixColAndRowZero(int a[4][4]){
    int row = 4;
	int col = 4;
 
	int* rowZero = (int*) malloc(sizeof(int)*row);
	int* colZero = (int*) malloc(sizeof(int)*col);

	for(int i = 0; i < row; i++){
		for(int j = 0; j < col; j++){
			if(a[i][j] == 0){
				rowZero[i] = 0;
				colZero[j] = 0;
			}
		}
	}

	for(int i = 0; i < row; i++) {
		if(!rowZero[i])
			setRowZero(a,i);
	}

	for(int j = 0; j < col; j++) {
		if(!colZero[j])
			setColZero(a,j);
	}

	for(int i = 0; i < 4; i++) {
		for(int j = 0; j < 4; j++) {
			printf("%d\t",a[i][j]);
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int matrix[4][4] = {{1,2,3,0},{5,6,7,8},{9,0,1,2},{3,4,5,6}};
	setMatrixColAndRowZero(matrix);
	getchar();
	return 0;
}

