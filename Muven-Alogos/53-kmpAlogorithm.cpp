// 53-kmpAlogorithm.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<string.h>
#include<stdlib.h>
 
void computeLPSArray(char *pat, int M, int *lps);
 
void KMPSearch(char *pat, char *txt)
{
    int M = strlen(pat);
    int N = strlen(txt);
 
    // create lps[] that will hold the longest prefix suffix
    // values for pattern
    int *lps = (int *)malloc(sizeof(int)*M);
    int j  = 0;  // index for pat[]
 
    // Preprocess the pattern (calculate lps[] array)
    computeLPSArray(pat, M, lps);
 
    int i = 0;  // index for txt[]
    while (i < N)
    {
      if (pat[j] == txt[i])
      {
        j++;
        i++;
      }
 
      if (j == M)
      {
        printf("Found pattern at index %d \n", i-j);
        j = lps[j-1];
      }
 
      // mismatch after j matches
      else if (i < N && pat[j] != txt[i])
      {
        // Do not match lps[0..lps[j-1]] characters,
        // they will match anyway
        if (j != 0)
         j = lps[j-1];
        else
         i = i+1;
      }
    }
    free(lps); // to avoid memory leak
}
 
void computeLPSArray(char *S, int m, int *p)
{
	int i = 0;
	p[0] = 0;

	for(int j = 1; j < m; j++){

		while(i > 0 && S[i] != S[j])
			i = p[i-1];

		if(S[i] == S[j])
			i++;

		p[j] = i;
	}

}
 
int _tmain(int argc, _TCHAR* argv[])
{
   char *txt = "AABAAAB";
   char *pat = "AAAB";
   KMPSearch(pat, txt);
   return 0;
}

