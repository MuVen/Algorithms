// 27 - Implement Queue Using Stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"

#include<stdio.h>
#include<stdlib.h>

class stack{
	int top;
	int arr[5];
public:
	stack(){
		top = -1;
	}
	bool isFull(){
		if(top == 4)
			return true;
		return false;
	}
	bool isEmpty(){
		if(top == -1)
			return true;
		return false;
	}
	void push(int data){
		if(isFull()){
			printf("Stack Overflow\n");
			return;
		}
		top++;
		arr[top] = data;
	}
	int pop(){
		if(isEmpty()) {
			printf("Stack Underflow\n");
			return -1;
		}
		int val = arr[top];
		top--;
		return val;
	}
};

class queue{
	stack newStack,oldStack;
public:
	void shiftStacks(){
		if(oldStack.isEmpty()){
			while(!newStack.isEmpty())
				oldStack.push(newStack.pop());
		}
	}
	void enQueue(int d){
		newStack.push(d);
	}
	int deQueue(){
        shiftStacks();
		return oldStack.pop();
	}
};

int _tmain(int argc, _TCHAR* argv[])
{
	queue q;
	q.enQueue(1);
    q.enQueue(2);
    q.enQueue(3);
	q.enQueue(4);
    q.enQueue(5);

	printf("%d\t",q.deQueue());
	printf("%d\t",q.deQueue());
	printf("%d\t",q.deQueue());
	printf("%d\t",q.deQueue());
	printf("%d\t",q.deQueue());

	q.enQueue(6);
    q.enQueue(7);
    q.enQueue(8);
	q.enQueue(9);
    q.enQueue(0);

	printf("%d\t",q.deQueue());
	printf("%d\t",q.deQueue());
	printf("%d\t",q.deQueue());
	printf("%d\t",q.deQueue());
	printf("%d\t",q.deQueue());

    getchar();
	return 0;
}

