#include<bits/stdc++.h>
using namespace std;

// time complexity: O(ElogE) or O(ElogV)
// O(logE) = O(logV) as E can be maximum V^2
// it takes ElogE to sort the array
// it takes ElogV to find cycles after including every edges

struct edge{
    int u,v,w;
};

	int find(int parent[], int i) {
    	if (parent[i]<0) return i;
    	else {
    		int ans = find(parent, parent[i]);
    		parent[i] = ans;
    		return ans;
		}
	}
	
	void Union(int parent[], int i, int j) {
		if (parent[i]<=parent[j]) {
			parent[i] += parent[j];
			parent[j] = i;
		} else {
			parent[j] += parent[i];
			parent[i] = j;
		}
	}
    
	bool isCycle(int V, vector<edge> edges)
	{
		int parent[V];
		for (int i=0; i<V; i++) parent[i]=-1;
		
		for (int i=0; i<edges.size(); i++) {
			int p1 = find(parent, edges[i].u);
			int p2 = find(parent, edges[i].v);
			
			if (p1==p2) return true;
			else Union(parent,p1,p2);
		}
		
		//for (int i=0; i<V; i++) cout << parent[i] << " ";
	    
	    return false;
	}

bool cmp(edge a, edge b) {
    return (a.w < b.w);
}

int main() {
    // Write your code here
    int v, e;
    cin >> v >> e;
    edge edges[e];
    for (int i=0; i<e; i++) {
        cin >> edges[i].u >> edges[i].v >> edges[i].w;
    }
    
    sort(edges, edges+e, cmp);
    vector<edge> ans;
    
    int i=0, k=0;
    while (k<v-1) {
        ans.push_back(edges[i]);
        
        if (isCycle(v,ans)) ans.pop_back();
        else {
            k++;
            if (edges[i].u<=edges[i].v)
            	cout << edges[i].u << " " << edges[i].v << " " << edges[i].w << endl;
            else 
                cout << edges[i].v << " " << edges[i].u << " " << edges[i].w << endl;
        }
        
        i++;
    }
}
