// 32-Sieve-of-eratosthenes.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <cstring>


void SieveOfEratosthenes(int n)
{
	bool isPrime[100000];
	std::memset(isPrime, true, sizeof(isPrime));
	for(int i = 2; i * i <= n; i++){
		if(isPrime[i]){
			for(int j = i * i; j <= n; j+=i){
				isPrime[j] = false;
			}
		}
	}

	for(int i = 2; i <= n; i++){
		if(isPrime[i])
			printf("%d\t",i);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int n;
	printf("Enter the number 'n' to print all the prime numbers between 1 - n using sieves method\n");
	scanf("%d",&n);
	SieveOfEratosthenes(n);
	return 0;
}

