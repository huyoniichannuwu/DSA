#include "AVL.h"
AVL::AVL() {
	this->root = nullptr;
	this->num = 0;
	this->height = 0;
}
AVL::~AVL() {
	//destructor is called
}

//QUAN TRONG
bool AVL::InsertNode(Node* val) {
	Node* p = this->root;
	Node* T = nullptr;

	if (this->root == nullptr) {
		this->root = val;
		return true;
	}

	while (p != nullptr) {
		T = p;
		if (p->Getkey() > val->Getkey()) {
			p = p->Getleft();
		}
		else if (p->Getkey() < val->Getkey()) {
			p = p->Getright();
		}
		else {
			cout << "trung element!";
			return false;
		}
	}

	if (T->Getkey() > val->Getkey()) {
		T->Setleft(val);
	}
	else {
		T->Setright(val);
	}

	val->Setparent(T);
	return true;

	//tiep tuc logic AVL tree
	Node* x = val;
	Node* parentX = x->Getparent();

	while (x != nullptr) {
		int balance = this->CheckBalance(x);

		switch (balance) {
		case 0:
			break;
		case 1:
			break;
		case -1:
			break;
		case 2:
		{
			Node* new_root_after_rotation = nullptr;
			if (this->CheckBalance(x->Getleft()) >= 0) {
				parentX = x->Getparent();
				Node* y = x->Getleft();

				this->RightRotate(x);

				y->Setparent(parentX);
				if (parentX != nullptr) {
					if (y->Getkey() > parentX->Getkey())
						parentX->Setright(y);
					else parentX->Setleft(y);
				}
				new_root_after_rotation = y;
			}

			else // Left-Right (BF của con trái < 0)
			{
				// Xử lý LR 
				Node* y = x->Getleft();
				this->LeftRotate(y); // Quay Trái tại Y

				parentX = x->Getparent();
				Node* new_root = x->Getleft(); // Nút gốc mới sau quay

				this->RightRotate(x); // Quay Phải tại Z (x)

				// Cập nhật liên kết
				new_root->Setparent(parentX);
				if (parentX != nullptr) {
					if (new_root->Getkey() > parentX->Getkey())
						parentX->Setright(new_root);
					else parentX->Setleft(new_root);
				}
				new_root_after_rotation = new_root;
			}

			if (parentX == nullptr)
				this->root = new_root_after_rotation;
			return true;
		}
		case -2:
		{
			Node* new_root_after_rotation = nullptr;
			if (this->CheckBalance(x->Getright()) <= 0) // RIGHT-RIGHT (BF của con phải <= 0)
			{
				// Xử lý RR (Quay đơn Trái)
				parentX = x->Getparent();
				Node* y = x->Getright(); // Nút gốc mới sau quay

				this->LeftRotate(x);

				// Cập nhật liên kết
				y->Setparent(parentX);
				if (parentX != nullptr) {
					if (y->Getkey() > parentX->Getkey())
						parentX->Setright(y);
					else parentX->Setleft(y);
				}
				new_root_after_rotation = y;
			}

			else // Right-Left (BF của con phải > 0)
			{
				// Xử lý RL (Quay kép: Phải tại Y, sau đó Trái tại Z)
				Node* y = x->Getright();
				this->RightRotate(y); // Quay Phải tại Y

				parentX = x->Getparent();
				Node* new_root = x->Getright(); // Nút gốc mới sau quay

				this->LeftRotate(x); // Quay Trái tại Z (x)

				// Cập nhật liên kết
				new_root->Setparent(parentX);
				if (parentX != nullptr) {
					if (new_root->Getkey() > parentX->Getkey())
						parentX->Setright(new_root);
					else parentX->Setleft(new_root);
				}
				new_root_after_rotation = new_root;
			}

			if (parentX == nullptr) {
				this->root = new_root_after_rotation;
			}
			return true;
			break;
		}

		// Nếu không có phép quay, đi lên nút cha
		x = x->Getparent();
		}
		return true;
	}
}

void AVL::LeftRotate(Node*& P) {
	Node* Q;
	Node* T;
	Q = P->Getright();
	T = Q->Getleft();

	Q->Setleft(P);
	P->Setright(T);

	P->Setparent(Q);

	if (T != nullptr) {
		T->Setparent(P);
	}
	P = Q;
}
void AVL::RightRotate(Node*& P) {
	Node* Q;
	Node* T;

	Q = P->Getleft();	
	T = Q->Getright();

	Q->Setright(P);
	P->Setleft(T);

	P->Setparent(Q);
	if (T != nullptr) {
		T->Setparent(P);
	}
	P = Q ;
}

int AVL::CheckBalance(Node* p) {
	int bal = this->TreeHeight(p->Getleft()) - this->TreeHeight(p->Getright());
	return bal;
}
//duyet tree 
// NLR:tien to
// LNR:trung to
// LRN:hau to
void AVL::NLR(Node* val) {
	//tien to
	if (val == nullptr) {
		return;
	}
	cout << val->Getkey() << endl;
	NLR(val->Getleft());
	NLR(val->Getright());
}
void AVL::LNR(Node* val) {
	//trung to
	if (val == nullptr) {
		return;
	}
	LNR(val->Getleft());
	cout << val->Getkey() << endl;
	LNR(val->Getright());
}
void AVL::LRN(Node* val) {
	//hau to
	if (val == nullptr) {
		return;
	}
	LRN(val->Getleft());
	LRN(val->Getright());
	cout << val->Getkey() << endl;
}
//hien ra tree ( Travel )
void AVL::TravelNLR() {
	NLR(this->root);
}
void AVL::TravelLNR() {
	LNR(this->root);
}
void AVL::TravelLRN() {
	LRN(this->root);
}

Node* AVL::searchX(int k) {
	Node* currentNode = this->root;
	Node* subNode = nullptr;
	if (currentNode == nullptr) {
		cout << "Cay rong!" << endl;
		return 0;
	}

	while (currentNode != nullptr) {
		if (k == currentNode->Getkey()) {
			return currentNode;
		}
		else if (k < currentNode->Getkey()) {
			currentNode = currentNode->Getleft();
		}
		else if (k > currentNode->Getkey()) {
			currentNode = currentNode->Getright();
		}
	}
	return nullptr;
}
int AVL::Min() {
	//nho nhat, lay phan tu ngoai cung ben trai
	Node* currentNode = this->root;

	if (currentNode == nullptr) {
		cout << "Cay rong!" << endl;
		return 0;
	}
	while (currentNode->Getleft() != nullptr) {		//lap den cuoi trai'
		currentNode = currentNode->Getleft();
	}
	return currentNode->Getkey();
}
int AVL::Max() {
	Node* currentNode = this->root;
	if (currentNode == nullptr) {
		cout << "Cay rong!" << endl;
		return 0;
	}
	while (currentNode->Getright() != nullptr) {
		currentNode = currentNode->Getright();
	}
	return currentNode->Getkey();
}
int AVL::SumtreeDequy(Node* val) {
	int total = 0;
	if (val == nullptr) {
		return 0;
	}
	total = val->Getkey() + SumtreeDequy(val->Getleft()) + SumtreeDequy(val->Getright());
	return total;
}
int AVL::SumTree() {
	return SumtreeDequy(this->root);
}

int AVL::CountNodeDequy(Node* val) {
	int count;
	if (val == nullptr) {
		return 0;
	}
	count = 1 + CountNodeDequy(val->Getleft()) + CountNodeDequy(val->Getright());
	return count;
}
int AVL::CountNode() {
	return CountNodeDequy(this->root);
}

int AVL::TreeHeight(Node* val) {
	if (val == nullptr) {
		//cout << "Cay rong!" << endl;
		return 0;
	}
	//de quy
	int leftH = TreeHeight(val->Getleft());
	int rightH = TreeHeight(val->Getright());
	int bigger;

	if (leftH > rightH) {
		bigger = leftH;
	}
	else {
		bigger = rightH;
	}

	return 1 + bigger;
}

bool AVL::isPrime(Node* val) {
	if (val->Getkey() == 0 || val->Getkey() == 1) {
		return false;
	}
	for (int index = 2; index <= sqrt(val->Getkey()); index++) {
		if (val->Getkey() % index == 0) {
			return false;
		}
	}
	return true;
}

int AVL::countPrime(Node* val) {
	int totalCount = 0;
	if (val == nullptr) {
		return 0;
	}
	int currentCount;
	if (isPrime(val)) {
		currentCount = 1;
	}
	else {
		currentCount = 0;
	}

	int leftPrime = countPrime(val->Getleft());
	int rightPrime = countPrime(val->Getright());

	totalCount = currentCount + leftPrime + rightPrime;
	return totalCount;
}

int AVL ::countNodeonLevel(Node* val, int level) {
	int totalCount = 0;
	if (val == nullptr) {
		return 0;
	}
	if (level == 1) {
		totalCount = 1;
	}

	int leftNCount = countNodeonLevel(val->Getleft(), level - 1);
	int rightNCount = countNodeonLevel(val->Getright(), level - 1);
	totalCount = leftNCount + rightNCount;

	return totalCount;
}