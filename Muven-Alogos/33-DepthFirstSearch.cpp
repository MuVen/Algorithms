// 33-DepthFirstSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define V 7

bool visited[V] = {false};

void DFS(int G[V][V], int source) {
	visited[source] = true;
	printf("%d\t",source);
	for(int i = 0; i < V; i++){
		if(G[source][i] == 1 && !visited[i])
			DFS(G, i);
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	int G[V][V] =
	{ { 0, 1, 0, 0, 0, 0, 1 },
	  { 1, 0, 1, 0, 0, 1, 0},
	  { 0, 1, 0, 1, 1, 0, 0,},
	  { 0, 0, 1, 0, 0, 0, 0},
	  { 0, 0, 1, 0, 0, 1, 0},
	  { 0, 1, 0, 0, 1, 0, 1},
	  { 1, 0, 0, 0, 0, 1, 0}
	};

	/*int G[V][V] =
	//A  B  C  D  E  F  G  H
	{ { 0, 1, 0, 1, 0, 0, 1, 0},
	  { 1, 0, 0, 0, 1, 1, 0, 0},
	  { 0, 0, 0, 0, 0, 1, 0, 1},
	  { 1, 0, 0, 0, 0, 1, 0, 0},
	  { 0, 1, 0, 0, 0, 0, 1, 0},
	  { 0, 1, 1, 1, 0, 0, 0, 0},
	  { 1, 0, 0, 0, 1, 0, 0, 0},
      { 0, 0, 1, 0, 0, 0, 0, 0},
	};

	int G[V][V] =
	{
		{0, 1, 0, 1, 0},
		{0, 0, 0, 0, 1},
		{1, 0, 0, 1, 0},
		{0, 0, 0, 0, 0},
		{0, 0, 0, 0, 0}
	};*/

	DFS(G, 4);

	return 0;
}

