#include <iostream>
#include <algorithm> 
using namespace std;

#define MAX 1000 

int b[MAX], c[MAX], nb, nc;

void Distribute(int a[], int N, int& nb, int& nc, int k) {
    int i, pa, pb, pc;
    pa = pb = pc = 0;
    while (pa < N) {
        // Chép k phần tử vào b
        for (i = 0; (pa < N) && (i < k); i++, pa++, pb++) {
            b[pb] = a[pa];
        }
        // Chép k phần tử tiếp theo vào c
        for (i = 0; (pa < N) && (i < k); i++, pa++, pc++) {
            c[pc] = a[pa];
        }
    }
    nb = pb; //b
    nc = pc; //c
}


void MergeSubarr(int a[], int nb, int nc, int& pa, int& pb, int& pc, int k) {
    int rb, rc;
    // Tính giới hạn (biên) của lần trộn này
    rb = min(nb, pb + k);
    rc = min(nc, pc + k);

    // So sánh và trộn
    while ((pb < rb) && (pc < rc)) {
        if (b[pb] < c[pc])
            a[pa++] = b[pb++];
        else
            a[pa++] = c[pc++];
    }

    while (pb < rb) {
        a[pa++] = b[pb++];
    }
    while (pc < rc) {
        a[pa++] = c[pc++];
    }
}

// 3. Hàm quản lý việc trộn toàn bộ b và c
void Merge(int a[], int nb, int nc, int k) {
    int pa, pb, pc;
    pa = pb = pc = 0;

    // Lần lượt trộn từng cặp cụm kích thước k
    while ((pb < nb) && (pc < nc)) {
        MergeSubarr(a, nb, nc, pa, pb, pc, k);
    }

    // Chép nốt các phần tử còn lại (nếu b hoặc c còn dư nguyên cụm)
    while (pb < nb) {
        a[pa++] = b[pb++];
    }
    while (pc < nc) {
        a[pa++] = c[pc++];
    }
}

// 4. Hàm chính thực hiện thuật toán
void MergeSort(int a[], int N) {
    int k = 1; // Bắt đầu với các mảng con kích thước 1
    while (k < N) {
        Distribute(a, N, nb, nc, k); // Chia a ra b và c
        Merge(a, nb, nc, k);         // Trộn b và c lại vào a
        k *= 2;                      // Tăng gấp đôi kích thước mảng con
    }
}


void InputInt(int& n) {
    cout << "Nhap so phan tu n: ";
    cin >> n;
}
void InputArr(int n, int arr[]) {
    for (int index = 0; index < n; index++) {
        cin >> arr[index];
    }
}

void PrintArr(int n, int a[]) {
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;
}

int main()
{
    int n;
    int arr[MAX];
    InputInt(n);
    InputArr(n, arr);
    MergeSort(arr, n);
    cout << "Mang sau khi sap xep (Merge Sort): "<<endl;
    PrintArr(n, arr);

    return 0;
}