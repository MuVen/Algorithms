// 6- ImageRotation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

//Rotate 4 x 4 matrix by 90 degress.
void rotateImage(int a[][4], int n)
{
	for(int layer = 0; layer < n/2; layer++) {
		int first = layer;
		int last = n - 1 - layer;
		for( int i = first; i < last; i++){
			int offset = i - first;
			int top = a[first][i];
			a[first][i] = a[last-offset][first];
			a[last-offset][first] = a[last][last-offset];
			a[last][last-offset] = a[i][last];
			a[i][last] = top;
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int image[4][4]={{1,2,3,4}, {5,6,7,8}, {9,0,1,2}, {3,4,5,6}};
    rotateImage(image, 4);

	for(int i = 0 ; i < 4; i++){
		for(int j = 0; j < 4; j++){
			printf("%d\t",image[i][j]);
		}
		printf("\n");
	}

	return 0;
}

