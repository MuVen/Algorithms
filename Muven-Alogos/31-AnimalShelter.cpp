// AnimalShelter.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string.h>

#define MAX 5

class queue {
   char aName[MAX][50];
   int arr[MAX];
   int rear, front;
public:
	queue(){
		rear = -1;
		front = 0;
	}

	bool isFull(){
		if(rear == MAX-1)
			return true;
		return false;
	}

	bool isEmpty(){
		if(rear == -1)
			return true;
		return false;
	}

	void enqueue(int val, char* tname){
		if(isFull())
			return;
		rear++;
		strcpy(aName[rear],tname);
		arr[rear] = val;
	}

	void dequeue(char* name, int& temp) {
		if(front == rear){
			temp = arr[front];
			strcpy(name,aName[front]);
			front = 0;
			rear = -1;
		}
		temp = arr[front];
		strcpy(name,aName[front]);
		front++;
	}

	int Order(){
		return arr[front];
	}
};

class animalShelter{
	queue dogs;
	queue cats;
	int count;

public:
	animalShelter(){
		count = 0;
	}

	void dequeueAny(char* name, int& temp){
		if(dogs.isEmpty() && cats.isEmpty()){
			printf("No Animal in the Shelter\n");
			return;
		}
        
		int orderDog = dogs.Order();
		int orderCat = cats.Order();

		if(orderDog < orderCat){
			dequeueDog(name, temp);
		}else {
			dequeueCat(name, temp);
		}
	}

	void queueDog(char* name){
		dogs.enqueue(++count, name); 
	}
	void queueCat(char* name){
		cats.enqueue(++count, name);
	}
	void dequeueDog(char* aName, int& temp){
		dogs.dequeue(aName, temp);
	}
	void dequeueCat(char* aName, int& temp){
        cats.dequeue(aName, temp);
	}
};
int _tmain(int argc, _TCHAR* argv[])
{
	animalShelter as;
	
	as.queueDog("Tommy");
    as.queueDog("Puppy");
	as.queueDog("Brownie");

	as.queueCat("Lilly");
	as.queueCat("Blacky");
	as.queueCat("Tiny");


	char name[50]; int order;

	as.dequeueDog(name, order);
	printf("Dequeued Dog %s:%d\n",name,order);

	as.dequeueCat(name, order);
	printf("Dequeued Cat %s:%d\n",name,order);

	as.dequeueAny(name, order);
    printf("Dequeued Animal %s:%d\n",name,order);

	as.queueDog("Chinky");
    as.queueCat("Floppy");

	as.dequeueAny(name, order);
    printf("Dequeued Animal %s:%d\n",name,order);

	as.dequeueAny(name, order);
    printf("Dequeued Animal %s:%d\n",name,order);

	return 0;
}

