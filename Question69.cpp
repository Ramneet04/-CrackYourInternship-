69 -> Cheapest Flights Within K Stops

Solution :

class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<pair<int,int>>adj[n];
        for(auto x:flights){
            adj[x[0]].push_back({x[1],x[2]});
        }
        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;
        pq.push({0,{0,src}});
        vector<int>distance(n,1e9);
        distance[src]=0;
        int steps=0;
        
        while(!pq.empty()){
            auto top=pq.top();
            int steps= top.first;
            int node=top.second.second;
            int w=top.second.first;
            pq.pop();
            if(steps==k+1)break;
                for(auto u:adj[node]){
                    int unode=u.first;
                    int uw=u.second;
                    if(distance[unode]>w+uw){
                        distance[unode]=w+uw;
                        pq.push({steps+1,{distance[unode],unode}});
                    }
                }
        }
        
        if(distance[dst]==1e9)return -1;
        return distance[dst];
    }
};