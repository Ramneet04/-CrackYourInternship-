10 -> Subarray Sums Divisible by K

Solution : 



class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        unordered_map<int,int>m;
        m[0]=1;
        int ans=0;
        int sum=0;
        for(auto x:nums){
            sum+=x;
            int mod=sum%k < 0 ? sum%k +k : sum%k;
            ans+=m[mod];
            m[mod]++;
        }
        return ans;
    }
};