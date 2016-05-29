// 56-Subset Sum Problem.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

int set[] = {3, 34, 4, 12, 15, 25};
int sum = 7;

int row,  col;
int dp[101][101];

void reset(){
	for(int i = 0; i <= row; i++){
		for(int j = 0; j <= col; j++){
			if(i == 0)
				dp[i][j] = 0;
			if(j == 0)
				dp[i][j] = 1;
		}
	}

}

bool isSubsetSum(){
	for(int i = 1; i <= row; i++){
		for(int j = 1; j <= col; j++){
   			    dp[i][j] = dp[i-1][j] || dp[i-1][j - set[i-1]];
		}
	}

	return dp[row][col];
}

int _tmain(int argc, _TCHAR* argv[])
{
  row = sizeof(set)/sizeof(set[0]);
  col = sum;
  reset();
  isSubsetSum() ? cout<<"True" : cout<<"False";
  return 0;
}

