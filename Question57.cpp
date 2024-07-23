57 -> Number of Islands
 

Solution :
class Solution {
public:
    void solve(int i, int j,vector<vector<char>>& grid){
        if(i>=grid.size()||j>=grid[0].size()||i<0||j<0||grid[i][j]=='0')return;
        grid[i][j]='0';
        
        solve(i+1,j,grid);
        solve(i-1,j,grid);
        solve(i,j+1,grid);
        solve(i,j-1,grid);
    }
    int numIslands(vector<vector<char>>& grid) {
        int count=0;
        
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]=='1'){
                    solve(i,j,grid);
                    count++;
                }
            }
        }
        return count;
    }
};
