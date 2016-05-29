// 48-SelectionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void printUtil(int a[], int len) {
for(int i = 0; i < len; i++)
    printf("%d\t",a[i]);
printf("\n");
}


void swapUtil(int& a, int& b) {
    a = a + b;
    b = a - b;
    a = a - b;
}

int minValuePos(int a[], int l, int r){

	int min = a[l];
	int minPos = l;
	for(int i = l+1; i < r; i++){
		if(a[i] < min){
			min = a[i];
			minPos = i;
		}
	}

	return minPos;
}

void selectionSortUtil(int a[], int len) {
	for(int i = 0; i < len; i++){
		int minPos = minValuePos(a, i, len);
		if(minPos != i)
			swapUtil(a[i], a[minPos]);
	}
}


void selectionSort(int a[], int len) {
	printf("BeforeSorting:\t");printUtil(a, len);
	selectionSortUtil(a,len);
	printf("AfterSorting:\t");printUtil(a, len);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {0,9,8,7,6,5,4,3,2,1};
	int len = sizeof(a)/sizeof(a[0]);
	selectionSort(a,len);
	return 0;
}

