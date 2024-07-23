62 -> Gas Station 

Solution :
class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int balance=0;
        int start=0;
        int currbalance=0;
        for(int i=0;i<gas.size();i++){
            currbalance=currbalance+gas[i]-cost[i];
            if(currbalance<0){
                start=i+1;
                balance=balance+currbalance;
                currbalance=0;
            }
        }
        if(balance+currbalance>=0){return start;}
        return -1;
        
    }
};
