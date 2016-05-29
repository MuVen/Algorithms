// 34-BreadthFirstSearch.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <malloc.h>

#define V 8

bool visited[V] = {false};

class Queue{
	int front;
	int rear;
	int size;
	int* vertices;

public:
	Queue(int qSize){
		front = 0;
		rear = -1;
		size = qSize;
		vertices = (int*) malloc(sizeof(int) * size);
	}

	bool isEmpty(){
		if(rear == -1 && front == 0)
			return true;
		return false;
	}

	bool isFull(){
		if(rear == size-1)
			return true;
		return false;
	}

	void enQueue(int val){
		if(isFull())
			return;
        rear++;
		vertices[rear] = val;
	}

	int deQueue(){
        if(isEmpty())
			return -1;

		int temp;
		if(rear == front){
			temp = vertices[rear];
			rear = -1;
			front = 0;
			return temp;
		}

		temp = vertices[front];
		front++;
		return temp;
	}
};


void BFS(int G[V][V], int source) {
	Queue queue(V);
	queue.enQueue(source);
	visited[source] = true;
	while (!queue.isEmpty()) {
		int u = queue.deQueue();
		printf("%d ", u);
		for (int v = 0; v < V; v++) {
			if (G[u][v] == 1 && !visited[v]) {
				visited[v] = 1;
				queue.enQueue(v);
			}
		}   
	}
}

int _tmain(int argc, _TCHAR* argv[])
{
	/*int G[V][V] = 
	 // 0  1  2  3  4  5  6  7
	{ { 0, 1, 0, 1, 1, 0, 0, 0 },
	  { 1, 0, 1, 0, 0, 1, 0, 0 },
	  { 0, 1, 0, 1, 0, 0, 1, 0 },
	  { 1, 0, 1, 0, 0, 0, 0, 1 },
	  { 1, 0, 0, 0, 0, 1, 0, 1 },
	  { 0, 1, 0, 0, 1, 0, 1, 0 },
	  { 0, 0, 1, 0, 0, 1, 0, 1 },
	  { 0, 0, 0, 1, 1, 0, 1, 0 }
	};*/

	int G[V][V] = 
	 // 0  1  2  3  4  5  6  7
	{ { 0, 1, 0, 1, 0, 0, 1, 0 },
	  { 1, 0, 0, 0, 1, 1, 0, 0 },
	  { 0, 0, 0, 0, 0, 1, 0, 1 },
	  { 1, 0, 0, 0, 0, 1, 0, 0 },
	  { 0, 1, 0, 0, 0, 0, 1, 0 },
	  { 0, 1, 1, 0, 0, 0, 0, 0 },
	  { 1, 0, 0, 1, 1, 0, 0, 0 },
	  { 0, 0, 1, 0, 0, 0, 0, 0 }
	};


	/*int G[V][V] = 
	{{0, 1, 1, 0},
	{0, 0, 1, 0},
	{1, 0, 0, 1},
	{0, 0, 0, 1}};*/


	BFS(G, 0);

	return 0;
}

