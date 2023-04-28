#include <iostream>
using namespace std;
#include <queue>

void printDFS(int** edges, int n, int sv, bool* visited) { // sv = starting vertex
    cout << sv << endl;
    visited[sv] = true;
    for (int i=0; i<n; i++) {
        if (edges[sv][i] == 1) {
            if (visited[i]) {
                continue;
            }
            printDFS(edges, n, i, visited);
        }
    }
}

void DFS(int** edges, int n) {
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) visited[i] = false;
    for (int i=0; i<n; i++) if (!visited[i]) printDFS(edges, n, i, visited);
    delete [] visited;
}

void printBFS(int** edges, int n, int sv, bool* visited) {
    queue<int> pending;
    pending.push(sv);
    visited[sv] = true;
    while (!pending.empty()) {
        int a = pending.front();
        pending.pop();
        cout << a << " ";
        for (int i=0; i<n; i++) {
            if (i == a) continue;
            if (edges[a][i] == 1 && !visited[i]) {
                pending.push(i);
                visited[i] = true;
            }
        }
    }
}

void BFS(int** edges, int n) {
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) visited[i] = false;
    for (int i=0; i<n; i++) if (!visited[i]) printBFS(edges, n, i, visited);
    delete [] visited;
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

    cout << "DFS: " << endl;
    DFS(edges, n);

    cout << "BFS: " << endl;
    BFS(edges, n);

    for (int i=0; i<n; i++) {
        delete [] edges[i];
    }
    delete [] edges;
}