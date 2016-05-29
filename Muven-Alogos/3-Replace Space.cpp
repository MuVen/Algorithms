// 3-Replace Space.cpp : Defines the entry point for the console application.
//

// This program replaces space with %20.

#include "stdafx.h"
#include <malloc.h>
#include <stdlib.h>
#include <windows.h>

void clrscr(){
	system("cls");
}

char* replaceSpaces(char* str){

	int nSpaces = 0, i = 0, len = 0, j = 0;
	for(i = 0, len = 0; str[i] !='\0'; i++, len++) {
		if(str[i] == ' ')
			nSpaces++;
	}

	printf("Number of Spaces in the string:%d & length:%d\n",nSpaces, len);
    int newStrLen = (len+(nSpaces*2))+1;
	char* nStr = (char*) malloc((sizeof(char) * newStrLen));

	if(nStr == NULL)
		return NULL;

	for(i = 0, j =0; i < len; i++, j++) {
		if(str[i] != ' ') {
			nStr[j] = str[i];
		}else{
            nStr[j] = '%';
			nStr[++j] = '2';
			nStr[++j] = '0';
		}
	}
    nStr[j] = '\0';
	return nStr;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[200];
	char temp;
	char* replacedStr = NULL;
	clrscr();
	printf("Enter string with spaces\n");
	scanf("%199[^\n]",str);
	scanf("%c",&temp);
    clrscr();
	replacedStr = replaceSpaces(str);
	printf("Replaced String:\n\n%s",replacedStr);
	getchar();
	return 0;
}

