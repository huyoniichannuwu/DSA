#include "Node.h"
Node::Node() {
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->key = 0;
	this->height = 0;
}
Node::Node(int k) {
	this->left = nullptr;
	this->right = nullptr;
	this->parent = nullptr;
	this->key = k;
	this->height = 0;
}
Node::~Node() {
	//destructor is called
}