// 46-BubbleSort.cpp : Defines the entry point for the console application.
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

void bubbleSortUtil(int a[], int len) {
    int i, j;
	for(i = 0; i < len-1; i++){
		for(j = i+1; j < len; j++){
			if(a[i] > a[j])
				swapUtil(a[i], a[j]);
	    }
	}
}

void bubbleSort(int a[], int len) {
    printf("BeforeSoting:\t");printUtil(a, len);
    bubbleSortUtil(a, len);
    printf("AfterSorting:\t");printUtil(a, len);
}


int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {0,9,8,7,6,5,4,3,2,1};
    int len = sizeof(a)/sizeof(a[0]);
    bubbleSort(a, len);
	return 0;
}

