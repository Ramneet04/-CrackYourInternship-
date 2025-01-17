60 -> Undirected Graph Cycle
 

Solution :
//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool dfs(vector<int> adj[], vector<bool>&visited,int node, int parent) 
{
    visited[node]=true;
    for(auto x:adj[node]){
        if(!visited[x]){
            if(dfs(adj,visited,x,node)){
                return true;
            }   
        }
        else if(visited[x]&&x!=parent)
        return true;
        }
    return false;
    
}
    bool isCycle(int V, vector<int> adj[]) {
        vector<bool>visited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
            if(dfs(adj,visited,i,-1)){
            return true;
            }
        }
        }
        return false;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int V, E;
        cin >> V >> E;
        vector<int> adj[V];
        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
            adj[v].push_back(u);
        }
        Solution obj;
        bool ans = obj.isCycle(V, adj);
        if (ans)
            cout << "1\n";
        else
            cout << "0\n";
    }
    return 0;
}
// } Driver Code Ends