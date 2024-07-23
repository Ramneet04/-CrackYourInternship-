77 -> Minimum Cost to Hire K Workers

Solution :

class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& wage, int k) {
        int n=wage.size();
        vector<pair<double,int>>arr;
        for(int i=0;i<n;i++){
            double ratio=(double)wage[i]/quality[i];
            arr.push_back({ratio,quality[i]});
        }
        sort(arr.begin(),arr.end());
        priority_queue<double>pq;
        double ans=0;
        int sum=0;
        for(int j=0;j<k;j++){
                pq.push(arr[j].second);
               sum+=arr[j].second;
            }
        ans=sum*arr[k-1].first;
        for(int i=k;i<n;i++){
            sum+=arr[i].second;
            pq.push(arr[i].second);
            sum-=pq.top();
            pq.pop();
            double res=sum*arr[i].first;
            ans=min(ans,res);
        }
        return ans;
    }
};