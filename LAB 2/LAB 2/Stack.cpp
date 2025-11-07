#include "Stack.h"

Stack::Stack() {
	this->nNum = 0;
	this->linkedlist = new linkedList();
}
Stack::~Stack() {
	//destructor is called
}

element* Stack::getHead() {
	return this->linkedlist->getHead();
}


void Stack::push(int x) {
	element* p = new element(x);
	this->linkedlist->insertFirst(p);
}
int Stack::pop() {
	int p = this->linkedlist->getHead()->getData();
	this->linkedlist->deleteFirst();
	return p;
}

//void Stack::push(int x) {
//	element* p = new element(x);
//	this->linkedlist->insertTail(p);
//}
//int Stack::pop() {
//	int p = this->linkedlist->getHead()->getData();
//	this->linkedlist->deleteTail();
//	return p;
//}

void Stack::printStack() {
	if (this->linkedlist->getHead() == nullptr) {
		cout << "STACK RONG, KHONG LAY DUOC PHAN TU";
	}
	else {
		this->linkedlist->travel();
	}
}

bool Stack::isEmpty() {
	return this->linkedlist->isEmpty();
}



