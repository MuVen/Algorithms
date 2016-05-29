// 37-topologicalSort.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define V 8
#define SIZE 100

bool visited[V] = {false};

/*int graph[V][V] = {   {0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 1, 0, 0},
					  {1, 0, 0, 0, 0, 0},
					  {1, 1, 0, 0, 0, 0},
					  {1, 0, 1, 0, 0, 0},
				  };*/


int graph[V][V] = {   {0, 0, 1, 1, 0, 0, 0, 0},
					  {0, 0, 0, 1, 0, 0, 0, 0},
					  {0, 0, 0, 1, 1, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 0},
					  {0, 0, 0, 0, 0, 0, 0, 1},
					  {0, 0, 0, 0, 1, 0, 1, 0},
					  {0, 0, 0, 0, 0, 0, 0, 1},
					  {0, 0, 0, 0, 0, 0, 0, 0},
				  };


class Stack{
int top;
int arr[SIZE];
public:
	Stack(){
		top = -1;
	}
	bool isFull(){
		if(top == SIZE-1)
			return true;
		return false;
	}
	bool isEmpty(){
		if(top == -1)
			return true;
		return false;
	}
	void push(int val){
		if(isFull())
			return;
		top++;
		arr[top] = val;
	}
	int pop(){
		if(isEmpty())
			return -1;
		int temp = arr[top];
		top--;
		return temp;
	}
};

Stack s;

void DFS(int source){
	visited[source] = true;
	//printf("%d\t",source);
	for(int i = 0; i < V; i++){
		if(graph[source][i] == 1 && visited[i] == false) {
			DFS(i);
		}
	}
	s.push(source);
}

int _tmain(int argc, _TCHAR* argv[])
{
	for(int i = 0; i < V; i++){
		if(visited[i] == false)
		    DFS(i);
	}
	while(!s.isEmpty()){
		printf("%d\n",s.pop());
	}
	return 0;
}

