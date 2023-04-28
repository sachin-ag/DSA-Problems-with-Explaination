#include <iostream>
using namespace std;

bool hasPath(int** edges, int n, int a, int b, bool* visited) {
	visited[a]=true;
    if (a==b) return true;
    for (int i=0; i<n; i++) {
    	if (edges[a][i] && !visited[i]) {
    		if (hasPath(edges,n,i,b,visited)) return true;
		}
	}
	return false;
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
    for (int i=0; i<n; i++) visited[i] = false;
    int a, b;
    cin >> a >> b;
    if (hasPath(edges, n, a, b, visited)) cout << "true";
    else cout << "false";
    
    for (int i=0; i<n; i++) delete [] edges[i];
    delete [] edges;
    delete [] visited;
}
