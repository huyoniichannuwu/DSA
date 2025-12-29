//// LAB hash table.cpp : This file contains the 'main' function. Program execution begins and ends there.
////Hash table (string)
//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <string>
//#include <cstring>
//#include <math.h>
//
//using namespace std;
//
//struct Word {
//	int key;
//	char value[128];
//};
//
//void inputInt(string label, int& n);
//int Hash(int k, int M);		//tim index
//void InitHash(Word* &U, int M);
//int main()
//{
//	int M = 10; //10ptu
//	Word* U = new Word[M];	//cap phat dong mang U
//	InitHash(U, M);
//	
//	int x;	//khoa
//	inputInt("Nhap khoa tim kiem: ", x);
//	int pos = Hash(x, M);
//
//	if (U[pos].key == x) {
//		cout << "Tim thay gia tri key = " << x << ", value = " << U[pos].value<< " tai vi tri (index) "<< pos << endl;
//	}
//	else {
//		cout << "Khong tim thay khoa " << x << " trong Hash Table" << endl;
//	}
//	delete[] U;
//	return 0;
//}
//void inputInt(string label, int& n) {
//	cout << label; cin >> n;
//}
//
//int Hash(int k, int M) {
//	if (M == 0) return 0;
//	return k % M;
//}
//
//void InitHash(Word* &U, int M) {
//	/*int n;
//	inputInt("Nhap n phan tu trong arr: ", n);
//	int* arr = new int [n];
//
//	for (int index = 0; index < n; index++) {
//		cin >> arr[index];
//	}*/
//
//	Word K[5];
//	K[0].key = 1;
//	strcpy(K[0].value, "Messi");
//
//	K[1].key = 3;
//	strcpy(K[1].value, "Ronaldo");
//	
//	K[2].key = 13;
//	strcpy(K[2].value, "Rooney");
//
//	K[3].key = 7;
//	strcpy(K[3].value, "Drogba");
//
//	K[4].key = 9;
//	strcpy(K[4].value, "Xavi");
//
//	for (int index = 0; index < M; index++) {
//		U[index].key = 0;
//	}
//	//input
//	for (int index = 0; index < 5; index++) {
//		int pos = Hash(K[index].key, M);
//		//collision
//		while (U[pos].key != 0) {
//			pos = (pos + 1) % M;
//		}
//		
//		U[pos] = K[index];
//	}
//}
