#pragma once
#include "linkedList.h"
class Stack
{
private:
	int nNum;
	linkedList* linkedlist;
public:
	Stack();				//constructor
	~Stack();		//destructor

	element* getHead();

	void push(int);			//them du lieu vao
	int pop();				//lay du lieu ra 
	void printStack();	
	bool isEmpty();
};

