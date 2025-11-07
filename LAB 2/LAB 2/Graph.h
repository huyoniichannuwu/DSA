#pragma once
#include "linkedList.h"
#include "Stack.h"
#include <vector> // Dùng std::vector để quản lý mảng các danh sách kề

class Graph {
private:
    int V; // Số lượng đỉnh
    std::vector<linkedList*> adj; // Danh sách kề: Mảng các danh sách liên kết

    //DFS
    void DFSUtil(int v, bool visited[], Stack& stack);

public:
    Graph(int); 
    ~Graph();   
    void addEdge(int v, int w); // Thêm cạnh từ v đến w (đồ thị vô hướng)

    // Thuật toán tìm kiếm
    void BFS(int startVertex);
    void DFS(int startVertex);
};