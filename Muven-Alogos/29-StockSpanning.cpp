// 29-StockSpanning.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#define MAX 7

class stack {
	int top;
	int arr[MAX];
public:
	stack(){top = -1;}
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
	int pop(){
		if(isEmpty())
			return -1;
		int popVal = arr[top];
		top--;
		return popVal;
	}
	void push(int val){
		if(isFull())
			return;
		top++;
		arr[top] = val;
	}
	int peek(){
		if(isEmpty())
			return -1;
		return arr[top];
	}
	void printStack(){
		if(isEmpty())
			return;
		for(int i = 0; i <= top; i++)
			printf("%d\t",arr[i]);
	}
};

stack span;
int count = 1;

void popAndCountSpan(stack& s, int temp){
	if(s.isEmpty())
		return;

	int pop = s.pop();
	if(pop < temp) {
		count++;
		popAndCountSpan(s,temp);
	}
	s.push(pop);
}

void insertSpan(stack& s, int temp){
	if(s.isEmpty() || s.peek() > temp)
	{
		span.push(count);
		s.push(temp);
		count = 1;
		return;
	}
	popAndCountSpan(s, temp);
	span.push(count);
	s.push(temp);
	count = 1;
}


void printStockSpan(stack& s){
	if(s.isEmpty())
		return;
	
	int temp = s.pop();
	printStockSpan(s);

	insertSpan(s, temp);
}

int _tmain(int argc, _TCHAR* argv[])
{
	stack s;

	int stockQuote[] = {10, 4, 5, 90, 120, 80};

	int arrLen = sizeof(stockQuote)/sizeof(stockQuote[0]);

	for(int i = 0; i < arrLen; i++){
		s.push(stockQuote[i]);
	}

	printStockSpan(s);

	printf("Stock Quotes:\n");
	s.printStack();

	printf("\n\nSpan Values:\n");
	span.printStack();

	return 0;
}

