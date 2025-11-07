#include "BST.h"

BST::BST() {
	this->root = nullptr;
}
BST::~BST() {
	//destructor is called
}
bool BST::InsertNode(Node* n) {
	Node* p = this->root;					//con tro chinh
	Node* subP = nullptr;					//con tro phu

	//dieu kien 1
	if (this->root == nullptr) {
		this->root = n;
		return true;
	}

	//dieu kien 2
	while (p != nullptr) {
		subP = p;
		if (n->Getkey() < p->Getkey()) {
			p = p->Getleft();
		}
		else if (n->Getkey() > p->Getkey()) {
			p = p->Getright();
		}
		else if (n->Getkey() == p->Getkey()) {		//hoac else
			//cout << "Trung element "<< n->Getkey()<< "!"<<endl;
			p->CountPlus();
			return false;
		}
	}
	//xet con tro subP
	if (n->Getkey() < subP->Getkey()) {
		subP->Setleft(n);
	}
	else {
		subP->Setright(n);
	}
	//set subP thanh parent cua n
	n->Setparent(subP);
	return true;
}
//Method 2
bool BST::InsertNodeII(Node* root, Node* p) {
	if (root == nullptr) {
		root = p;
	}
	if (root->Getkey() == p->Getkey()) {
		cout << "Trung element!";
		return false;
	}
	else if (root->Getkey() > p->Getkey())
		return InsertNodeII(root->Getleft(), p);
		else return InsertNodeII(root->Getright(), p);
}

//duyet tree 
// NLR:tien to
// LNR:trung to
// LRN:hau to
void BST::NLR(Node* val) {
	//tien to
	if (val == nullptr) {
		return;
	}
	cout << val->Getkey()<<endl;
	NLR(val->Getleft());
	NLR(val->Getright());
}
void BST::LNR(Node* val) {
	//trung to
	if (val == nullptr) {
		return;
	}
	LNR(val->Getleft());
	cout << val->Getkey() << endl;
	LNR(val->Getright());
}
void BST::LRN(Node* val) {
	//hau to
	if (val == nullptr) {
		return;
	}
	LRN(val->Getleft());
	LRN(val->Getright());
	cout << val->Getkey()<<endl;
}
void BST::DeleteNode(Node* n) {
	Node* p = n;			//con tro phu.
	//I:leaf
	if (n->Getleft() == nullptr && n->Getright() == nullptr) {
		//B1: dat ten cha P
		Node* P = n->Getparent();
		//TH1: Root
		if (P == nullptr) {
			this->root = nullptr;
			return;
		}
		//TH2: con trai'
		else if (P->Getleft() == n) {
			P->Setleft(nullptr);
			return;
		}
		//TH3: con phai
		else if (P->Getright() == n) {
			P->Setright(nullptr);
			return;
		}
		delete n;
	}
	//II
	else if (p->Getright() != nullptr && p->Getleft() != nullptr) {
		p = p->Getright();
		while (p->Getleft() != nullptr) {
			p = p->Getleft();				// SUCCESSOR
		}
		n->Setkey(p->Getkey());				//1.DAT GIA TRI n THANH p (p dang la SUCCESSOR)

		Node* S = p;						//2.DAT S, P_S, C_S
		Node* ParentS = S->Getparent();
		Node* ChildS = S->Getright();		//neu co them getleft thi 0 la successor

		//3.Ngat lien ket P_S == S, noi P_S -> C_S
		if (ParentS->Getleft() == S) {
			ParentS->Setleft(ChildS);
		}
		else {
			ParentS->Setright(ChildS);
		}
		//4.cap nhat con tro parent cua childS
		if (ChildS != nullptr) {
			ChildS->Setparent(ParentS);
		}
		delete S;
	}
	//III
	else {
		//con duy nhat ( trai hoac phai )
		Node* C = (n->Getleft() != nullptr) ? n->Getleft() : n->Getright();
		Node* P = n->Getparent();

		if (P == nullptr) {
			this->root = C;			//doi this->root phan tu con tiep theo
		}
		else if (P->Getleft() == n) {
			P->Setleft(C);
		}
		else {
			P->Setright(C);
		}

		C->Setparent(P);
		delete n;
	}
	return;
}

//hien ra tree ( Travel )
void BST::TravelNLR() {
	NLR(this->root);
}
void BST::TravelLNR() {
	LNR(this->root);
}
void BST::TravelLRN() {
	LRN(this->root);
}

Node* BST::searchX(int k) {
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
int BST::Min() {
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
int BST::Max() {
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
int BST::SumtreeDequy(Node* val) {
	int total = 0;
	if (val == nullptr) {
		return 0;
	}
	total = val->Getkey() + SumtreeDequy(val->Getleft()) + SumtreeDequy(val->Getright());
	return total;
}
int BST::SumTree() {
	return SumtreeDequy(this->root);
}

int BST::CountNodeDequy(Node* val) {
	int count;
	if (val == nullptr) {
		return 0;
	}
	count = 1 + CountNodeDequy(val->Getleft()) + CountNodeDequy(val->Getright());
	return count;
}
int BST::CountNode() {
	return CountNodeDequy(this->root);
}

int BST::TreeHeight(Node* val) {
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

void BST::printAppeared(Node* val) {
	if (val == nullptr) {
		cout << "Cay rong!" << endl;
		return;
	}
	printAppeared(val->Getleft());
	cout << val->Getkey() << " da xuat hien " << val->Getcount() << " lan" << endl;
	printAppeared(val->Getright());
}

bool BST::isPrime(Node* val) {
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

int BST::countPrime(Node* val) {
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

int BST::countNodeonLevel(Node*val, int level) {
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



//LUYEN TAP


int BST::TreeHeightpratice(Node* val) {
	if (val == nullptr) {
		//cout << "Cay rong!" << endl;
		return 0;
	}
	//val => currentNode
	int leftHeight = TreeHeightpratice(val->Getleft());
	int rightHeight = TreeHeightpratice(val->Getright());
	int bigger;

	/*if (leftHeight > rightHeight) {
		bigger = leftHeight;
	}
	else {
		bigger = rightHeight;
	}*/
	bigger = (leftHeight > rightHeight) ? leftHeight : rightHeight;
	return  1 + bigger;
}	

int BST::countNodeLevelpractice(Node* val, int level) {
	int totalCount = 0;
	if (val == nullptr) {
		return 0;
	}

	if (level == 1) {
		return totalCount = 1;
	}
	int leftNode = countNodeLevelpractice(val->Getleft(), level - 1);
	int rightNode = countNodeLevelpractice(val->Getright(), level - 1);
	return leftNode + rightNode;
}
int BST::CountNodepractice(Node* value) {
	int totalNode = 0;

	if (value == nullptr) {
		return 0;
	}
	int currentNode = 1;	//this->root
	totalNode = currentNode + CountNodepractice(value->Getleft()) + CountNodepractice(value->Getright());

	return totalNode;
}