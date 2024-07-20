9 -> Best Time to Buy and Sell Stock II

Solution :

class Solution {
public:
    int f(int ind,int buy,vector<int>& prices,vector<vector<int>>&dp){
        if(ind==prices.size())return 0;
        int profit=0;
        if(dp[ind][buy]!=-1)return dp[ind][buy];
        if(buy){
            //naice thought jo ayya hai sell krke usse -kro curr buy se
            profit=max(f(ind+1,0,prices,dp)-prices[ind],f(ind+1,1,prices,dp));
        }
        else{
            profit=max(prices[ind]+f(ind+1,1,prices,dp),f(ind+1,0,prices,dp));
        }
        return dp[ind][buy]=profit;
    }
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        // vector<vector<int>>dp(n+1,vector<int>(2,0));
        vector<int>prev(2,0),curr(2,0);
        // return f(0,1,prices,dp);
        // buy 1 se start tha ab 0 se hoga ulta 
        
        // int prev1=0,prev2=0,curr1=0,curr2=0;
        for(int ind=n-1;ind>=0;ind--){
            int profit=0;
            for(int buy=0;buy<2;buy++){
                 if(buy){
            profit=max(prev[0]-prices[ind],prev[1]);
        }
        else{
            profit=max(prices[ind]+prev[1],prev[0]);
        }
                curr[buy]=profit;
            }
            prev=curr;
        }
        return prev[1];
    }
};