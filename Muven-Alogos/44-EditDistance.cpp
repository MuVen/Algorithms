// 44-EditDistance.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
using namespace std;

#define MAX 10000

int arr[MAX][MAX];

char* str1 = "praveen";
char* str2 = "munukutla";

int strlen(char* str){
	int len;
	for(len  = 0; str[len] != '\0'; len++);
	return len;
}

int min2(int a, int b){
	return a < b ? a : b;
}

int min3(int a, int b, int c){
    return min2(min2(a,b),c);
}

int editDist(char* str1, char* str2) {
	int str1len = strlen(str1);
	int str2len = strlen(str2);

	for(int i = 0; i <= str1len; i++){
		for(int j = 0; j <= str2len; j++){
			if(i == 0)
				arr[i][j] = j;
			else if(j == 0)
				arr[i][j] = i;
			else {
				if(str1[i-1] == str2[j-1]) {
					arr[i][j] = arr[i-1][j-1];
				}else{
					arr[i][j] = min3(arr[i][j-1], arr[i-1][j-1], arr[i-1][j])+1;
				}
			}
		}
	}

	return arr[str1len][str2len];
}

int _tmain(int argc, _TCHAR* argv[])
{
	cout<<editDist(str1, str2);
	return 0;
}

