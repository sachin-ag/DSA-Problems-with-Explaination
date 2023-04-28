// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends



class Solution 
{
    public:
    //Function to detect cycle in an undirected graph.
    
    bool helper(vector<int> adj[], vector<bool>& used, vector<bool> visited, int c, int p) {
        visited[c]=true;
        used[c]=true;
        if (c==p) return true; // self loop
        
        for (int i=0; i<adj[c].size(); i++) {
            if (visited[adj[c][i]] && adj[c][i]!=p) // edge present to a ancestor edge
                return true;
        }
        
        for (int i=0; i<adj[c].size(); i++) {
            if (!visited[adj[c][i]])
                if (helper(adj,used,visited,adj[c][i],c)) // recursion
                    return true;
        }
        
        return false;
        
    }
    
	bool isCycle(int V, vector<int> adj[])
	{
	    // Code here
	    vector<bool> visited(V,false); // recursion stack
	    vector<bool> used(V, false); // as the graph can be disconnected
	    
	    for (int i=0; i<V; i++) {
	        if (!used[i]) {
	            used[i]=true;
	            visited[i]=true;
	            for (int j=0; j<adj[i].size(); j++) {
	                if (helper(adj,used,visited,adj[i][j],i)) return true;
	            }
	            visited[i]=false; // to be used in next vertice
	        }
	    }
	    
	    return false;
	}
};

// { Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int V, E;
		cin >> V >> E;
		vector<int>adj[V];
		for(int i = 0; i < E; i++){
			int u, v;
			cin >> u >> v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		Solution obj;
		bool ans = obj.isCycle(V, adj);
		if(ans)
			cout << "1\n";
		else cout << "0\n";
	}
	return 0;
}  // } Driver Code Ends
