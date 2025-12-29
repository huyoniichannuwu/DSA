#include "AVL.h" // Bao gồm lớp AVL
#include "Node.h" // Bao gồm lớp Node
#include <iostream>
#include <vector>
#include <string>
#include <cmath> // Cần cho hàm sqrt() trong countPrime

using namespace std;

// Hàm tiện ích để in cây LNR (Inorder Traversal - Dạng đã sắp xếp)
void PrintTreeLNR(AVL& tree) {
    cout << "\n--- Duyet Cay (LNR - Trung To) ---" << endl;
    tree.TravelLNR();
    cout << "---------------------------------" << endl;
}

// Hàm Main để kiểm tra toàn bộ logic
int main() {
    //AVL myTree;
    AVL wordTree;
    // Các phần tử được chèn để kiểm tra các loại phép quay:
    // Chèn 30, 20, 40, 10, 50, 35.
    // Lần chèn 35 sẽ tạo ra trường hợp RL hoặc LR, kiểm tra cân bằng phức tạp.
    //vector<int> elements = { 50, 20, 70, 10, 30, 80, 5, 25, 40 };

    vector<char> elements = { 'D', 'H', 'G', 'T', 'V','T','T','P','H','C','M'};
    
    cout << "=== Bat dau chen cac phan tu (Kich hoat can bang AVL) ===" << endl;

    for (char key : elements) {
        cout << "Chen: " << key;
        // Do InsertNode nhận đối tượng Node*, ta cần cấp phát động
        Node* newNode = new Node(key);
        if (wordTree.InsertNode(newNode)) {
            cout << "  -> Thanh cong. Root: " << wordTree.Getroot()->Getkey() << endl;
        }
        else {
            cout << "  -> That bai (Trung key)." << endl;
            delete newNode; // Xoa node neu khong chen duoc
        }
    }

    cout << "\n========================================================" << endl;
    cout << "=== KET QUA CAY AVL CUNG CAC THONG KE ===" << endl;
    cout << "Root cua cay: " << wordTree.Getroot()->Getkey() << endl;

    // 1. Kiem tra duyet cay (LNR phai in ra cac so da sap xep)
    PrintTreeLNR(wordTree);

    // 2. Thong ke chung
    cout << "Chieu cao cua cay (Height): " << wordTree.TreeHeight(wordTree.Getroot()) << endl;
    cout << "Tong so node: " << wordTree.CountNode() << endl;
    cout << "Tong gia tri cac node: " << wordTree.SumTree() << endl;

    // 3. Thong ke min/max
    cout << "Gia tri nho nhat (Min): " << wordTree.Min() << endl;
    cout << "Gia tri lon nhat (Max): " << wordTree.Max() << endl;

    // 4. Chuc nang nang cao
    int levelCheck = 3;
    cout << "So luong node tren Level " << levelCheck << ": " << wordTree.countNodeonLevel(wordTree.Getroot(), levelCheck) << endl;
    // Cac so nguyen to trong tap {5, 10, 20, 70, 80, 5, 25, 40} la: 5, 5, ... (tuy thuoc vao vi tri)
    cout << "So luong node la so nguyen to: " << wordTree.countPrime(wordTree.Getroot()) << endl;

    // 5. Kiem tra tim kiem
    int searchKey = 3;
    Node* foundNode = wordTree.searchX(searchKey);
    if (foundNode) {
        cout << "Tim kiem key " << searchKey << ": Tim thay." << endl;
    }
    else {
        cout << "Tim kiem key " << searchKey << ": Khong tim thay." << endl;
    }

    // 6. Kiem tra mat can bang (RR Rotation)
    AVL testRR;
    testRR.InsertNode(new Node(10));
    testRR.InsertNode(new Node(20));
    testRR.InsertNode(new Node(30)); // RR rotation se kich hoat (Root moi la 20)

    cout << "\n=== Kiem tra RR Rotation ===" << endl;
    cout << "Root sau quay (10, 20, 30): " << testRR.Getroot()->Getkey() << " (Mong doi: 20)" << endl;
    testRR.TravelLNR();

    // Lưu ý: Để tránh memory leak, bạn cần triển khai logic giải phóng bộ nhớ (hàm đệ quy) trong destructor của AVL.

    return 0;
}