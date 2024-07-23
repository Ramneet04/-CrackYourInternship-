65 -> Shortest Bridge

Solution :
class Solution {
public:
    bool check(int i,int j, vector<vector<int>>& grid,int n){
        if(i>=0 && i<n && j>=0 && j<n && grid[i][j]==1)return true;
        return false;
    }
    void dfs(vector<vector<int>>& grid,int n,int i,int j){
        grid[i][j]=2;
        
        if(check(i+1,j,grid,n)){
            dfs(grid,n,i+1,j);
        }
         if(check(i,j+1,grid,n)){
            dfs(grid,n,i,j+1);
        }
         if(check(i,j-1,grid,n)){
            dfs(grid,n,i,j-1);
        }
         if(check(i-1,j,grid,n)){
            dfs(grid,n,i-1,j);
        }
    }
    int bfs(vector<vector<int>>& grid,queue<pair<int,int>>&q,vector<vector<int>>&visited,int n){
        int count=0;
        int arrx[4]={0,0,-1,1};
        int arry[4]={1,-1,0,0};
        while(!q.empty()){
            int size=q.size();
            while(size--){
                auto x= q.front();
                q.pop();
                for(int i=0;i<4;i++){
                    int newi=x.first+arrx[i];
                    int newj=x.second+arry[i];
                    if(newi >=0 && newi <n && newj >=0 && newj<n && !visited[newi][newj]){
                        if(grid[newi][newj]==2)return count;
                        q.push({newi,newj});
                        visited[newi][newj]=true;
                    }
                }
            }
            count++;
        }
        return count;
    }
    int shortestBridge(vector<vector<int>>& grid) {
        for(int i=0;i<grid.size();i++){
            bool flag=false;
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    dfs(grid,grid.size(),i,j);
                    flag=true;
                    break;
                }
            }
            if(flag)break;
        }
        int ans=1e9;
        queue<pair<int,int>>q;
        vector<vector<int>>visited(grid.size(),vector<int>(grid.size(),false));
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid.size();j++){
                if(grid[i][j]==1){
                    q.push({i,j});
                    visited[i][j]=true;
                }
            }
        }
        ans=bfs(grid,q,visited,grid.size());
        return ans;
    }
};