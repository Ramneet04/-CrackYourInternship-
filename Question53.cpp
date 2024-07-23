53 -> Game of Life

Solution :
class Solution {
public:
    bool isvalid(int row,int col,vector<vector<int>>&board){
        if(row>=0&&col>=0&&row<board.size()&&col<board[0].size()&&abs(board[row][col])==1){
            return true;
        }
        return false;
    }
    void gameOfLife(vector<vector<int>>& board) {
        int arow[8]={1,-1,0,0,1,-1,1,-1};
        int acol[8]={0,0,1,-1,1,-1,-1,1};
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                int livecell=0;
                int row=i,col=j;
                for(int i=0;i<8;i++){
                    int newrow=row+arow[i];
                    int newcol=col+acol[i];
                    if(isvalid(newrow,newcol,board)){
                        livecell++;
                    }
                }
                if(board[row][col]==0){
                    if(livecell==3)
                        board[row][col]=2;
                }
               else if(board[row][col]==1){
                   if(livecell<2){
                       board[row][col]=-1;
                   }
                   else if(livecell>3){
                       board[row][col]=-1;
                   }
               }
            }
        }
              for(int i=0;i<board.size();i++){
                for(int j=0;j<board[0].size();j++){
                    if(board[i][j]==-1){
                        board[i][j]=0;
                    }
                    else if(board[i][j]==2){
                        board[i][j]=1;
                    }
                }
            }
    }
};