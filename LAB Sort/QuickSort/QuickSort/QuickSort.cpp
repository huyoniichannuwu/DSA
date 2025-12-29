// QuickSort.cpp

#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void Swap(int& a, int& b);
void inputInt(string label, int& n);
void inputArr(int n, int array[]);
void inputFile(int n, int array[],const char* filename);
int partition(int array[], int l, int r);
void quickSort(int array[], int l, int r);
void printArr(int n, int array[]);

int main()
{
    int n;
    inputInt("n = ", n);
    int* arr = new int[n];
    inputArr(n, arr);
    quickSort(arr, 0, n - 1);
    printArr(n, arr);
    
    cout << endl << endl << "Sort tu file 'Numbers.txt': " << endl;
    inputInt("n = ", n);
    int mang[10];
    inputFile(n, mang, "Numbers.txt");
    quickSort(mang, 0, n - 1);
    printArr(n, mang);

    delete[] arr;
    return 0;
}

void Swap(int& a, int& b) {
    int tmp = a;
    a = b;
    b = tmp;
}
void inputInt(string label, int& n) {
    cout << label; cin >> n;
}
void inputArr(int n, int array[]) {
    for (int index = 0; index < n; index++) {
        cin >> array[index];
    }
}
void inputFile(int n, int array[], const char* filename) {
    ifstream addFile("Numbers.txt");
    if (addFile.is_open()) {
        for (int index = 0; index < n; index++) {
            addFile >> array[index];
        }
        addFile.close();
    }
    else {
        cout<< endl << "Khong the mo file tren!" << endl;
    }
}
void printArr(int n, int array[]) {
    cout << "Mang sau khi sap xep (QuickSort - Lomuto): " << endl;
    for (int index = 0; index < n; index++) {
        cout << array[index] << " ";
    }
}
int partition(int array[], int l, int r) {
    //dat pivot
    int pivot = array[r];
    int index = l - 1;
    for (int jindex = l; jindex < r; jindex++) {
        if (array[jindex] <= pivot) {
            index = index + 1;
            Swap(array[index], array[jindex]);
        }
    }
    //dua pivot ve giua
    index = index + 1;
    Swap(array[index], array[r]);
    return index;
}
void quickSort(int array[], int l, int r) {
    if (l >= r) return;
    int p = partition(array, l, r);
    quickSort(array, l, p - 1);
    quickSort(array, p + 1, r);
}


