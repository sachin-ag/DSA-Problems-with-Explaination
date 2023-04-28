#include <iostream>
using namespace std;
/* An island is a small piece of land surrounded by water . 
A group of islands is said to be connected if we can reach from 
any given island to any other island in the same group . 
Given V islands (numbered from 1 to V) and E connections or 
edges between islands. Count the number of connected groups of islands. */

void helper(int** edges, int n, int sv, bool* visited) {
    visited[sv] = true;
    for (int i=0; i<n; i++) {
        if (edges[sv][i] == 1 && !visited[i]) {
            helper(edges, n, i, visited);
        }
    }
}

int connectedGroups(int** edges, int n) {
    int ans = 0;
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) visited[i] = false;
    for (int i=0; i<n; i++) {
        if (!visited[i]) {
            helper(edges, n, i, visited);
            ans++;
        }
    }
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
    cout << connectedGroups(edges, n);
    for (int i=0; i<n; i++) delete [] edges[i];
    delete [] edges;
}