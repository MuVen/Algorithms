// 5 - Compression.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>
#include <string>
#include <iostream>
#include <sstream>

using namespace std;

string charToString(char ch) {// conver char to string
	stringstream s;
	s << ch;
	return s.str();
}

string intToString(int i) // convert int to string
{
    stringstream s;
    s << i;
    return s.str();
}

int countCompression(char* str){
    int compressionLen = 0;
	int countConsecutive = 0;

	for(int i = 0; str[i] != '\0'; i++) {
        countConsecutive++;

		if(str[i+1] == '\0' || (str[i] != str[i+1])) {
			compressionLen += 2;
			countConsecutive = 0;
		}
	}

	return compressionLen;
}

std::string compress(char* str) {
	std::string cStr;
	int countConsecutive = 0;
	for(int i = 0, j = 0; str[i] != '\0'; i++) {
        countConsecutive++;
		if(str[i+1] =='\0' || (str[i] != str[i+1])) {
			cStr.append(charToString(str[i]));
			cStr.append(intToString(countConsecutive));
			countConsecutive = 0;
		}
	}
	return cStr;
}

int _tmain(int argc, _TCHAR* argv[])
{
	char str[500];

	printf("Enter the string\n");
	scanf("%499[^\n]",str);getchar();

	std::string cStr = compress(str);
	cout<<"Compressed String "<<cStr;
    getchar();
	return 0;
}

