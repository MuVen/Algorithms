// 43-LongestIncreasingSubsequence.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>

#define MAX -9999999

int arr[] = {2, 5, 3, 7, 11, 8, 10, 13, 6};

int LIS(){
	int arrLen = sizeof(arr)/sizeof(arr[0]);
	int* lis = (int*)malloc(sizeof(int)*arrLen);
	int max = MAX;

	for(int i = 0; i < arrLen; i++)
		lis[i] = 1;

	for(int i = 1; i < arrLen; i++)
		for(int j = 0; j < i; j++)
			if(arr[i] > arr[j] && lis[i] < lis[j] + 1)
				lis[i] = lis[j] + 1;

	for(int i = 0; i < arrLen; i++)
		if(lis[i] > max)
			max = lis[i];

	return max;
}

int _tmain(int argc, _TCHAR* argv[])
{
	printf("Longest Increasing Subsequence: %d\n",LIS());
	return 0;
}

