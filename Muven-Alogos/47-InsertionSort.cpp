// 47-InsertionSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

void printUtil(int a[], int len) {
     for(int i = 0; i < len; i++)
         printf("%d\t",a[i]);
     printf("\n");
}

void insertionSortUtil(int a[], int len) {
	int hole, holeValue;
	for(int i = 1; i < len; i++){
		hole = i; holeValue = a[i];
		while(hole > 0 && a[hole-1] > holeValue){
			a[hole] = a[hole-1];
			hole--;
		}
		a[hole] = holeValue;
	}
}

void insertionSort(int a[], int len) {
    printf("BeforeSorting:\t");printUtil(a, len);
    insertionSortUtil(a, len);
    printf("AfterSorting:\t");printUtil(a, len);
}

int _tmain(int argc, _TCHAR* argv[])
{
    int a[] = {0,9,8,7,6,5,4,3,2,1};
    int len = sizeof(a)/sizeof(a[0]);
    insertionSort(a, len);
    return 0;
}

