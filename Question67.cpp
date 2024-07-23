67 -> Find Eventual Safe States

Solution :
class Solution {
public:
   bool dfs(vector<vector<int>>& graph,int source,vector<bool>&visited,vector<bool>&dfsvisited){
        visited[source]=true;
        dfsvisited[source]=true;
        for(auto x:graph[source]){
            if(!visited[x]){
                if(dfs(graph,x,visited,dfsvisited)){
                    return true;
                }
                }
             else if(dfsvisited[x]){
                    return true;
            }
            
        }
        dfsvisited[source]=false;
        return false;
    }
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        int n=graph.size();
        vector<bool>visited(n);
      
            vector<bool>dfsvisited(n);
        for(int i=0;i<n;i++){
            if(visited[i]==false){
                dfs(graph,i,visited,dfsvisited);
            }
        }
        vector<int>ans;
        for(int i=0;i<n;i++){
            if(dfsvisited[i]==false){
                ans.push_back(i);
            }
        }
        return ans;
    }
};