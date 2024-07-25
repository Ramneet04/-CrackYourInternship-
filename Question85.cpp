85 -> Coin Change 

Solution :
class Solution {
public:
    int solve(int ind,vector<int>& coins, int amount,vector<vector<int>>&dp){
        if(amount==0)return 0;
        if(ind==0){
            if(amount>=coins[0]){
                if(amount%coins[0]==0){
                    return amount/coins[0];
                }
            }
            return 1e9;
        }
        if(dp[ind][amount]!=-1)return dp[ind][amount];
        int take=1e9;
        if(amount>=coins[ind]){
            take=1+solve(ind,coins,amount-coins[ind],dp);
        }
        int nottake=0+solve(ind-1,coins,amount,dp);
        return dp[ind][amount]=min(take,nottake);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<vector<int>>dp(coins.size()+1,vector<int>(amount+1,-1));
        if(amount==0)return 0;
        int ans=solve(coins.size()-1,coins,amount,dp);
        // min(1e9,1e9+x) x is some count 1 2 3  for explaination we want minimum
        if(ans==1e9)return -1;
        return ans;
    }
};