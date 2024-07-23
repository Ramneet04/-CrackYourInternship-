59 -> RAT IN MAZE 

Solution :

//{ Driver Code Starts
// Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function template for C++

class Solution {
  public:
  bool valid(int i,int j,int n,vector<vector<int>>&grid){
        if(i>=0&&j>=0&&i<n&&j<n&&grid[i][j]==1){
            return true;
        }
        return false;
    }
    void solve(vector<vector<int>>&grid,int n,int i,int j,vector<string>&ans,string&s){
        if(i==n-1&&j==n-1){
            ans.push_back(s);
            return; //base and return condition must
        }
        grid[i][j]=0;
        if(valid(i+1,j,n,grid)){
            s.push_back('D'); //phele insert phir call
            solve(grid,n,i+1,j,ans,s);
             s.pop_back();
            
        }
           if(valid(i,j-1,n,grid)){
            s.push_back('L'); 
            solve(grid,n,i,j-1,ans,s);
             s.pop_back();
            
        }
           if(valid(i,j+1,n,grid)){
            s.push_back('R'); 
            solve(grid,n,i,j+1,ans,s);
             s.pop_back();
            
        }
           if(valid(i-1,j,n,grid)){
            s.push_back('U'); 
            solve(grid,n,i-1,j,ans,s);
             s.pop_back();
            
        }
        grid[i][j]=1;
        
        
    }
    vector<string> findPath(vector<vector<int>> &mat) {
        // Your code goes here
        int i=0;
        int j=0;
        vector<string>ans;
        string s="";
        if(mat[i][j]==0){
            return ans;
        }
        solve(mat,mat.size(),i,j,ans,s);
        return ans;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<vector<int>> m(n, vector<int>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                cin >> m[i][j];
            }
        }
        Solution obj;
        vector<string> result = obj.findPath(m);
        sort(result.begin(), result.end());
        if (result.size() == 0)
            cout << -1;
        else
            for (int i = 0; i < result.size(); i++)
                cout << result[i] << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends