// 35-FloydWarshall.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define V 3

#define INF 99999

void printShortestPathMatrix(int output[][V]){
	for(int i = 0; i < V; i++){
		for(int j = 0; j < V; j++){
			if(output[i][j] == INF)
				printf("%s\t","INF");
			else
				printf("%d\t",output[i][j]);
		}
		printf("\n");
	}
}

void floydWarshall(int graph[][V]){

	int output[V][V], i, j, k;

	for(i = 0; i < V; i++){
		for(j = 0; j < V; j++){
			output[i][j] = graph[i][j];
		}
	}

	for(k = 0; k < V; k++){
		for(i = 0; i < V; i++){
			for(j = 0; j < V; j++){
				if(graph[i][k] + graph[k][j] < graph[i][j])
					output[i][j] = graph[i][k] + graph[k][j];
			}
		}
	}

	printShortestPathMatrix(output);
}


int _tmain(int argc, _TCHAR* argv[])
{
	/*int graph[V][V] = { {0,   5,  INF, 10},
                        {INF, 0,   3, INF},
                        {INF, INF, 0,   1},
                        {INF, INF, INF, 0}
                      };*/

	int graph[V][V] = { {INF, 10,   3},
                        {INF, INF, INF},
                        {INF, 4, INF}
                      };


	// Print the solution
    floydWarshall(graph);

	return 0;
}

