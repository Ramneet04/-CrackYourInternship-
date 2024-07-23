75 -> Ugly Number II

Solution :
class Solution {
public:
    int nthUglyNumber(int n) {
        vector<int>arr(n+1,0);
        arr[1]=1;
        int i2=1;
        int i3=1;
        int i5=1;
        for(int i=2;i<=n;i++){
            int num2=arr[i2]*2;
            int num3=arr[i3]*3;
            int num5=arr[i5]*5;
            int ans=min(num2,min(num3,num5));
            
            if(ans==num2){
                i2++;
            }
            if(ans==num3){
                i3++;
            }
            if(ans==num5){
                i5++;
            }
            arr[i]=ans;
        }
        
        return arr[n];
    }
};