// 51-BinarySearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define size 10

int arr[size] = {100, 90, 80, 70, 60, 50, 40, 30, 20, 10};

void swap(int& a, int& b){
	int t = a;
	a = b;
	b = t;
}

int partition(int left, int right) {
	int pivot = arr[right];
	int sIndex = left - 1;
	for(int i = left; i < right; i++){
		if(arr[i] <= pivot){
			sIndex++;
			swap(arr[sIndex], arr[i]);
		}
	}
	swap(arr[sIndex+1], arr[right]);
	return sIndex+1;
}

void qSort(int left, int right) {
	if(left < right){
		int wall = partition(left, right);
		qSort(left, wall-1);
		qSort(wall+1, right);
	}
}

int binSearch(int nu, int left, int right) {
	int res = -1;
	int middle = left + (right - left)/2;

	if(arr[middle] == nu)
		return middle;

	else if(nu > arr[middle])
		res = binSearch(nu, middle+1, right);

	else if(nu < arr[middle])
		res = binSearch(nu, left, middle-1);

	return res;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int no;
	qSort(0, size-1);
	printf("Enter Number To Be Searched\n");
	scanf("%d",&no);
	int res = binSearch(no, 0, size-1);
	if(res != -1)
		printf("%d found at %d index\n",no, res);
	else
		printf("%d not-found\n");
	return 0;
}

