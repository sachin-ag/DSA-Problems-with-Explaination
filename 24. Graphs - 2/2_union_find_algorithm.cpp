#include<bits/stdc++.h>
using namespace std;

// UNION FIND ALGORITHM TO DETECT CYCLES IN A GRAPH
// IMPORTANT: THIS ALGORITHM CANNOT DETECT *SELF LOOPS*

class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
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
    
	bool isCycle(int V, vector<pair<int,int> > edges)
	{
		int parent[V];
		for (int i=0; i<V; i++) parent[i]=-1;
		
		for (int i=0; i<edges.size(); i++) {
			int p1 = find(parent, edges[i].first);
			int p2 = find(parent, edges[i].second);
			
			if (p1==p2) return true;
			else Union(parent,p1,p2);
		}
		
		//for (int i=0; i<V; i++) cout << parent[i] << " ";
	    
	    return false;
	}
};

int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<pair<int,int> > edges(E);
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			edges[i] = make_pair(u,v);
		}
		Solution obj;
		bool ans = obj.isCycle(V, edges);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}
