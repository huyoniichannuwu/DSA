#pragma once
#include <iostream>

using namespace std;

class Node
{
private:
	Node* left;
	Node* right;
	Node* parent;
	//int bal; // -1 0 1 -2 2
	int key;
	int height;
public:
	Node();
	Node(int);
	~Node();

	Node* Getleft() { return this->left; }
	void Setleft(Node* val) {
		this->left = val;
	}

	Node* Getright() { return this->right; }
	void Setright(Node* val) {
		this->right = val;
	}

	Node* Getparent() { return this->parent; }
	void Setparent(Node* val) {
		this->parent = val;
	}

	int Getkey() { return this->key; }
	void Setkey(int val) {
		this->key = val;
	}

	int Getheight() { return this->height; }
	void Setheight(int val) {
		this->height = val;
	}

};

