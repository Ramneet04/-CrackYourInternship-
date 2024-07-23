70 -> alien dictionary 

Solution :
//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
   // User function Template for C++
    public:
   void topological(int node,vector<int>adj[],vector<int>&ans,vector<bool>&visited){
        visited[node]=true;
        
        for(auto x:adj[node]){
            if(!visited[x]){
                topological(x,adj,ans,visited);
            }
        }
        ans.push_back(node);
    }
    string findOrder(string dict[], int N, int K) {
        vector<int>adj[K];
        for(int i=0;i<N-1;i++){
            string s1=dict[i];
            string s2=dict[i+1];
            int len=min(s1.length(),s2.length());
            for(int i=0;i<len;i++){
                if(s1[i]!=s2[i]){
                    adj[s1[i]-'a'].push_back(s2[i]-'a');
                    break;
                }
            }
        }
        vector<int>ans;
        vector<bool>visited(K,false);
        for(int i=0;i<K;i++){
            if(!visited[i])
        topological(i,adj,ans,visited);
        }
        string str="";
        for(auto x:ans){
            str.push_back(x+'a');
        }
        reverse(str.begin(),str.end());
        return str;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends
