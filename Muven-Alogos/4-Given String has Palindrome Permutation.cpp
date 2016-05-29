// 4 - Given String has Palindrome Permutation.cpp : Defines the entry point for the console application.
//

// Accept a string and print if it has a palindrome permuation in it.

#include "stdafx.h"
#include <windows.h>
#include <stdlib.h>

void clrscr(){
	system("cls");
}

int getCharValue(char ch) {
	if(ch >= 'a' && ch <= 'z')
		return ch - 'a';
	if(ch >= 'A' && ch <= 'Z')
		return ch - 'A';
	return -1;
}

bool checkIfStringHasPalindrome(char* str){
	int alpha[26] = {0};
    int countOdd = 0;
	for(int i = 0; str[i] != '\0'; i++) {
		int val = getCharValue(str[i]);
		if(val != -1) {
            alpha[val]++;
            if(alpha[val]%2 == 1)
				countOdd++;
			else
				countOdd--;
		}
	}
	return countOdd <= 1;
}


int _tmain(int argc, _TCHAR* argv[])
{
	char str[500];

	printf("Enter the string\n");
	scanf("%499[^\n]",str);
	getchar();clrscr();

	checkIfStringHasPalindrome(str) ?
		printf("%s has Palindrome combination",str) :
	    printf("%s doesnt have Palindrome combination",str);

    getchar();
	return 0;
}

