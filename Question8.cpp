8 -> Two Sum

Solution :

class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        int n=nums.size();
        int sum=0;
          vector<int> ans;
        for(int i=0;
           i<n;
           i++){
            for(int j=i+1;
               j<n;
               j++){
                sum=nums[i]+nums[j];
                if(sum==target){
                ans.push_back(i);
                ans.push_back(j);
                    break;
                }
            }
        }
        return ans;
    }
};