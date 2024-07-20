4 -> Set Matrix Zeroes


Solution :

class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        vector<int>arr1;
        vector<int>arr2;
        for(int i=0;i<matrix.size();i++){
            for(int j=0;j<matrix[0].size();j++){
                if(matrix[i][j]==0){
                    arr1.push_back(i);
                    arr2.push_back(j);
                }
            }
        }
        
         for(auto i:arr1){
             for(int j=0;j<matrix[0].size();j++){
                 matrix[i][j]=0;
             }
         }
          for(auto i:arr2){ 
             for(int j=0;j<matrix.size();j++){
                 matrix[j][i]=0;
             }
         }
        
    }
};