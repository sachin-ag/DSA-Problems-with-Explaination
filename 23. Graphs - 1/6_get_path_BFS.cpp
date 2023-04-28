#include <bits/stdc++.h>
using namespace std;


vector<int> getPathBFS(int** edges, int n, int a, int b) {
    bool visited[n];
    vector<int> ans;
    if (a==b) {ans.push_back(a); return ans;}
    queue<int> pending;
    unordered_map<int,int> ourmap;
    pending.push(a);
    visited[a]=true;
    while (!pending.empty()) {
    	int a = pending.front();
    	pending.pop();
    	for (int i=0; i<n; i++) {
    		if (edges[a][i] && !visited[i]) {
    			pending.push(i);
    			visited[i]=true;
    			ourmap.insert(make_pair(i,a));
			}
		}
	}
	while (b!=a) {
		ans.push_back(b);
		b=ourmap[b];
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
    int a, b;
    cin >> a >> b;
    vector<int> ans = getPathBFS(edges, n, a, b);
    for (int i=0; i<ans.size(); i++) cout << ans[i] << " ";

    for (int i=0; i<n; i++) delete [] edges[i];
    delete [] edges;
}
