// 42-LongesCommonSubsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define I -1

char X[] = "AGGTAB";
char Y[] = "GXTXAYB";

int xLen, yLen;

int LCS[1000][1000];

int max(int a, int b){
	return a > b ? a : b;
}

int lcs(){
	for(int i = 0; i < xLen+1; i++){
		for(int j = 0; j < yLen+1; j++){
			if(i == 0 || j ==0)
				LCS[i][j] = 0;
			else if(X[i-1] == Y[j-1])
				LCS[i][j] = LCS[i-1][j-1]+1;
			else
				LCS[i][j] = max(LCS[i-1][j], LCS[i][j-1]);
		}
	}
	return LCS[xLen][yLen];
}

int strlen(char* x){
	int len;
	for(len = 0; x[len] !='\0'; len++);
	return len;
}

int _tmain(int argc, _TCHAR* argv[])
{
	xLen = strlen(X);
    yLen = strlen(Y);
    printf("LCS:%d\n",lcs());
	return 0;
}

