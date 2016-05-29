// 49-MergeSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>


void printUtil(int a[], int len) {
for(int i = 0 ; i < len ; i++)
    printf("%d\t",a[i]);
printf("\n");
}

void merge(int a[], int l, int m, int r) {
	
	int i, j, k;

	int n1 = m - l + 1;
	int n2 = r - m;

	int* L = (int*) malloc(sizeof(int) * n1);
	int* R = (int*) malloc(sizeof(int) * n2);

	for(i = 0; i < n1; i++)
		L[i] = a[l + i];
	for(j = 0; j < n2; j++)
		R[j] = a[m + 1+ j];

	i = 0; j = 0; k = l;
	while(i < n1 && j < n2){
		if(L[i] > R[j]){
			a[k] = L[i];
			i++;
		}else{
			a[k] = R[j];
			j++;
		}
		k++;
	}

	while(i < n1){
		a[k] = L[i];
		k++;
		i++;
	}

	while(j < n2){
		a[k] = R[j];
		k++;
		j++;
	}

	free(L);
	free(R);
}

void mergeSortUtil(int a[], int l, int r) {
	if(l < r){
		int m = l + (r - l)/2;
		mergeSortUtil(a, l, m);
		mergeSortUtil(a, m+1, r);
		merge(a, l, m, r);
	}
}


void mergeSort(int a[], int len) {
    printf("BeforeSorting:\t");printUtil(a, len);
    mergeSortUtil(a, 0, len-1);
    printf("AfterSorting:\t");printUtil(a, len);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[] = {0,1,2,3,4};
	int len = sizeof(a)/sizeof(a[0]);
	mergeSort(a, len);
	return 0;
}

