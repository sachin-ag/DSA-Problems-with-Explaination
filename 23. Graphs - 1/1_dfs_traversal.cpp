// DFS - Adjancy matrix
#include <iostream>
using namespace std;

void printGraph(int** edges, int n, int sv, bool* visited) { // sv = starting vertex
    cout << sv << endl;
    visited[sv] = true;
    for (int i=0; i<n; i++) {
        if (edges[sv][i] == 1) {
            if (visited[i]) {
                continue;
            }
            printGraph(edges, n, i, visited);
        }
    }
}

int main() {
    int n, e;
    cin >> n >> e;
    int** edges = new int*[n];
    for (int i=0; i<n; i++) {
        edges[i] = new int[n];
        for (int j=0; j<n; j++) {
            edges[i][j] = 0;
        }
    }
    for (int i=0; i<e; i++) {
        int f, s; // first and second vertex
        cin >> f >> s;
        edges[f][s] = 1; // edge added to the graph
        edges[s][f] = 1;
    }

    bool* visited = new bool[n];
    for (int i=0; i<n; i++) {
        visited[i] = false;
    }
    printGraph(edges, n, 0, visited);

    for (int i=0; i<n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
    delete [] visited;
}