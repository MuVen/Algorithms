// 12-nthfebonacciNumber.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>

void clrscr(){
	system("cls");
}

int nthFebo(int n){
	if(n == 0)
		return 0;
	if(n == 1)
		return 1;
	return nthFebo(n-1) + nthFebo(n-2);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	printf("Print nth Febonacci Number\n");
	scanf("%d",&n);
	getchar();
	clrscr();
	printf("%d - is %dth Febonacci Number\n",nthFebo(n),n);
	getchar();
	return 0;
}

