82 -> Find the number of islands using DFS

Soution :

//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    // Function to find the number of islands.
    bool check(vector<vector<char>>& grid,int i,int j,int n,int m){
        if(i>=0 && j>=0 && i<n && j<m && grid[i][j]=='1')return true;
        return false;
    }
    void dfs(vector<vector<char>>& grid,int i,int j,int n,int m){
        grid[i][j]='0';
        if(check(grid,i+1,j,n,m)){
            dfs(grid,i+1,j,n,m);
        }
        if(check(grid,i-1,j,n,m)){
            dfs(grid,i-1,j,n,m);
        }
        if(check(grid,i,j+1,n,m)){
            dfs(grid,i,j+1,n,m);
        }
        if(check(grid,i,j-1,n,m)){
            dfs(grid,i,j-1,n,m);
        }
        if(check(grid,i-1,j-1,n,m)){
            dfs(grid,i-1,j-1,n,m);
        }
        if(check(grid,i+1,j+1,n,m)){
            dfs(grid,i+1,j+1,n,m);
        }
        if(check(grid,i+1,j-1,n,m)){
            dfs(grid,i+1,j-1,n,m);
        }
        if(check(grid,i-1,j+1,n,m)){
            dfs(grid,i-1,j+1,n,m);
        }
        
    }
    int numIslands(vector<vector<char>>& grid) {
        int ans=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j,grid.size(),grid[0].size());
                }
            }
        }
        return ans;
    }
};

//{ Driver Code Starts.
int main() {
    int tc;
    cin >> tc;
    while (tc--) {
        int n, m;
        cin >> n >> m;
        vector<vector<char>> grid(n, vector<char>(m, '#'));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < m; j++) {
                cin >> grid[i][j];
            }
        }
        Solution obj;
        int ans = obj.numIslands(grid);
        cout << ans << '\n';
    }
    return 0;
}
// } Driver Code Ends