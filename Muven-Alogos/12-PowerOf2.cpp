// 12-PowerOf2.cpp : Defines the entry point for the console application.
//

// Pritns power of 2 from 1 - n.

#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>

void clrscr(){
	system("cls");
}

int powerOf2(int n){
	int output = 0;
	if(n < 1)
		output = 0;
	else if(n == 1)
		output = 1;
	else {
   	  int pre = powerOf2(n/2);
	  int curr = pre * 2;
	  output = curr;
	}
	printf("%d\t",output);
	return output;
}

int _tmain(int argc, _TCHAR* argv[])
{
    int n;
	printf("Enter the Nth Number till where you want to print powers of 2\n");
	scanf("%d",&n);
	clrscr();
	powerOf2(n);
	return 0;
}

