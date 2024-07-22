50 -> Backspace String Compare

Solution :

class Solution {
public:
    void solve(string s,string &ans){
        for(auto x:s){
            if(x=='#'){
                if(!ans.empty())
                ans.pop_back();
            }
            else
                ans.push_back(x);
        }
    }
    bool backspaceCompare(string s, string t) {
        string ans1="";
        string ans2="";
        
        solve(s,ans1);
        solve(t,ans2);
        if(ans1.size()!=ans2.size())return false;
        for(int i=0;i<ans1.size();i++){
            if(ans1[i]!=ans2[i])return false;
        }
        return true;
    }
};