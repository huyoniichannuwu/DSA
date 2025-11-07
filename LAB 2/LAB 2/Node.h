#pragma once
#include <iostream>
using namespace std;

class Node
{
private:
	Node* left;
	Node* right;
	Node* parent;
	int key;
	int appearedCount = 1;
public:
	Node();
	Node(int);
	~Node();

	Node* Getleft() {
		return this->left;
	}
	void Setleft(Node* l) {
		this->left = l;
	}
	Node* Getright() {
		return this->right;
	}
	void Setright(Node* r) {
		this->right = r;
	}
	Node* Getparent() {
		return this->parent;
	}
	void Setparent(Node* p) {
		this->parent = p;
	}
	int Getkey() {
		return this->key;
	}
	void Setkey(int k) {
		this->key = k;
	}

	int Getcount() {
		return this->appearedCount;
	}
	void CountPlus() {
		this->appearedCount++;
	}


};

