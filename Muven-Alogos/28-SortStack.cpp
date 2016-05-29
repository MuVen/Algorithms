// 28 - SortStack.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>

using namespace std;

#define MAX 5

class stack{
	int top;
	int arr[MAX];
public:
	stack(){
		top = -1;
	}
	bool isEmpty(){
		if(top == -1)
			return true;
		return false;
	}

	bool isFull(){
		if(top == MAX-1)
			return true;
		return false;
	}

	void push(int data){
		if(isFull())
			return;
		top++;
		arr[top] = data;
	}

	int peek(){
		if(isEmpty())
			return -1;
		return arr[top];
	}

	int pop(){
		if(isEmpty())
			return -1;
		int temp = arr[top];
		top--;
		return temp;
	}

	void printStack(){
		if(isEmpty()){
			cout<<"Stack is Empty\n";
			return;
		}
		cout<<"Printing Stack: Start\n\n\n";
		for(int i = 0; i <= top; i++)
			cout<<arr[i]<<"\t";
		cout<<"\n\n\nPrinting Stack: Finished\n\n\n";
	}
};

void sortStack(stack &s)
{
	stack sdup;
	while(!s.isEmpty()){
		int temp = s.pop();
		while(!sdup.isEmpty() && sdup.peek() > temp){
			s.push(sdup.pop());
		}
		sdup.push(temp);
	}
	sdup.printStack();
}

void sortedInsert(stack &s, int temp)
{
	if(s.isEmpty() || temp > s.peek()) {
		s.push(temp);
		return;
	}

	int peek = s.pop();
	sortedInsert(s, temp);
    
	s.push(peek);
}

void sortStackWithoutNewStack(stack &s)
{
	if(s.isEmpty())
		return;

	int temp = s.pop();
	sortStackWithoutNewStack(s);

	sortedInsert(s, temp);
}

int _tmain(int argc, _TCHAR* argv[])
{
	stack s;
	s.push(13);
	s.push(11);
	s.push(10);
	s.push(12);
	s.push(9);


	sortStack(s);

	s.push(13);
	s.push(11);
	s.push(10);
	s.push(12);
	s.push(9);
	sortStackWithoutNewStack(s);
	s.printStack();

	return 0;
}

