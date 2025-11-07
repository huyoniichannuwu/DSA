#include "linkedList.h"
#include "element.h"

//add phan tu dau -> co 3 cach
//insertFirst: dau con tro
//insertTail: cuoi con tro
//insertP: tao phan tu sau p 
linkedList::linkedList() {
	this->head = nullptr;
	this->tail = nullptr;
	this->num = 0;
}
linkedList::~linkedList() {

}
void linkedList::insertFirst(element* e) {
	if (this->head == nullptr) {
		this->head = this->tail = e;
	}
	else {
		e->setPointer(this->head);
		this->head = e;
	}
	this->num++;
}
void linkedList::insertTail(element* e) {
	if (this->tail == nullptr) {
		this->tail = this->head = e;
	}
	
	//e->setPointer(this->tail); (SAI)
	this->tail->setPointer(e);
	this->tail = e;
	this->num++;
}

bool linkedList::insertP(element*e,element* newe) {
	if (newe == nullptr) {
		return false;
	}
	else {
		e->setPointer(newe ->getPointer());
		newe->setPointer(e);
	}
	return true;
}

//cach 2
bool linkedList::insertP2(element* e, element* newe) {
	if (e == nullptr || newe == nullptr) {
		return false;
	}
	//phan tu e tro den phan tu ma newe dang tro toi (sau newe)
	e->setPointer(newe->getPointer());
	newe->setPointer(e);

	if (this->tail = newe) {
		this->tail = e;
	}
	this->num++;
	
	return true;
}

bool linkedList::deleteFirst() {
	if (this->head == nullptr) return false;
	else {
		//1
		element* p = this->head;
		//2
		this->head = this->head->getPointer();
		//3
		delete p;
		return true;
		}
}

bool linkedList::deleteTail() {
	if (this->head == nullptr) return false;
	
	element* tmp = this->tail;

	//neu array co 1 phan tu
	if (this->head == this->tail) {
		this->head = nullptr;
		this->tail = nullptr;
		delete tmp;
		this->num--;
		return true;
	}

	//tu 2 ptu tro len
	//tao con tro duyet
	element* p = this->head;
	//duyet
	while (p->getPointer() != this->tail) {
		p = p->getPointer();
	}
	this->tail = p;
	this->tail->setPointer(nullptr);
	delete tmp;
	this->num--;
	return true;
}

bool linkedList::deleteP(element* p) {
	if (p == nullptr) {
		return false;
	}

	//if (p == this->head) {							//deleteFirst()
	//	element* temp = this->head;
	//	this->head = this->head->getPointer();
	//	delete temp;
	//	return true;
	//}
	if (p == this->head) {
		return deleteFirst();
	}

	element* p_before = this->head;
	while (p_before != nullptr && p_before->getPointer() != p) {
		p_before = p_before->getPointer();
	}

	if (p_before == nullptr) {
		return false;
	}
	p_before->setPointer(p->getPointer());

	delete p;
	this->num--;
	return true;
}

//9.
bool linkedList::isAppeared(element* head, element*end) {
	element* p = this->head;

	while (p != end) {
		if (p->getData() == end->getData()) {
			return true;
		}
		p = p->getPointer();
	}
	return false;
}
int linkedList::countDuplicates() {
	if (this->head == nullptr) {
		return 0;
	}
	int totalDuplicates = 0;
	element* current = this->head;		//vong lap ngoai

	while (current != nullptr) {
		if (!isAppeared(this->head, current)) {
			int frequency = 0;
			element* tmp = this->head;		//duyet lai (vong lap trong)
			while (tmp != nullptr) {
				if (tmp->getData() == current->getData()) {
					frequency++;
				}
				tmp = tmp->getPointer();
			}
			if (frequency > 1) {
				totalDuplicates += (frequency - 1);
			}
		}
		current = current->getPointer();
	}
	return totalDuplicates;
}

bool linkedList::isExist(int data) {
	element* p = this->head;
	while (p != nullptr) {
		if (p->getData() == data) {
			return true;
		}
		p = p->getPointer();
	}
	return false;
}

bool linkedList::khonglap(element* p) {
	//ghi insertTail
	if (p == nullptr) {
		return false;
	}
	//kiem tra xem ton tai gia tri ?
	if (this->isExist(p->getData())) {
		//cout << "Gia tri " << p->getData() << " da ton tai" << endl;
		delete p;
		return false;
	}	
	//neu chua ton tai insert nhu binh thuong
	if (this->tail == nullptr) {
		this->tail = this->head = p;
	}
	else {
		this->tail->setPointer(p);
		this->tail = p;
	}
	this->num++;
	return true;


}

//Hien ra ARRAY
void linkedList::travel() {
	element* p = this->head;
	while (p != nullptr) {
		cout << p->getData() << "\t";
		p = p->getPointer();
	}
}

bool linkedList::isEmpty() {
	return this->head == nullptr;
}

int linkedList::SumList() {
	int total = 0;
	element* p = this->head;
	while (p != nullptr) {
		total += p->getData();
		p = p->getPointer();
	}
	return total;
}

int linkedList::MaxList() {
	if (this->head == nullptr) {
		return 0;
	}

	int maxValue = this->head->getData();
	element* p = this->head->getPointer();
	while (p != nullptr) {
		if (p->getData() > maxValue) {
			maxValue = p->getData();
		}
		p = p->getPointer();
	}
	return maxValue;
}

int linkedList::MinList() {
	if (this->head == nullptr) {
		return 0;
	}
	int minValue = this->head->getData();
	element* p = this->head->getPointer();

	while (p != nullptr) {
		if (p->getData() < minValue) {
			minValue = p->getData();
		}
		p = p->getPointer();
	}
	return minValue;
}

bool linkedList::isPrime(int n) {
	if (n <= 1) return false;			//1 chi co uoc chung la chinh no

	if (n == 2) return true;

	if (n > 2) {
		for (int index = 2; index <= sqrt(n); index++) {
			if (n % index == 0) {
				return false;
			}
		}
		return true;
	}
}

int linkedList::countPrime() {
	int totalPrime = 0;
	element* p = this->head;
	while (p != nullptr) {
		if (isPrime(p->getData())) {
			totalPrime++;
		}
		p = p->getPointer();
	}
	return totalPrime;
}


