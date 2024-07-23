66 -> Number of Operations to Make Network Connected 

Solution :
class Solution {
public:
    vector<int>parent;
    vector<int>rank;
    int find(int x){
        if(parent[x]==x)return x;
        return parent[x]=find(parent[x]);
    }
    void Union(int x,int y,int &comp){
        int xp=find(x);
        int yp=find(y);
        if(xp==yp){
            return;
        }
        comp--;
        if(rank[xp]==rank[yp]){
            parent[xp]=yp;
            rank[yp]++;
        }
        else if(rank[xp]>rank[yp]){
            parent[yp]=xp;
        }
        else{
            parent[xp]=yp;
        }
    }
    int makeConnected(int n, vector<vector<int>>& connections) {
        parent.resize(n);
        rank.resize(n);
        if(connections.size()<n-1)return -1;
        int component=n;
        for(int i=0;i<n;i++){
            parent[i]=i;
            rank[i]=0;
        }
        for(auto x:connections){
            Union(x[0],x[1],component);
        }
        return component-1;
    }
};