// LAB Sort.cpp

#include <iostream>
#include <fstream>
#include <math.h>
#include <string>
using namespace std;

void inputInt(string label, int& n);
void inputArr(int n, int array[]);
void inputFile(int &n, int arr[],const char* filename );
void Swap(int& a, int& b);
void SelectionSort(int n, int array[]);
void SelectionSortDescending(int n, int array[]);
void printArr(int n, int array[]);

int main() {
	int arr[10];
	int n;

	inputInt("n = ", n);
	inputArr(n, arr);
	SelectionSort(n, arr);
	printArr(n, arr);

	cout << endl << endl << "Sort tu file 'Numbers.txt' (Ascending): " << endl;
	inputInt("n = ", n);
	inputFile(n, arr, "Numbers.txt");
	SelectionSort(n, arr);
	printArr(n, arr);

	cout << endl << endl << "Sort tu file 'Numbers.txt' (Descending): " << endl;
	inputInt("n = ", n);
	inputFile(n, arr, "Numbers.txt");
	SelectionSortDescending(n, arr);
	printArr(n, arr);

	return 0;
}

void inputInt(string label, int& n) {
	cout << label; cin >> n;
}
void inputArr(int n, int array[]) {
	for (int index = 0; index < n; index++) {
		cin >> array[index];
	}
}
void inputFile(int &n, int arr[], const char* filename) {
	ifstream arrfile (filename);
	if (arrfile.is_open()) {
		for (int index = 0; index < n; index++) {
			arrfile >> arr[index];
		}
		arrfile.close();
	}
	else {
		cout << "Khong the mo file!" << endl;
	}
}
void Swap(int& a, int& b) {
	int tmp = a;
	a = b;
	b = tmp;
}
void SelectionSort(int n, int array[]) {
	for (int index = 0; index < n - 1; index++) {
		int min = index;
		//check remaining elements
		for (int jindex = index + 1; jindex < n; jindex++) {
			if (array[jindex] < array[min]) {
				min = jindex;
			}
		}
		if (min != index) {
			Swap(array[min], array[index]);
		}
	}
}
void SelectionSortDescending(int n, int array[]) {
	for (int index = 0; index < n - 1; index++) {
		int max = index;
		for (int jindex = index + 1; jindex < n; jindex++) {
			if (array[jindex] > array[max]) {
				max = jindex;
			}
		}
		if (max != index) {
			Swap(array[index], array[max]);
		}
	}
}
void printArr(int n, int array[]) {
	cout << "Mang sau khi sap xep: " << endl;
	for (int index = 0; index < n; index++) {
		cout << array[index] << " ";
	}
}