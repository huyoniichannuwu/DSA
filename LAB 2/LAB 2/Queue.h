#pragma once
#include "linkedList.h"

class Queue
{
private:
	int nNum;
	linkedList* linkedlist;
public:
	Queue();
	~Queue();

	element* getHead();

	void enqueue(int);
	int dequeue();
	void printQueue();
	bool isEmpty();

};

