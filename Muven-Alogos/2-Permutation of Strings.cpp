// 2 - Permutation of Strings.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <stdlib.h>
#include <windows.h>

// Accept two strings and print if the two strings are permutation of each other.

void clrscr(){
	system("cls");
}

int strlen(char* str){
	int len = 0;
	if(str == NULL)
		return len;
	for(len = 0; str[len]!='\0';len++);
	return len;
}

bool strcmp(char* str1, char* str2) {

	if(strlen(str1)!=strlen(str2))
		return false;

	for(int i = 0; str1[i] !='\0' && str2[i] !='\0'; i++){
		if(str1[i]!=str2[i])
			return false;
	}

	return true;
}

void sortString(char* str) {
    int len = strlen(str);
	char temp;
	for(int i = 0; i < len-1; i++) {
		for(int j = i + 1; j < len; j++) {
			if(str[i]>str[j]) {
				temp = str[i];
				str[i] = str[j];
				str[j] = temp;
			}
		}
	}
}

bool isAnagramBySort(char* str1, char* str2){
    sortString(str1);
	sortString(str2);
	return strcmp(str1,str2);
}

bool isAnagramByCount(char* str1, char* str2){

	char strarr[256] = {0};
    int i;

	for(i = 0; str1[i]!='\0'; i++)
        strarr[str1[i]] += 1;

	for(i = 0; str2[i]!='\0'; i++){
		strarr[str2[i]] -= 1;
		if(strarr[str2[i]] < 0)
			return false;
	}

	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str1[200];char temp;
	char str2[200];

	printf("Enter string 1\n");
	scanf("%199[^\n]",str1);
	scanf("%c",&temp);
	
	printf("Enter string 2\n");
	scanf("%199[^\n]",str2);
	scanf("%c",&temp);

	clrscr();

	isAnagramBySort(str1, str2) ?
		printf("1. %s and %s are anagrams\n",str1,str2) :
		printf("1. %s and %s are not anagrams\n",str1,str2);

    isAnagramByCount(str1, str2) ?
		printf("2. %s and %s are anagrams\n",str1,str2) :
	    printf("2. %s and %s are not anagrams\n",str1,str2);

	getchar();
	return 0;
}

