// kanpsack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAX 10000

int arr[MAX][MAX];

int maxWeight = 50;
int weights[] = {10, 20, 30};
int values[] = {60, 100, 120};


int max(int a, int b){ return a > b ? a : b; }

int kanpSack(){
// weights x maxWeight+1
	int tI = sizeof(weights)/sizeof(weights[0]);
	int tW = maxWeight+1;

	for(int i = 0; i <= tI; i++){
		for(int j = 0; j <= tW; j++){
			if(i == 0 || j == 0)
				arr[i][j] = 0;
			else if(j >= weights[i-1])
				arr[i][j] = max(values[i-1]+arr[i-1][j-weights[i-1]], arr[i-1][j]);
			else
				arr[i][j] = arr[i-1][j];
		}
	}
	return arr[tI][tW];
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("kanpSack:%d\n",kanpSack());
	return 0;
}

