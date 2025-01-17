61 -> Directed Graph Cycle

Solution :

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
   bool dfs(vector<int> adj[], vector<bool>&visited,vector<bool>&dfsvisited,int node, int parent) 
{
    visited[node]=true;
    dfsvisited[node]=true;
    for(auto x:adj[node]){
        if(!visited[x]){
            if(dfs(adj,visited,dfsvisited,x,node)){
                return true;
            }   
        }
        else if(visited[x]&& dfsvisited[x])
        return true;
        }
        dfsvisited[node]=false;
    return false;
    
}
    // Function to detect cycle in a directed graph.
    bool isCyclic(int V, vector<int> adj[]) {
        // code here
        vector<bool>visited(V,false);
        vector<bool>dfsvisited(V,false);
        for(int i=0;i<V;i++){
            if(!visited[i]){
            if(dfs(adj,visited,dfsvisited,i,-1)){
            return true;
            }
        }
        }
        return false;
    }
};

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;

        vector<int> adj[V];

        for (int i = 0; i < E; i++) {
            int u, v;
            cin >> u >> v;
            adj[u].push_back(v);
        }

        Solution obj;
        cout << obj.isCyclic(V, adj) << "\n";
    }

    return 0;
}

// } Driver Code Ends