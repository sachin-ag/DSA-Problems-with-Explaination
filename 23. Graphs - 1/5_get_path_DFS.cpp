#include <iostream>
using namespace std;
#include <vector>

vector<int>* getPathDFS(int** edges, int n, int a, int b, bool* visited) {
	visited[a]=true;
    if (a==b) {
    	vector<int>* ans = new vector<int>;
    	ans->push_back(b);
    	return ans;
	}
	for (int i=0; i<n; i++) {
		if (edges[a][i] && !visited[i]) {
			visited[i]=true;
			vector<int>* ans = getPathDFS(edges,n,i,b,visited);	
			if (ans!=NULL) {
				ans->push_back(a);
				return ans;
			}
		}
	}
	return NULL;
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
    vector<int>* ans = getPathDFS(edges, n, a, b, visited);
    if (ans != NULL) for (int i=0; i<ans->size(); i++) cout << ans -> at(i) << " ";

    for (int i=0; i<n; i++) delete [] edges[i];
    delete [] edges;
    delete [] visited;
    delete ans;
    return 0;
}
