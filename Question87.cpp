87 -> Decode Ways

Solution :
class Solution {
public:
    int solve(int i,string &s,vector<int>&dp){
        if(i==s.length())
            return 1;
        if(s[i]=='0')
            return 0;
        if(dp[i]!=-1)return dp[i];
        int onechar=solve(i+1,s,dp);
        int twochar=0;
        if((i<s.length()-1)&&(s[i]=='1'||(s[i]=='2'&&s[i+1]<='6'))){
            twochar=solve(i+2,s,dp);
        }
        return dp[i]=onechar+twochar;
    }
    int numDecodings(string s) {
        vector<int>dp(s.length()+1,-1);
        return solve(0,s,dp);
    }
};