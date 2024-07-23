79 -> Sliding Window Maximum

Solution :
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        priority_queue<pair<int,int>>pq;
        vector<int>ans;
        int i=0,j=0;
        while(j<k){
            pq.push({nums[j],j});
            j++;
        }
        ans.push_back(pq.top().first);
        
        while(j<nums.size()){
            
            while(!pq.empty()&&pq.top().second<=i){
                pq.pop();
            }
            pq.push({nums[j],j});
            ans.push_back(pq.top().first);
            i++;j++;
        }
        return ans;
    }
};