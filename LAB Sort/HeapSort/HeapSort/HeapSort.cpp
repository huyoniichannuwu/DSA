// HeapSort.cpp

#include <iostream>
#include <string>
#include <math.h>
using namespace std;
void Swap(int& a, int& b);
void inputInt(string label, int& n);
void inputArr(int n, int array[]);
void printArr(int n, int array[]);
void heapify(int array[], int n, int i);
void heapSort(int array[], int n);
int main()
{
    int n;
    inputInt("n = ", n);
    int arr[1000];
    inputArr(n, arr);
    heapSort(arr, n);
    printArr(n, arr);

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
void printArr(int n, int array[]) {
    cout << "Mang sau khi sap xep (Heap Sort): " << endl;
    for (int index = 0; index < n; index++) {
        cout << array[index] << " ";
    }
}
void heapify(int array[], int n, int index) {
    int l = 2 * index + 1;  //left
    int r = 2 * index + 2; //right
    int largest = index;
    if (l < n && array[l] > array[largest]) {
        largest = l;
    }
    if (r < n && array[r] > array[largest]) {
        largest = r;
    }
    if (largest != index) {
        Swap(array[index], array[largest]);
        heapify(array, n, largest);
    }

}
void heapSort(int array[], int n) {
    //xay dung max heap
    for (int index = n / 2 - 1;index >= 0; index--) {
        heapify(array, n, index);
    }
    //chi so cuoi cung
    for (int index = n - 1; index >= 0; index--) {
        Swap(array[index], array[0]);
        heapify(array, index, 0);
    }
}