// 52-StringPermutation.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include <string.h>
 
void swap(char& ch1, char& ch2){
	char ch;
	ch = ch1;
	ch1 = ch2;
	ch2 = ch;
}

void permute(char* str, int l, int r){
    if(l == r)
		printf("%s\n",str);
	else{
		for(int i = l; i <= r; i++){
			swap(str[i], str[l]);
			permute(str, l+1, r);
			swap(str[i], str[l]);
		}
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
    char str[] = "ABC";
    int n = strlen(str);
    permute(str, 0, n-1);
	return 0;
}

