#include <iostream>
using namespace std;
#include <vector>

void addEdge(vector<vector<int>>* graph, int x, int y) {
    graph -> at(x).push_back(y);
    graph -> at(y).push_back(x);
}

void printDFS(vector<vector<int>>* graph, vector<int>* visited, int sv) {
    cout << sv << " ";
    for (int i=0; i<graph->at(sv).size(); i++) {
        int x = graph->at(sv)[i];
        if (!visited->at(x)) {
            visited -> at(x) = true;
            printDFS(graph, visited, x);
        }
    }
}

void printDFS(vector<vector<int>>* graph, int n) {
    vector<int>* visited = new vector<int>(n, false);
    for (int i=0; i<n; i++) {
        if (!visited->at(i)) {
            visited -> at(i) = true;
            printDFS(graph, visited, i);
        }
    }
}

int main () {
    int n = 12;
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
    printDFS(graph, n);
    delete graph;
    return 0;
}