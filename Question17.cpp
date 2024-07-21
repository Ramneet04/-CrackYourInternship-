17 -> Spiral Matrix

Solution :

class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        vector<int>ans;
        int n=matrix.size();
        int m=matrix[0].size();
        
        int count=0;
        int total=n*m;
        
        int startingrow=0;
        int endingrow=n-1;
        int startingcol=0;
        int endingcol=m-1;
        
        while(count<total){
            for(int i=startingcol;i<=endingcol&&count<total;i++){
                int ele=matrix[startingrow][i];
                ans.push_back(ele);
                count++;
            }
            startingrow++;
            
             for(int i=startingrow;i<=endingrow&&count<total;i++){
                int ele=matrix[i][endingcol];
                ans.push_back(ele);
                 count++;
            }
            endingcol--;
            
             for(int i=endingcol;i>=startingcol&&count<total;i--){
                int ele=matrix[endingrow][i];
                ans.push_back(ele);
                 count++;
            }
            endingrow--;
            
             for(int i=endingrow;i>=startingrow&&count<total;i--){
                int ele=matrix[i][startingcol];
                ans.push_back(ele);
                 count++;
            }
            startingcol++;;
        }
        return ans;
    }
};