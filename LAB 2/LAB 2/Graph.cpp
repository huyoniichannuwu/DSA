#include "Graph.h"
#include "Stack.h"
#include "Queue.h"
#include <iostream>
#include <algorithm> // for std::fill

using namespace std;

Graph::Graph(int V) {
    this->V = V;
    adj.resize(V);
    for (int i = 0; i < V; ++i) {
        adj[i] = new linkedList(); // Khởi tạo danh sách liên kết cho mỗi đỉnh
    }
}

Graph::~Graph() {
    for (int i = 0; i < V; ++i) {
        delete adj[i];
    }
}

// Thêm cạnh (vô hướng)
void Graph::addEdge(int v, int w) {
    // Thêm w vào danh sách kề của v
    adj[v]->insertFirst(new element(w));
    // Thêm v vào danh sách kề của w (vì là đồ thị vô hướng)
    adj[w]->insertFirst(new element(v));
}

// --- Thuật toán BFS (Tìm kiếm theo chiều rộng) sử dụng Queue ---
void Graph::BFS(int startVertex) {
    cout << "\nBFS bat dau tu dinh " << startVertex << ":\n";

    // Mảng đánh dấu các đỉnh đã được thăm
    bool* visited = new bool[V];
    fill(visited, visited + V, false);

    // Hàng đợi cho BFS
    Queue q;

    // Bắt đầu
    visited[startVertex] = true;
    q.enqueue(startVertex);

    while (!q.isEmpty()) {
        // Lấy đỉnh đầu tiên trong hàng đợi
        int u = q.dequeue();
        cout << u << " ";

        // Duyệt tất cả các đỉnh kề của u
        element* neighbor = adj[u]->getHead();
        while (neighbor != nullptr) {
            int v = neighbor->getData();
            if (!visited[v]) {
                visited[v] = true;
                q.enqueue(v);
            }
            neighbor = neighbor->getPointer();
        }
    }
    cout << endl;
    delete[] visited;
}

// --- Thuật toán DFS (Tìm kiếm theo chiều sâu) sử dụng Stack ---

// Hàm hỗ trợ đệ quy (thường dùng) - Dùng Stack để mô phỏng không đệ quy:
void Graph::DFS(int startVertex) {
    cout << "\nDFS bat dau tu dinh " << startVertex << ":\n";

    bool* visited = new bool[V];
    fill(visited, visited + V, false);

    // Stack cho DFS (mô phỏng đệ quy)
    Stack stack;

    // Bắt đầu
    stack.push(startVertex);

    while (!stack.isEmpty()) {
        int u = stack.pop();

        if (!visited[u]) {
            cout << u << " ";
            visited[u] = true;
        }

        // Duyệt các đỉnh kề (theo thứ tự ngược lại để đảm bảo thứ tự thăm)
        element* neighbor = adj[u]->getHead();
        // Do danh sách kề được chèn bằng insertFirst (ngược thứ tự), 
        // duyệt bình thường sẽ cho kết quả giống như đệ quy.
        while (neighbor != nullptr) {
            int v = neighbor->getData();
            if (!visited[v]) {
                // Đẩy các đỉnh kề chưa thăm vào stack
                stack.push(v);
            }
            neighbor = neighbor->getPointer();
        }
    }
    cout << endl;
    delete[] visited;
}
