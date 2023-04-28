#include <iostream>
using namespace std;
#include <vector>
#include <queue>

void addEdge(vector<vector<int>>* graph, int x, int y) {
    graph -> at(x).push_back(y);
    graph -> at(y).push_back(x);
}

void printBFS(vector<vector<int>>* graph, vector<bool>* visited, int sv) {
    queue<int> pending;
    pending.push(sv);
    visited -> at(sv) = true;
    while (!pending.empty()) {
        int a = pending.front();
        pending.pop();
        cout << a << " ";
        for (int i=0; i<graph->at(a).size(); i++) {
            if (!visited -> at(graph->at(a)[i])) {
                pending.push(graph->at(a)[i]);
                visited -> at(graph->at(a)[i]) = true;
            }
        }
    }
}

void printBFS(vector<vector<int>>* graph, int n) {
    vector<bool>* visited = new vector<bool>(n, false);
    for (int i=0; i<n; i++) {
        if (visited -> at(i) == false) {
            printBFS(graph, visited, i);
        }
    }
}

int main () {
    int n = 12; // no of vertices of graph
    vector<vector<int>>* graph = new vector<vector<int>>(n);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 0, 4);
    addEdge(graph, 1, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 2, 5);
    addEdge(graph, 3, 6);
    addEdge(graph, 3, 7);
    addEdge(graph, 6, 9);
    addEdge(graph, 7, 8);
    addEdge(graph, 10, 11);
    printBFS(graph, n);
    delete graph;
    return 0;
}