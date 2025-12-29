#pragma once
#include "Node.h"

using namespace std;
class AVL
{
private:
	Node* root;
	int num;
	int height;
public:
	//constructor and destructor
	AVL();
	~AVL();

	Node* Getroot() {
		return this->root;
	}
	void Setroot(Node* val) {
		this->root = val;
	}

	bool InsertNode(Node*);
	//bool InsertNodeII(Node*, Node*);
	void DeleteNode(Node*);

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
//logic AVL
	void LeftRotate(Node*&);
	void RightRotate(Node*&);
	int CheckBalance(Node*);


	//8,9
	bool isPrime(Node*);
	int countPrime(Node*);
	int countNodeonLevel(Node*, int);


};

