// LAB hash table.cpp : This file contains the 'main' function. Program execution begins and ends there.
//Hash table (string)
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>
#include <math.h>

using namespace std;

void inputInt(string label, int& n);
int Hash(int k, int M);		//tim index
void InitHash(int *U, int M);
int main()
{
	int M = 7; //mang co 10ptu
	int *U = new int[M];	//cap phat dong mang U
	InitHash(U, M);

	int x;	//khoa
	inputInt("Nhap khoa tim kiem: ", x);
	int pos = Hash(x, M);

	if (U[pos] == x) {
		cout << "Tim thay gia tri key = " << x << ", value = " << U[pos]<< " tai vi tri (index) " << pos << endl;
	}
	else {
		cout << "Khong tim thay khoa " << x << " trong Hash Table" << endl;
	}
	delete[] U;
	return 0;
}
void InitHash(int* U, int M) {

	int n;
	do {
		cout << "Nhap n phan tu (n <= " << M << "): ";
		cin >> n;
	
	} while (n > M);

	cout << "Nhap gia tri ac phan tu: " << endl;
	for (int index = 0; index < n; index++) {
		int val;
		cout << "Phan tu thu " << index + 1 << " : ";
		cin >> val;

		//input

		int pos = Hash(val, M);

		//collision
		int startPos = pos;
		while (U[pos] != 0) {
			pos = (pos + 1) % M;
			if (pos == startPos) break;
		}

		if (U[pos] == 0) {
			U[pos] = val;
		}
		else {
			cout << "Warning: Bang da day, khong the them so " << val << endl;
		}
	}
}
int Hash(int k, int M) {
	if (M == 0) return 0;
	return k % M;
}
void inputInt(string label, int& n) {
	cout << label; cin >> n;
}