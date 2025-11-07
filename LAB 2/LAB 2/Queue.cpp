#include "Queue.h"



Queue::Queue() {
	this->nNum = 0;
	this->linkedlist = new linkedList();
}
Queue::~Queue() {
	//DESTRUCTOR IS CALLED bel i sg
}

element* Queue::getHead() {
	return this->linkedlist->getHead();
}
 
//void Queue::enqueue(int x) {
//	element* p = new element(x);
//	this->linkedlist->insertFirst(p);
//}
//int Queue::dequeue() {
//	int p = this->linkedlist->getHead()->getData();
//	this->linkedlist->deleteTail();
//	return p;
//}

void Queue::enqueue(int x) {
	element* p = new element(x);
	this->linkedlist->insertTail(p);
}
int Queue::dequeue() {
	int p = this->linkedlist->getHead()->getData();
	this->linkedlist->deleteFirst();
	return p;
}
void Queue::printQueue() {
	if (this->linkedlist->getHead() == nullptr) {
		cout << "QUEUE RONG, KHONG LAY DUOC PHAN TU";
	}
	else {
		this->linkedlist->travel();
	}
}
bool Queue::isEmpty() {
	return this->linkedlist->isEmpty();
}

