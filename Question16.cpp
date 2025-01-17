16 -> Subarray Sum Equals K

Solution :

class Solution {
public:
    int subarraySum(vector<int>& nums, int k) {
       unordered_map<int,int>m;
        m[0]=1;
        int ans=0;
        int sum=0;
        for(auto x:nums){
            sum+=x;
            ans+=m[sum-k];
            m[sum]++;
        }
        return ans;
    }
};