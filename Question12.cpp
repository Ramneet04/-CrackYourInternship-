12 -> Container With Most Water

Solution

class Solution {
public:
    int maxArea(vector<int>& height) {
        //khuch bhi nhi tha EASY //two pointer
        int start=0;
        int end=height.size()-1;
        int ans=0;
        while(start<end){
            ans=max(min(height[start],height[end])*(end-start),ans); //easy login jo mene bhi bana liya tha
            if(height[start]<height[end]){
                start++;
            }
            else{
                end--;
            }
        }
        return ans;
        
    }
};