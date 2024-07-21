18 -> Word Search

Solution :

class Solution {
public:
    int n,m;
    
    bool solve(int ind,int i,int j,vector<vector<char>>& board,string &word){
        if(ind==word.length())return true;
        if(i>=n||i<0||j>=m||j<0||board[i][j]!=word[ind])return false;
        // char curr=board[i][j];
        board[i][j]='-1';
        if(solve(ind+1,i+1,j,board,word))return true;
        if(solve(ind+1,i,j+1,board,word))return true;
        if(solve(ind+1,i-1,j,board,word))return true;
        if(solve(ind+1,i,j-1,board,word))return true;
        board[i][j]=word[ind];
        return false;
    }
    
    bool exist(vector<vector<char>>& board, string word) {
        n=board.size();
        m=board[0].size();
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(solve(0,i,j,board,word)){
                    return true;
                }
            }
        }
        return false;
    }
};