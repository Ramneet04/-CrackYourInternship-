83 -> Combinations

Solution :
class Solution {
public:
    void solve(int i,vector<int>&output,vector<vector<int>>&ans,int n,int k){
        if(output.size()==k){
            ans.push_back(output);
        return;
    }
        for(int x=i;x<=n;x++){
            output.push_back(x);
            solve(x+1,output,ans,n,k);
            output.pop_back();
        }
    }
    vector<vector<int>> combine(int n, int k) {
     vector<int>output;
     vector<vector<int>>ans;
        solve(1,output,ans,n,k);
            return ans;
    }
};