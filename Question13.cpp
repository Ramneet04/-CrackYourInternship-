13 -> Three Sum

Solution :

class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>ans;  
        sort(nums.begin(),nums.end());
        for(int i=0;i<nums.size();i++){     //pure size se kam tak dekho ek kam tak hi chalge < hai aut j end pe and k bhi end pe but j<k hai nihce toh loop me jayga hi nhi .
              if(i > 0 && nums[i] == nums[i - 1]){
            continue;
            }
            
            int j=i+1;
            int k=nums.size()-1;
            while(j<k){
                if(nums[i]+nums[j]+nums[k]==0){
                    vector<int>data;
                    data.push_back(nums[i]);
                     data.push_back(nums[j]);
                     data.push_back(nums[k]);
                    ans.push_back(data);
                    while(j<k&&nums[j]==nums[j+1]){
                        j++;
                    }
                    while(j<k&&nums[k]==nums[k-1]){
                        k--;
                    }
                    j++;k--;
                }
                else if(nums[i]+nums[j]+nums[k]>0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }
        return ans;
    }
};