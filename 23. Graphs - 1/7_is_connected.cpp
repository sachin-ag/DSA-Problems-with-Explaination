#include <iostream>
using namespace std;

void isConnectedHelp(int** edges, int n, int sv, bool* visited) {
    visited[sv] = true;
    for (int i=0; i<n; i++) {
        if (edges[sv][i] == 1 && !visited[i]) {
            isConnectedHelp(edges, n, i, visited);
        }
    }
}

bool isConnected(int** edges, int n) {
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) visited[i] = false;
    isConnectedHelp(edges, n, 0, visited);
    bool ans = true;
    for (int i=0; i<n; i++) {
        if (visited[i] == false) {
            ans = false;
            break;
        }
    }
    delete [] visited;
    return ans;
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
    if (isConnected(edges, n)) cout << "true";
    else cout << "false";

    for (int i=0; i<n; i++) delete [] edges[i];
    delete [] edges;
}