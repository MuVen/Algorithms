// 13-apowerb.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>

void clrscr(){
	system("cls");
}

int powerOfn1n2(int n1, int n2) {
    if(n2 < 0)
		return 0;
	if(n2 == 0)
		return 1;
	else
		return n1 * powerOfn1n2(n1, n2 - 1);
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n1,n2;
	printf("Enter the n1^n2\n");
	scanf("%d%d",&n1,&n2);
	clrscr();
	printf("%d ^ %d = %d\n",n1,n2,powerOfn1n2(n1,n2));
	return 0;
}

