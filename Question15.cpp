15 -> Maximum Points You Can Obtain from Cards

Solution :

class Solution {
public:
    int maxScore(vector<int>& cardPoints, int k) {
        int n=cardPoints.size();
        vector<int>pref1;
        vector<int>pref2(n,0);
        int sum=0;
        for(auto x:cardPoints){
            sum+=x;
            pref1.push_back(sum);
        }
        sum=0;
        for(int i=n-1;i>=0;i--){
            sum+=cardPoints[i];
            pref2[i]=sum;
        }
        
        int ans=pref1[k-1];
        int i=k-2;
        int j=n-1;
        
        while(i>=0){
            ans=max(ans,pref1[i]+pref2[j]);
            cout<<ans<<endl;
            i--;
            j--;
        }
        ans=max(ans,pref2[n-k]);
        i=n-k+1;
        j=0;
        while(i<n){
            ans=max(ans,pref2[i]+pref1[j]);
            i++;
            j++;
        }
        return ans;
        
    }
};