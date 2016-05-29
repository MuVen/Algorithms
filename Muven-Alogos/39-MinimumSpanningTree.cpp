// 39-MinimumSpanningTree.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include<stdio.h>
#include<conio.h>

#define V 6
#define INF 999999

int key[V];
int parent[V];
bool visitedVertex[V];

int graph[V][V] = {{0, 4, 0, 0, 0, 2},
                   {4, 0, 6, 0, 0, 3},
                   {0, 6, 0, 3, 0, 1},
                   {0, 0, 3, 0, 2, 0},
                   {0, 0, 0, 2, 0, 4},
				   {2, 3, 1, 0, 4, 0},
                  };

void printMST()
{
   printf("Edge   Weight\n");
   for (int i = 1; i < V; i++)
      printf("%d - %d    %d \n", parent[i], i, graph[i][parent[i]]);
}

void getMinKeyVertex(int& minVertex){
	int minKey = INF;
	for(int i = 0; i < V; i++){
		if(visitedVertex[i] == false && key[i] <= minKey){
			minKey = key[i];
			minVertex = i;
		}
	}
}

void primMST(){
	for(int i = 0; i < V; i++){
		key[i] = INF;
		visitedVertex[i] = false;
	}

	key[0] = 0;
	int minVertex;
	for(int i = 0; i < V; i++){
		getMinKeyVertex(minVertex);
		visitedVertex[minVertex] = true;
		for(int j = 0; j < V; j++){
			if(visitedVertex[j] == false && graph[minVertex][j]){
				if(graph[minVertex][j] < key[j]){
					key[j] = graph[minVertex][j];
					parent[j] = minVertex;
				}
			}
		}
	}

	printMST();
}

int _tmain(int argc, _TCHAR* argv[])
{
	primMST();
}

