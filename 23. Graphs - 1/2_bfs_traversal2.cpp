// this implementation uses adjacency list instead of adjacency matrix
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

void addEdge(vector<vector<int>>* graph, int x, int y) {
    graph -> at(x).push_back(y);
    graph -> at(y).push_back(x);
    // inserting the edge in the list of both vertices
}

void printBFS(vector<vector<int>>* graph) {
    queue<int> pending;
    pending.push(0);
    vector<bool> visited(10, false);
    while (!pending.empty()) {
        int a = pending.front();
        pending.pop();
        visited[a] = true;
        cout << a << " ";
        for (int i=0; i<graph->at(a).size(); i++) {
            int x = graph->at(a)[i];
            if (!visited[x]) {
                pending.push(x);
                visited[x] = true;
            }
        }
    }
}

int main () {
    int n = 10; // no of vertices
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
    printBFS(graph);
    delete graph;
    return 0;
}