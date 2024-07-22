52 -> Next Greater Element I

Solution :

class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int,int>m;
        stack<int>st;
        st.push(-1);
        for(int i=nums2.size()-1;i>=0;i--){
            while(st.top()<nums2[i]){    //ya phir agar empty mila toh -1 dal dege warna element dusri approach pr mera shi hai.........no worryies.
                if(st.top()==-1){
                    break;
                }
                st.pop();
            }
            m[nums2[i]]=st.top();
            st.push(nums2[i]);
        }
        vector<int>ans;
        for(auto x:nums1){
                ans.push_back(m[x]);
        }
        return ans;
    }
};