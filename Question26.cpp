26 -> Climbing Stairs

Solution :

class Solution {
public:
    int solve(int ind,int n,vector<int>&dp){
        if(ind==n){
            return 1; 
            //when we reached return one, as we have reached...
        }
        if(ind>n){
            return 0;
        }
        if(dp[ind]!=-1)return dp[ind];
        int one=solve(ind+1,n,dp);
        int two=solve(ind+2,n,dp);
        return dp[ind]=one+two;
    }
    int climbStairs(int n) {
        vector<int>dp(n+1,0);
        // dp[n]=1;
        //reached here so 1.
        // return solve(0,n,dp);
        // for(int ind=n-1;ind>=0;ind--){
        //     int one=dp[ind+1];
        //     int two=0;
        //     if(ind+2<=n)
        //     two=dp[ind+2];
        //     dp[ind]=one+two;
        // }
        // return dp[0];
        int a=0;
        int b=1;
        int curr=0;
        for(int i=1;i<=n;i++){
            curr=a+b;
            a=b;
            b=curr;
        }
        return curr;
    }
};