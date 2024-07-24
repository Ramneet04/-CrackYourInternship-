80 -> Add Binary

Solution :

class Solution {
public:
    string addBinary(string a, string b) {
        int i=a.length()-1;
        int j=b.length()-1;
        int carry=0;
        string s="";
        while(i>=0&&j>=0){
            int ans=(a[i]-'0')+(b[j]-'0')+carry;
            if(ans>=2){
                ans=ans-2;
                char ch=ans+'0';
                s=s+ch;
                carry=1;
            }
            else{
                char ch=ans+'0';
                s=s+ch;
                carry=0;
            }
            i--;j--;
        }
        while(j>=0){
            int ans=carry+(b[j]-'0');
            if(ans>=2){
                ans=ans-2;
                char ch=ans+'0';
                s=s+ch;
                carry=1;
            }
            else{
                char ch=ans+'0';
                s=s+ch;
                carry=0;
            }
            j--;
        }
        while(i>=0){
            int ans=carry+(a[i]-'0');
            if(ans>=2){
                ans=ans-2;
                char ch=ans+'0';
                s=s+ch;
                carry=1;
            }
            else{
                char ch=ans+'0';
                s=s+ch;
                carry=0;
            }
            i--;
        }
        if(carry==1){
            char ch=carry+'0';
            s=s+ch;
            carry=0;
        }
        reverse(s.begin(),s.end());
        return s;
    }
};