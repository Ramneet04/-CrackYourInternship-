64 -> DECODE STRING 

Solution :

class Solution {
public:
    string decodeString(string s) {
        stack<int>nst; stack<string>sst;
        int number=0; string ans="";
        
        int i=0;
        while(i<s.length()){
            if(s[i]=='['){
                sst.push(ans);
                ans="";
                nst.push(number);
                number=0;
            }
            else if(s[i]>='0'&&s[i]<='9'){
                number=number*10+(s[i]-'0');
            }
            else if(s[i]==']'){
                int num=nst.top();
                nst.pop();
                string prevstr=sst.top();
                sst.pop();
                string temp="";
                while(num--){
                    temp+=ans;
                }
                //below line is important
                ans=prevstr+temp;
            }
            else{
                ans+=s[i];
            }
            
            i++;
        }
        return ans;
    }
};