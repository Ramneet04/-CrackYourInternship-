63 -> STEPS BY KNIGHT 

Solution :
//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
	bool isvalid(int i,int j,int n, vector<vector<bool>>&visited){  //adrees bhejege &
        if(i>=0&&j>=0&&i<n&&j<n&&visited[i][j]==false){
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    int n=N;
	    int tx=TargetPos[0]-1,ty=TargetPos[1]-1;
	    int x1=KnightPos[0]-1,y1=KnightPos[1]-1;
	    queue<pair<int,int>>q;
	    q.push({x1,y1});  //curr toh push krege hi na
	    if(x1==tx&&y1==ty){
	        return 0;
	    }
	    vector<vector<bool>>visited(n,vector<bool>(n,false));
	    visited[x1][y1]=true;
	    int ans=0;
	    while(!q.empty()){
	        int size=q.size();
	        ans++;
	       
	        while(size!=0){
	            int x1=q.front().first;
	            int y1=q.front().second;
	            q.pop();
	            int ax[8]={1,-1,1,-1,2,-2,-2,2};
	            int ay[8]={2,-2,-2,2,1,-1,1,-1};
	            for(int i=0;i<8;i++){
	                int x=x1+ax[i];
	                int y=y1+ay[i];
	                if(isvalid(x,y,n,visited)){
	                    visited[x][y]=true;
	                    q.push({x,y});
	                    if(x==tx&&y==ty){
	                        return ans;
	                    }
	                }
	            }
	            size--;
	        }
	    }
	    return ans;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends