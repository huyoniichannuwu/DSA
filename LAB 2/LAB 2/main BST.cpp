#include <iostream>
#include "BST.h"
#include "Node.h"

using namespace std;

void testAllFeatures() {
    BST tree;
    int elements[] = { 50, 30, 70, 20, 40, 60, 80, 40, 60, 17 }; // Thêm một số phần tử lặp lại
    int n = sizeof(elements) / sizeof(elements[0]);

    cout << "--- Khoi tao va Chen Node (Insert) ---" << endl;
    for (int key : elements) {
        Node* newNode = new Node(key);
        if (tree.InsertNode(newNode)) {
            cout << "Da chen: " << key << endl;
        }
        else {
            // Node đã được tăng appearedCount trong InsertNode
            cout << "Gia tri " << key << " da ton tai. Tang count." << endl;
            delete newNode; // Giải phóng Node không được chèn
        }
    }
    // 
    cout << "\n--- Tim kiem Node (Search) ---" << endl;
    int searchKey = 40;
    Node* foundNode = tree.searchX(searchKey);
    if (foundNode != nullptr) {
        cout << "Tim thay Node voi key = " << searchKey << ". Key xuat hien "
            << foundNode->Getcount() << " lan." << endl;
    }
    else {
        cout << "Khong tim thay Node voi key = " << searchKey << "." << endl;
    }

    searchKey = 99;
    foundNode = tree.searchX(searchKey);
    if (foundNode != nullptr) {
        cout << "Tim thay Node voi key = " << searchKey << "." << endl;
    }
    else {
        cout << "Khong tim thay Node voi key = " << searchKey << "." << endl;
    }

    cout << "\n--- Du lich Cay (Traversal) ---" << endl;
    cout << "NLR: (Root, Left, Right)" << endl;
    tree.TravelNLR();

    cout << "\nLNR: (Left, Root, Right)" << endl;
    tree.TravelLNR();

    cout << "\nLRN: (Left, Right, Root)" << endl;
    tree.TravelLRN();

    cout << "\n--- Min va Max ---" << endl;
    cout << "Gia tri nho nhat (Min): " << tree.Min() << endl;
    cout << "Gia tri lon nhat (Max): " << tree.Max() << endl;

    cout << "\n--- Tong va Dem Node ---" << endl;
    cout << "Tong gia tri cac Node (SumTree): " << tree.SumTree() << endl;
    cout << "So luong Node (CountNode): " << tree.CountNode() << endl;

    cout << "\n--- Chieu cao Cay (Height) ---" << endl;
    cout << "Chieu cao cua Cay: " << tree.TreeHeight(tree.Getroot()) << endl;

    cout << "\n--- So lan xuat hien (printAppeared) ---" << endl;
    //printAppeared in ra LNR
    tree.printAppeared(tree.Getroot());
    cout << endl;

    cout << "\n--- Xoa Node (Delete) ---" << endl;
    int deleteKey = 40;
    Node* toDelete = tree.searchX(deleteKey);
    if (toDelete != nullptr) {
        cout << "Xoa Node voi key: " << deleteKey << endl;
        tree.DeleteNode(toDelete);
        cout << "Kiem tra lai In-order sau khi xoa " << deleteKey << ":" << endl;
        tree.TravelLNR();
    }
    else {
        cout << "Khong tim thay key " << deleteKey << " de xoa." << endl;
    }

    deleteKey = 50; // Root
    toDelete = tree.searchX(deleteKey);
    if (toDelete != nullptr) {
        cout << "\nXoa Node Root voi key: " << deleteKey << endl;
        tree.DeleteNode(toDelete);
        cout << "Kiem tra lai In-order sau khi xoa " << deleteKey << ":" << endl;
        tree.TravelLNR();
    }
    else {
        cout << "Khong tim thay key " << deleteKey << " de xoa." << endl;
    }

    cout << "\n--- Kiem tra lai CountNode sau khi xoa ---" << endl;
    cout << "So luong Node hien tai: " << tree.CountNode() << endl;

    cout << "---Dem tren cay co bao nhieu so nguyen to---" << endl;
    cout << "So luong so nguyen to: " << tree.countPrime(tree.Getroot()) << endl;
}



int main() {
    testAllFeatures();
    // Destructor has been called
    return 0;
}