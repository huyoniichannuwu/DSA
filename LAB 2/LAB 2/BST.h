#pragma once
#include "Node.h"
#include <math.h>

class BST
{
private:
	Node* root;
public:
	BST();
	~BST();

	Node* Getroot() {
		return this->root;
	}
	void Setroot(Node* r) {
		this->root = r;
	}

	bool InsertNode(Node*);
	bool InsertNodeII(Node*, Node*);
	void DeleteNode(Node*);
	void printAppeared(Node*);

	void TravelNLR();
	void TravelLNR();
	void TravelLRN();

	void NLR(Node*);
	void LNR(Node*);
	void LRN(Node*);

	Node* searchX(int);		//*
	int Min();
	int Max();
	int SumtreeDequy(Node*);
	int CountNodeDequy(Node*);
	int SumTree();
	int CountNode();
	int TreeHeight(Node*);
	
	//8,9
	bool isPrime(Node*);
	int countPrime(Node*);

	int countNodeonLevel(Node*, int);
	
	
	
	int countNodeLevelpractice(Node*, int);
	int TreeHeightpratice(Node*);
	int CountNodepractice(Node*);
};

