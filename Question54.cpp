54 -> Largest Rectangle in Histogram

Solution :

class Solution {
public:
    void nextsmallest(vector<int>&ans1,vector<int>& heights){
        stack<int>st;
        st.push(heights.size());
        for(int i=heights.size()-1;i>=0;i--){
            while(st.size()>1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans1[i]=st.top();
            st.push(i);
        }
      
    }
    void prevsmallest(vector<int>&ans2,vector<int>& heights){
        stack<int>st;
        st.push(-1);
        for(int i=0;i<heights.size();i++){
            while(st.size()>1 && heights[st.top()]>=heights[i]){
                st.pop();
            }
            ans2[i]=st.top();
            st.push(i);
        }
     
    }
    int largestRectangleArea(vector<int>& heights) {
        vector<int>ans1(heights.size());
        vector<int>ans2(heights.size());
       nextsmallest(ans1,heights);
       prevsmallest(ans2,heights);
        int ans=0;
        for(int i=0;i<heights.size();i++){
           int curr=(ans1[i]-ans2[i]-1)*heights[i];
            ans=max(curr,ans);
        }
        return ans;
    }
};