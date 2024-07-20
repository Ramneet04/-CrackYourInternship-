6 -> Best Time to Buy and Sell Stock

Solution :

class Solution {
public:
    int maxProfit(vector<int>& prices) {
            int mini=prices[0];
        int ans=0;
        for(int i=0;i<prices.size();i++){
            int cost=prices[i]-mini;
            ans=max(ans,cost);
            mini=min(mini,prices[i]);
        }
        return ans;
    }
};