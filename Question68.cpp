68 -> Time Needed to Inform All Employees

Solution :

class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
    vector<int>adj[n];
        for(int i=0;i<n;i++){
            if(manager[i]!=-1){
               adj[manager[i]].push_back(i);
                   }  
        }
                   
    queue<int>q;
                   int ans=0;
                   q.push(headID);
                   vector<int>distance(n,0);
                   while(!q.empty()){
                       auto front=q.front();
                       q.pop();
                       for(auto x:adj[front]){
                           distance[x]=distance[front]+informTime[front];
                           q.push(x);
                           ans=max(ans,distance[x]);
                   }
                   }
                   return ans;
                  
    }
    };