20 -> Jump Game

Solution : 



class Solution {
public:
    bool f(int ind,vector<int>&nums,vector<int>&dp){
        if(ind>=nums.size()-1)return true;
        //as such no need chal jayega
        // if(nums[ind]==0)return false;
        if(dp[ind]!=-1)return dp[ind];
        for(int i=1;i<=nums[ind];i++){
            if(f(ind+i,nums,dp))return dp[ind]= true;
        }
        return dp[ind]=false;
    }
    bool canJump(vector<int>& nums) {
        vector<int>dp(nums.size()+1,-1);
        return f(0,nums,dp);
    }
    
};