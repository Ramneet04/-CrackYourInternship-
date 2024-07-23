74 -> Combination Sum II

Solution :

class Solution {
public:
     void solve(int i,vector<int>&nums,vector<vector<int>>&ans,vector<int>&output,int target){
            if(target==0){
                ans.push_back(output);
                return;
            }
        for(int x=i;x<nums.size();x++){
            if(x>i&&nums[x]==nums[x-1])continue;
            if(target<nums[x])break;
           output.push_back(nums[x]);
        solve(x+1,nums,ans,output,target-nums[x]);
            output.pop_back();
        }
        return;
    }
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(),candidates.end());
        int i=0;
        vector<int>output;
        vector<vector<int>>ans;
        solve(i,candidates,ans,output,target);
        return ans;
    }
};