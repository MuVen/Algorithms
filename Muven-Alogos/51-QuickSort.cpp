// 51-QuickSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define size 5

int arr[size] = {5,4,3,2,1};

void swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

int partition(int left, int right){
	int pivot = arr[right];
	int sIndex = left - 1;

	for(int i = left; i < right; i++){
		if(arr[i] <= pivot){
			sIndex++;
			swap(arr[i], arr[sIndex]);
		}
	}
	swap(arr[sIndex+1], arr[right]);
	return sIndex+1;
} 

void qSort(int left, int right){
	if(left < right){
		int wall = partition(left, right);
		qSort(left, wall-1);
		qSort(wall+1, right);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	qSort(0, size-1);
	for(int i = 0; i < size; printf("%d ",arr[i]),i++);
	return 0;
}

