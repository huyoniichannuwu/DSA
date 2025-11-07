#pragma once
#include "element.h"
class linkedList
{ 
private:
	element *head;
	element *tail;
	int num;

public:
	linkedList();
	~linkedList();

	//get/set
	element* getHead() { return this->head; }
	void* setHead(element* value) { this->head = value; }

	element* getTail() { return this->tail;}
	void* setTail(element* value) { this->tail = value; }

	//insert
	void insertFirst(element*);
	void insertTail(element*);
	
	bool insertP(element*, element*);
	bool insertP2(element*, element*);				//btvn
	//delete
	bool deleteFirst();
	bool deleteTail();
	bool deleteP(element*);							//btvn
	//travel
	void travel();
	
	bool isEmpty();

	
	//btvn
	int SumList();
	int MaxList();
	int MinList();

	bool isPrime(int n);
	int countPrime();
	
	bool isAppeared(element*, element*);
	int countDuplicates();

	//lay danh sach ko co phan tu lap
	bool isExist(int data);
	bool khonglap(element*);
};