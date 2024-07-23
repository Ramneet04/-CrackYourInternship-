73 -> Kth Largest Element in an Array 

Solution :
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        //first aproach sorf return arr[size-k];
        //second approach priority queue;
       /*priority_queue<int>q(nums.begin(),nums.end());
        int count=0;
        int ans=0;
        while(!q.empty()){
            count++;
            if(count==k){
                ans=q.top();
                break;
            }
            q.pop();
        }
        return ans;
           */
        //THIRD APPROACH 
  /*      priority_queue<int,vector<int>,greater<int>>q;
        for(int i=0;i<nums.size();i++){
            q.push(nums[i]);
            if(q.size()>k){
                q.pop();
            }
        }
        return q.top();*/
        
        
        
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
};