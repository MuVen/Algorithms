// 40-MinimumSpanningTreePrimsAndDijkstra.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define INF 99999999
#define V 9

int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
                   {0, 0, 4, 0, 10, 0, 2, 0, 0},
                   {0, 0, 0, 14, 0, 2, 0, 1, 6},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
                   {0, 0, 2, 0, 0, 0, 6, 7, 0}
                  };

/*int graph[V][V] = {{0, 4, 0, 0, 0, 2},
                   {4, 0, 6, 0, 0, 3},
                   {0, 6, 0, 3, 0, 1},
                   {0, 0, 3, 0, 2, 0},
                   {0, 0, 0, 2, 0, 4},
				   {2, 3, 1, 0, 4, 0},
                  };*/

bool visitedVertex[V];
int dist[V];
int key[V];
int parent[V];


void printDijkstra(){
	for(int i = 0; i < V; i++)
		printf("%d\t",dist[i]);
}

void getMinDistAndMinVertex(int& minDist, int& minVertex) {
	minDist = INF;
	for(int i = 0; i < V; i++){
		if(visitedVertex[i] == false && dist[i] < minDist){
			minDist = dist[i];
			minVertex = i;
		}
	}
}

void dijkstra() {
	for(int i = 0; i < V; i++){
		visitedVertex[i] = false;
		dist[i] = INF;
	}
	dist[0] = 0;
	int minDist = 0, minVertex = 0;
	for(int i = 0; i < V; i++){
		getMinDistAndMinVertex(minDist, minVertex);
		visitedVertex[minVertex] = true;
		for(int j = 0; j < V; j++){
			if(visitedVertex[j] == false && graph[minVertex][j] && graph[minVertex][j] != 0) {
				if(graph[minVertex][j]+minDist < dist[j])
					dist[j] = graph[minVertex][j] + minDist;
			}
		}
	}
	printDijkstra();
	printf("\n");
}

void printPrims(){
	for(int i = 1; i < V; i++){
		printf("%d - %d  %d\n",parent[i], i, graph[i][parent[i]]);
	}
}
void getMinKeyVertex(int& minKeyVertex){
	int minKey = INF;
	for(int i = 0; i < V; i++){
		if(visitedVertex[i] == false && key[i] <= minKey){
			minKey = key[i];
			minKeyVertex = i;
		}
	}
}

void prims(){
	for(int i = 0; i < V; i++){
		key[i] = INF;
		visitedVertex[i] = false;
	}

	key[0] = 0;
	int minKeyVertex = 0;
	for(int i = 0; i < V; i++){
		getMinKeyVertex(minKeyVertex);
		visitedVertex[minKeyVertex] = true;
		for(int j = 0; j < V; j++){
			if(visitedVertex[j] == false && graph[minKeyVertex][j]) {
				if(graph[minKeyVertex][j] < key[j]){
					key[j] = graph[minKeyVertex][j];
					parent[j] = minKeyVertex;
				}
			}
		}
	}
	printPrims();
}

int _tmain(int argc, _TCHAR* argv[])
{
	dijkstra();
	prims();
	return 0;
}

