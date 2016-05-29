// 10-PrintAllPrimeNumbers.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

bool isPrime(int nu) {
	for(int i = 2; i * i <= nu; i++){
        if(nu % i == 0)
			return false;
	}
	return true;
}

int _tmain(int argc, _TCHAR* argv[])
{
	for(int i = 0; i < 100; i++){
		if(isPrime(i)) 
			printf("%d\t",i);
	}
	getchar();
	return 0;
}

