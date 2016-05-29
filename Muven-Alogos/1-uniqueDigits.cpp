// 1-uniqueDigits.cpp : Defines the entry point for the console application.
//

// Accpet a string and return true if the string has all unique characters.

#include "stdafx.h"
#include<windows.h>
#include<stdlib.h>

void clrscr()
{
    system("cls");
}

/*
Allocate char array of char set range for ASCII 
its 256. for  UNICODE it varies again.
*/

bool doesStringHasUniqueChars(char* string)
{
	char allchars[256] = {0};

	for(int i = 0; string[i]!='\0'; i++){
		if(!allchars[string[i]])
            allchars[string[i]] = 1;
		else
			return false;
	}
	return true;
}

/*
Without allocating char array, by reducing space we can findout unique chars
but we can check only from a - z.
*/
bool doesStringHasUniqueCharsWithoutExtraSpace(char* string)
{
    int mask = 0;

	for(int i = 0; string[i] != '\0'; i++) {
		int val = string[i] - 'a';
		if((mask & 1 << val) > 0 )
			return false;
		mask |= (1 << val);
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char string[200];char ch;
	
	printf("Enter the string\n");
	scanf("%199[^\n]",string);
	scanf("%c",&ch);

	clrscr();

	doesStringHasUniqueChars(string) ? 
		printf("1. %s has unique characters\n",string) : 
	    printf("1. %s doesnt have unique characters\n",string);

	doesStringHasUniqueCharsWithoutExtraSpace(string) ? 
		printf("2. %s has unique characters\n",string) : 
	    printf("2. %s doesnt have unique characters\n",string);

	getchar();
	return 0;
}

