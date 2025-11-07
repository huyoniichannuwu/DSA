#include "Node.h"
Node::Node() {
	this->key = 0;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}
Node::Node(int x) {
	this->key = x;
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
}
Node::~Node() {
	//Destructor is called
}