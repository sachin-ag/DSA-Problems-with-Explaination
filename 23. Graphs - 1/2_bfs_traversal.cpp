#include <iostream>
using namespace std;
#include <queue>

void printGraphBFS(int** edges, int n) {
    queue<int> pending;
    pending.push(0);
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) visited[i] = false;
    visited[0] = true;
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
    printGraphBFS(edges, n);

    for (int i=0; i<n; i++) delete [] edges[i];
    delete [] edges;
}