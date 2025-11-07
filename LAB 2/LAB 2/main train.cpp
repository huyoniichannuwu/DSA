#include "linkedList.h"
#include "Stack.h"
#include "Queue.h"

using namespace std;

bool Train(int n, int* arr) {
	Queue A;
	Stack B;
	Queue Ctarget;

	for (int index = 1; index <= n; index++) {
		A.enqueue(index);
	}

	for (int index = 0; index < n; index++) {
		Ctarget.enqueue(arr[index]);
	}

	//mo phong duong tau
	while (!Ctarget.isEmpty()) {
		bool moved = false;
		if (!A.isEmpty() && A.getHead()->getData() == Ctarget.getHead()->getData()) {
			int data = A.getHead()->getData();
			cout << "A -> C: " << data << endl;
			A.dequeue();
			Ctarget.dequeue();
			moved = true;
		}

		else if (!B.isEmpty() && B.getHead()->getData() == Ctarget.getHead()->getData()) {
			int data = B.getHead()->getData();
			cout << "B -> C: " << data <<endl;
			B.pop();
			Ctarget.dequeue();
			moved = true;
		}

		else if (!A.isEmpty()) {
			int data = A.getHead()->getData();
			cout << "A -> B: " << data << endl;
			int x = A.dequeue();
			B.push(x);
			moved = true;
		}

		if (!moved && !Ctarget.isEmpty()) {
			cout << "Khong the di chuyen tiep!" << endl;
			return false;
		}
	}
	return Ctarget.isEmpty();
}
void input_int(string label, int &n) {
	cout << label; cin >> n;
}
void input_arr(int n, int* arr) {
	cout << "Nhap mang output tau: ";
	for (int index = 0; index < n; index++) {
		cin >> arr[index];
	}
}

//int main() {
//	int n;
//	input_int("n = ", n);
//	int* target = new int[n];
//	input_arr(n, target);
//
//	cout << "\nQua trinh mo phong tau: \n";
//	bool result = Train(n, target);
//
//	cout << "\n~ Ket qua ~\n";
//	if (result) {
//		cout << "Co the thiet lap duong tau!";
//	}
//	else {
//		cout << "Khong the thiet lap duong tau!";
//	}
//
//
//	delete[]target;
//	return 0;
//}