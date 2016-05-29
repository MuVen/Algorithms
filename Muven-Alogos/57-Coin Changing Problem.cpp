// 57-Coin Changing Problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int arr[] = {1, 2, 3};
int total = 4;
int row, col;

int dp[100][100];

void reset(){
	for(int i = 0; i <= row; i++)
		for(int j = 0; j <= col; j++)
			dp[i][j] = 0;

}

int coinChangeWays(){
	int wpc, pc;
	int i, j, k;
	for(i = 1; i <= row; i++){
		for(k = 0; k < i; k++){
			if(k == 0)
				dp[i][k] = 1;
			else
				dp[i][k] = dp[i-1][k];
		}
		for(j = k; j <= col; j++){
			// count picking coin
			 pc = dp[i][j-arr[i-1]];

			// count without picking coin
			 wpc = dp[i-1][j];
			 dp[i][j] = pc + wpc;
		}
	}
	return dp[row][col];
}


int _tmain(int argc, _TCHAR* argv[])
{
	row = sizeof(arr)/sizeof(arr[0]);
	col = total;
    reset();
	cout<<coinChangeWays()<<endl;
	return 0;
}

