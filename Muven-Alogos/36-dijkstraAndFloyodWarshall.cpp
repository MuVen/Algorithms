// 36-dijkstraAndFloyodWarshall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define V 5
#define INF 999999

bool visitedVertex[V];
int dist[V];
int path[V];

/*int graph[V][V] = {{0, 4, 0, 0, 0, 0, 0, 8, 0},
                   {4, 0, 8, 0, 0, 0, 0, 11, 0},
                   {0, 8, 0, 7, 0, 4, 0, 0, 2},
                   {0, 0, 7, 0, 9, 14, 0, 0, 0},
                   {0, 0, 0, 9, 0, 10, 0, 0, 0},
                   {0, 0, 4, 0, 10, 0, 2, 0, 0},
                   {0, 0, 0, 14, 0, 2, 0, 1, 6},
                   {8, 11, 0, 0, 0, 0, 1, 0, 7},
                   {0, 0, 2, 0, 0, 0, 6, 7, 0}
                  };*/

int graph[V][V] = {{0, 4, 2, 0, 0},
                   {0, 0, 0, 2, 3},
                   {0, 1, 0, 4, 5},
                   {0, 0, 0, 0, 0},
                   {0, 0, 0, 1, 0}
                  };


void printDistance(){
	for(int i = 0; i < V; i++)
		printf("%d\t",dist[i]);
}

void printPath(){
	for(int i = 0; i < V; i++)
		printf("%d\t",path[i]);
}

void getMinimumDistAndIndex(int& minDist, int& minIndex)
{   minDist = INF;
	for(int i = 0; i < V; i++){
		if(visitedVertex[i] == false && dist[i] < minDist){
			minDist = dist[i];
			minIndex = i;
		}
	}
}

void dijkstra(int src){
    for(int i = 0; i < V; i++){
    	dist[i] = INF;
    	visitedVertex[i] = false;
    }

    dist[src] = 0;
    int minDist, minIndex;
    for(int i = 0; i < V; i++){
    	getMinimumDistAndIndex(minDist, minIndex);
    	visitedVertex[minIndex] = true;
		path[minIndex] = i;
    	for(int j = 0; j < V; j++){
    		if(visitedVertex[j] == false && graph[minIndex][j] != INF && graph[minIndex][j] != 0){
    			if(minDist + graph[minIndex][j] < dist[j])
    				dist[j] = minDist + graph[minIndex][j];
    		}
    	}
    }
    printDistance();
    printf("\n");
	printPath();
}

void floydWarshall(){
	int dGraph[V][V],i,j,k;
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			dGraph[i][j] = (i != j && graph[i][j] == 0) ? INF : graph[i][j];
		}
	}

	for(int k = 0; k < V; k++){
		for( int i = 0; i < V; i ++){
			for( int j = 0; j < V; j++){
				if(dGraph[i][k] + dGraph[k][j] < dGraph[i][j])
					dGraph[i][j] = dGraph[i][k] + dGraph[k][j];
			}
		}
	}

    printf("\nfloydWarshall:\n");
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(dGraph[i][j] == INF)
				printf("x\t");
			else
			    printf("%d\t",dGraph[i][j]);
		}
		printf("\n");
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	for(int i = 0; i < V; i++)
        dijkstra(i);
    floydWarshall();
	return 0;
}

