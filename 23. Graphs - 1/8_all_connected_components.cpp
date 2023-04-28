#include <bits/stdc++.h>
using namespace std;
/* Given an undirected graph G(V,E), find and print all the connected components of the given graph G.
Note:
1. V is the number of vertices present in graph G and vertices are numbered from 0 to V-1. 
2. E is the number of edges present in graph G.
3. You need to take input in main and create a function which should return all the connected components. 
And then print them in the main, not inside function.

Print different components in new line. And each component should be printed in increasing order 
(separated by space). Order of different components doesn't matter. */

vector<int>* connectedHelp(int** edges, int n, int sv, bool* visited) {
    vector<int>* ans = new vector<int>;
    ans -> push_back(sv);
    visited[sv] = true;
    for (int i=0; i<n; i++) {
        if (edges[sv][i] == 1 && !visited[i]) {
            vector<int>* temp = connectedHelp(edges, n, i, visited);
            for (int i=0; i<temp->size(); i++) ans -> push_back(temp -> at(i));
            delete temp;
        }
    }
    return ans;
}

vector<vector<int>*>* connectedComponents(int** edges, int n) {
    vector<vector<int>*>* ans = new vector<vector<int>*>;
    bool* visited = new bool[n];
    for (int i=0; i<n; i++) visited[i] = false;
    for (int i=0; i<n; i++) {
        if (visited[i] == false) {
            ans -> push_back(connectedHelp(edges, n, i, visited));
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
    vector<vector<int>*>* ans = connectedComponents(edges, n);
    for (int i=0; i<ans->size(); i++) {
        sort(ans -> at(i) -> begin(), ans -> at(i) -> end());
        for (int j=0; j<ans->at(i)->size(); j++) {
            cout << ans -> at(i) -> at(j) << " ";
        }
        cout << endl;
    }

	for (int i=0; i<ans->size(); i++) delete ans -> at(i);
    for (int i=0; i<n; i++) delete [] edges[i];
    delete ans;
    delete [] edges;
}